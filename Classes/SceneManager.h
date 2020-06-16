#ifndef _SCENE_MANAGER_H
#define _SCENE_MANAGER_H

#include "cocos2d.h"
#include "Common.h"
#include "CScene.h"

enum EScene
{
    SPLASH_SCENE,
    GAMEPLAY_SCENE,
    MENU_SCENE,
    UI_SCENE,
    GAMEOVER_SCENE
};

class SceneManager
{
protected:
    static SceneManager* _instance;

    SceneManager();
    SceneManager(const SceneManager & other){}
    virtual ~SceneManager() {}

public:
    static SceneManager* getInstance();

    CScene* createScene(int sceneID);
    CScene* createStartScene();
    CScene* getCurrentScene();

    void replaceScene(int sceneID);
    void pushScene(int sceneID);
    void popLastScene();
    void increaseScore();

    void reset();

    CC_SYNTHESIZE_READONLY(int, _score, Score);
    CC_SYNTHESIZE(cocos2d::Label*,_scoreLabel, ScoreLabel);
};
#endif //_SCENE_MANAGER_H