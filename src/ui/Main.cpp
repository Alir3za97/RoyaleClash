//
// Created by alireza on 7/9/16.
//

#include "Main.h"
#include <settings.h>

Main::Main(QWidget* parent, Qt::WindowFlags flag) : QMainWindow(parent, flag) {
    entertain();
    make_stack();
}

void Main::entertain() {
    player = new QMediaPlayer(this);
    player -> setMedia(QUrl::fromLocalFile(Setting::music));
    player -> setVolume(Setting::default_music_volume);
    player -> setMuted(Setting::is_muted);
    player -> play();
}

void Main::make_stack() {
    stacked_widget = new QStackedWidget(this);
    first_window = new FirstWindow(stacked_widget);
    stacked_widget -> addWidget(first_window);

}