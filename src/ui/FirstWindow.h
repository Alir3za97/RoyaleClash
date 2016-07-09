//
// Created by alireza on 7/9/16.
//

#ifndef ROYALECLASH_FIRSTWINDOW_H
#define ROYALECLASH_FIRSTWINDOW_H
#include <QWidget>
#include <QLineEdit>

class FirstWindow : public QWidget {
public:
    FirstWindow(QWidget* parent = 0, Qt::WindowFlags = 0);

private:
    void make_name_input();

    QLineEdit* name;

};


#endif //ROYALECLASH_FIRSTWINDOW_H
