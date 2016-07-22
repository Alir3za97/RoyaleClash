//
// Created by alireza on 7/9/16.
//

#include "Main.h"
#include "Menu.h"

#include <settings.h>
#include <QDesktopWidget>
#include "TrainingGame.h"

Main::Main(QWidget* parent, Qt::WindowFlags flag) : QMainWindow(parent, flag) {
    entertain();
    make_stack();
    set_properties();
    make_connections();
    show();
}

void Main::entertain() {
    player = new QMediaPlayer(this);
    player -> setMedia(QUrl::fromLocalFile(Setting::outmusic));
    player -> setVolume(Setting::default_music_volume);
    player -> setMuted(Setting::is_muted);
    player -> play();
}

void Main::make_stack() {
    stacked_widget = new QStackedWidget(this);
    first_window = new FirstWindow(stacked_widget);
    stacked_widget -> addWidget(first_window);
}

void Main::set_properties() {
    setFixedSize(Setting::window_size);
    QDesktopWidget* desktop = new QDesktopWidget;
    setGeometry(desktop -> screen() -> width() - width(),
                desktop -> screen() -> height() - height(),
                width(), height());

    setWindowTitle("RoyaleClash");
    setCentralWidget(stacked_widget);
}

void Main::make_connections() {
    connect(first_window -> ok, SIGNAL(clicked()), this, SLOT(start()));
}

void Main::start() {
    menu = new Menu(first_window -> name -> text(), first_window -> is_training -> isChecked(), stacked_widget);
    stacked_widget -> addWidget(menu);
    stacked_widget -> setCurrentWidget(menu);
    connect(menu, SIGNAL(gameStart()), this, SLOT(startGame()));
}

void Main::startGame() {
    if (menu -> is_training) {
        trainingGame = new TrainingGame(menu -> name, menu -> getCards());
        connect(trainingGame -> back, SIGNAL(clicked()), this, SLOT(backToMenu()));
        stacked_widget -> addWidget(trainingGame);
        stacked_widget -> setCurrentWidget(trainingGame);
        player -> stop();
    }
}

void Main::backToMenu() {
    delete trainingGame;
    stacked_widget -> setCurrentWidget(menu);
}