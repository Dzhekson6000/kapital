#ifndef MAP_VIEW_H_
#define MAP_VIEW_H_


#include "cocos2d.h"

#include "WorldMap.h"
#include "RegionMap.h"

USING_NS_CC;

class MapView : public cocos2d::Layer
{
private:
	Layer* _worldMap;
	Layer* _regionMap;
public:
	virtual bool init();
	CREATE_FUNC(MapView);
};

#endif /* MAP_VIEW_H_ */