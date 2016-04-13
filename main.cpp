// main.cpp

#include <QApplication>
#include <QDesktopWidget>


#include "window.h"



char * filename=NULL;


int main(int argc, char *argv[])
{
    if(argc==2)
    {
        filename=argv[1];
    }
    QApplication app(argc, argv);
    Window window;
    //window.ui->myGLWidget->getPoints(filename);
    window.resize(window.sizeHint());
    int desktopArea = QApplication::desktop()->width() *
                     QApplication::desktop()->height();
    int widgetArea = window.width() * window.height();

    window.setWindowTitle("OpenGL with Qt");

    if (((float)widgetArea / (float)desktopArea) < 0.75f)
        window.show();
    else
        window.showMaximized();
    return app.exec();
}
