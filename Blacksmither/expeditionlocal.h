#ifndef EXPEDITIONLOCAL_H
#define EXPEDITIONLOCAL_H

#include <serializavel.h>

class ExpeditionLocal : public Serializavel{
private:
    QString localName;
    int eventID[3];
    QString localIDLeft, localIDRight;
    QString localDescp;
public:
    ExpeditionLocal();
    ExpeditionLocal(QString localName, int chance, int ID);

    ~ExpeditionLocal();

    QString getLocalName() const;
    void setLocalName(const QString &value);

    bool Serializar(QTextStream *stream);
    bool Deserializar(QTextStream *stream);
    QString getLocalIDLeft() const;
    void setLocalIDLeft(const QString &value);
    QString getLocalIDRight() const;
    void setLocalIDRight(const QString &value);
    QString getLocalDescp() const;
    void setLocalDescp(const QString &value);
};

#endif // EXPEDITIONLOCAL_H
