#ifndef REGION_MAP_H_
#define REGION_MAP_H_


#include "cocos2d.h"
USING_NS_CC;

class RegionMap : public cocos2d::Layer
{
private:
	float _positionX;
	float _positionY;
	int _regionId;
public:
	virtual bool init();
	CREATE_FUNC(RegionMap);
};

#endif /* REGION_MAP_H_ */