#include "editriverdialog.h"
#include "river.h"

EditRiverDialog::EditRiverDialog(QWidget* pwgt): QDialog(pwgt)
{
    editID = new QLineEdit();
    editName = new QLineEdit();
    editFlow = new QLineEdit();
    editLenght = new QLineEdit();
    editRunoff = new QLineEdit();
    editArea = new QLineEdit();

    QGridLayout* mainLayout = new QGridLayout;
    mainLayout->addWidget(new QLabel("ID"),1,1);
    mainLayout->addWidget(editID,1,2);
    mainLayout->addWidget(new QLabel("Название"),2,1);
    mainLayout->addWidget(editName,2,2);
    mainLayout->addWidget(new QLabel("Куда впадает?"),3,1);
    mainLayout->addWidget(editFlow,3,2);
    mainLayout->addWidget(new QLabel("Протяженность"),4,1);
    mainLayout->addWidget(editLenght,4,2);
    mainLayout->addWidget(new QLabel("Годовой сток"),5,1);
    mainLayout->addWidget(editRunoff,5,2);
    mainLayout->addWidget(new QLabel("Площадь бассейна"),6,1);
    mainLayout->addWidget(editArea,6,2);

    QPushButton* btnOk = new QPushButton("&ОК");

    mainLayout->addWidget(btnOk,7,1,1,2);

    QObject::connect(btnOk, SIGNAL(clicked()), this, SLOT(accept()));

    this->setLayout(mainLayout);
    this->setWindowTitle("Данные о реке");

    int gx = 100;
    int gy = 100;
    if (pwgt!=nullptr)
    {
        gx = pwgt->geometry().x();
        gy = pwgt->geometry().y();

    }
    this->setGeometry(gx+10,gy+10,300,150);
}

QString EditRiverDialog::id() const
{
    return editID->text();
}
QString EditRiverDialog::name() const
{
    return editName->text();
}
QString EditRiverDialog::flow() const
{
    return editFlow->text();
}
QString EditRiverDialog::lenght() const
{
    return editLenght->text();
}
QString EditRiverDialog::runoff() const
{
    return editRunoff->text();
}
QString EditRiverDialog::area() const
{
    return editArea->text();
}

void EditRiverDialog::SetUpDialog(QString id, QString name, QString flow, QString lenght, QString runoff, QString area)
{
    editID->setText(id);
    editName->setText(name);
    editFlow->setText(flow);
    editLenght->setText(lenght);
    editRunoff->setText(runoff);
    editArea->setText(area);
}
