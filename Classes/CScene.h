#ifndef _CSCENE_H
#define _CSCENE_H

#include "CObject.h"

class CScene: public cocos2d::Scene
{
public:
    virtual bool init();
    virtual void update(float deltaTime);

};


#endif //_SCENE_H