#ifndef REGION_MAP_OBJECT_H_
#define REGION_MAP_OBJECT_H_


#include "cocos2d.h"
USING_NS_CC;

class RegionMapObject : public cocos2d::Layer
{
private:
	void createTile(float x, float y, std::string tip);
public:
	virtual bool init();
	CREATE_FUNC(RegionMapObject);
};

#endif /* REGION_MAP_OBJECT_H_ */