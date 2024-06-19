#ifndef CAPTUREFULLSCREEN_H
#define CAPTUREFULLSCREEN_H

#include <QObject>

#include "capturebase.h"

class TaskSettings;

class CaptureFullScreen: public CaptureBase
{
    Q_OBJECT
public:

    virtual TaskMetadata execute(TaskSettings *pTaskSettings) override;

};

#endif // CAPTUREFULLSCREEN_H
