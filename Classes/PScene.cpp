#include "PScene.h"
#include "GameScene.h"
#include "GameScene2.h"
#include "Definitions.h"
#include "cocos2d.h"
#include <cocostudio/SimpleAudioEngine.h>

USING_NS_CC;
using namespace CocosDenshion;

Scene* PScene::createScene()
{
   auto scene = Scene::create();

   auto layer = PScene::create();

   scene->addChild(layer);

   return PScene::create();
}

bool PScene::init()
{
	if (!Scene::init())
	{
		return false;
	}

	auto audio = SimpleAudioEngine::getInstance();
	audio->stopBackgroundMusic(TRUE);
	audio->playBackgroundMusic("Audio/BATMAN.mp3",TRUE);

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto backgroundSprite = Sprite::create("JP.png");
	backgroundSprite->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

	this->addChild(backgroundSprite);

	auto titleSprite = Sprite::create("Run.png");
	titleSprite->setPosition(Point(525,400));

	this->addChild(titleSprite);

	auto playItem = MenuItemImage::create( "ElHeroe.png", "ElHeroe.png", CC_CALLBACK_1(PScene::GoToGameScene, this ));
	playItem->setPosition(Point(300, 200));

	auto playItem2 = MenuItemImage::create("Heroe2.png", "Heroe2..png", CC_CALLBACK_1(PScene::GoToGameScene2, this));
	playItem2->setPosition(Point(650, 200));

	auto* ElMenu = Menu::create(playItem, NULL);
	ElMenu->setPosition(Point(0, 0));
	this->addChild( ElMenu );

	auto* ElMenu2 = Menu::create(playItem2, NULL);
	ElMenu2->setPosition(Point(0, 0));
	this->addChild(ElMenu2);

	return true;
}

void PScene::GoToGameScene(cocos2d::Ref* sender)
{
	auto scene = GameScene::createScene();

	Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
}

void PScene::GoToGameScene2(cocos2d::Ref* sender)
{
	auto scene = GameScene2::createScene();

	Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
}
