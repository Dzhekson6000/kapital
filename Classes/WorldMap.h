#ifndef WORLD_MAP_H_
#define WORLD_MAP_H_


#include "cocos2d.h"
USING_NS_CC;

class WorldMap : public cocos2d::Layer
{
private:
	Sprite* _map;
public:
	virtual bool init();
	CREATE_FUNC(WorldMap);
};

#endif /* WORLD_MAP_H_ */