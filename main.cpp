#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "controller.h"

int main(int argc, char *argv[])
{
  // normal mandatory start
  QGuiApplication app(argc, argv);

  Controller c;

  QQmlApplicationEngine engine;
  engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
  return app.exec();
}
