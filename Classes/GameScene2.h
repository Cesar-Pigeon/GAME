#ifndef __GAME_SCENE_2_H__
#define __GAME_SCENE_2_H__

#include "cocos2d.h"
#include "Snake.h"
#include "iostream"


using namespace cocos2d;

class GameScene2 : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    CREATE_FUNC(GameScene2);

    cocos2d::Sprite *mySprite1;
    cocos2d::Sprite* mySpriteHeroe1;
    cocos2d::Sprite* mySpriteSnake1;
    cocos2d::Sprite* mySpriteGordo1;

    void GameScene2::onKeyPressed(cocos2d::EventKeyboard::KeyCode key, cocos2d::Event* event);
    void GameScene2::onKeyReleased(cocos2d::EventKeyboard::KeyCode key, cocos2d::Event* event);

    bool GameScene2::onContactBegin(PhysicsContact& contact);
    
    void GameScene2::MoveEnemy(float dt);

    Label* label;
    std::string st;

    void GameScene2::Score(float dt);
    int puntaje;

private:
    cocos2d::PhysicsWorld* sceneWorld;
    void SetPhysicsWorld(cocos2d::PhysicsWorld* world) { sceneWorld = world; };
};

#endif // __GAME_SCENE_2_H__
