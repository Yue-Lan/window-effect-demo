#include "mainwindow.h"
#include <QApplication>
#include <QTimer>

#include <QScreen>

#include <QPainter>
#include <QImage>
#include <QPixmap>

#include <QLabel>
QT_BEGIN_NAMESPACE
extern void qt_blurImage(QPainter *p, QImage &blurImage, qreal radius, bool quality, bool alphaOnly, int transposed = 0);
QT_END_NAMESPACE

#define BLUR_RADIUS 100 //模糊半径，越大图像越模糊

/*!
 * \brief main
 * \param argc
 * \param argv
 * \return
 * \details
 * 图片模糊的示例，原理是通过qt的external API qt_blurImage对图像进行处理
 * Step1: 通过QScreen::grabWindow获取图像
 * Step2: 使用qt_blurImage模糊图像
 *
 * MainWindow没有特别的意义
 *
 * 应用场景：
 * 1.图像处理、阴影绘制
 * 2.如果对于窗口是固定大小的应用，比如开始菜单（不考虑分辨率改变等情况）用此法可以模拟毛玻璃的效果
 */

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
    w.setGeometry(QApplication::primaryScreen()->availableGeometry());
    auto pixmap = QApplication::primaryScreen()->grabWindow(0, w.x(), w.y(), w.width(), w.height()); //若第一个参数为0，则截取对象为当前屏幕
    pixmap.save("test.png");
    QPixmap target(pixmap.size());
    QPainter painter(&target);
    QImage srcImg = pixmap.toImage();
    qt_blurImage(&painter, srcImg, BLUR_RADIUS, false, false);
    painter.end();
    target.save("testblur.png");

    QLabel l("在二进制文件所在目录可以查看原图和效果图");
    l.setAlignment(Qt::AlignCenter);
    w.setCentralWidget(&l);
    w.show();

    return a.exec();
}
