//
// Created by mareal on 7/22/16.
//

#ifndef ROYALECLASH_TRAININGGAME_H
#define ROYALECLASH_TRAININGGAME_H

#include <QWidget>
#include <QtWidgets/qboxlayout.h>
#include <QtWidgets/qpushbutton.h>
#include <src/obj/cards/card.h>

class TrainingGame : public QWidget{
Q_OBJECT

public:
    TrainingGame(QString, QVector<int>);
private:
    QString name;
    QVector<int> cards;
    QPushButton* firstCard;
    QPushButton* secondCard;
    QPushButton* thirdCard;
    QPushButton* fourthCard;
    QHBoxLayout* canDeployCards;

    QPushButton* pause;
    QPushButton* mute;
    QPushButton* back;

    Card* currentCard;

    void set_interface();

private slots:
    void firstCardPush();
    void secondCardPush();
    void thirdCardPush();
    void fourthCardPush();
    void setCurrentCard(int);
};


#endif //ROYALECLASH_TRAININGGAME_H
