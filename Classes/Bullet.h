//
//  Created by 关东升 on 2014-5-18.
//  本书网站：http://www.cocoagame.net
//  智捷iOS课堂在线课堂：http://v.51work6.com
//  智捷iOS课堂新浪微博：http://weibo.com/u/3215753973
//  作者微博：http://weibo.com/516inc
//  QQ：1575716557 邮箱：jylong06@163.com
//  QQ交流群：389037167/327403678
//


#ifndef __BULLET__H__
#define __BULLET__H__

#include "cocos2d.h"
#include "Fighter.h"

class Bullet : public cocos2d::Sprite
{
    CC_SYNTHESIZE(cocos2d::Vec2, velocity, Velocity);
    
public :

    void shootBulletFromFighter(Fighter* fighter);
    
    virtual void update(float dt);
    static Bullet* createWithSpriteFrameName(const char* spriteFrameName);
};

#endif //__BULLET__H__
