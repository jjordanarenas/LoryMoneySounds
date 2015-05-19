//
//  GameScene.cpp
//  LoryMoney
//
//  Created by Jorge Jordán on 11/05/15.
//
//

//#include "ui/CocosGUI.h"
#include "SimpleAudioEngine.h"
#include "GameScene.h"
#include "GADBannerView.h"

USING_NS_CC;

auto viewWidth = 0.0;
auto viewHeight = 0.0;
auto adHeight = 50.0;
auto buttonSize = 50.0;
auto gapX = 0.0;
auto gapY = 0.0;
auto maxNumColumns = 4;
auto maxNumRows = 5;
auto bannerView;

//ID del bloque de anuncios: ca-app-pub-5767684210972160/5150935139
Scene* GameScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = GameScene::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool GameScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    
    //CSLog(@"Google Mobile Ads SDK version: %@", [GADRequest sdkVersion]);
    
    
    //Size visibleSize = Director::getInstance()->getVisibleSize();
    //Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.
    
    // add a "close" icon to exit the progress. it's an autorelease object
    /*auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(GameScene::menuCloseCallback, this));*/
    
    /*closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));*/
    
    // create menu, it's an autorelease object
    //auto menu = Menu::create(closeItem, NULL);
    //menu->setPosition(Vec2::ZERO);
    //this->addChild(menu, 1);
    
    /////////////////////////////
    // 3. add your codes below...
    
    // add a label shows "Hello World"
    // create and initialize a label
    
    //auto label = Label::createWithTTF("Hello World", "fonts/Marker Felt.ttf", 24);
    
    // position the label on the center of the screen
    /*label->setPosition(Vec2(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - label->getContentSize().height));*/
    
    // add the label as a child to this layer
    //this->addChild(label, 1);
    
    // add "GameScene" splash screen"
    //auto sprite = Sprite::create("HelloWorld.png");
    
    // position the sprite on the center of the screen
    //sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    
    // add the sprite as a child to this layer
    //this->addChild(sprite, 0);
    this->initializeVariables();
    
    return true;
}

void GameScene::initializeVariables() {
    viewWidth = Director::getInstance()->getVisibleSize().width;
    viewHeight = Director::getInstance()->getVisibleSize().height;
    
    auto buttonAux = cocos2d::ui::Button::create("Icon-40@3x.png", "Icon-40@3x.png", "Icon-40@3x.png");
    
    buttonSize = buttonAux->getSize().width;
    
    //auto buttonPositionX = buttonSize/2 + gapX;
    auto buttonPositionX = 0;
    auto buttonPositionY = buttonSize/2 + gapX;
    auto tag = 0;
    auto index = 0;
    
    
    
    // Calculate max number of buttons in a row
   // maxNumColumns = (viewWidth - 2 * gapX + gapX/2) / (gapX/2 + buttonSize);
    
    
    //gapX = (viewWidth - maxNumColumns * buttonSize - ((maxNumColumns - 1) * gapX / 2)) / 2;
    gapX = (viewWidth - maxNumColumns * buttonSize) / (2 + (maxNumColumns - 1) / 2);
    gapY = (viewHeight - adHeight - (maxNumRows * buttonSize)) / (2 + (maxNumRows - 1) / 2);
    buttonPositionX = gapX;
    
    buttonPositionY = gapY + adHeight;
    
    
    
    for (int j = 0; j < maxNumRows; j++) {
        
    for (int i = 0; i < maxNumColumns; i++) {
       
        
        
        index = 10 * j + i;
        
        // Add new button
        auto button = cocos2d::ui::Button::create("Icon-40@3x.png", "Icon-40@3x.png", "Icon-40@3x.png");
        button->setTag(i);
        
        //buttonSize = button->getSize().width;
        
        CCLog("Tag: %d", button->getTag());
        button->cocos2d::Node::setPosition(buttonPositionX + gapX, buttonPositionY + gapX);
        
        switch (index) {
            case 0:
                button->addTouchEventListener([&](Ref* sender, cocos2d::ui::Widget::TouchEventType type){
                    switch (type)
                    {
                        case ui::Widget::TouchEventType::BEGAN:
                            break;
                        case ui::Widget::TouchEventType::ENDED:
                            //CCLog("Button 1 clicked");
                            //CCLog("Button clicked: %d", sender->getReferenceCount());
                            auto audio = CocosDenshion::SimpleAudioEngine::getInstance();
                            audio->playBackgroundMusic("background_music.mp3");
                            //this->playSound01(button);
                            
                            break;
                            //default:
                            //  break;
                    }
                });
                break;
                
            case 10:
                button->addTouchEventListener([&](Ref* sender, cocos2d::ui::Widget::TouchEventType type){
                    switch (type)
                    {
                        case ui::Widget::TouchEventType::BEGAN:
                            break;
                        case ui::Widget::TouchEventType::ENDED:
                            //CCLog("Button 1 clicked");
                            //CCLog("Button clicked: %d", sender->getReferenceCount());
                            auto audio = CocosDenshion::SimpleAudioEngine::getInstance();
                            audio->playEffect("9mm.mp3", false, 1.0f, 1.0f, 1.0f);
                            //this->playSound01(button);
                            
                            break;
                            //default:
                            //  break;
                    }
                });
                break;
            case 20:
                button->addTouchEventListener([&](Ref* sender, cocos2d::ui::Widget::TouchEventType type){
                    switch (type)
                    {
                        case ui::Widget::TouchEventType::BEGAN:
                            break;
                        case ui::Widget::TouchEventType::ENDED:
                            //CCLog("Button 1 clicked");
                            //CCLog("Button clicked: %d", sender->getReferenceCount());
                            auto audio = CocosDenshion::SimpleAudioEngine::getInstance();
                            audio->playEffect("9mm.mp3", false, 1.0f, 1.0f, 1.0f);
                            //this->playSound01(button);
                            
                            break;
                            //default:
                            //  break;
                    }
                });
                break;

                
            case 1:
                button->addTouchEventListener([&](Ref* sender, cocos2d::ui::Widget::TouchEventType type){
                    switch (type)
                    {
                        case ui::Widget::TouchEventType::BEGAN:
                            break;
                        case ui::Widget::TouchEventType::ENDED:
                            //CCLog("Button 1 clicked");
                            //CCLog("Button clicked: %d", sender->getReferenceCount());
                            auto audio = CocosDenshion::SimpleAudioEngine::getInstance();
                            audio->playEffect("storm.mp3", false, 1.0f, 1.0f, 1.0f);
                            //this->playSound01(button);
                            
                            break;
                            //default:
                            //  break;
                    }
                });
                break;
            case 2:
                button->addTouchEventListener([&](Ref* sender, cocos2d::ui::Widget::TouchEventType type){
                    switch (type)
                    {
                        case ui::Widget::TouchEventType::BEGAN:
                            break;
                        case ui::Widget::TouchEventType::ENDED:
                            //CCLog("Button 1 clicked");
                            //CCLog("Button clicked: %d", sender->getReferenceCount());
                            auto audio = CocosDenshion::SimpleAudioEngine::getInstance();
                            audio->playEffect("applause.mp3", false, 1.0f, 1.0f, 1.0f);
                            //this->playSound01(button);
                            
                            break;
                            //default:
                            //  break;
                    }
                });
                break;
                
                
            case 3:
                button->addTouchEventListener([&](Ref* sender, cocos2d::ui::Widget::TouchEventType type){
                    switch (type)
                    {
                        case ui::Widget::TouchEventType::BEGAN:
                            break;
                        case ui::Widget::TouchEventType::ENDED:
                            auto audio = CocosDenshion::SimpleAudioEngine::getInstance();
                            audio->playEffect("piano.mp3", false, 1.0f, 1.0f, 1.0f);
                            break;
                    }
                });
                break;
                
                
                default:
                break;
        }
        
        
        
        
        
        this->addChild(button);
        
       // buttonPositionX += button->getSize().width + gapX;
         buttonPositionX += buttonSize + gapX/2;
    }
        //buttonPositionX = buttonSize/2 + gapX/2;
        buttonPositionX = gapX;
        buttonPositionY += buttonSize + gapY/2;
    }
}

void GameScene::playSound01(cocos2d::ui::Button *b) {
    auto audio = CocosDenshion::SimpleAudioEngine::getInstance();
    CCLog("Button clicked: %d", b->getTag());
    switch(b->getTag()) {
        case 0:
            // play a sound effect, just once.
            audio->playEffect("9mm.mp3", false, 1.0f, 1.0f, 1.0f);
            
            break;
        case 1:
            // play a sound effect, just once.
            audio->playEffect("storm.mp3", false, 1.0f, 1.0f, 1.0f);
            
            break;
            
        case 2:
            // play a sound effect, just once.
            audio->playEffect("applause.mp3", false, 1.0f, 1.0f, 1.0f);
            
            break;
            
        case 3:
            // play a sound effect, just once.
            audio->playEffect("piano.mp3", false, 1.0f, 1.0f, 1.0f);
            
            break;
    }
    
}

    void GameScene::menuCloseCallback(Ref* pSender)
    {
        Director::getInstance()->end();
        
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
        exit(0);
#endif
    }
