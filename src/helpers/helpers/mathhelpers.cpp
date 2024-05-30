#include "mathhelpers.h"

#include <QtMath>

const float MathHelpers::RadianPI = 57.29578f; // 180 / PI
const float MathHelpers::DegreePI = 0.01745329f; // PI / 180
const float MathHelpers::TwoPI = 6.28319f;  //PI * 2

MathHelpers::MathHelpers()
{

}

float MathHelpers::remap(float value, float from1, float to1, float from2, float to2)
{
    return ((value - from1) / (to1 - from1) * (to2 - from2)) + from2;
}

bool MathHelpers::isEvenNumber(int num)
{
    return num % 2 == 0;
}

bool MathHelpers::isOddNumber(int num)
{
    return num % 2 != 0;
}

float MathHelpers::lerp(float value1, float value2, float amount)
{
    return value1 + ((value2 - value1) * amount);
}

QPointF MathHelpers::lerp(const QPointF &pos1, const QPointF &pos2, float amount)
{
    float x = lerp(pos1.x(), pos2.x(), amount);
    float y = lerp(pos1.y(), pos2.y(), amount);
    return QPointF(x, y);
}

float MathHelpers::radianToDegree(float radian)
{
    return radian * RadianPI;
}

float MathHelpers::degreeToRadian(float degree)
{
    return degree * DegreePI;
}

QPointF MathHelpers::radianToVector2(float radian)
{
    return QPointF((float)qCos(radian), (float)qSin(radian));
}

QPointF MathHelpers::radianToVector2(float radian, float length)
{
    return radianToVector2(radian) * length;
}

QPointF MathHelpers::degreeToVector2(float degree)
{
    return radianToVector2(degreeToRadian(degree));
}

QPointF MathHelpers::degreeToVector2(float degree, float length)
{
    return radianToVector2(degreeToRadian(degree), length);
}

float MathHelpers::vector2ToRadian(const QPointF &direction)
{
    return (float)qAtan2(direction.y(), direction.x());
}

float MathHelpers::lookAtRadian(const QPointF &pos1, const QPointF &pos2)
{
    return (float)qAtan2(pos2.y() - pos1.y(), pos2.x() - pos1.x());
}

float MathHelpers::lookAtDegree(const QPointF &pos1, const QPointF &pos2)
{
    return radianToDegree(lookAtRadian(pos1, pos2));
}

float MathHelpers::distance(const QPointF &pos1, const QPointF &pos2)
{
    return (float)qSqrt(qPow(pos2.x() - pos1.x(), 2) + qPow(pos2.y() - pos1.y(), 2));
}
