#include "WorldMap.h"

bool WorldMap::init()
{
	if ( !Layer::init() )
    {
        return false;
    }

	float widthScene = Director::getInstance()->getWinSize().width;
	float heightScene = Director::getInstance()->getWinSize().height;

	_map  = Sprite::create("img/world_map.png");
	_map->setScaleX((widthScene/2)/_map->getContentSize().width);
	_map->setScaleY(heightScene/_map->getContentSize().height * 0.8);
	_map->setPosition(Point(
		widthScene/4,
		heightScene/2 * 1.2)
		);

	this->addChild(_map,1);
	
	return true;
}