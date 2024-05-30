#ifndef TASKMETADATA_H
#define TASKMETADATA_H

#include <QObject>
#include <QImage>

#include "helpers/native/windowinfo.h"

class TaskMetadata : public QObject
{
    Q_OBJECT
public:
    explicit TaskMetadata(QImage &image, QObject *parent = nullptr);
    explicit TaskMetadata(QObject *parent = nullptr);
    TaskMetadata(const TaskMetadata &other);


    void setWindowTitle(const QString &title);
    const QString &getWindowTitle();

    void setProcessName(const QString &name);
    const QString &getProcessName();

    void updateInfo(Helpers::WindowInfo windowInfo);


public:
    QImage m_image;

private:
    QString m_strWindowTitle;
    QString m_strProcessName;

signals:

};

#endif // TASKMETADATA_H
