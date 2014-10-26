#include "Scroller.h"


bool Scroller::init()
{

	if ( !Layer::init() )  {
        return false;
    }
	
	_size = Director::getInstance()->getWinSize();
	_positionX = 0;
	_moved = false;
	_menuView = MenuView::create();

	_scroll = Layer::create();
	_scroll->setPosition(Point(0,0));
	this->addChild(_scroll);

	auto touchListener = EventListenerTouchOneByOne::create();
	touchListener->onTouchBegan = CC_CALLBACK_2(Scroller::touchBegan,this);
	touchListener->onTouchMoved = CC_CALLBACK_2(Scroller::touchMoved, this);
	touchListener->onTouchEnded = CC_CALLBACK_2(Scroller::touchEnded,this);
	getEventDispatcher()->addEventListenerWithFixedPriority(touchListener, 100);

	this->addChild(_menuView);
	return true;
}

void Scroller::addRage(Rage* rage, int n)
{
	rage->setPositionX( _size.width*rage->getId() );
	_scroll->addChild(rage, n);
	_rageList.push_back(rage);
}

bool Scroller::touchBegan(Touch* touch, Event* event)
{
	if( (touch->getLocation().x < 50 || touch->getLocation().x >  _size.width-50) && !_moved)
	{
		_moved = true;
		_xMoved = touch->getLocation().x;
	}
	return true;
}

void Scroller::touchMoved(Touch* touch, Event* event)
{

	if(touch->getLocation().x < 0 || touch->getLocation().x > _size.width) return;

	if(_moved)
	{
		_positionX -= touch->getLocation().x - _xMoved;
		_scroll->setPositionX(-_positionX);
		_xMoved = touch->getLocation().x;
		
	}

}

void Scroller::touchEnded(Touch* touch, Event* event)
{
	
	int n = floor(_positionX / _size.width);
	float remain = _positionX - _size.width*n;
	if(remain > _size.width/2)
	{//вправо
		if( (int)_rageList.size() > n+1 )
		{
			_positionX = _size.width*(n+1);
		} else {
			_positionX = _size.width*((int)_rageList.size()-1);
		}
	}else{//влево
		if(n<0){n=0;}
		_positionX = _size.width*n;
	}
	_scroll->setPositionX(-_positionX);
	_moved = false;
	_menuView->onSelect(floor(_positionX / _size.width));

	if(_menuView->isSelectedMenu(touch->getLocation().y) )
	{
		goToRage(_menuView->selectMenuItem(touch->getLocation().x));
	}
	updateActive();
}

void Scroller::goToRage(int n)
{
	_positionX = _size.width*n;
	_menuView->onSelect(n);
	_scroll->setPositionX(-_positionX);
}

void Scroller::updateActive()
{
	int n = floor(_positionX / _size.width);

	
	for ( int i=0; i< _rageList.size(); ++i )
	{
		if(_rageList[i]->getId() == n)
		{
			_rageList[i]->setActive(true);
		} else {
			_rageList[i]->setActive(false);
		}
	}

}