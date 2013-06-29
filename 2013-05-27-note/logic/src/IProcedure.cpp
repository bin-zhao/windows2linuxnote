#include "../include/IProcedure.h"


IProcedure::IProcedure()
{
	m_Type = _TYPED_UNKOWN_PROCEDURE_;
}

IProcedure::~IProcedure()
{

}

int IProcedure::GetType()
{
	return m_Type;
}
