#include "HelloWorldScene.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = HelloWorld::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
	//////////////////////////////
	// 1. super init first
	if ( !Layer::init() )
	{
		return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	///////////////////////////////////////////////
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("texture/loading_texture.plist");

	// add "HelloWorld" splash screen"
	auto bg = TMXTiledMap::create("map/red_bg.tmx");

	// add the sprite as a child to this layer
	this->addChild(bg);

	auto logo =  Sprite::createWithSpriteFrameName("logo.png");
	this->addChild(logo);
	logo->setPosition(Vec2(visibleSize.width/2, visibleSize.height/2));

	auto sprite =  Sprite::createWithSpriteFrameName("loding4.png");
	this->addChild(sprite);
	sprite->setPosition(logo->getPosition() - Vec2(0, logo->getContentSize().height / 2 + 30));

	///////////////动画开始//////////////////////
	Animation* animation = Animation::create();
	for( int i=1; i<= 4; i++)
	{
		__String *frameName = __String::createWithFormat("loding%d.png",i);
		log("frameName = %s",frameName->getCString());
		SpriteFrame *spriteFrame = SpriteFrameCache::getInstance()->getSpriteFrameByName(frameName->getCString());
		animation->addSpriteFrame(spriteFrame);
	}

	animation->setDelayPerUnit(0.5f);           //设置两个帧播放时间
	animation->setRestoreOriginalFrame(true);    //动画执行后还原初始状态

	Animate* action = Animate::create(animation);
	sprite->runAction(RepeatForever::create(action));
	//////////////////动画结束///////////////////

	m_nNumberOfLoaded = 0;

	Director::getInstance()->getTextureCache()->addImageAsync("texture/home_texture.png",
		CC_CALLBACK_1(HelloWorld::loadingTextureCallBack, this));

	Director::getInstance()->getTextureCache()->addImageAsync("texture/setting_texture.png",
		CC_CALLBACK_1(HelloWorld::loadingTextureCallBack, this));

	Director::getInstance()->getTextureCache()->addImageAsync("texture/gameplay_texture.png",
		CC_CALLBACK_1(HelloWorld::loadingTextureCallBack, this));


	_loadingAudioThread = new std::thread(&HelloWorld::loadingAudio,this);

	//////////////////////////////////////

	return true;
}

void HelloWorld::loadingTextureCallBack(Texture2D *texture)
{

	switch (m_nNumberOfLoaded++)
	{
	case 0:
		SpriteFrameCache::getInstance()->addSpriteFramesWithFile("texture/home_texture.plist",texture);
		log("home textrue ok.");
		break;
	case 1:
		SpriteFrameCache::getInstance()->addSpriteFramesWithFile("texture/setting_texture.plist",texture);
		log("setting textrue ok.");
		break;
	case 2:
		SpriteFrameCache::getInstance()->addSpriteFramesWithFile("texture/gameplay_texture.plist",texture);
		log("gamepla textrue ok.");
		this->schedule(schedule_selector(HelloWorld::delayCall),1,1,3);
		//float interval, unsigned int repeat, float delay
		break;
	}

}

void HelloWorld::delayCall(float dt)  
{
	auto sc = HomeMenuLayer::createScene();
	Director::getInstance()->replaceScene(sc);
}

void HelloWorld::loadingAudio()
{
	log("loadAudio");
	//初始化 音乐
	SimpleAudioEngine::getInstance()->preloadBackgroundMusic(bg_music_1);
	SimpleAudioEngine::getInstance()->preloadBackgroundMusic(bg_music_2);
	//初始化音效  TODO  预处理后没有声音，移植的时候需要测试。
	//SimpleAudioEngine::getInstance()->preloadEffect(sound_1);

}


void HelloWorld::onExit()
{
	Layer::onExit();	
	_loadingAudioThread->join();
	CC_SAFE_DELETE(_loadingAudioThread);
	SpriteFrameCache::getInstance()->removeSpriteFramesFromFile("texture/loading_texture.plist");
	Director::getInstance()->getTextureCache()->removeTextureForKey("texture/loading_texture.png");
	this->unschedule(schedule_selector(HelloWorld::delayCall));
}