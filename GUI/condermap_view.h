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
    ~ConderMapView();
    void DrawConder(const Conder &conder);
    void DrawVector(const Vector &vector);
    void GenerateScene();
    void DrawScene();

private:
    QGraphicsScene *scene;
    QGraphicsItemGroup *conders;
    QGraphicsItemGroup *tracks;
    ConderMap *map;
    void resizeEvent(QResizeEvent *event);
    void ClearGroup(QGraphicsItemGroup *group);

    // void deleteItemsFromGroup(QGraphicsItemGroup *group_1);
};
