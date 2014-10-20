#ifndef WORLD_RAGE_H_
#define WORLD_RAGE_H_

#include "Rage.h"
#include "MapView.h"

USING_NS_CC;

class WorldRage : public Rage
{
public:
	MapView * _mapView;
	virtual bool init();
	CREATE_FUNC(WorldRage);
};

#endif /* WORLD_RAGE_H_ */