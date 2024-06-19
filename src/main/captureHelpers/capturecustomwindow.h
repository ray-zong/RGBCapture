#ifndef CAPTURECUSTOMWINDOW_H
#define CAPTURECUSTOMWINDOW_H

#include <QObject>

#include "capturebase.h"

class TaskSettings;

class CaptureCustomWindow : public CaptureBase
{
    Q_OBJECT
public:

    virtual TaskMetadata execute(TaskSettings *pTaskSettings) override;

};

#endif // CAPTURECUSTOMWINDOW_H
