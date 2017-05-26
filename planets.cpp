#include "planets.h"


Planets::Planets()
{
    //loadtexture();
}


void Planets::loadTexture()
{
    texture = new QOpenGLTexture(QImage(":/Maps/earthmap1k.jpg").mirrored()) ;
    texture->setMinificationFilter(QOpenGLTexture::LinearMipMapLinear);
    texture->setMagnificationFilter(QOpenGLTexture::Linear);
}

void Planets::setPlanetParameter(QOpenGLShaderProgram* _shaderProgram,
                                int* _unifMatrixModel,
                                std::stack<QMatrix4x4>* _modelStack,
                                unsigned int* _iboLength,
                                QOpenGLTexture *_texture,
                                bool* _paused,
                                int _radius,
                                double _angleCenterFactor ,
                                double _selfRotationFactor ,
                                double _scale,double _neigung )
{
    shaderProgram = _shaderProgram ;
    unifMatrixModel = _unifMatrixModel ;
    modelStack = _modelStack ;
    radius = _radius ;
    angleCenterFactor = _angleCenterFactor ;
    selfRotationFactor = _selfRotationFactor ;
    scale = _scale ;
    iboLength = _iboLength ;
    paused = _paused ;
    texture = _texture ;
    neigung = _neigung;

}



void Planets::addSubPlanet( Planets* _newSubPlanet )
{
    subplantes.push_back(_newSubPlanet);
}


void Planets::render()
{

    texture->bind();
    QMatrix4x4 modelMatrix ;

    modelMatrix = modelStack->top() ;   // Worauf bezieht sich das aktuelle rendern
    modelMatrix.rotate    (counter * angleCenterFactor, 0, 1, 0);         // Auf welchen Winkel im Bezug auf den Ursprung soll gedreht werden? (Regeln der Umlaufgeschwindigkeit)
    modelMatrix.translate (radius , 0, 0);                                // Planet vom Ursprung "auf" die Umlaufbahn schieben
    modelMatrix.rotate    (-counter * angleCenterFactor, 0, 1, 0);
    modelMatrix.rotate    (neigung, 1, 0, 0) ;
    modelMatrix.rotate    (counter * selfRotationFactor, 0, 1, 0) ;       // Eigendrehung

    // Beim Skalieren muss ich aufpassen. Wenn ich hier mein Koordinatensystem "kleiner" mache,
    // bezieht sich dass auch auf die Subsysteme. Deshalb skaliere ich es in dem Punkt wo ich es
    // hinhaben will und mach die Skalierung danach wieder rückgängig.
    modelMatrix.scale(scale);

    shaderProgram->setUniformValue(*unifMatrixModel,modelMatrix);



    //shaderProgram->setUniformValue("texture",0);
    glDrawElements ( GL_TRIANGLES,
                     *iboLength,
                     GL_UNSIGNED_INT,
                     0);

        //glEnd();
    // Koordinatensystem wieder in den ursprünglichen Zustand bringen. Nur die Entfernung bleibt bestehen.
    modelMatrix.scale(1/scale) ;    // Skalierung wieder umkehren
    // Eigendrehung des Planeten wieder rückgängig machen
    modelMatrix.rotate(-counter*selfRotationFactor, 0, 1, 0) ;
    modelMatrix.rotate(-neigung, 1, 0, 0) ;
    // Koordinatensystem wieder zurückdrehen, damit es in der initialen Position liegtt.
    modelMatrix.rotate(-counter * angleCenterFactor,0,1,0);


    // Das aktuelle Objekt ist gezeichnet. Jetzt betrachtet man noch die untergeordneten Systeme.
    // Damit die wissen worauf sie sich beziehen, legt man das aktuelle Model Koordinatensystem auf den Stack
    // welches die Subplanenten dann verwenden.
    modelStack->push(modelMatrix);

    for ( unsigned int i = 0 ; i < subplantes.size() ; i++ )
    {
        subplantes[i]->render();
    }

    // Der Planet ist gezeichnet und es gibt keine Subplaneten mehr.
    // Deshalb kann man die Model-Matrix wieder vom Stack runter nehmen.
    modelStack->pop();

    if ( !*paused )
    {
       counter++;
    }

}
