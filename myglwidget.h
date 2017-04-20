#ifndef MYGLWIDGET_H
#define MYGLWIDGET_H
#include <QOpenGLWidget>
#include <QWidget>
#include <QObject>
class MyGLWidget : public QOpenGLWidget
{
    Q_OBJECT
public:
    MyGLWidget();
    MyGLWidget(QWidget *parent) : QOpenGLWidget(parent) {setFocusPolicy(Qt::StrongFocus); }
    void resizeGL(GLsizei width, GLsizei height);
    void paintGL();
    void initializeGL();
    void keyPressEvent(QKeyEvent *event);
    void wheelEvent(QWheelEvent *event);

   public slots:
        void  receiveRotationZ(int);
    signals:
        void valueChanged(int);
};



#endif // MYGLWIDGET_H
