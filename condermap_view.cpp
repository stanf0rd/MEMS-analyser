#include "condermap_view.h"
 
ConderMapView::ConderMapView(QWidget *parent)
: QGraphicsView(parent)
, scene(new QGraphicsScene())
, conders(new QGraphicsItemGroup())
, tracks (new QGraphicsItemGroup())
{
    this->setScene(scene);                  // Устанавливаем сцену в виджет
    scene->addItem(conders);                // Добавляем первую группу в сцену
    scene->addItem(tracks);                 // Добавляем вторую группу в сцену
}
