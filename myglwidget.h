#ifndef MYGLWIDGET_H
#define MYGLWIDGET_H


#include <QOpenGLBuffer>        // Buffer
#include <QGLWidget>
#include <QWidget>
#include <QInputEvent>
//#include <QOpenGLFunctions_3_1>
#include <QOpenGLShaderProgram>  // Shader
#include <stack>
#include <modelloader.h>
#include <QOpenGLTexture>

#include <iostream>
#include "planets.h"
#include <QTimer>
#include <QElapsedTimer>
typedef struct {
    GLfloat x, y, z, h;
    GLfloat r, g, b, t;
} Vertex;
class MyGLWidget : public QGLWidget
{
    Q_OBJECT

private:
    int     zRotation = 0 ;
    GLfloat zoom      = 0 ;
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
    // Zeitmessung
    QElapsedTimer tmrRender ; // Misst vergangene Zeit zwischen Rendern ;
   // Modelle
       void loadModel();
   // Lokalisiere bzw. definiere die Schnittstelle für die Eckpunkte und Texturen, ..
   int attrVertices = 0;
   int attrTexCoords = 3 ;
   int unifMatrixPerspective = 0 ;
   int unifMatrixView = 0 ;
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
    //3.6 Texturen
    QOpenGLTexture* qTex ;
    //3.11:
    QOpenGLTexture *textures[12];
    QOpenGLShaderProgram shaderProgram;
    int unifMatrixModel = 0 ;       // Uniform Value für Model Matrix. Hier deklariert, um Referenz an die Planten Klasse zu übergeben.
    int elapsedTime = 0 ;           // Zeit zwischen dem Rendern. Referenz wird an die Planeten übergeben, damit die damit arbeiten können.

    // Planeten
    Planets sonne, merkur, venus, erde, erdemond, mars, phobos, deimos, jupiter, saturn, uranus, neptun;
    // 3.9: Camera
       QVector3D cameraPos = QVector3D(0.0f, 0.0f, 3.0f);
       QVector3D cameraFront = QVector3D(0.0f, 0.0f, -1.0f);
       QVector3D cameraUp = QVector3D(0.0f, 1.0f, 0.0f);
       GLfloat yaw   = -90.0f;	// Yaw is initialized to -90.0 degrees since a yaw of 0.0 results in a direction vector pointing to the right (due to how Eular angles work) so we initially rotate a bit to the left.
       GLfloat pitch =   0.0f;
       QVector3D perspectivCamPos = QVector3D(0.0f,0.0f,0.0f);
    // Paused
    bool paused = false ;
    //MyGLWidget();
    MyGLWidget(QWidget *parent);
    ~MyGLWidget();
    void resizeGL(GLsizei width, GLsizei height);
    void paintGL();
    void initializeGL();
    void keyPressEvent(QKeyEvent *event);
    void wheelEvent(QWheelEvent *event);
    void initBuffer();
    void initShader();
    void initTexturen();
    void initPlaneten();
    void fillArray();
   public slots:
        void  receiveRotationZ(int);
    signals:
        void valueChanged(int);
};



#endif // MYGLWIDGET_H
