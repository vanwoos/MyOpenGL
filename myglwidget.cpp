// myglwidget.cpp

#include <QtWidgets>
#include <QtOpenGL>

#include "myglwidget.h"

MyGLWidget::MyGLWidget(QWidget *parent)
    : QGLWidget(QGLFormat(QGL::SampleBuffers), parent)
{
    xRot = 0;
    yRot = 0;
    zRot = 0;
    xTrans=0;
    yTrans=0;
}

MyGLWidget::~MyGLWidget()
{
}

QSize MyGLWidget::minimumSizeHint() const
{
    return QSize(50, 50);
}

QSize MyGLWidget::sizeHint() const
{
    return QSize(400, 400);
}

static void qNormalizeAngle(int &angle)
{
    while (angle < 0)
        angle += 360;
    while (angle > 360)
        angle -= 360;
}

void MyGLWidget::setXRotation(int angle)
{
    qNormalizeAngle(angle);
    if (angle != xRot) {
        xRot = angle;
        emit xRotationChanged(angle);
        updateGL();
    }
}

void MyGLWidget::setYRotation(int angle)
{
    qNormalizeAngle(angle);
    if (angle != yRot) {
        yRot = angle;
        emit yRotationChanged(angle);
        updateGL();
    }
}

void MyGLWidget::setZRotation(int angle)
{
    qNormalizeAngle(angle);
    if (angle != zRot) {
        zRot = angle;
        emit zRotationChanged(angle);
        updateGL();
    }
}

void MyGLWidget::initializeGL()
{
    qglClearColor(Qt::black);

    //glEnable(GL_DEPTH_TEST);
    //glEnable(GL_CULL_FACE);
    glShadeModel(GL_SMOOTH);
    //glEnable(GL_LIGHTING);
    //glEnable(GL_LIGHT0);
    glPointSize(1.0);
    glLineWidth(1.0);

    //static GLfloat lightPosition[4] = { 0, 0, 10, 1.0 };
    //glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
}

void MyGLWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(xTrans, yTrans, -10.0);
    glRotatef(xRot / 1.0, 1.0, 0.0, 0.0);
    glRotatef(yRot / 1.0, 0.0, 1.0, 0.0);
    glRotatef(zRot / 1.0, 0.0, 0.0, 1.0);
    //draw();
    drawCoordinate();
}

void MyGLWidget::resizeGL(int width, int height)
{
    int side = qMin(width, height);
    glViewport((width - side) / 2, (height - side) / 2, side, side);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
#ifdef QT_OPENGL_ES_1
    glOrthof(-2, +2, -2, +2, 1.0, 15.0);
#else
    glOrtho(-2, +2, -2, +2, 1.0, 15.0);
#endif
    glMatrixMode(GL_MODELVIEW);
}

void MyGLWidget::mousePressEvent(QMouseEvent *event)
{
    lastPos = event->pos();
}


void MyGLWidget::mouseMoveEvent(QMouseEvent *event)
{
    int dx = event->x() - lastPos.x();
    int dy = event->y() - lastPos.y();

    if (event->buttons() & Qt::LeftButton) {
        setXRotation(xRot + 1 * dy);
        setYRotation(yRot + 1 * dx);
    } else if (event->buttons() & Qt::RightButton) {
        xTrans+=dx/50.0;
        yTrans-=dy/50.0;
        updateGL();
        //setXRotation(xRot + 1 * dy);
        //setZRotation(zRot + 1 * dx);
    }else if(event->buttons() & Qt::MiddleButton)
    {
        setXRotation(xRot + 1 * dy);
        setYRotation(yRot + 1 * dx);
    }

    lastPos = event->pos();
}

void MyGLWidget::wheelEvent(QWheelEvent *event)
{
    event->delta();

}

void MyGLWidget::draw()
{
    qglColor(Qt::red);

}

void MyGLWidget::drawCoordinate()
{
    //qglColor(Qt::red);
    glBegin(GL_LINES);
        //glNormal3f(1,0, 0.707);
        glColor3f(1.0,0.0,0.0);//x coordinate
        glVertex3f(10,0,0);
        glVertex3f(0,0,0);
        glColor3f(0.0,1.0,0.0);//y coordinate
        glVertex3f(0,10,0);
        glVertex3f(0,0,0);
        glColor3f(0.0,0.0,1.0);//z coordinate
        glVertex3f(0,0,10);
        glVertex3f(0,0,0);
    glEnd();
    glBegin(GL_TRIANGLES);
        glColor3f(1.0,1.0,0.0);
        //glNormal3f(0,1,0.707);
        glVertex3f(1,1,0);
        glVertex3f(-1,1,0);
        glVertex3f(0,0,1.2);
    glEnd();
    /*glBegin(GL_TRIANGLES);
        glNormal3f(0,-1,0.707);
        glVertex3f(-1,-1,0);
        glVertex3f(1,-1,0);
        glVertex3f(0,0,1.2);
    glEnd();
    glBegin(GL_TRIANGLES);
        glNormal3f(1,0, 0.707);
        glVertex3f(1,-1,0);
        glVertex3f(1,1,0);
        glVertex3f(0,0,1.2);
    glEnd();
    glBegin(GL_TRIANGLES);
        glNormal3f(0,1,0.707);
        glVertex3f(1,1,0);
        glVertex3f(-1,1,0);
        glVertex3f(0,0,1.2);
    glEnd();
    glBegin(GL_TRIANGLES);
        glNormal3f(-1,0,0.707);
        glVertex3f(-1,1,0);
        glVertex3f(-1,-1,0);
        glVertex3f(0,0,1.2);
    glEnd();*/
}
