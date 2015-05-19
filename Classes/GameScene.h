//
//  GameScene.h
//  LoryMoney
//
//  Created by Jorge Jordán on 11/05/15.
//
//

#ifndef LoryMoney_GameScene_h
#define LoryMoney_GameScene_h

#include "cocos2d.h"
#include "ui/CocosGUI.h"

class GameScene : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();
    
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    void initializeVariables();
    
    void playSound01(cocos2d::ui::Button *b);
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(GameScene);
};

#endif