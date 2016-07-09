//
// Created by alireza on 7/9/16.
//

#ifndef ROYALECLASH_MAIN_H
#define ROYALECLASH_MAIN_H
#include <QMainWindow>
#include <QStackedWidget>
#include <QMediaPlayer>
#include "FirstWindow.h"

class Main : QMainWindow {
Q_OBJECT

public:
    Main(QWidget* = 0, Qt::WindowFlags = 0);
public slots:
private:

    void entertain();
    void make_stack();

    QStackedWidget* stacked_widget;
    QMediaPlayer* player;
    FirstWindow* first_window;
};


#endif //ROYALECLASH_MAIN_H
