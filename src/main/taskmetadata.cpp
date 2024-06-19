#include "taskmetadata.h"

TaskMetadata::TaskMetadata(QImage &image, QObject *parent)
    : QObject{parent}
    , m_image(image)
{
}

TaskMetadata::TaskMetadata(QObject *parent)
{
}

TaskMetadata::TaskMetadata(const TaskMetadata &other)
{
    this->m_strProcessName = other.m_strProcessName;
    this->m_image = other.m_image;
    this->m_strWindowTitle = other.m_strWindowTitle;
}

void TaskMetadata::setWindowTitle(const QString &title)
{
    m_strWindowTitle = title;
}

const QString &TaskMetadata::getWindowTitle()
{
    return m_strWindowTitle;
}

void TaskMetadata::setProcessName(const QString &name)
{
    m_strProcessName = name;
}

const QString &TaskMetadata::getProcessName()
{
    return m_strProcessName;
}

void TaskMetadata::updateInfo(Helpers::WindowInfo windowInfo)
{
    m_strWindowTitle = windowInfo.m_strText;
    m_strProcessName = windowInfo.m_strProcessName;
}


