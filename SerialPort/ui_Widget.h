/********************************************************************************
** Form generated from reading UI file 'Widget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QComboBox *portsComboBox;
    QPushButton *rescanPortsButton;
    QSpacerItem *horizontalSpacer;
    QLabel *connectedJudgesLabel;
    QPushButton *startStopButton;
    QPushButton *newFightButton;
    QHBoxLayout *horizontalLayout_2;
    QLabel *competitor1points;
    QLabel *competitor2points;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(1212, 585);
        Widget->setStyleSheet(QString::fromUtf8("QWidget\n"
"{\n"
"background-color: rgb(255, 255, 255);\n"
"}"));
        verticalLayout = new QVBoxLayout(Widget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(Widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setEnabled(false);
        label->setMinimumSize(QSize(220, 50));
        label->setMaximumSize(QSize(250, 50));
        label->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"color: rgb(255, 178, 42);\n"
"border-radius: 10px;\n"
"font: 75 24pt \"MS Shell Dlg 2\";\n"
"}\n"
"\n"
""));
        label->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label);

        portsComboBox = new QComboBox(Widget);
        portsComboBox->setObjectName(QString::fromUtf8("portsComboBox"));
        portsComboBox->setMinimumSize(QSize(190, 40));
        portsComboBox->setMaximumSize(QSize(190, 40));
        portsComboBox->setStyleSheet(QString::fromUtf8("QComboBox\n"
"{\n"
"border: 1px solid gray;\n"
"border-radius: 3px;\n"
"padding: 1px 18px 1px 3px;\n"
"background-color:rgb(255, 178, 42);\n"
"color: white;\n"
"	font: 30px \"MS Shell Dlg 2\";\n"
"}\n"
"QComboBox QAbstractItemView{background: rgb(255, 178, 42);}\n"
"\n"
"QComboBox::item:selected\n"
"{\n"
"    background-color: rgb(255, 190, 50);\n"
"    color: rgb(0, 0, 0);\n"
"}\n"
"QComboBox::drop-down {\n"
"    width: 70px;\n"
"}\n"
"\n"
"QComboBox::indicator{\n"
"    background-color:transparent;\n"
"    selection-background-color:transparent;\n"
"    color:transparent;\n"
"    selection-color:transparent;\n"
"}"));
        portsComboBox->setSizeAdjustPolicy(QComboBox::AdjustToContentsOnFirstShow);

        horizontalLayout->addWidget(portsComboBox);

        rescanPortsButton = new QPushButton(Widget);
        rescanPortsButton->setObjectName(QString::fromUtf8("rescanPortsButton"));
        rescanPortsButton->setMinimumSize(QSize(40, 40));
        rescanPortsButton->setMaximumSize(QSize(40, 40));
        rescanPortsButton->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"color: white;\n"
"background-color: rgb(255, 178, 42);\n"
"border-radius: 10px;\n"
"font: 75 24pt \"MS Shell Dlg 2\";\n"
"}\n"
"\n"
"QPushButton:hover:!pressed\n"
"{\n"
"background-color: rgb(255, 190, 50);\n"
"}"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/img/res/img/refresh.png"), QSize(), QIcon::Normal, QIcon::Off);
        rescanPortsButton->setIcon(icon);
        rescanPortsButton->setIconSize(QSize(30, 30));

        horizontalLayout->addWidget(rescanPortsButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        connectedJudgesLabel = new QLabel(Widget);
        connectedJudgesLabel->setObjectName(QString::fromUtf8("connectedJudgesLabel"));
        connectedJudgesLabel->setEnabled(false);
        connectedJudgesLabel->setMinimumSize(QSize(400, 50));
        connectedJudgesLabel->setMaximumSize(QSize(420, 50));
        connectedJudgesLabel->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"color: rgb(255, 178, 42);\n"
"border-radius: 10px;\n"
"font: 75 18pt \"MS Shell Dlg 2\";\n"
"}\n"
"\n"
""));
        connectedJudgesLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout->addWidget(connectedJudgesLabel);

        startStopButton = new QPushButton(Widget);
        startStopButton->setObjectName(QString::fromUtf8("startStopButton"));
        startStopButton->setMinimumSize(QSize(40, 40));
        startStopButton->setMaximumSize(QSize(40, 40));
        startStopButton->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"color: white;\n"
"background-color: rgb(255, 178, 42);\n"
"border-radius: 10px;\n"
"font: 75 24pt \"MS Shell Dlg 2\";\n"
"}\n"
"\n"
"QPushButton:hover:!pressed\n"
"{\n"
"background-color: rgb(255, 190, 50);\n"
"}"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/img/res/img/play.png"), QSize(), QIcon::Normal, QIcon::Off);
        startStopButton->setIcon(icon1);
        startStopButton->setIconSize(QSize(30, 30));

        horizontalLayout->addWidget(startStopButton);

        newFightButton = new QPushButton(Widget);
        newFightButton->setObjectName(QString::fromUtf8("newFightButton"));
        newFightButton->setMinimumSize(QSize(40, 40));
        newFightButton->setMaximumSize(QSize(40, 40));
        newFightButton->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"color: white;\n"
"background-color: rgb(255, 178, 42);\n"
"border-radius: 10px;\n"
"font: 75 24pt \"MS Shell Dlg 2\";\n"
"}\n"
"\n"
"QPushButton:hover:!pressed\n"
"{\n"
"background-color: rgb(255, 190, 50);\n"
"}"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/img/res/img/clean.png"), QSize(), QIcon::Normal, QIcon::Off);
        newFightButton->setIcon(icon2);
        newFightButton->setIconSize(QSize(30, 30));

        horizontalLayout->addWidget(newFightButton);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(15);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(-1, -1, -1, 0);
        competitor1points = new QLabel(Widget);
        competitor1points->setObjectName(QString::fromUtf8("competitor1points"));
        competitor1points->setMinimumSize(QSize(300, 299));
        competitor1points->setMaximumSize(QSize(3000000, 3000000));
        competitor1points->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"color: rgb(255, 255, 255);\n"
"	background-color: rgb(255, 0, 0);\n"
"	font: 75 400pt \"MS Shell Dlg 2\";\n"
"qproperty-alignment: 'AlignCenter | AlignCenter';\n"
"}"));

        horizontalLayout_2->addWidget(competitor1points);

        competitor2points = new QLabel(Widget);
        competitor2points->setObjectName(QString::fromUtf8("competitor2points"));
        competitor2points->setMinimumSize(QSize(300, 300));
        competitor2points->setMaximumSize(QSize(300000, 300000));
        competitor2points->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"color: rgb(255, 255, 255);\n"
"	background-color: rgb(0, 0, 255);\n"
"	font: 75 400pt \"MS Shell Dlg 2\";\n"
"qproperty-alignment: 'AlignCenter | AlignCenter';\n"
"}"));

        horizontalLayout_2->addWidget(competitor2points);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", nullptr));
        label->setText(QApplication::translate("Widget", "Select port:", nullptr));
        rescanPortsButton->setText(QString());
        connectedJudgesLabel->setText(QApplication::translate("Widget", "Connected judges:", nullptr));
        startStopButton->setText(QString());
        newFightButton->setText(QString());
        competitor1points->setText(QApplication::translate("Widget", "0", nullptr));
        competitor2points->setText(QApplication::translate("Widget", "0", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
