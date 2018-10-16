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



Q_SIGNALS:

public Q_SLOTS:
  void connect(const std::string &sfuUrl, const std::string &clientId);

private:
  QWebRTCProxy *webrtcProxy_;
  QSfuSignaling *sfuSignaling_;
};

#endif // CONTROLLER_H
