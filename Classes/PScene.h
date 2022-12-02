#ifndef __P_SCENE_H__
#define __P_SCENE_H__

#include "cocos2d.h"

class PScene : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(PScene);

private:
    void GoToGameScene(cocos2d::Ref* sender);
    void GoToGameScene2(cocos2d::Ref* sender);
};

#endif // __MAIN_MENU_SCENE_H__
