#ifndef  _UILOADER_LAYOUTXMLHANDLER_H_
#define  _UILOADER_LAYOUTXMLHANDLER_H_


#include <string>
#include <vector>

namespace  uiloader
{


class XMLAttribute;
class UIWindow;
class LayoutXMLHandler
{
public:
	static const std::string GUILayoutElement;          //!< Tag name for GUILayout elements.
	static const std::string WindowElement;				//!< Tag name for Window elements.
	static const std::string PropertyElement;			//!< Tag name for Property elements.
	static const std::string WindowTypeAttribute;		//!< Attribute name that stores the type of Window to create.
	static const std::string WindowNameAttribute;		//!< Attribute name that stores the name of the window to create.
	static const std::string WindowZOrderAttribute;		//!< Attribute name that stores the zorder of the window to create.
	static const std::string PropertyNameAttribute;		//!< Attribute name that stores the name of the property to set.
	static const std::string PropertyValueAttribute;	//!< Attribute name that stores the value to pass to the property.
	static const std::string LayoutParentAttribute;		//!< Attribute name that stores the name of the window to attach the layout to.

public:
	typedef std::pair<UIWindow*,bool> WindowStackEntry;
	typedef std::vector<WindowStackEntry>	WindowStack;
	typedef std::vector<int>	WindowZOrderStack;

private:
	UIWindow*	      m_Root;			//!< Will point to first window created.
	WindowStack	      m_Stack;          //!< Stack used to keep track of what we're doing to which window.
	WindowZOrderStack m_ZOrderStack;
	std::string       m_PropertyName;   //!< Use for long property value 
	std::string       m_PropertyValue;  //!< Use for long property value 
	std::string	      m_NamingPrefix;	//!< Prefix that is to prepend all names of created windows.
	
private:
	static long long  m_NamingPrefixId; //!< Window Name ID

public:
	LayoutXMLHandler();
	~LayoutXMLHandler();

public:
	/*
		得到当前布局文件的根窗口对象
	*/
	UIWindow* GetRoot();

public:
	/*
		开始解析的回调处理
	*/
	void StartElement(std::string element, XMLAttribute* pAttribute);
	/*
		结束解析的回调处理
	*/
	void EndElement(std::string element);
	/*
		数据解析的毁掉处理
	*/
	void Text(std::string text);

public:
	/*
		GUI元素开始解析回调处理
	*/
	void ElementGUILayoutStart(XMLAttribute* pAttribute);
	/*
		Window元素开始解析回调处理
	*/
	void ElementWindowStart(XMLAttribute* pAttribute);
	/*
		Property元素开始解析回调处理
	*/
	void ElementPropertyStart(XMLAttribute* pAttribute);
	/*
		GUI元素结束解析回调处理
	*/
	void ElementGUILayoutEnd();
	/*
		Window元素结束解析回调处理
	*/
	void ElementWindowEnd();
	/*
		Property元素结束解析回调处理
	*/
	void ElementPropertyEnd();
};


}


#endif
