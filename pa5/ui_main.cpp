
#include <QApplication>
#include "ui_window.h"

int main(int argc, char *argv[]) {
    // 1. Die Qt-Anwendung instanziieren
    QApplication app(argc, argv);

    // 2. Das Hauptfenster erstellen und anzeigen
    MainWindow window;
    window.show();

    // 3. Die Event-Schleife von Qt starten
    return app.exec();
}