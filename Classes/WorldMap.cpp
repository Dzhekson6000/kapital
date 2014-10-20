#include "WorldMap.h"

bool WorldMap::init()
{
	if ( !Layer::init() )
    {
        return false;
    }

	_size = Director::getInstance()->getWinSize();
	_size.height = _size.height - 87*(_size.width/2600);
	
	initFonAndMap();
	_action = true;
	_moveMap = false;
	_scaleMap = 0;

	initPlusMinus();
	initTouch();

	return true;
}

bool WorldMap::touchBegan(Touch *touch, Event *event)
{
	if(_action)
	{
		if(isClickMap(touch) )
			{
				_moveMap = true;
				_moveMapPoint = touch->getLocation();
			}
	}
	return true;
}

void WorldMap::touchMoved(Touch* touch, Event* event)
{
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
	if(_action)
	{
		if(isClickPlus(touch) )
		{
			clickPlus();
		}

		if(isClickMinus(touch) )
		{
			clickMinus();
		}
		if(_moveMap)
		{
			_moveMap = false;
		}
	}
}

void WorldMap::clickPlus()
{
	_scaleMap+=1;
	updateScaleMap();
}

void WorldMap::clickMinus()
{
	if(_scaleMap > 0)_scaleMap-=1;
	updateScaleMap();
}

void WorldMap::updateScaleMap()
{
	_map->setScaleX(_minScaleMapX + _scaleMap);
	_map->setScaleY(_minScaleMapY + _scaleMap);
	updatePosition();
}

void WorldMap::initTouch()
{
	_touchListener = EventListenerTouchOneByOne::create();
	_touchListener->onTouchBegan = CC_CALLBACK_2(WorldMap::touchBegan,this);
	_touchListener->onTouchMoved = CC_CALLBACK_2(WorldMap::touchMoved, this);
	_touchListener->onTouchEnded = CC_CALLBACK_2(WorldMap::touchEnded,this);
	getEventDispatcher()->addEventListenerWithFixedPriority(_touchListener, 100);
}

void WorldMap::initMinScale()
{
	_minScaleMapX = _size.width/_map->getContentSize().width * 0.51;
	_minScaleMapY = _size.height/_map->getContentSize().height * 0.85;
}

void WorldMap::initPlusMinus()
{
	_plus = Sprite::create("img/map/plus.png");
	_minus = Sprite::create("img/map/minus.png");

	_plus->setScaleX(_size.width* 0.017/ _minus->getContentSize().width );
	_plus->setScaleY(_size.height* 0.027/ _minus->getContentSize().height );
	_plus->setPosition(Point(_size.width*0.49, _size.height*0.1) );
	this->addChild(_plus);

	_minus->setScaleX(_size.width* 0.017/ _minus->getContentSize().width );
	_minus->setScaleY(_size.height* 0.027/ _minus->getContentSize().height );
	_minus->setPosition(Point(_size.width*0.49, _size.height*0.066) );
	this->addChild(_minus);
}

bool WorldMap::isClickPlus(Touch* touch)
{
	float width = _plus->getContentSize().width * _plus->getScaleX();
	float height = _plus->getContentSize().height * _plus->getScaleY();
	if(isBounds(touch, _plus->getPositionX(), _plus->getPositionY(), width, height) )
	{
		return true;
	}
	return false;
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

bool WorldMap::isClickMinus(Touch* touch)
{
	float width = _minus->getContentSize().width * _minus->getScaleX();
	float height = _minus->getContentSize().height * _minus->getScaleY();
	if(isBounds(touch, _minus->getPositionX(), _minus->getPositionY(), width, height) )
	{
		return true;
	}
	return false;
}


void WorldMap::initFonAndMap()
{
	_map = Sprite::create("img/map/world_map.png");
	initMinScale();
	_map->setScaleX(_minScaleMapX);
	_map->setScaleY(_minScaleMapY);
	mapPointReset();
	_map->setPosition(_mapPoint);
	this->addChild(_map,-1);

	_fon = Sprite::create("img/map/WorldRageFon.png");
	_fon->setScaleX(_size.width/_fon->getContentSize().width);
	_fon->setScaleY(_size.height /_fon->getContentSize().height);
	_fon->setPosition(Point(_size.width/2, _size.height/2) );
	this->addChild(_fon, 0);
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