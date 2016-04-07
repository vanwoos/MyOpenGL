// window.cpp

#include <QtWidgets>
#include "window.h"
#include "ui_window.h"

#include "myglwidget.h"

Window::Window(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Window)
{
    ui->setupUi(this);

    connect(ui->myGLWidget, SIGNAL(xRotationChanged(int)), ui->rotXSlider, SLOT(setValue(int)));
    connect(ui->myGLWidget, SIGNAL(yRotationChanged(int)), ui->rotYSlider, SLOT(setValue(int)));
    connect(ui->myGLWidget, SIGNAL(zRotationChanged(int)), ui->rotZSlider, SLOT(setValue(int)));
}

Window::~Window()
{
    delete ui;
}

void Window::keyPressEvent(QKeyEvent *e)
{
    if (e->key() == Qt::Key_Escape)
        close();
    else
        QWidget::keyPressEvent(e);
}

void Window::on_rotXSlider_valueChanged(int value)
{
    ui->rotXSpinBox->setValue(value);
}

void Window::on_rotYSlider_valueChanged(int value)
{
    ui->rotYSpinBox->setValue(value);
}

void Window::on_rotZSlider_valueChanged(int value)
{
    ui->rotZSpinBox->setValue(value);
}

void Window::on_rotXSpinBox_valueChanged(int arg1)
{
    ui->rotXSlider->setValue(arg1);
}

void Window::on_rotYSpinBox_valueChanged(int arg1)
{
    ui->rotYSlider->setValue(arg1);
}

void Window::on_rotZSpinBox_valueChanged(int arg1)
{
    ui->rotZSlider->setValue(arg1);
}
