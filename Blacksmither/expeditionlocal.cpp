#include "expeditionlocal.h"

QString ExpeditionLocal::getLocalName() const
{
    return localName;
}

void ExpeditionLocal::setLocalName(const QString &value)
{
    localName = value;
}

bool ExpeditionLocal::Serializar(QTextStream *stream){
    return true;
}

bool ExpeditionLocal::Deserializar(QTextStream *stream){
    QStringList data = stream->readLine().split(";");
    this->localName = data[0];
    this->eventID[0] = data[1].toInt();
    this->eventID[1] = data[2].toInt();
    this->eventID[2] = data[3].toInt();
    this->localIDLeft = data[4];
    this->localIDRight = data[5];
    this->localDescp = data[6];
    return true;
}

QString ExpeditionLocal::getLocalIDLeft() const
{
    return localIDLeft;
}

void ExpeditionLocal::setLocalIDLeft(const QString &value)
{
    localIDLeft = value;
}

QString ExpeditionLocal::getLocalIDRight() const
{
    return localIDRight;
}

void ExpeditionLocal::setLocalIDRight(const QString &value)
{
    localIDRight = value;
}

QString ExpeditionLocal::getLocalDescp() const
{
    return localDescp;
}

void ExpeditionLocal::setLocalDescp(const QString &value)
{
    localDescp = value;
}

ExpeditionLocal::ExpeditionLocal(){

}

ExpeditionLocal::~ExpeditionLocal(){

}
