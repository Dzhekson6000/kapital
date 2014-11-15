#ifndef REGION_MAP_CONTROLLER_H_
#define REGION_MAP_CONTROLLER_H_

#include "cocos2d.h"
USING_NS_CC;

class RegionMapController
{
private:
	bool _moveMap;//true если карта двигаеться
	bool _move;//true если карта двигалась
	Point _moveMapPoint;//координаты после движения карты

	Size _size;
public:
	RegionMapController();
	void touchBegan(Touch* touch, Event* event);
	void touchMoved(Touch* touch, Event* event);
	void touchEnded(Touch* touch, Event* event);

	float _ScaleMap;
	Point _mapPoint;//координаты положения карты
};

#endif /* REGION_MAP_CONTROLLER_H_ */