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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionLoad_Configuration;
    QAction *actionHide_Speedometer;
    QAction *actionHide_Plot_2D;
    QWidget *centralWidget;
    QCustomPlot *customPlot;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QComboBox *comboBox;
    QPushButton *loadBtn;
    QPushButton *clearBtn;
    QPushButton *exitBtn;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QGraphicsView *graphicsView;
    QPushButton *playBtn;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QMenuBar *menuBar;
    QMenu *menuasfsafa;
    QMenu *menuErase_Plot;
    QMenu *menuHide_Unhide;
    QMenu *menuExit;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(772, 423);
        actionLoad_Configuration = new QAction(MainWindow);
        actionLoad_Configuration->setObjectName(QStringLiteral("actionLoad_Configuration"));
        actionHide_Speedometer = new QAction(MainWindow);
        actionHide_Speedometer->setObjectName(QStringLiteral("actionHide_Speedometer"));
        actionHide_Plot_2D = new QAction(MainWindow);
        actionHide_Plot_2D->setObjectName(QStringLiteral("actionHide_Plot_2D"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        customPlot = new QCustomPlot(centralWidget);
        customPlot->setObjectName(QStringLiteral("customPlot"));
        customPlot->setGeometry(QRect(380, 70, 371, 291));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(0, 10, 751, 60));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        comboBox = new QComboBox(layoutWidget);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        horizontalLayout->addWidget(comboBox);

        loadBtn = new QPushButton(layoutWidget);
        loadBtn->setObjectName(QStringLiteral("loadBtn"));

        horizontalLayout->addWidget(loadBtn);

        clearBtn = new QPushButton(layoutWidget);
        clearBtn->setObjectName(QStringLiteral("clearBtn"));

        horizontalLayout->addWidget(clearBtn);

        exitBtn = new QPushButton(layoutWidget);
        exitBtn->setObjectName(QStringLiteral("exitBtn"));

        horizontalLayout->addWidget(exitBtn);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(10, 80, 351, 281));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        graphicsView = new QGraphicsView(widget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));

        verticalLayout->addWidget(graphicsView);

        playBtn = new QPushButton(widget);
        playBtn->setObjectName(QStringLiteral("playBtn"));

        verticalLayout->addWidget(playBtn);

        MainWindow->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 772, 22));
        menuasfsafa = new QMenu(menuBar);
        menuasfsafa->setObjectName(QStringLiteral("menuasfsafa"));
        menuErase_Plot = new QMenu(menuBar);
        menuErase_Plot->setObjectName(QStringLiteral("menuErase_Plot"));
        menuHide_Unhide = new QMenu(menuBar);
        menuHide_Unhide->setObjectName(QStringLiteral("menuHide_Unhide"));
        menuExit = new QMenu(menuBar);
        menuExit->setObjectName(QStringLiteral("menuExit"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuasfsafa->menuAction());
        menuBar->addAction(menuErase_Plot->menuAction());
        menuBar->addAction(menuHide_Unhide->menuAction());
        menuBar->addAction(menuExit->menuAction());
        menuasfsafa->addAction(actionLoad_Configuration);
        menuHide_Unhide->addAction(actionHide_Speedometer);
        menuHide_Unhide->addAction(actionHide_Plot_2D);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        actionLoad_Configuration->setText(QApplication::translate("MainWindow", "Load Configuration", nullptr));
        actionHide_Speedometer->setText(QApplication::translate("MainWindow", "Hide Speedometer", nullptr));
        actionHide_Plot_2D->setText(QApplication::translate("MainWindow", "Hide Plot 2D", nullptr));
        loadBtn->setText(QApplication::translate("MainWindow", "Load", nullptr));
        clearBtn->setText(QApplication::translate("MainWindow", "Erase", nullptr));
        exitBtn->setText(QApplication::translate("MainWindow", "Exit", nullptr));
        playBtn->setText(QApplication::translate("MainWindow", "Play", nullptr));
        menuasfsafa->setTitle(QApplication::translate("MainWindow", "File", nullptr));
        menuErase_Plot->setTitle(QApplication::translate("MainWindow", "Erase Plot", nullptr));
        menuHide_Unhide->setTitle(QApplication::translate("MainWindow", "Hide/Unhide", nullptr));
        menuExit->setTitle(QApplication::translate("MainWindow", "Exit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
