//
// Created by mareal on 6/27/16.
//

#ifndef ROYALECLASH_CARD_H
#define ROYALECLASH_CARD_H

#include <QGraphicsPixmapItem>
#include <QObject>

enum Target {
    ground_only,
    air_and_ground,
    buildings,
    None
};

class Card : public QObject, public QGraphicsPixmapItem {
Q_OBJECT

public:
    Card();
    Card(const QPixmap&, QPointF = QPointF(0, 0));

protected:
    Target target;
    qint8 elixir_cost;
    qreal deploy_time;
};

#endif //ROYALECLASH_CARD_H
