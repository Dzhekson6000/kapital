#include "RegionMapView.h"

bool RegionMapView::init()
{
	if ( !Layer::init() )
    {
        return false;
    }
	initTouch();

	return true;
}

void RegionMapView::initRegion(int idRegion)
{

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
	return true;
}

void RegionMapView::touchMoved(Touch* touch, Event* event)
{
	if(!_active)return;
}

void RegionMapView::touchEnded(Touch* touch, Event* event)
{
	if(!_active)return;

}