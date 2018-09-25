#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "host.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    qmlRegisterType<Host>("MyModule", 1,0, "Host");

//    QObject * root = engine.rootObjects()[0];

//    Host host;
//    QObject::connect(root, SIGNAL(amountOfTimeChanged(int)), &host, SLOT(counting(int)));

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}