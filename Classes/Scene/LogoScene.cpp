#include "LogoScene.h"


Scene* LogoScene::createScene()
{
	auto scene = Scene::create();
	auto layer = LogoScene::create();
	scene->addChild(layer);
	return scene;
}

bool LogoScene::init()
{
	_time = 0;

	if ( !Layer::init() )
    {
        return false;
    }

	_logoImage  = Sprite::create("img/logo.png");
	_logoImage->setScaleX(Director::getInstance()->getWinSize().width/_logoImage->getContentSize().width/2);
	_logoImage->setScaleY(Director::getInstance()->getWinSize().height/_logoImage->getContentSize().height/2);
	_logoImage->setPosition(Point(
		Director::getInstance()->getWinSize().width/2,
		Director::getInstance()->getWinSize().height/2)
		);
	this->addChild(_logoImage,0);


	this->schedule(schedule_selector(LogoScene::timeout),1.00f);//таймер до завершение показа логотипа
	
	return true;
}

void LogoScene::timeout(float dt)
{
	_time+=dt;
	if(_time > 0.5)
	{
		Director::getInstance()->pushScene(AuthorizationScene::create()->getScene());//переходим на главное окно
	}

}