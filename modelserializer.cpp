#include "modelserializer.h"
#include <QAbstractTableModel>

ModelSerializer::ModelSerializer(QAbstractTableModel *model) : _model(model)
{
}

bool ModelSerializer::serialize(QString &error)
{
    if (_model)
    {
        QStringList data;
        QStringList header;
        for (int col = 0; col < _model->columnCount(); ++col)
        {
            header.append(_model->headerData(col, Qt::Horizontal).toString());
        }
        appendData(header.join("    "));
        for (int col = 0; col < _model->columnCount(); ++col)
        {
            data.clear();
            for (int row = 0; row < _model->rowCount(); ++row)
                data.append(_model->data(_model->index(row, col), Qt::DisplayRole).toString());
            appendData(data.join("    "));
        }
        return true;
    }
    error = QStringLiteral("No data to serialize.");
    return false;

}

void ModelSerializer::appendData(const QString &data)
{
    if (!_serializedData.isEmpty())
        _serializedData.append("\n");
    _serializedData.append(data);
}
