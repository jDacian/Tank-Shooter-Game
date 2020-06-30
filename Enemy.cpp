#include "Enemy.h"
#include<QTimer>
#include<QGraphicsScene>
#include<QList>
#include<stdlib.h>
#include "MyRect.h"
#include "Health.h"
#include "score.h"
#include "gameover.h"
#include <iostream>
#include <QImage>
#include <QBrush>

using namespace std;

extern Health *health;
extern Score *score;

Enemy::Enemy(): QObject(), QGraphicsPixmapItem()
{
    //Set Random Position
    int random_number = rand()%750;
    setPos(random_number,-100 );

    //Draw Object
//    setRect(0,0,50,50);
    setPixmap(QPixmap(":/models/enemy tank.png"));
    setTransformOriginPoint(50,50);
    setRotation(180);

    //Connect enemy to timer
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(50);
}

int speed;

void Enemy::move()
{
    //Adjust Speed Levels
    if(score->getScore() >= 0 && score->getScore() < 10)
    {
        speed = 3;
    }

    else if(score->getScore() >= 10 && score->getScore() < 15)
    {
        speed = 4;
    }

    else if(score->getScore() >= 15 && score->getScore() < 20)
    {
        speed = 6;
    }

    else if(score->getScore() >= 20 && score->getScore() < 25)
    {
        speed = 7;
    }

    else if(score->getScore() >= 25)
    {
        speed = 20;
    }

    //Adjust The Movement Speed of Enemy
    setPos(x(),y()+speed);

    if(pos().y() > 650)
    {
       health->decrease();
       scene()->removeItem(this);
       delete this;
    }

    //colliding
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for(int j=0, n=colliding_items.size(); j<n; j++)
    {
        if(typeid(* (colliding_items[j])) == typeid (MyRect))
        {
            health->decrease();
            scene()->removeItem(this);

             //Delete
             delete this;
             if (health->getHealth() == 0)
             {
//                 return;
             }
        }
    }
}
