#include "RegionMapView.h"

bool RegionMapView::init()
{
	if ( !Layer::init() )
    {
        return false;
    }

	_regionMapController = new RegionMapController();
	_regionMap = Layer::create();

	this->addChild(_regionMap);
	initTouch();

	return true;
}

void RegionMapView::initRegion(int idRegion)
{
	_regionMapDate = (new RegionMapLoad())->getMapDate();
	_regionMap->addChild(_regionMapDate->_fon);
}

void RegionMapView::updatePosition()
{
	_regionMap->setPosition(_regionMapController->_mapPoint);
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
	_regionMapController->touchBegan(touch, event);
	return true;
}

void RegionMapView::touchMoved(Touch* touch, Event* event)
{
	if(!_active)return;
	_regionMapController->touchMoved(touch, event);
	updatePosition();
}

void RegionMapView::touchEnded(Touch* touch, Event* event)
{
	if(!_active)return;
	_regionMapController->touchEnded(touch, event);
}