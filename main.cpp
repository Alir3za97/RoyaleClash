//
// Created by mareal on 6/26/16.
//


#include <QApplication>
#include <src/ui/Main.h>

using namespace std;

int main(int argc, char** argv) {
    QApplication* app = new QApplication(argc, argv);
    Main* main = new Main;
    return app -> exec();
}
