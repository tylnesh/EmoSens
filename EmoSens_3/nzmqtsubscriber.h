#ifndef NZMQTSUBSCRIBER_H
#define NZMQTSUBSCRIBER_H

//#define MSGPACK_USE_BOOST

#include <QObject>
#include <include/nzmqt/nzmqt.hpp>
#include <msgpack.hpp>
#include <iostream>
#include <QByteArray>
#include <QList>
#include <QRegExp>
#include <string>
#include <map>
#include <QVariant>
#include <qmsgpack/msgpack.h>
#include <qmsgpack/msgpackstream.h>
#include <QJsonArray>

//namespace msgpack {
//    std::string& operator>>(msgpack::object o, std::string& v) {
//        v = std::string(o.via.raw.ptr, o.via.raw.size);
//        return v;
//    }
//}

typedef std::map<std::string, std::string> Map;

class nzmqtSubscriber : public QObject
{
    Q_OBJECT
public:
    explicit nzmqtSubscriber(
            nzmqt::ZMQContext& context,
            const QString& address,
            const QString& topic,
            QObject *parent = nullptr);

    void startImpl()
    {
        //qDebug()<< "Starting affectiva zmq...";
        socket_->subscribeTo(topic_);
        socket_->connectTo(address_);

        if (socket_->isConnected())
        //qDebug() << socket_->;
        qDebug() << "connected";
    }

    float getNumberFromQString(const QString &xString)
    {
      QRegExp xRegExp("(-?\\d+(?:[\\.,]\\d+(?:e\\d+)?)?)");
      xRegExp.indexIn(xString);
      QStringList xList = xRegExp.capturedTexts();
      if (true == xList.empty())
      {
        return 0.0;
      }
      return xList.begin()->toDouble();
    }

signals:
    //void extractData(float diameter_3d,float X, float Y, float Z);
    void extractData(QVariant v,QString t);

protected:


protected slots:
    void messageReceived(const QList<QByteArray>& message)
    {
        //qDebug() << "received msg";
       QVariant v = MsgPack::unpack(message.last());
          //qDebug() << "Message received";
          emit extractData(v,topic_);
}
private:
    QString address_;
    QString topic_;
    nzmqt::ZMQSocket* socket_;

};

#endif // NZMQTSUBSCRIBER_H
