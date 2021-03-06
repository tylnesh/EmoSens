#ifndef KEYPRESSEVENTFILTER_H
#define KEYPRESSEVENTFILTER_H

#include <QObject>
#include <global.h>



class KeyPressEventFilter : public QObject
{
    Q_OBJECT
public:
    explicit KeyPressEventFilter(QObject *parent = nullptr);


protected:
    bool eventFilter(QObject *obj, QEvent *event) override;
};

#endif // KEYPRESSEVENTFILTER_H
