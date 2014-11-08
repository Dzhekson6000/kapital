#ifndef WORLD_RAGE_H_
#define WORLD_RAGE_H_

#include "Tools/Rage.h"
#include "View/WorldMap/WorldMapView.h"
#include "View/RegionMap/RegionMapView.h"

USING_NS_CC;

class WorldRage : public Rage
{
private:
	WorldMapView * _worldMapView;
	RegionMapView * _regionMapView;
public:
	virtual bool init();
	void setActive(bool active);
	CREATE_FUNC(WorldRage);

	void update(float dt);
};

#endif /* WORLD_RAGE_H_ */