#ifndef WATCHFOLDERSETTINGS_H
#define WATCHFOLDERSETTINGS_H

#include <QString>

class WatchFolderSettings
{
public:
    QString strFolderPath;
    QString strFilter;
    bool bIncludeSubdirectories;
    bool bMoveFilesToScreenshotsFolder;
};
#endif // WATCHFOLDERSETTINGS_H
