//-------------------------------------------------------------------------------------------
//  University of Victoria Computer Science Department
//	FrameWork for OpenGL application under QT
//  Course title: Computer Graphics CSC305
//-------------------------------------------------------------------------------------------
//These two lines are header guiardians against multiple includes
#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QGLWidget>
#include <vector>
#include "foundation.h"

// A 3x3 Matrix
struct Matrix33
{
    qreal M11, M12, M13, M21, M22, M23, M31, M32, M33;
};

//This is our OpenGL Component we built it on top of QGLWidget
class GLWidget : public QGLWidget
{
    Q_OBJECT

public:
    //Constructor for GLWidget
    GLWidget(QWidget *parent = 0);

    //Destructor for GLWidget
    ~GLWidget();


public slots:
    void ClearInput();
    void setM11(double i);
    void setM12(double i);
    void setM13(double i);
    void setM21(double i);
    void setM22(double i);
    void setM23(double i);
    void setM31(double i);
    void setM32(double i);
    void setM33(double i);
    void transformMatrix();
    void storeMatrix();
    void pushMatrix();
    void popMatrix();
    void applyStack();

protected:
    //Initialize the OpenGL Graphics Engine
    void initializeGL();

    //All our painting stuff are here
    void paintGL();

    //When user resizes main window, the scrollArea will be resized and it will call this function from
    //its attached GLWidget
    void resizeGL(int width, int height);

    //Handle mouse press event in scrollArea
    void mousePressEvent(QMouseEvent *event);

    void mouseReleaseEvent(QMouseEvent *event);
    //Handle Mouse Move Event
    void mouseMoveEvent(QMouseEvent *event);

private:
     const double RADIUS;
     const double SAMPLESTEP;
private:
    std::vector<Vec2d> mouseInputs;

    bool leftPressed;
    int CurrentPtsId;
    int SelectPoint(QPoint mousePts);
    void addPoint(QPoint mousePts);
    void movePointById(int PointId, QPoint dest);
    Matrix33 currentMatrix;
    float circleColor[3];
    void drawCircle(Vec2d center);
    float circCords[20][2];
    float basicLineColor[3];
    void drawLine(Vec2d start, Vec2d end);
    void cleanCurrentMatrix();


private:
    Matrix33 matrixStack [5];
    int stackIndex;

};

#endif
