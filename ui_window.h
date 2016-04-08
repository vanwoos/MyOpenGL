/********************************************************************************
** Form generated from reading UI file 'window.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINDOW_H
#define UI_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "myglwidget.h"

QT_BEGIN_NAMESPACE

class Ui_Window
{
public:
    QGridLayout *gridLayout;
    MyGLWidget *myGLWidget;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QSpinBox *rotZSpinBox;
    QSlider *rotZSlider;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QSpinBox *rotYSpinBox;
    QSlider *rotYSlider;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpinBox *rotXSpinBox;
    QSlider *rotXSlider;
    QFormLayout *formLayout;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_7;
    QCheckBox *checkBox;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QDoubleSpinBox *doubleSpinBox;
    QPushButton *pushButton;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_5;
    QLineEdit *lineEdit;
    QPushButton *pushButton_2;
    QHBoxLayout *horizontalLayout_9;

    void setupUi(QWidget *Window)
    {
        if (Window->objectName().isEmpty())
            Window->setObjectName(QStringLiteral("Window"));
        Window->resize(364, 350);
        gridLayout = new QGridLayout(Window);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(9, -1, -1, -1);
        myGLWidget = new MyGLWidget(Window);
        myGLWidget->setObjectName(QStringLiteral("myGLWidget"));
        myGLWidget->setEnabled(true);
        myGLWidget->setMinimumSize(QSize(200, 200));

        gridLayout->addWidget(myGLWidget, 0, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_3 = new QLabel(Window);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_3->addWidget(label_3);

        rotZSpinBox = new QSpinBox(Window);
        rotZSpinBox->setObjectName(QStringLiteral("rotZSpinBox"));
        rotZSpinBox->setMaximum(360);

        horizontalLayout_3->addWidget(rotZSpinBox);

        rotZSlider = new QSlider(Window);
        rotZSlider->setObjectName(QStringLiteral("rotZSlider"));
        rotZSlider->setMaximum(360);
        rotZSlider->setOrientation(Qt::Horizontal);
        rotZSlider->setTickPosition(QSlider::TicksAbove);
        rotZSlider->setTickInterval(15);

        horizontalLayout_3->addWidget(rotZSlider);


        gridLayout->addLayout(horizontalLayout_3, 3, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(Window);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        rotYSpinBox = new QSpinBox(Window);
        rotYSpinBox->setObjectName(QStringLiteral("rotYSpinBox"));
        rotYSpinBox->setMaximum(360);

        horizontalLayout_2->addWidget(rotYSpinBox);

        rotYSlider = new QSlider(Window);
        rotYSlider->setObjectName(QStringLiteral("rotYSlider"));
        rotYSlider->setLayoutDirection(Qt::LeftToRight);
        rotYSlider->setMaximum(360);
        rotYSlider->setOrientation(Qt::Horizontal);
        rotYSlider->setTickPosition(QSlider::TicksAbove);
        rotYSlider->setTickInterval(15);

        horizontalLayout_2->addWidget(rotYSlider);


        gridLayout->addLayout(horizontalLayout_2, 2, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(Window);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        rotXSpinBox = new QSpinBox(Window);
        rotXSpinBox->setObjectName(QStringLiteral("rotXSpinBox"));
        rotXSpinBox->setMaximum(360);

        horizontalLayout->addWidget(rotXSpinBox);

        rotXSlider = new QSlider(Window);
        rotXSlider->setObjectName(QStringLiteral("rotXSlider"));
        rotXSlider->setCursor(QCursor(Qt::ArrowCursor));
        rotXSlider->setMinimum(0);
        rotXSlider->setMaximum(360);
        rotXSlider->setOrientation(Qt::Horizontal);
        rotXSlider->setTickPosition(QSlider::TicksAbove);
        rotXSlider->setTickInterval(15);

        horizontalLayout->addWidget(rotXSlider);


        gridLayout->addLayout(horizontalLayout, 1, 0, 1, 1);

        formLayout = new QFormLayout();
        formLayout->setSpacing(6);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        checkBox = new QCheckBox(Window);
        checkBox->setObjectName(QStringLiteral("checkBox"));

        horizontalLayout_7->addWidget(checkBox);


        verticalLayout_2->addLayout(horizontalLayout_7);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_4 = new QLabel(Window);
        label_4->setObjectName(QStringLiteral("label_4"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy);

        horizontalLayout_4->addWidget(label_4);

        doubleSpinBox = new QDoubleSpinBox(Window);
        doubleSpinBox->setObjectName(QStringLiteral("doubleSpinBox"));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(doubleSpinBox->sizePolicy().hasHeightForWidth());
        doubleSpinBox->setSizePolicy(sizePolicy1);
        QFont font;
        font.setBold(false);
        font.setItalic(false);
        font.setUnderline(false);
        font.setWeight(50);
        font.setStrikeOut(false);
        doubleSpinBox->setFont(font);
        doubleSpinBox->setDecimals(1);
        doubleSpinBox->setMinimum(-200);
        doubleSpinBox->setMaximum(200);
        doubleSpinBox->setSingleStep(1);

        horizontalLayout_4->addWidget(doubleSpinBox);


        verticalLayout_2->addLayout(horizontalLayout_4);

        pushButton = new QPushButton(Window);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout_2->addWidget(pushButton);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        label_5 = new QLabel(Window);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_10->addWidget(label_5);

        lineEdit = new QLineEdit(Window);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(lineEdit->sizePolicy().hasHeightForWidth());
        lineEdit->setSizePolicy(sizePolicy2);
        lineEdit->setReadOnly(true);
        lineEdit->setClearButtonEnabled(false);

        horizontalLayout_10->addWidget(lineEdit);

        pushButton_2 = new QPushButton(Window);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        sizePolicy2.setHeightForWidth(pushButton_2->sizePolicy().hasHeightForWidth());
        pushButton_2->setSizePolicy(sizePolicy2);

        horizontalLayout_10->addWidget(pushButton_2);


        verticalLayout_2->addLayout(horizontalLayout_10);


        formLayout->setLayout(0, QFormLayout::FieldRole, verticalLayout_2);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));

        formLayout->setLayout(1, QFormLayout::FieldRole, horizontalLayout_9);


        gridLayout->addLayout(formLayout, 0, 2, 4, 1);


        retranslateUi(Window);
        QObject::connect(rotXSlider, SIGNAL(valueChanged(int)), myGLWidget, SLOT(setXRotation(int)));
        QObject::connect(rotYSlider, SIGNAL(valueChanged(int)), myGLWidget, SLOT(setYRotation(int)));
        QObject::connect(rotZSlider, SIGNAL(valueChanged(int)), myGLWidget, SLOT(setZRotation(int)));

        QMetaObject::connectSlotsByName(Window);
    } // setupUi

    void retranslateUi(QWidget *Window)
    {
        Window->setWindowTitle(QApplication::translate("Window", "Window", 0));
        label_3->setText(QApplication::translate("Window", "zRot", 0));
        label_2->setText(QApplication::translate("Window", "yRot", 0));
        label->setText(QApplication::translate("Window", "xRot", 0));
        checkBox->setText(QApplication::translate("Window", "showOnLeft", 0));
        label_4->setText(QApplication::translate("Window", "Height(cm):", 0));
        doubleSpinBox->setPrefix(QString());
        pushButton->setText(QApplication::translate("Window", "CalGirth", 0));
        label_5->setText(QApplication::translate("Window", "Girth(cm):", 0));
        pushButton_2->setText(QApplication::translate("Window", "Clear", 0));
    } // retranslateUi

};

namespace Ui {
    class Window: public Ui_Window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOW_H
