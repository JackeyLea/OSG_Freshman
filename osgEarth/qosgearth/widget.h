#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

#include "osgQOpenGL/osgQOpenGLWidget"

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

protected slots:
    void initWindow();

private:
    Ui::Widget *ui;

    osgQOpenGLWidget *m_pOSGQOpenGLWidget;
};
#endif // WIDGET_H
