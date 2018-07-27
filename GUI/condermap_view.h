#pragma once

#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsItemGroup>

#include "conder.h"
#include "vector.h"
#include "conder_map.h"

class ConderMapView : public QGraphicsView {
Q_OBJECT

public:
    explicit ConderMapView(QWidget *parent = 0);
    // ~ConderMapView();
    void drawConder(const Conder &conder);
    void drawVector(const Vector &vector);
    void generateScene();
    void drawScene();

private:
    QGraphicsScene *scene;
    QGraphicsItemGroup *conders;
    QGraphicsItemGroup *tracks;
    ConderMap *map;
    void resizeEvent(QResizeEvent *event);
    void ClearGroup(QGraphicsItemGroup *group);

    // void deleteItemsFromGroup(QGraphicsItemGroup *group_1);
};
