#ifndef MATHHELPERS_H
#define MATHHELPERS_H

#include <QPointF>

class MathHelpers
{
public:
    MathHelpers();

    static const float RadianPI; // 180 / PI
    static const float DegreePI; // PI / 180
    static const float TwoPI;  //PI * 2

    static float remap(float value, float from1, float to1, float from2, float to2);

    static bool isEvenNumber(int num);

    static bool isOddNumber(int num);

    static float lerp(float value1, float value2, float amount);

    static QPointF lerp(const QPointF &pos1, const QPointF &pos2, float amount);

    static float radianToDegree(float radian);

    static float degreeToRadian(float degree);

    static QPointF radianToVector2(float radian);

    static QPointF radianToVector2(float radian, float length);

    static QPointF degreeToVector2(float degree);

    static QPointF degreeToVector2(float degree, float length);

    static float vector2ToRadian(const QPointF &direction);

    static float lookAtRadian(const QPointF &pos1, const QPointF &pos2);

    static float lookAtDegree(const QPointF &pos1, const QPointF &pos2);

    static float distance(const QPointF & pos1, const QPointF &pos2);

};

#endif // MATHHELPERS_H
