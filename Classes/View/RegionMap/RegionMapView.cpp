#include "RegionMapView.h"

bool RegionMapView::init()
{
	if ( !Layer::init() )
    {
        return false;
    }

	_regionMap = Layer::create();

	this->addChild(_regionMap);
	initTouch();

	return true;
}

void RegionMapView::initRegion(int idRegion)
{
	_fonRegionMap = FonRegionMap::create();
	_regionMap->addChild(_fonRegionMap);
}

void RegionMapView::initTouch()
{
	_touchListener = EventListenerTouchOneByOne::create();
	_touchListener->onTouchBegan = CC_CALLBACK_2(RegionMapView::touchBegan,this);
	_touchListener->onTouchMoved = CC_CALLBACK_2(RegionMapView::touchMoved, this);
	_touchListener->onTouchEnded = CC_CALLBACK_2(RegionMapView::touchEnded,this);
	getEventDispatcher()->addEventListenerWithFixedPriority(_touchListener, 100);
}

bool RegionMapView::touchBegan(Touch *touch, Event *event)
{
	if(!_active)return true;
	_moveMap = true;
	_moveMapPoint = touch->getLocation();
	return true;
}

void RegionMapView::touchMoved(Touch* touch, Event* event)
{
	if(!_active)return;

	_move = true;
	if(_moveMap)
	{
		float deviationX = touch->getLocation().x - _moveMapPoint.x;
		float deviationY = touch->getLocation().y - _moveMapPoint.y;

		_mapPoint.x += deviationX;
		_mapPoint.y += deviationY;
		
		_moveMapPoint.x = touch->getLocation().x;
		_moveMapPoint.y = touch->getLocation().y;

		
		updatePosition();
	}
}

void RegionMapView::touchEnded(Touch* touch, Event* event)
{
	if(!_active)return;
	if(_moveMap)
	{
		_moveMap = false;
	}
	_move = false;
}

void RegionMapView::updatePosition()
{
	_regionMap->setPosition(_mapPoint);
}