﻿#ifndef  _NINJIATRIBE_GUIDEDATAMANAGER_H_
#define  _NINJIATRIBE_GUIDEDATAMANAGER_H_


#include <include/common/Singleton.h>
#include "IDataManager.h"
#include <list>
#include <string>
using  namespace  cobra_win;

#pragma pack(push, 1)
class GuideItemData : public IData
{
public:
	int   mGuideType;              // 引导类型
	int   mGuideIndex;             // 引导索引
	int   mMaskRedColor;           // 引导蒙版红色值
	int   mMaskGreenColor;         // 引导蒙版绿色值
	int   mMaskBlueColor;          // 引导蒙版蓝色值
	int   mMaskAlphaColor;         // 引导蒙版透明度
	float mMaskStartXPos;          // 引导高亮区开始X坐标
	float mMaskStartYPos;          // 引导高亮区开始Y坐标
	float mMaskEndXPos;            // 引导高亮区结束X坐标
	float mMaskEndYPos;            // 引导高亮区结束Y坐标
	bool  mClickAnyWhereToNextStep;// 点击任何区域就直接开始下一步操作
	bool  mClickButtonToNextStep;  // 只有点击button才会进入下一步操作
	char  mButtonEventName[128];   // 按钮操作的事件名称
	char  mButtonName[128];        // 按钮名称
	bool  mShowGuideArrow;         // 是否显示引导箭头
	char  mArrowImageName[128];    // 引导箭头名称
	float mArrowXPos;              // 引导箭头X坐标
	float mArrowYPos;              // 引导箭头Y坐标
	float mArrowRotation;          // 引导箭头旋转角度
	bool  mShowGuide;              // 是否显示引导员图片
	char  mGuideImageName[128];    // 引导员图片名称
	float mGuideXPos;              // 引导员X坐标
	float mGuideYPos;              // 引导员Y坐标
	char  mGuideTextCn[1024];      // 引导文字中文
	char  mGuideTextEn[1024];      // 引导文字英语

public:
	GuideItemData();
	virtual ~GuideItemData();

public:
	/*
		解析数据
	*/
	virtual  bool  ParseBuffer(char* pBuffer, unsigned int iLen);
};
#pragma pack(pop)


class GuideDataManager : public IDataManager, public cobra_win::Singleton2<GuideDataManager>
{
public:
	std::list<GuideItemData*> m_GuideStepList;

public:
	GuideDataManager(bool bLoadFromDB, bool bEncryption);
	virtual ~GuideDataManager();

public:
	/*
		得到新手引导类型对应的步骤个数
	*/
	int  GetGuideStepNumberByType(int guideType);
	/*
        得到指定步骤的新手引导信息
    */
	GuideItemData* GetGuideStepInfoByIndex(int guideType, int guideIdx);

public:
	/*
		得到对应的数据管理器名称
	*/
	virtual  std::string   GetName();
	/*
		得到对应的数据管理器内存占用大小
	*/
	virtual  unsigned  int GetSize();

public:
	/*
		初始化数据管理器
	*/
	virtual  bool  Init();
	/*
		数据管理器帧更新处理
	*/
	virtual  void  Tick();
	/*
		销毁数据管理器
	*/
	virtual  void  Destroy();

public:
	/*
		校验加载的数据(单行数据的有效性校验)
	*/
	virtual  bool  Varify(IData* pData);
	/*
		校验加载的数据(所有数据加载完之后进行的表与表关联性校验)
	*/
	virtual  bool  VarifyAfterLoadAll();

protected:
	/*
		创建指定的ItemData数据
	*/
	virtual  bool  LoadData(char* pBuffer, unsigned int iBufferLen);

private:
	friend   class   cobra_win::Singleton2<GuideDataManager>;
};


#endif