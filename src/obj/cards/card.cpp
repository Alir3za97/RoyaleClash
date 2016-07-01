//
// Created by mareal on 6/27/16.
//

#include "card.h"

Card::Card() {

}

Card::Card(const QPixmap& img, QPointF pos) : QGraphicsPixmapItem(img){
    setPos(pos);
}
