#ifndef CAPTUREWINDOW_H
#define CAPTUREWINDOW_H

#include <QObject>

#include "capturebase.h"

class TaskSettings;

class CaptureWindow : public CaptureBase
{
    Q_OBJECT
public:

    virtual TaskMetadata execute(TaskSettings *pTaskSettings) override;

};

#endif // CAPTUREACTIVEMONITOR_H
