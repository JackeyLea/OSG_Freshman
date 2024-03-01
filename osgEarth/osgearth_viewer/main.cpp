#include <osgDB/ReadFile>
#include <osgViewer/Viewer>
#include <osgUtil/Optimizer>
#include <osgGA/TrackballManipulator>
#include <osgEarth/TerrainOptions>
#include <osgEarth/Config>
#include <osgEarth/MapNode>
#include <osgEarth/TileMesher>
#include "osgEarth/EarthManipulator"

int main()
{
    //osgViewer
    osg::ref_ptr<osgViewer::Viewer> viewer = new osgViewer::Viewer();
    //MapNode
    osg::ref_ptr<osg::Group> root = new osg::Group;
    osg::ref_ptr<osg::Node> earthNode = osgDB::readNodeFile("D:\\Code\\osgearth\\tests\\simple.earth");
    //Earth操作器
    osg::ref_ptr<osgEarth::Util::EarthManipulator> em = new osgEarth::Util::EarthManipulator;
    root->addChild(earthNode);
    viewer->setSceneData(root.get());
    viewer->setCameraManipulator(em);
    viewer->setUpViewInWindow(0,0,800,600);
    viewer->realize();
    return viewer->run();
}
