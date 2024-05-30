#ifndef EXTERNALPROGRAM_H
#define EXTERNALPROGRAM_H

#include <QObject>

class ExternalProgram : public QObject
{
    Q_OBJECT
public:
    explicit ExternalProgram(QObject *parent = nullptr);

signals:

};

#endif // EXTERNALPROGRAM_H
