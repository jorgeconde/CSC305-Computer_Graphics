//-------------------------------------------------------------------------------------------
//  University of Bath Computer Science Department
//	FrameWork for OpenGL application under QT
//  Course title: Computer Graphics CM20219
//-------------------------------------------------------------------------------------------
//These two lines are header guardians against multiple includes
#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QGLWidget>
#include <QProgressBar>
#include "foundation.h"
#include <QtGui>
#include <QtOpenGL>
#include <glu.h>
#include "version.h"


const int maxw=1024;
const int maxh=1024;
//This is our OpenGL Component we built it on top of QGLWidget
class GLWidget : public QGLWidget
{
    Q_OBJECT

public:
    //Constructor for GLWidget
    GLWidget(QWidget *parent = 0);

    //Destructor for GLWidget
    ~GLWidget();

    void clear();
    void about();
    void help();
    void rotx(int);
    void roty(int);
    void rotz(int);
    void setxFrom(int a);
    void setyFrom(int a);
    void setzFrom(int a);
    void setViewTo();

protected:
    //Initialize the OpenGL Graphics Engine
    void initializeGL();

    //All our painting stuff are here
    void paintGL();

    //When user resizes main window, the scrollArea will be resized and it will call this function from
    //its attached GLWidget
    void resizeGL(int width, int height);
    //Handle mouse
        void mousePressEvent(QMouseEvent *event);
        void mouseReleaseEvent(QMouseEvent *event);
        void mouseMoveEvent(QMouseEvent *event);

private:
    void startup();
    int winw, winh, button,imx,imy;
    int viewto;
    int version;
    void dopan(int x, int y, bool click);
    void zoomWheel(int z);
    QImage *myimage;
    QImage timage;
    void drawFace(float w, float h);
    void displayImage();
    void drawCircle(double radius, double xcen, double ycen, bool line, int nseg);
    // for display list
    int object;
    // for the cube
    double xangle, yangle, zangle, scale;
    QImage tex[6]; // one for each face

    // Functions
    void redraw();
    void drawLine(double x0, double y0, double x1, double y1, double z0, double z1 );
    void makeSpots(int tim, QImage *buf);
    void drawCircle(int radius, int xcen, int ycen,  QImage *buf);
    void drawFace( int tim, float w);
    GLuint makeDice( );
    void initLight();

    // Rotation Calculation


    Vector3d CameraPos;
    GLdouble xto, yto, zto;
    QPoint lastMousePoint;

    bool Rotating;
    bool Scaling;
    void RotateY(Vector3d * vec_in, double rad);
    void RotateZ(Vector3d * vec_in, double rad);
    void DoRotate(QPoint desc, QPoint orig);
    void DoScale(QPoint desc, QPoint orig);
};


#endif
