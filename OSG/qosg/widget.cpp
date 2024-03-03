#include "widget.h"
#include "ui_widget.h"

#include<osgViewer/Viewer>
#include<osg/Node>
#include<osg/Group>
#include<osgDB/ReadFile>
#include<osgDB/WriteFile>
#include<osgUtil/Optimizer>
#include <osg/Node>
#include <osgViewer/Viewer>
#include <osg/Geode>
#include <osg/Group>
#include <osgDB/ReadFile>
#include <osgDB/WriteFile>
#include <osgUtil/Optimizer>
#include <osgGA/TrackballManipulator>       /// osgGA::TrackballManipulator
#include <osgViewer/ViewerEventHandlers>    /// osgViewer::StatsHandler
#include <osg/MatrixTransform>              /// osg::Transform
#include <osg/BoundingSphere>               /// osg::BoundingSphere::bound()
#include <osg/ShapeDrawable>                /// osg::ShapeDrawable
#include <osg/LineWidth>
#include <osg/BlendColor>                   /// osg::BlendColor
#include <osg/BlendFunc>                    /// osg::BlendFunc

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    m_pOSGQOpenGLWidget = new osgQOpenGLWidget(this);
    m_pOSGQOpenGLWidget->setGeometry(geometry());

    connect(m_pOSGQOpenGLWidget,&osgQOpenGLWidget::initialized,this,&Widget::initWindow);
}

Widget::~Widget()
{
    if(m_pOSGQOpenGLWidget){
        m_pOSGQOpenGLWidget->deleteLater();
    }

    delete ui;
}

void Widget::initWindow()
{
    osgViewer::Viewer* pViewer = m_pOSGQOpenGLWidget->getOsgViewer();
    pViewer->setCameraManipulator(new osgGA::TrackballManipulator);
    osg::Node* node = osgDB::readNodeFile("D:\\Apps\\OpenSceneGraph-Data-3.4.0\\OpenSceneGraph-Data\\cow.osg");
    pViewer->setSceneData(node);
}
