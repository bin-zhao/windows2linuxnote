/*
 * CCAplication.h
 *
 *  Created on: Aug 8, 2011
 *      Author: laschweinski
 */

#ifndef CCAPLICATION_H_
#define CCAPLICATION_H_

#include "platform/CCCommon.h"
#include "platform/CCApplicationProtocol.h"

NS_CC_BEGIN
class CCRect;

class CCApplication : public CCApplicationProtocol
{
public:
	CCApplication();
	virtual ~CCApplication();

	/**
	 @brief	Callback by CCDirector for limit FPS.
	 @interval       The time, which expressed in second in second, between current frame and next.
	 */
	void setAnimationInterval(double interval);

	/**
	 @brief	Run the message loop.
	 */
	int run();

	/**
	 @brief	Get current applicaiton instance.
	 @return Current application instance pointer.
	 */
	static CCApplication* sharedApplication();

	/* override functions */
	virtual ccLanguageType getCurrentLanguage();

	/* set the Resource root path */
	void setResourceRootPath(const char* pszRootResDir);
    
	/* get the Resource root path */
	const char* getResourceRootPath(void);
    
    /**
     @brief Get target platform
     */
    virtual TargetPlatform getTargetPlatform();

	/**
     @brief Get target platform
     */
	virtual std::string getDeviceUUID();

	/**
     @brief Get target platform
     */
	virtual std::string getDeviceIMEI();

	/**
     @brief Get target platform
     */
	virtual std::string getDeviceMacAddr();

	/**
     @brief Get target platform
     */
	virtual void openURL(std::string url);

protected:
    long       m_nAnimationInterval;  //micro second

	static CCApplication * sm_pSharedApplication;
};

NS_CC_END

#endif /* CCAPLICATION_H_ */
