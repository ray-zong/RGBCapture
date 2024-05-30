#ifndef CAPTUREBASE_H
#define CAPTUREBASE_H

#include <QObject>

#include "taskmetadata.h"

class TaskSettings;

class CaptureBase : public QObject
{
    Q_OBJECT
public:
    explicit CaptureBase(QObject *parent = nullptr);

    void capture(bool autoHideForm);

    void capture(TaskSettings *pTaskSettings, bool autoHideForm = false);

    virtual TaskMetadata execute(TaskSettings *pTaskSettings);

    void afterCapture(TaskMetadata &metadata, TaskSettings *pTaskSettings);

signals:

private slots:
    void captureInternal(TaskSettings *pTaskSettings, bool autoHideForm);

private:
    bool m_bAllowAutoHideForm;
    bool m_bAllowAnnotation;

};

#endif // CAPTUREBASE_H
