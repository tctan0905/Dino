/****************************************************************************
 Copyright (c) 2017-2018 Xiamen Yaji Software Co., Ltd.
 
 http://www.cocos2d-x.org
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/

#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"
#include "AppDelegate.h"
#include "Define.h"
#include "Helper.h"
#include "Common.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    return HelloWorld::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    // //set design size
    // float DH = MAX(glview->getFrameSize().height , glview->getFrameSize().width);
    // float DW = MIN(glview->getFrameSize().height , glview->getFrameSize().width);
    
    // DH = DH / DW * 600;
    // DW = 600;

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    LayerColor * _bgColor = LayerColor::create(Color4B(247,247,247,255));
    this->addChild(_bgColor, -10);

    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));

    if (closeItem == nullptr ||
        closeItem->getContentSize().width <= 0 ||
        closeItem->getContentSize().height <= 0)
    {
        problemLoading("'CloseNormal.png' and 'CloseSelected.png'");
    }
    else
    {
        float x = origin.x + visibleSize.width - closeItem->getContentSize().width/2;
        float y = origin.y + closeItem->getContentSize().height/2;
        closeItem->setPosition(Vec2(x,y));
    }

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label

    auto label = Sprite::create("logo-vtca-xanh-duong.png");
    if (label == nullptr)
    {
        problemLoading("logo-vtca-xanh-duong.png");
    }
    else
    {
        // position the label on the center of the screen
        label->setPosition(Vec2(origin.x + visibleSize.width/2,
                                origin.y + visibleSize.height - label->getContentSize().height));

        // add the label as a child to this layer
        this->addChild(label, 0);
    }

    // add "HelloWorld" splash screen"
    auto sprite = Sprite::create("title.png");
    if (sprite == nullptr)
    {
        problemLoading("'title.png'");
    }
    else
    {
        // position the sprite on the center of the screen
        sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height - sprite->getContentSize().height    + origin.y ));

        // add the sprite as a child to this layer
        this->addChild(sprite, 0);
    }

    auto spRoad1 = Sprite::create("road_1.png");
    spRoad1->setAnchorPoint(Vec2::ANCHOR_MIDDLE_LEFT);
    spRoad1->setPosition(Vec2(0 , GROUND_HEIGHT));
    
    this->addChild(spRoad1,0);

    auto spRoad2 = Sprite::create("road_2.png");
    spRoad2->setAnchorPoint(Vec2::ANCHOR_MIDDLE_LEFT);
    spRoad2->setPosition(Vec2(spRoad1->getPositionX() + spRoad1->getContentSize().width - 5, GROUND_HEIGHT));
    this->addChild(spRoad2, 0);


    auto _scoreicon = Sprite::create("scoreicon.png");
    _scoreicon->SetAnchorpoint(Vec2(0.5f,0.5f));
    _scoreicon->setPosition(Helper::getTopRight);
    this->addChild(_scoreicon , 1);

    // auto frames = Helper::getAnimation("dino_%d.png",2);
    // auto _character = Sprite::createWithSpriteFrame(frames.front());
    // this->setContentSize(_character->getContentSize());
    // _character->setPosition(Vec2(50,-60));
    // this->addChild(_character, 0);

    // auto walks = Animation::createWithSpriteFrames(frames, 0.2);
    // _character->runAction(RepeatForever::create(Animate::create(walks)));



    // SpriteFrameCache *spriteCache = SpriteFrameCache::getInstance();
  
    // Vector<SpriteFrame*> frames(22);
    // for (int i; i<= 22; i++)
    // {
    //     CCString *frame_name = CCString::createWithFormat("%d.png",i);
    //     auto frame = spriteCache->getSpriteFrameByName(frame_name->getCString());
    //     //frames->addObject(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(frame->getCString()));
    //     frames.pushBack(frame);

    // }

    // auto blast_frame = Animation::createWithSpriteFrames(frames,0.1);
    // blast_frame->setRestoreOriginalFrame(true);
    // auto blast = Sprite::createWithSpriteFrameName("0.png");
    // blast->setPosition(Vec2(visibleSize.width/2,visibleSize.height/2));
    // this->addChild(blast,500);

    // blast->runAction(RepeatForever::create(Animate::create(blast_frame)));
    
    return true;
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();

    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() as given above,instead trigger a custom event created in RootViewController.mm as below*/

    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);


}
