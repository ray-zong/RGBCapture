#ifndef CAPTURELASTREGION_H
#define CAPTURELASTREGION_H

#include <QObject>

#include "capturebase.h"

class TaskSettings;

class CaptureLastRegion : public CaptureBase
{
    Q_OBJECT
public:

    virtual TaskMetadata execute(TaskSettings *pTaskSettings) override;

};

#endif // CAPTURELASTREGION_H
