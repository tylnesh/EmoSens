#include "keypresseventfilter.h"

#include <QKeyEvent>
#include <QDebug>

KeyPressEventFilter::KeyPressEventFilter(QObject *parent)
    : QObject(parent)
{
}

bool KeyPressEventFilter::eventFilter(QObject *obj, QEvent *event)
{
    if (event->type() != QEvent::KeyPress)
        return QObject::eventFilter(obj, event);

    QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);
    switch(keyEvent->key()) {
    case Qt::Key_Space: { qDebug() << " ";
        //capturedKey=0;
        break; }
    case Qt::Key_Up: { qDebug() << "+";
        //key=1;
        break;}
    case Qt::Key_Down: { qDebug() << "-";
        //key=-1;
        break;}
    default: { qDebug() << "Unhandled"; break; }
    }
    return true;
}
