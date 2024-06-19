#ifndef CAPTUREACTIVEMONITOR_H
#define CAPTUREACTIVEMONITOR_H

#include <QObject>

#include "capturebase.h"

class TaskSettings;

class CaptureActiveMonitor : public CaptureBase
{
    Q_OBJECT
public:

    virtual TaskMetadata execute(TaskSettings *pTaskSettings) override;

};

#endif // CAPTUREACTIVEMONITOR_H
