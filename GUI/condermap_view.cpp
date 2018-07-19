/* by stanford */

#include "condermap_view.h"

ConderMapView::ConderMapView(QWidget *parent)
: QGraphicsView(parent)
, scene(new QGraphicsScene())
, conders(new QGraphicsItemGroup())
, tracks (new QGraphicsItemGroup())
, map(nullptr)
{
    this->setScene(scene);
    this->scale(1, -1);         // flip on 180 degrees
    scene->addItem(conders);
    scene->addItem(tracks);
}

void ConderMapView::drawScene() {
    auto mapSizes = ConderMapSizes(this->width(), this->height());
    // TODO: separate generateScene from drawScene
    // int widgetWidth  = width();
    // int widgetHeight = height();
    // TODO: draw real conder, not just rectangle
    // TODO: separate one-conder drawing
    ConderMap matrix();

    scene->setSceneRect(0, 0, this->width(), this->height());

    QGraphicsRectItem* conder = new QGraphicsRectItem(40, 40, 120, 120);

    conder->setBrush(QBrush(Qt::black));
    conders->addToGroup(conder);
}
