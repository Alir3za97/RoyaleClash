//
// Created by mareal on 6/27/16.
//

#include <settings.h>
#include "crown.h"

CrownTower::CrownTower() {
    QPixmap pix;
    pix.convertFromImage(QImage("/home/mareal/RoyaleClash/res/img/crown.png").scaled(QSize(70, 80)));
    setPixmap(pix);
}