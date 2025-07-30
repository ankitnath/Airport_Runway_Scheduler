
#include <QApplication>
#include "scheduler_gui.hpp"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    SchedulerGUI window(2); // Use 2 runways
    window.show();
    return app.exec();
}
