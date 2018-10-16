#include "moc_deps.h"
#include "QWebRTCProxy.h"
#include "qt-dm-sfu-client-lib/qt_sfu_signaling.h"
#include "controller.h"

Controller::Controller(QObject *parent) :
  QObject(parent),
  webrtcProxy_(QWebRTCProxy::getInstance()),
  sfuSignaling_(new QSfuSignaling)
{
}

Controller::~Controller() {
  delete webrtcProxy_;
  delete sfuSignaling_;
}
