#ifndef BULLET_H
#define BULLET_H

//#include<QGraphicsRectItem>
#include<QGraphicsScene>
#include<QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>

//class Bullet: public QObject, public QGraphicsRectItem {
class Bullet: public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    Bullet();
public slots:
    void move();

};

#endif // BULLET_H
