#include "MainMenu.h"
#include "HelloWorldScene.h"
#include "GameOver.h"
#include <cstdio>

using namespace std;

USING_NS_CC;


void MainMenu::GoToGameScene(Ref *pSender) {
    auto scene = HelloWorld::createScene();
    Director::getInstance()->replaceScene(scene);
}


Scene *MainMenu::createScene() {
    auto scene = Scene::create();
    auto layer = MainMenu::create();
    scene->addChild(layer);
    return scene;
}

bool MainMenu::init() {
    if (!Layer::init()) {
        return false;
    }

    Size size = Director::getInstance()->getWinSize();

    auto gameNameLabel = Label::createWithTTF("Bee Balls", "fonts/Marker Felt.ttf", 36);
    gameNameLabel->setPosition(Vec2(size.width / 2, size.height / 1.5));
    this->addChild(gameNameLabel);

    auto playItem = MenuItemImage::create("playButton.png", "playButton.png",
                                          CC_CALLBACK_1(MainMenu::GoToGameScene, this));
    auto menu = Menu::create(playItem, NULL);
    menu->alignItemsVerticallyWithPadding(200);
    this->addChild(menu);

    return true;
}