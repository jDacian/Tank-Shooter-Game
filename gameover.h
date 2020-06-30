#ifndef GAMEOVER_H
#define GAMEOVER_H

#include<QGraphicsScene>
#include<QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>

class GameOver: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    GameOver();
    void over();
};

#endif // GAMEOVER_H
