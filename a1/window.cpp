//-------------------------------------------------------------------------------------------
//  This is a demo. program for open gl vertex arrays
//-------------------------------------------------------------------------------------------
#include <QtGui>
#include <QtOpenGL>

#include "glwidget.h"
#include "window.h"


//------------------------------------------------------------------------------------
// Creates and initializes the main window for application
//------------------------------------------------------------------------------------
Window::Window(QWidget *parent):QDialog(parent)
{
    //We create an instance of GLWidget component we built in glwidget.h
	m_glWidget = new GLWidget;
	
	//Setup application interface. Creates all the required components and sliders.
	setupUi(this);

    //We need to attach our m_glWidget to glWidgetArea
    //All our drawings will be on glWidgetArea
    glWidgetArea->setWidget(m_glWidget);

    stack_size = 0;


    //Setting up all the SIGNALS and SLOTS
    doubleSpinBox->setRange(-1000,1000);
    doubleSpinBox_2->setRange(-1000,1000);
    doubleSpinBox_3->setRange(-1000,1000);
    doubleSpinBox_4->setRange(-1000,1000);
    doubleSpinBox_5->setRange(-1000,1000);
    doubleSpinBox_6->setRange(-1000,1000);
    doubleSpinBox_7->setRange(-1000,1000);
    doubleSpinBox_8->setRange(-1000,1000);
    doubleSpinBox_9->setRange(-1000,1000);


    connect(clearButton, SIGNAL(clicked()), m_glWidget, SLOT(ClearInput()));
    connect(doubleSpinBox, SIGNAL(valueChanged(double)), m_glWidget, SLOT(setM11(double)));
    connect(doubleSpinBox_2, SIGNAL(valueChanged(double)), m_glWidget, SLOT(setM12(double)));
    connect(doubleSpinBox_3, SIGNAL(valueChanged(double)), m_glWidget, SLOT(setM13(double)));
    connect(doubleSpinBox_4, SIGNAL(valueChanged(double)), m_glWidget, SLOT(setM21(double)));
    connect(doubleSpinBox_5, SIGNAL(valueChanged(double)), m_glWidget, SLOT(setM22(double)));
    connect(doubleSpinBox_6, SIGNAL(valueChanged(double)), m_glWidget, SLOT(setM23(double)));
    connect(doubleSpinBox_7, SIGNAL(valueChanged(double)), m_glWidget, SLOT(setM31(double)));
    connect(doubleSpinBox_8, SIGNAL(valueChanged(double)), m_glWidget, SLOT(setM32(double)));
    connect(doubleSpinBox_9, SIGNAL(valueChanged(double)), m_glWidget, SLOT(setM33(double)));
    connect(btnTransform,SIGNAL(clicked()), m_glWidget, SLOT(transformMatrix()));
    connect(store, SIGNAL(clicked()), this, SLOT(on_store()));
    connect(push, SIGNAL(clicked()), this, SLOT(on_push()));
    connect(pop, SIGNAL(clicked()), this, SLOT(on_pop()));
    connect(apply, SIGNAL(clicked()), this, SLOT(on_stack()));

}

//------------------------------------------------------------------------------------
// Handle the "Store" button, which stores a matrix into a stack.
//------------------------------------------------------------------------------------
void Window::on_store()
{
    // Maximum number of matrices in a stack is 5
    if (stack_size < 5) {
        m_glWidget->storeMatrix();

        // Set current matrix values to 0
        doubleSpinBox->setValue(0.0);
        doubleSpinBox_2->setValue(0.0);
        doubleSpinBox_3->setValue(0.0);
        doubleSpinBox_4->setValue(0.0);
        doubleSpinBox_5->setValue(0.0);
        doubleSpinBox_6->setValue(0.0);
        doubleSpinBox_7->setValue(0.0);
        doubleSpinBox_8->setValue(0.0);
        doubleSpinBox_9->setValue(0.0);
        stack->setText("Matrix Stack [" + QString::number(stack_size+1) + "]");
        stack_size++;
    }
}

//------------------------------------------------------------------------------------
// Handle the "Push" button, which multiplies the current matrix with the top matrix
// of the stack.
//------------------------------------------------------------------------------------
void Window::on_push()
{
    if (stack_size > 0) {
        m_glWidget->pushMatrix();

        // Set current matrix values to 0
        doubleSpinBox->setValue(0.0);
        doubleSpinBox_2->setValue(0.0);
        doubleSpinBox_3->setValue(0.0);
        doubleSpinBox_4->setValue(0.0);
        doubleSpinBox_5->setValue(0.0);
        doubleSpinBox_6->setValue(0.0);
        doubleSpinBox_7->setValue(0.0);
        doubleSpinBox_8->setValue(0.0);
        doubleSpinBox_9->setValue(0.0);
    }
}

//------------------------------------------------------------------------------------
// Handle the "Pop" button, which pops the top matrix of the stack and it is applied
// to the vertices of a chosen shape
//------------------------------------------------------------------------------------
void Window::on_pop()
{
    if (stack_size > 0) {
        m_glWidget->popMatrix();
        stack_size--;
        stack->setText("Matrix Stack [" + QString::number(stack_size) + "]");
    }
}

//------------------------------------------------------------------------------------
// Handle the "Apply Stack" button, which applies all the matrices of the stack to the
// chosen shape, in the order stated by the user.
//------------------------------------------------------------------------------------
void Window::on_stack()
{
    if (stack_size > 0) {
        m_glWidget->applyStack();
        stack_size = 0;
        stack->setText("Matrix Stack [" + QString::number(stack_size) + "]");
    }
}



