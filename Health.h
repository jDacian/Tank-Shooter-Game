#ifndef HEALTH_H
#define HEALTH_H
#include<QGraphicsTextItem>
#include<QGraphicsScene>
#include<QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>

class Health: public QGraphicsTextItem{
public:
    Health(QGraphicsTextItem *parent =0);
    void decrease();
    void CheckHealth();
    void getLife();
    int getHealth();
public:
        int health;
};

class Life: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Life();
    void getLife();
};

#endif // HEALTH_H
