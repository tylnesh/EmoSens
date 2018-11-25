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
    case Qt::Key_Space: { qDebug() << " "; break; }
    case Qt::Key_Up: { qDebug() << "+"; break; }
    case Qt::Key_Down: { qDebug() << "-"; break; }
    default: { qDebug() << "Unhandled"; break; }
    }
    return true;
}
