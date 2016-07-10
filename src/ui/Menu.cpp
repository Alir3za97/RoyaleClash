//
// Created by mareal on 7/10/16.
//

#include "Menu.h"
#include <settings.h>

Menu::Menu(QString name, bool is_training, QWidget* parent) : QWidget(parent) {
    this -> is_training = is_training;
    this -> name = name;
    set_interface();
}   

void Menu::set_interface() {
    setFixedSize(Setting::window_size);
    setStyleSheet("background-color: lightblue");
}