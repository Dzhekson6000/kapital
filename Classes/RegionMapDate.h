#ifndef REGION_MAP_DATE_H_
#define REGION_MAP_DATE_H_

#include "RegionMapObject.h"
#include "List.h"

class RegionMapDate{
public:
	List<RegionMapObject*>* objects;
	~RegionMapDate(){
		delete objects;
	}
};
#endif /* REGION_MAP_DATE_H_ */