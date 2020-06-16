#ifndef _HELPER_H
#define _HELPER_H

#include "cocos2d.h"

USING_NS_CC;

class Helper
{
public:
    static Size getSceneSize();
    static Vec2 getSceneCenter();
    static Vec2 getOrigin();
    static Vector<SpriteFrame*> getAnimation(const char* format,int count); 
    static Vec2 getTopRight();
    

};

#endif //_HELPER_H