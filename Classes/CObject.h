#ifndef _COBJECT_H_
#define _COBJECT_H_

#include "cocos2d.h"

class CObject: public cocos2d::Node
{
public:
    CObject();
    virtual bool init();
    virtual void updateObject(float deltaTime);
    virtual void run(float deltaTime) =0;

    cocos2d::Rect getRect();

    virtual void createPhysicsBody(bool dynamic =true, bool rotationEnable = true);

    virtual void onCollsionEnter(CObject* gameObject){}
    virtual void onCollisionExit(CObject* gameObject){}
    virtual void onCollisionPreEnter(CObject* gameObject){}
    virtual void onCollisionPostExit(CObject* gameObject){}

protected:
    bool _isAlive;
};
#endif //_COBJECT_H_