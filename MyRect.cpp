#include"MyRect.h"
#include<QKeyEvent>
#include<QDebug>
#include"Bullet.h"
#include<QGraphicsScene>
#include"Enemy.h"

void MyRect::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Left)
    {
        if(pos().x() > 0)
        {
            setPos(x()-10,y());
        }
    }

    else if(event->key() == Qt::Key_Right)
    {
        if(100 + pos().x() < 800)
        {
            setPos(x()+7,y());
        }
    }

//    else if(event->key() == Qt::Key_Up)
//    {
//        setPos(x(),y()-10);
//    }

//    else if(event->key() == Qt::Key_Down)
//    {
//        setPos(x(),y()+10);
//    }
// event->ignore();
// event->accept();
    else if(event->key() == Qt::Key_Space)
    {
        Bullet * bullet = new Bullet();
        scene()->addItem(bullet);
        bullet->setPos(x()+48,y()-30);
    }
}

void MyRect::spawn()
{
    Enemy * enemy = new Enemy();
    scene()->addItem(enemy);
}
