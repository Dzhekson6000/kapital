#ifndef WORLD_MAP_VIEW_H_
#define WORLD_MAP_VIEW_H_


#include "cocos2d.h"

#include "InterfaceWorldView.h"
#include "WorldMap.h"


USING_NS_CC;

class WorldMapView : public cocos2d::Layer
{
private:
	int _idSelectRegion;
	bool _active;

	InterfaceWorldView* _interface;
	WorldMap* _map;

	void initTouch();
	EventListenerTouchOneByOne* _touchListener;
	Size _size;

public:
	virtual bool init();
	CREATE_FUNC(WorldMapView);

	virtual bool touchBegan(Touch* touch, Event* event);
	virtual void touchMoved(Touch* touch, Event* event);
	virtual void touchEnded(Touch* touch, Event* event);

	void setActive(bool active){_active = active;}
};

#endif /* WORLD_MAP_VIEW_H_ */