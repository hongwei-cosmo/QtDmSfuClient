#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>

class QWebRTCProxy;
class QSfuSignaling;

class Controller : public QObject
{
  Q_OBJECT
public:
  explicit Controller(QObject *parent = nullptr);
  ~Controller();

  void connect();

Q_SIGNALS:

public Q_SLOTS:

private:
  QWebRTCProxy *webrtcProxy_;
  QSfuSignaling *sfuSignaling_;
};

#endif // CONTROLLER_H
