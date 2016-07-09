
//
// Created by mareal on 6/27/16.
//

#ifndef ROYALECLASH_TROOP_H
#define ROYALECLASH_TROOP_H

#include <src/obj/cards/card.h>

enum MoveType {
    flying,
    ground
};

class Troop : public Card {
public:
public slots:
protected:
    int damage_area;
    int damage;
    int range;
    int attack_speed;
    int hitpoint;
    int movement_speed;
    MoveType move_type;
    int vision;
};

#endif //ROYALECLASH_TROOP_H
