#include "Bullet.h"
#include<QTimer>
#include<QGraphicsScene>
#include <QList>
#include"Enemy.h"
#include"score.h"

extern Score * score;

Bullet::Bullet()
{
//    setRect(0,0,5,30);
    setPixmap(QPixmap(":/models/bullet.png"));

    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(50);
}

void Bullet::move()
{
    //Adjust The Speed of the Bullet
    setPos(x(),y()-10);

    //Delete if Outside the Scene
    if(40 + pos().y() < 0)
    {
        scene()->removeItem(this);
        delete this;
    }

    //if bullet collides with enemy
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for(int i=0, n=colliding_items.size(); i<n; i++)
    {
        if(typeid(* (colliding_items[i])) == typeid (Enemy))
        {
             score->increase();
             scene()->removeItem(colliding_items[i]);
             scene()->removeItem(this);

             //Delete Bullet and Enemy
             delete colliding_items[i];
             delete this;
        }
    }

}
