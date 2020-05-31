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

void GameOver::GoToGameScene(cocos2d::Ref *pSender) {
    auto scene = HelloWorld::createScene();
    Director::getInstance()->replaceScene(scene);
}

void GameOver::GoToMainMenu(cocos2d::Ref *pSender) {
    auto scene = MainMenu::createScene();
    Director::getInstance()->replaceScene(scene);
}


bool GameOver::init() {
    if (!Layer::init()) {
        return false;
    }

    Size size = Director::getInstance()->getWinSize();

    auto gameNameLabel = Label::createWithTTF("Game Over", "fonts/Marker Felt.ttf", 36);
    gameNameLabel->setPosition(Vec2(size.width / 2, size.height / 1.5));
    this->addChild(gameNameLabel);

    return true;
}