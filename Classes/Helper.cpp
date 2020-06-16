#include "Helper.h"

USING_NS_CC;

Size Helper::getSceneSize()
{
    return Director::getInstance->getWinSize();
}

Vector<SpriteFrame*> Helper::getAnimation(const char* format, int count)
{
    auto spritecache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> aniFrames;
    char str[50];
    for(int i = 1; i<= count; i++)
    {
        sprintf(str, format ,i);
        aniFrames.pushBack(spritecache->getSpriteFrameByName(str));
    }
    return aniFrames;
    
}

Vec2 Helper::getOrigin()
{
    return Director::getInstance()->getVisibleOrigin();
}

Vec2 Helper::getSceneCenter()
{
    auto winSize = getSceneSize();
    return Vec2(winSize.width /2.0f, winSize.height / 2.0f);
}

Vec2 Helper::getTopRight()
{
    return Vec2(getSceneSize().width - getOrigin().x,getContentSize().height - getOrigin().y);
}