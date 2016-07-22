//
// Created by mareal on 7/22/16.
//

#include <settings.h>
#include <QtWidgets/qlabel.h>
#include <iostream>
#include "TrainingGame.h"
#include <QTimer>
#include <QMouseEvent>

TrainingGame::TrainingGame(QString name, QVector<int> cards) {
    this -> name = name;
    this -> cards = cards;
    scene = new QGraphicsScene(this);
    scene -> setSceneRect(QRect(0, 85, Setting::window_size.width() - 5, Setting::window_size.height() - 170));
    setScene(scene);
    set_interface();
    currentCard = -1;
    show();
    player = new QMediaPlayer(this);
    player -> setMedia(QUrl::fromLocalFile(Setting::inmusic));
    player -> setVolume(50);
    player -> play();
    elixir = 5;
    timer = new QTimer();
    timer -> start(100);
    connect(timer, SIGNAL(timeout()), this, SLOT(fcingSlotForTimer()));
}

void TrainingGame::set_interface() {
    setGeometry(QRect(0, 0, Setting::window_size.width(), Setting::window_size.height()));
    setFixedSize(Setting::window_size);

    setStyleSheet("background-color: #0073e6");
    QLabel* down = new QLabel(this);
    down -> setGeometry(0, Setting::window_size.height() - 85, Setting::window_size.width(), 85);
    down -> setStyleSheet("background-color: black");

    current = new QPushButton(down);
    current -> setGeometry(5, 5, 75, 75);
    current -> setIconSize(QSize(75, 75));
    current -> setEnabled(false);
    current -> setFocusPolicy(Qt::NoFocus);

    firstCard = new QPushButton(down);
    firstCard -> setIconSize(QSize(70, 70));
    firstCard -> setGeometry(QRect(Setting::window_size.width() / 2 - 200, 5, 75, 75));
    firstCard -> setFocusPolicy(Qt::NoFocus);
    connect(firstCard, SIGNAL(clicked()), SLOT(firstCardPush()));
    secondCard = new QPushButton(down);
    secondCard -> setIconSize(QSize(70, 70));
    secondCard -> setGeometry(QRect(Setting::window_size.width() / 2 - 100, 5, 75, 75));
    secondCard -> setFocusPolicy(Qt::NoFocus);
    connect(secondCard, SIGNAL(clicked()), SLOT(secondCardPush()));
    thirdCard = new QPushButton(down);
    thirdCard -> setIconSize(QSize(70, 70));
    thirdCard -> setGeometry(QRect(Setting::window_size.width() / 2, 5, 75, 75));
    thirdCard -> setFocusPolicy(Qt::NoFocus);
    connect(thirdCard, SIGNAL(clicked()), SLOT(thirdCardPush()));
    fourthCard = new QPushButton(down);
    fourthCard -> setIconSize(QSize(70, 70));
    fourthCard -> setGeometry(QRect(Setting::window_size.width() / 2 + 100, 5, 75, 75));
    fourthCard -> setFocusPolicy(Qt::NoFocus);
    connect(fourthCard, SIGNAL(clicked()), SLOT(fourthCardPush()));

    firstCard -> setIcon(QIcon(Setting::picturesPath[cards.at(0)]));
    secondCard -> setIcon(QIcon(Setting::picturesPath[cards.at(1)]));
    thirdCard -> setIcon(QIcon(Setting::picturesPath[cards.at(2)]));
    fourthCard -> setIcon(QIcon(Setting::picturesPath[cards.at(3)]));

    QLabel* river = new QLabel;
    scene -> addWidget(river);
    river -> setStyleSheet("background-color: red");
    river -> setGeometry(0, Setting::window_size.height() / 2 - 30, Setting::window_size.width(), 60);

    QLabel* leftBridge  = new QLabel(river);
    scene -> addWidget(leftBridge);
    leftBridge  -> setStyleSheet("background-color: #663300");
    leftBridge  -> setGeometry(river -> width() / 4, Setting::window_size.height() / 2 - 30, 70, river -> height());

    QLabel* rightBridge = new QLabel(river);
    scene -> addWidget(rightBridge);
    rightBridge -> setStyleSheet("background-color: #663300");
    rightBridge -> setGeometry(3 * river -> width() / 4 - 70, Setting::window_size.height() / 2 - 30, 70, river -> height());


    QLabel* top = new QLabel(this);
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
    connect(mute, SIGNAL(clicked()), this, SLOT(pauseMusic()));

    back -> setGeometry(5, 5, 75, 75);
    pause -> setGeometry(Setting::window_size.width() / 2 - 75 / 2, 5, 75, 75);
    mute -> setGeometry(Setting::window_size.width() - 80, 5, 75, 75);

    topKing = new KingTower();
    scene -> addItem(topKing);
    topKing -> setPos(scene -> width() / 2 - 40, 100);

    downKing = new KingTower();
    scene -> addItem(downKing);
    downKing -> setPos(scene -> width() / 2 - 40, scene -> height() - 30);

    topLeftCrown = new CrownTower();
    scene -> addItem(topLeftCrown);
    topLeftCrown -> setPos(scene -> width() / 6 - 70, 140);

    topRightCrown = new CrownTower();
    scene -> addItem(topRightCrown);
    topRightCrown -> setPos(5 * scene -> width() / 6, 140);

    downLeftCrown = new CrownTower();
    scene -> addItem(downLeftCrown);
    downLeftCrown -> setPos(scene -> width() / 6 - 70, scene -> height() - 70);

    downRightCrown = new CrownTower();
    scene -> addItem(downRightCrown);
    downRightCrown -> setPos(5 * scene -> width() / 6, scene -> height() - 70);

    elixirLabel = new QLabel(down);
    elixirLabel -> setGeometry(Setting::window_size.width() - 100, 5, 100, 75);
    elixirLabel -> setStyleSheet("color: magenta");
}

void TrainingGame::setCurrentCard(int number) {
    int tmp = cards[number];

    cards[number] = cards[4];
    for(int i = 5;i < 8;i ++)
        cards[i - 1] = cards[i];
    cards[7] = tmp;

    firstCard -> setIcon(QIcon(Setting::picturesPath[cards.at(0)]));
    secondCard -> setIcon(QIcon(Setting::picturesPath[cards.at(1)]));
    thirdCard -> setIcon(QIcon(Setting::picturesPath[cards.at(2)]));
    fourthCard -> setIcon(QIcon(Setting::picturesPath[cards.at(3)]));

}

void TrainingGame::firstCardPush() {
    currentCard = 0;
    current -> setIcon(QIcon(Setting::picturesPath[cards.at(currentCard)]));
}

void TrainingGame::secondCardPush() {
    currentCard = 1;
    current -> setIcon(QIcon(Setting::picturesPath[cards.at(currentCard)]));
}

void TrainingGame::thirdCardPush() {
    currentCard = 2;
    current -> setIcon(QIcon(Setting::picturesPath[cards.at(currentCard)]));
}

void TrainingGame::fourthCardPush() {
    currentCard = 3;
    current -> setIcon(QIcon(Setting::picturesPath[cards.at(currentCard)]));
}

void TrainingGame::mousePressEvent(QMouseEvent* event) {
    if(currentCard == -1 ||
       event -> pos().y() > scene -> height() + 40 ||
       event -> pos().y() < 90 ||
       event -> pos().x() > scene -> width() - 30
      )
        return;
    Card* card = Card::createCard(cards.at(currentCard));
    if(elixir < Setting::elixir_costs[cards.at(currentCard)])
        return;
    elixir -= Setting::elixir_costs[cards.at(currentCard)];
    scene -> addItem(card);
    card -> setParent(scene);
    card -> show();
    card -> setPos(event -> pos());
    current -> setIcon(QIcon());
    setCurrentCard(currentCard);
    currentCard = -1;
}

void TrainingGame::pauseMusic() {
    player -> setMuted(!player -> isMuted());
}

void TrainingGame::fcingSlotForTimer() {
    elixir += .1;
    if(elixir > 10)
        elixir = 10;
    elixirLabel -> setNum(elixir);
}