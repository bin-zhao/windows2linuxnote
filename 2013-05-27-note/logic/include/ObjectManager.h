#ifndef  _NINJIATRIBE_OBJECTMANAGER_H_
#define  _NINJIATRIBE_OBJECTMANAGER_H_


#include <include/common/Singleton.h>
#include <list>
#include <map>
using  namespace  cobra_win;

class IObject;
class ObjectManager : public cobra_win::Singleton2<ObjectManager>
{
public:
	std::list<IObject*> m_ObjectList;
	std::map<std::string, IObject*> m_ObjectListById;

public:
	ObjectManager();
	virtual ~ObjectManager();

public:
	/*
		得到当前对象总数
	*/
	unsigned int GetObjectNumber();
	/*
		得到指定位置的对象信息
	*/
	IObject* GetObjectByPos(unsigned int pos);
	/*
		得到指定Id的对象信息
	*/
	IObject* GetObjectById(std::string id);

public:
	/*
		插入对象
	*/
	void  InsertObject(IObject* pObject);
	/*
		删除对象
	*/
	void  DeleteObject(IObject* pObject);
	/*
		删除所有对象
	*/
	void  DeleteAllObject();

public:
	/*
		初始化对象系统管理器
	*/
	bool  Init();
	/*
		对象系统逻辑桢更新
	*/
	void  Tick();
	/*
		销毁对象系统管理器
	*/
	void  Destroy();

public:
	/*
		获得唯一的对象Id
	*/
	static  std::string  CreateObjectId(int objectType);
public:
	friend  class  cobra_win::Singleton2<ObjectManager>;
};

#define  OBJECTMANAGER  (ObjectManager::get_instance2())


#endif
