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
    const auto mapSizes = ConderMapSizes(this->width(), this->height());
    auto &config = Configuration::Instance();
    if (map) delete map;
    map = new ConderMap(mapSizes, config.getConderSizes());
    map->GenConders(config.getAskedConderCount());
}

void ConderMapView::drawConder(const Conder &conder) {
    const auto coord = conder.getCoord();
    const auto sizes = conder.getSizes();
    int plateHeight = (sizes.height - sizes.delta)/2;
    auto conderBottom = new QGraphicsRectItem(
        coord.x, coord.y,
        sizes.width, plateHeight
    );
    auto conderTop = new QGraphicsRectItem(
        coord.x, coord.y + sizes.delta + plateHeight,
        sizes.width, plateHeight
    );
    QBrush brush(Qt::darkGray);
    QPen pen(Qt::darkGray);
    conderTop->setPen(pen);       // uncomment these two lines
    conderBottom->setPen(pen);    // to remove black border around conder
    conderTop->setBrush(brush);
    conderBottom->setBrush(brush);
    conders->addToGroup(conderTop);
    conders->addToGroup(conderBottom);
}

void ConderMapView::drawVector(const Vector &vector) {
    const Dot begin = vector.getBegin();
    const Dot end = vector.getEnd();
    auto track = new QGraphicsLineItem(begin.x, begin.y, end.x, end.y);
    // track->setZValue(-100);
    QPen pen(Qt::black);
    tracks->setZValue(-1);
    pen.setWidthF(1);
    track->setPen(pen);
    tracks->addToGroup(track);
}

void ConderMapView::drawScene() {
    ClearGroup(conders);
    ClearGroup(tracks);
    scene->setSceneRect(0, 0, this->width(), this->height());
    auto const &conderVector = map->getConders();
    // std::cout << conders.size() << std::endl;
    for (auto conder : conderVector) {
        drawConder(conder);
        Vector *vector = new Vector(conder.getCoord(), Dot(this->width()/2, this->height()));
        drawVector(*vector);
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
