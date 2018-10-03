/* by stanford */

#include "fieldwidget.hpp"
#include "controller.hpp"


FieldWidget::FieldWidget(QWidget *parent)
: QGraphicsView(parent)
, scene(new QGraphicsScene())
, conders(new QGraphicsItemGroup())
, tracks (new QGraphicsItemGroup())
{
    this->setScene(scene);
    this->scale(1, -1);         // rotate on 180 degrees
    scene->addItem(conders);
    scene->addItem(tracks);
}

FieldWidget::~FieldWidget() {
    delete scene;
}


void FieldWidget::DrawConder(const Conder &conder) {
    const auto &coord = conder.getCoord();
    const auto &sizes = conder.getSizes();
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

void FieldWidget::DrawVector(const Vector &vector) {
    const Dot &begin = vector.getBegin();
    const Dot &end = vector.getEnd();
    auto track = new QGraphicsLineItem(begin.x, begin.y, end.x, end.y);
    // track->setZValue(-100);
    QPen pen(Qt::black);
    // pen.setWidthF(2);
    track->setPen(pen);
    tracks->addToGroup(track);
}

void FieldWidget::DrawScene(
    const std::vector<Conder>& conderList,
    const std::vector<Vector>& vectorList
) {
    ClearGroup(conders);
    ClearGroup(tracks);
    scene->setSceneRect(0, 0, this->width(), this->height());
    tracks->setZValue(-1);  // Drawing tracks behind conders

    Controller::Instance();

    for (const auto &conder : conderList) {
        // const auto conder = conderPair.second;
        DrawConder(conder);
        // DrawVector(conder.getVectorRange().first);
        // DrawVector(conder.getVectorRange().second);
    }

    for (const auto &vector : vectorList) {
        DrawVector(vector);
    }


    fitInView(scene->sceneRect(), Qt::KeepAspectRatio);
}

void FieldWidget::ClearGroup(QGraphicsItemGroup *group) {
    foreach(QGraphicsItem *item, scene->items(group->boundingRect())) {
        if (item->group() == group) delete item;
    }
}

void FieldWidget::resizeEvent(QResizeEvent *event) {
    QGraphicsView::resizeEvent(event);
    fitInView(scene->sceneRect(), Qt::KeepAspectRatio);
}
