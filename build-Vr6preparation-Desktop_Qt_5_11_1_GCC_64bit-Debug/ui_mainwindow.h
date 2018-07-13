/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <qcustomplot.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionLoad;
    QAction *actionErase;
    QAction *actionHideSpeedometer;
    QAction *actionHidePlot;
    QAction *actionExit;
    QWidget *centralWidget;
    QCustomPlot *customPlot;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *playBtn;
    QGraphicsView *graphicsView;
    QStatusBar *statusBar;
    QMenuBar *menuBar;
    QMenu *menuOptions;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(772, 423);
        actionLoad = new QAction(MainWindow);
        actionLoad->setObjectName(QStringLiteral("actionLoad"));
        actionErase = new QAction(MainWindow);
        actionErase->setObjectName(QStringLiteral("actionErase"));
        actionHideSpeedometer = new QAction(MainWindow);
        actionHideSpeedometer->setObjectName(QStringLiteral("actionHideSpeedometer"));
        actionHidePlot = new QAction(MainWindow);
        actionHidePlot->setObjectName(QStringLiteral("actionHidePlot"));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        customPlot = new QCustomPlot(centralWidget);
        customPlot->setObjectName(QStringLiteral("customPlot"));
        customPlot->setGeometry(QRect(380, 10, 371, 351));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 361, 351));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        playBtn = new QPushButton(layoutWidget);
        playBtn->setObjectName(QStringLiteral("playBtn"));

        verticalLayout->addWidget(playBtn);

        graphicsView = new QGraphicsView(layoutWidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setAutoFillBackground(true);

        verticalLayout->addWidget(graphicsView);

        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 772, 22));
        menuOptions = new QMenu(menuBar);
        menuOptions->setObjectName(QStringLiteral("menuOptions"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuOptions->menuAction());
        menuOptions->addAction(actionLoad);
        menuOptions->addAction(actionErase);
        menuOptions->addAction(actionHideSpeedometer);
        menuOptions->addAction(actionHidePlot);
        menuOptions->addAction(actionExit);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        actionLoad->setText(QApplication::translate("MainWindow", "Load Configuration", nullptr));
        actionErase->setText(QApplication::translate("MainWindow", "Erase Plot", nullptr));
        actionHideSpeedometer->setText(QApplication::translate("MainWindow", "Hide Speedometer", nullptr));
        actionHidePlot->setText(QApplication::translate("MainWindow", "Hide Plot 2D", nullptr));
        actionExit->setText(QApplication::translate("MainWindow", "Exit", nullptr));
        playBtn->setText(QApplication::translate("MainWindow", "Play", nullptr));
        menuOptions->setTitle(QApplication::translate("MainWindow", "Options", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
