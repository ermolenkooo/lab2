#include "dialogdelegate.h"
#include "QtWidgets"
#include "editriverdialog.h"

DialogDelegate::DialogDelegate(QObject *parent, QWidget* parentWidget): QStyledItemDelegate(parent)
{
    dparentWidget = parentWidget;
}

bool DialogDelegate::editorEvent(QEvent *event, QAbstractItemModel *model,
                 const QStyleOptionViewItem &, const QModelIndex &index)
{
    if (event->type() == QEvent::MouseButtonDblClick)
    {
        EditRiverDialog* editDialog = new EditRiverDialog(dparentWidget);

        QString ID = model->data(model->index(index.row(),0,index)).toString();
        QString Name = model->data(model->index(index.row(),1,index)).toString();
        QString Flow = model->data(model->index(index.row(),2,index)).toString();
        QString Lenght = model->data(model->index(index.row(),3,index)).toString();
        QString Runoff = model->data(model->index(index.row(),4,index)).toString();
        QString Area = model->data(model->index(index.row(),5,index)).toString();

        editDialog->SetUpDialog(ID, Name, Flow, Lenght, Runoff, Area);
        if (editDialog->exec() == QDialog::Accepted)
        {
            model->setData(model->index(index.row(),0,index),editDialog->id());
            model->setData(model->index(index.row(),1,index),editDialog->name());
            model->setData(model->index(index.row(),2,index),editDialog->flow());
            model->setData(model->index(index.row(),3,index),editDialog->lenght());
            model->setData(model->index(index.row(),4,index),editDialog->runoff());
            model->setData(model->index(index.row(),5,index),editDialog->area());
        }
        editDialog->deleteLater();
    }
    return false;

}

QWidget *DialogDelegate::createEditor(QWidget* /* parent */,
    const QStyleOptionViewItem &/* option */,
    const QModelIndex &/* index */) const
{
    return nullptr;
}
