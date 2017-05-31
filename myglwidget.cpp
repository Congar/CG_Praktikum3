#include "myglwidget.h"
#include <QMouseEvent>
#include <QKeyEvent>
#include <QWheelEvent>
#include "GL/gl.h"
#include "planets.h"
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
float z_Axis=-7.0f;

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


MyGLWidget::MyGLWidget(QWidget *parent):QGLWidget(parent)
  ,vbo(QOpenGLBuffer::VertexBuffer) // Typ festlegen
  ,ibo(QOpenGLBuffer::IndexBuffer)  // Typ festlegen
{
       setFocusPolicy(Qt::StrongFocus); // the widget accepts focus by both tabbing and clicking
       /*QTimer *timer = new QTimer(this) ;
         connect(timer, SIGNAL(timeout()),this,SLOT(updateGL()));
         timer->start(0);*/
       cameraPos = QVector3D(0.0f, 0.0f, 20.0f);
}


MyGLWidget::~MyGLWidget()
{
    //qTex->release();
    shaderProgram.release();

    vbo.release();
    ibo.release();

    // Deaktiviere die Verwendung der Attribute Arrays
    shaderProgram.disableAttributeArray(attrVertices);
    //shaderProgram.disableAttributeArray(attrColors);
    shaderProgram.disableAttributeArray(attrTexCoords);
}
// Handler for window resize and creation event
void MyGLWidget::resizeGL(GLsizei width, GLsizei height)
{
   // Compute aspect ratio
   height = (height == 0) ? 1 : height;
  // GLfloat aspect = (GLfloat)width / (GLfloat)height;

   // Set viewport to cover the whole window
   glViewport(0, 0, width, height);

   // Set p matrix to a perspective projection
  // glMatrixMode(GL_PROJECTION);
   //
  // matrix.perspective(60.0, 4.0/3.0, 0.1, 100.0);
   //glLoadIdentity();
   float aspect = (float)width/(float)height;
   pMatrix.setToIdentity();                // Set projection matrix to a perspective projection
       if (aspect >= 1.0) {
           pMatrix.frustum(-0.05f * aspect, 0.05f * aspect, -0.05f, 0.05f, 0.1f, 1000.0f);
       }
       else {
           pMatrix.frustum(-0.05f, 0.05f, -0.05f / aspect, 0.05f / aspect, 0.1f, 1000.0f);
       }
  // pMatrix.setToIdentity();
 //  pMatrix.frustum(-0.05, 0.05, -0.05, 0.05, 0.1, 1000.0);
}
//Alle Initialisierungen:
void MyGLWidget::initBuffer()
{
    // *** Erzeugen der Buffer (nur einmal aufrufen) ***
    // Erzeuge VBO, die Parameter verteilen sich hier auf mehrere Methoden
    vbo.create();
    vbo.bind();
    vbo.setUsagePattern(QOpenGLBuffer::StaticDraw);
    vbo.allocate(vboData, sizeof(GLfloat) * vboLength);
    vbo.release();
    // Erzeuge Index-Buffer
    ibo.create();
    ibo.bind();
    ibo.setUsagePattern(QOpenGLBuffer::StaticDraw);
    ibo.allocate(indexData, sizeof(GLuint) * iboLength);
    ibo.release();

    vbo.bind();
    ibo.bind();
}
void MyGLWidget::initShader()
{


    // Initialisierung Shader
    // Lade Shader-Source aus externen Dateien
    shaderProgram.addShaderFromSourceFile(QOpenGLShader::Vertex,"D:/Computergrafik/Praktikum3/P3/default130.vert") ;

    shaderProgram.addShaderFromSourceFile(QOpenGLShader::Fragment,"D:/Computergrafik/Praktikum3/P3/default130.frag") ;
    // Kompiliere und linke die Shader-Programme
    shaderProgram.link() ;

    // Binde das Shader-Programm an den OpenGL-Kontext
    shaderProgram.bind();

}
void MyGLWidget::loadModel()
{
    // Lade Model aus Datei:
        ModelLoader model ;
        bool res = model.loadObjectFromFile("D:/Computergrafik/Praktikum3/P3_models/sphere_low.obj");
        // Wenn erfolgreich, generiere VBO und Index-Array
        if (res) {
            // Frage zu erwartende Array-Längen ab
            //vboLength = model.lengthOfSimpleVBO();
            vboLength = model.lengthOfVBO(0,false,true);
            iboLength = model.lengthOfIndexArray();
            // Generiere VBO und Index-Array
            vboData = new GLfloat[vboLength];
            indexData = new GLuint[iboLength];
            //model.genSimpleVBO(vboData);
            model.genVBO(vboData,0,false,true);  // With textures
            model.genIndexArray(indexData);
        }
        else {
            // Modell konnte nicht geladen werden
             assert(0) ;
        }

}

// OpenGL settings initialization
void MyGLWidget::initializeGL()
{
    //fillArray();

    glEnable(GL_DEPTH_TEST);
    //glEnable(GL_CULL_FACE);
    glDepthFunc(GL_LEQUAL);
    //glShadeModel(GL_SMOOTH);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
    glClearDepth(1.0f);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    loadModel();
    initTexturen();
    initBuffer();
    initShader();
    initPlaneten();


    // *** Initialisierung ***
       attrVertices  = shaderProgram.attributeLocation("vert");     // #version 130
       attrTexCoords = shaderProgram.attributeLocation("texCoord"); // #version 130


       // Aktiviere die Verwendung der Attribute-Arrays
       shaderProgram.enableAttributeArray(attrVertices);
       shaderProgram.enableAttributeArray(attrTexCoords);


       // Laden der
       // Ein paar Hilfsvariablen - die 8 steht für
       // 4 Eckpunktkoordinaten + 4 Texturkoordinaten
       int offset = 0 ;
       size_t stride = 8 * sizeof(GLfloat);
       shaderProgram.setAttributeBuffer(attrVertices,GL_FLOAT,offset,4,stride);
       offset += 4*sizeof(GLfloat);
       shaderProgram.setAttributeBuffer(attrTexCoords,GL_FLOAT,offset,4,stride);


       // Lokalisiere bzw. definierte die Schnittstelle für die Matritzen
       // Die Matrix kann direkt übergeben werden, da setUniformValue für diesen Typ überladen ist.
       unifMatrixPerspective = shaderProgram.uniformLocation("pMatrix");
       Q_ASSERT(unifMatrixPerspective >= 0) ;
       unifMatrixModel = shaderProgram.uniformLocation("matrix");
       Q_ASSERT(unifMatrixModel >= 0) ;
       unifMatrixView = shaderProgram.uniformLocation("vMatrix");
       Q_ASSERT(unifMatrixView >= 0) ;

       //qTex->bind();
}


void MyGLWidget::initTexturen()
{

    // Initialization
    // Es scheint, dass man die QOpenQLTexture in dieser Klasse verwenden muss
    // und die Übergabe an den Shader autmoatisch beim Erzeugen erfolgt.
    // Aus anderen Klassen kann man dann die entsprechende QOpenGLTexture dann binden.

   /* qTex = new QOpenGLTexture(QImage(":/Map/sunmap.jpg").mirrored()) ;
    qTex->setMinificationFilter(QOpenGLTexture::LinearMipMapLinear);
    qTex->setMagnificationFilter(QOpenGLTexture::Linear);*/

    textures[0] = new QOpenGLTexture(QImage("D:/Computergrafik/Praktikum3/Map/sunmap.jpg").mirrored()) ;
    textures[1] = new QOpenGLTexture(QImage("D:/Computergrafik/Praktikum3/Map/mercurymap.jpg").mirrored()) ;
    textures[2] = new QOpenGLTexture(QImage("D:/Computergrafik/Praktikum3/Map/venusmap.jpg").mirrored()) ;
    textures[3] = new QOpenGLTexture(QImage("D:/Computergrafik/Praktikum3/Map/earthmap1k.jpg").mirrored()) ;
    textures[4] = new QOpenGLTexture(QImage("D:/Computergrafik/Praktikum3/Map/moonmap1k.jpg").mirrored()) ;
    textures[5] = new QOpenGLTexture(QImage("D:/Computergrafik/Praktikum3/Map/marsmap1k.jpg").mirrored()) ;
    textures[6] = new QOpenGLTexture(QImage("D:/Computergrafik/Praktikum3/Map/phobos.jpg").mirrored()) ;
    textures[7] = new QOpenGLTexture(QImage("D:/Computergrafik/Praktikum3/Map/deimos.jpg").mirrored()) ;
    textures[8] = new QOpenGLTexture(QImage("D:/Computergrafik/Praktikum3/Map/jupitermap.jpg").mirrored()) ;
    textures[9] = new QOpenGLTexture(QImage("D:/Computergrafik/Praktikum3/Map/saturnmap.jpg").mirrored()) ;
    textures[10] = new QOpenGLTexture(QImage("D:/Computergrafik/Praktikum3/Map/uranusmap.jpg").mirrored()) ;
    textures[11] = new QOpenGLTexture(QImage("D:/Computergrafik/Praktikum3/Map/neptunemap.jpg").mirrored()) ;


    for ( int i=0 ; i < 12 ; i++) {
        textures[i]->setMinificationFilter(QOpenGLTexture::LinearMipMapLinear);
        textures[i]->setMagnificationFilter(QOpenGLTexture::Linear);
    }

  //Q_ASSERT( qTex->textureId() == 0 ) ;


}
void MyGLWidget::initPlaneten()
{
    // Logische Anordnung der Planeten univmap.jpg
    sonne.setPlanetParameter(&shaderProgram, &unifMatrixModel, &matrixStack, &iboLength, textures[0]    ,  &paused, 0,0,0.2,5,0) ;
    merkur.setPlanetParameter(&shaderProgram, &unifMatrixModel, &matrixStack, &iboLength, textures[1]   ,  &paused,10,0.5,0.001,0.5,0) ;
    venus.setPlanetParameter(&shaderProgram, &unifMatrixModel, &matrixStack, &iboLength, textures[2]    ,  &paused, 14,0.6,0.001,0.85,0) ;
    erde.setPlanetParameter(&shaderProgram, &unifMatrixModel, &matrixStack, &iboLength, textures[3]     ,  &paused, 18,0.1,1.1,0.7,40) ;
    erdemond.setPlanetParameter(&shaderProgram, &unifMatrixModel, &matrixStack, &iboLength, textures[4] ,  &paused, 1,1.25,0,0.2,0) ;
    mars.setPlanetParameter(&shaderProgram, &unifMatrixModel, &matrixStack, &iboLength, textures[5]     ,  &paused, 22,0.53,0.5,0.6,0) ;
    phobos.setPlanetParameter(&shaderProgram, &unifMatrixModel, &matrixStack, &iboLength, textures[6]   ,  &paused, 1,2,0.5,0.03,0) ;
    deimos.setPlanetParameter(&shaderProgram, &unifMatrixModel, &matrixStack, &iboLength, textures[7]   ,  &paused, 2,0.5,0.5,0.03,0) ;
    jupiter.setPlanetParameter(&shaderProgram, &unifMatrixModel, &matrixStack, &iboLength, textures[8]  ,  &paused, 35,0.085,2.42,3,0) ;
    saturn.setPlanetParameter(&shaderProgram, &unifMatrixModel, &matrixStack, &iboLength, textures[9]   ,  &paused, 45,0.035,2.22,1.5,0) ;
    uranus.setPlanetParameter(&shaderProgram, &unifMatrixModel, &matrixStack, &iboLength, textures[10]   , &paused, 55,0.012,1.39,1.5,0) ;
    neptun.setPlanetParameter(&shaderProgram, &unifMatrixModel, &matrixStack, &iboLength, textures[11]   , &paused, 65,0.006,1.42,1,0) ;
    sonne.addSubPlanet(&merkur);
    sonne.addSubPlanet(&venus);
    sonne.addSubPlanet(&erde);
    erde.addSubPlanet(&erdemond);

    sonne.addSubPlanet(&mars);
    mars.addSubPlanet(&phobos);
    mars.addSubPlanet(&deimos);

    sonne.addSubPlanet(&jupiter);
    sonne.addSubPlanet(&saturn);
    sonne.addSubPlanet(&uranus);
    sonne.addSubPlanet(&neptun);



}
// Handler for window draw event
void MyGLWidget::paintGL()
{
    // *** Rendern ***
     // Clear buffer to set color and alpha
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    shaderProgram.setUniformValue(unifMatrixPerspective,pMatrix);
    // VIEW TRANSFORMATION
        QMatrix4x4 viewMatrix ;
        viewMatrix.lookAt(cameraPos,cameraPos+cameraFront,cameraUp);
        shaderProgram.setUniformValue(unifMatrixView,viewMatrix);

        // MODEL TRANSFORMATION (Neues OpenGL)
        QMatrix4x4 modelMatrix ;
        // Initialisierung des Modells
        modelMatrix.setToIdentity();
        matrixStack.push(modelMatrix);


      /*  // Zeit zwischen den Render Bildern
        elapsedTime = tmrRender.elapsed();
        //qDebug() << elapsedTime ;
        tmrRender.start();*/


        // glBindTexture(GL_TEXTURE_2D,tList[sun]);
        //qTex->bind();
        textures[1]->bind();
        textures[1]->bind();


        // Übergebe die Textur an die Uniform Variable
        // Die 0 steht dabei für die verwendete Unit (0=Standard)
        //shaderProgram.setUniformValue("texture",0);



        // Triggern des Renderns
        sonne.render();

        // Stack wieder säubern.
        matrixStack.pop();

        //qTex->release();



/*      glDrawElements(GL_TRIANGLES, iboLength, GL_UNSIGNED_INT, 0);
        glVertex3f(-1.0f,-1.0f,-1.0f);      //A
        glVertex3f( 1.0f, -1.0f,  -1.0f);   //B
        glVertex3f(1.0f,  1.0f,  -1.0f);    //C
        glVertex3f(-1.0f,  1.0f,  -1.0f);   //D
        glVertex3f( -1.0f, -1.0f,  1.0f);   //E
        glVertex3f( 1.0f, -1.0f,  1.0f);    //F
        glVertex3f(1.0f,1.0f,1.0f);         //G
        glVertex3f( -1.0f, 1.0f,  1.0f);    //H
*/
        //counter++;
        cameraPos=perspectivCamPos;
        update();
}
void MyGLWidget::receiveRotationZ(int wert)
{
    zRotation = wert ;
}
void MyGLWidget::keyPressEvent(QKeyEvent *event)
{

    /*if (event->key() == Qt::Key_Up || event->key() == Qt::Key_W)
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
             */
    GLfloat   cameraSpeed = 1.0f ;
       QVector3D cross ;

       bool      changedFront = false ;
       switch ( event->key()) {
           case Qt::Key_W     : cameraPos += cameraSpeed * cameraFront ;
                break ;
           case Qt:: Key_S    : cameraPos -= cameraSpeed * cameraFront ;
                break ;
           case Qt::Key_A     : cross = cross.crossProduct(cameraFront , cameraUp) ;
                                cross.normalize();
                                cameraPos -= cross * cameraSpeed ;
                break ;
           case Qt::Key_D     : cross = cross.crossProduct(cameraFront , cameraUp) ;
                                cross.normalize();
                                cameraPos += cross * cameraSpeed ;
                break ;
           case Qt::Key_Up    : pitch += 1 ;
                                changedFront = true ;
                break ;
           case Qt::Key_Down  : pitch -= 1 ;
                                changedFront = true ;
                break ;
           case Qt::Key_Left  : yaw -= 1 ;
                                changedFront = true ;
                break ;
           case Qt::Key_Right : yaw += 1 ;
                                changedFront = true ;
                break ;
           case Qt::Key_P     : paused = !paused ;
                break ;
           case Qt::Key_R     : //cameraPos = QVector3D(0.0f, 0.0f, 3.0f);
                                cameraPos = QVector3D(0.0f, 0.0f, 20.0f);
                                cameraFront = QVector3D(0.0f, 0.0f, -1.0f);
                                cameraUp = QVector3D(0.0f, 1.0f, 0.0f);
                break ;
           default : QGLWidget::keyPressEvent(event) ;
       }

         if (changedFront)
         {
         QVector3D front;
             front.setX ( cos(pitch*(M_PI/180)) * cos(yaw*(M_PI/180)) );
             front.setY ( sin(pitch*(M_PI/180) )  );
             front.setZ ( cos(pitch*(M_PI/180)) * sin(yaw*(M_PI/180)) );
             front.normalize();
             cameraFront = front ;
         }
}
void MyGLWidget::wheelEvent(QWheelEvent* event)
{
    //Maus 360° jeder step ist 15°
    int numDegrees = event->delta() / 8;
    int numSteps = numDegrees / 15;

    if (event->orientation() == Qt::Horizontal) {
        cameraPos = QVector3D(0.0f, 0.0f, numSteps);
    }
}
