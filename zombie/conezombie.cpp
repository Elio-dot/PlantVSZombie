#include "conezombie.h"

ConeZombie::ConeZombie()
{
    hp = 640;
    atk = 100 * 33 / 1000;
    speed = 80.0 * 33 / 1000 / 4.7;
    setMovie(":resource/images/ConeZombieWalk.gif");
}

void ConeZombie::advance(int phase)
{
    if (!phase)
        return;
    update();
    if (hp <= 0)
    {
        if (state < 2)
        {
            state = 2;
            setMovie(":resource/images/ZombieDie.gif");
            setHead(":resource/images/ZombieHead.gif");
        }
        else if (movie->currentFrameNumber() == movie->frameCount() - 1)
            delete this;
        return;
    }
    QList<QGraphicsItem *> items = collidingItems();
    if (!items.isEmpty())
    {
        Plant *plant = qgraphicsitem_cast<Plant *>(items[0]);
        plant->hp -= atk;
        if (state != 1)
        {
            state = 1;
            setMovie(":resource/images/ConeZombieAttack.gif");
        }
        return;
    }
    if (state)
    {
        state = 0;
        setMovie(":resource/images/ConeZombieWalk.gif");
    }
    setX(x() - speed);
}
