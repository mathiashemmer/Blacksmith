#ifndef SERIALIZAVEL_H
#define SERIALIZAVEL_H

#include<string>
#include <QFile>
#include <QCoreApplication>
#include <QTextStream>

class Serializavel
{
public:
    Serializavel();
    virtual ~Serializavel();
    virtual bool Serializar(QTextStream *dataStream) = 0;
    virtual bool Deserializar(QTextStream *dataStream) = 0;
};

#endif // SERIALIZAVEL_H
