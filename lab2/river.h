#ifndef RIVER_H
#define RIVER_H
#include "QString"
#include <QObject>

class River: public QObject
{
    Q_OBJECT

public:
    River(QString ID, QString Name, QString Flow, QString Lenght, QString Runoff, QString Area, QObject *parent = nullptr );
    virtual ~River();
    void SetID(QString ID);
    void SetName(QString Name);
    void SetFlow(QString Flow);
    void SetLenght(QString Lenght);
    void SetRunoff(QString Runoff);
    void SetArea(QString Area);

    QString ID();
    QString Name();
    QString Flow();
    QString Lenght();
    QString Runoff();
    QString Area();

private:
    QString id;
    QString name; //название
    QString lenght; //протяженность
    QString flow; //куда впадает
    QString runoff; //годовой сток
    QString area; //площадь бассейна
};

#endif // RIVER_H
