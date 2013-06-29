#ifndef __PLATFOMR_CCPROPERTY_H__
#define __PLATFOMR_CCPROPERTY_H__


#include <string>

namespace  cocos2d
{


class CCNode;
class CCProperty
{
public:
	/*!
	\brief
	Creates a new Property object.

	\param name
	String containing the name of the new Property.

	\param help
	String containing a description of the Property and it's usage.

	\param defaultValue
	String holding the textual representation of the default value for this Property
	*/
	CCProperty(std::string name, std::string help, std::string defaultValue);
	
	virtual ~CCProperty();

	/*!
	\brief
	Return a String that describes the purpose and usage of this Property.

	\return
	String that contains the help text
	*/
	std::string getHelp();

	/*!
	\brief
	Return a the name of this Property

	\return
	String containing the name of the Property
	*/
	std::string getName();

	/*!
	\brief
	Return the current value of the Property as a String

	\param receiver
	Pointer to the target object.

	\return
	String object containing a textual representation of the current value of the Property
	*/
	virtual std::string	get(CCNode* receiver) = 0;

	/*!
	\brief
	Sets the value of the property

	\param receiver
	Pointer to the target object.

	\param value
	A String object that contains a textual representation of the new value to assign to the Property.

	\return
	Nothing.

	\exception InvalidRequestException	Thrown when the Property was unable to interpret the content of \a value.
	*/
	virtual void	set(CCNode* receiver, std::string value) = 0;


	/*!
	\brief
	Returns whether the property is at it's default value.

	\param receiver
	Pointer to the target object.

	\return
	- true if the property has it's default value.
	- false if the property has been modified from it's default value.
	*/
	virtual bool	isDefault(CCNode* receiver);

	/*!
	\brief
	Returns the default value of the Property as a String.

	\param receiver
	Pointer to the target object.

	\return
	String object containing a textual representation of the default value for this property.
	*/
	virtual std::string	getDefault(CCNode* receiver);

protected:
	std::string	m_name;		//!< String that stores the Property name.
	std::string	m_help;		//!< String that stores the Property help text.
	std::string	m_default;	//!< String that stores the Property default value string.
};


}


#endif
