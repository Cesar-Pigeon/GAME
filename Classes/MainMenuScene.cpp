#include "MainMenuScene.h"
#include "GameScene.h"
#include "Definitions.h"
#include "cocos2d.h"
#include <cocostudio/SimpleAudioEngine.h>
#include "PScene.h"

USING_NS_CC;
using namespace CocosDenshion;

Scene* MainMenuScene::createScene()
{
   auto scene = Scene::create();

   auto layer = MainMenuScene::create();

   scene->addChild(layer);

   return MainMenuScene::create();
}

bool MainMenuScene::init()
{
	if (!Scene::init())
	{
		return false;
	}

	auto audio = SimpleAudioEngine::getInstance();
	audio->stopBackgroundMusic(TRUE);
	audio->playBackgroundMusic("Audio/Angeles.mp3",TRUE);

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto backgroundSprite = Sprite::create("Cielo.png");
	backgroundSprite->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

	this->addChild(backgroundSprite);

	auto titleSprite = Sprite::create("Run.png");
	titleSprite->setPosition(Point(525,400));

	this->addChild(titleSprite);

	auto playItem = MenuItemImage::create( "play1.png", "play2.png", CC_CALLBACK_1(MainMenuScene::GoToGameScene, this ));
	playItem->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

	auto* ElMenu = Menu::create(playItem, NULL);
	ElMenu->setPosition(Point(0, 0));
	this->addChild( ElMenu );

	return true;
}

void MainMenuScene::GoToGameScene(cocos2d::Ref* sender)
{
	auto scene = PScene::createScene();

	Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
}
