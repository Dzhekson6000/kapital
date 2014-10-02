#include "ChatRage.h"

bool ChatRage::init()
{
	if ( !Layer::init() )  {
        return false;
    }
	_id = 0;
	_size = Director::getInstance()->getWinSize();

	auto sprite = Sprite::create("img/ScreenProjectFon.png");
	sprite->setScaleX(_size.width/sprite->getContentSize().width);
	sprite->setScaleY(_size.height/sprite->getContentSize().height);
	sprite->setPosition(Point(_size.width/2, _size.height/2));
	this->addChild(sprite, 0);

	return true;
}