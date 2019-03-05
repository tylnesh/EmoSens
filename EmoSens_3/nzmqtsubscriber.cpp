#include "nzmqtsubscriber.h"

nzmqtSubscriber::nzmqtSubscriber(nzmqt::ZMQContext& context,
                                 const QString& address,
                                 const QString& topic,
                                 QObject *parent)
    : QObject(parent), address_(address), topic_(topic), socket_(0)
{
    socket_ = context.createSocket(nzmqt::ZMQSocket::TYP_SUB, this);
            socket_->setObjectName("Subscriber.Socket.socket(SUB)");
    connect(socket_, SIGNAL(messageReceived(const QList<QByteArray>&)), SLOT(messageReceived(const QList<QByteArray>&)));
}
