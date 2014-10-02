#include "AuthorizationScene.h"

AuthorizationScene* AuthorizationScene::create()
{

	AuthorizationScene* scene = new AuthorizationScene();
	if(scene && scene->init()){
		return (AuthorizationScene*)scene->autorelease();
	}
	CC_SAFE_DELETE(scene);
	return scene;
}


bool AuthorizationScene::init()
{
	if ( !Layer::init() )
    {
        return false;
    }
	_scene = Scene::create();
	_scene->addChild(this);
	
	_touchListener = EventListenerTouchOneByOne::create();
	_touchListener->onTouchBegan = CC_CALLBACK_2(AuthorizationScene::touchBegan,this);
	_touchListener->onTouchMoved = CC_CALLBACK_2(AuthorizationScene::touchMoved, this);
	_touchListener->onTouchEnded = CC_CALLBACK_2(AuthorizationScene::touchEnded,this);
	getEventDispatcher()->addEventListenerWithFixedPriority(_touchListener, 100);

	return true;
}

bool AuthorizationScene::isAuthorization()
{
	return true;
}

void AuthorizationScene::checkAutorization(){
	if(isAuthorization()){
		Director::getInstance()->pushScene(MainScene::create(1, _key)->getScene());//переходим на главное окно
		getEventDispatcher()->removeEventListener(_touchListener);
	}else{
		auth();
	}
}

void AuthorizationScene::auth()
{
	_key = "";
	//тут авторизация
}

bool AuthorizationScene::touchBegan(Touch *touch, Event *event)
{
	return true;
}

void AuthorizationScene::touchMoved(Touch* touch, Event* event)
{

}

void AuthorizationScene::touchEnded(Touch* touch, Event* event)
{
	checkAutorization();
}