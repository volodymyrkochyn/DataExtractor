#ifndef MODELSERIALIZER_H
#define MODELSERIALIZER_H

#include "serializer.h"

class QAbstractTableModel;

class ModelSerializer : public Serializer
{
public:
    ModelSerializer(QAbstractTableModel *model);

    bool serialize(QString &error) override;

    QString serializedData() const { return _serializedData; }

private:
    void appendData(const QString &data);

private:
    QAbstractTableModel *_model;
    QString _serializedData;
};

#endif // MODELSERIALIZER_H
