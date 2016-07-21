//
// Created by mareal on 7/22/16.
//

#include <settings.h>
#include "TrainingGame.h"

TrainingGame::TrainingGame(QString name, QVector<int> cards) {
    this -> name = name;
    this -> cards = cards;
    setFixedSize(Setting::window_size);
}