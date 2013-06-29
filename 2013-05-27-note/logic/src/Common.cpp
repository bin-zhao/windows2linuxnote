#include "../include/Common.h"
#include <include/common/Declare.h>
using  namespace  cobra_win;


float SquaredLength(cocos2d::CCPoint x1a)
{
	return x1a.x*x1a.x + x1a.y*x1a.y;
}

float Length(cocos2d::CCPoint x1a)
{
	return sqrt(x1a.x*x1a.x + x1a.y*x1a.y);
}

float Normalise(cocos2d::CCPoint& x1a)
{
	float fLength = sqrt( x1a.x*x1a.x + x1a.y*x1a.y);
	if (fLength > 1e-08)
	{
		float fInvLength = 1.0f/fLength;
		x1a.x *= fInvLength;
		x1a.y *= fInvLength;
	}

	return fLength;
}

bool IsCirlceCollisionRect(float circleXPos, float circleYPos, float radius, float rectX, float rectY, float rectW, float rectH)
{
	float arcR  = radius;
	float arcOx = circleXPos;
	float arcOy = circleYPos;

	//分别判断矩形4个顶点与圆心的距离是否<=圆半径；如果<=，说明碰撞成功   
	if(((rectX-arcOx) * (rectX-arcOx) + (rectY-arcOy) * (rectY-arcOy)) <= arcR * arcR)   
		return true;   
	if(((rectX+rectW-arcOx) * (rectX+rectW-arcOx) + (rectY-arcOy) * (rectY-arcOy)) <= arcR * arcR)   
		return true;   
	if(((rectX-arcOx) * (rectX-arcOx) + (rectY+rectH-arcOy) * (rectY+rectH-arcOy)) <= arcR * arcR)   
		return true;   
	if(((rectX+rectW-arcOx) * (rectX+rectW-arcOx) + (rectY+rectH-arcOy) * (rectY+rectH-arcOy)) <= arcR * arcR)   
		return true;

	//判断当圆心的Y坐标进入矩形内时X的位置，如果X在(rectX-arcR)到(rectX+rectW+arcR)这个范围内，则碰撞成功   
	float minDisX = 0;   
	if(arcOy >= rectY && arcOy <= rectY + rectH)
	{   
		if(arcOx < rectX)   
			minDisX = rectX - arcOx;   
		else if(arcOx > rectX + rectW)   
			minDisX = arcOx - rectX - rectW;   
		else    
			return true;   
		if(minDisX <= arcR)   
			return true;   
	}

	//判断当圆心的X坐标进入矩形内时Y的位置，如果X在(rectY-arcR)到(rectY+rectH+arcR)这个范围内，则碰撞成功
	float minDisY = 0;   
	if(arcOx >= rectX && arcOx <= rectX + rectW)
	{   
		if(arcOy < rectY)   
			minDisY = rectY - arcOy;   
		else if(arcOy > rectY + rectH)   
			minDisY = arcOy - rectY - rectH;   
		else  
			return true;   
		if(minDisY <= arcR)   
			return true;   
	}

	return false; 
}

bool IsLineCollisionLine(cocos2d::CCPoint p1, cocos2d::CCPoint p2, cocos2d::CCPoint p3, cocos2d::CCPoint p4)
{
	float x1 = p1.x, x2 = p2.x, x3 = p3.x, x4 = p4.x;
	float y1 = p1.y, y2 = p2.y, y3 = p3.y, y4 = p4.y;

	float d = (x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4);
	// If d is zero, there is no intersection
	if (d == 0) 
		return false;

	// Get the x and y
	float pre = (x1*y2 - y1*x2), post = (x3*y4 - y3*x4);
	float x = ( pre * (x3 - x4) - (x1 - x2) * post ) / d;
	float y = ( pre * (y3 - y4) - (y1 - y2) * post ) / d;

	// Check if the x and y coordinates are within both lines
	if ( x < MIN(x1, x2) || x > MAX(x1, x2) ||
		x < MIN(x3, x4) || x > MAX(x3, x4) )
		return false;

	if ( y < MIN(y1, y2) || y > MAX(y1, y2) ||
		y < MIN(y3, y4) || y > MAX(y3, y4) ) 
		return false;

	return true;
}

bool IsLineCollisionRect(cocos2d::CCPoint lineStartPoint, cocos2d::CCPoint lineEndPoint, cocos2d::CCPoint rectleftBottomPoint, float width, float height)
{
	// 因为这个方法专门进行射线光束的碰撞检测，所以暂不进行线段在矩形内的碰撞检测
	cocos2d::CCPoint leftLineStartPoint = rectleftBottomPoint;
	cocos2d::CCPoint leftLineEndPoint   = cocos2d::CCPoint(leftLineStartPoint.x, leftLineStartPoint.y+height);

	cocos2d::CCPoint rightLineStartPoint= cocos2d::CCPoint(leftLineStartPoint.x+width, leftLineStartPoint.y);
	cocos2d::CCPoint rightLineEndPoint  = cocos2d::CCPoint(leftLineStartPoint.x+width, leftLineStartPoint.y+height);

	cocos2d::CCPoint topLineStartPoint  = cocos2d::CCPoint(leftLineStartPoint.x, leftLineStartPoint.y+height);
	cocos2d::CCPoint topLineEndPoint    = cocos2d::CCPoint(leftLineStartPoint.x+width, leftLineStartPoint.y+height);

	cocos2d::CCPoint bottomLineStartPoint= cocos2d::CCPoint(leftLineStartPoint.x, leftLineStartPoint.y);
	cocos2d::CCPoint bottomLineEndPoint  = cocos2d::CCPoint(leftLineStartPoint.x+width, leftLineStartPoint.y);
	
	do 
	{
		if (IsLineCollisionLine(lineStartPoint, lineEndPoint, leftLineStartPoint, leftLineEndPoint))
			break;

		if (IsLineCollisionLine(lineStartPoint, lineEndPoint, rightLineStartPoint, rightLineEndPoint))
			break;

		if (IsLineCollisionLine(lineStartPoint, lineEndPoint, topLineStartPoint, topLineEndPoint))
			break;

		if (IsLineCollisionLine(lineStartPoint, lineEndPoint, bottomLineStartPoint, bottomLineEndPoint))
			break;

		return false;
	} 
	while (false);

	return true;
}

