#ifndef WORLD_MAP_H_
#define WORLD_MAP_H_


#include "cocos2d.h"
USING_NS_CC;

class WorldMap : public cocos2d::Layer
{
private:
	Sprite* _map;
	Sprite* _fon;
	Sprite* _plus;
	Sprite* _minus;

	Size _size;

	float _minScaleMapX;
	float _minScaleMapY;
	float _scaleMap;
	bool _moveMap;
	Point _moveMapPoint;
	Point _mapPoint;

	EventListenerTouchOneByOne* _touchListener;
	bool _action;

	void initFonAndMap();
	void initMinScale();
	void initPlusMinus();
	void initTouch();

	bool isClickPlus(Touch* touch);
	bool isClickMinus(Touch* touch);
	bool isClickMap(Touch* touch);

	void clickPlus();
	void clickMinus();

	void updateScaleMap();
	void mapPointReset();
	void updatePosition();

	bool isBounds(Touch* event, int x, int y, int width, int height);
public:
	virtual bool init();
	CREATE_FUNC(WorldMap);

	virtual bool touchBegan(Touch* touch, Event* event);
	virtual void touchMoved(Touch* touch, Event* event);
	virtual void touchEnded(Touch* touch, Event* event);

};

#endif /* WORLD_MAP_H_ */