// window.cpp

#include <QWidget>
#include "window.h"
#include "ui_window.h"

#include "myglwidget.h"
#include "calculategirth.h"

extern char * filename;
//extern list<struct node> pclList;
void rigidTransform(float &x,float &y,float &z,int rotx,int roty,int rotz);

Window::Window(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Window)
{
    ui->setupUi(this);

    connect(ui->myGLWidget, SIGNAL(xRotationChanged(int)), ui->rotXSlider, SLOT(setValue(int)));
    connect(ui->myGLWidget, SIGNAL(yRotationChanged(int)), ui->rotYSlider, SLOT(setValue(int)));
    connect(ui->myGLWidget, SIGNAL(zRotationChanged(int)), ui->rotZSlider, SLOT(setValue(int)));
    ui->doubleSpinBox_2->setValue(ui->myGLWidget->platSize);
    ui->horizontalSlider->setValue(int(ui->myGLWidget->platSize*100));
    //ui->widget->setXRotation(90);
    ui->myGLWidget->getPoints(filename);
    ui->widget->redPoints=0;
    //ui->checkBox_2->clicked((bool)ui->myGLWidget->showAxis);//no use

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
    ui->myGLWidget->showPlat=arg1;
    ui->myGLWidget->updateGL();
}

void Window::on_doubleSpinBox_valueChanged(double arg1)
{
    ui->myGLWidget->platHeight=arg1/100;
    ui->myGLWidget->updateGL();
}

void Window::on_pushButton_clicked()
{
    ui->widget->pclList.clear();
    list<struct node> tmpPclList;
    list<struct node>::iterator it;
    for(it=ui->myGLWidget->pclList.begin();it!=ui->myGLWidget->pclList.end();++it)
    {
        struct node tmpnode;
        tmpnode.x=(*it).x;tmpnode.y=(*it).y;tmpnode.z=(*it).z;
        rigidTransform(tmpnode.x,tmpnode.y,tmpnode.z,ui->myGLWidget->xPointRot,ui->myGLWidget->yPointRot,ui->myGLWidget->zPointRot);
        tmpPclList.push_back(tmpnode);
    }
    float girth=calculateGirth(tmpPclList,ui->myGLWidget->platHeight,ui->doubleSpinBox_3->value()/100.0,ui->widget->pclList);
    QString str;
    str.setNum(girth*100);
    ui->lineEdit->setText(str);

    ui->widget->updateGL();
}

void Window::on_pushButton_2_clicked()
{
    ui->lineEdit->setText(QString(""));
    ui->widget->pclList.clear();
    ui->widget->updateGL();
}

void Window::on_horizontalSlider_valueChanged(int value)
{
    ui->myGLWidget->platSize=value/100.0;
    ui->doubleSpinBox_2->setValue(value/100.0);
    ui->myGLWidget->updateGL();
}

void Window::on_doubleSpinBox_2_valueChanged(double arg1)
{
    ui->myGLWidget->platSize=arg1;
    ui->horizontalSlider->setValue(int(arg1*100));
    ui->myGLWidget->updateGL();
}

void Window::on_spinBox_valueChanged(int arg1)
{
    ui->myGLWidget->redPoints=arg1;

    ui->myGLWidget->updateGL();
    ui->LastRedPoint_LineEdit->setText(ui->myGLWidget->lastRedPoint);
}

void Window::on_pushButton_3_clicked()
{
    int tmpvalue=ui->spinBox->value();
    ui->spinBox->setValue(-tmpvalue);
}

void Window::on_spinBox_4_valueChanged(int arg1)
{
    ui->myGLWidget->xPointRot=arg1;
    ui->myGLWidget->updateGL();
}

void Window::on_spinBox_3_valueChanged(int arg1)
{
    ui->myGLWidget->yPointRot=arg1;
    ui->myGLWidget->updateGL();
}

void Window::on_spinBox_2_valueChanged(int arg1)
{
    ui->myGLWidget->zPointRot=arg1;
    ui->myGLWidget->updateGL();
}

void Window::on_checkBox_2_stateChanged(int arg1)
{
    ui->myGLWidget->showAxis=arg1;
    ui->widget->showAxis=arg1;
    ui->myGLWidget->updateGL();
    ui->widget->updateGL();
}

void Window::on_doubleSpinBox_4_valueChanged(double arg1)
{
    ui->myGLWidget->greenPointX=arg1;
    ui->myGLWidget->updateGL();
}

void Window::on_doubleSpinBox_5_valueChanged(double arg1)
{
    ui->myGLWidget->greenPointY=arg1;
    ui->myGLWidget->updateGL();
}

void Window::on_doubleSpinBox_6_valueChanged(double arg1)
{
    ui->myGLWidget->greenPointZ=arg1;
    ui->myGLWidget->updateGL();
}
