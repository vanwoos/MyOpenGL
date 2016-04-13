// myglwidget.h

#ifndef MYGLWIDGET_H
#define MYGLWIDGET_H

#include <QGLWidget>
#include <list>
using namespace std;


#ifndef STRUCTNODE
#define STRUCTNODE
struct node {
    float x;
    float y;
    float z;
};
#endif



class MyGLWidget : public QGLWidget
{
    Q_OBJECT
public:
    explicit MyGLWidget(QWidget *parent = 0);
    ~MyGLWidget();
signals:

public slots:

protected:
    void initializeGL();
    void paintGL();
    void resizeGL(int width, int height);

    QSize minimumSizeHint() const;
    QSize sizeHint() const;
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void wheelEvent(QWheelEvent *event);

public slots:
    // slots for xyz-rotation slider
    void setXRotation(int angle);
    void setYRotation(int angle);
    void setZRotation(int angle);
    void myPaintGL();

signals:
    // signaling rotation from mouse movement
    void xRotationChanged(int angle);
    void yRotationChanged(int angle);
    void zRotationChanged(int angle);

private:
    void draw();
    void drawCoordinate();
    int printPoints();


    int xRot;//angle to rotate
    int yRot;
    int zRot;
    float xTrans;//transfer distance
    float yTrans;
    int viewWidth;//the width of the viewport
    int viewHeight;
    int viewSided;//use to zoom in or zoom out

    QPoint lastPos;

public:
    int showPlat;//if show a platform
    double platHeight;//the height of the platform
    double platSize;//the size of the platform
    int redPoints;//the number of red points
    list<struct node> pclList;

public:
    int getPoints(char *filename);
};

#endif // MYGLWIDGET_H

