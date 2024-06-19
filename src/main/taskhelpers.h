#ifndef TASKHELPERS_H
#define TASKHELPERS_H

#include "screenCapture/screenshot.h"

class TaskSettings;

class TaskHelpers
{
public:
    static Screenshot &getScreenshot(TaskSettings *pTaskSettings = nullptr);

private:
    static Screenshot m_sScreenshot;
};

#endif // TASKHELPERS_H
