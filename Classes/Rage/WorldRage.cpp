#include "WorldRage.h"


bool WorldRage::init()
{
	if ( !Layer::init() )  {
        return false;
    }
	_id = 1;
	_size = Director::getInstance()->getWinSize();
	
	_worldMapView = WorldMapView::create();
	this->addChild(_worldMapView);
	_worldMapView->setVisible(false);

	_regionMapView = RegionMapView::create();
	_regionMapView->initRegion(1);
	this->addChild(_regionMapView);

	this->schedule(schedule_selector(WorldRage::update),1.00f);

	return true;
}

void WorldRage::setActive(bool active)
{
	if(_worldMapView->isVisible())
	{
		_worldMapView->setActive(active);
	} else {
		_worldMapView->setActive(!active);
	}

	if(_regionMapView->isVisible())
	{
		_regionMapView->setActive(active);
	} else {
		_regionMapView->setActive(!active);
	}
}

void WorldRage::update(float dt)
{
	
}