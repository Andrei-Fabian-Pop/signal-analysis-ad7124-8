# Form implementation generated from reading ui file '/home/andrei-fabian/CLionProjects/gui/ui/main_gui.ui'
#
# Created by: PyQt6 UI code generator 6.4.0
#
# WARNING: Any manual changes made to this file will be lost when pyuic6 is
# run again.  Do not edit this file unless you know what you are doing.


from PyQt6 import QtCore, QtGui, QtWidgets


class Ui_MainWindow(object):
    def setupUi(self, MainWindow):
        MainWindow.setObjectName("MainWindow")
        MainWindow.resize(890, 841)
        self.centralwidget = QtWidgets.QWidget(MainWindow)
        self.centralwidget.setObjectName("centralwidget")
        self.verticalLayout_4 = QtWidgets.QVBoxLayout(self.centralwidget)
        self.verticalLayout_4.setObjectName("verticalLayout_4")
        self.verticalLayout_3 = QtWidgets.QVBoxLayout()
        self.verticalLayout_3.setObjectName("verticalLayout_3")
        self.horizontalLayout = QtWidgets.QHBoxLayout()
        self.horizontalLayout.setObjectName("horizontalLayout")
        self.label = QtWidgets.QLabel(self.centralwidget)
        self.label.setObjectName("label")
        self.horizontalLayout.addWidget(self.label)
        self.lineEdit_context = QtWidgets.QLineEdit(self.centralwidget)
        self.lineEdit_context.setObjectName("lineEdit_context")
        self.horizontalLayout.addWidget(self.lineEdit_context)
        self.pushButton_findContext = QtWidgets.QPushButton(self.centralwidget)
        self.pushButton_findContext.setObjectName("pushButton_findContext")
        self.horizontalLayout.addWidget(self.pushButton_findContext)
        self.verticalLayout_3.addLayout(self.horizontalLayout)
        self.label_findContextResult = QtWidgets.QLabel(self.centralwidget)
        self.label_findContextResult.setObjectName("label_findContextResult")
        self.verticalLayout_3.addWidget(self.label_findContextResult)
        self.horizontalLayout_3 = QtWidgets.QHBoxLayout()
        self.horizontalLayout_3.setObjectName("horizontalLayout_3")
        self.label_2 = QtWidgets.QLabel(self.centralwidget)
        self.label_2.setObjectName("label_2")
        self.horizontalLayout_3.addWidget(self.label_2)
        self.lineEdit_deviceName = QtWidgets.QLineEdit(self.centralwidget)
        self.lineEdit_deviceName.setObjectName("lineEdit_deviceName")
        self.horizontalLayout_3.addWidget(self.lineEdit_deviceName)
        self.pushButton_selectDevName = QtWidgets.QPushButton(self.centralwidget)
        self.pushButton_selectDevName.setObjectName("pushButton_selectDevName")
        self.horizontalLayout_3.addWidget(self.pushButton_selectDevName)
        self.verticalLayout_3.addLayout(self.horizontalLayout_3)
        self.label_devNameFound = QtWidgets.QLabel(self.centralwidget)
        self.label_devNameFound.setObjectName("label_devNameFound")
        self.verticalLayout_3.addWidget(self.label_devNameFound)
        self.label_3 = QtWidgets.QLabel(self.centralwidget)
        self.label_3.setObjectName("label_3")
        self.verticalLayout_3.addWidget(self.label_3)
        self.verticalLayout_2 = QtWidgets.QVBoxLayout()
        self.verticalLayout_2.setObjectName("verticalLayout_2")
        self.horizontalLayout_2 = QtWidgets.QHBoxLayout()
        self.horizontalLayout_2.setObjectName("horizontalLayout_2")
        self.verticalLayout = QtWidgets.QVBoxLayout()
        self.verticalLayout.setObjectName("verticalLayout")
        self.label_4 = QtWidgets.QLabel(self.centralwidget)
        self.label_4.setObjectName("label_4")
        self.verticalLayout.addWidget(self.label_4)
        self.listWidget_channelList = QtWidgets.QListWidget(self.centralwidget)
        self.listWidget_channelList.setObjectName("listWidget_channelList")
        self.verticalLayout.addWidget(self.listWidget_channelList)
        self.horizontalLayout_2.addLayout(self.verticalLayout)
        self.gridLayout = QtWidgets.QGridLayout()
        self.gridLayout.setObjectName("gridLayout")
        self.label_sampleCount = QtWidgets.QLabel(self.centralwidget)
        self.label_sampleCount.setObjectName("label_sampleCount")
        self.gridLayout.addWidget(self.label_sampleCount, 4, 0, 1, 1)
        self.comboBox_scaleAvailable = QtWidgets.QComboBox(self.centralwidget)
        self.comboBox_scaleAvailable.setObjectName("comboBox_scaleAvailable")
        self.gridLayout.addWidget(self.comboBox_scaleAvailable, 3, 1, 1, 1)
        self.label_5 = QtWidgets.QLabel(self.centralwidget)
        self.label_5.setObjectName("label_5")
        self.gridLayout.addWidget(self.label_5, 0, 0, 1, 1)
        self.lineEdit_samplingFrequency = QtWidgets.QLineEdit(self.centralwidget)
        self.lineEdit_samplingFrequency.setObjectName("lineEdit_samplingFrequency")
        self.gridLayout.addWidget(self.lineEdit_samplingFrequency, 1, 1, 1, 1)
        self.lineEdit_offset = QtWidgets.QLineEdit(self.centralwidget)
        self.lineEdit_offset.setObjectName("lineEdit_offset")
        self.gridLayout.addWidget(self.lineEdit_offset, 0, 1, 1, 1)
        self.lineEdit_sampleCount = QtWidgets.QLineEdit(self.centralwidget)
        self.lineEdit_sampleCount.setObjectName("lineEdit_sampleCount")
        self.gridLayout.addWidget(self.lineEdit_sampleCount, 4, 1, 1, 1)
        self.label_7 = QtWidgets.QLabel(self.centralwidget)
        self.label_7.setObjectName("label_7")
        self.gridLayout.addWidget(self.label_7, 2, 0, 1, 1)
        self.label_8 = QtWidgets.QLabel(self.centralwidget)
        self.label_8.setObjectName("label_8")
        self.gridLayout.addWidget(self.label_8, 3, 0, 1, 1)
        self.label_6 = QtWidgets.QLabel(self.centralwidget)
        self.label_6.setObjectName("label_6")
        self.gridLayout.addWidget(self.label_6, 1, 0, 1, 1)
        self.lineEdit_scale = QtWidgets.QLineEdit(self.centralwidget)
        self.lineEdit_scale.setObjectName("lineEdit_scale")
        self.gridLayout.addWidget(self.lineEdit_scale, 2, 1, 1, 1)
        self.label_frequency = QtWidgets.QLabel(self.centralwidget)
        self.label_frequency.setObjectName("label_frequency")
        self.gridLayout.addWidget(self.label_frequency, 5, 0, 1, 1)
        self.lineEdit_frequency = QtWidgets.QLineEdit(self.centralwidget)
        self.lineEdit_frequency.setObjectName("lineEdit_frequency")
        self.gridLayout.addWidget(self.lineEdit_frequency, 5, 1, 1, 1)
        self.horizontalLayout_2.addLayout(self.gridLayout)
        self.verticalLayout_2.addLayout(self.horizontalLayout_2)
        self.pushButton_runPlot = QtWidgets.QPushButton(self.centralwidget)
        self.pushButton_runPlot.setObjectName("pushButton_runPlot")
        self.verticalLayout_2.addWidget(self.pushButton_runPlot)
        self.qwtPlot_graph = QwtPlot(self.centralwidget)
        self.qwtPlot_graph.setAutoReplot(True)
        self.qwtPlot_graph.setObjectName("qwtPlot_graph")
        self.verticalLayout_2.addWidget(self.qwtPlot_graph)
        self.verticalLayout_3.addLayout(self.verticalLayout_2)
        self.verticalLayout_4.addLayout(self.verticalLayout_3)
        MainWindow.setCentralWidget(self.centralwidget)
        self.menubar = QtWidgets.QMenuBar(MainWindow)
        self.menubar.setGeometry(QtCore.QRect(0, 0, 890, 22))
        self.menubar.setObjectName("menubar")
        self.menuFile = QtWidgets.QMenu(self.menubar)
        self.menuFile.setObjectName("menuFile")
        MainWindow.setMenuBar(self.menubar)
        self.statusbar = QtWidgets.QStatusBar(MainWindow)
        self.statusbar.setObjectName("statusbar")
        MainWindow.setStatusBar(self.statusbar)
        self.toolBar = QtWidgets.QToolBar(MainWindow)
        self.toolBar.setObjectName("toolBar")
        MainWindow.addToolBar(QtCore.Qt.ToolBarArea.TopToolBarArea, self.toolBar)
        self.actionSave = QtGui.QAction(MainWindow)
        self.actionSave.setObjectName("actionSave")
        self.actionLoad = QtGui.QAction(MainWindow)
        self.actionLoad.setObjectName("actionLoad")
        self.menuFile.addAction(self.actionSave)
        self.menuFile.addAction(self.actionLoad)
        self.menubar.addAction(self.menuFile.menuAction())

        self.retranslateUi(MainWindow)
        QtCore.QMetaObject.connectSlotsByName(MainWindow)

    def retranslateUi(self, MainWindow):
        _translate = QtCore.QCoreApplication.translate
        MainWindow.setWindowTitle(_translate("MainWindow", "MainWindow"))
        self.label.setText(_translate("MainWindow", "Device context:"))
        self.pushButton_findContext.setText(_translate("MainWindow", "Find"))
        self.label_findContextResult.setText(_translate("MainWindow", "No device found"))
        self.label_2.setText(_translate("MainWindow", "Device name:"))
        self.pushButton_selectDevName.setText(_translate("MainWindow", "Select"))
        self.label_devNameFound.setText(_translate("MainWindow", "No name found"))
        self.label_3.setText(_translate("MainWindow", "----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"))
        self.label_4.setText(_translate("MainWindow", "Channels"))
        self.label_sampleCount.setText(_translate("MainWindow", "Sample Count:"))
        self.label_5.setText(_translate("MainWindow", "Offset:"))
        self.label_7.setText(_translate("MainWindow", "Scale:"))
        self.label_8.setText(_translate("MainWindow", "Scale Available:"))
        self.label_6.setText(_translate("MainWindow", "Sampling Frequency:"))
        self.label_frequency.setText(_translate("MainWindow", "Frequency (Hz):"))
        self.pushButton_runPlot.setText(_translate("MainWindow", "Plot"))
        self.menuFile.setTitle(_translate("MainWindow", "File"))
        self.toolBar.setWindowTitle(_translate("MainWindow", "toolBar"))
        self.actionSave.setText(_translate("MainWindow", "Save"))
        self.actionLoad.setText(_translate("MainWindow", "Load"))
from qwt_plot import QwtPlot
