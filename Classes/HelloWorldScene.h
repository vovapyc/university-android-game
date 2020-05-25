

#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"

class HelloWorld : public cocos2d::Layer {
public:
    static cocos2d::Scene* createScene();



    virtual bool init();
    bool onCollision(cocos2d::PhysicsContact& contact);
    bool onTouchBegan(cocos2d::Touch *touch, cocos2d::Event * event);
    void onTouchMoved(cocos2d::Touch *touch, cocos2d::Event * event);
    cocos2d::Sprite *sprite;
    cocos2d::PhysicsBody *spriteBody2;
    cocos2d::Size size;
    bool isTouching;
    float touchPosition_x, touchPosition_y;

    CREATE_FUNC(HelloWorld);



};

#endif // __HELLOWORLD_SCENE_H__