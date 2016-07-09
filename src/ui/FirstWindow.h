//
// Created by alireza on 7/9/16.
//

#ifndef ROYALECLASH_FIRSTWINDOW_H
#define ROYALECLASH_FIRSTWINDOW_H
#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QCheckBox>

class FirstWindow : public QWidget {
    friend class Main;
public:
    FirstWindow(QWidget* parent = 0, Qt::WindowFlags = 0);

private:
    void make_name_input();
    void make_start_button();

    QLineEdit* name;
    QPushButton* ok;
    QCheckBox* is_training;
};


#endif //ROYALECLASH_FIRSTWINDOW_H
