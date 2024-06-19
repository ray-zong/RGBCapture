#ifndef CAPTURECUSTOMREGION_H
#define CAPTURECUSTOMREGION_H

#include <QObject>

#include "capturebase.h"

class TaskSettings;

class CaptureCustomRegion : public CaptureBase
{
    Q_OBJECT
public:

    virtual TaskMetadata execute(TaskSettings *pTaskSettings) override;

};

#endif // CAPTURECUSTOMREGION_H
