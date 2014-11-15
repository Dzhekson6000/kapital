#include "RegionMapController.h"

RegionMapController::RegionMapController()
{

}

void RegionMapController::touchBegan(Touch *touch, Event *event)
{
	_moveMap = true;
	_moveMapPoint = touch->getLocation();
}

void RegionMapController::touchMoved(Touch* touch, Event* event)
{
	_move = true;
	if(_moveMap)
	{
		_mapPoint.x += touch->getLocation().x - _moveMapPoint.x;
		_mapPoint.y += touch->getLocation().y - _moveMapPoint.y;
		
		_moveMapPoint.x = touch->getLocation().x;
		_moveMapPoint.y = touch->getLocation().y;
	}
}

void RegionMapController::touchEnded(Touch* touch, Event* event)
{
	if(_moveMap)
	{
		_moveMap = false;
	}
	_move = false;
}
