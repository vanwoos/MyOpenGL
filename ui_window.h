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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "myglwidget.h"

QT_BEGIN_NAMESPACE

class Ui_Window
{
public:
    QVBoxLayout *verticalLayout;
    MyGLWidget *myGLWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpinBox *rotXSpinBox;
    QSlider *rotXSlider;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QSpinBox *rotYSpinBox;
    QSlider *rotYSlider;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QSpinBox *rotZSpinBox;
    QSlider *rotZSlider;

    void setupUi(QWidget *Window)
    {
        if (Window->objectName().isEmpty())
            Window->setObjectName(QStringLiteral("Window"));
        Window->resize(350, 350);
        verticalLayout = new QVBoxLayout(Window);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        myGLWidget = new MyGLWidget(Window);
        myGLWidget->setObjectName(QStringLiteral("myGLWidget"));
        myGLWidget->setMinimumSize(QSize(200, 200));

        verticalLayout->addWidget(myGLWidget);

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


        verticalLayout->addLayout(horizontalLayout);

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


        verticalLayout->addLayout(horizontalLayout_2);

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


        verticalLayout->addLayout(horizontalLayout_3);


        retranslateUi(Window);
        QObject::connect(rotXSlider, SIGNAL(valueChanged(int)), myGLWidget, SLOT(setXRotation(int)));
        QObject::connect(rotYSlider, SIGNAL(valueChanged(int)), myGLWidget, SLOT(setYRotation(int)));
        QObject::connect(rotZSlider, SIGNAL(valueChanged(int)), myGLWidget, SLOT(setZRotation(int)));

        QMetaObject::connectSlotsByName(Window);
    } // setupUi

    void retranslateUi(QWidget *Window)
    {
        Window->setWindowTitle(QApplication::translate("Window", "Window", 0));
        label->setText(QApplication::translate("Window", "xRot", 0));
        label_2->setText(QApplication::translate("Window", "yRot", 0));
        label_3->setText(QApplication::translate("Window", "zRot", 0));
    } // retranslateUi

};

namespace Ui {
    class Window: public Ui_Window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOW_H
