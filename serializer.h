#ifndef SERIALIZER_H
#define SERIALIZER_H

#include <QString>

class Serializer
{
public:
    virtual ~Serializer() =default;
    virtual bool serialize(QString &error) =0;
};

#endif // SERIALIZER_H
