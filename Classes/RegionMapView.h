#ifndef REGION_MAP_VIEW_H_
#define REGION_MAP_VIEW_H_


#include "cocos2d.h"

USING_NS_CC;

class RegionMapView : public cocos2d::Layer
{
private:
	bool _active;

	void initTouch();
	EventListenerTouchOneByOne* _touchListener;
	Size _size;

public:
	virtual bool init();
	CREATE_FUNC(RegionMapView);

	virtual bool touchBegan(Touch* touch, Event* event);
	virtual void touchMoved(Touch* touch, Event* event);
	virtual void touchEnded(Touch* touch, Event* event);

	void setActive(bool active){_active = active;}

	void initRegion(int idRegion);
};

#endif /* REGION_MAP_VIEW_H_ */