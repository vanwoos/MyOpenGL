// myglwidget.cpp

#include <QWidget>
#include <QtOpenGL>

#include "myglwidget.h"






int MyGLWidget::getPoints(char *filename)
{
    if(filename==NULL) return -1;
    FILE * fp=fopen(filename,"r");
    if(fp==NULL) return -1;
    struct node tmpNode;
    //printf("start read file %sx\n",filename);
    while(!feof(fp))
    {
        fscanf(fp,"%f %f %f\n",&tmpNode.x,&tmpNode.y,&tmpNode.z);
        pclList.push_back(tmpNode);
        //printf("%f %f %f\n",tmpNode.x,tmpNode.y,tmpNode.z);
        //glVertex3f(x/2,y/2,z/2);
    }
    fclose(fp);
    fp=NULL;
    return 0;
}

int MyGLWidget::printPoints()
{
    list<struct node>::iterator it;

    glColor3f(1.0,1.0,1.0);
    //printf("start print points\n");
    for(it=pclList.begin();it!=pclList.end();++it)
    {
        glBegin(GL_POINTS);
        glVertex3f((*it).x,(*it).y,(*it).z);
        glEnd();
        //printf("%f %f %f\n",(*it).x,(*it).y,(*it).z);
    }
    glColor3f(1.0,0.0,0.0);
    glPointSize(5.0);
    {//draw red points
        int i=abs(this->redPoints);
        //i=25;
        if(redPoints>0)
        {
            for(it=pclList.begin();it!=pclList.end();++it)
            {
                --i;
                if(i<0) break;
                glBegin(GL_POINTS);
                glVertex3f((*it).x,(*it).y,(*it).z);
                glEnd();
            }
        }
        else{
            for(it=pclList.end();it!=pclList.begin();--it)
            {
                --i;
                if(i<0) break;
                glBegin(GL_POINTS);
                glVertex3f((*it).x,(*it).y,(*it).z);
                glEnd();
            }
        }
    }
    glColor3f(1.0,1.0,1.0);
    glPointSize(1.0);
    return 0;
}

MyGLWidget::MyGLWidget(QWidget *parent)
    : QGLWidget(QGLFormat(QGL::SampleBuffers), parent)
{
    this->xRot = 0;
    this->yRot = 0;
    this->zRot = 0;
    this->xTrans=0;
    this->yTrans=0;
    this->viewSided=0;
    this->showPlat=0;
    this->platHeight=0.0;
    this->platSize=1.0;
    this->redPoints=-25;
    //getPoints(filename);
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
    //qglClearColor(Qt::white);
    glClearColor(0.0,0.0,0.0,0.0);
    glEnable(GL_DEPTH_TEST);
    //glEnable(GL_CULL_FACE);
    //glShadeModel(GL_SMOOTH);
    //glEnable(GL_LIGHTING);
    //glEnable(GL_LIGHT0);
    glPointSize(1.0);
    glLineWidth(1.0);


    //static GLfloat lightPosition[4] = { 0, 0, 10, 1.0 };
    //glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
}

void MyGLWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    //this->viewSided=1000;
    int side = qMin(this->viewWidth, this->viewHeight);
    glViewport((this->viewWidth - side) / 2-this->viewSided/2, (this->viewHeight - side) / 2-this->viewSided/2, side+this->viewSided, side+this->viewSided);
    glLoadIdentity();
    glScaled(1,1,1);
    glTranslatef(xTrans, yTrans, -10.0);
    glRotatef(xRot / 1.0, 1.0, 0.0, 0.0);
    glRotatef(yRot / 1.0, 0.0, 1.0, 0.0);
    glRotatef(zRot / 1.0, 0.0, 0.0, 1.0);
    if(this->showPlat)
    {
        glBegin(GL_QUADS);
            //glNormal3f(1,0, 0.707);
            glColor3f(1.0,1.0,0.0);//x coordinate
            glVertex3f(-platSize,platHeight,-platSize);
            glVertex3f(-platSize,platHeight,platSize);
            glVertex3f(platSize,platHeight,platSize);
            glVertex3f(platSize,platHeight,-platSize);
        glEnd();
        glBegin(GL_LINES);
            //glNormal3f(1,0, 0.707);
            glColor3f(1.0,1.0,0.0);//x coordinate
            glVertex3f(-platSize,platHeight,-platSize);
            glVertex3f(-platSize,platHeight,platSize);
            glVertex3f(-platSize,platHeight,platSize);
            glVertex3f(platSize,platHeight,platSize);
            glVertex3f(platSize,platHeight,platSize);
            glVertex3f(platSize,platHeight,-platSize);
            glVertex3f(platSize,platHeight,-platSize);
            glVertex3f(-platSize,platHeight,-platSize);
        glEnd();
    }
    //draw();
    printPoints();
    drawCoordinate();
}

void MyGLWidget::resizeGL(int width, int height)
{
    this->viewWidth=width;this->viewHeight=height;
    int side = qMin(this->viewWidth, this->viewHeight);
    glViewport((this->viewWidth - side) / 2, (this->viewHeight - side) / 2, side, side);

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
        setXRotation(xRot + 0.5 * dy);
        setYRotation(yRot + 0.5 * dx);
    } else if (event->buttons() & Qt::RightButton) {
        xTrans+=dx/50.0;
        yTrans-=dy/50.0;
        updateGL();
        //setXRotation(xRot + 1 * dy);
        //setZRotation(zRot + 1 * dx);
    }else if(event->buttons() & Qt::MiddleButton)
    {
        xTrans+=dx/50.0;
        yTrans-=dy/50.0;
        updateGL();
        //setXRotation(xRot + 1 * dy);
        //setYRotation(yRot + 1 * dx);
        //this->viewSided+=dy;
    }

    lastPos = event->pos();
}

void MyGLWidget::wheelEvent(QWheelEvent *event)
{
    this->viewSided+=event->delta()/2;
    //printf("hello\n");
    /*if(filename!=NULL)
    {
        printf(filename);
    }*/
    updateGL();
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
    /*glBegin(GL_TRIANGLES);
        glColor3f(1.0,1.0,0.0);
        //glNormal3f(0,1,0.707);
        glVertex3f(1,1,0);
        glVertex3f(-1,1,0);
        glVertex3f(0,0,1.2);
    glEnd();*/
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

void MyGLWidget::myPaintGL()
{
    this->paintGL();
}
