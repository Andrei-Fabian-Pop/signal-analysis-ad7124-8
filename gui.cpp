#include "gui.h"

Window::Window(QWidget *parent) : Ui_MainWindow(), ui(new Ui::MainWindow) {
    this->ui->setupUi(this);

    this->ui->label_findContextResult->setStyleSheet("QLabel { color : red; }");
    this->ui->label_devNameFound->setStyleSheet("QLabel { color : red; }");

    this->iio_context = nullptr;
    this->iio_device = nullptr;
    this->iio_channel = nullptr;

    this->ui->lineEdit_context->setText(DEVICE_IP);
    this->ui->lineEdit_deviceName->setText(DEVICE_NAME);
    this->sample_count = 1024; // default
    this->plot_data.reserve(this->sample_count);

    this->connectSignalsAndSlots();
}

Window::~Window() {
    iio_context_destroy(this->iio_context);
}

void Window::connectSignalsAndSlots() {
    QObject::connect(this->ui->pushButton_findContext, &QPushButton::clicked, this, &Window::find_context);
    QObject::connect(this->ui->pushButton_selectDevName, &QPushButton::clicked, this, &Window::find_name);
    QObject::connect(this->ui->listWidget_channelList, &QListWidget::currentItemChanged, this,
                        &Window::populate_channel_properties);

    QObject::connect(this->ui->lineEdit_samplingFrequency, &QLineEdit::editingFinished, this,
                        &Window::set_sampling_frequency);
    QObject::connect(this->ui->lineEdit_sampleCount, &QLineEdit::editingFinished, this, 
                        &Window::set_sample_count);
    QObject::connect(this->ui->comboBox_scaleAvailable, SIGNAL(currentIndexChanged(int)), this, SLOT(set_scale()));

    QObject::connect(this->ui->pushButton_runPlot, &QPushButton::clicked, this, &Window::start_plot);
    QObject::connect(this->ui->actionSave, &QAction::triggered, this, &Window::save_to_file);
    QObject::connect(this->ui->actionLoad, &QAction::triggered, this, &Window::load_from_file);
}

void Window::find_context() {
    std::string ctx = this->ui->lineEdit_context->text().toStdString();

    this->iio_context = iio_create_context_from_uri(ctx.c_str());
    if (this->iio_context == nullptr) {
        this->ui->label_findContextResult->setText("No context made => No context found");
        this->ui->label_findContextResult->setStyleSheet("QLabel { color : red; }");
        this->iio_context = nullptr;
        this->iio_device = nullptr;
        return;
    }

    this->ui->label_findContextResult->setText("Device context found!");
    this->ui->label_findContextResult->setStyleSheet("QLabel { color : green; }");
}

void Window::find_name() {
    if (this->iio_context == nullptr) {
        this->ui->label_devNameFound->setText("Error: enter a valid context before device name");
        this->ui->label_devNameFound->setStyleSheet("QLabel { color: red; }");
        return;
    }

    this->iio_device = iio_context_find_device(this->iio_context, this->ui->lineEdit_deviceName->text().toStdString().c_str());
    if (this->iio_device == nullptr) {
        this->ui->label_devNameFound->setText("No device with this name found");
        this->ui->label_devNameFound->setStyleSheet("QLabel { color : red; }");
        this->iio_context = nullptr;
        this->iio_device = nullptr;
        return;
    }

    this->ui->label_devNameFound->setText("Device found!");
    this->ui->label_devNameFound->setStyleSheet("QLabel { color : green; }");

    this->populate_channels();
}

void Window::populate_channels() {
    this->ui->listWidget_channelList->clear();

    unsigned int channel_count = iio_device_get_channels_count(this->iio_device);
    for (size_t i = 0; i < channel_count; ++i) {
        const struct iio_channel *iio_chn = iio_device_get_channel(this->iio_device, i);
        this->ui->listWidget_channelList->addItem(iio_channel_get_id(iio_chn));
    }
}

void Window::populate_channel_properties() {
    unsigned int index = this->ui->listWidget_channelList->currentIndex().row();
    this->iio_channel = iio_device_get_channel(this->iio_device, index);

    char *read_buffer = new char[128];
    float offset;
    ssize_t attr_read = iio_channel_attr_read(this->iio_channel, "offset", read_buffer, 128);
    if (attr_read > 0) {
        offset = std::stof(read_buffer);
        this->channel_offset = offset;
        this->ui->lineEdit_offset->setText(read_buffer);
    } else {
        this->ui->lineEdit_offset->setText("Error when reading.");
    }

    float sampling_frequency;
    attr_read = iio_channel_attr_read(this->iio_channel, "sampling_frequency", read_buffer, 128);
    if (attr_read > 0) {
        sampling_frequency = std::stof(read_buffer);
        this->channel_sampling_frequency = sampling_frequency;
        this->ui->lineEdit_samplingFrequency->setText(read_buffer);
    } else {
        this->ui->lineEdit_samplingFrequency->setText("Error when reading.");
    }

    float local_channel_scale;
    attr_read = iio_channel_attr_read(this->iio_channel, "scale", read_buffer, 128);
    if (attr_read > 0) {
        local_channel_scale = std::stof(read_buffer);
        this->channel_scale = local_channel_scale;
        this->ui->lineEdit_scale->setText(read_buffer);
    } else {
        this->ui->lineEdit_scale->setText("Error when reading.");
    }

    attr_read = iio_channel_attr_read(this->iio_channel, "scale_available", read_buffer, 128);
    if (attr_read > 0) {
        this->ui->comboBox_scaleAvailable->clear();
        std::vector<std::string> scales = tokenize(read_buffer, ' ');
        int local_index = 0;
        for (int i = 0; i < scales.size(); ++i) {
            this->ui->comboBox_scaleAvailable->addItem(QString::fromStdString(scales[i]));
            if (scales[i] == this->ui->lineEdit_scale->text().toStdString()) {
                local_index = i;
            }
        }
        this->ui->comboBox_scaleAvailable->setCurrentIndex(local_index); // so it does not reset the scale on startup
    } else {
        this->ui->lineEdit_samplingFrequency->setText("Error when reading.");
    }

    this->ui->lineEdit_sampleCount->setText(QString::number(this->sample_count));

    delete[] read_buffer;
}

void Window::set_scale() {
    
}

void Window::set_sampling_frequency() {
    std::string sampling_freq = this->ui->lineEdit_samplingFrequency->text().toStdString();
    const char *write_buffer = sampling_freq.c_str();
    ssize_t result = iio_channel_attr_write(this->iio_channel, "sampling_frequency", write_buffer);
    if (result < 0) {
        qDebug() << "Error when writing sampling_frequency";
    }
}

void Window::set_sample_count() {
    this->sample_count = (uint32_t)(this->ui->lineEdit_sampleCount->text().toInt());
    this->plot_data.clear();
    this->plot_data.resize(this->sample_count);
}

ssize_t Window::for_sample(const struct iio_channel *channel, void *sample, size_t length, void *data) {
    int *ptr = (int*)(sample);
    auto* p = (struct pack*)(data);
    double channel_value = ((double) (swap_Endians(*ptr)) + (double) (p->offset)) * p->scale * DMM_UM_SCAL;
    qDebug() << channel_value;
}

void Window::start_plot() {
    if (this->iio_channel == nullptr || this->iio_device == nullptr) {
        return;
    }
    this->plot_data.clear();

    iio_channel_enable(this->iio_channel);
    iio_device_set_kernel_buffers_count(this->iio_device, 1);
    struct iio_buffer *iio_buffer = iio_device_create_buffer(this->iio_device, this->sample_count, false);
    if (iio_buffer == nullptr) {
        qDebug() << "Could not make iio buffer";
        return;
    }

    ssize_t refill_bytes = iio_buffer_refill(iio_buffer);
    if (refill_bytes < 0) {
        qDebug() << "[ERROR] Refill bytes number is negative!";
        qDebug() << refill_bytes;
        return;
    }

//    struct pack p { p.offset = this->channel_offset, p.scale = this->channel_scale };
//    iio_buffer_foreach_sample(iio_buffer, this->for_sample, &p);

//    qDebug() << "---------------------------";

    for (char * ptr = (char*) iio_buffer_first(iio_buffer, this->iio_channel);
            ptr != iio_buffer_end(iio_buffer);
            ptr += iio_buffer_step(iio_buffer)) // 1 int
    {
        uint32_t val;
        iio_channel_convert(this->iio_channel, &val, ptr);
        double channel_value = ((double) (val) + (double) (channel_offset)) * channel_scale * DMM_UM_SCAL;
        qDebug() << channel_value;
        this->plot_data.push_back(channel_value);
    }

    this->frequencyHz = this->compute_frequency();
    this->ui->lineEdit_frequency->setText(QString::number(this->frequencyHz));

    this->plot(this->plot_data.data());

    iio_channel_disable(this->iio_channel);
    iio_buffer_destroy(iio_buffer);
}

void Window::save_to_file() {
    std::ofstream file("plot_values.txt");

    for (int i = 0; i < this->sample_count; ++i) {
        file << this->plot_data[i] << std::endl;
    }

    file.close();
}

void Window::load_from_file() {
    std::ifstream file("plot_values.txt");
    
    double data;
    this->plot_data.clear();
    for (int i = 0; i < this->sample_count; ++i) {
        file >> data;
        this->plot_data.push_back(data);
    }

    file.close();

    this->plot(this->plot_data.data());
}

void Window::plot(double* ydata) {
    this->frequency_curve = new QwtPlotCurve("Voltage");
    this->frequency_curve->setRawSamples(ydata, (int)(this->sample_count));
    this->frequency_curve->attach(this->ui->qwtPlot_graph);

    this->ui->qwtPlot_graph->replot();
}

unsigned int Window::swap_Endians(int value) {
    unsigned int leftmost_byte, left_middle_byte, right_middle_byte, rightmost_byte;
    unsigned int result;

    leftmost_byte = (value & 0x000000FF) >> 0;
    left_middle_byte = (value & 0x0000FF00) >> 8;
    right_middle_byte = (value & 0x00FF0000) >> 16;
    rightmost_byte = (value & 0xFF000000) >> 24;

    leftmost_byte <<= 24;
    left_middle_byte <<= 16;
    right_middle_byte <<= 8;
    rightmost_byte <<= 0;

    // Result is the concatenation of all these values.
    result = (leftmost_byte | left_middle_byte | right_middle_byte | rightmost_byte);

    return result;
}

std::vector<std::string> Window::tokenize(const std::string& str, char delimiter) {
    std::vector<std::string> result;
    std::stringstream ss(str);
    std::string token;

    while (std::getline(ss, token, delimiter))
        result.push_back(token);

    return result;
}

double Window::compute_frequency() {
    int index1 = -1, index2 = -1;
    bool peak;

    for (int i = PLOT_ERR; i < this->plot_data.size()-PLOT_ERR; ++i) {
        peak = true;
        for (int j = 0; j < PLOT_ERR; ++j) {
            if (plot_data[i-j] > plot_data[i] || plot_data[i] < plot_data[i+j]) {
                peak = false;
            }
        }

        if (peak) {
            if (index1 == -1) {
                index1 = i;
            } else if (index2 == -1) {
                index2 = i;
            } else {
                break;
            }
        }
    }

    double period = (double)(index2)-(double)(index1);
    double freq = (double)(this->channel_sampling_frequency) / period;
    return freq;
}
