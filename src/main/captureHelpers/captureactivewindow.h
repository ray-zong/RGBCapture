#ifndef CAPTUREACTIVEWINDOW_H
#define CAPTUREACTIVEWINDOW_H

#include <QObject>

#include "capturebase.h"

class TaskSettings;

class CaptureActiveWindow : public CaptureBase
{
    Q_OBJECT
public:

    virtual TaskMetadata execute(TaskSettings *pTaskSettings) override;

};

#endif // CAPTUREACTIVEWINDOW_H
