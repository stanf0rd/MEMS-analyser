#pragma once

#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsItemGroup>

#include "conder.h"
#include "conder_map.h"

class ConderMapView : public QGraphicsView {
Q_OBJECT

public:
    explicit ConderMapView(QWidget *parent = 0);
    // ~ConderMapView();
    void drawConder(Conder conder);
    void generateScene();
    void drawScene();

private:
    QGraphicsScene *scene;
    QGraphicsItemGroup *conders;
    QGraphicsItemGroup *tracks;
    ConderMap *map;
    void resizeEvent(QResizeEvent *event);
    // void deleteItemsFromGroup(QGraphicsItemGroup *group_1);

};
