#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <vector>
using std::vector;
class Entity{
public:
    int id;
    int ahead;
    int arriveAt;
    static int base;
    Entity(int id, int iahead);
    Entity(int id);
    void showTime();
    int getTime();
    vector<int> friendsTimes;
    void getNotife(int arriveAtFriend);
    void getTimeStemp();
    void updateTime();
private:
    static void getBase();
    const static int MAX_AHEAD = 110;
};
int Entity::base = 0;
Entity::Entity(int iid, int iahead):id(iid), ahead(iahead) {}
Entity::Entity(int iid):id(iid)
{
    ahead = random() % MAX_AHEAD;
}
int Entity::getTime()
{
    getBase();
    return ahead + base;
}
void Entity::showTime()
{
    std::cout << "id = " << id <<
        "\ttime = " << getTime() << std::endl;
}
void Entity::getBase()
{
    base = time(NULL);
}
void Entity::getNotife(int arriveAtFriend)
{
    friendsTimes.push_back(arriveAtFriend);
}
void Entity::getTimeStemp()
{
    arriveAt = getTime();
}
void Entity::updateTime()
{
    int average = 0;
    int delta = 1000000000;
    for (int i = 0; i < friendsTimes.size(); i++)
        average += friendsTimes[i] - delta;
    std::cout << "aver = " << average << std::endl;
    average /= friendsTimes.size();
    int diff = arriveAt - average - delta;
    ahead -= diff;
}
