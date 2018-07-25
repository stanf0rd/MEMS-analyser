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
    this->scale(1, -1);         // rotate on 180 degrees
    scene->addItem(conders);
    scene->addItem(tracks);
    srand(time(nullptr));       // for conder generation
}

void ConderMapView::generateScene() {
    auto mapSizes = ConderMapSizes(this->width(), this->height());
    auto &config = Configuration::Instance();
    map = new ConderMap(mapSizes, config.getConderSizes());
    map->GenConders(config.getAskedConderCount());
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
    ClearGroup(conders);
    scene->setSceneRect(0, 0, this->width(), this->height());
    auto const &conderVector = map->getConders();
    // std::cout << conders.size() << std::endl;
    for (auto conder : conderVector) {
        drawConder(conder);
    }
    fitInView(scene->sceneRect(), Qt::KeepAspectRatio);
}

void ConderMapView::ClearGroup(QGraphicsItemGroup *group) {
    foreach(QGraphicsItem *item, scene->items(group->boundingRect())) {
        if (item->group() == group) delete item;
    }
}

void ConderMapView::resizeEvent(QResizeEvent *event) {
    QGraphicsView::resizeEvent(event);
    fitInView(scene->sceneRect(), Qt::KeepAspectRatio);
}