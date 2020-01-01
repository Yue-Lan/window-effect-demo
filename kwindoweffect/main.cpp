#include "mainwindow.h"
#include <QApplication>

#include <KWindowEffects>
#include <QLabel>
#include <QDebug>

/*!
 * \brief main
 * \param argc
 * \param argv
 * \return
 * \details
 * 使用KWindowEffects
 * 模糊特效要求：
 * 1.窗口属性 WA_TranslucentBackground
 * 2.窗口管理器为KWin，在特效实现前会有判断窗口管理器是否支持的逻辑
 *
 * 滑动要求
 * 同上2
 *
 * 关于毛玻璃特效：
 * 与blurimg比较，KWindowEffects的效果更好（主要体现在噪点的绘制上，imgblur没有噪点），效率更高且适用范围更广泛
 * 缺点是必须要窗口管理器的支持
 */

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setAttribute(Qt::WA_TranslucentBackground);

    QLabel l("test");
    l.setAlignment(Qt::AlignCenter);
    w.setCentralWidget(&l);

    qDebug()<<"支持模糊特效？"<<KWindowEffects::isEffectAvailable(KWindowEffects::BlurBehind);
    qDebug()<<"支持滑动特效？"<<KWindowEffects::isEffectAvailable(KWindowEffects::Slide);
    KWindowEffects::enableBlurBehind(w.winId(), true);
    KWindowEffects::slideWindow(w.winId(), KWindowEffects::LeftEdge);
    w.show();

    return a.exec();
}
