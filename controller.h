#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "qt_sfu_signaling.h"

#include <QObject>
#include <QWebSocket>

class QWebRTCProxy;

class Controller : public QObject
{
  Q_OBJECT
public:
  explicit Controller(QObject *parent = nullptr);
  ~Controller();

Q_SIGNALS:

public Q_SLOTS:
  void connectSfu(const std::string &sfuUrl, const std::string &clientId);

private Q_SLOTS:
  void onConnectedSfu();
  void onDisconnectedSfu();
  void onSfuMessageReceived(const QString &message);
  void onSslErrors(const QList<QSslError> &errors);

  private:
    QWebRTCProxy *webrtcProxy_;
  QSfuSignaling sfuSignaling_;
  QWebSocket webSocket_;
};

#endif // CONTROLLER_H
