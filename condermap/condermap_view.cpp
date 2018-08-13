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

ConderMapView::~ConderMapView() {
    delete scene;
    delete map;
}

void ConderMapView::GenerateScene() {
    const auto mapSizes = ConderMapSizes(this->width(), this->height());
    auto &config = Configuration::Instance();
    delete map;
    map = new ConderMap(mapSizes, config.getConderSizes());
    map->GenConders(config.getAskedConderCount());
    // Dot vectorsBegin(this->width()/2, this->height());
    map->CountRanges();
    // std::cout << map->GenVectors(config.getVectorCount()) << endl;
}

void ConderMapView::DrawConder(const Conder &conder) {
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
    conderTop->setPen(pen);       // comment these two lines
    conderBottom->setPen(pen);    // to add pretty black border around conders
    conderTop->setBrush(brush);
    conderBottom->setBrush(brush);
    conders->addToGroup(conderTop);
    conders->addToGroup(conderBottom);
}

void ConderMapView::DrawVector(const Vector &vector) {
    const Dot begin = vector.getBegin();
    const Dot end = vector.getEnd();
    auto track = new QGraphicsLineItem(begin.x, begin.y, end.x, end.y);
    // track->setZValue(-100);
    QPen pen(Qt::black);
    // pen.setWidthF(2);
    track->setPen(pen);
    tracks->addToGroup(track);
}

void ConderMapView::DrawScene() {
    ClearGroup(conders);
    ClearGroup(tracks);
    scene->setSceneRect(0, 0, this->width(), this->height());
    auto const &conders = map->getConders();
    tracks->setZValue(-1);  // Drawing tracks behind conders

    for (const auto &conder : conders) {
        // const auto conder = conderPair.second;
        DrawConder(conder);
        // DrawVector(conder.getVectorRange().first);
        // DrawVector(conder.getVectorRange().second);
    }

    for (const auto &vector : map->getVectors()) {
        DrawVector(vector);
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
