//
// Created by alireza on 7/9/16.
//

#include "FirstWindow.h"
#include <settings.h>
#include <QLabel>
#include <QHBoxLayout>

FirstWindow::FirstWindow(QWidget *parent, Qt::WindowFlags flags) : QWidget(parent, flags){
    resize(Setting::window_size);
    QLabel* back = new QLabel(this);
    back->setPixmap(QPixmap("/home/mareal/RoyaleClash/res/img/first.jpg"));
    back->setAlignment(Qt::AlignCenter);
    back->setAttribute(Qt::WA_TranslucentBackground);
    back->setGeometry(0, 0, Setting::window_size.width(), Setting::window_size.height());

//    setStyleSheet("background-image: url(/home/mareal/RoyaleClash/res/img/first.jpg)");
    make_name_input();
    make_start_button();
    show();
}

void FirstWindow::make_name_input() {
    QLabel* name_label = new QLabel("Please enter your name !   :", this);
    name_label -> setStyleSheet("color: red");
    name_label -> setGeometry(QRect(10, 590, 200, 30));
    name = new QLineEdit("Unknown", this);
    name -> setGeometry(QRect(210, 590, 170, 30));
    name -> setStyleSheet("background: transparent; color: red");
}

void FirstWindow::make_start_button() {
    ok = new QPushButton("start", this);
    ok -> setGeometry(210, 630, 150, 30);
    ok -> setFlat(true);
    ok -> setStyleSheet("color: red");
    is_training = new QCheckBox("Training", this);
    is_training -> setGeometry(100, 630, 100, 30);
    is_training -> setStyleSheet("color: red");
    is_training -> setFocusPolicy(Qt::NoFocus);
}
