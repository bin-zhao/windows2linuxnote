#ifndef  _NINJIATRIBE_COMMON_H_
#define  _NINJIATRIBE_COMMON_H_


#include <cocos2d.h>

// PI
#define  _PI (3.14159f)
// 重力加速度系数
#define  _G  (9.8f)

// 计算平方长度
extern  float  SquaredLength(cocos2d::CCPoint x1a);

// 计算长度
extern  float  Length(cocos2d::CCPoint x1a);

// 归一
extern  float  Normalise(cocos2d::CCPoint& x1a);

// 矩形和圆形碰撞检测
extern  bool  IsCirlceCollisionRect(float circleXPos, float circleYPos, float radius, float rectX, float rectY, float rectW, float rectH);

// 线段和线段碰撞检测
extern  bool  IsLineCollisionLine(cocos2d::CCPoint line1StartPoint, cocos2d::CCPoint line1EndPoint, cocos2d::CCPoint line2StartPoint, cocos2d::CCPoint line2EndPoint);

// 线段和矩形碰撞检测
extern  bool  IsLineCollisionRect(cocos2d::CCPoint lineStartPoint, cocos2d::CCPoint lineEndPoint, cocos2d::CCPoint rectleftBottomPoint, float width, float height);


#endif
