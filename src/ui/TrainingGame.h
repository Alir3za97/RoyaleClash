//
// Created by mareal on 7/22/16.
//

#ifndef ROYALECLASH_TRAININGGAME_H
#define ROYALECLASH_TRAININGGAME_H

#include <QWidget>

class TrainingGame : public QWidget{
Q_OBJECT

public:
    TrainingGame(QString, QVector<int>);
private:
    QString name;
    QVector<int> cards;
private slots:

};


#endif //ROYALECLASH_TRAININGGAME_H
