//
// Created by mareal on 7/9/16.
//

#include "settings.h"

QString Setting::music = "felan";
int Setting::default_music_volume = 50;
bool Setting::is_muted = false;
QSize Setting::window_size = QSize(800, 679);

QString Setting::startIcon = "/home/mareal/RoyaleClash/res/img/Start-icon.png";

QString Setting::picturesPath[15] = {
        "/home/mareal/RoyaleClash/res/img/cards/1.png",
        "/home/mareal/RoyaleClash/res/img/cards/2.png",
        "/home/mareal/RoyaleClash/res/img/cards/3.png",
        "/home/mareal/RoyaleClash/res/img/cards/4.png",
        "/home/mareal/RoyaleClash/res/img/cards/5.png",
        "/home/mareal/RoyaleClash/res/img/cards/6.png",
        "/home/mareal/RoyaleClash/res/img/cards/7.png",
        "/home/mareal/RoyaleClash/res/img/cards/8.png",
        "/home/mareal/RoyaleClash/res/img/cards/9.png",
        "/home/mareal/RoyaleClash/res/img/cards/10.png",
        "/home/mareal/RoyaleClash/res/img/cards/11.png",
        "/home/mareal/RoyaleClash/res/img/cards/12.png",
        "/home/mareal/RoyaleClash/res/img/cards/13.png",
        "/home/mareal/RoyaleClash/res/img/cards/14.png",
        "/home/mareal/RoyaleClash/res/img/cards/15.png",
};

QString Setting::cardNames[15] = {
        "lava",
        "balloon",
        "minion-horde",
        "ice-wizard",
        "dark-prince",
        "miner",
        "valkyrie",
        "witch",
        "royale-giant",
        "hog-rider",
        "mirror",
        "zap",
        "rage",
        "furnace",
        "inferno-tower",
};