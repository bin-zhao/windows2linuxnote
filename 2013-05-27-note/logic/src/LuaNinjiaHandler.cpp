/*
** Lua binding: ninjia
** Generated automatically by tolua++-1.0.92 on 04/24/13 13:16:30.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_ninjia_open (lua_State* tolua_S);

#include "../include/NinjiaTribeApp.h"
#include "../include/EngineSystem.h"
#include "../include/DBSystem.h"
#include "../include/DebugerSystem.h"
#include "../include/EventSystem.h"
#include "../include/EventTyper.h"
#include "../include/GuideSystem.h"
#include "../include/UISystem.h"
#include "../include/InputSystem.h"
#include "../include/NetSystem.h"
#include "../include/ScriptSystem.h"
#include "../include/SoundSystem.h"
#include "../include/TimeSystem.h"
#include "../include/IProcedure.h"
#include "../include/LoginProcedure.h"
#include "../include/LobbyProcedure.h"
#include "../include/SelectServerProcedure.h"
#include "../include/ObjectManager.h"
#include "../include/IWindow.h"
#include "../include/ScriptFunctionWrapper.h"
#include "../include/SysLangDataManager.h"
#include "../include/LoginProcedure.h"
#include "../include/LobbyProcedure.h"
#include "../include/ArenaProcedure.h"
#include "../include/SceneManager.h"
#include "../include/ObjectManager.h"
#include "../include/IObject.h"
#include "../include/LocalPlayerDataManager.h"
#include "../include/IProcedure.h"
#include "../include/LogoProcedure.h"
#include "../include/LoginProcedure.h"
#include "../include/LobbyProcedure.h"
#include "../include/ArenaProcedure.h"
#include "../include/SelectServerProcedure.h"

/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"EngineSystem");
 tolua_usertype(tolua_S,"IObject");
 tolua_usertype(tolua_S,"IWindow");
 tolua_usertype(tolua_S,"DBSystem");
 tolua_usertype(tolua_S,"cocos2d::CCAnimation");
 tolua_usertype(tolua_S,"CCMenuItem");
 tolua_usertype(tolua_S,"SysLangDataManager");
 tolua_usertype(tolua_S,"GuideSystem");
 tolua_usertype(tolua_S,"LocalPlayerDataManager");
 tolua_usertype(tolua_S,"ObjectManager");
 tolua_usertype(tolua_S,"CCNode");
 tolua_usertype(tolua_S,"CCLabelTTF");
 tolua_usertype(tolua_S,"cocos2d::CCNode");
 tolua_usertype(tolua_S,"ArenaProcedure");
 tolua_usertype(tolua_S,"EventSystem");
 tolua_usertype(tolua_S,"LogoProcedure");
 tolua_usertype(tolua_S,"LobbyProcedure");
 tolua_usertype(tolua_S,"LoginProcedure");
 tolua_usertype(tolua_S,"SoundSystem");
 tolua_usertype(tolua_S,"CCSprite");
 tolua_usertype(tolua_S,"SelectServerProcedure");
 tolua_usertype(tolua_S,"NinjiaTribeApp");
 tolua_usertype(tolua_S,"SceneManager");
 tolua_usertype(tolua_S,"UISystem");
}

/* method: GetSysLangById of class  SysLangDataManager */
#ifndef TOLUA_DISABLE_tolua_ninjia_SysLangDataManager_GetSysLangById00
static int tolua_ninjia_SysLangDataManager_GetSysLangById00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"SysLangDataManager",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  SysLangDataManager* self = (SysLangDataManager*)  tolua_tousertype(tolua_S,1,0);
  int langId = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetSysLangById'", NULL);
#endif
  {
   std::string tolua_ret = (std::string)  self->GetSysLangById(langId);
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetSysLangById'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetSysLangById of class  SysLangDataManager */
#ifndef TOLUA_DISABLE_tolua_ninjia_SysLangDataManager_GetSysLangById01
static int tolua_ninjia_SysLangDataManager_GetSysLangById01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"SysLangDataManager",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  SysLangDataManager* self = (SysLangDataManager*)  tolua_tousertype(tolua_S,1,0);
  int langId = ((int)  tolua_tonumber(tolua_S,2,0));
  int langType = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetSysLangById'", NULL);
#endif
  {
   std::string tolua_ret = (std::string)  self->GetSysLangById(langId,langType);
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
tolua_lerror:
 return tolua_ninjia_SysLangDataManager_GetSysLangById00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetWindowType of class  IWindow */
#ifndef TOLUA_DISABLE_tolua_ninjia_IWindow_GetWindowType00
static int tolua_ninjia_IWindow_GetWindowType00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"IWindow",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  IWindow* self = (IWindow*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetWindowType'", NULL);
#endif
  {
   int tolua_ret = (int)  self->GetWindowType();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetWindowType'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsLoad of class  IWindow */
#ifndef TOLUA_DISABLE_tolua_ninjia_IWindow_IsLoad00
static int tolua_ninjia_IWindow_IsLoad00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"IWindow",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  IWindow* self = (IWindow*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsLoad'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->IsLoad();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsLoad'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetRootNode of class  IWindow */
#ifndef TOLUA_DISABLE_tolua_ninjia_IWindow_GetRootNode00
static int tolua_ninjia_IWindow_GetRootNode00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"IWindow",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  IWindow* self = (IWindow*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetRootNode'", NULL);
#endif
  {
   cocos2d::CCNode* tolua_ret = (cocos2d::CCNode*)  self->GetRootNode();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"cocos2d::CCNode");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetRootNode'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetWindowDataByPos of class  IWindow */
#ifndef TOLUA_DISABLE_tolua_ninjia_IWindow_SetWindowDataByPos00
static int tolua_ninjia_IWindow_SetWindowDataByPos00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"IWindow",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  IWindow* self = (IWindow*)  tolua_tousertype(tolua_S,1,0);
  std::string str = ((std::string)  tolua_tocppstring(tolua_S,2,0));
  unsigned int pos = ((unsigned int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetWindowDataByPos'", NULL);
#endif
  {
   self->SetWindowDataByPos(str,pos);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetWindowDataByPos'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetWindowDataByPos of class  IWindow */
#ifndef TOLUA_DISABLE_tolua_ninjia_IWindow_GetWindowDataByPos00
static int tolua_ninjia_IWindow_GetWindowDataByPos00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"IWindow",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  IWindow* self = (IWindow*)  tolua_tousertype(tolua_S,1,0);
  unsigned int pos = ((unsigned int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetWindowDataByPos'", NULL);
#endif
  {
   std::string tolua_ret = (std::string)  self->GetWindowDataByPos(pos);
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetWindowDataByPos'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetTickListenser of class  IWindow */
#ifndef TOLUA_DISABLE_tolua_ninjia_IWindow_SetTickListenser00
static int tolua_ninjia_IWindow_SetTickListenser00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"IWindow",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  IWindow* self = (IWindow*)  tolua_tousertype(tolua_S,1,0);
  bool bListenser = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetTickListenser'", NULL);
#endif
  {
   self->SetTickListenser(bListenser);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetTickListenser'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Show of class  IWindow */
#ifndef TOLUA_DISABLE_tolua_ninjia_IWindow_Show00
static int tolua_ninjia_IWindow_Show00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"IWindow",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  IWindow* self = (IWindow*)  tolua_tousertype(tolua_S,1,0);
  bool bShow = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Show'", NULL);
#endif
  {
   self->Show(bShow);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Show'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsVisible of class  IWindow */
#ifndef TOLUA_DISABLE_tolua_ninjia_IWindow_IsVisible00
static int tolua_ninjia_IWindow_IsVisible00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"IWindow",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  IWindow* self = (IWindow*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsVisible'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->IsVisible();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsVisible'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsFadeout of class  IWindow */
#ifndef TOLUA_DISABLE_tolua_ninjia_IWindow_IsFadeout00
static int tolua_ninjia_IWindow_IsFadeout00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"IWindow",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  IWindow* self = (IWindow*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsFadeout'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->IsFadeout();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsFadeout'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetXPosition of class  IWindow */
#ifndef TOLUA_DISABLE_tolua_ninjia_IWindow_SetXPosition00
static int tolua_ninjia_IWindow_SetXPosition00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"IWindow",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  IWindow* self = (IWindow*)  tolua_tousertype(tolua_S,1,0);
  float xPos = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetXPosition'", NULL);
#endif
  {
   self->SetXPosition(xPos);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetXPosition'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetXPosition of class  IWindow */
#ifndef TOLUA_DISABLE_tolua_ninjia_IWindow_GetXPosition00
static int tolua_ninjia_IWindow_GetXPosition00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"IWindow",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  IWindow* self = (IWindow*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetXPosition'", NULL);
#endif
  {
   float tolua_ret = (float)  self->GetXPosition();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetXPosition'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetYPosition of class  IWindow */
#ifndef TOLUA_DISABLE_tolua_ninjia_IWindow_SetYPosition00
static int tolua_ninjia_IWindow_SetYPosition00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"IWindow",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  IWindow* self = (IWindow*)  tolua_tousertype(tolua_S,1,0);
  float yPos = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetYPosition'", NULL);
#endif
  {
   self->SetYPosition(yPos);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetYPosition'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetYPosition of class  IWindow */
#ifndef TOLUA_DISABLE_tolua_ninjia_IWindow_GetYPosition00
static int tolua_ninjia_IWindow_GetYPosition00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"IWindow",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  IWindow* self = (IWindow*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetYPosition'", NULL);
#endif
  {
   float tolua_ret = (float)  self->GetYPosition();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetYPosition'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetXScale of class  IWindow */
#ifndef TOLUA_DISABLE_tolua_ninjia_IWindow_SetXScale00
static int tolua_ninjia_IWindow_SetXScale00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"IWindow",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  IWindow* self = (IWindow*)  tolua_tousertype(tolua_S,1,0);
  float xScale = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetXScale'", NULL);
#endif
  {
   self->SetXScale(xScale);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetXScale'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetYScale of class  IWindow */
#ifndef TOLUA_DISABLE_tolua_ninjia_IWindow_SetYScale00
static int tolua_ninjia_IWindow_SetYScale00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"IWindow",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  IWindow* self = (IWindow*)  tolua_tousertype(tolua_S,1,0);
  float yScale = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetYScale'", NULL);
#endif
  {
   self->SetYScale(yScale);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetYScale'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: RegisterEvent of class  IWindow */
#ifndef TOLUA_DISABLE_tolua_ninjia_IWindow_RegisterEvent00
static int tolua_ninjia_IWindow_RegisterEvent00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"IWindow",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,3,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  IWindow* self = (IWindow*)  tolua_tousertype(tolua_S,1,0);
  int iEventType = ((int)  tolua_tonumber(tolua_S,2,0));
  bool bNotifyOnlyWhenVisible = ((bool)  tolua_toboolean(tolua_S,3,false));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'RegisterEvent'", NULL);
#endif
  {
   self->RegisterEvent(iEventType,bNotifyOnlyWhenVisible);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'RegisterEvent'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: PushEvent of class  IWindow */
#ifndef TOLUA_DISABLE_tolua_ninjia_IWindow_PushEvent00
static int tolua_ninjia_IWindow_PushEvent00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"IWindow",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  IWindow* self = (IWindow*)  tolua_tousertype(tolua_S,1,0);
  int iEventType = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'PushEvent'", NULL);
#endif
  {
   self->PushEvent(iEventType);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'PushEvent'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: PushEvent of class  IWindow */
#ifndef TOLUA_DISABLE_tolua_ninjia_IWindow_PushEvent01
static int tolua_ninjia_IWindow_PushEvent01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"IWindow",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  IWindow* self = (IWindow*)  tolua_tousertype(tolua_S,1,0);
  int iEventType = ((int)  tolua_tonumber(tolua_S,2,0));
  char* pArgs = ((char*)  tolua_tostring(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'PushEvent'", NULL);
#endif
  {
   self->PushEvent(iEventType,pArgs);
  }
 }
 return 0;
tolua_lerror:
 return tolua_ninjia_IWindow_PushEvent00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: PlayOpenSound of class  IWindow */
#ifndef TOLUA_DISABLE_tolua_ninjia_IWindow_PlayOpenSound00
static int tolua_ninjia_IWindow_PlayOpenSound00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"IWindow",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  IWindow* self = (IWindow*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'PlayOpenSound'", NULL);
#endif
  {
   self->PlayOpenSound();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'PlayOpenSound'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: RegisterTimerFunction of class  IWindow */
#ifndef TOLUA_DISABLE_tolua_ninjia_IWindow_RegisterTimerFunction00
static int tolua_ninjia_IWindow_RegisterTimerFunction00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"IWindow",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  IWindow* self = (IWindow*)  tolua_tousertype(tolua_S,1,0);
  float time = ((float)  tolua_tonumber(tolua_S,2,0));
  std::string functionName = ((std::string)  tolua_tocppstring(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'RegisterTimerFunction'", NULL);
#endif
  {
   self->RegisterTimerFunction(time,functionName);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'RegisterTimerFunction'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Fadeout of class  IWindow */
#ifndef TOLUA_DISABLE_tolua_ninjia_IWindow_Fadeout00
static int tolua_ninjia_IWindow_Fadeout00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"IWindow",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  IWindow* self = (IWindow*)  tolua_tousertype(tolua_S,1,0);
  float time = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Fadeout'", NULL);
#endif
  {
   self->Fadeout(time);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Fadeout'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Init of class  IWindow */
#ifndef TOLUA_DISABLE_tolua_ninjia_IWindow_Init00
static int tolua_ninjia_IWindow_Init00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"IWindow",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  IWindow* self = (IWindow*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Init'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->Init();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Init'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Load of class  IWindow */
#ifndef TOLUA_DISABLE_tolua_ninjia_IWindow_Load00
static int tolua_ninjia_IWindow_Load00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"IWindow",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  IWindow* self = (IWindow*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Load'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->Load();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Load'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Tick of class  IWindow */
#ifndef TOLUA_DISABLE_tolua_ninjia_IWindow_Tick00
static int tolua_ninjia_IWindow_Tick00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"IWindow",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  IWindow* self = (IWindow*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Tick'", NULL);
#endif
  {
   self->Tick();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Tick'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Destroy of class  IWindow */
#ifndef TOLUA_DISABLE_tolua_ninjia_IWindow_Destroy00
static int tolua_ninjia_IWindow_Destroy00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"IWindow",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  IWindow* self = (IWindow*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Destroy'", NULL);
#endif
  {
   self->Destroy();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Destroy'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: Lua_GetNinjiaTribeApp */
#ifndef TOLUA_DISABLE_tolua_ninjia_Lua_GetNinjiaTribeApp00
static int tolua_ninjia_Lua_GetNinjiaTribeApp00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   NinjiaTribeApp* tolua_ret = (NinjiaTribeApp*)  Lua_GetNinjiaTribeApp();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"NinjiaTribeApp");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Lua_GetNinjiaTribeApp'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: Lua_GetEngineSystem */
#ifndef TOLUA_DISABLE_tolua_ninjia_Lua_GetEngineSystem00
static int tolua_ninjia_Lua_GetEngineSystem00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   EngineSystem* tolua_ret = (EngineSystem*)  Lua_GetEngineSystem();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"EngineSystem");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Lua_GetEngineSystem'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: Lua_GetDBSystem */
#ifndef TOLUA_DISABLE_tolua_ninjia_Lua_GetDBSystem00
static int tolua_ninjia_Lua_GetDBSystem00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   DBSystem* tolua_ret = (DBSystem*)  Lua_GetDBSystem();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"DBSystem");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Lua_GetDBSystem'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: Lua_GetEventSystem */
#ifndef TOLUA_DISABLE_tolua_ninjia_Lua_GetEventSystem00
static int tolua_ninjia_Lua_GetEventSystem00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   EventSystem* tolua_ret = (EventSystem*)  Lua_GetEventSystem();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"EventSystem");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Lua_GetEventSystem'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: Lua_GetGuideSystem */
#ifndef TOLUA_DISABLE_tolua_ninjia_Lua_GetGuideSystem00
static int tolua_ninjia_Lua_GetGuideSystem00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   GuideSystem* tolua_ret = (GuideSystem*)  Lua_GetGuideSystem();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"GuideSystem");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Lua_GetGuideSystem'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: Lua_GetUISystem */
#ifndef TOLUA_DISABLE_tolua_ninjia_Lua_GetUISystem00
static int tolua_ninjia_Lua_GetUISystem00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   UISystem* tolua_ret = (UISystem*)  Lua_GetUISystem();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"UISystem");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Lua_GetUISystem'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: Lua_GetSoundSystem */
#ifndef TOLUA_DISABLE_tolua_ninjia_Lua_GetSoundSystem00
static int tolua_ninjia_Lua_GetSoundSystem00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   SoundSystem* tolua_ret = (SoundSystem*)  Lua_GetSoundSystem();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"SoundSystem");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Lua_GetSoundSystem'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: Lua_GetObjectManager */
#ifndef TOLUA_DISABLE_tolua_ninjia_Lua_GetObjectManager00
static int tolua_ninjia_Lua_GetObjectManager00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   ObjectManager* tolua_ret = (ObjectManager*)  Lua_GetObjectManager();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"ObjectManager");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Lua_GetObjectManager'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: Lua_GetSceneManager */
#ifndef TOLUA_DISABLE_tolua_ninjia_Lua_GetSceneManager00
static int tolua_ninjia_Lua_GetSceneManager00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   SceneManager* tolua_ret = (SceneManager*)  Lua_GetSceneManager();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"SceneManager");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Lua_GetSceneManager'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: Lua_GetWindow */
#ifndef TOLUA_DISABLE_tolua_ninjia_Lua_GetWindow00
static int tolua_ninjia_Lua_GetWindow00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isnumber(tolua_S,1,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  int iWindowType = ((int)  tolua_tonumber(tolua_S,1,0));
  {
   IWindow* tolua_ret = (IWindow*)  Lua_GetWindow(iWindowType);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"IWindow");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Lua_GetWindow'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: Lua_GetSysLangTextById */
#ifndef TOLUA_DISABLE_tolua_ninjia_Lua_GetSysLangTextById00
static int tolua_ninjia_Lua_GetSysLangTextById00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isnumber(tolua_S,1,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  int langId = ((int)  tolua_tonumber(tolua_S,1,0));
  {
   const char* tolua_ret = (const char*)  Lua_GetSysLangTextById(langId);
   tolua_pushstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Lua_GetSysLangTextById'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: Lua_GetLocalPlayerDataManager */
#ifndef TOLUA_DISABLE_tolua_ninjia_Lua_GetLocalPlayerDataManager00
static int tolua_ninjia_Lua_GetLocalPlayerDataManager00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   LocalPlayerDataManager* tolua_ret = (LocalPlayerDataManager*)  Lua_GetLocalPlayerDataManager();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"LocalPlayerDataManager");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Lua_GetLocalPlayerDataManager'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: Lua_GetCCNodeByName */
#ifndef TOLUA_DISABLE_tolua_ninjia_Lua_GetCCNodeByName00
static int tolua_ninjia_Lua_GetCCNodeByName00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isstring(tolua_S,1,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  char* pName = ((char*)  tolua_tostring(tolua_S,1,0));
  {
   CCNode* tolua_ret = (CCNode*)  Lua_GetCCNodeByName(pName);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"CCNode");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Lua_GetCCNodeByName'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: Lua_GetCCSpriteByName */
#ifndef TOLUA_DISABLE_tolua_ninjia_Lua_GetCCSpriteByName00
static int tolua_ninjia_Lua_GetCCSpriteByName00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isstring(tolua_S,1,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  char* pName = ((char*)  tolua_tostring(tolua_S,1,0));
  {
   CCSprite* tolua_ret = (CCSprite*)  Lua_GetCCSpriteByName(pName);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"CCSprite");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Lua_GetCCSpriteByName'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: Lua_GetCCLabelTTFByName */
#ifndef TOLUA_DISABLE_tolua_ninjia_Lua_GetCCLabelTTFByName00
static int tolua_ninjia_Lua_GetCCLabelTTFByName00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isstring(tolua_S,1,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  char* pName = ((char*)  tolua_tostring(tolua_S,1,0));
  {
   CCLabelTTF* tolua_ret = (CCLabelTTF*)  Lua_GetCCLabelTTFByName(pName);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"CCLabelTTF");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Lua_GetCCLabelTTFByName'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: Lua_GetCCMenuItemByName */
#ifndef TOLUA_DISABLE_tolua_ninjia_Lua_GetCCMenuItemByName00
static int tolua_ninjia_Lua_GetCCMenuItemByName00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isstring(tolua_S,1,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  char* pName = ((char*)  tolua_tostring(tolua_S,1,0));
  {
   CCMenuItem* tolua_ret = (CCMenuItem*)  Lua_GetCCMenuItemByName(pName);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"CCMenuItem");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Lua_GetCCMenuItemByName'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: Lua_SetCCLabelTTFText */
#ifndef TOLUA_DISABLE_tolua_ninjia_Lua_SetCCLabelTTFText00
static int tolua_ninjia_Lua_SetCCLabelTTFText00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isstring(tolua_S,1,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  char* pLabelName = ((char*)  tolua_tostring(tolua_S,1,0));
  int sysLangId = ((int)  tolua_tonumber(tolua_S,2,0));
  {
   Lua_SetCCLabelTTFText(pLabelName,sysLangId);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Lua_SetCCLabelTTFText'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m_pLogoProcedure of class  NinjiaTribeApp */
#ifndef TOLUA_DISABLE_tolua_get_NinjiaTribeApp_m_pLogoProcedure_ptr
static int tolua_get_NinjiaTribeApp_m_pLogoProcedure_ptr(lua_State* tolua_S)
{
  NinjiaTribeApp* self = (NinjiaTribeApp*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_pLogoProcedure'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)self->m_pLogoProcedure,"LogoProcedure");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m_pLogoProcedure of class  NinjiaTribeApp */
#ifndef TOLUA_DISABLE_tolua_set_NinjiaTribeApp_m_pLogoProcedure_ptr
static int tolua_set_NinjiaTribeApp_m_pLogoProcedure_ptr(lua_State* tolua_S)
{
  NinjiaTribeApp* self = (NinjiaTribeApp*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_pLogoProcedure'",NULL);
  if (!tolua_isusertype(tolua_S,2,"LogoProcedure",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m_pLogoProcedure = ((LogoProcedure*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m_pSelServerProcedure of class  NinjiaTribeApp */
#ifndef TOLUA_DISABLE_tolua_get_NinjiaTribeApp_m_pSelServerProcedure_ptr
static int tolua_get_NinjiaTribeApp_m_pSelServerProcedure_ptr(lua_State* tolua_S)
{
  NinjiaTribeApp* self = (NinjiaTribeApp*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_pSelServerProcedure'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)self->m_pSelServerProcedure,"SelectServerProcedure");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m_pSelServerProcedure of class  NinjiaTribeApp */
#ifndef TOLUA_DISABLE_tolua_set_NinjiaTribeApp_m_pSelServerProcedure_ptr
static int tolua_set_NinjiaTribeApp_m_pSelServerProcedure_ptr(lua_State* tolua_S)
{
  NinjiaTribeApp* self = (NinjiaTribeApp*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_pSelServerProcedure'",NULL);
  if (!tolua_isusertype(tolua_S,2,"SelectServerProcedure",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m_pSelServerProcedure = ((SelectServerProcedure*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m_pLoginProcedure of class  NinjiaTribeApp */
#ifndef TOLUA_DISABLE_tolua_get_NinjiaTribeApp_m_pLoginProcedure_ptr
static int tolua_get_NinjiaTribeApp_m_pLoginProcedure_ptr(lua_State* tolua_S)
{
  NinjiaTribeApp* self = (NinjiaTribeApp*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_pLoginProcedure'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)self->m_pLoginProcedure,"LoginProcedure");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m_pLoginProcedure of class  NinjiaTribeApp */
#ifndef TOLUA_DISABLE_tolua_set_NinjiaTribeApp_m_pLoginProcedure_ptr
static int tolua_set_NinjiaTribeApp_m_pLoginProcedure_ptr(lua_State* tolua_S)
{
  NinjiaTribeApp* self = (NinjiaTribeApp*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_pLoginProcedure'",NULL);
  if (!tolua_isusertype(tolua_S,2,"LoginProcedure",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m_pLoginProcedure = ((LoginProcedure*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m_pLobbyProcedure of class  NinjiaTribeApp */
#ifndef TOLUA_DISABLE_tolua_get_NinjiaTribeApp_m_pLobbyProcedure_ptr
static int tolua_get_NinjiaTribeApp_m_pLobbyProcedure_ptr(lua_State* tolua_S)
{
  NinjiaTribeApp* self = (NinjiaTribeApp*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_pLobbyProcedure'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)self->m_pLobbyProcedure,"LobbyProcedure");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m_pLobbyProcedure of class  NinjiaTribeApp */
#ifndef TOLUA_DISABLE_tolua_set_NinjiaTribeApp_m_pLobbyProcedure_ptr
static int tolua_set_NinjiaTribeApp_m_pLobbyProcedure_ptr(lua_State* tolua_S)
{
  NinjiaTribeApp* self = (NinjiaTribeApp*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_pLobbyProcedure'",NULL);
  if (!tolua_isusertype(tolua_S,2,"LobbyProcedure",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m_pLobbyProcedure = ((LobbyProcedure*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m_pArenaProcedure of class  NinjiaTribeApp */
#ifndef TOLUA_DISABLE_tolua_get_NinjiaTribeApp_m_pArenaProcedure_ptr
static int tolua_get_NinjiaTribeApp_m_pArenaProcedure_ptr(lua_State* tolua_S)
{
  NinjiaTribeApp* self = (NinjiaTribeApp*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_pArenaProcedure'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)self->m_pArenaProcedure,"ArenaProcedure");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m_pArenaProcedure of class  NinjiaTribeApp */
#ifndef TOLUA_DISABLE_tolua_set_NinjiaTribeApp_m_pArenaProcedure_ptr
static int tolua_set_NinjiaTribeApp_m_pArenaProcedure_ptr(lua_State* tolua_S)
{
  NinjiaTribeApp* self = (NinjiaTribeApp*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_pArenaProcedure'",NULL);
  if (!tolua_isusertype(tolua_S,2,"ArenaProcedure",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m_pArenaProcedure = ((ArenaProcedure*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetVersion of class  NinjiaTribeApp */
#ifndef TOLUA_DISABLE_tolua_ninjia_NinjiaTribeApp_GetVersion00
static int tolua_ninjia_NinjiaTribeApp_GetVersion00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"NinjiaTribeApp",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  NinjiaTribeApp* self = (NinjiaTribeApp*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetVersion'", NULL);
#endif
  {
   std::string tolua_ret = (std::string)  self->GetVersion();
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetVersion'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetActive of class  NinjiaTribeApp */
#ifndef TOLUA_DISABLE_tolua_ninjia_NinjiaTribeApp_SetActive00
static int tolua_ninjia_NinjiaTribeApp_SetActive00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"NinjiaTribeApp",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  NinjiaTribeApp* self = (NinjiaTribeApp*)  tolua_tousertype(tolua_S,1,0);
  bool bActive = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetActive'", NULL);
#endif
  {
   self->SetActive(bActive);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetActive'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsActive of class  NinjiaTribeApp */
#ifndef TOLUA_DISABLE_tolua_ninjia_NinjiaTribeApp_IsActive00
static int tolua_ninjia_NinjiaTribeApp_IsActive00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"NinjiaTribeApp",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  NinjiaTribeApp* self = (NinjiaTribeApp*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsActive'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->IsActive();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsActive'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetRun of class  NinjiaTribeApp */
#ifndef TOLUA_DISABLE_tolua_ninjia_NinjiaTribeApp_SetRun00
static int tolua_ninjia_NinjiaTribeApp_SetRun00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"NinjiaTribeApp",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  NinjiaTribeApp* self = (NinjiaTribeApp*)  tolua_tousertype(tolua_S,1,0);
  bool bRun = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetRun'", NULL);
#endif
  {
   self->SetRun(bRun);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetRun'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetFPS of class  NinjiaTribeApp */
#ifndef TOLUA_DISABLE_tolua_ninjia_NinjiaTribeApp_GetFPS00
static int tolua_ninjia_NinjiaTribeApp_GetFPS00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"NinjiaTribeApp",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  NinjiaTribeApp* self = (NinjiaTribeApp*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetFPS'", NULL);
#endif
  {
   int tolua_ret = (int)  self->GetFPS();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetFPS'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetAppChannel of class  NinjiaTribeApp */
#ifndef TOLUA_DISABLE_tolua_ninjia_NinjiaTribeApp_GetAppChannel00
static int tolua_ninjia_NinjiaTribeApp_GetAppChannel00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"NinjiaTribeApp",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  NinjiaTribeApp* self = (NinjiaTribeApp*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetAppChannel'", NULL);
#endif
  {
   int tolua_ret = (int)  self->GetAppChannel();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetAppChannel'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetAppWidth of class  NinjiaTribeApp */
#ifndef TOLUA_DISABLE_tolua_ninjia_NinjiaTribeApp_GetAppWidth00
static int tolua_ninjia_NinjiaTribeApp_GetAppWidth00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"NinjiaTribeApp",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  NinjiaTribeApp* self = (NinjiaTribeApp*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetAppWidth'", NULL);
#endif
  {
   int tolua_ret = (int)  self->GetAppWidth();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetAppWidth'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetAppHeight of class  NinjiaTribeApp */
#ifndef TOLUA_DISABLE_tolua_ninjia_NinjiaTribeApp_GetAppHeight00
static int tolua_ninjia_NinjiaTribeApp_GetAppHeight00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"NinjiaTribeApp",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  NinjiaTribeApp* self = (NinjiaTribeApp*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetAppHeight'", NULL);
#endif
  {
   int tolua_ret = (int)  self->GetAppHeight();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetAppHeight'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: MuteBackgroundMusic of class  SoundSystem */
#ifndef TOLUA_DISABLE_tolua_ninjia_SoundSystem_MuteBackgroundMusic00
static int tolua_ninjia_SoundSystem_MuteBackgroundMusic00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"SoundSystem",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  SoundSystem* self = (SoundSystem*)  tolua_tousertype(tolua_S,1,0);
  bool bMute = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'MuteBackgroundMusic'", NULL);
#endif
  {
   self->MuteBackgroundMusic(bMute);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'MuteBackgroundMusic'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: MuteEffectSound of class  SoundSystem */
#ifndef TOLUA_DISABLE_tolua_ninjia_SoundSystem_MuteEffectSound00
static int tolua_ninjia_SoundSystem_MuteEffectSound00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"SoundSystem",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  SoundSystem* self = (SoundSystem*)  tolua_tousertype(tolua_S,1,0);
  bool bMute = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'MuteEffectSound'", NULL);
#endif
  {
   self->MuteEffectSound(bMute);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'MuteEffectSound'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsBackgroundMusicMute of class  SoundSystem */
#ifndef TOLUA_DISABLE_tolua_ninjia_SoundSystem_IsBackgroundMusicMute00
static int tolua_ninjia_SoundSystem_IsBackgroundMusicMute00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"SoundSystem",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  SoundSystem* self = (SoundSystem*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsBackgroundMusicMute'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->IsBackgroundMusicMute();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsBackgroundMusicMute'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsEffectSoundMute of class  SoundSystem */
#ifndef TOLUA_DISABLE_tolua_ninjia_SoundSystem_IsEffectSoundMute00
static int tolua_ninjia_SoundSystem_IsEffectSoundMute00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"SoundSystem",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  SoundSystem* self = (SoundSystem*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsEffectSoundMute'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->IsEffectSoundMute();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsEffectSoundMute'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: PlayEffect of class  SoundSystem */
#ifndef TOLUA_DISABLE_tolua_ninjia_SoundSystem_PlayEffect00
static int tolua_ninjia_SoundSystem_PlayEffect00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"SoundSystem",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  SoundSystem* self = (SoundSystem*)  tolua_tousertype(tolua_S,1,0);
  int effectType = ((int)  tolua_tonumber(tolua_S,2,0));
  std::string soundName = ((std::string)  tolua_tocppstring(tolua_S,3,0));
  bool bLoop = ((bool)  tolua_toboolean(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'PlayEffect'", NULL);
#endif
  {
   self->PlayEffect(effectType,soundName,bLoop);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'PlayEffect'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: StopEffect of class  SoundSystem */
#ifndef TOLUA_DISABLE_tolua_ninjia_SoundSystem_StopEffect00
static int tolua_ninjia_SoundSystem_StopEffect00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"SoundSystem",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  SoundSystem* self = (SoundSystem*)  tolua_tousertype(tolua_S,1,0);
  int effectType = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'StopEffect'", NULL);
#endif
  {
   self->StopEffect(effectType);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'StopEffect'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: PlayBackgroundMusic of class  SoundSystem */
#ifndef TOLUA_DISABLE_tolua_ninjia_SoundSystem_PlayBackgroundMusic00
static int tolua_ninjia_SoundSystem_PlayBackgroundMusic00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"SoundSystem",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  SoundSystem* self = (SoundSystem*)  tolua_tousertype(tolua_S,1,0);
  std::string soundName = ((std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'PlayBackgroundMusic'", NULL);
#endif
  {
   self->PlayBackgroundMusic(soundName);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'PlayBackgroundMusic'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: StopBackgroundMusic of class  SoundSystem */
#ifndef TOLUA_DISABLE_tolua_ninjia_SoundSystem_StopBackgroundMusic00
static int tolua_ninjia_SoundSystem_StopBackgroundMusic00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"SoundSystem",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  SoundSystem* self = (SoundSystem*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'StopBackgroundMusic'", NULL);
#endif
  {
   self->StopBackgroundMusic();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'StopBackgroundMusic'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ChangeToLobbyProcedure of class  LoginProcedure */
#ifndef TOLUA_DISABLE_tolua_ninjia_LoginProcedure_ChangeToLobbyProcedure00
static int tolua_ninjia_LoginProcedure_ChangeToLobbyProcedure00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LoginProcedure",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LoginProcedure* self = (LoginProcedure*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ChangeToLobbyProcedure'", NULL);
#endif
  {
   self->ChangeToLobbyProcedure();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ChangeToLobbyProcedure'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ChangeToSelectServerProcedure of class  LoginProcedure */
#ifndef TOLUA_DISABLE_tolua_ninjia_LoginProcedure_ChangeToSelectServerProcedure00
static int tolua_ninjia_LoginProcedure_ChangeToSelectServerProcedure00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LoginProcedure",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LoginProcedure* self = (LoginProcedure*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ChangeToSelectServerProcedure'", NULL);
#endif
  {
   self->ChangeToSelectServerProcedure();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ChangeToSelectServerProcedure'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ChangeToArenaProcedure of class  LobbyProcedure */
#ifndef TOLUA_DISABLE_tolua_ninjia_LobbyProcedure_ChangeToArenaProcedure00
static int tolua_ninjia_LobbyProcedure_ChangeToArenaProcedure00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LobbyProcedure",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LobbyProcedure* self = (LobbyProcedure*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ChangeToArenaProcedure'", NULL);
#endif
  {
   self->ChangeToArenaProcedure();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ChangeToArenaProcedure'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ChangeToLoginProcedure of class  LobbyProcedure */
#ifndef TOLUA_DISABLE_tolua_ninjia_LobbyProcedure_ChangeToLoginProcedure00
static int tolua_ninjia_LobbyProcedure_ChangeToLoginProcedure00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LobbyProcedure",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LobbyProcedure* self = (LobbyProcedure*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ChangeToLoginProcedure'", NULL);
#endif
  {
   self->ChangeToLoginProcedure();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ChangeToLoginProcedure'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetSubType of class  ArenaProcedure */
#ifndef TOLUA_DISABLE_tolua_ninjia_ArenaProcedure_GetSubType00
static int tolua_ninjia_ArenaProcedure_GetSubType00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ArenaProcedure",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ArenaProcedure* self = (ArenaProcedure*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetSubType'", NULL);
#endif
  {
   int tolua_ret = (int)  self->GetSubType();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetSubType'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ChangeToLobbyProcedure of class  ArenaProcedure */
#ifndef TOLUA_DISABLE_tolua_ninjia_ArenaProcedure_ChangeToLobbyProcedure00
static int tolua_ninjia_ArenaProcedure_ChangeToLobbyProcedure00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ArenaProcedure",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ArenaProcedure* self = (ArenaProcedure*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ChangeToLobbyProcedure'", NULL);
#endif
  {
   self->ChangeToLobbyProcedure();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ChangeToLobbyProcedure'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: StartCoolDown of class  ArenaProcedure */
#ifndef TOLUA_DISABLE_tolua_ninjia_ArenaProcedure_StartCoolDown00
static int tolua_ninjia_ArenaProcedure_StartCoolDown00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ArenaProcedure",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ArenaProcedure* self = (ArenaProcedure*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'StartCoolDown'", NULL);
#endif
  {
   self->StartCoolDown();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'StartCoolDown'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: StartGame of class  ArenaProcedure */
#ifndef TOLUA_DISABLE_tolua_ninjia_ArenaProcedure_StartGame00
static int tolua_ninjia_ArenaProcedure_StartGame00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ArenaProcedure",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ArenaProcedure* self = (ArenaProcedure*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'StartGame'", NULL);
#endif
  {
   self->StartGame();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'StartGame'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: EndGame of class  ArenaProcedure */
#ifndef TOLUA_DISABLE_tolua_ninjia_ArenaProcedure_EndGame00
static int tolua_ninjia_ArenaProcedure_EndGame00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ArenaProcedure",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ArenaProcedure* self = (ArenaProcedure*)  tolua_tousertype(tolua_S,1,0);
  bool bWin = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'EndGame'", NULL);
#endif
  {
   self->EndGame(bWin);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'EndGame'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: PauseGame of class  ArenaProcedure */
#ifndef TOLUA_DISABLE_tolua_ninjia_ArenaProcedure_PauseGame00
static int tolua_ninjia_ArenaProcedure_PauseGame00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ArenaProcedure",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ArenaProcedure* self = (ArenaProcedure*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'PauseGame'", NULL);
#endif
  {
   self->PauseGame();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'PauseGame'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ResumeGame of class  ArenaProcedure */
#ifndef TOLUA_DISABLE_tolua_ninjia_ArenaProcedure_ResumeGame00
static int tolua_ninjia_ArenaProcedure_ResumeGame00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ArenaProcedure",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ArenaProcedure* self = (ArenaProcedure*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ResumeGame'", NULL);
#endif
  {
   self->ResumeGame();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ResumeGame'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ReplayGame of class  ArenaProcedure */
#ifndef TOLUA_DISABLE_tolua_ninjia_ArenaProcedure_ReplayGame00
static int tolua_ninjia_ArenaProcedure_ReplayGame00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ArenaProcedure",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ArenaProcedure* self = (ArenaProcedure*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ReplayGame'", NULL);
#endif
  {
   self->ReplayGame();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ReplayGame'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetTickSpeedFactor of class  SceneManager */
#ifndef TOLUA_DISABLE_tolua_ninjia_SceneManager_SetTickSpeedFactor00
static int tolua_ninjia_SceneManager_SetTickSpeedFactor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"SceneManager",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  SceneManager* self = (SceneManager*)  tolua_tousertype(tolua_S,1,0);
  float speed = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetTickSpeedFactor'", NULL);
#endif
  {
   self->SetTickSpeedFactor(speed);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetTickSpeedFactor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetTickSpeedFactor of class  SceneManager */
#ifndef TOLUA_DISABLE_tolua_ninjia_SceneManager_GetTickSpeedFactor00
static int tolua_ninjia_SceneManager_GetTickSpeedFactor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"SceneManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  SceneManager* self = (SceneManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetTickSpeedFactor'", NULL);
#endif
  {
   float tolua_ret = (float)  self->GetTickSpeedFactor();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetTickSpeedFactor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetTickPaused of class  SceneManager */
#ifndef TOLUA_DISABLE_tolua_ninjia_SceneManager_SetTickPaused00
static int tolua_ninjia_SceneManager_SetTickPaused00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"SceneManager",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  SceneManager* self = (SceneManager*)  tolua_tousertype(tolua_S,1,0);
  bool bPause = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetTickPaused'", NULL);
#endif
  {
   self->SetTickPaused(bPause);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetTickPaused'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetTickPaused of class  SceneManager */
#ifndef TOLUA_DISABLE_tolua_ninjia_SceneManager_GetTickPaused00
static int tolua_ninjia_SceneManager_GetTickPaused00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"SceneManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  SceneManager* self = (SceneManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetTickPaused'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->GetTickPaused();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetTickPaused'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetSceneRootLayer of class  SceneManager */
#ifndef TOLUA_DISABLE_tolua_ninjia_SceneManager_GetSceneRootLayer00
static int tolua_ninjia_SceneManager_GetSceneRootLayer00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"SceneManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  SceneManager* self = (SceneManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetSceneRootLayer'", NULL);
#endif
  {
   cocos2d::CCNode* tolua_ret = (cocos2d::CCNode*)  self->GetSceneRootLayer();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"cocos2d::CCNode");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetSceneRootLayer'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetSceneBackgroundLayer of class  SceneManager */
#ifndef TOLUA_DISABLE_tolua_ninjia_SceneManager_GetSceneBackgroundLayer00
static int tolua_ninjia_SceneManager_GetSceneBackgroundLayer00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"SceneManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  SceneManager* self = (SceneManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetSceneBackgroundLayer'", NULL);
#endif
  {
   cocos2d::CCNode* tolua_ret = (cocos2d::CCNode*)  self->GetSceneBackgroundLayer();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"cocos2d::CCNode");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetSceneBackgroundLayer'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetSceneEffectLayer of class  SceneManager */
#ifndef TOLUA_DISABLE_tolua_ninjia_SceneManager_GetSceneEffectLayer00
static int tolua_ninjia_SceneManager_GetSceneEffectLayer00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"SceneManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  SceneManager* self = (SceneManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetSceneEffectLayer'", NULL);
#endif
  {
   cocos2d::CCNode* tolua_ret = (cocos2d::CCNode*)  self->GetSceneEffectLayer();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"cocos2d::CCNode");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetSceneEffectLayer'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetSceneInverseLayer of class  SceneManager */
#ifndef TOLUA_DISABLE_tolua_ninjia_SceneManager_GetSceneInverseLayer00
static int tolua_ninjia_SceneManager_GetSceneInverseLayer00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"SceneManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  SceneManager* self = (SceneManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetSceneInverseLayer'", NULL);
#endif
  {
   cocos2d::CCNode* tolua_ret = (cocos2d::CCNode*)  self->GetSceneInverseLayer();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"cocos2d::CCNode");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetSceneInverseLayer'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: InverseScene of class  SceneManager */
#ifndef TOLUA_DISABLE_tolua_ninjia_SceneManager_InverseScene00
static int tolua_ninjia_SceneManager_InverseScene00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"SceneManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  SceneManager* self = (SceneManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'InverseScene'", NULL);
#endif
  {
   self->InverseScene();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'InverseScene'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ShakeScene of class  SceneManager */
#ifndef TOLUA_DISABLE_tolua_ninjia_SceneManager_ShakeScene00
static int tolua_ninjia_SceneManager_ShakeScene00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"SceneManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  SceneManager* self = (SceneManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ShakeScene'", NULL);
#endif
  {
   self->ShakeScene();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ShakeScene'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetAnimtionByName of class  SceneManager */
#ifndef TOLUA_DISABLE_tolua_ninjia_SceneManager_GetAnimtionByName00
static int tolua_ninjia_SceneManager_GetAnimtionByName00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"SceneManager",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  SceneManager* self = (SceneManager*)  tolua_tousertype(tolua_S,1,0);
  std::string name = ((std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetAnimtionByName'", NULL);
#endif
  {
   cocos2d::CCAnimation* tolua_ret = (cocos2d::CCAnimation*)  self->GetAnimtionByName(name);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"cocos2d::CCAnimation");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetAnimtionByName'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetObjectNumber of class  ObjectManager */
#ifndef TOLUA_DISABLE_tolua_ninjia_ObjectManager_GetObjectNumber00
static int tolua_ninjia_ObjectManager_GetObjectNumber00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ObjectManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ObjectManager* self = (ObjectManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetObjectNumber'", NULL);
#endif
  {
   unsigned int tolua_ret = (unsigned int)  self->GetObjectNumber();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetObjectNumber'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetObjectByPos of class  ObjectManager */
#ifndef TOLUA_DISABLE_tolua_ninjia_ObjectManager_GetObjectByPos00
static int tolua_ninjia_ObjectManager_GetObjectByPos00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ObjectManager",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ObjectManager* self = (ObjectManager*)  tolua_tousertype(tolua_S,1,0);
  unsigned int pos = ((unsigned int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetObjectByPos'", NULL);
#endif
  {
   IObject* tolua_ret = (IObject*)  self->GetObjectByPos(pos);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"IObject");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetObjectByPos'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetObjectById of class  ObjectManager */
#ifndef TOLUA_DISABLE_tolua_ninjia_ObjectManager_GetObjectById00
static int tolua_ninjia_ObjectManager_GetObjectById00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ObjectManager",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ObjectManager* self = (ObjectManager*)  tolua_tousertype(tolua_S,1,0);
  std::string id = ((std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetObjectById'", NULL);
#endif
  {
   IObject* tolua_ret = (IObject*)  self->GetObjectById(id);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"IObject");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetObjectById'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: InsertObject of class  ObjectManager */
#ifndef TOLUA_DISABLE_tolua_ninjia_ObjectManager_InsertObject00
static int tolua_ninjia_ObjectManager_InsertObject00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ObjectManager",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"IObject",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ObjectManager* self = (ObjectManager*)  tolua_tousertype(tolua_S,1,0);
  IObject* pObject = ((IObject*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'InsertObject'", NULL);
#endif
  {
   self->InsertObject(pObject);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'InsertObject'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: DeleteObject of class  ObjectManager */
#ifndef TOLUA_DISABLE_tolua_ninjia_ObjectManager_DeleteObject00
static int tolua_ninjia_ObjectManager_DeleteObject00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ObjectManager",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"IObject",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ObjectManager* self = (ObjectManager*)  tolua_tousertype(tolua_S,1,0);
  IObject* pObject = ((IObject*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'DeleteObject'", NULL);
#endif
  {
   self->DeleteObject(pObject);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'DeleteObject'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: DeleteAllObject of class  ObjectManager */
#ifndef TOLUA_DISABLE_tolua_ninjia_ObjectManager_DeleteAllObject00
static int tolua_ninjia_ObjectManager_DeleteAllObject00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ObjectManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ObjectManager* self = (ObjectManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'DeleteAllObject'", NULL);
#endif
  {
   self->DeleteAllObject();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'DeleteAllObject'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetObjectId of class  IObject */
#ifndef TOLUA_DISABLE_tolua_ninjia_IObject_SetObjectId00
static int tolua_ninjia_IObject_SetObjectId00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"IObject",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  IObject* self = (IObject*)  tolua_tousertype(tolua_S,1,0);
  std::string objectId = ((std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetObjectId'", NULL);
#endif
  {
   self->SetObjectId(objectId);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetObjectId'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetObjectId of class  IObject */
#ifndef TOLUA_DISABLE_tolua_ninjia_IObject_GetObjectId00
static int tolua_ninjia_IObject_GetObjectId00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"IObject",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  IObject* self = (IObject*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetObjectId'", NULL);
#endif
  {
   std::string tolua_ret = (std::string)  self->GetObjectId();
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetObjectId'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetObjectType of class  IObject */
#ifndef TOLUA_DISABLE_tolua_ninjia_IObject_SetObjectType00
static int tolua_ninjia_IObject_SetObjectType00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"IObject",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  IObject* self = (IObject*)  tolua_tousertype(tolua_S,1,0);
  int objectType = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetObjectType'", NULL);
#endif
  {
   self->SetObjectType(objectType);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetObjectType'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetObjectType of class  IObject */
#ifndef TOLUA_DISABLE_tolua_ninjia_IObject_GetObjectType00
static int tolua_ninjia_IObject_GetObjectType00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"IObject",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  IObject* self = (IObject*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetObjectType'", NULL);
#endif
  {
   int tolua_ret = (int)  self->GetObjectType();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetObjectType'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetObjectSubType of class  IObject */
#ifndef TOLUA_DISABLE_tolua_ninjia_IObject_SetObjectSubType00
static int tolua_ninjia_IObject_SetObjectSubType00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"IObject",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  IObject* self = (IObject*)  tolua_tousertype(tolua_S,1,0);
  int objectSubType = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetObjectSubType'", NULL);
#endif
  {
   self->SetObjectSubType(objectSubType);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetObjectSubType'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetObjectSubType of class  IObject */
#ifndef TOLUA_DISABLE_tolua_ninjia_IObject_GetObjectSubType00
static int tolua_ninjia_IObject_GetObjectSubType00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"IObject",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  IObject* self = (IObject*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetObjectSubType'", NULL);
#endif
  {
   int tolua_ret = (int)  self->GetObjectSubType();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetObjectSubType'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetIsValid of class  IObject */
#ifndef TOLUA_DISABLE_tolua_ninjia_IObject_SetIsValid00
static int tolua_ninjia_IObject_SetIsValid00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"IObject",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  IObject* self = (IObject*)  tolua_tousertype(tolua_S,1,0);
  bool bValid = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetIsValid'", NULL);
#endif
  {
   self->SetIsValid(bValid);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetIsValid'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetIsValid of class  IObject */
#ifndef TOLUA_DISABLE_tolua_ninjia_IObject_GetIsValid00
static int tolua_ninjia_IObject_GetIsValid00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"IObject",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  IObject* self = (IObject*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetIsValid'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->GetIsValid();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetIsValid'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetIsCollision of class  IObject */
#ifndef TOLUA_DISABLE_tolua_ninjia_IObject_SetIsCollision00
static int tolua_ninjia_IObject_SetIsCollision00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"IObject",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  IObject* self = (IObject*)  tolua_tousertype(tolua_S,1,0);
  bool bIsCollision = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetIsCollision'", NULL);
#endif
  {
   self->SetIsCollision(bIsCollision);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetIsCollision'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetIsCollision of class  IObject */
#ifndef TOLUA_DISABLE_tolua_ninjia_IObject_GetIsCollision00
static int tolua_ninjia_IObject_GetIsCollision00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"IObject",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  IObject* self = (IObject*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetIsCollision'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->GetIsCollision();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetIsCollision'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: NeedSaveToDisk of class  LocalPlayerDataManager */
#ifndef TOLUA_DISABLE_tolua_ninjia_LocalPlayerDataManager_NeedSaveToDisk00
static int tolua_ninjia_LocalPlayerDataManager_NeedSaveToDisk00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LocalPlayerDataManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LocalPlayerDataManager* self = (LocalPlayerDataManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'NeedSaveToDisk'", NULL);
#endif
  {
   self->NeedSaveToDisk();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'NeedSaveToDisk'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_ninjia_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  tolua_constant(tolua_S,"_TYPED_EVENT_UNKOWN_",_TYPED_EVENT_UNKOWN_);
  tolua_constant(tolua_S,"_TYPED_EVENT_SNS_LOGIN_SUCCESS_",_TYPED_EVENT_SNS_LOGIN_SUCCESS_);
  tolua_constant(tolua_S,"_TYPED_EVENT_SNS_LOGIN_FAILED_",_TYPED_EVENT_SNS_LOGIN_FAILED_);
  tolua_constant(tolua_S,"_TYPED_EVENT_SNS_SHARE_SUCCESS_",_TYPED_EVENT_SNS_SHARE_SUCCESS_);
  tolua_constant(tolua_S,"_TYPED_EVENT_SNS_SHARE_FAILED_",_TYPED_EVENT_SNS_SHARE_FAILED_);
  tolua_constant(tolua_S,"_TYPED_EVENT_SNS_SHARETOLOGIN_SUCCESS_",_TYPED_EVENT_SNS_SHARETOLOGIN_SUCCESS_);
  tolua_constant(tolua_S,"_TYPED_EVENT_SNS_ADDFRIEND_SUCCESS_",_TYPED_EVENT_SNS_ADDFRIEND_SUCCESS_);
  tolua_constant(tolua_S,"_TYPED_EVENT_SNS_ADDFRIEND_FAILED_",_TYPED_EVENT_SNS_ADDFRIEND_FAILED_);
  tolua_constant(tolua_S,"_TYPED_EVENT_GAMECENTER_AUTHENTICATION_",_TYPED_EVENT_GAMECENTER_AUTHENTICATION_);
  tolua_constant(tolua_S,"_TYPED_EVENT_LOCAL_IAP_SUCCESS_",_TYPED_EVENT_LOCAL_IAP_SUCCESS_);
  tolua_constant(tolua_S,"_TYPED_EVENT_LOCAL_IAP_FAILED_",_TYPED_EVENT_LOCAL_IAP_FAILED_);
  tolua_constant(tolua_S,"_TYPED_EVENT_UPDATE_LOGIC_DEBUGER_",_TYPED_EVENT_UPDATE_LOGIC_DEBUGER_);
  tolua_constant(tolua_S,"_TYPED_EVENT_UPDATE_NET_DEBUGER_",_TYPED_EVENT_UPDATE_NET_DEBUGER_);
  tolua_constant(tolua_S,"_TYPED_EVENT_UPDATE_RENDER_DEBUGER_",_TYPED_EVENT_UPDATE_RENDER_DEBUGER_);
  tolua_constant(tolua_S,"_TYPED_EVENT_SHOW_TOPWINDOW_",_TYPED_EVENT_SHOW_TOPWINDOW_);
  tolua_constant(tolua_S,"_TYPED_EVENT_HIDE_TOPWINDOW_",_TYPED_EVENT_HIDE_TOPWINDOW_);
  tolua_constant(tolua_S,"_TYPED_EVENT_UPDATE_TOPWINDOW_",_TYPED_EVENT_UPDATE_TOPWINDOW_);
  tolua_constant(tolua_S,"_TYPED_EVENT_FADEOUT_TOPWINDOW_",_TYPED_EVENT_FADEOUT_TOPWINDOW_);
  tolua_constant(tolua_S,"_TYPED_EVENT_POP_SYS_TEXT_",_TYPED_EVENT_POP_SYS_TEXT_);
  tolua_constant(tolua_S,"_TYPED_EVENT_SHOW_ALERTWINDOW_",_TYPED_EVENT_SHOW_ALERTWINDOW_);
  tolua_constant(tolua_S,"_TYPED_EVENT_HIDE_ALERTWINDOW_",_TYPED_EVENT_HIDE_ALERTWINDOW_);
  tolua_constant(tolua_S,"_TYPED_EVENT_UPDATE_ALERTWINDOW_",_TYPED_EVENT_UPDATE_ALERTWINDOW_);
  tolua_constant(tolua_S,"_TYPED_EVENT_FADEOUT_ALERTWINDOW_",_TYPED_EVENT_FADEOUT_ALERTWINDOW_);
  tolua_constant(tolua_S,"_TYPED_EVENT_SHOW_MESSAGEBOXWINDOW_",_TYPED_EVENT_SHOW_MESSAGEBOXWINDOW_);
  tolua_constant(tolua_S,"_TYPED_EVENT_HIDE_MESSAGEBOXWINDOW_",_TYPED_EVENT_HIDE_MESSAGEBOXWINDOW_);
  tolua_constant(tolua_S,"_TYPED_EVENT_UPDATE_MESSAGEBOXWINDOW_",_TYPED_EVENT_UPDATE_MESSAGEBOXWINDOW_);
  tolua_constant(tolua_S,"_TYPED_EVENT_FADEOUT_MESSAGEBOXWINDOW_",_TYPED_EVENT_FADEOUT_MESSAGEBOXWINDOW_);
  tolua_constant(tolua_S,"_TYPED_EVENT_SHOW_LOGOWINDOW_",_TYPED_EVENT_SHOW_LOGOWINDOW_);
  tolua_constant(tolua_S,"_TYPED_EVENT_HIDE_LOGOWINDOW_",_TYPED_EVENT_HIDE_LOGOWINDOW_);
  tolua_constant(tolua_S,"_TYPED_EVENT_UPDATE_LOGOWINDOW_",_TYPED_EVENT_UPDATE_LOGOWINDOW_);
  tolua_constant(tolua_S,"_TYPED_EVENT_FADEOUT_LOGOWINDOW_",_TYPED_EVENT_FADEOUT_LOGOWINDOW_);
  tolua_constant(tolua_S,"_TYPED_EVENT_SHOW_SELECTSERVERWINDOW_",_TYPED_EVENT_SHOW_SELECTSERVERWINDOW_);
  tolua_constant(tolua_S,"_TYPED_EVENT_HIDE_SELECTSERVERWINDOW_",_TYPED_EVENT_HIDE_SELECTSERVERWINDOW_);
  tolua_constant(tolua_S,"_TYPED_EVENT_UPDATE_SELECTSERVERWINDOW_",_TYPED_EVENT_UPDATE_SELECTSERVERWINDOW_);
  tolua_constant(tolua_S,"_TYPED_EVENT_FADEOUT_SELECTSERVERWINDOW_",_TYPED_EVENT_FADEOUT_SELECTSERVERWINDOW_);
  tolua_constant(tolua_S,"_TYPED_EVENT_SHOW_LOADINGWINDOW_",_TYPED_EVENT_SHOW_LOADINGWINDOW_);
  tolua_constant(tolua_S,"_TYPED_EVENT_HIDE_LOADINGWINDOW_",_TYPED_EVENT_HIDE_LOADINGWINDOW_);
  tolua_constant(tolua_S,"_TYPED_EVENT_UPDATE_LOADINGWINDOW_BAR_",_TYPED_EVENT_UPDATE_LOADINGWINDOW_BAR_);
  tolua_constant(tolua_S,"_TYPED_EVENT_UPDATE_LOADINGWINDOW_TEXT_",_TYPED_EVENT_UPDATE_LOADINGWINDOW_TEXT_);
  tolua_constant(tolua_S,"_TYPED_EVENT_UPDATE_LOADINGWINDOW_",_TYPED_EVENT_UPDATE_LOADINGWINDOW_);
  tolua_constant(tolua_S,"_TYPED_EVENT_FADEOUT_LOADINGWINDOW_",_TYPED_EVENT_FADEOUT_LOADINGWINDOW_);
  tolua_constant(tolua_S,"_TYPED_EVENT_SHOW_LOGINWINDOW_",_TYPED_EVENT_SHOW_LOGINWINDOW_);
  tolua_constant(tolua_S,"_TYPED_EVENT_HIDE_LOGINWINDOW_",_TYPED_EVENT_HIDE_LOGINWINDOW_);
  tolua_constant(tolua_S,"_TYPED_EVENT_UPDATE_LOGINWINDOW_",_TYPED_EVENT_UPDATE_LOGINWINDOW_);
  tolua_constant(tolua_S,"_TYPED_EVENT_FADEOUT_LOGINWINDOW_",_TYPED_EVENT_FADEOUT_LOGINWINDOW_);
  tolua_constant(tolua_S,"_TYPED_EVENT_SHOW_LOBBYWINDOW_",_TYPED_EVENT_SHOW_LOBBYWINDOW_);
  tolua_constant(tolua_S,"_TYPED_EVENT_HIDE_LOBBYWINDOW_",_TYPED_EVENT_HIDE_LOBBYWINDOW_);
  tolua_constant(tolua_S,"_TYPED_EVENT_UPDATE_LOBBYWINDOW_",_TYPED_EVENT_UPDATE_LOBBYWINDOW_);
  tolua_constant(tolua_S,"_TYPED_EVENT_FADEOUT_LOBBYWINDOW_",_TYPED_EVENT_FADEOUT_LOBBYWINDOW_);
  tolua_constant(tolua_S,"_TYPED_EVENT_SHOW_PAUSEWINDOW_",_TYPED_EVENT_SHOW_PAUSEWINDOW_);
  tolua_constant(tolua_S,"_TYPED_EVENT_HIDE_PAUSEWINDOW_",_TYPED_EVENT_HIDE_PAUSEWINDOW_);
  tolua_constant(tolua_S,"_TYPED_EVENT_UPDATE_PAUSEWINDOW_",_TYPED_EVENT_UPDATE_PAUSEWINDOW_);
  tolua_constant(tolua_S,"_TYPED_EVENT_FADEOUT_PAUSEWINDOW_",_TYPED_EVENT_FADEOUT_PAUSEWINDOW_);
  tolua_constant(tolua_S,"_TYPED_EVENT_SHOW_ABOUTWINDOW_",_TYPED_EVENT_SHOW_ABOUTWINDOW_);
  tolua_constant(tolua_S,"_TYPED_EVENT_HIDE_ABOUTWINDOW_",_TYPED_EVENT_HIDE_ABOUTWINDOW_);
  tolua_constant(tolua_S,"_TYPED_EVENT_UPDATE_ABOUTWINDOW_",_TYPED_EVENT_UPDATE_ABOUTWINDOW_);
  tolua_constant(tolua_S,"_TYPED_EVENT_FADEOUT_ABOUTWINDOW_",_TYPED_EVENT_FADEOUT_ABOUTWINDOW_);
  tolua_constant(tolua_S,"_TYPED_EVENT_SHOW_ARENAWINDOW_",_TYPED_EVENT_SHOW_ARENAWINDOW_);
  tolua_constant(tolua_S,"_TYPED_EVENT_HIDE_ARENAWINDOW_",_TYPED_EVENT_HIDE_ARENAWINDOW_);
  tolua_constant(tolua_S,"_TYPED_EVENT_UPDATE_ARENAWINDOW_",_TYPED_EVENT_UPDATE_ARENAWINDOW_);
  tolua_constant(tolua_S,"_TYPED_EVENT_FADEOUT_ARENAWINDOW_",_TYPED_EVENT_FADEOUT_ARENAWINDOW_);
  tolua_constant(tolua_S,"_TYPED_EVENT_SHOW_ARENARESULTWINDOW_",_TYPED_EVENT_SHOW_ARENARESULTWINDOW_);
  tolua_constant(tolua_S,"_TYPED_EVENT_HIDE_ARENARESULTWINDOW_",_TYPED_EVENT_HIDE_ARENARESULTWINDOW_);
  tolua_constant(tolua_S,"_TYPED_EVENT_UPDATE_ARENARESULTWINDOW_",_TYPED_EVENT_UPDATE_ARENARESULTWINDOW_);
  tolua_constant(tolua_S,"_TYPED_EVENT_FADEOUT_ARENARESULTWINDOW_",_TYPED_EVENT_FADEOUT_ARENARESULTWINDOW_);
  tolua_constant(tolua_S,"_TYPED_EVENT_SHOW_SYSTEMSETTINGWINDOW_",_TYPED_EVENT_SHOW_SYSTEMSETTINGWINDOW_);
  tolua_constant(tolua_S,"_TYPED_EVENT_HIDE_SYSTEMSETTINGWINDOW_",_TYPED_EVENT_HIDE_SYSTEMSETTINGWINDOW_);
  tolua_constant(tolua_S,"_TYPED_EVENT_UPDATE_SYSTEMSETTINGWINDOW_",_TYPED_EVENT_UPDATE_SYSTEMSETTINGWINDOW_);
  tolua_constant(tolua_S,"_TYPED_EVENT_FADEOUT_SYSTEMSETTINGWINDOW_",_TYPED_EVENT_FADEOUT_SYSTEMSETTINGWINDOW_);
  tolua_constant(tolua_S,"_TYPED_EVENT_SHOW_GUIDEWINDOW_",_TYPED_EVENT_SHOW_GUIDEWINDOW_);
  tolua_constant(tolua_S,"_TYPED_EVENT_HIDE_GUIDEWINDOW_",_TYPED_EVENT_HIDE_GUIDEWINDOW_);
  tolua_constant(tolua_S,"_TYPED_EVENT_UPDATE_GUIDEWINDOW_",_TYPED_EVENT_UPDATE_GUIDEWINDOW_);
  tolua_constant(tolua_S,"_TYPED_EVENT_FADEOUT_GUIDEWINDOW_",_TYPED_EVENT_FADEOUT_GUIDEWINDOW_);
  tolua_constant(tolua_S,"_TYPED_EVENT_NEXT_GUIDESTEP_",_TYPED_EVENT_NEXT_GUIDESTEP_);
  tolua_constant(tolua_S,"_TYPED_EVENT_SHOW_SCOREWINDOW_",_TYPED_EVENT_SHOW_SCOREWINDOW_);
  tolua_constant(tolua_S,"_TYPED_EVENT_HIDE_SCOREWINDOW_",_TYPED_EVENT_HIDE_SCOREWINDOW_);
  tolua_constant(tolua_S,"_TYPED_EVENT_UPDATE_SCOREWINDOW_",_TYPED_EVENT_UPDATE_SCOREWINDOW_);
  tolua_constant(tolua_S,"_TYPED_EVENT_FADEOUT_SCOREWINDOW_",_TYPED_EVENT_FADEOUT_SCOREWINDOW_);
  tolua_constant(tolua_S,"_TYPED_EVENT_SHOW_SHOPWINDOW_",_TYPED_EVENT_SHOW_SHOPWINDOW_);
  tolua_constant(tolua_S,"_TYPED_EVENT_HIDE_SHOPWINDOW_",_TYPED_EVENT_HIDE_SHOPWINDOW_);
  tolua_constant(tolua_S,"_TYPED_EVENT_UPDATE_SHOPWINDOW_",_TYPED_EVENT_UPDATE_SHOPWINDOW_);
  tolua_constant(tolua_S,"_TYPED_EVENT_FADEOUT_SHOPWINDOW_",_TYPED_EVENT_FADEOUT_SHOPWINDOW_);
  tolua_constant(tolua_S,"_TYPED_EVENT_SHOW_SETTINGWINDOW_",_TYPED_EVENT_SHOW_SETTINGWINDOW_);
  tolua_constant(tolua_S,"_TYPED_EVENT_HIDE_SETTINGWINDOW_",_TYPED_EVENT_HIDE_SETTINGWINDOW_);
  tolua_constant(tolua_S,"_TYPED_EVENT_UPDATE_SETTINGWINDOW_",_TYPED_EVENT_UPDATE_SETTINGWINDOW_);
  tolua_constant(tolua_S,"_TYPED_EVENT_FADEOUT_SETTINGWINDOW_",_TYPED_EVENT_FADEOUT_SETTINGWINDOW_);
  tolua_constant(tolua_S,"_TYPED_EVENT_SHOW_LOCALIAPWINDOW_",_TYPED_EVENT_SHOW_LOCALIAPWINDOW_);
  tolua_constant(tolua_S,"_TYPED_EVENT_HIDE_LOCALIAPWINDOW_",_TYPED_EVENT_HIDE_LOCALIAPWINDOW_);
  tolua_constant(tolua_S,"_TYPED_EVENT_UPDATE_LOCALIAPWINDOW_",_TYPED_EVENT_UPDATE_LOCALIAPWINDOW_);
  tolua_constant(tolua_S,"_TYPED_EVENT_FADEOUT_LOCALIAPWINDOW_",_TYPED_EVENT_FADEOUT_LOCALIAPWINDOW_);
  tolua_constant(tolua_S,"_TYPED_EVENT_SHOW_REWARDWINDOW_",_TYPED_EVENT_SHOW_REWARDWINDOW_);
  tolua_constant(tolua_S,"_TYPED_EVENT_HIDE_REWARDWINDOW_",_TYPED_EVENT_HIDE_REWARDWINDOW_);
  tolua_constant(tolua_S,"_TYPED_EVENT_UPDATE_REWARDWINDOW_",_TYPED_EVENT_UPDATE_REWARDWINDOW_);
  tolua_constant(tolua_S,"_TYPED_EVENT_FADEOUT_REWARDWINDOW_",_TYPED_EVENT_FADEOUT_REWARDWINDOW_);
  tolua_constant(tolua_S,"_TYPED_EVENT_SHOW_STORYWINDOW_",_TYPED_EVENT_SHOW_STORYWINDOW_);
  tolua_constant(tolua_S,"_TYPED_EVENT_HIDE_STORYWINDOW_",_TYPED_EVENT_HIDE_STORYWINDOW_);
  tolua_constant(tolua_S,"_TYPED_EVENT_UPDATE_STORYWINDOW_",_TYPED_EVENT_UPDATE_STORYWINDOW_);
  tolua_constant(tolua_S,"_TYPED_EVENT_FADEOUT_STORYWINDOW_",_TYPED_EVENT_FADEOUT_STORYWINDOW_);
  tolua_constant(tolua_S,"_TYPED_EVENT_UPDATE_UI_TEXT_",_TYPED_EVENT_UPDATE_UI_TEXT_);
  tolua_constant(tolua_S,"_TYPED_EVENT_ANDROID_SURFACE_CREATED_",_TYPED_EVENT_ANDROID_SURFACE_CREATED_);
  tolua_constant(tolua_S,"_TYPED_EVENT_UPDATE_PLAYER_GOLD_",_TYPED_EVENT_UPDATE_PLAYER_GOLD_);
  tolua_constant(tolua_S,"_TYPED_EVENT_NUMBER_",_TYPED_EVENT_NUMBER_);
  tolua_cclass(tolua_S,"SysLangDataManager","SysLangDataManager","",NULL);
  tolua_beginmodule(tolua_S,"SysLangDataManager");
   tolua_constant(tolua_S,"_TYPED_SYSLANG_CN_",SysLangDataManager::_TYPED_SYSLANG_CN_);
   tolua_constant(tolua_S,"_TYPED_SYSLANG_EN_",SysLangDataManager::_TYPED_SYSLANG_EN_);
   tolua_constant(tolua_S,"_TYPED_SYSLANG_TW_",SysLangDataManager::_TYPED_SYSLANG_TW_);
   tolua_constant(tolua_S,"_TYPED_SYSLANG_UNKOWN_",SysLangDataManager::_TYPED_SYSLANG_UNKOWN_);
   tolua_constant(tolua_S,"_TYPED_SYSLANG_SNS_RENN_LOGIN_SUCCESS_",SysLangDataManager::_TYPED_SYSLANG_SNS_RENN_LOGIN_SUCCESS_);
   tolua_constant(tolua_S,"_TYPED_SYSLANG_SNS_RENN_LOGIN_FAILED_",SysLangDataManager::_TYPED_SYSLANG_SNS_RENN_LOGIN_FAILED_);
   tolua_constant(tolua_S,"_TYPED_SYSLANG_SNS_RENN_SHARE_TEXT_",SysLangDataManager::_TYPED_SYSLANG_SNS_RENN_SHARE_TEXT_);
   tolua_constant(tolua_S,"_TYPED_SYSLANG_SNS_RENN_SHARE_PICTURETEXT_",SysLangDataManager::_TYPED_SYSLANG_SNS_RENN_SHARE_PICTURETEXT_);
   tolua_constant(tolua_S,"_TYPED_SYSLANG_SNS_RENN_SHARE_SUCCESS_",SysLangDataManager::_TYPED_SYSLANG_SNS_RENN_SHARE_SUCCESS_);
   tolua_constant(tolua_S,"_TYPED_SYSLANG_SNS_RENN_SHARE_FAILED_",SysLangDataManager::_TYPED_SYSLANG_SNS_RENN_SHARE_FAILED_);
   tolua_constant(tolua_S,"_TYPED_SYSLANG_SNS_WEIBO_SHARE_TEXT_",SysLangDataManager::_TYPED_SYSLANG_SNS_WEIBO_SHARE_TEXT_);
   tolua_constant(tolua_S,"_TYPED_SYSLANG_SNS_WEIBO_SHARE_PICTURETEXT_",SysLangDataManager::_TYPED_SYSLANG_SNS_WEIBO_SHARE_PICTURETEXT_);
   tolua_constant(tolua_S,"_TYPED_SYSLANG_SNS_WEIBO_LOGIN_SUCCESS_",SysLangDataManager::_TYPED_SYSLANG_SNS_WEIBO_LOGIN_SUCCESS_);
   tolua_constant(tolua_S,"_TYPED_SYSLANG_SNS_WEIBO_LOGIN_FAILED_",SysLangDataManager::_TYPED_SYSLANG_SNS_WEIBO_LOGIN_FAILED_);
   tolua_constant(tolua_S,"_TYPED_SYSLANG_SNS_WEIBO_SHARE_SUCCESS_",SysLangDataManager::_TYPED_SYSLANG_SNS_WEIBO_SHARE_SUCCESS_);
   tolua_constant(tolua_S,"_TYPED_SYSLANG_SNS_WEIBO_SHARE_FAILED_",SysLangDataManager::_TYPED_SYSLANG_SNS_WEIBO_SHARE_FAILED_);
   tolua_constant(tolua_S,"_TYPED_SYSLANG_SNS_QQ_SHARE_TEXT_",SysLangDataManager::_TYPED_SYSLANG_SNS_QQ_SHARE_TEXT_);
   tolua_constant(tolua_S,"_TYPED_SYSLANG_SNS_QQ_SHARE_PICTURETEXT_",SysLangDataManager::_TYPED_SYSLANG_SNS_QQ_SHARE_PICTURETEXT_);
   tolua_constant(tolua_S,"_TYPED_SYSLANG_SNS_QQ_LOGIN_SUCCESS_",SysLangDataManager::_TYPED_SYSLANG_SNS_QQ_LOGIN_SUCCESS_);
   tolua_constant(tolua_S,"_TYPED_SYSLANG_SNS_QQ_LOGIN_FAILED_",SysLangDataManager::_TYPED_SYSLANG_SNS_QQ_LOGIN_FAILED_);
   tolua_constant(tolua_S,"_TYPED_SYSLANG_SNS_QQ_SHARE_SUCCESS_",SysLangDataManager::_TYPED_SYSLANG_SNS_QQ_SHARE_SUCCESS_);
   tolua_constant(tolua_S,"_TYPED_SYSLANG_SNS_QQ_SHARE_FAILED_",SysLangDataManager::_TYPED_SYSLANG_SNS_QQ_SHARE_FAILED_);
   tolua_constant(tolua_S,"_TYPED_SYSLANG_SNS_FACEBOOK_SHARE_TEXT_",SysLangDataManager::_TYPED_SYSLANG_SNS_FACEBOOK_SHARE_TEXT_);
   tolua_constant(tolua_S,"_TYPED_SYSLANG_SNS_FACEBOOK_SHARE_PICTURETEXT_",SysLangDataManager::_TYPED_SYSLANG_SNS_FACEBOOK_SHARE_PICTURETEXT_);
   tolua_constant(tolua_S,"_TYPED_SYSLANG_SNS_FACEBOOK_LOGIN_SUCCESS_",SysLangDataManager::_TYPED_SYSLANG_SNS_FACEBOOK_LOGIN_SUCCESS_);
   tolua_constant(tolua_S,"_TYPED_SYSLANG_SNS_FACEBOOK_LOGIN_FAILED_",SysLangDataManager::_TYPED_SYSLANG_SNS_FACEBOOK_LOGIN_FAILED_);
   tolua_constant(tolua_S,"_TYPED_SYSLANG_SNS_FACEBOOK_SHARE_SUCCESS_",SysLangDataManager::_TYPED_SYSLANG_SNS_FACEBOOK_SHARE_SUCCESS_);
   tolua_constant(tolua_S,"_TYPED_SYSLANG_SNS_FACEBOOK_SHARE_FAILED_",SysLangDataManager::_TYPED_SYSLANG_SNS_FACEBOOK_SHARE_FAILED_);
   tolua_constant(tolua_S,"_TYPED_SYSLANG_SNS_TWITTER_SHARE_TEXT_",SysLangDataManager::_TYPED_SYSLANG_SNS_TWITTER_SHARE_TEXT_);
   tolua_constant(tolua_S,"_TYPED_SYSLANG_SNS_TWITTER_SHARE_PICTURETEXT_",SysLangDataManager::_TYPED_SYSLANG_SNS_TWITTER_SHARE_PICTURETEXT_);
   tolua_constant(tolua_S,"_TYPED_SYSLANG_SNS_TWITTER_LOGIN_SUCCESS_",SysLangDataManager::_TYPED_SYSLANG_SNS_TWITTER_LOGIN_SUCCESS_);
   tolua_constant(tolua_S,"_TYPED_SYSLANG_SNS_TWITTER_LOGIN_FAILED_",SysLangDataManager::_TYPED_SYSLANG_SNS_TWITTER_LOGIN_FAILED_);
   tolua_constant(tolua_S,"_TYPED_SYSLANG_SNS_TWITTER_SHARE_SUCCESS_",SysLangDataManager::_TYPED_SYSLANG_SNS_TWITTER_SHARE_SUCCESS_);
   tolua_constant(tolua_S,"_TYPED_SYSLANG_SNS_TWITTER_SHARE_FAILED_",SysLangDataManager::_TYPED_SYSLANG_SNS_TWITTER_SHARE_FAILED_);
   tolua_constant(tolua_S,"_TYPED_SYSLANG_GAMECENTER_INVALID_",SysLangDataManager::_TYPED_SYSLANG_GAMECENTER_INVALID_);
   tolua_constant(tolua_S,"_TYPED_SYSLANG_GAMECENTER_AUTH_SUCCESS_",SysLangDataManager::_TYPED_SYSLANG_GAMECENTER_AUTH_SUCCESS_);
   tolua_constant(tolua_S,"_TYPED_SYSLANG_GAMECENTER_AUTH_FAILED_",SysLangDataManager::_TYPED_SYSLANG_GAMECENTER_AUTH_FAILED_);
   tolua_constant(tolua_S,"_TYPED_SYSLANG_GAMECENTER_SHOW_LEADERBOARD_SUCCESS_",SysLangDataManager::_TYPED_SYSLANG_GAMECENTER_SHOW_LEADERBOARD_SUCCESS_);
   tolua_constant(tolua_S,"_TYPED_SYSLANG_GAMECENTER_SHOW_LEADERBOARD_FAILED_",SysLangDataManager::_TYPED_SYSLANG_GAMECENTER_SHOW_LEADERBOARD_FAILED_);
   tolua_constant(tolua_S,"_TYPED_SYSLANG_GAMECENTER_SHOW_ACHIEVEMENT_SUCCESS_",SysLangDataManager::_TYPED_SYSLANG_GAMECENTER_SHOW_ACHIEVEMENT_SUCCESS_);
   tolua_constant(tolua_S,"_TYPED_SYSLANG_GAMECENTER_SHOW_ACHIEVEMENT_FAILED_",SysLangDataManager::_TYPED_SYSLANG_GAMECENTER_SHOW_ACHIEVEMENT_FAILED_);
   tolua_constant(tolua_S,"_TYPED_SYSLANG_GAMECENTER_REPORT_SCORE_SUCCESS_",SysLangDataManager::_TYPED_SYSLANG_GAMECENTER_REPORT_SCORE_SUCCESS_);
   tolua_constant(tolua_S,"_TYPED_SYSLANG_GAMECENTER_REPORT_SCORE_FAILED_",SysLangDataManager::_TYPED_SYSLANG_GAMECENTER_REPORT_SCORE_FAILED_);
   tolua_constant(tolua_S,"_TYPED_SYSLANG_GAMECENTER_SUBMIT_ACHIEVEMENT_SUCCESS_",SysLangDataManager::_TYPED_SYSLANG_GAMECENTER_SUBMIT_ACHIEVEMENT_SUCCESS_);
   tolua_constant(tolua_S,"_TYPED_SYSLANG_GAMECENTER_SUBMIT_ACHIEVEMENT_FAILED_",SysLangDataManager::_TYPED_SYSLANG_GAMECENTER_SUBMIT_ACHIEVEMENT_FAILED_);
   tolua_constant(tolua_S,"_TYPED_SYSLANG_OPEN_MOREGAME_FAILED_",SysLangDataManager::_TYPED_SYSLANG_OPEN_MOREGAME_FAILED_);
   tolua_constant(tolua_S,"_TYPED_SYSLANG_ESTIMATE_TITLE_",SysLangDataManager::_TYPED_SYSLANG_ESTIMATE_TITLE_);
   tolua_constant(tolua_S,"_TYPED_SYSLANG_ESTIMATE_OK_",SysLangDataManager::_TYPED_SYSLANG_ESTIMATE_OK_);
   tolua_constant(tolua_S,"_TYPED_SYSLANG_ESTIMATE_NEVER_",SysLangDataManager::_TYPED_SYSLANG_ESTIMATE_NEVER_);
   tolua_constant(tolua_S,"_TYPED_SYSLANG_ESTIMATE_LATER_",SysLangDataManager::_TYPED_SYSLANG_ESTIMATE_LATER_);
   tolua_constant(tolua_S,"_TYPED_SYSLANG_RECEIVE_YOUMI_POINTS_",SysLangDataManager::_TYPED_SYSLANG_RECEIVE_YOUMI_POINTS_);
   tolua_constant(tolua_S,"_TYPED_SYSLANG_RECEIVE_DIANJOY_POINTS_",SysLangDataManager::_TYPED_SYSLANG_RECEIVE_DIANJOY_POINTS_);
   tolua_constant(tolua_S,"_TYPED_SYSLANG_RECEIVE_IMMOB_POINTS_",SysLangDataManager::_TYPED_SYSLANG_RECEIVE_IMMOB_POINTS_);
   tolua_constant(tolua_S,"_TYPED_SYSLANG_RECEIVE_TAPJOY_POINTS_",SysLangDataManager::_TYPED_SYSLANG_RECEIVE_TAPJOY_POINTS_);
   tolua_constant(tolua_S,"_TYPED_SYSLANG_RECEIVE_DOMOB_POINTS_",SysLangDataManager::_TYPED_SYSLANG_RECEIVE_DOMOB_POINTS_);
   tolua_constant(tolua_S,"_TYPED_SYSLANG_RECEIVE_91_POINTS_",SysLangDataManager::_TYPED_SYSLANG_RECEIVE_91_POINTS_);
   tolua_constant(tolua_S,"_TYPED_SYSLANG_NO_NETWORK_",SysLangDataManager::_TYPED_SYSLANG_NO_NETWORK_);
   tolua_constant(tolua_S,"_TYPED_SYSLANG_RESULTWINDOW_PREFIX_DESC_TEXT_",SysLangDataManager::_TYPED_SYSLANG_RESULTWINDOW_PREFIX_DESC_TEXT_);
   tolua_constant(tolua_S,"_TYPED_SYSLANG_RESULTWINDOW_SUFFIX_DESC_TEXT_",SysLangDataManager::_TYPED_SYSLANG_RESULTWINDOW_SUFFIX_DESC_TEXT_);
   tolua_constant(tolua_S,"_TYPED_SYSLANG_RESULTWINDOW_RISK_MODE_",SysLangDataManager::_TYPED_SYSLANG_RESULTWINDOW_RISK_MODE_);
   tolua_constant(tolua_S,"_TYPED_SYSLANG_RESULTWINDOW_BOSS_MODE_",SysLangDataManager::_TYPED_SYSLANG_RESULTWINDOW_BOSS_MODE_);
   tolua_function(tolua_S,"GetSysLangById",tolua_ninjia_SysLangDataManager_GetSysLangById00);
   tolua_function(tolua_S,"GetSysLangById",tolua_ninjia_SysLangDataManager_GetSysLangById01);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"IWindow","IWindow","",NULL);
  tolua_beginmodule(tolua_S,"IWindow");
   tolua_constant(tolua_S,"_TYPED_WINDOW_UNKOWN_",IWindow::_TYPED_WINDOW_UNKOWN_);
   tolua_constant(tolua_S,"_TYPED_WINDOW_LOADING_",IWindow::_TYPED_WINDOW_LOADING_);
   tolua_constant(tolua_S,"_TYPED_WINDOW_TOP_",IWindow::_TYPED_WINDOW_TOP_);
   tolua_constant(tolua_S,"_TYPED_WINDOW_ALERT_",IWindow::_TYPED_WINDOW_ALERT_);
   tolua_constant(tolua_S,"_TYPED_WINDOW_MESSAGEBOX_",IWindow::_TYPED_WINDOW_MESSAGEBOX_);
   tolua_constant(tolua_S,"_TYPED_WINDOW_LOGO_",IWindow::_TYPED_WINDOW_LOGO_);
   tolua_constant(tolua_S,"_TYPED_WINDOW_LOGIN_",IWindow::_TYPED_WINDOW_LOGIN_);
   tolua_constant(tolua_S,"_TYPED_WINDOW_LOBBY_",IWindow::_TYPED_WINDOW_LOBBY_);
   tolua_constant(tolua_S,"_TYPED_WINDOW_ARENA_",IWindow::_TYPED_WINDOW_ARENA_);
   tolua_constant(tolua_S,"_TYPED_WINDOW_ARENARESULT_",IWindow::_TYPED_WINDOW_ARENARESULT_);
   tolua_constant(tolua_S,"_TYPED_WINDOW_PAUSE_",IWindow::_TYPED_WINDOW_PAUSE_);
   tolua_constant(tolua_S,"_TYPED_WINDOW_SYSTEM_SETTING_",IWindow::_TYPED_WINDOW_SYSTEM_SETTING_);
   tolua_constant(tolua_S,"_TYPED_WINDOW_SHOP_",IWindow::_TYPED_WINDOW_SHOP_);
   tolua_function(tolua_S,"GetWindowType",tolua_ninjia_IWindow_GetWindowType00);
   tolua_function(tolua_S,"IsLoad",tolua_ninjia_IWindow_IsLoad00);
   tolua_function(tolua_S,"GetRootNode",tolua_ninjia_IWindow_GetRootNode00);
   tolua_function(tolua_S,"SetWindowDataByPos",tolua_ninjia_IWindow_SetWindowDataByPos00);
   tolua_function(tolua_S,"GetWindowDataByPos",tolua_ninjia_IWindow_GetWindowDataByPos00);
   tolua_function(tolua_S,"SetTickListenser",tolua_ninjia_IWindow_SetTickListenser00);
   tolua_function(tolua_S,"Show",tolua_ninjia_IWindow_Show00);
   tolua_function(tolua_S,"IsVisible",tolua_ninjia_IWindow_IsVisible00);
   tolua_function(tolua_S,"IsFadeout",tolua_ninjia_IWindow_IsFadeout00);
   tolua_function(tolua_S,"SetXPosition",tolua_ninjia_IWindow_SetXPosition00);
   tolua_function(tolua_S,"GetXPosition",tolua_ninjia_IWindow_GetXPosition00);
   tolua_function(tolua_S,"SetYPosition",tolua_ninjia_IWindow_SetYPosition00);
   tolua_function(tolua_S,"GetYPosition",tolua_ninjia_IWindow_GetYPosition00);
   tolua_function(tolua_S,"SetXScale",tolua_ninjia_IWindow_SetXScale00);
   tolua_function(tolua_S,"SetYScale",tolua_ninjia_IWindow_SetYScale00);
   tolua_function(tolua_S,"RegisterEvent",tolua_ninjia_IWindow_RegisterEvent00);
   tolua_function(tolua_S,"PushEvent",tolua_ninjia_IWindow_PushEvent00);
   tolua_function(tolua_S,"PushEvent",tolua_ninjia_IWindow_PushEvent01);
   tolua_function(tolua_S,"PlayOpenSound",tolua_ninjia_IWindow_PlayOpenSound00);
   tolua_function(tolua_S,"RegisterTimerFunction",tolua_ninjia_IWindow_RegisterTimerFunction00);
   tolua_function(tolua_S,"Fadeout",tolua_ninjia_IWindow_Fadeout00);
   tolua_function(tolua_S,"Init",tolua_ninjia_IWindow_Init00);
   tolua_function(tolua_S,"Load",tolua_ninjia_IWindow_Load00);
   tolua_function(tolua_S,"Tick",tolua_ninjia_IWindow_Tick00);
   tolua_function(tolua_S,"Destroy",tolua_ninjia_IWindow_Destroy00);
  tolua_endmodule(tolua_S);
  tolua_function(tolua_S,"Lua_GetNinjiaTribeApp",tolua_ninjia_Lua_GetNinjiaTribeApp00);
  tolua_function(tolua_S,"Lua_GetEngineSystem",tolua_ninjia_Lua_GetEngineSystem00);
  tolua_function(tolua_S,"Lua_GetDBSystem",tolua_ninjia_Lua_GetDBSystem00);
  tolua_function(tolua_S,"Lua_GetEventSystem",tolua_ninjia_Lua_GetEventSystem00);
  tolua_function(tolua_S,"Lua_GetGuideSystem",tolua_ninjia_Lua_GetGuideSystem00);
  tolua_function(tolua_S,"Lua_GetUISystem",tolua_ninjia_Lua_GetUISystem00);
  tolua_function(tolua_S,"Lua_GetSoundSystem",tolua_ninjia_Lua_GetSoundSystem00);
  tolua_function(tolua_S,"Lua_GetObjectManager",tolua_ninjia_Lua_GetObjectManager00);
  tolua_function(tolua_S,"Lua_GetSceneManager",tolua_ninjia_Lua_GetSceneManager00);
  tolua_function(tolua_S,"Lua_GetWindow",tolua_ninjia_Lua_GetWindow00);
  tolua_function(tolua_S,"Lua_GetSysLangTextById",tolua_ninjia_Lua_GetSysLangTextById00);
  tolua_function(tolua_S,"Lua_GetLocalPlayerDataManager",tolua_ninjia_Lua_GetLocalPlayerDataManager00);
  tolua_function(tolua_S,"Lua_GetCCNodeByName",tolua_ninjia_Lua_GetCCNodeByName00);
  tolua_function(tolua_S,"Lua_GetCCSpriteByName",tolua_ninjia_Lua_GetCCSpriteByName00);
  tolua_function(tolua_S,"Lua_GetCCLabelTTFByName",tolua_ninjia_Lua_GetCCLabelTTFByName00);
  tolua_function(tolua_S,"Lua_GetCCMenuItemByName",tolua_ninjia_Lua_GetCCMenuItemByName00);
  tolua_function(tolua_S,"Lua_SetCCLabelTTFText",tolua_ninjia_Lua_SetCCLabelTTFText00);
  tolua_cclass(tolua_S,"NinjiaTribeApp","NinjiaTribeApp","",NULL);
  tolua_beginmodule(tolua_S,"NinjiaTribeApp");
   tolua_constant(tolua_S,"_TYPED_APP_CHANNEL_UNKOWN_",NinjiaTribeApp::_TYPED_APP_CHANNEL_UNKOWN_);
   tolua_constant(tolua_S,"_TYPED_APP_CHANNEL_WIN32_",NinjiaTribeApp::_TYPED_APP_CHANNEL_WIN32_);
   tolua_constant(tolua_S,"_TYPED_APP_CHANNEL_IOS_",NinjiaTribeApp::_TYPED_APP_CHANNEL_IOS_);
   tolua_constant(tolua_S,"_TYPED_APP_CHANNEL_HUAWEI_",NinjiaTribeApp::_TYPED_APP_CHANNEL_HUAWEI_);
   tolua_constant(tolua_S,"_TYPED_APP_CHANNEL_GFAN_",NinjiaTribeApp::_TYPED_APP_CHANNEL_GFAN_);
   tolua_constant(tolua_S,"_TYPED_APP_CHANNEL_XIAOMI_",NinjiaTribeApp::_TYPED_APP_CHANNEL_XIAOMI_);
   tolua_constant(tolua_S,"_TYPED_APP_CHANNEL_91_",NinjiaTribeApp::_TYPED_APP_CHANNEL_91_);
   tolua_variable(tolua_S,"m_pLogoProcedure",tolua_get_NinjiaTribeApp_m_pLogoProcedure_ptr,tolua_set_NinjiaTribeApp_m_pLogoProcedure_ptr);
   tolua_variable(tolua_S,"m_pSelServerProcedure",tolua_get_NinjiaTribeApp_m_pSelServerProcedure_ptr,tolua_set_NinjiaTribeApp_m_pSelServerProcedure_ptr);
   tolua_variable(tolua_S,"m_pLoginProcedure",tolua_get_NinjiaTribeApp_m_pLoginProcedure_ptr,tolua_set_NinjiaTribeApp_m_pLoginProcedure_ptr);
   tolua_variable(tolua_S,"m_pLobbyProcedure",tolua_get_NinjiaTribeApp_m_pLobbyProcedure_ptr,tolua_set_NinjiaTribeApp_m_pLobbyProcedure_ptr);
   tolua_variable(tolua_S,"m_pArenaProcedure",tolua_get_NinjiaTribeApp_m_pArenaProcedure_ptr,tolua_set_NinjiaTribeApp_m_pArenaProcedure_ptr);
   tolua_function(tolua_S,"GetVersion",tolua_ninjia_NinjiaTribeApp_GetVersion00);
   tolua_function(tolua_S,"SetActive",tolua_ninjia_NinjiaTribeApp_SetActive00);
   tolua_function(tolua_S,"IsActive",tolua_ninjia_NinjiaTribeApp_IsActive00);
   tolua_function(tolua_S,"SetRun",tolua_ninjia_NinjiaTribeApp_SetRun00);
   tolua_function(tolua_S,"GetFPS",tolua_ninjia_NinjiaTribeApp_GetFPS00);
   tolua_function(tolua_S,"GetAppChannel",tolua_ninjia_NinjiaTribeApp_GetAppChannel00);
   tolua_function(tolua_S,"GetAppWidth",tolua_ninjia_NinjiaTribeApp_GetAppWidth00);
   tolua_function(tolua_S,"GetAppHeight",tolua_ninjia_NinjiaTribeApp_GetAppHeight00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"SoundSystem","SoundSystem","",NULL);
  tolua_beginmodule(tolua_S,"SoundSystem");
   tolua_constant(tolua_S,"_TYPED_EFFECTSOUND_UNKOWN_",SoundSystem::_TYPED_EFFECTSOUND_UNKOWN_);
   tolua_constant(tolua_S,"_TYPED_EFFECTSOUND_COMMONBUTTON_",SoundSystem::_TYPED_EFFECTSOUND_COMMONBUTTON_);
   tolua_constant(tolua_S,"_TYPED_EFFECTSOUND_ITEM_",SoundSystem::_TYPED_EFFECTSOUND_ITEM_);
   tolua_constant(tolua_S,"_TYPED_EFFECTSOUND_EFFECT_",SoundSystem::_TYPED_EFFECTSOUND_EFFECT_);
   tolua_constant(tolua_S,"_TYPED_EFFECTSOUND_MONSTER_",SoundSystem::_TYPED_EFFECTSOUND_MONSTER_);
   tolua_constant(tolua_S,"_TYPED_EFFECTSOUND_OTHER_",SoundSystem::_TYPED_EFFECTSOUND_OTHER_);
   tolua_constant(tolua_S,"_TYPED_EFFECTSOUND_NUMBER_",SoundSystem::_TYPED_EFFECTSOUND_NUMBER_);
   tolua_function(tolua_S,"MuteBackgroundMusic",tolua_ninjia_SoundSystem_MuteBackgroundMusic00);
   tolua_function(tolua_S,"MuteEffectSound",tolua_ninjia_SoundSystem_MuteEffectSound00);
   tolua_function(tolua_S,"IsBackgroundMusicMute",tolua_ninjia_SoundSystem_IsBackgroundMusicMute00);
   tolua_function(tolua_S,"IsEffectSoundMute",tolua_ninjia_SoundSystem_IsEffectSoundMute00);
   tolua_function(tolua_S,"PlayEffect",tolua_ninjia_SoundSystem_PlayEffect00);
   tolua_function(tolua_S,"StopEffect",tolua_ninjia_SoundSystem_StopEffect00);
   tolua_function(tolua_S,"PlayBackgroundMusic",tolua_ninjia_SoundSystem_PlayBackgroundMusic00);
   tolua_function(tolua_S,"StopBackgroundMusic",tolua_ninjia_SoundSystem_StopBackgroundMusic00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"LoginProcedure","LoginProcedure","",NULL);
  tolua_beginmodule(tolua_S,"LoginProcedure");
   tolua_function(tolua_S,"ChangeToLobbyProcedure",tolua_ninjia_LoginProcedure_ChangeToLobbyProcedure00);
   tolua_function(tolua_S,"ChangeToSelectServerProcedure",tolua_ninjia_LoginProcedure_ChangeToSelectServerProcedure00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"LobbyProcedure","LobbyProcedure","",NULL);
  tolua_beginmodule(tolua_S,"LobbyProcedure");
   tolua_function(tolua_S,"ChangeToArenaProcedure",tolua_ninjia_LobbyProcedure_ChangeToArenaProcedure00);
   tolua_function(tolua_S,"ChangeToLoginProcedure",tolua_ninjia_LobbyProcedure_ChangeToLoginProcedure00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"ArenaProcedure","ArenaProcedure","",NULL);
  tolua_beginmodule(tolua_S,"ArenaProcedure");
   tolua_constant(tolua_S,"_TYPED_ARENAPROCEDURE_UNKOWN_",ArenaProcedure::_TYPED_ARENAPROCEDURE_UNKOWN_);
   tolua_constant(tolua_S,"_TYPED_ARENAPROCEDURE_BEGIN_",ArenaProcedure::_TYPED_ARENAPROCEDURE_BEGIN_);
   tolua_constant(tolua_S,"_TYPED_ARENAPROCEDURE_COOLDOWN_",ArenaProcedure::_TYPED_ARENAPROCEDURE_COOLDOWN_);
   tolua_constant(tolua_S,"_TYPED_ARENAPROCEDURE_GAMING_",ArenaProcedure::_TYPED_ARENAPROCEDURE_GAMING_);
   tolua_constant(tolua_S,"_TYPED_ARENAPROCEDURE_PAUSE_",ArenaProcedure::_TYPED_ARENAPROCEDURE_PAUSE_);
   tolua_constant(tolua_S,"_TYPED_ARENAPROCEDURE_END_",ArenaProcedure::_TYPED_ARENAPROCEDURE_END_);
   tolua_constant(tolua_S,"_TYPED_ARENAPROCEDURE_NUMBER_",ArenaProcedure::_TYPED_ARENAPROCEDURE_NUMBER_);
   tolua_function(tolua_S,"GetSubType",tolua_ninjia_ArenaProcedure_GetSubType00);
   tolua_function(tolua_S,"ChangeToLobbyProcedure",tolua_ninjia_ArenaProcedure_ChangeToLobbyProcedure00);
   tolua_function(tolua_S,"StartCoolDown",tolua_ninjia_ArenaProcedure_StartCoolDown00);
   tolua_function(tolua_S,"StartGame",tolua_ninjia_ArenaProcedure_StartGame00);
   tolua_function(tolua_S,"EndGame",tolua_ninjia_ArenaProcedure_EndGame00);
   tolua_function(tolua_S,"PauseGame",tolua_ninjia_ArenaProcedure_PauseGame00);
   tolua_function(tolua_S,"ResumeGame",tolua_ninjia_ArenaProcedure_ResumeGame00);
   tolua_function(tolua_S,"ReplayGame",tolua_ninjia_ArenaProcedure_ReplayGame00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"SceneManager","SceneManager","",NULL);
  tolua_beginmodule(tolua_S,"SceneManager");
   tolua_function(tolua_S,"SetTickSpeedFactor",tolua_ninjia_SceneManager_SetTickSpeedFactor00);
   tolua_function(tolua_S,"GetTickSpeedFactor",tolua_ninjia_SceneManager_GetTickSpeedFactor00);
   tolua_function(tolua_S,"SetTickPaused",tolua_ninjia_SceneManager_SetTickPaused00);
   tolua_function(tolua_S,"GetTickPaused",tolua_ninjia_SceneManager_GetTickPaused00);
   tolua_function(tolua_S,"GetSceneRootLayer",tolua_ninjia_SceneManager_GetSceneRootLayer00);
   tolua_function(tolua_S,"GetSceneBackgroundLayer",tolua_ninjia_SceneManager_GetSceneBackgroundLayer00);
   tolua_function(tolua_S,"GetSceneEffectLayer",tolua_ninjia_SceneManager_GetSceneEffectLayer00);
   tolua_function(tolua_S,"GetSceneInverseLayer",tolua_ninjia_SceneManager_GetSceneInverseLayer00);
   tolua_function(tolua_S,"InverseScene",tolua_ninjia_SceneManager_InverseScene00);
   tolua_function(tolua_S,"ShakeScene",tolua_ninjia_SceneManager_ShakeScene00);
   tolua_function(tolua_S,"GetAnimtionByName",tolua_ninjia_SceneManager_GetAnimtionByName00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"ObjectManager","ObjectManager","",NULL);
  tolua_beginmodule(tolua_S,"ObjectManager");
   tolua_function(tolua_S,"GetObjectNumber",tolua_ninjia_ObjectManager_GetObjectNumber00);
   tolua_function(tolua_S,"GetObjectByPos",tolua_ninjia_ObjectManager_GetObjectByPos00);
   tolua_function(tolua_S,"GetObjectById",tolua_ninjia_ObjectManager_GetObjectById00);
   tolua_function(tolua_S,"InsertObject",tolua_ninjia_ObjectManager_InsertObject00);
   tolua_function(tolua_S,"DeleteObject",tolua_ninjia_ObjectManager_DeleteObject00);
   tolua_function(tolua_S,"DeleteAllObject",tolua_ninjia_ObjectManager_DeleteAllObject00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"IObject","IObject","",NULL);
  tolua_beginmodule(tolua_S,"IObject");
   tolua_constant(tolua_S,"_TYPED_OBJECT_UNKOWN_",IObject::_TYPED_OBJECT_UNKOWN_);
   tolua_constant(tolua_S,"_TYPED_OBJECT_EFFECT_",IObject::_TYPED_OBJECT_EFFECT_);
   tolua_constant(tolua_S,"_TYPED_OBJECT_ITEM_",IObject::_TYPED_OBJECT_ITEM_);
   tolua_function(tolua_S,"SetObjectId",tolua_ninjia_IObject_SetObjectId00);
   tolua_function(tolua_S,"GetObjectId",tolua_ninjia_IObject_GetObjectId00);
   tolua_function(tolua_S,"SetObjectType",tolua_ninjia_IObject_SetObjectType00);
   tolua_function(tolua_S,"GetObjectType",tolua_ninjia_IObject_GetObjectType00);
   tolua_function(tolua_S,"SetObjectSubType",tolua_ninjia_IObject_SetObjectSubType00);
   tolua_function(tolua_S,"GetObjectSubType",tolua_ninjia_IObject_GetObjectSubType00);
   tolua_function(tolua_S,"SetIsValid",tolua_ninjia_IObject_SetIsValid00);
   tolua_function(tolua_S,"GetIsValid",tolua_ninjia_IObject_GetIsValid00);
   tolua_function(tolua_S,"SetIsCollision",tolua_ninjia_IObject_SetIsCollision00);
   tolua_function(tolua_S,"GetIsCollision",tolua_ninjia_IObject_GetIsCollision00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"LocalPlayerDataManager","LocalPlayerDataManager","",NULL);
  tolua_beginmodule(tolua_S,"LocalPlayerDataManager");
   tolua_function(tolua_S,"NeedSaveToDisk",tolua_ninjia_LocalPlayerDataManager_NeedSaveToDisk00);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_ninjia (lua_State* tolua_S) {
 return tolua_ninjia_open(tolua_S);
};
#endif

