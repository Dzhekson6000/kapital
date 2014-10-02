#include "WorldRage.h"


bool WorldRage::init()
{
	if ( !Layer::init() )  {
        return false;
    }
	_id = 1;
	_size = Director::getInstance()->getWinSize();

	Sprite * _fon = Sprite::create("img/world_map.png");
	this->addChild(_fon,0);
	
	_fon->setScaleX(0.5);
	_fon->setScaleY(0.5);
	_fon->setPosition(Point(_size.width/2, _size.height/2));

	return true;
}