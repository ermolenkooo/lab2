#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QtWidgets"
#include "myModel.h"
#include "QGridLayout"
#include "linedelegate.h"
#include "editriverdialog.h"
#include "dialogdelegate.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Справочник гидролога");
    tableView = new QTableView();
    myModel = new MyModel(this);
    tableView->setModel( myModel );

    DialogDelegate* ddel = new DialogDelegate(nullptr,this);
    lineDelegate* ldel = new lineDelegate();
    tableView->setItemDelegateForColumn(0,ddel);
    tableView->setItemDelegateForColumn(1,ldel);
    tableView->setItemDelegateForColumn(2,ldel);
    tableView->setItemDelegateForColumn(3,ldel);
    tableView->setItemDelegateForColumn(4,ldel);
    tableView->setItemDelegateForColumn(5,ldel);
    tableView->viewport()->setAttribute(Qt::WA_Hover); //устанавливаем флаг, чтобы представление реагировало на перемещения курсора мыши

    tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);

    this->setMaximumHeight(300);
    this->setMinimumWidth(300);


    QGridLayout* glay= new QGridLayout();
    glay->addWidget(tableView,1,1,1,2);

    QPushButton* pb1 = new QPushButton("Добавить");
    QPushButton* pb2 = new QPushButton("Удалить");
    QPushButton* pb3 = new QPushButton("Расположить по алфавиту");

    glay->addWidget(pb1,2,1);
    glay->addWidget(pb2,2,2);
    glay->addWidget(pb3,3,1,1,2);

    QObject::connect(pb1,SIGNAL(clicked(bool)),this,SLOT(AddRow()));
    QObject::connect(pb2,SIGNAL(clicked(bool)),this,SLOT(DeleteRow()));
    QObject::connect(pb3,SIGNAL(clicked(bool)),this,SLOT(Sort()));

    QWidget* wdg=new QWidget();
    wdg->setLayout(glay);

    this->setCentralWidget(wdg);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::AddRow()
{
    EditRiverDialog* addDialog = new EditRiverDialog(this);
    if (addDialog->exec() == QDialog::Accepted)
    {
        River* r = new River(addDialog->id(),addDialog->name(),addDialog->flow(), addDialog->lenght(), addDialog->runoff(), addDialog->area(), this);
        myModel->AddRiver(r);
    }
    addDialog->deleteLater();
}

void MainWindow::DeleteRow()
{
    QModelIndex selList = tableView->currentIndex();
    myModel->DeleteRiver(selList.row());
}

void MainWindow::Sort()
{
    myModel->Sort();
}
