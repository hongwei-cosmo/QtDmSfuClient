#include "moc_deps.h"
#include "QWebRTCProxy.h"
#include "controller.h"

#include <QDebug>

Controller::Controller(QObject *parent) :
  QObject(parent),
  webrtcProxy_(QWebRTCProxy::getInstance())
{
}

Controller::~Controller() {
  delete webrtcProxy_;
}

void Controller::connectSfu(const std::string& sfuUrl, const std::string& clientId)
{
  qDebug("%s is called url=%s, id=%s", __func__, sfuUrl.c_str(), clientId.c_str());

  QString ws = QString::fromStdString(sfuUrl + "/?clientId=" + clientId);

  connect(&webSocket_, &QWebSocket::connected, this, &Controller::onConnectedSfu);
  connect(&webSocket_, &QWebSocket::disconnected, this, &Controller::onDisconnectedSfu);
  connect(&webSocket_, &QWebSocket::textMessageReceived, this, &Controller::onSfuMessageReceived);
  connect(&webSocket_, &QWebSocket::sslErrors, this, &Controller::onSfuMessageReceived);
  webSocket_.open(QUrl(ws));
}

void Controller::onConnectedSfu()
{
  qDebug("%s is called", __func__);
}

void Controller::onDisconnectedSfu()
{
  qDebug("%s is called", __func__);
}

void Controller::onSfuMessageReceived(const QString& message)
{
  sfuSignaling_.gotMsgFromSfu(message.toStdString());
}

void Controller::onSslErrors(const QList<QSslError> &errors)
{
    Q_UNUSED(errors);

    // WARNING: Never ignore SSL errors in production code.
    // The proper way to handle self-signed certificates is to add a custom root
    // to the CA store.

    webSocket_.ignoreSslErrors();
}

