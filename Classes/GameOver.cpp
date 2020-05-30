#include "GameOver.h"
#include "MainMenu.h"
#include "HelloWorldScene.h"


USING_NS_CC;

Scene *GameOver::createScene() {
    auto scene = Scene::create();
    auto layer = GameOver::create();
    scene->addChild(layer);
    return scene;
}

void GameOver::GoToGameScene(cocos2d::Ref *pSender)
{
    auto scene = HelloWorld::createScene();
    Director::getInstance()->replaceScene(scene);
}
void GameOver::GoToMainMenu(cocos2d::Ref *pSender)
{
    auto scene = MainMenu::createScene();
    Director::getInstance()->replaceScene(scene);
}



bool GameOver::init()
{
    if (!Layer::init())
    {
        return false;
    }
    return true;
}