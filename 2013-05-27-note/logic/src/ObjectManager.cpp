#include "../include/ObjectManager.h"
#include "../include/LoggerSystem.h"
#include "../include/IObject.h"
#include "../include/ArenaProcedure.h"
#include "../include/NinjiaTribeApp.h"
#include "../include/SceneManager.h"


template<> ObjectManager* cobra_win::Singleton2<ObjectManager>::m_pMySelf = NULL;

ObjectManager::ObjectManager()
{
	m_ObjectList.clear();
	m_ObjectListById.clear();
}

ObjectManager::~ObjectManager()
{

}

unsigned int ObjectManager::GetObjectNumber()
{
	return m_ObjectList.size();
}

IObject* ObjectManager::GetObjectByPos(unsigned int pos)
{
	assert(pos < m_ObjectList.size());

	std::list<IObject*>::iterator iter   = m_ObjectList.begin();
	std::list<IObject*>::iterator iter_e = m_ObjectList.end();
	for (int i=0; iter!=iter_e; ++i, ++iter)
	{
		if (i == pos)
			return (*iter);
	}

	return NULL;
}

IObject* ObjectManager::GetObjectById(std::string id)
{
	std::map<std::string, IObject*>::iterator iter = m_ObjectListById.find(id);
	if (iter != m_ObjectListById.end() && iter->second->GetIsValid())
	{
		return iter->second;
	}

	return NULL;
}

void ObjectManager::InsertObject(IObject* pObject)
{
	assert(pObject != NULL);

	m_ObjectList.push_back(pObject);
	m_ObjectListById[pObject->GetObjectId()] = pObject;
}

void ObjectManager::DeleteObject(IObject* pObject)
{
	assert(pObject != NULL);

	std::list<IObject*>::iterator iter   = m_ObjectList.begin();
	std::list<IObject*>::iterator iter_e = m_ObjectList.end();
	for ( ; iter!=iter_e; )
	{
		std::list<IObject*>::iterator temp = iter;
		++iter;

		if ((*temp) == pObject)
		{
			// 从玩家Id列表中清除
			std::map<std::string, IObject*>::iterator iter2 = m_ObjectListById.find(pObject->GetObjectId());
			if (iter2 != m_ObjectListById.end())
				m_ObjectListById.erase(iter2);

			(*temp)->Destroy();
			delete (*temp);
			m_ObjectList.erase(temp);
			return ;
		}
	}
}

void ObjectManager::DeleteAllObject()
{
	std::list<IObject*>::iterator iter   = m_ObjectList.begin();
	std::list<IObject*>::iterator iter_e = m_ObjectList.end();
	for ( ; iter!=iter_e; ++iter)
	{
		(*iter)->Destroy();
		delete (*iter);
	}
	m_ObjectList.clear();
	m_ObjectListById.clear();
}

bool ObjectManager::Init()
{
	m_ObjectList.clear();
	m_ObjectListById.clear();
	LOGGERSYSTEM->LogInfo("Init ObjectManager Success\n");
	return true;
}

void ObjectManager::Tick()
{
	// 不是竞技场流程，暂不进行Tick
	if (NinjiaTribeApp::get_instance2()->m_pActiveProcedure->GetType() != IProcedure::_TYPED_ARENA_PROCEDURE_)
		return;

	if (NinjiaTribeApp::get_instance2()->m_pArenaProcedure->GetSubType() == ArenaProcedure::_TYPED_ARENAPROCEDURE_PAUSE_)
		return;

	std::list<IObject*>::iterator iter   = m_ObjectList.begin();
	std::list<IObject*>::iterator iter_e = m_ObjectList.end();
	for ( ; iter!=iter_e; )
	{
		std::list<IObject*>::iterator temp = iter;
		++iter;

		if ((*temp)->GetIsValid())
		{
			if (SCENEMANAGER->GetTickPaused())
			{
				(*temp)->RenderTick();
			}
			else
			{
				(*temp)->Tick();
				(*temp)->RenderTick();
			}
		}
		else
		{
			// 从玩家Id列表中清除
			std::map<std::string, IObject*>::iterator iter2 = m_ObjectListById.find((*temp)->GetObjectId());
			if (iter2 != m_ObjectListById.end())
				m_ObjectListById.erase(iter2);

			(*temp)->Destroy();
			delete (*temp);
			m_ObjectList.erase(temp);
		}
	}
}

void ObjectManager::Destroy()
{
	std::list<IObject*>::iterator iter   = m_ObjectList.begin();
	std::list<IObject*>::iterator iter_e = m_ObjectList.end();
	for ( ; iter!=iter_e; ++iter)
	{
		(*iter)->Destroy();
		delete (*iter);
	}
	m_ObjectList.clear();
	LOGGERSYSTEM->LogInfo("Destroy ObjectManager Success\n");
}

std::string ObjectManager::CreateObjectId(int objectType)
{
	static long long counter = 0;
	
	char buffer[128] = "";
	sprintf(buffer, "%d_%lld", objectType, counter);
	counter++;

	return buffer;
}
