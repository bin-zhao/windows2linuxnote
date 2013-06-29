#include "../include/UILayer.h"
#include "../include/InputEvent.h"
#include "../include/InputSystem.h"
#include "../include/LoggerSystem.h"


UILayer::UILayer()
{

}

UILayer::~UILayer()
{

}

void UILayer::onEnter()
{
	cocos2d::CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, getPriority(), true);
	this->setKeypadEnabled(true);

	cocos2d::CCLayer::onEnter();
}

void UILayer::onExit()
{
	this->setKeypadEnabled(false);
	cocos2d::CCDirector::sharedDirector()->getTouchDispatcher()->removeDelegate(this);

	cocos2d::CCLayer::onExit();
}	

bool UILayer::ccTouchBegan(cocos2d::CCTouch* touche, cocos2d::CCEvent* event)
{
	cocos2d::CCPoint touchLocation = touche->getLocation();

	InputEvent inputEvent;
	inputEvent.mEventID = _TYPED_INPUT_EVENT_TOUCHBEGIN_;
	inputEvent.mXPos    = touchLocation.x;
	inputEvent.mYPos    = touchLocation.y;
	INPUTSYSTEM->AddInputEvent(inputEvent);

	LOGGERSYSTEM->LogTrace("UILayer Touch Begin: xPos=%f, yPos=%f\n", inputEvent.mXPos, inputEvent.mYPos);
	return true;
}

void UILayer::ccTouchMoved(cocos2d::CCTouch* touche, cocos2d::CCEvent* event)
{
	cocos2d::CCPoint preTouchLocation = touche->getPreviousLocation();
	cocos2d::CCPoint touchLocation    = touche->getLocation();

	InputEvent inputEvent;
	inputEvent.mEventID = _TYPED_INPUT_EVENT_TOUCHMOVE_;
	inputEvent.mXPos    = touchLocation.x;
	inputEvent.mYPos    = touchLocation.y;
	inputEvent.mPreXPos = preTouchLocation.x;
	inputEvent.mPreYPos = preTouchLocation.y;

	LOGGERSYSTEM->LogTrace("UILayer Touch Move: xPos=%f, yPos=%f\n", inputEvent.mXPos, inputEvent.mYPos);
	INPUTSYSTEM->AddInputEvent(inputEvent);
}

void UILayer::ccTouchEnded(cocos2d::CCTouch* touche, cocos2d::CCEvent* event)
{
	cocos2d::CCPoint touchLocation = touche->getLocation();

	InputEvent inputEvent;
	inputEvent.mEventID = _TYPED_INPUT_EVENT_TOUCHEND_;
	inputEvent.mXPos    = touchLocation.x;
	inputEvent.mYPos    = touchLocation.y;
	INPUTSYSTEM->AddInputEvent(inputEvent);

	LOGGERSYSTEM->LogTrace("UILayer Touch End: xPos=%f, yPos=%f\n", inputEvent.mXPos, inputEvent.mYPos);
}

void UILayer::ccTouchCancelled(cocos2d::CCTouch* touche, cocos2d::CCEvent* event)
{
	cocos2d::CCPoint touchLocation = touche->getLocation();

	InputEvent inputEvent;
	inputEvent.mEventID = _TYPED_INPUT_EVENT_TOUCHEND_;
	inputEvent.mXPos    = touchLocation.x;
	inputEvent.mYPos    = touchLocation.y;
	INPUTSYSTEM->AddInputEvent(inputEvent);

	LOGGERSYSTEM->LogTrace("UILayer Touch Cancel: xPos=%f, yPos=%f\n", inputEvent.mXPos, inputEvent.mYPos);
}

void UILayer::didAccelerate(cocos2d::CCAcceleration* pAccelerationValue)
{
	InputEvent inputEvent;
	inputEvent.mEventID   = _TYPED_INPUT_EVENT_ACCELERATE_;
	inputEvent.mXPos      = (float)pAccelerationValue->x;
	inputEvent.mYPos      = (float)pAccelerationValue->y;
	inputEvent.mZPos      = (float)pAccelerationValue->z;
	inputEvent.mTimeStamp = pAccelerationValue->timestamp;
	INPUTSYSTEM->AddInputEvent(inputEvent);

	LOGGERSYSTEM->LogTrace("UILayer Accelerate: xPos=%f, yPos=%f, zPos=%f, timestamp=%f\n", inputEvent.mXPos, inputEvent.mYPos, inputEvent.mZPos, inputEvent.mTimeStamp);
}

void UILayer::keyBackClicked()
{
	InputEvent inputEvent;
	inputEvent.mEventID = _TYPED_INPUT_EVENT_KEY_BACK_CLICKED_;
	INPUTSYSTEM->AddInputEvent(inputEvent);
	LOGGERSYSTEM->LogTrace("UILayer: key back clicked\n");
}

void UILayer::keyMenuClicked()
{
	InputEvent inputEvent;
	inputEvent.mEventID = _TYPED_INPUT_EVENT_KEY_MENU_CLICKED_;
	INPUTSYSTEM->AddInputEvent(inputEvent);
	LOGGERSYSTEM->LogTrace("UILayer: key menu clicked\n");
}
