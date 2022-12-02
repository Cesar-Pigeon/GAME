#include "GameScene.h"
#include "MainMenuScene.h"
#include <cocostudio/SimpleAudioEngine.h>
#include "GameOverScene.h"
#include "Definitions.h"
#include "iostream"
#include <cstdlib>
#include "string"
#include <windows.h>


USING_NS_CC;

using namespace CocosDenshion;
using namespace std;





Scene* GameScene::createScene()
{
   auto scene = Scene::createWithPhysics();
   //scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
   

   auto layer = GameScene::create();
   layer->SetPhysicsWorld(scene->getPhysicsWorld());
   

   scene->addChild(layer);

   return scene;
}

bool GameScene::init()
{
	if (!Scene::init())
	{
		return false;
	}

	puntaje = 0;

	schedule(CC_SCHEDULE_SELECTOR(GameScene::Score),0.1, CC_REPEAT_FOREVER, 0);

	int random;
	random = 1 +rand() % 2;


	auto contactListener = EventListenerPhysicsContact::create();
	contactListener->onContactBegin = CC_CALLBACK_1(GameScene::onContactBegin, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(contactListener, this);


	schedule(CC_SCHEDULE_SELECTOR(GameScene::MoveEnemy), random, CC_REPEAT_FOREVER, 5);
	auto listener = EventListenerKeyboard().create();
	listener->onKeyPressed = CC_CALLBACK_2(GameScene::onKeyPressed, this);
	listener->onKeyReleased = CC_CALLBACK_2(GameScene::onKeyReleased, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

	auto audio = SimpleAudioEngine::getInstance();
	audio->stopBackgroundMusic(TRUE);
	audio->playBackgroundMusic("Audio/CYZ.mp3", TRUE);

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto backgroundSprite = Sprite::create("BG.png");
	backgroundSprite->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

	this->addChild(backgroundSprite);

	mySprite = Sprite::create("Map.png");
	auto spriteBody1 = PhysicsBody::createBox(mySprite->getContentSize());
	spriteBody1->setGravityEnable(false);
	spriteBody1->setDynamic(false);
	mySprite->setPhysicsBody(spriteBody1);
	mySprite->setPosition(500, 20);

	this->addChild(mySprite);

	//Heroe

	mySpriteHeroe = Sprite::create("ElHeroe.png");
	mySpriteHeroe->setTag(9);

	auto cuerpo = PhysicsBody::createBox(mySpriteHeroe->getContentSize());
	cuerpo->setGravityEnable(true);
	cuerpo->setDynamic(true);
	cuerpo->setCategoryBitmask(0x04);
	cuerpo->setCollisionBitmask(0x03);
	cuerpo->setContactTestBitmask(0xFFFFFFFF);
	mySpriteHeroe->addComponent(cuerpo);

	mySpriteHeroe->setPosition(100, 230);

	this->addChild(mySpriteHeroe);

	st = std::to_string(puntaje);
	label = Label::createWithSystemFont(st, "Arial", 30);
	label->setPosition(870, 450);
	label->setAnchorPoint(Vec2(0, 0));
	this->addChild(label);

	return true;
}


void GameScene::onKeyPressed(cocos2d::EventKeyboard::KeyCode key, cocos2d::Event* event)
{
	auto visibleSize = Director::getInstance()->getVisibleSize();
	auto position_ = mySpriteHeroe->getPosition();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	if (key == EventKeyboard::KeyCode::KEY_RIGHT_ARROW) {
		CCLOG("Key flecha derecha pressed");
		if (position_.x <= visibleSize.width) {
			auto action = RepeatForever::create(MoveBy::create(.05, Vec2(14, 0)));
			mySpriteHeroe->setRotation(0);
			mySpriteHeroe->runAction(action);
		}
	}

	if (key == EventKeyboard::KeyCode::KEY_LEFT_ARROW) {
		if (position_.x >= origin.x) {
			auto action = RepeatForever::create(MoveBy::create(.05, Vec2(-14, 0)));
			mySpriteHeroe->setRotation(0);
			mySpriteHeroe->runAction(action);
		}
	}

	if (key == EventKeyboard::KeyCode::KEY_UP_ARROW) {
		if (position_.y >= 0) {
			auto action = JumpBy::create(.5, Point(0, 0), 120, 1);
			mySpriteHeroe->setRotation(0);
			mySpriteHeroe->runAction(action);

		}
	}
}

void GameScene::onKeyReleased(cocos2d::EventKeyboard::KeyCode key, cocos2d::Event* event) {
	if (key == EventKeyboard::KeyCode::KEY_RIGHT_ARROW) {

		mySpriteHeroe->stopAllActions();
	}

	if (key == EventKeyboard::KeyCode::KEY_LEFT_ARROW) {

		mySpriteHeroe->stopAllActions();
	}

	if (key == EventKeyboard::KeyCode::KEY_UP_ARROW) {

		mySpriteHeroe->stopAllActions();
	}

}

void GameScene::MoveEnemy(float dt)
{
	int a;
	a = rand() % 2;
	if (a == 0)
	{
		mySpriteSnake = Sprite::create("Snake.png");

		auto cuerpo2 = PhysicsBody::createCircle(mySpriteSnake->getContentSize().width / 2);
		cuerpo2->setGravityEnable(false);
		cuerpo2->setDynamic(true);
		cuerpo2->setCategoryBitmask(0x03);
		cuerpo2->setCollisionBitmask(0x04);
		cuerpo2->setContactTestBitmask(0xFFFFFFFF);
		mySpriteSnake->addComponent(cuerpo2);
		mySpriteSnake->setPosition(1100, 200);

		auto movimiento = MoveTo::create(2, Point(0, 200));
		auto camino = Sequence::create(movimiento, RemoveSelf::create(), NULL);
		mySpriteSnake->runAction(camino);

		this->addChild(mySpriteSnake);
	}
	if (a == 1)
	{
		mySpriteGordo = Sprite::create("Gordo.png");

		auto cuerpo3 = PhysicsBody::createCircle(mySpriteGordo->getContentSize().width / 2);
		cuerpo3->setGravityEnable(false);
		cuerpo3->setDynamic(true);
		cuerpo3->setCategoryBitmask(0x03);
		cuerpo3->setCollisionBitmask(0x04);
		cuerpo3->setContactTestBitmask(0xFFFFFFFF);
		mySpriteGordo->addComponent(cuerpo3);
		mySpriteGordo->setPosition(800, 225);

		auto movimiento = MoveTo::create(2, Point(-200, 225));
		auto camino = Sequence::create(movimiento, RemoveSelf::create(), NULL);
		mySpriteGordo->runAction(camino);


		this->addChild(mySpriteGordo);
	}
}

bool GameScene::onContactBegin(PhysicsContact& contact)
{
	auto nodeA = contact.getShapeA()->getBody()->getNode();
	auto nodeB = contact.getShapeB()->getBody()->getNode();

	if (nodeA && nodeB)
	{
		if (nodeA->getTag() == 9)
		{
			nodeB->removeFromParentAndCleanup(true);
		}
		else if (nodeB->getTag() == 9)
		{
			nodeA->removeFromParentAndCleanup(true);
			auto scene = GameOverScene::createScene();

			Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
		}

		
	}
	return true;
}

void GameScene::Score(float dt)
{
	puntaje++;
	st = std::to_string(puntaje);
	label->setString(st);
}


	
