// window.cpp

#include <QWidget>
#include "window.h"
#include "ui_window.h"

#include "myglwidget.h"
#include "calculategirth.h"

int showOnLeft=0;
double showHeight=0.0;
double platSize=1.0;
int redPoints=-25;
extern list<struct node> pclList;

Window::Window(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Window)
{
    ui->setupUi(this);

    connect(ui->myGLWidget, SIGNAL(xRotationChanged(int)), ui->rotXSlider, SLOT(setValue(int)));
    connect(ui->myGLWidget, SIGNAL(yRotationChanged(int)), ui->rotYSlider, SLOT(setValue(int)));
    connect(ui->myGLWidget, SIGNAL(zRotationChanged(int)), ui->rotZSlider, SLOT(setValue(int)));
    ui->doubleSpinBox_2->setValue(platSize);
    ui->horizontalSlider->setValue(int(platSize*100));
}

Window::~Window()
{
    delete ui;
}

void Window::keyPressEvent(QKeyEvent *e)
{
    //if (e->key() == Qt::Key_Escape)
      //  close();
    //else
      //  QWidget::keyPressEvent(e);
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

void Window::on_checkBox_stateChanged(int arg1)
{
    showOnLeft=arg1;
    ui->myGLWidget->updateGL();
}

void Window::on_doubleSpinBox_valueChanged(double arg1)
{
    showHeight=arg1/100;
    ui->myGLWidget->updateGL();
}

void Window::on_pushButton_clicked()
{
    float girth=calculateGirth(pclList,showHeight);
    QString str;
    str.setNum(girth*100);
    ui->lineEdit->setText(str);
}

void Window::on_pushButton_2_clicked()
{
    ui->lineEdit->setText(QString(""));
}

void Window::on_horizontalSlider_valueChanged(int value)
{
    platSize=value/100.0;
    ui->doubleSpinBox_2->setValue(value/100.0);
    ui->myGLWidget->updateGL();
}

void Window::on_doubleSpinBox_2_valueChanged(double arg1)
{
    platSize=arg1;
    ui->horizontalSlider->setValue(int(arg1*100));
    ui->myGLWidget->updateGL();
}

void Window::on_spinBox_valueChanged(int arg1)
{
    redPoints=arg1;
    ui->myGLWidget->updateGL();
}
