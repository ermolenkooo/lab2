#include "river.h"

River::River(QString ID, QString Name, QString Flow, QString Lenght, QString Runoff, QString Area, QObject *parent): QObject(parent)
{
    id = ID;
    name = Name;
    flow = Flow;
    lenght = Lenght;
    runoff = Runoff;
    area = Area;
}

void River::SetID(QString ID)
{
    id = ID;
}
void River::SetName(QString Name)
{
    name = Name;
}
void River::SetFlow(QString Flow)
{
    flow = Flow;
}
void River::SetLenght(QString Lenght)
{
    lenght = Lenght;
}
void River::SetRunoff(QString Runoff)
{
    runoff = Runoff;
}
void River::SetArea(QString Area)
{
    area = Area;
}

QString River::ID()
{
    return id;
}
QString River::Name()
{
    return name;
}
QString River::Flow()
{
    return flow;
}
QString River::Lenght()
{
    return lenght;
}
QString River::Runoff()
{
    return runoff;
}
QString River::Area()
{
    return area;
}

 River::~River()
{
}
