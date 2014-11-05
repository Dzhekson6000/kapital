#include "RegionMapObject.h"

bool RegionMapObject::init()
{
	if ( !Layer::init() )
    {
        return false;
    }
}


void RegionMapObject::createTile(float x, float y, std::string tip)
{
	Sprite* newSprite = Sprite::create("img/map/Object/"+tip+".png");
	newSprite->setScaleX(1);
	newSprite->setScaleY(1);

	//x1 = x – z;
	//y1 = (x + z) * 0.5;
	newSprite->setPosition(Point(x-y, (x+y)/2) );


	this->addChild(newSprite);
}