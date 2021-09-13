//
// Created by ivaaahn on 30.05.2021.
//

#ifndef __LAB_03_QT_DRAWER_HPP__
#define __LAB_03_QT_DRAWER_HPP__


#include "drawer/drawer.hpp"
#include "math/linalg.hpp"
#include <QGraphicsScene>
#include <memory>

using namespace linalg::aliases;

class QtDrawer : public Drawer {
public:
    QtDrawer() = delete;

    explicit QtDrawer(std::shared_ptr<QGraphicsScene> &scene);

    QtDrawer(const QtDrawer &drawer);

//    void drawLine(const Point &point1, const Point &point2) override;

    void putPixel(const int2 &coords, const ColorRGB &color) override;

    void clearScene() final;

    void updateScene() final;

    void updateWithImage() final;

private:
    std::shared_ptr<QGraphicsScene> scene;
    std::shared_ptr<QPainter> painter;

    QImage image;
    QPixmap pixmap;
};

#endif //__LAB_03_QT_DRAWER_HPP__
