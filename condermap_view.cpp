/* by stanford */

#include "condermap_view.h"

ConderMapView::ConderMapView(QWidget *parent)
: QGraphicsView(parent)
, scene(new QGraphicsScene())
, conders(new QGraphicsItemGroup())
, tracks (new QGraphicsItemGroup())
{
    this->setScene(scene);                  // Устанавливаем сцену в виджет
    this->scale(1, -1);
    scene->addItem(conders);                // Добавляем первую группу в сцену
    scene->addItem(tracks);                 // Добавляем вторую группу в сцену
}

void ConderMapView::drawScene() {
    int widgetWidth = this->width();
    int widgetHeight = this->height();

    scene->setSceneRect(0, 0, widgetWidth, widgetHeight);

    QGraphicsRectItem* conder = new QGraphicsRectItem(40, 40, 120, 120);

    conder->setBrush(QBrush(Qt::black));
    conders->addToGroup(conder);
}

// ConderMapView::