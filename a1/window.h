//-------------------------------------------------------------------------------------------
//  University of Victoria Computer Science Department 
//	FrameWork for OpenGL application under QT
//  Course title: Computer Graphics CSC305
//-------------------------------------------------------------------------------------------
#ifndef WINDOW_H
#define WINDOW_H

#include <QDialog>
#include "ui_MainWindow.h"

class GLWidget;

namespace Ui {
    class Window;
}

//Create a window and load the components from generated code ui_MainWindow.h
class Window : public QDialog, public Ui::frmMain
{
	Q_OBJECT;

public slots:
    void on_push();
    void on_pop();
    void on_store();
    void on_stack();

public:
	//Constructor 
	Window(QWidget *parent = 0);
	
private:
	//Member variable to hold the GLWidget instance
    //We need a reference to this
    GLWidget *m_glWidget;
    int stack_size;
};


#endif
