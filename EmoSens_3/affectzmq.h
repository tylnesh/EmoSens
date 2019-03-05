#ifndef AFFECTZMQ_H
#define AFFECTZMQ_H
#include <QThread>
#include <QString>
#include "zhelpers.hpp"
#include <zmq.hpp>

class AffectZMQ : public QThread
{
public:
    explicit AffectZMQ(QString address);

    void run();



private:

  //  zmq::context_t contextAffectiva();
//    zmq::socket_t* subscriber(zmq::context_t, int);


};

#endif // AFFECTZMQ_H
