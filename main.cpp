#include <QApplication>
#include "gui.h"


int main(int argc, char **argv) {
    QApplication app(argc, argv);
    
    Window *window = new Window();
    window->show();

    return QApplication::exec();
}
