#include "InterfaceWorldView.h"

bool InterfaceWorldView::init()
{
	if ( !Layer::init() )
    {
        return false;
    }

	_size = Director::getInstance()->getWinSize();
	_size.height = _size.height - 87*(_size.width/2600);

	_scaleMap = 0;
	_createInfo = false;
	_nextRegion = false;

	_mainInterface = Sprite::create("img/map/WorldRageFon.png");
	_mainInterface->setScaleX(_size.width/_mainInterface->getContentSize().width);
	_mainInterface->setScaleY(_size.height /_mainInterface->getContentSize().height);
	_mainInterface->setPosition(Point(_size.width/2, _size.height/2) );
	this->addChild(_mainInterface, 0);

	_nextButton = Sprite::create("img/map/ButtonGo.png");
	_nextButton->setScaleX(_size.width/_mainInterface->getContentSize().width);
	_nextButton->setScaleY(_size.height /_mainInterface->getContentSize().height);
	_nextButton->setPosition(Point(_size.width-(_nextButton->getContentSize().width*_nextButton->getScaleX()/2) - 10, _nextButton->getContentSize().height/2 + 10) );
	_nextButton->setVisible(false);
	this->addChild(_nextButton);

	initPlusMinus();

	return true;
}

void InterfaceWorldView::initPlusMinus()
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



void InterfaceWorldView::touchEnded(Touch* touch, Event* event)
{
	if(isClickPlus(touch) )
	{
		clickScale(+1);
	}

	if(isClickMinus(touch) )
	{
		clickScale(-1);
	}

	if(_createInfo &&isClickNext(touch) )
	{
		_nextRegion = true;
	}
	
}

bool InterfaceWorldView::isClickPlus(Touch* touch)
{
	float width = _plus->getContentSize().width * _plus->getScaleX();
	float height = _plus->getContentSize().height * _plus->getScaleY();
	if(isBounds(touch, _plus->getPositionX(), _plus->getPositionY(), width, height) )
	{
		return true;
	}
	return false;
}

bool InterfaceWorldView::isClickMinus(Touch* touch)
{
	float width = _minus->getContentSize().width * _minus->getScaleX();
	float height = _minus->getContentSize().height * _minus->getScaleY();
	if(isBounds(touch, _minus->getPositionX(), _minus->getPositionY(), width, height) )
	{
		return true;
	}
	return false;
}

bool InterfaceWorldView::isBounds(Touch* event, int x, int y, int width, int height)
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

bool InterfaceWorldView::isClickNext(Touch* touch)
{
	float width = _nextButton->getContentSize().width * _nextButton->getScaleX();
	float height = _nextButton->getContentSize().height * _nextButton->getScaleY();
	if(isBounds(touch, _nextButton->getPositionX(), _nextButton->getPositionY(), width, height) )
	{
		CCLOG("ClickNext");
		return true;
	}
	return false;
}

void InterfaceWorldView::clickScale(int scale)
{
	if(_scaleMap + scale < 0)return;
	_scaleMap+=scale;
}

void InterfaceWorldView::createInfoRegion(int id)
{
	//загружаем информацию о регионе.
	_nextButton->setVisible(true);
	_createInfo = true;//говорим что информация создана
}

bool InterfaceWorldView::getNextRegion()
{
	return _nextRegion;
}