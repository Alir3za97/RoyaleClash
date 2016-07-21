//
// Created by mareal on 7/10/16.
//

#include "Menu.h"
#include <settings.h>
#include <iostream>
#include <QtWidgets/qcheckbox.h>
#include <QtWidgets/qlabel.h>

Menu::Menu(QString name, bool is_training, QWidget* parent) : QWidget(parent) {
    this -> is_training = is_training;
    this -> name = name;
    set_interface();
}   

void Menu::set_interface() {
    setFixedSize(Setting::window_size);
    setStyleSheet("background-color: black");
    QLabel* label = new QLabel(this);
    label -> setGeometry(0, 0, Setting::window_size.width(), Setting::window_size.height());
    label -> setStyleSheet("background-color: black");

    cardsLay = new QGridLayout(this);
    setLayout(cardsLay);
    setStyleSheet("background-color: black");
    cardsLay -> setGeometry(QRect(50, 50, Setting::window_size.width() - 100, Setting::window_size.height() - 100));
    cards = new QVector<QCheckBox*>();

    for(int i = 0 ;i < 15 ;i ++) {
        QCheckBox* p = new QCheckBox;
        if(i % 2)
            p -> setChecked(true);
        cards -> push_back(p);
        p -> setIcon(QIcon(Setting::picturesPath[i]));
        p -> setIconSize(QSize(100, 100));
        p -> setFocusPolicy(Qt::NoFocus);
        p -> setFixedSize(Setting::window_size.width() / 4 - 20, Setting::window_size.height() / 4 - 20);
        cardsLay->addWidget(p, i / 4, i % 4);
    }

    start = new QPushButton;
    start -> setFixedSize(Setting::window_size.width() / 5 - 20, Setting::window_size.height() / 5 - 20);
    start -> setFocusPolicy(Qt::NoFocus);
    start -> setIconSize(QSize(100, 100));
    start -> setIcon(QIcon(Setting::startIcon));
    cardsLay -> addWidget(start);
    connect(start, SIGNAL(clicked()), this, SLOT(handleStartPushed()));
}

void Menu::handleStartPushed() {
    int checked = 0;
    foreach(QCheckBox* i, *cards)
        checked += i -> isChecked();
    if(checked == 8)
        emit gameStart();
}

QVector<int> Menu::getCards() {
    QVector<int> cards;
    for(int i = 0;i < this -> cards -> size();i ++)
        if(this -> cards -> at(i) -> isChecked())
            cards.push_back(i);
    return cards;
}