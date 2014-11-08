#ifndef FON_REGION_MAP_H_
#define FON_REGION_MAP_H_


#include "cocos2d.h"
USING_NS_CC;

class FonRegionMap : public cocos2d::Layer
{
private:
	std::vector<Sprite*> sprites;
	void createTile(float x, float y, std::string tip);
public:
	virtual bool init();
	CREATE_FUNC(FonRegionMap);
};

#endif /* FON_REGION_MAP_H_ */