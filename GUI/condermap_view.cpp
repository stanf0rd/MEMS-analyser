/* by stanford */

#include "condermap_view.h"
#include "configuration.h"

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

void ConderMapView::generateScene() {
    auto mapSizes = ConderMapSizes(this->width(), this->height());
    auto &config = Configuration::Instance();
    ConderMap matrix(mapSizes, config.getConderSizes());
    // TODO: send conderCount (through config)
    matrix.GenConders(10);
}

void ConderMapView::drawConder(Conder conder) {
    auto coord = conder.getCoord();
    auto sizes = conder.getSizes();
    int plateHeight = (sizes.height - sizes.delta)/2;
    QGraphicsRectItem* conderBottom = new QGraphicsRectItem(
        coord.x, coord.y,
        sizes.width, plateHeight
    );
    QGraphicsRectItem* conderTop = new QGraphicsRectItem(
        coord.x, coord.y + sizes.delta + plateHeight,
        sizes.width, plateHeight
    );
    conderBottom->setBrush(QBrush(Qt::black));
    conderTop->setBrush(QBrush(Qt::black));
    conders->addToGroup(conderBottom);
    conders->addToGroup(conderTop);
}

void ConderMapView::drawScene() {
    scene->setSceneRect(0, 0, this->width(), this->height());
    // TODO: draw all conders here
    auto const &conders = map->getConders();
    for (auto conder : conders) {
        drawConder(conder);
    }
    fitInView(scene->sceneRect(), Qt::KeepAspectRatio);
}

void ConderMapView::resizeEvent(QResizeEvent *event) {
    QGraphicsView::resizeEvent(event);
    fitInView(scene->sceneRect(), Qt::KeepAspectRatio);
}