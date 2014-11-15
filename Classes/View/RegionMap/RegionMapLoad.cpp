#include "RegionMapLoad.h"

RegionMapLoad::RegionMapLoad()
{
	_regionMapDate = new RegionMapDate;
	_regionMapDate->_fon = FonRegionMap::create();
}

RegionMapDate* RegionMapLoad::getMapDate()
{
	return _regionMapDate;
}