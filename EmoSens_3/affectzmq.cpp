#include "affectzmq.h"
#include <QDebug>
#include "zhelpers.hpp"

//zmq::context_t contextAffectiva(1);
//zmq::socket_t subscriber (contextAffectiva, ZMQ_SUB);


AffectZMQ::AffectZMQ(QString address)
{
    //subscriber.connect("tcp://localhost:5555");
    //subscriber.setsockopt( ZMQ_SUBSCRIBE, "aff", 3);

}


void AffectZMQ::run()
{

    qDebug() << "Connecting affectiva";
             //zmq::context_t contextAffectiva(1);
             //zmq::socket_t subscriber (contextAffectiva, ZMQ_SUB);


             //for(int i =0; i++; i<100000)

            // while(true)
             //{

                 //  Read envelope with address
              //   QString add =  QString::fromStdString(s_recv (subscriber));
                 //  Read message contents
              //   QString contents =  QString::fromStdString(s_recv (subscriber));

           //      qDebug() << "[" << add << "] " << contents << endl;
            //     sleep(1);
           //}
}
