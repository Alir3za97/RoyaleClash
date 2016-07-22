//
// Created by mareal on 7/22/16.
//

#ifndef ROYALECLASH_TRAININGGAME_H
#define ROYALECLASH_TRAININGGAME_H

#include <QWidget>
#include <QtWidgets/qboxlayout.h>
#include <QtWidgets/qpushbutton.h>
#include <src/obj/cards/card.h>
#include <QLabel>
#include <QtMultimedia/qmediaplayer.h>
#include <QtWidgets/qgraphicsview.h>

class TrainingGame : public QGraphicsView{
Q_OBJECT

public:
    TrainingGame(QString, QVector<int>);

    QPushButton* back;
private:

    void set_interface();
    void mousePressEvent(QMouseEvent*);

    QString name;
    QVector<int> cards;
    QPushButton* firstCard;
    QPushButton* secondCard;
    QPushButton* thirdCard;
    QPushButton* fourthCard;
    QHBoxLayout* canDeployCards;

    QPushButton* pause;
    QPushButton* mute;

    QPushButton* current;
    int currentCard;

    QMediaPlayer* player;

    QGraphicsScene* scene;

    QGraphicsPixmapItem* river;
    QGraphicsPixmapItem* leftBridge;
    QGraphicsPixmapItem* rightBridge;

private slots:
    void firstCardPush();
    void secondCardPush();
    void thirdCardPush();
    void fourthCardPush();
    void setCurrentCard(int);
    void pauseMusic();
};


#endif //ROYALECLASH_TRAININGGAME_H
