#include <QPushButton>
#include <QDebug>

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <cfloat>

#include <iio.h>

#include <qwt_plot_curve.h>

#include "main_gui.h"


#define DMM_UM_SCAL 0.001
#define PLOT_ERR 3

// FIXME: delete these, too lazy to enter them during testing :/
#define DEVICE_IP "ip:10.48.65.115"
#define DEVICE_NAME "ad7124-8"

class Window : public QMainWindow, public Ui_MainWindow {
    Q_OBJECT
private:
    Ui::MainWindow *ui;

    std::string context;

    struct pack {
        float offset;
        float scale;
    };

    struct iio_context *iio_context;
    struct iio_device *iio_device;
    struct iio_channel *iio_channel;

    float channel_offset{};
    float channel_scale{};
    float channel_sampling_frequency{};

    double frequencyHz{};
    
    uint32_t sample_count;

    std::vector<double> plot_data;
    QwtPlotCurve *frequency_curve{};

protected:
    void connectSignalsAndSlots();

public:
    explicit Window(QWidget *parent = nullptr);
    ~Window() override;

    void populate_channels();

public slots:
    void find_context();
    void find_name();

    void set_scale();
    void set_sample_count();
    void set_sampling_frequency();

    void start_plot();
    void populate_channel_properties();

    void save_to_file();
    void load_from_file();

protected:
    void plot(double* ydata);
    static unsigned int swap_Endians(int value);
    static std::vector<std::string> tokenize(const std::string& str, char delimiter);
    double compute_frequency();
public:
    ssize_t for_sample(const struct iio_channel *channel, void *sample, size_t length, void *data);
};
