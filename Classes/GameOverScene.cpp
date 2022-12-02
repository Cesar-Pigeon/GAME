#include "GameOverScene.h"
#include "MainMenuScene.h"
#include "GameScene.h"
#include "Definitions.h"
#include "cocos2d.h"
#include <cocostudio/SimpleAudioEngine.h>

USING_NS_CC;

using namespace CocosDenshion;


Scene* GameOverScene::createScene()
{
   auto scene = Scene::create();

   auto layer = GameOverScene::create();

   scene->addChild(layer);

   return scene;
}

bool GameOverScene::init()
{
	if (!Scene::init())
	{
		return false;
	}

	auto audio = SimpleAudioEngine::getInstance();
	audio->stopBackgroundMusic(TRUE);
	audio->playBackgroundMusic("Audio/Pedo.mp3", TRUE);

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto backgroundSprite = Sprite::create("fin.png");
	backgroundSprite->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

	this->addChild(backgroundSprite);

	auto titleSprite = Sprite::create("GO.png");
	titleSprite->setPosition(Point(505, 450));

	this->addChild(titleSprite);

	auto playItem = MenuItemImage::create("menu1.png", "menu2.png", CC_CALLBACK_1(GameOverScene::GoToMainMenuScene, this));
	playItem->setPosition(Point(550, 100));

	auto* ElMenu = Menu::create(playItem, NULL);
	ElMenu->setPosition(Point(0, 0));
	this->addChild(ElMenu);



	return true;
}

void GameOverScene::GoToMainMenuScene(cocos2d::Ref* sender)
{
	auto scene = MainMenuScene::createScene();

	Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
}

