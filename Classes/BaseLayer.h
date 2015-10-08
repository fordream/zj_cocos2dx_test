//
//  Created by 关东升 on 2014-5-18.
//  本书网站：http://www.cocoagame.net
//  智捷iOS课堂在线课堂：http://v.51work6.com
//  智捷iOS课堂新浪微博：http://weibo.com/u/3215753973
//  作者微博：http://weibo.com/516inc
//  QQ：1575716557 邮箱：jylong06@163.com
//  QQ交流群：389037167/327403678
//
#ifndef __BSAE_LAYER_H__
#define __BSAE_LAYER_H__

#include "cocos2d.h"

#include "SystemHeader.h"

class BaseLayer : public cocos2d::Layer
{
public:

	// Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
	virtual bool init();  
	
	virtual void onEnterTransitionDidFinish();

	void menuBackCallback(cocos2d::Ref* pSender);

};

#endif // __BSAE_LAYER_H__
