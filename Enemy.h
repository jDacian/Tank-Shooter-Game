#ifndef ENEMY_H
#define ENEMY_H

//#include<QGraphicsRectItem>
#include<QGraphicsScene>
#include<QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>

class Enemy: public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    Enemy();
public slots:
    void move();

};

#endif
