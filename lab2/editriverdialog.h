#ifndef EDITRIVERDIALOG_H
#define EDITRIVERDIALOG_H

#include <QDialog>
#include <QtWidgets>
#include "river.h"

class EditRiverDialog : public QDialog
{
  Q_OBJECT

private:
    QLineEdit* editID;
    QLineEdit* editName;
    QLineEdit* editFlow;
    QLineEdit* editLenght;
    QLineEdit* editRunoff;
    QLineEdit* editArea;

public:
    EditRiverDialog(QWidget* pwgt = nullptr);

    QString id() const;
    QString name() const;
    QString flow() const;
    QString lenght() const;
    QString runoff() const;
    QString area() const;

    void SetUpDialog(QString id, QString name, QString flow, QString lenght, QString runoff, QString area);
};

#endif // EDITRIVERDIALOG_H
