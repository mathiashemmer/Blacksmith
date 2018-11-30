#ifndef EXPEDITIONLOCAL_H
#define EXPEDITIONLOCAL_H

#include <serializavel.h>

class ExpeditionLocal : public Serializavel{
private:
    QString localName;
    int eventID[3];
public:
    ExpeditionLocal();
    ExpeditionLocal(QString localName, int chance, int ID);

    QString getLocalName() const;
    void setLocalName(const QString &value);

    bool Serializsar(QTextStream *stream);
    bool Deserializsar(QTextStream *stream);
};

#endif // EXPEDITIONLOCAL_H
