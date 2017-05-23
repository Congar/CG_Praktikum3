#ifndef MYGLWIDGET_H
#define MYGLWIDGET_H

#include <QWidget>
#include <QGLWidget>
#include <QKeyEvent>
#include <QWheelEvent>
#include <QOpenGLBuffer>
#include <QOpenGLShaderProgram>
#include <stack>
#include <modelloader.h>
#include <QDebug>
#include <QDir>
#include <QOpenGLTexture>
//#include <planet.h>
#include <string>
#include <QTimer>
#include <QtOpenGL>
#include <QOpenGLShaderProgram>
class MyGLWidget : public QOpenGLWidget
{
    Q_OBJECT
    QOpenGLTexture* qTex;
private:
    QMatrix4x4 pMatrix;                 //Projection Matrix
    QMatrix4x4 matrix;                  //Modelmatrix
    QMatrix4x4 vMatrix;                 //ViewMatrix
    std::stack<QMatrix4x4> matrixStack;
    QOpenGLBuffer vbo;
    QOpenGLBuffer ibo;
    // Als Pointer, da die Größer später dynamisch festgelegt wird
    GLfloat* vboData;
    GLuint* indexData; // GLuint statt GLubyte, da viele Modelle groß sind
    unsigned int vboLength;
    unsigned int iboLength;
public:
    // Eckpunkte
    // (1 Rechteck mit 4 Eckpunkten mit je 4 Koordinaten und 4 Farbkanälen)
    GLfloat vertices[8*(4+4)];
    // Verwendete Elemente (1 Rechteck, das durch 2 Dreiecke dargestellt wird)
    GLubyte indices[36]; // für große Meshes lieber GLuint
    // Handle für VBO (Eckpunkte + Farben)
    GLuint vboHandle;
    // Handle für BO der Indizes für die zu zeichnenden Elemente
    GLuint indicesHandle;

    QOpenGLShaderProgram shaderProgram;
    //MyGLWidget();
    MyGLWidget(QWidget *parent);
    void resizeGL(GLsizei width, GLsizei height);
    void paintGL();
    void initializeGL();
    void keyPressEvent(QKeyEvent *event);
    void wheelEvent(QWheelEvent *event);
    void erzeugeBuffer();
    void fillArray();
   public slots:
        void  receiveRotationZ(int);
    signals:
        void valueChanged(int);
};



#endif // MYGLWIDGET_H
