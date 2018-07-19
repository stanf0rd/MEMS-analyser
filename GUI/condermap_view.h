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
    void drawScene();

private:
    QGraphicsScene *scene;
    QGraphicsItemGroup *conders;
    QGraphicsItemGroup *tracks;
    ConderMap *map;
// signals:

// private slots:
    // void slotAlarmTimer();

/*
    // Таймер для задержки отрисовки.
    //  * Дело в том, что при создании окна и виджета
    //  * необходимо некоторое время, чтобы родительский слой
    //  * развернулся, чтобы принимать от него адекватные параметры
    //  * ширины и высоты
    //  *
    QTimer              *timer; */

// private:
    /* Перегружаем событие изменения размера окна,
     * чтобы перехватывать его
     * */
    // void resizeEvent(QResizeEvent *event);
    /* Метод для удаления всех элементов
     * из группы элементов
     * */
    // void deleteItemsFromGroup(QGraphicsItemGroup *group_1);
};
