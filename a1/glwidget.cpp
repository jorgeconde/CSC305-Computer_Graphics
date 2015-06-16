//-------------------------------------------------------------------------------------------
//  University of Victoria Computer Science Department
//	FrameWork for OpenGL application under QT
//  Course title: Computer Graphics CSC305
//-------------------------------------------------------------------------------------------
#include <QtGui>
#include <QtOpenGL>
#include <math.h>
#include "glwidget.h"


#ifndef M_PI
 #define M_PI 3.141592653589793
#endif
GLWidget::GLWidget(QWidget *parent)
    : QGLWidget(parent), RADIUS(8.0), SAMPLESTEP(0.02)
{
    stackIndex = 0;
	leftPressed = false;
	CurrentPtsId = -1;
    circleColor[0] = 0.2f;
    circleColor[1] = 0.8f;
    circleColor[2] = 0.1f;

    basicLineColor[0] = 1.0f;
    basicLineColor[1] = 0.0f;
    basicLineColor[2] = 0.1f;

    for (int i = 0; i < 20; ++ i)
    {
        circCords[i][0]=RADIUS*cos(i*2*M_PI/20.0);
        circCords[i][1]=RADIUS*sin(i*2*M_PI/20.0);
    }
}

GLWidget::~GLWidget()
{    

}

void GLWidget::initializeGL()
{
    //Background color will be white
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glShadeModel( GL_FLAT );
    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();
    glPointSize(5);
}

void GLWidget::paintGL()
{
    //Clear target buffer and depth buffer
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    //Draw the points and dots
    if (mouseInputs.size() > 0)
    {
        drawCircle(mouseInputs[0]);

        for (size_t i = 1; i < mouseInputs.size(); ++ i)
        {
            drawLine(mouseInputs[i-1], mouseInputs[i]);
            drawCircle(mouseInputs[i]);
        }
    }
}

/* 2D */
void GLWidget::resizeGL( int w, int h )
{
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    glOrtho(0.0,GLdouble(w),0,GLdouble(h),-10.0,10.0);
    glFlush();
    glMatrixMode(GL_MODELVIEW);
    glViewport( 0, 0, (GLint)w, (GLint)h );
}

void GLWidget::mousePressEvent( QMouseEvent *e )
{
    //Reverse the Y axis in mouse coordinate
    QPoint MouseLocation = e->pos();
    MouseLocation.setY(height() - e->y());
    if (e->button() == Qt::LeftButton)
	{
		leftPressed = true;
        CurrentPtsId = SelectPoint(MouseLocation);
	}
	
	if (e->button() == Qt::RightButton)
	{
        addPoint(MouseLocation);
        updateGL();
	}
}

void GLWidget::mouseReleaseEvent( QMouseEvent *e)
{
    //Reverse the Y axis in mouse coordinate
    QPoint MouseLocation = e->pos();
    MouseLocation.setY(height() - e->y());
    if (e->button() == Qt::LeftButton && leftPressed)
    {
        if (CurrentPtsId >= 0)
        {
            movePointById(CurrentPtsId, MouseLocation);
        }
        leftPressed = false;
        CurrentPtsId = -1;
        updateGL();
    }
}

void GLWidget::mouseMoveEvent ( QMouseEvent *e )
{
    //Reverse the Y axis in mouse coordinate
    QPoint MouseLocation = e->pos();
    MouseLocation.setY(height() - e->y());
    if ((e->buttons() & Qt::LeftButton) && leftPressed)
    {
        if (CurrentPtsId >= 0)
        {
            movePointById(CurrentPtsId, MouseLocation);
        }
    }
    updateGL();
}

void GLWidget::addPoint(QPoint mousePts)
{
    mouseInputs.push_back(Vec2d(mousePts.x(), mousePts.y()));
}

int GLWidget::SelectPoint(QPoint mousePts)
{
    for (size_t i = 0; i < mouseInputs.size(); ++ i)
    {
        const Vec2d & currentPts = mouseInputs[i];
        if ( (currentPts.x - RADIUS < mousePts.x() && currentPts.x + RADIUS > mousePts.x())
           &&(currentPts.y - RADIUS < mousePts.y() && currentPts.y + RADIUS > mousePts.y()))
        {
            return (int)i;
        }
    }
    return -1;
}

void GLWidget::movePointById(int PointId, QPoint dest)
{
    mouseInputs[PointId] = Vec2d(dest.x(), dest.y());
}

void GLWidget::drawCircle(Vec2d center)
{
    glColor3fv(circleColor);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 20; ++ i)
        glVertex2f(center.x + circCords[i][0],
                center.y + circCords[i][1]);
    glEnd();
}

void GLWidget::drawLine(Vec2d start, Vec2d end)
{
    glColor3fv(basicLineColor);
    glLineWidth(1);
    glBegin(GL_LINES);
    glVertex2f(start.x, start.y);
    glVertex2f(end.x, end.y);
    glEnd();
}

void GLWidget::ClearInput()
{
    mouseInputs.clear();
    updateGL();
}

void GLWidget::setM11(double i)
{
    currentMatrix.M11 = i;
}

void GLWidget::setM12(double i)
{
    currentMatrix.M12 = i;
}

void GLWidget::setM13(double i)
{
    currentMatrix.M13 = i;
}

void GLWidget::setM21(double i)
{
    currentMatrix.M21 = i;
}

void GLWidget::setM22(double i)
{
    currentMatrix.M22 = i;
}

void GLWidget::setM23(double i)
{
    currentMatrix.M23 = i;
}

void GLWidget::setM31(double i)
{
    currentMatrix.M31 = i;
}

void GLWidget::setM32(double i)
{
    currentMatrix.M32 = i;
}

void GLWidget::setM33(double i)
{
    currentMatrix.M33 = i;
}

void GLWidget::transformMatrix()
{
    for (size_t i = 0; i < mouseInputs.size(); i++)
    {
        mouseInputs[i].x = (currentMatrix.M11 * mouseInputs[i].x) + (currentMatrix.M12 * mouseInputs[i].y) + (currentMatrix.M13 * 1);
        mouseInputs[i].y = (currentMatrix.M21 * mouseInputs[i].x) + (currentMatrix.M22 * mouseInputs[i].y) + (currentMatrix.M23 * 1);
    }
    updateGL();
}

void GLWidget::cleanCurrentMatrix()
{
    currentMatrix.M11 = 0;
    currentMatrix.M12 = 0;
    currentMatrix.M13 = 0;
    currentMatrix.M21 = 0;
    currentMatrix.M22 = 0;
    currentMatrix.M23 = 0;
    currentMatrix.M31 = 0;
    currentMatrix.M32 = 0;
    currentMatrix.M33 = 0;

    updateGL();
}

void GLWidget::pushMatrix()
{

    if (stackIndex > 0) {

        //Multiply top of stack with current Matrix and then push to the stack
        matrixStack[stackIndex-1].M11 = (matrixStack[stackIndex-1].M11*currentMatrix.M11)
                                    + (matrixStack[stackIndex-1].M12*currentMatrix.M21)
                                    + (matrixStack[stackIndex-1].M13*currentMatrix.M31);

        matrixStack[stackIndex-1].M12 = (matrixStack[stackIndex-1].M11*currentMatrix.M12)
                                    + (matrixStack[stackIndex-1].M12*currentMatrix.M22)
                                    + (matrixStack[stackIndex-1].M13*currentMatrix.M32);

        matrixStack[stackIndex-1].M13 = (matrixStack[stackIndex-1].M11*currentMatrix.M13)
                                    + (matrixStack[stackIndex-1].M12*currentMatrix.M23)
                                    + (matrixStack[stackIndex-1].M13*currentMatrix.M33);

        matrixStack[stackIndex-1].M21 = (matrixStack[stackIndex-1].M21*currentMatrix.M11)
                                    + (matrixStack[stackIndex-1].M22*currentMatrix.M21)
                                    + (matrixStack[stackIndex-1].M23*currentMatrix.M31);

        matrixStack[stackIndex-1].M22 = (matrixStack[stackIndex-1].M21*currentMatrix.M12)
                                    + (matrixStack[stackIndex-1].M22*currentMatrix.M22)
                                    + (matrixStack[stackIndex-1].M23*currentMatrix.M32);

        matrixStack[stackIndex-1].M23 = (matrixStack[stackIndex-1].M21*currentMatrix.M13)
                                    + (matrixStack[stackIndex-1].M22*currentMatrix.M23)
                                    + (matrixStack[stackIndex-1].M23*currentMatrix.M33);

        matrixStack[stackIndex-1].M31 = (matrixStack[stackIndex-1].M31*currentMatrix.M11)
                                    + (matrixStack[stackIndex-1].M32*currentMatrix.M21)
                                    + (matrixStack[stackIndex-1].M33*currentMatrix.M31);

        matrixStack[stackIndex-1].M32 = (matrixStack[stackIndex-1].M31*currentMatrix.M12)
                                    + (matrixStack[stackIndex-1].M32*currentMatrix.M22)
                                    + (matrixStack[stackIndex-1].M33*currentMatrix.M32);

        matrixStack[stackIndex-1].M33 = (matrixStack[stackIndex-1].M31*currentMatrix.M13)
                                    + (matrixStack[stackIndex-1].M32*currentMatrix.M23)
                                    + (matrixStack[stackIndex-1].M33*currentMatrix.M33);

        cleanCurrentMatrix();
        updateGL();
    }
}

void GLWidget::storeMatrix()
{

    if (stackIndex < 5) {

        //Store current Matrix in the matrix stack
        matrixStack[stackIndex].M11 = currentMatrix.M11;
        matrixStack[stackIndex].M12 = currentMatrix.M12;
        matrixStack[stackIndex].M13 = currentMatrix.M13;
        matrixStack[stackIndex].M21 = currentMatrix.M21;
        matrixStack[stackIndex].M22 = currentMatrix.M22;
        matrixStack[stackIndex].M23 = currentMatrix.M23;
        matrixStack[stackIndex].M31 = currentMatrix.M31;
        matrixStack[stackIndex].M32 = currentMatrix.M32;
        matrixStack[stackIndex].M33 = currentMatrix.M33;
        stackIndex++;
        cleanCurrentMatrix();
        updateGL();
    }
}

void GLWidget::popMatrix()
{
    if (stackIndex > 0) {

        // Pop the top matrix of the stack and apply it to the chosen shape
        for (size_t i = 0; i < mouseInputs.size(); i++)
        {
            mouseInputs[i].x = (matrixStack[stackIndex-1].M11 * mouseInputs[i].x)
                    + (matrixStack[stackIndex-1].M12 * mouseInputs[i].y)
                    + (matrixStack[stackIndex-1].M13 * 1);

            mouseInputs[i].y = (matrixStack[stackIndex-1].M21 * mouseInputs[i].x)
                    + (matrixStack[stackIndex-1].M22 * mouseInputs[i].y)
                    + (matrixStack[stackIndex-1].M23 * 1);
        }
        stackIndex--;
        updateGL();
    }
}

void GLWidget::applyStack()
{
    // Apply every matrix in the stack to the chosen shape, in the order stated by the user
    for (size_t j = 0; j < stackIndex; j++)
    {
        for (size_t i = 0; i < mouseInputs.size(); i++)
        {
            mouseInputs[i].x = (matrixStack[j].M11 * mouseInputs[i].x) + (matrixStack[j].M12 * mouseInputs[i].y) + (matrixStack[j].M13 * 1);
            mouseInputs[i].y = (matrixStack[j].M21 * mouseInputs[i].x) + (matrixStack[j].M22 * mouseInputs[i].y) + (matrixStack[j].M23 * 1);
        }
    }
    stackIndex = 0;
    updateGL();
}
