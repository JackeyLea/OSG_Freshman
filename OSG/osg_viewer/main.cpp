#include<osgViewer/Viewer>
#include<osg/Node>
#include<osg/Group>
#include<osgDB/ReadFile>
#include<osgDB/WriteFile>
#include<osgUtil/Optimizer>
int main() {
    // 创建Viewer对象，场景浏览器
    osg::ref_ptr<osgViewer::Viewer> viewer = new osgViewer::Viewer();
    // 创建场景组节点
    osg::ref_ptr<osg::Group> root = new osg::Group();
    // 创建一个节点，读取牛的模型
    osg::ref_ptr<osg::Node> node = osgDB::readNodeFile("D:\\Apps\\OpenSceneGraph-Data-3.4.0\\OpenSceneGraph-Data\\cow.osg");
    // 添加到场景
    root->addChild(node.get());
    // 优化场景数据
    osgUtil::Optimizer optimizer;
    optimizer.optimize(root.get());
    // 设置场景数据
    viewer->setSceneData(root.get());
    //设置窗口大小
    viewer->setUpViewInWindow(0,0,800,600);
    // 初始化并创建窗口
    viewer->realize();
    // 开始渲染
    viewer->run();
    return 0;
}
