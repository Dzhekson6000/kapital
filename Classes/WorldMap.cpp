#include "WorldMap.h"

bool WorldMap::init()
{
	if ( !Layer::init() )
    {
        return false;
    }
	_size = Director::getInstance()->getWinSize();
	_size.height = _size.height - 87*(_size.width/2600);

	//применяем значение по умолчанию
	_moveMap = false;
	_idSelectRegion = 0;


	_map = Sprite::create("img/map/world_map.png");
	initMinScale();//получаем минимальный скалинг
	_map->setScale(_minScaleMapX, _minScaleMapY);
	mapPointReset();//ставим в точке по центру
	_map->setPosition(_mapPoint);
	this->addChild(_map);


	return true;
}

bool WorldMap::touchBegan(Touch *touch, Event *event)
{
	if(isClickMap(touch) )
	{
		_moveMap = true;
		_moveMapPoint = touch->getLocation();
	}
	
	return true;
}

void WorldMap::touchMoved(Touch* touch, Event* event)
{
	_move = true;
	if(_moveMap)
	{
		float deviationX = touch->getLocation().x - _moveMapPoint.x;
		float deviationY = touch->getLocation().y - _moveMapPoint.y;

		_mapPoint.x += deviationX;
		_mapPoint.y += deviationY;
		
		_moveMapPoint.x = touch->getLocation().x;
		_moveMapPoint.y = touch->getLocation().y;

		updatePosition();
		
	}
	
}

void WorldMap::touchEnded(Touch* touch, Event* event)
{
	if(_moveMap)
	{
		_moveMap = false;
	}
	_move = false;
	
}



void WorldMap::updateScaleMap(float scaleMap)
{
	_map->setScaleX(_minScaleMapX + scaleMap);
	_map->setScaleY(_minScaleMapY + scaleMap);
	updatePosition();
}

void WorldMap::initMinScale()
{
	_minScaleMapX = _size.width/_map->getContentSize().width * 0.51;
	_minScaleMapY = _size.height/_map->getContentSize().height * 0.85;
}





bool WorldMap::isClickMap(Touch* touch)
{
	float width = _size.width * 0.51;
	float height = _size.height * 0.85;
	if(isBounds(touch, _size.width*0.51/2, _size.height/2 * 1.15 , width, height) )
	{
		return true;
	}
	return false;
}

bool WorldMap::isBounds(Touch* event, int x, int y, int width, int height)
{
	if(
		event->getLocation().x > x-(width/2) && event->getLocation().x < x + (width/2) - 1 
		&&
		event->getLocation().y > y-(height/2) && event->getLocation().y < y + (height/2) - 1
	)
		return true;
	else
		return false;
}

void WorldMap::mapPointReset()
{
	_mapPoint = Point(
		_size.width*0.51/2,
		_size.height/2 * 1.15);
}

void WorldMap::updatePosition(){
	float width = _map->getContentSize().width * _map->getScaleX();
	float height = _map->getContentSize().height * _map->getScaleY();

	//это для Х
	if(_mapPoint.x > width/2)
	{
		_mapPoint.x = width/2;
	}
		
	if(_mapPoint.x < -width/2 + _size.width*0.51)
	{
		_mapPoint.x = -width/2 + _size.width*0.51;
	}
		
	//это для У
	if(_mapPoint.y + height/2 < _size.height)
	{
		_mapPoint.y = _size.height - height/2;
	}
	if(_mapPoint.y  + _size.height*0.85 - height/2 > _size.height)
	{
		_mapPoint.y = _size.height + height/2 - _size.height*0.85;
	}

	_map->setPosition(_mapPoint);
}

bool WorldMap::isSelectRegion(Touch* touch)
{
	return (isClickMap(touch) && !_move );

}

int WorldMap::SelectRegion(float x, float y)
{
	float width = _size.width * 0.51;
	float height = _size.height * 0.85;

	float xClick;
	float yClick;
	int xSelected = 0;
	int ySelected = 0;

	xClick =  x;
	yClick =  _size.height - y;

	xSelected = xClick/_map->getScaleX();//scall
	xSelected += _mapPoint.x - _size.width*0.51/2;//scrool
	float d = _mapPoint.x;
	ySelected = yClick/_map->getScaleY();

	//800x800
	//int IdRegion = ( (ySelected-1) * 800) + xSelected;
	//нужно определить ID региона по которому кликнули.
	_idSelectRegion = 1;
	CCLOG("ClickSelectRegion");
	return _idSelectRegion;
}