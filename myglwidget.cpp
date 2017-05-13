#include "myglwidget.h"
#include <QMouseEvent>
#include <QKeyEvent>
#include <QWheelEvent>
#include "GL/gl.h"

using namespace  std;

/*MyGLWidget::MyGLWidget()
{

}*/
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

//AUFGABE 3.2
//FILLARAY:
void MyGLWidget::fillArray()
{
   /* //E:
    vertices[0] = -1.0f;
    vertices[1] = -1.0f;
    vertices[2] = 1.0f;
    vertices[3] = 1.0f;
        //rot
        vertices[4] = 1.0f;
        vertices[5] = 0.0f;
        vertices[6] = 0.0f;
        vertices[7] = 0.1f;
    //F:
    vertices[8]  = 1.0f;
    vertices[9]  = -1.0f;
    vertices[10] = 1.0f;
    vertices[11] = 1.0f;
        //grün
        vertices[12] = 0.0f;
        vertices[13] = 1.0f;
        vertices[14] = 0.0f;
        vertices[15] = 1.0f;
    //G:
    vertices[16] = 1.0f;
    vertices[17] = 1.0f;
    vertices[18] = 1.0f;
    vertices[19] = 1.0f;
        //blau
        vertices[20] = 0.0f;
        vertices[21] = 0.0f;
        vertices[22] = 1.0f;
        vertices[23] = 1.0f;
    //H:
    vertices[24] = 1.0f;
    vertices[25] = 1.0f;
    vertices[26] = -1.0f;
    vertices[27] = 1.0f;
        //rot
        vertices[28] = 1.0f;
        vertices[29] = 0.0f;
        vertices[30] = 0.0f;
        vertices[31] = 0.0f;
    //D
    vertices[32] = -1.0f;
    vertices[33] = 1.0f;
    vertices[34] = -1.0f;
    vertices[35] = 1.0f;
        //grün
        vertices[36] = 0.0f;
        vertices[37] = 1.0f;
        vertices[38] = 0.0f;
        vertices[39] = 1.0f;
    //C
    vertices[40] = 1.0f;
    vertices[41] = 1.0f;
    vertices[42] = -1.0f;
    vertices[43] = 1.0f;
        //blau
        vertices[44] = 1.0f;
        vertices[45] = 1.0f;
        vertices[46] = -1.0f;
        vertices[47] = 1.0f;
    //B
    vertices[48] = 1.0f;
    vertices[49] = -1.0f;
    vertices[50] = -1.0f;
    vertices[51] = 1.0f;
        //lila
        vertices[52] = 1.0f;
        vertices[53] = 0.0f;
        vertices[54] = 1.0f;
        vertices[55] = 1.0f;
    //A
    vertices[56] = -1.0f;
    vertices[57] = -1.0f;
    vertices[58] = -1.0f;
    vertices[59] = 1.0f;
        //
        vertices[60] = 1.0f;
        vertices[61] = 1.0f;
        vertices[62] = 0.0f;
        vertices[63] = 1.0f;
*/

        // 1. Vertex, Position
            vertices[0] = -1.0f;
            vertices[1] = -1.0f;
            vertices[2] = -1.0f;
            vertices[3] = 1.0f; // 4. Komponente ist immer 1
            // 1. Vertex, Farbe
            vertices[4] = 1.0f;
            vertices[5] = 0.0f;
            vertices[6] = 0.0f;
            vertices[7] = 1.0f; // 4

            // 2. Vertex, Position
            vertices[8] = 1.0f;
            vertices[9] = -1.0f;
            vertices[10] = -1.0f;
            vertices[11] = 1.0f; // 4. Komponente ist immer 1
            // 2. Vertex, Farbe
            vertices[12] = 0.0f;
            vertices[13] = 0.0f;
            vertices[14] = 1.0f;
            vertices[15] = 1.0f; // 4. Komponente ist immer 1

            // 3. Vertex, Position
            vertices[16] = 1.0f;
            vertices[17] = 1.0f;
            vertices[18] = -1.0f;
            vertices[19] = 1.0f; // 4. Komponente ist immer 1
            // 3. Vertex, Farbe
            vertices[20] = 0.0f;
            vertices[21] = 1.0f;
            vertices[22] = 0.0f;
            vertices[23] = 1.0f; // 4. Komponente ist immer 1

            // 4. Vertex, Position
            vertices[24] = -1.0f;
            vertices[25] = 1.0f;
            vertices[26] = -1.0f;
            vertices[27] = 1.0f; // 4. Komponente ist immer 1
            // 4. Vertex, Farbe
            vertices[28] = 1.0f;
            vertices[29] = 1.0f;
            vertices[30] = 0.0f;
            vertices[31] = 1.0f; // 4. Komponente ist immer 1

            // 5. Vertex, Position
            vertices[32] = -1.0f;
            vertices[33] = -1.0f;
            vertices[34] = 1.0f;
            vertices[35] = 1.0f; // 4. Komponente ist immer 1
            // 5. Vertex, Farbe
            vertices[36] = 0.0f;
            vertices[37] = 1.0f;
            vertices[38] = 1.0f;
            vertices[39] = 1.0f; // 4. Komponente ist immer 1

            // 6. Vertex, Position
            vertices[40] = 1.0f;
            vertices[41] = -1.0f;
            vertices[42] = 1.0f;
            vertices[43] = 1.0f; // 4. Komponente ist immer 1
            // 6. Vertex, Farbe
            vertices[44] = 1.0f;
            vertices[45] = 0.0f;
            vertices[46] = 1.0f;
            vertices[47] = 1.0f; // 4. Komponente ist immer 1

            // 7. Vertex, Position
            vertices[48] = 1.0f;
            vertices[49] = 1.0f;
            vertices[50] = 1.0f;
            vertices[51] = 1.0f; // 4. Komponente ist immer 1
            // 7. Vertex, Farbe
            vertices[52] = 1.0f;
            vertices[53] = 0.5f;
            vertices[54] = 0.0f;
            vertices[55] = 1.0f; // 4. Komponente ist immer 1

            // 8. Vertex, Position
            vertices[56] = -1.0f;
            vertices[57] = 1.0f;
            vertices[58] = 1.0f;
            vertices[59] = 1.0f; // 4. Komponente ist immer 1
            // 8. Vertex, Farbe
            vertices[60] = 0.737255f;
            vertices[61] = 0.560784f;
            vertices[62] = 0.560784f;
            vertices[63] = 1.0f; // 4. Komponente ist immer 1

  /*  //vorne
    indices[0]  = 0;
    indices[1]  = 1;
    indices[2]  = 2;
    indices[3]  = 2;
    indices[4]  = 3;
    indices[5]  = 0;
    //hinten
    indices[6]  = 4;
    indices[7]  = 5;
    indices[8]  = 6;
    indices[9]  = 6;
    indices[10] = 7;
    indices[11] = 4;
    //oben
    indices[12] = 3;
    indices[13] = 6;
    indices[14] = 7;
    indices[15] = 7;
    indices[16] = 2;
    indices[17] = 3;
    //unten
    indices[18] = 5;
    indices[19] = 4;
    indices[20] = 1;
    indices[21] = 1;
    indices[22] = 0;
    indices[23] = 5;
    //rechts
    indices[24] = 1;
    indices[25] = 2;
    indices[26] = 7;
    indices[27] = 7;
    indices[28] = 4;
    indices[29] = 1;
    //links
    indices[30] = 5;
    indices[31] = 6;
    indices[32] = 3;
    indices[33] = 3;
    indices[34] = 0;
    indices[35] = 5;
    */

    //TOP
       indices[0] = 7;
       indices[1] = 6;
       indices[2] = 3;
       indices[3] = 6;
       indices[4] = 2;
       indices[5] = 3;

       //BACK
       indices[6] = 0;
       indices[7] = 1;
       indices[8] = 3;
       indices[9] = 1;
       indices[10] = 2;
       indices[11] = 3;

       //RICHT
       indices[12] = 5;
       indices[13] = 1;
       indices[14] = 6;
       indices[15] = 1;
       indices[16] = 2;
       indices[17] = 6;

       //LEFT
       indices[18] = 7;
       indices[19] = 4;
       indices[20] = 0;
       indices[21] = 0;
       indices[22] = 3;
       indices[23] = 7;

       //FRONT
       indices[24] = 7;
       indices[25] = 4;
       indices[26] = 5;
       indices[27] = 5;
       indices[28] = 6;
       indices[29] = 7;

       //DOWN
       indices[30] = 0;
       indices[31] = 4;
       indices[32] = 5;
       indices[33] = 5;
       indices[34] = 1;
       indices[35] = 0;
}


MyGLWidget::MyGLWidget(QWidget *parent):QOpenGLWidget(parent)
  ,vbo(QOpenGLBuffer::VertexBuffer) // Typ festlegen
  ,ibo(QOpenGLBuffer::IndexBuffer)  // Typ festlegen
{
       setFocusPolicy(Qt::StrongFocus); // the widget accepts focus by both tabbing and clicking
}
// OpenGL settings initialization
void MyGLWidget::initializeGL()
{
    fillArray();
    glEnable(GL_DEPTH_TEST);
    //glEnable(GL_CULL_FACE);
    glDepthFunc(GL_LEQUAL);
    glShadeModel(GL_SMOOTH);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
    glClearDepth(1.0f);
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    erzeugeBuffer();
    // *** Initialisierung ***
    // Lade die Shader-Sourcen aus externen Dateien (ggf. anpassen)
    shaderProgram.addShaderFromSourceFile(QOpenGLShader::Vertex, "D:/Computergrafik/Praktikum3/P3/default130.vert");
    shaderProgram.addShaderFromSourceFile(QOpenGLShader::Fragment,"D:/Computergrafik/Praktikum3/P3/default130.frag");
    // Kompiliere und linke die Shader-Programme
    shaderProgram.link();



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
  // glMatrixMode(GL_PROJECTION);
   //
  // matrix.perspective(60.0, 4.0/3.0, 0.1, 100.0);
   //glLoadIdentity();
   pMatrix.setToIdentity();
   pMatrix.frustum(-0.05, 0.05, -0.05, 0.05, 0.1, 100.0);
}
void MyGLWidget::erzeugeBuffer()
{
    // *** Erzeugen der Buffer (nur einmal aufrufen) ***
    // Erzeuge VBO, die Parameter verteilen sich hier auf mehrere Methoden
    vbo.create();
    vbo.bind();
    vbo.setUsagePattern(QOpenGLBuffer::StaticDraw);
    vbo.allocate(vertices, sizeof(GLfloat) * 8 * 8);
    vbo.release();
    // Erzeuge Index-Buffer
    ibo.create();
    ibo.bind();
    ibo.setUsagePattern(QOpenGLBuffer::StaticDraw);
    ibo.allocate(indices, sizeof(GLubyte) * 36);
    ibo.release();
}

// Handler for window draw event
void MyGLWidget::paintGL()
{
    // *** Rendern ***
     // Clear buffer to set color and alpha
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    //std::stack<QMatrix4x4> matrixStack;
    matrix.setToIdentity();
    vMatrix.setToIdentity();
    matrix.translate(x_Axis, y_Axis, z_Axis);
    matrix.rotate(counter,0,1,0);
    matrix.rotate(counter,0,1,0);
    matrixStack.push(matrix);
    matrix=matrixStack.top();
    matrixStack.pop();
    shaderProgram.bind();
    vbo.bind();
    ibo.bind();
    // Lokalisiere bzw. definiere die Schnittstelle für die Eckpunkte
    int attrVertices = 0;
    attrVertices = shaderProgram.attributeLocation("vert"); // #version 130
    // Lokalisiere bzw. definiere die Schnittstelle für die Farben
    int attrColors = 1;
    attrColors = shaderProgram.attributeLocation("color"); // #version 130
    // Aktiviere die Verwendung der Attribute-Arrays
    shaderProgram.enableAttributeArray(attrVertices);
    shaderProgram.enableAttributeArray(attrColors);
    // Lokalisiere bzw. definiere die Schnittstelle für die Transformationsmatrix
    // Die Matrix kann direkt übergeben werden, da setUniformValue für diesen Typ
    // überladen ist
    int unifMatrix = 0;
    unifMatrix = shaderProgram.uniformLocation("matrix"); // #version 130
    int punifMatrix = 0;
    punifMatrix = shaderProgram.uniformLocation("pMatrix"); // #version 130
    int vunifMatrix = 0;
    vunifMatrix = shaderProgram.uniformLocation("vMatrix"); // #version 130

    shaderProgram.setUniformValue(unifMatrix, matrix);
    shaderProgram.setUniformValue(punifMatrix, pMatrix);
    shaderProgram.setUniformValue(vunifMatrix, vMatrix);
    // Fülle die Attribute-Buffer mit den korrekten Daten
    int offset = 0;
    int stride = 8 * sizeof(GLfloat);
    shaderProgram.setAttributeBuffer(attrVertices, GL_FLOAT, offset, 4, stride);
    offset += 4 * sizeof(GLfloat);
    shaderProgram.setAttributeBuffer(attrColors, GL_FLOAT, offset, 4, stride);




    //glEnableClientState(GL_VERTEX_ARRAY);
    //glEnableClientState(GL_COLOR_ARRAY);

    // Setze den Vertex-Pointer ( veraltet )
    // Der erste Vertex liegt an Stelle 0 des VBO, hat 4 Komponenten,
    // ist vom Typ GL_FLOAT, und 8*GL_Float Byte liegen zwischen jedem
    // nachfolgenden Eckpunkt

    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_BYTE, 0);
    //glDrawArrays(GL_TRIANGLES, 0, 6); // Alternative zu glDrawElements
    // Deaktiviere die Client-States wieder
    // Deaktiviere die Verwendung der Attribute-Arrays
    shaderProgram.disableAttributeArray(attrVertices);
    shaderProgram.disableAttributeArray(attrColors);

    /*glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_COLOR_ARRAY);*/


//NEU FÜR P3:
   // pmodel = glmReadOBJ("data/al.obj");


        //Punkt1: rot

/*
        glVertex3f(-1.0f,-1.0f,-1.0f);      //A
        glVertex3f( 1.0f, -1.0f,  -1.0f);   //B
        glVertex3f(1.0f,  1.0f,  -1.0f);    //C
        glVertex3f(-1.0f,  1.0f,  -1.0f);   //D
        glVertex3f( -1.0f, -1.0f,  1.0f);   //E
        glVertex3f( 1.0f, -1.0f,  1.0f);    //F
        glVertex3f(1.0f,1.0f,1.0f);         //G
        glVertex3f( -1.0f, 1.0f,  1.0f);    //H
*/

    QOpenGLWidget::update();
    // Execute all issued GL commands

    // Increment counter
    counter++;
    vbo.release();
    ibo.release();
    // Löse das Shader-Programm
    shaderProgram.release();
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
