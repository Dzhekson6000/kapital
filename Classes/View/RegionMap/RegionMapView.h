#ifndef REGION_MAP_VIEW_H_
#define REGION_MAP_VIEW_H_


#include "cocos2d.h"
#include "RegionMapController.h";
#include "RegionMapDate.h"
#include "RegionMapLoad.h"

USING_NS_CC;

class RegionMapView : public cocos2d::Layer
{
private:
	Size _size;
	Layer* _regionMap;
	RegionMapDate* _regionMapDate;
	RegionMapController* _regionMapController;


	bool _active;

	void initTouch();
	EventListenerTouchOneByOne* _touchListener;
	
	
	void updatePosition();//обвноляем положение карты
public:
	virtual bool init();
	void initRegion(int idRegion);
	CREATE_FUNC(RegionMapView);

	virtual bool touchBegan(Touch* touch, Event* event);
	virtual void touchMoved(Touch* touch, Event* event);
	virtual void touchEnded(Touch* touch, Event* event);

	void setActive(bool active){_active = active;}

	
};

#endif /* REGION_MAP_VIEW_H_ */