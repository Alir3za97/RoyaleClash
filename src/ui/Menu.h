//
// Created by mareal on 7/10/16.
//

#ifndef ROYALECLASH_MENU_H
#define ROYALECLASH_MENU_H
#include <QWidget>
#include <QString>

class Menu : public QWidget {
    friend class Main;

public:
    Menu(QString, bool, QWidget* = 0);

private:
    void set_interface();

    bool is_training;
    QString name;
};


#endif //ROYALECLASH_MENU_H
