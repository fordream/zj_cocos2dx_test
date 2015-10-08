#include "HelpScene.h"

USING_NS_CC;

Scene* HelpLayer::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = HelpLayer::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool HelpLayer::init()
{
	//////////////////////////////
	// 1. super init first
	if ( !BaseLayer::init() )
	{
		return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto top = Sprite::createWithSpriteFrameName("help-top.png");
	top->setPosition(Vec2(visibleSize.width/2, visibleSize.height - top->getContentSize().height /2));
	addChild(top);

	//设置“测试”文字.
	auto txtTest = Label::createWithTTF(MyUtility::getUTF8Char("test"), "fonts/hanyi.ttf", 18);
	txtTest->setColor(Color3B(14,83,204));	
	txtTest->setPosition(95, top->getPosition().y - 70);
	txtTest->setAnchorPoint(Vec2(0,0));
	addChild(txtTest, 1);

	//设置测试下文字 51work6
	auto test = Label::createWithTTF("51work6", "fonts/hanyi.ttf", 18);
	test->setAnchorPoint(Vec2(0,0));
	Vec2 p1 = txtTest->convertToWorldSpace(Vec2(0, -20));
	test->setColor(Color3B(198,12,0));	
	test->setPosition(p1);
	addChild(test, 1);

	//设置“音乐”文字.
	auto txtMusic = Label::createWithTTF(MyUtility::getUTF8Char("music"), "fonts/hanyi.ttf", 18);
	txtMusic->setColor(Color3B(14,83,204));	
	Vec2 p2 = test->convertToWorldSpace(Vec2(0, -40));
	txtMusic->setPosition(p2);
	txtMusic->setAnchorPoint(Vec2(0,0));
	addChild(txtMusic, 1);

	//设置 音乐下文字 Mr.Guan
	auto music1 = Label::createWithTTF("Mr.Guan", "fonts/hanyi.ttf", 18);
	music1->setAnchorPoint(Vec2(0,0));
	Vec2 p3 = txtMusic->convertToWorldSpace(Vec2(0, -20));
	music1->setColor(Color3B(198,12,0));	
	music1->setPosition(p3);
	addChild(music1, 1);

	//设置 音乐下文字 YunLong
	auto music2 = Label::createWithTTF("YunLong", "fonts/hanyi.ttf", 18);
	music2->setAnchorPoint(Vec2(0,0));
	Vec2 p4 = music1->convertToWorldSpace(Vec2(0, -20));
	music2->setColor(Color3B(198,12,0));	
	music2->setPosition(p4);
	addChild(music2, 1);

	//设置“音效”文字.
	auto txtSound = Label::createWithTTF(MyUtility::getUTF8Char("sound"), "fonts/hanyi.ttf", 18);
	txtSound->setColor(Color3B(14,83,204));	
	Vec2 p5 = music2->convertToWorldSpace(Vec2(0, -40));
	txtSound->setPosition(p5);
	txtSound->setAnchorPoint(Vec2(0,0));
	addChild(txtSound, 1);

	//设置 音效下文字 Mr.Zhao
	auto sound1 = Label::createWithTTF("Mr.Zhao", "fonts/hanyi.ttf", 18);
	sound1->setAnchorPoint(Vec2(0,0));
	Vec2 p6 = txtSound->convertToWorldSpace(Vec2(0, -20));
	sound1->setColor(Color3B(198,12,0));	
	sound1->setPosition(p6);
	addChild(sound1, 1);

	//设置 音效下文字 YunLong
	auto sound2 = Label::createWithTTF("YunLong", "fonts/hanyi.ttf", 18);
	sound2->setAnchorPoint(Vec2(0,0));
	Vec2 p7 = sound1->convertToWorldSpace(Vec2(0, -20));
	sound2->setColor(Color3B(198,12,0));	
	sound2->setPosition(p7);
	addChild(sound2, 1);

		//设置“信息与服务”文字.
	auto txtInfoService = Label::createWithTTF(MyUtility::getUTF8Char("info_service"), "fonts/hanyi.ttf", 18);
	txtInfoService->setColor(Color3B(14,83,204));	
	Vec2 p8 = sound2->convertToWorldSpace(Vec2(0, -40));
	txtInfoService->setPosition(p8);
	txtInfoService->setAnchorPoint(Vec2(0,0));
	addChild(txtInfoService, 1);

	//设置 信息与服务 下文字 
	auto infoService = Label::createWithTTF("www.51work6.com", "fonts/hanyi.ttf", 18);
	infoService->setAnchorPoint(Vec2(0,0));
	Vec2 p9 = txtInfoService->convertToWorldSpace(Vec2(0, -20));
	infoService->setColor(Color3B(198,12,0));	
	infoService->setPosition(p9);
	addChild(infoService, 1);

	return true;
}
