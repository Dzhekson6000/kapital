#include "WorldRage.h"


bool WorldRage::init()
{
	if ( !Layer::init() )  {
        return false;
    }
	_id = 1;
	_size = Director::getInstance()->getWinSize();
	
	_mapView = MapView::create();
	this->addChild(_mapView);

	return true;
}