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
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *addValueBtn;
    QPushButton *clearBtn;
    QCustomPlot *customPlot;
    QDoubleSpinBox *Yspinbox;
    QDoubleSpinBox *Xspinbox;
    QMenuBar *menuBar;
    QMenu *menuMain_window;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(734, 572);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        addValueBtn = new QPushButton(centralWidget);
        addValueBtn->setObjectName(QStringLiteral("addValueBtn"));
        addValueBtn->setGeometry(QRect(520, 20, 89, 25));
        clearBtn = new QPushButton(centralWidget);
        clearBtn->setObjectName(QStringLiteral("clearBtn"));
        clearBtn->setGeometry(QRect(620, 20, 89, 25));
        customPlot = new QCustomPlot(centralWidget);
        customPlot->setObjectName(QStringLiteral("customPlot"));
        customPlot->setGeometry(QRect(100, 100, 551, 351));
        Yspinbox = new QDoubleSpinBox(centralWidget);
        Yspinbox->setObjectName(QStringLiteral("Yspinbox"));
        Yspinbox->setGeometry(QRect(420, 20, 69, 26));
        Xspinbox = new QDoubleSpinBox(centralWidget);
        Xspinbox->setObjectName(QStringLiteral("Xspinbox"));
        Xspinbox->setGeometry(QRect(330, 20, 69, 26));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 734, 22));
        menuMain_window = new QMenu(menuBar);
        menuMain_window->setObjectName(QStringLiteral("menuMain_window"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuMain_window->menuAction());

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        addValueBtn->setText(QApplication::translate("MainWindow", "Add", nullptr));
        clearBtn->setText(QApplication::translate("MainWindow", "Clear", nullptr));
        menuMain_window->setTitle(QApplication::translate("MainWindow", "Main window", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
