#include "Health.h"
#include <QFont>
#include <gameover.h>
#include"MyRect.h"

extern  MyRect * player;

Health::Health(QGraphicsTextItem *parent)
{
    health = 5;
    setPlainText(QString("Health: ") + QString::number(health));
    setDefaultTextColor(Qt::red);
    setFont(QFont("times",16));
}

void Health::decrease()
{
    health--;
    if(health <= 0)
    {
        health = 0;
    }
    setPlainText(QString("Health: ") + QString::number(health));

    if(health == 0)
    {
        GameOver * gameover = new GameOver();
        scene()->addItem(gameover);
        gameover->setPos(125,180);
    }
}

int Health::getHealth()
{
    health = health;
    return health;
}

//Life::Life()
//{
//    setPixmap(QPixmap(":/models/life.png"));
//}

//void Life::getLife()
//{
//    if(health == 5)
//    {
//        Life * life = new Life();
//        scene()->addItem(life);
//        life->setPos()
//    }
//}

