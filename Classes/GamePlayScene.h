
//
//  Created by 关东升 on 2014-5-18.
//  本书网站：http://www.cocoagame.net
//  智捷iOS课堂在线课堂：http://v.51work6.com
//  智捷iOS课堂新浪微博：http://weibo.com/u/3215753973
//  作者微博：http://weibo.com/516inc
//  QQ：1575716557 邮箱：jylong06@163.com
//  QQ交流群：389037167/327403678
//


#ifndef __GAME_PLAY_SCENE_H__
#define __GAME_PLAY_SCENE_H__

#define GameSceneNodeTagStatusBarFighterNode		301
#define GameSceneNodeTagStatusBarLifeNode			302
#define GameSceneNodeTagStatusBarScore				303

#define GameSceneNodeBatchTagBackground				800
#define GameSceneNodeTagFighter						900
#define GameSceneNodeTagExplosionParticleSystem		901
#define GameSceneNodeBatchTagBullet					902
#define GameSceneNodeBatchTagEnemy					903

//发射炮弹的速度
#define GameSceneBulletVelocity						300

#include "cocos2d.h"
#include "Enemy.h"
#include "Fighter.h"
#include "Bullet.h"
#include "GameOverScene.h"

#include "SystemHeader.h"

//定义 击毁敌人获得的分数.
typedef enum
{
	EnemyStone_Score = 5,
	Enemy1_Score = 10,
	Enemy2_Score = 15,
	EnemyPlanet_Score = 20
} EnemyScores;


class GamePlayLayer : public cocos2d::Layer
{
private:

	Fighter* fighter;	
	cocos2d::Menu* menu;
	//分数
	int score;
	//记录0~999分数
	int scorePlaceholder;
	cocos2d::EventListenerTouchOneByOne *touchFighterlistener;
	cocos2d::EventListenerPhysicsContact *contactListener;

public:
	// there's no 'id' in cpp, so we recommend returning the class instance pointer
	static cocos2d::Scene* createScene();

	// Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
	virtual bool init();

	virtual void onExit();
	virtual void onEnter();
	virtual void onEnterTransitionDidFinish();

	//发射炮弹.
	void shootBullet(float dt);
	//初始化背景.
	void initBG();

	//在状态栏中设置和更新玩家的生命值.
	void updateStatusBarFighter();
	//在状态栏中更新得分.
	void updateStatusBarScore();

	void menuPauseCallback(cocos2d::Ref* pSender);
	void menuBackCallback(cocos2d::Ref* pSender);
	void menuResumeCallback(cocos2d::Ref* pSender);

	//处理玩家与敌人的碰撞检测
	void handleFighterCollidingWithEnemy(Enemy* enemy);

	//处理子弹与敌人的碰撞检测
	void handleBulletCollidingWithEnemy(Enemy* enemy);

	// implement the "static create()" method manually
	CREATE_FUNC(GamePlayLayer);
};

#endif // __GAME_PLAY_SCENE_H__
