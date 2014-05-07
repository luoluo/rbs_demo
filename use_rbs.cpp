#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <vector>
#include "rbs.cpp"
using std::vector;
class Simulator {
public:
    vector<Entity> timers;
    Simulator(int n);
    void showAll();
    void setArriveAt();
    void signalAll();
    void updateAll();
};
Simulator::Simulator(int n)
{
    for (int i = 0; i < n; i++) {
        timers.push_back(Entity(i));
    }
}
void Simulator::showAll()
{
    for (int i = 0; i < timers.size(); i++) {
        timers[i].showTime();
    }
}
void Simulator::setArriveAt()
{
    for (int i = 0; i < timers.size(); i++) {
        timers[i].getTimeStemp();
    }
}
void Simulator::signalAll()
{
    for (int i = 0; i < timers.size(); i++) {
        for (int j = 0; j < timers.size(); j++) {
            timers[i].getNotife(timers[j].arriveAt);
        }
    }
}
void Simulator::updateAll()
{
    for (int i = 0; i < timers.size(); i++) {
        timers[i].updateTime();
    }
}
void testEntity()
{
    Entity entity1(1);
    Entity entity2(2);
    entity1.showTime();
    entity2.showTime();
    entity1.getTimeStemp();
    entity2.getTimeStemp();
    entity1.getNotife(entity2.arriveAt);
    entity2.getNotife(entity1.arriveAt);
    entity1.updateTime();
    entity2.updateTime();
    entity1.showTime();
    entity2.showTime();
}
void testUseRbs()
{
    Simulator simulator(3);
    simulator.showAll();
    simulator.setArriveAt();
    simulator.signalAll();
    simulator.updateAll();
    simulator.showAll();
}
int main()
{
    srand((unsigned)time(NULL));
    testUseRbs();
    return 0;
}
