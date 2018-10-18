#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "controller.h"

int main(int argc, char *argv[])
{
  // normal mandatory start
  QGuiApplication app(argc, argv);

  Controller c;
  c.connectSfu("wss://192.168.2.2:9443", "client3333");

  QQmlApplicationEngine engine;
  engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
  return app.exec();
}
