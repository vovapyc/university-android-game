#include "HelloWorldScene.h"
#include <cstdio>
#include "GameOver.h"

using namespace std;

USING_NS_CC;


Scene *HelloWorld::createScene() {
    // 'scene' is an autorelease object
    auto scene = Scene::createWithPhysics();
    // 'layer' is an autorelease object
    scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
    auto layer = HelloWorld::create();
    // add layer as a child to scene

    scene->addChild(layer);
    // return the scene
    return scene;
}

void HelloWorld::GoToPauseScene(cocos2d::Ref *pSender) {
//    auto scene = PauseScene::createScene();
//    Director::getInstance()->pushScene(scene);
}

void HelloWorld::GoToGameOverScene() {
    auto scene = GameOver::createScene();
    Director::getInstance()->replaceScene(scene);
}

bool HelloWorld::init() {
    if (!Layer::init()) {
        return false;
    }


    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();


    auto wall = Node::create();
    auto wallBody = PhysicsBody::createEdgeBox(visibleSize, PhysicsMaterial(0.1f, 1.0f, 0.0f));
    wall->setPhysicsBody(wallBody);
    wall->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
    addChild(wall);

    auto sprite3 = Sprite::create("ball.png");
    sprite3->setPosition(Vec2(0, 250));
    sprite3->setScale(0.40f);
    auto spriteBody3 = PhysicsBody::createBox(sprite3->getContentSize(),
                                              PhysicsMaterial(0, 1.9, 0.7));
    sprite3->setPhysicsBody(spriteBody3);
    spriteBody3->setGravityEnable(false);
    spriteBody3->setVelocity(Vect(100, 50));
    spriteBody3->setVelocityLimit(0);
    this->addChild(sprite3);


    auto sprite2 = Sprite::create("ball.png");
    sprite2->setPosition(Vec2(200, 250));
    sprite2->setScale(0.40f);
    auto spriteBody = PhysicsBody::createCircle(sprite2->getContentSize().height / 2,
                                                PhysicsMaterial(0, 1.9, 0.7));
    sprite2->setPhysicsBody(spriteBody);
    spriteBody->setGravityEnable(false);
    spriteBody->setVelocity(Vect(100, 50));
    spriteBody->setVelocityLimit(200);
    this->addChild(sprite2);


    sprite = Sprite::create("ball.png");
    sprite->setPosition(Vec2(0, 0));
    sprite->setScale(0.40f);
    spriteBody2 = PhysicsBody::createCircle(sprite->getContentSize().height / 2,
                                            PhysicsMaterial(0, 1.9, 0.7));
    sprite->setPhysicsBody(spriteBody2);
    spriteBody2->setGravityEnable(false);
    spriteBody2->setVelocityLimit(0);

    size = Director::getInstance()->getWinSize();
    auto listener = EventListenerTouchOneByOne::create();
    listener->setSwallowTouches(true);

    listener->onTouchBegan = CC_CALLBACK_2(HelloWorld::onTouchBegan, this);
    listener->onTouchMoved = CC_CALLBACK_2(HelloWorld::onTouchBegan, this);

    this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);

    this->addChild(sprite);
//////////////////////////////////////////////////////

    auto contactListener = EventListenerPhysicsContact::create();

    contactListener->onContactBegin = CC_CALLBACK_1(HelloWorld::onCollision, this);

    this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(contactListener, this);

    return true;

}

bool HelloWorld::onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *event) {
    isTouching = true;
    touchPosition_x = touch->getLocation().x;
    touchPosition_y = touch->getLocation().y;
    sprite->setPosition(Vec2(touchPosition_x, touchPosition_y));
    spriteBody2->setPositionOffset(
            Vec2(touchPosition_x - touchPosition_x, touchPosition_y - touchPosition_y));
    return true;
}

void HelloWorld::onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *event) {
    // isTouching = true;
    touchPosition_x = touch->getLocation().x;
    touchPosition_y = touch->getLocation().y;
    spriteBody2->setPositionOffset(Vec2(touchPosition_x, touchPosition_y));

}

bool HelloWorld::onCollision(PhysicsContact &contact) {

    return false;
}
