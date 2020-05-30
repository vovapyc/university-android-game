#ifndef __GAMEOVER_H__
#define __GAMEOVER_H__


#include "cocos2d.h"


class GameOver : public cocos2d::Layer {
public:
    static cocos2d::Scene *createScene();
    void GoToGameScene(Ref *pSender);
    void GoToMainMenu(Ref *pSender);

    virtual bool init();

    CREATE_FUNC(GameOver);
};


#endif // __GAMEOVER_H__