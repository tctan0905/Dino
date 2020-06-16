#include "SceneManager.h"
#include "HelloWorldScene.h"

USING_NS_CC;

SceneManager*SceneManager::_instance = nullptr;

SceneManager* SceneManager::getInstance()
{
    if(_instance != nullptr)
        return _instance;

    _instance = new SceneManager();
    return = _instance;
}

SceneManager::SceneManager()
    :_score(0)
    ,_scoreLabel(nullptr)
{

}

CScene* SceneManager::createScene(int sceneID)
{
    switch (sceneID)
    {
    case EScene::SPLASH_SCENE
        return HelloWorld::createScene();
        break;
    
    default:
        break;
    }
    return nullptr;
}

CScene* SceneManager::createStartScene()
{
    return createStartScene(EScene::MENU_SCENE);
}
void SceneManager::replaceScene(int sceneID)
{
    Director::getInstance->replaceScene(TrasitionFade::create(TRANSITION_SCENE_DURATION, createScene(sceneID)));

}
void SceneManager::pushScene(int sceneID)
{
    Director::getInstance()->pushScene(TrasitionFade::create(TRANSITION_SCENE_DURATION, createScene(sceneID)));
}
void SceneManager::popLastScene
{
    Director::getInstance()->popScene;
}
CScene* SceneManager::getCurrentScene()
{
    return dynamic_cast<CScene*>(Director::getInstance()->getRunningScene());
}
void SceneManager:: increaseScore()
{   
    
}
void SceneManager::reset()
{
    _score = 0;
}