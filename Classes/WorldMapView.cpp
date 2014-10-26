#include "WorldMapView.h"

bool WorldMapView::init()
{
	if ( !Layer::init() )
    {
        return false;
    }
	initTouch();
	_idSelectRegion = 0;

	_size = Director::getInstance()->getWinSize();
	_size.height = _size.height - 87*(_size.width/2600);

	_interface = InterfaceWorldView::create();
	addChild(_interface);

	_map = WorldMap::create();
	addChild(_map,-1);

	return true;
}

void WorldMapView::initTouch()
{
	_touchListener = EventListenerTouchOneByOne::create();
	_touchListener->onTouchBegan = CC_CALLBACK_2(WorldMapView::touchBegan,this);
	_touchListener->onTouchMoved = CC_CALLBACK_2(WorldMapView::touchMoved, this);
	_touchListener->onTouchEnded = CC_CALLBACK_2(WorldMapView::touchEnded,this);
	getEventDispatcher()->addEventListenerWithFixedPriority(_touchListener, 100);
}

bool WorldMapView::touchBegan(Touch *touch, Event *event)
{
	if(!_active)return true;
	_map->touchBegan(touch, event);
	return true;
}

void WorldMapView::touchMoved(Touch* touch, Event* event)
{
	if(!_active)return;
	_map->touchMoved(touch, event);
}

void WorldMapView::touchEnded(Touch* touch, Event* event)
{
	if(!_active)return;
	_interface->touchEnded(touch, event);

	_map->updateScaleMap(_interface->_scaleMap);

	if(_map->isSelectRegion(touch))
	{
		_idSelectRegion = _map->SelectRegion(touch->getLocation().x, touch->getLocation().y);
		_interface->createInfoRegion(_idSelectRegion);

	} else {
		_map->touchEnded(touch, event);
	}
}