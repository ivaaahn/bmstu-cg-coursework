//
// Created by ivaaahn on 30.05.2021.
//

#ifndef __LAB_03_QT_DRAWER_HPP__
#define __LAB_03_QT_DRAWER_HPP__


#include "drawer/drawer.hpp"
#include "math/linalg.hpp"
#include <QGraphicsScene>
#include <QImage>
#include <memory>
#include <iostream>

using namespace linalg::aliases;
using std::cout, std::endl;

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

    [[nodiscard]] std::shared_ptr<QImage> getImage() const final {
        return this->image;
    }

    void setImage(std::shared_ptr<QImage> value) final {
//        this->image.reset();
        uchar *tmp = this->image->bits();
//        this->image = value;
        for (int i = 3; i < 22; i += 3)
        {
            std::cout << (int)tmp[i - 3] << ' ' << (int)tmp[i - 2] << ' ' << (int)tmp[i - 1] << std::endl;
        }
    }


private:
    std::shared_ptr<QGraphicsScene> scene;
    std::shared_ptr<QPainter> painter;

    std::shared_ptr<QImage> image;
    QPixmap pixmap;
};

#endif //__LAB_03_QT_DRAWER_HPP__
