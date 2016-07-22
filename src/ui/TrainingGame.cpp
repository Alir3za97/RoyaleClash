//
// Created by mareal on 7/22/16.
//

#include <settings.h>
#include <QtWidgets/qlabel.h>
#include "TrainingGame.h"

TrainingGame::TrainingGame(QString name, QVector<int> cards) {
    this -> name = name;
    this -> cards = cards;
    set_interface();
    show();
}

void TrainingGame::set_interface() {
    setFixedSize(Setting::window_size);
    QLabel* label = new QLabel(this);
    label -> setGeometry(0, 0, Setting::window_size.width(), Setting::window_size.height());
    label -> setStyleSheet("background-color: #0073e6");

    QLabel* down = new QLabel(label);
    down -> setGeometry(0, Setting::window_size.height() - 85, Setting::window_size.width(), 85);
    down -> setStyleSheet("background-color: black");

    firstCard = new QPushButton(down);
    firstCard -> setIconSize(QSize(70, 70));
    firstCard -> setGeometry(QRect(Setting::window_size.width() / 2 - 200, 5, 75, 75));
    connect(firstCard, SIGNAL(clicked), SLOT(firstCardPush()));
    secondCard = new QPushButton(down);
    secondCard -> setIconSize(QSize(70, 70));
    secondCard -> setGeometry(QRect(Setting::window_size.width() / 2 - 100, 5, 75, 75));
    connect(secondCard, SIGNAL(clicked), SLOT(secondCardPush()));
    thirdCard = new QPushButton(down);
    thirdCard -> setIconSize(QSize(70, 70));
    thirdCard -> setGeometry(QRect(Setting::window_size.width() / 2, 5, 75, 75));
    connect(thirdCard, SIGNAL(clicked), SLOT(thirdCardPush()));
    fourthCard = new QPushButton(down);
    fourthCard -> setIconSize(QSize(70, 70));
    fourthCard -> setGeometry(QRect(Setting::window_size.width() / 2 + 100, 5, 75, 75));
    connect(fourthCard, SIGNAL(clicked), SLOT(fourthCardPush()));

    firstCard -> setIcon(QIcon(Setting::picturesPath[cards.at(0)]));
    secondCard -> setIcon(QIcon(Setting::picturesPath[cards.at(1)]));
    thirdCard -> setIcon(QIcon(Setting::picturesPath[cards.at(2)]));
    fourthCard -> setIcon(QIcon(Setting::picturesPath[cards.at(3)]));

    QLabel* river = new QLabel(label);
    river -> setStyleSheet("background-color: red");
    river -> setGeometry(0, Setting::window_size.height() / 2 - 30, Setting::window_size.width(), 60);

    QLabel* leftBridge  = new QLabel(river);
    leftBridge  -> setStyleSheet("background-color: #663300");
    leftBridge  -> setGeometry(river -> width() / 4, 0, 70, river -> height());
    QLabel* rightBridge = new QLabel(river);
    rightBridge -> setStyleSheet("background-color: #663300");
    rightBridge -> setGeometry(3 * river -> width() / 4 - 70, 0, 70, river -> height());


    QLabel* top = new QLabel(label);
    top -> setGeometry(0, 0, Setting::window_size.width(), 85);
    top -> setStyleSheet("background-color: black");

    pause = new QPushButton(top);
    pause -> setIconSize(QSize(75, 75));
    pause -> setIcon(QIcon("/home/mareal/RoyaleClash/res/img/pause.png"));
    pause -> setFocusPolicy(Qt::NoFocus);
    back = new QPushButton(top);
    back -> setIconSize(QSize(75, 75));
    back -> setIcon(QIcon("/home/mareal/RoyaleClash/res/img/back.png"));
    back -> setFocusPolicy(Qt::NoFocus);
    mute = new QPushButton(top);
    mute -> setIconSize(QSize(75, 75));
    mute -> setIcon(QIcon("/home/mareal/RoyaleClash/res/img/mute.png"));
    mute -> setFocusPolicy(Qt::NoFocus);

    back -> setGeometry(5, 5, 75, 75);
    pause -> setGeometry(Setting::window_size.width() / 2 - 75 / 2, 5, 75, 75);
    mute -> setGeometry(Setting::window_size.width() - 80, 5, 75, 75);
}

void TrainingGame::setCurrentCard(int number) {

}

void TrainingGame::firstCardPush() {

}

void TrainingGame::secondCardPush() {

}

void TrainingGame::thirdCardPush() {

}

void TrainingGame::fourthCardPush() {

}