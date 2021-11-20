//
// Created by ivaaahn on 30.05.2021.
//

#include <QPainter>
#include <iostream>
#include "qt_drawer.hpp"

QtDrawer::QtDrawer(std::shared_ptr<QGraphicsScene>& scene) : scene(scene) {
    this->image = std::make_shared<QImage>(1081, 900, QImage::Format_RGB32);
    this->painter = std::make_shared<QPainter>(this->image.get());
    this->updateScene();
//    this->image.fill(Qt::white);
//    color = QColor()
}

QtDrawer::QtDrawer(const QtDrawer& drawer) : scene(drawer.scene) {}

//void QtDrawer::drawLine(const Point& point1, const Point& point2) {
//    this->scene->addLine(point1.getX(), point1.getY(), point2.getX(), point2.getY());
//}

void QtDrawer::clearScene() {
    this->scene->clear();
}


void QtDrawer::putPixel(const int2& coords, const ColorRGB& color) {
    QColor color_((int)(color[0]), (int)(color[1]), (int)(color[2]));
    this->painter->setPen(color_);
    this->painter->drawPoint(coords.x, coords.y);
}

void QtDrawer::updateScene() {
//    uchar *tmp = this->image->bits();
//    int size = (int)this->image->sizeInBytes();
//
//    for (int i = 3; i < 22; i += 3)
//    {
//        std::cout << (int)tmp[i - 3] << ' ' << (int)tmp[i - 2] << ' ' << (int)tmp[i - 1] << std::endl;
//    }

    this->pixmap = QPixmap::fromImage(*this->image);
    this->scene->addPixmap(this->pixmap);
//    this->scene->update();
}

void QtDrawer::updateWithImage() {

//    this->image = QImage(scene->WIDTH(), scene->height(), QImage::Format_RGB32);
//    this->updateScene();
}

