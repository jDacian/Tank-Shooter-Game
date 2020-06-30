#include <QApplication>
#include <QGraphicsScene>
#include "MyRect.h"
#include <QGraphicsView>
#include <QtWidgets>
#include <QGraphicsTextItem>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include "score.h"
#include "Health.h"
#include <QImage>
#include <QBrush>
#include "gameover.h"

Health *health;
Score *score;
MyRect * player;

int level;
int lvl;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //create a scene
    QGraphicsScene * scene = new QGraphicsScene;
    scene->setSceneRect(0,0,800,600);
    scene->setBackgroundBrush(QBrush(QImage(":/models/bgsand.jpg")));

    //create an item in the scene
    MyRect * player = new MyRect();
//    player->setRect(0,0,100,100);

    player->setPixmap(QPixmap(":/models/tank1.png"));

    //add item
    scene->addItem(player);

    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    //add a view
    QGraphicsView * view = new QGraphicsView(scene);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    view->setFixedSize(800,600);
    view->setSceneRect(0,0,800,600);
    view->show();

    player->setPos((view->width()/2) - 50,view->height()-100);

    score = new Score();
    scene->addItem(score);

    health = new Health();
    health->setPos(health->x(),health->y()+25);
    scene->addItem(health);

//    if(health->getHealth() == 0)
//    {
//        GameOver * gameover = new GameOver();
//    }

    if(score->getScore() >= 0 && score->getScore() < 10)
    {
        level = 3000;
        lvl = 1;
    }

    else if(score->getScore() >= 10 && score->getScore() < 15)
    {
        level = 2500;
        lvl = 2;
    }

    else if(score->getScore() >= 15 && score->getScore() < 20)
    {
        level = 2000;
        lvl = 3;
    }

    else if(score->getScore() >= 20 && score->getScore() < 25)
    {
        level = 1000;
        lvl = 4;
    }

    else if(score->getScore() >= 25)
    {
        level = 500;
        lvl = 5;
    }



    //spawn enemies
    QTimer * timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),player,SLOT(spawn()));
    timer->start(level);

    return a.exec();
}
