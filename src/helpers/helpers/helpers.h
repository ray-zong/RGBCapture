#ifndef HELPERS_H
#define HELPERS_H

#include <QString>

class Helpers
{
public:
    Helpers();
    const QString Numbers = "0123456789"; // 48 ... 57
    const QString AlphabetCapital = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; // 65 ... 90
    const QString Alphabet = "abcdefghijklmnopqrstuvwxyz"; // 97 ... 122
    const QString Alphanumeric = Numbers + AlphabetCapital + Alphabet;
    const QString AlphanumericInverse = Numbers + Alphabet + AlphabetCapital;
    const QString Hexadecimal = Numbers + "ABCDEF";
    const QString Base58 = "123456789ABCDEFGHJKLMNPQRSTUVWXYZabcdefghijkmnopqrstuvwxyz"; // https://en.wikipedia.org/wiki/Base58
    const QString Base56 = "23456789ABCDEFGHJKLMNPQRSTUVWXYZabcdefghijkmnpqrstuvwxyz"; // A variant, Base56, excludes 1 (one) and o (lowercase o) compared to Base 58.


    static bool isWindowsXP();
    static bool isWindowsXPOrGreater();
    static bool isWindowsVista();
    static bool isWindowsVistaOrGreater();
    static bool isWindows7();
    static bool isWindows7OrGreater();
    static bool isWindows8();
    static bool isWindows8OrGreater();
    static bool isWindows10OrGreater(int build = -1);
    static bool isWindows11OrGreater(int build = -1);


};

#endif // HELPERS_H
