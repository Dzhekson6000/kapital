#ifndef AUTHORIZATION_SCENE_H_
#define AUTHORIZATION_SCENE_H_

#include "cocos2d.h"
#include "MainScene.h"

USING_NS_CC;

class AuthorizationScene : public cocos2d::Layer
{
private:
	std::string _key;
	int _id;

	bool isAuthorization();
	void auth();
	void checkAutorization();

	EventListenerTouchOneByOne* _touchListener;
	Scene* _scene;
public:
	static AuthorizationScene* create();
	virtual bool init();
	
	Scene* getScene() {return _scene;}

	virtual bool touchBegan(Touch* touch, Event* event);
	virtual void touchMoved(Touch* touch, Event* event);
	virtual void touchEnded(Touch* touch, Event* event);
};

#endif /* AUTHORIZATION_SCENE_H_ */