#include "myglwidget.h"
#include <QMouseEvent>
#include <QKeyEvent>
#include <QWheelEvent>
MyGLWidget::MyGLWidget()
{

}
/* Computergrafik Praktikum
 * Klassisches OpenGL mit freeGLUT
 * FH Aachen, 2015
 */

#define WINDOW_CAPTION "Computergrafik Praktikum"
#define WINDOW_XPOS 50
#define WINDOW_YPOS 50
#define WINDOW_WIDTH 480
#define WINDOW_HEIGHT 480
#define UPDATE_RATE 60


// global variable for engine purposes
// not pretty and hardware-dependent, but gets the job done
unsigned int counter = 0;
unsigned int slider=0;
float x_Axis=0;
float y_Axis=0;
float z_Axis=-7;
// OpenGL settings initialization
void MyGLWidget::initializeGL()
{
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    glDepthFunc(GL_LEQUAL);
    glShadeModel(GL_SMOOTH);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

    glClearDepth(1.0f);
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

}


// Handler for window resize and creation event
void MyGLWidget::resizeGL(GLsizei width, GLsizei height)
{
   // Compute aspect ratio
   height = (height == 0) ? 1 : height;
  // GLfloat aspect = (GLfloat)width / (GLfloat)height;

   // Set viewport to cover the whole window
   glViewport(0, 0, width, height);

   // Set projection matrix to a perspective projection
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glFrustum(-0.05, 0.05, -0.05, 0.05, 0.1, 100.0);
}


// Handler for window draw event
void MyGLWidget::paintGL()
{

    // Clear buffer to set color and alpha
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Apply model view transformations
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(x_Axis, y_Axis, z_Axis);

    // Set color for drawing
    //Aufgabe 1.10
    //glOrtho(3.0,-3.0,3.0,-3.0,0.1,100);
   // glDisable(GL_CULL_FACE);
    glRotatef(slider,0,0,1);
    glRotatef(counter,0,1,0);
    // Draw shape
    glBegin(GL_QUADS);

        //Punkt1: rot


        /*glVertex3f(-1.0f,-1.0f,-1.0f);      //A
        glVertex3f( 1.0f, -1.0f,  -1.0f);   //B
        glVertex3f(1.0f,  1.0f,  -1.0f);    //C
        glVertex3f(-1.0f,  1.0f,  -1.0f);   //D
        glVertex3f( -1.0f, -1.0f,  1.0f);   //E
        glVertex3f( 1.0f, -1.0f,  1.0f);    //F
        glVertex3f(1.0f,1.0f,1.0f);         //G
        glVertex3f( -1.0f, 1.0f,  1.0f);    //H*/
        //TESTTTTTTTTTTTTS
        //VORNE
        glColor3f(0,1,0);
        glVertex3f( -1.0f, -1.0f,  1.0f);   //E
        glVertex3f( 1.0f, -1.0f,  1.0f);    //F
        glVertex3f(1.0f,1.0f,1.0f);         //G
        glVertex3f( -1.0f, 1.0f,  1.0f);    //H
        //rechts
        glColor3f(1,1,0);
        glVertex3f( 1.0f, -1.0f,  1.0f);    //F
        glVertex3f( 1.0f, -1.0f,  -1.0f);   //B
        glVertex3f(1.0f,  1.0f,  -1.0f);    //C
        glVertex3f(1.0f,1.0f,1.0f);         //G
        //oben
        glColor3f(0,1,1);
        glVertex3f( -1.0f, 1.0f,  1.0f);    //H
        glVertex3f(1.0f,1.0f,1.0f);         //G
        glVertex3f(1.0f,  1.0f,  -1.0f);    //C
        glVertex3f(-1.0f,  1.0f,  -1.0f);   //D

        //hinten
        glColor3f(0,1,0);
        glVertex3f(-1.0f,  1.0f,  -1.0f);   //D
        glVertex3f(1.0f,  1.0f,  -1.0f);    //C
        glVertex3f( 1.0f, -1.0f,  -1.0f);   //B
        glVertex3f(-1.0f,-1.0f,-1.0f);      //A

        //links
        glColor3f(1,1,0);
        glVertex3f( -1.0f, -1.0f,  1.0f);   //E
        glVertex3f( -1.0f, 1.0f,  1.0f);    //H
        glVertex3f(-1.0f,  1.0f,  -1.0f);   //D
        glVertex3f(-1.0f,-1.0f,-1.0f);      //A

        //unten
        glColor3f(0,1,1);
        glVertex3f( -1.0f, -1.0f,  1.0f);   //E
        glVertex3f(-1.0f,-1.0f,-1.0f);      //A
        glVertex3f( 1.0f, -1.0f,  -1.0f);   //B
        glVertex3f( 1.0f, -1.0f,  1.0f);    //F


    glEnd();
    QOpenGLWidget::update();
    // Execute all issued GL commands

    // Increment counter
    counter++;
}
void MyGLWidget::receiveRotationZ(int wert)
{
    slider = wert;
}
void MyGLWidget::keyPressEvent(QKeyEvent *event)
{

    if (event->key() == Qt::Key_Up || event->key() == Qt::Key_W)
            y_Axis++;
        else if(event->key() == Qt::Key_Down || event->key() == Qt::Key_S)
            y_Axis--;
        else if(event->key() == Qt::Key_Left || event->key() == Qt::Key_A)
            x_Axis--;
        else if(event->key() == Qt::Key_Right || event->key() == Qt::Key_D)
            x_Axis++;
        else {
                QOpenGLWidget::keyPressEvent(event);
             }
}


void MyGLWidget::wheelEvent(QWheelEvent* event)
{
    //Maus 360° jeder step ist 15°
    int numDegrees = event->delta() / 8;
    int numSteps = numDegrees / 15;

    if (event->orientation() == Qt::Horizontal) {
        z_Axis+=numSteps;
        //The emit line emits the signal valueChanged() from the object, with the new value as argument.
        emit valueChanged(z_Axis);


    } else {
        z_Axis-=numSteps;
        //The emit line emits the signal valueChanged() from the object, with the new value as argument.
        emit valueChanged(z_Axis);
    }
    event->accept();
}
