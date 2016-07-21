//
// Created by mareal on 7/10/16.
//

#ifndef ROYALECLASH_MENU_H
#define ROYALECLASH_MENU_H
#include <QWidget>
#include <QString>
#include <QVector>
#include <QtWidgets/qpushbutton.h>
#include <QtWidgets/qgridlayout.h>
#include <QtWidgets/qcheckbox.h>

class Menu : public QWidget {
Q_OBJECT
    friend class Main;

public:
    Menu(QString, bool, QWidget* = 0);
    QVector<int> getCards();

    bool is_training;
    QString name;
signals:
    void gameStart();

private:
    void handleStartPushed();

    void set_interface();
    QGridLayout* cardsLay;
    QVector<QCheckBox*>* cards;
    QPushButton* start;
};


#endif //ROYALECLASH_MENU_H
