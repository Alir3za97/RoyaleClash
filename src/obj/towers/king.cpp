//
// Created by mareal on 6/27/16.
//

#include "king.h"


KingTower::KingTower() {
    QPixmap pix;
    pix.convertFromImage(QImage("/home/mareal/RoyaleClash/res/img/king.png").scaled(QSize(80, 90)));
    setPixmap(pix);
}