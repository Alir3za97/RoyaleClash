//
// Created by mareal on 6/27/16.
//

#include <settings.h>
#include "card.h"
#include <src/obj/cards/troops/lava_hound.h>
#include <src/obj/cards/troops/balloon.h>
#include <src/obj/cards/troops/minion_horde.h>
#include <src/obj/cards/troops/ice_wizard.h>
#include <src/obj/cards/troops/dark_prince.h>
#include <src/obj/cards/troops/miner.h>
#include <src/obj/cards/troops/valkyrie.h>
#include <src/obj/cards/troops/witch.h>
#include <src/obj/cards/troops/royal_giant.h>
#include <src/obj/cards/troops/hog_rider.h>
#include <src/obj/cards/mirror.h>
#include <src/obj/cards/spells/zap.h>
#include <src/obj/cards/spells/rage.h>
#include <src/obj/cards/buildings/furnace.h>
#include <src/obj/cards/buildings/inferno_tower.h>

Card::Card() {

}

Card::Card(const QPixmap& img, QPointF pos) : QGraphicsPixmapItem(img){
    setPos(pos);
}

Card* Card::createCard(int which) {
    Card* card = 0;
    if(Setting::cardNames[which] == "lava")
        card = new LavaHound();
    else if(Setting::cardNames[which] == "balloon")
        card = new Balloon();
    else if(Setting::cardNames[which] == "minion-horde")
        card = new MinionHorde();
    else if(Setting::cardNames[which] == "ice-wizard")
        card = new IceWizard();
    else if(Setting::cardNames[which] == "dark-prince")
        card = new DarkPrince();
    else if(Setting::cardNames[which] == "miner")
        card = new Miner();
    else if(Setting::cardNames[which] == "valkyrie")
        card = new Valkyrie();
    else if(Setting::cardNames[which] == "witch")
        card = new Witch();
    else if(Setting::cardNames[which] == "royale-giant")
        card = new RoyalGiant();
    else if(Setting::cardNames[which] == "hog-rider")
        card = new HogRider();
    else if(Setting::cardNames[which] == "mirror")
        card = new Mirror();
    else if(Setting::cardNames[which] == "zap")
        card = new Zap();
    else if(Setting::cardNames[which] == "rage")
        card = new Rage();
    else if(Setting::cardNames[which] == "furnace")
        card = new Furnace();
    else if(Setting::cardNames[which] == "inferno-tower")
        card = new InfernoTower();
    QPixmap pix;
    pix.convertFromImage(QImage(Setting::picturesPath[which]).scaled(QSize(30, 37)));
    card -> setPixmap(pix);
    return card;
}