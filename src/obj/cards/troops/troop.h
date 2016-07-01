//
// Created by mareal on 6/27/16.
//

#ifndef ROYALECLASH_TROOP_H
#define ROYALECLASH_TROOP_H

#include <src/obj/cards/card.h>

class Troop : public Card {
public:
protected:
    qreal hitpoint;
    MoveType move_type;
    qreal movement_speed;
    qreal attack_speed;
    qreal range;
    qreal vision;
    qreal damage;
    qreal damage_area;
    qint8 summons;
};

enum MoveType {
    flying,
    land
};
#endif //ROYALECLASH_TROOP_H
