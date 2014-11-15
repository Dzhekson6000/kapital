#ifndef REGION_MAP_LOAD_H_
#define REGION_MAP_LOAD_H_

#include "RegionMapDate.h"

class RegionMapLoad{

private:
	RegionMapDate* _regionMapDate;
public:
	RegionMapLoad();
	RegionMapDate* getMapDate();
};
#endif /* REGION_MAP_LOAD_H_ */