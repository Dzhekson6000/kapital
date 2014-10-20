#include "MapView.h"

bool MapView::init()
{
	if ( !Layer::init() )
    {
        return false;
    }


	_worldMap = WorldMap::create();
	_regionMap = RegionMap::create();
	this->addChild(_worldMap);
	return true;
}