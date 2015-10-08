#ifndef __GAMEOVER_SCENE_H__
#define __GAMEOVER_SCENE_H__

#include "cocos2d.h"
#include "MyUtility.h"

#include "SystemHeader.h"

class GameOverLayer : public cocos2d::Layer
{
	//当前玩家比赛分数
	int score;
public:

	GameOverLayer(int score);

	virtual bool init();
	virtual void onExit();

	static GameOverLayer* createWithScore(int score);
};

#endif // __GAMEOVER_SCENE_H__
