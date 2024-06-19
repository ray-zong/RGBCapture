#ifndef CAPTUREMONITOR_H
#define CAPTUREMONITOR_H

#include <QObject>

#include "capturebase.h"

class TaskSettings;

class CaptureMonitor : public CaptureBase
{
    Q_OBJECT
public:

    virtual TaskMetadata execute(TaskSettings *pTaskSettings) override;

    void setMonitorRectangle(QRect rect);
    QRect getMonitorRectangle();

    void captureMonitor(QRect rect);

private:
    QRect m_monitorRectangle;
};

#endif // CAPTUREMONITOR_H
