#ifndef CAPTUREREGION_H
#define CAPTUREREGION_H

#include <QObject>

#include "capturebase.h"
#include "main/enums.h"

class TaskSettings;

class CaptureRegion : public CaptureBase
{
    Q_OBJECT
public:
    CaptureRegion();
    CaptureRegion(RegionCaptureType type);

    virtual TaskMetadata execute(TaskSettings *pTaskSettings) override;

    void setRegionCaptureType(RegionCaptureType type);
    RegionCaptureType getRegionCaptureType();

protected:
    TaskMetadata executeRegionCapture(TaskSettings *pTaskSettings);
    TaskMetadata executeRegionCaptureLight(TaskSettings *pTaskSettings);
    TaskMetadata executeRegionCaptureTransparent(TaskSettings *pTaskSettings);

protected:
    static RegionCaptureType lastRegionCaptureType;

private:
    RegionCaptureType m_enRegionCaptureType;

};

#endif // CAPTUREREGION_H
