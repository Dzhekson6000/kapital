#include "RegionMap.h"

bool RegionMap::init()
{
	if ( !Layer::init() )
    {
        return false;
    }

	float widthScene = Director::getInstance()->getWinSize().width;
	float heightScene = Director::getInstance()->getWinSize().height;

	_positionX = widthScene /2;
	_positionY = heightScene /2;

	//сдесь рисуеться регион

	return true;
}