//
// Created by alireza on 7/9/16.
//

#include "Main.h"
#include <settings.h>
#include <QDesktopWidget>

Main::Main(QWidget* parent, Qt::WindowFlags flag) : QMainWindow(parent, flag) {
    entertain();
    make_stack();
    set_properties();
    show();
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

void Main::set_properties() {
    setFixedSize(Setting::window_size);
    QDesktopWidget* desktop = new QDesktopWidget;
    setGeometry(desktop -> screen() -> width() - width(),
                desktop -> screen() -> height() - height(),
                width(), height());

    setWindowTitle("RoyaleClash");
    setCentralWidget(stacked_widget);
}