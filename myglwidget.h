// myglwidget.h

#ifndef MYGLWIDGET_H
#define MYGLWIDGET_H

#include <QGLWidget>
#include <list>
using namespace std;
extern char *filename;

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

    int xRot;
    int yRot;
    int zRot;
    float xTrans;
    float yTrans;
    int viewWidth;
    int viewHeight;
    int viewSided;

    QPoint lastPos;
};

#endif // MYGLWIDGET_H

