#pragma once
#ifndef LOGO_H_
#define LOGO_H_

#include "cocos2d.h"
#include "AuthorizationScene.h"


USING_NS_CC;

class LogoScene : public cocos2d::Layer
{
private:
	Sprite* _logoImage;
	float _time;
public:
	static cocos2d::Scene* createScene();
	virtual bool init();
	void timeout(float dt);
	CREATE_FUNC(LogoScene);
};

#endif /* LOGO_H_ */