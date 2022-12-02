#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__

#include "cocos2d.h"
#include "Snake.h"
#include "iostream"


using namespace cocos2d;

class GameScene : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    CREATE_FUNC(GameScene);

    cocos2d::Sprite *mySprite;
    cocos2d::Sprite* mySpriteHeroe;
    cocos2d::Sprite* mySpriteSnake;
    cocos2d::Sprite* mySpriteGordo;

    void GameScene::onKeyPressed(cocos2d::EventKeyboard::KeyCode key, cocos2d::Event* event);
    void GameScene::onKeyReleased(cocos2d::EventKeyboard::KeyCode key, cocos2d::Event* event);

    bool GameScene::onContactBegin(PhysicsContact& contact);
    
    void GameScene::MoveEnemy(float dt);

    Label* label;
    std::string st;

    void GameScene::Score(float dt);
    int puntaje;

private:
    cocos2d::PhysicsWorld* sceneWorld;
    void SetPhysicsWorld(cocos2d::PhysicsWorld* world) { sceneWorld = world; };
};

#endif // __GAME_SCENE_H__
