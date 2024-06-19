#include "helpers.h"

#include <QOperatingSystemVersion>

Helpers::Helpers()
{

}

bool Helpers::isWindowsXP()
{
    static QOperatingSystemVersion osVersion = QOperatingSystemVersion::current();
    return osVersion.majorVersion() == 5 && osVersion.minorVersion() == 1;
}

bool Helpers::isWindowsXPOrGreater()
{
    static QOperatingSystemVersion osVersion = QOperatingSystemVersion::current();


    return (osVersion.majorVersion() == 5 && osVersion.minorVersion() >= 1) || osVersion.majorVersion() > 5;
}

bool Helpers::isWindowsVista()
{
    static QOperatingSystemVersion osVersion = QOperatingSystemVersion::current();


    return osVersion.majorVersion() == 6;
}

bool Helpers::isWindowsVistaOrGreater()
{
    static QOperatingSystemVersion osVersion = QOperatingSystemVersion::current();


    return osVersion.majorVersion() >= 6;
}

bool Helpers::isWindows7()
{
    static QOperatingSystemVersion osVersion = QOperatingSystemVersion::current();


    return osVersion.majorVersion() == 6 && osVersion.minorVersion() == 1;
}

bool Helpers::isWindows7OrGreater()
{
    static QOperatingSystemVersion osVersion = QOperatingSystemVersion::current();


    return (osVersion.majorVersion() == 6 && osVersion.minorVersion() >= 1) || osVersion.majorVersion() > 6;
}

bool Helpers::isWindows8()
{
    static QOperatingSystemVersion osVersion = QOperatingSystemVersion::current();


    return osVersion.majorVersion() == 6 && osVersion.minorVersion() == 2;
}

bool Helpers::isWindows8OrGreater()
{
    static QOperatingSystemVersion osVersion = QOperatingSystemVersion::current();


    return (osVersion.majorVersion() == 6 && osVersion.minorVersion() >= 2) || osVersion.majorVersion() > 6;
}

bool Helpers::isWindows10OrGreater(int build)
{

    static QOperatingSystemVersion osVersion = QOperatingSystemVersion::current();


    //return osVersion.majorVersion() >= 10 /*&& osVersion.*/;
    return osVersion >= QOperatingSystemVersion::Windows10;
}

bool Helpers::isWindows11OrGreater(int build)
{
    static QOperatingSystemVersion osVersion = QOperatingSystemVersion::current();

    //return osVersion.majorVersion() >= 10;
    return osVersion >= QOperatingSystemVersion::Windows11;
}




