//
// Created by mareal on 6/27/16.
//

#include <src/obj/cards/card.h>
#include "balloon.h"

Balloon::Balloon(const QPoint& pos) {
    target = buildings;
    damage_area = 0;
    damage = 600;
    range = 0;
    attack_speed = 3;
    hitpoint = 1050;
    movement_speed = 3;
    move_type = flying;
    vision = 100;
    elixir_cost = 5;
    deploy_time = 1;
}