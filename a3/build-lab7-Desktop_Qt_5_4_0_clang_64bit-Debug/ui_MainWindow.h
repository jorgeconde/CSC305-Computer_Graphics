/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_frmMain
{
public:
    QGridLayout *gridLayout;
    QScrollArea *glWidgetArea;
    QWidget *scrollAreaWidgetContents;
    QLabel *label;
    QLabel *label_2;
    QFrame *controlFrame;
    QPushButton *pushButton;
    QPushButton *pushButton_4;
    QPushButton *pushButton_3;
    QPushButton *pushButton_2;

    void setupUi(QWidget *frmMain)
    {
        if (frmMain->objectName().isEmpty())
            frmMain->setObjectName(QStringLiteral("frmMain"));
        frmMain->resize(1058, 874);
        gridLayout = new QGridLayout(frmMain);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        glWidgetArea = new QScrollArea(frmMain);
        glWidgetArea->setObjectName(QStringLiteral("glWidgetArea"));
        QSizePolicy sizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(glWidgetArea->sizePolicy().hasHeightForWidth());
        glWidgetArea->setSizePolicy(sizePolicy);
        glWidgetArea->setMinimumSize(QSize(580, 470));
        glWidgetArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        glWidgetArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        glWidgetArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 816, 816));
        glWidgetArea->setWidget(scrollAreaWidgetContents);

        gridLayout->addWidget(glWidgetArea, 1, 2, 1, 2);

        label = new QLabel(frmMain);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(100, 16));
        label->setMaximumSize(QSize(100, 16));

        gridLayout->addWidget(label, 0, 1, 1, 1);

        label_2 = new QLabel(frmMain);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMinimumSize(QSize(100, 16));
        label_2->setMaximumSize(QSize(100, 16));

        gridLayout->addWidget(label_2, 0, 2, 1, 1);

        controlFrame = new QFrame(frmMain);
        controlFrame->setObjectName(QStringLiteral("controlFrame"));
        controlFrame->setMinimumSize(QSize(200, 470));
        controlFrame->setMaximumSize(QSize(200, 16777215));
        controlFrame->setFrameShape(QFrame::StyledPanel);
        controlFrame->setFrameShadow(QFrame::Raised);
        pushButton = new QPushButton(controlFrame);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(25, 25, 150, 50));
        pushButton_4 = new QPushButton(controlFrame);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(25, 550, 150, 32));
        pushButton_3 = new QPushButton(controlFrame);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(25, 175, 150, 48));
        pushButton_2 = new QPushButton(controlFrame);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(25, 100, 150, 50));

        gridLayout->addWidget(controlFrame, 1, 1, 1, 1);


        retranslateUi(frmMain);
        QObject::connect(pushButton, SIGNAL(clicked()), frmMain, SLOT(openImage()));
        QObject::connect(pushButton_2, SIGNAL(clicked()), frmMain, SLOT(saveImage()));
        QObject::connect(pushButton_3, SIGNAL(clicked()), frmMain, SLOT(makeImage()));
        QObject::connect(pushButton_4, SIGNAL(clicked()), frmMain, SLOT(close()));

        QMetaObject::connectSlotsByName(frmMain);
    } // setupUi

    void retranslateUi(QWidget *frmMain)
    {
        frmMain->setWindowTitle(QApplication::translate("frmMain", "QT skeleton - BW 2014", 0));
        label->setText(QApplication::translate("frmMain", "Control Panel", 0));
        label_2->setText(QApplication::translate("frmMain", "OpenGL Window", 0));
        pushButton->setText(QApplication::translate("frmMain", "Open Image", 0));
        pushButton_4->setText(QApplication::translate("frmMain", "Quit", 0));
        pushButton_3->setText(QApplication::translate("frmMain", "Make Image", 0));
        pushButton_2->setText(QApplication::translate("frmMain", "Save Image", 0));
    } // retranslateUi

};

namespace Ui {
    class frmMain: public Ui_frmMain {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
