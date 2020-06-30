#ifndef MYRECT_H
#define MYRECT_H

//#include<QGraphicsRectItem>
#include<QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>

class MyRect: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    void keyPressEvent(QKeyEvent *event);

public slots:
    void spawn();
};

#endif // MYRECT_H
