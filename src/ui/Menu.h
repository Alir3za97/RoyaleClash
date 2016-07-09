//
// Created by mareal on 7/10/16.
//

#ifndef ROYALECLASH_MENU_H
#define ROYALECLASH_MENU_H
#include <QWidget>

class Menu : public QWidget {
    friend class Main;

public:
    Menu(QString, bool, QWidget* = 0);
};


#endif //ROYALECLASH_MENU_H
