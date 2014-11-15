#ifndef REGION_MAP_DATE_H_
#define REGION_MAP_DATE_H_

#include "RegionMapObject.h"
#include "FonRegionMap.h"
#include "Tools/List.h"

class RegionMapDate{
public:
	List<RegionMapObject*>* objects;
	FonRegionMap* _fon;
	~RegionMapDate(){
		delete objects;
	}
};
#endif /* REGION_MAP_DATE_H_ */