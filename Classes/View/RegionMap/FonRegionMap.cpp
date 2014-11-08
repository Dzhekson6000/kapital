#include "FonRegionMap.h"

bool FonRegionMap::init()
{
	if ( !Layer::init() )
    {
        return false;
    }

	//draw fon region
	for(int i = -20; i < 20; i++)
		for(int j = -20; j < 20; j++)
			createTile(100.5*i ,100.5*j,"herb");
	return true;
}

void FonRegionMap::createTile(float x, float y, std::string tip)
{
	Sprite* newSprite = Sprite::create("img/map/soil/"+tip+".png");
	newSprite->setScaleX(1);
	newSprite->setScaleY(1);

	//x1 = x – z;
	//y1 = (x + z) * 0.5;
	newSprite->setPosition(Point(x-y, (x+y)/2) );


	this->addChild(newSprite);
	sprites.push_back(newSprite);
}