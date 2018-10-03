#pragma once

#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsItemGroup>

#include "conder.hpp"
#include "vector.hpp"


class FieldWidget : public QGraphicsView {
Q_OBJECT

public:
    explicit FieldWidget(QWidget *parent = 0);
    ~FieldWidget();
    void DrawConder(const Conder &conder);
    void DrawVector(const Vector &vector);
    void DrawScene(const std::vector<Conder>&,
                   const std::vector<Vector>&);

private:
    QGraphicsScene *scene;
    QGraphicsItemGroup *conders;
    QGraphicsItemGroup *tracks;
    void resizeEvent(QResizeEvent *event);
    void ClearGroup(QGraphicsItemGroup *group);

    // void deleteItemsFromGroup(QGraphicsItemGroup *group_1);
};
