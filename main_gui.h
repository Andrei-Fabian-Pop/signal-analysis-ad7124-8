/********************************************************************************
** Form generated from reading UI file 'main_gui.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef MAIN_GUI_H
#define MAIN_GUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qwt_plot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionSave;
    QAction *actionLoad;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit_context;
    QPushButton *pushButton_findContext;
    QLabel *label_findContextResult;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QLineEdit *lineEdit_deviceName;
    QPushButton *pushButton_selectDevName;
    QLabel *label_devNameFound;
    QLabel *label_3;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *label_4;
    QListWidget *listWidget_channelList;
    QGridLayout *gridLayout;
    QLabel *label_sampleCount;
    QComboBox *comboBox_scaleAvailable;
    QLabel *label_5;
    QLineEdit *lineEdit_samplingFrequency;
    QLineEdit *lineEdit_offset;
    QLineEdit *lineEdit_sampleCount;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_6;
    QLineEdit *lineEdit_scale;
    QLabel *label_frequency;
    QLineEdit *lineEdit_frequency;
    QPushButton *pushButton_runPlot;
    QwtPlot *qwtPlot_graph;
    QMenuBar *menubar;
    QMenu *menuFile;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(890, 841);
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        actionLoad = new QAction(MainWindow);
        actionLoad->setObjectName(QString::fromUtf8("actionLoad"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout_4 = new QVBoxLayout(centralwidget);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        lineEdit_context = new QLineEdit(centralwidget);
        lineEdit_context->setObjectName(QString::fromUtf8("lineEdit_context"));

        horizontalLayout->addWidget(lineEdit_context);

        pushButton_findContext = new QPushButton(centralwidget);
        pushButton_findContext->setObjectName(QString::fromUtf8("pushButton_findContext"));

        horizontalLayout->addWidget(pushButton_findContext);


        verticalLayout_3->addLayout(horizontalLayout);

        label_findContextResult = new QLabel(centralwidget);
        label_findContextResult->setObjectName(QString::fromUtf8("label_findContextResult"));

        verticalLayout_3->addWidget(label_findContextResult);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_3->addWidget(label_2);

        lineEdit_deviceName = new QLineEdit(centralwidget);
        lineEdit_deviceName->setObjectName(QString::fromUtf8("lineEdit_deviceName"));

        horizontalLayout_3->addWidget(lineEdit_deviceName);

        pushButton_selectDevName = new QPushButton(centralwidget);
        pushButton_selectDevName->setObjectName(QString::fromUtf8("pushButton_selectDevName"));

        horizontalLayout_3->addWidget(pushButton_selectDevName);


        verticalLayout_3->addLayout(horizontalLayout_3);

        label_devNameFound = new QLabel(centralwidget);
        label_devNameFound->setObjectName(QString::fromUtf8("label_devNameFound"));

        verticalLayout_3->addWidget(label_devNameFound);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout_3->addWidget(label_3);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout->addWidget(label_4);

        listWidget_channelList = new QListWidget(centralwidget);
        listWidget_channelList->setObjectName(QString::fromUtf8("listWidget_channelList"));

        verticalLayout->addWidget(listWidget_channelList);


        horizontalLayout_2->addLayout(verticalLayout);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_sampleCount = new QLabel(centralwidget);
        label_sampleCount->setObjectName(QString::fromUtf8("label_sampleCount"));

        gridLayout->addWidget(label_sampleCount, 4, 0, 1, 1);

        comboBox_scaleAvailable = new QComboBox(centralwidget);
        comboBox_scaleAvailable->setObjectName(QString::fromUtf8("comboBox_scaleAvailable"));

        gridLayout->addWidget(comboBox_scaleAvailable, 3, 1, 1, 1);

        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 0, 0, 1, 1);

        lineEdit_samplingFrequency = new QLineEdit(centralwidget);
        lineEdit_samplingFrequency->setObjectName(QString::fromUtf8("lineEdit_samplingFrequency"));

        gridLayout->addWidget(lineEdit_samplingFrequency, 1, 1, 1, 1);

        lineEdit_offset = new QLineEdit(centralwidget);
        lineEdit_offset->setObjectName(QString::fromUtf8("lineEdit_offset"));

        gridLayout->addWidget(lineEdit_offset, 0, 1, 1, 1);

        lineEdit_sampleCount = new QLineEdit(centralwidget);
        lineEdit_sampleCount->setObjectName(QString::fromUtf8("lineEdit_sampleCount"));

        gridLayout->addWidget(lineEdit_sampleCount, 4, 1, 1, 1);

        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout->addWidget(label_7, 2, 0, 1, 1);

        label_8 = new QLabel(centralwidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout->addWidget(label_8, 3, 0, 1, 1);

        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 1, 0, 1, 1);

        lineEdit_scale = new QLineEdit(centralwidget);
        lineEdit_scale->setObjectName(QString::fromUtf8("lineEdit_scale"));

        gridLayout->addWidget(lineEdit_scale, 2, 1, 1, 1);

        label_frequency = new QLabel(centralwidget);
        label_frequency->setObjectName(QString::fromUtf8("label_frequency"));

        gridLayout->addWidget(label_frequency, 5, 0, 1, 1);

        lineEdit_frequency = new QLineEdit(centralwidget);
        lineEdit_frequency->setObjectName(QString::fromUtf8("lineEdit_frequency"));

        gridLayout->addWidget(lineEdit_frequency, 5, 1, 1, 1);


        horizontalLayout_2->addLayout(gridLayout);


        verticalLayout_2->addLayout(horizontalLayout_2);

        pushButton_runPlot = new QPushButton(centralwidget);
        pushButton_runPlot->setObjectName(QString::fromUtf8("pushButton_runPlot"));

        verticalLayout_2->addWidget(pushButton_runPlot);

        qwtPlot_graph = new QwtPlot(centralwidget);
        qwtPlot_graph->setObjectName(QString::fromUtf8("qwtPlot_graph"));
        qwtPlot_graph->setAutoReplot(true);

        verticalLayout_2->addWidget(qwtPlot_graph);


        verticalLayout_3->addLayout(verticalLayout_2);


        verticalLayout_4->addLayout(verticalLayout_3);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 890, 22));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        menubar->addAction(menuFile->menuAction());
        menuFile->addAction(actionSave);
        menuFile->addAction(actionLoad);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionSave->setText(QCoreApplication::translate("MainWindow", "Save", nullptr));
        actionLoad->setText(QCoreApplication::translate("MainWindow", "Load", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Device context:", nullptr));
        pushButton_findContext->setText(QCoreApplication::translate("MainWindow", "Find", nullptr));
        label_findContextResult->setText(QCoreApplication::translate("MainWindow", "No device found", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Device name:", nullptr));
        pushButton_selectDevName->setText(QCoreApplication::translate("MainWindow", "Select", nullptr));
        label_devNameFound->setText(QCoreApplication::translate("MainWindow", "No name found", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Channels", nullptr));
        label_sampleCount->setText(QCoreApplication::translate("MainWindow", "Sample Count:", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Offset:", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Scale:", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Scale Available:", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Sampling Frequency:", nullptr));
        label_frequency->setText(QCoreApplication::translate("MainWindow", "Frequency (Hz):", nullptr));
        pushButton_runPlot->setText(QCoreApplication::translate("MainWindow", "Plot", nullptr));
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // MAIN_GUI_H
