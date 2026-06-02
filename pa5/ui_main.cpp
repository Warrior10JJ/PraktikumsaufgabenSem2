#include "ui_window.h"


int main(int argc, char *argv[]) {
    // QT starten
    QApplication app(argc, argv);
    //fenster erstellen + anzeigen
    MainWindow window;
    window.show();
    // qt event starten
    return app.exec();
}
