#ifndef WORLD_MAP_H_
#define WORLD_MAP_H_


#include "cocos2d.h"
USING_NS_CC;

class WorldMap : public cocos2d::Layer
{
private:
	Size _size;
	Sprite* _map;

	
	//минимальный скалинг
	float _minScaleMapX;
	float _minScaleMapY;
	
	bool _moveMap;//true если карта двигаеться
	Point _mapPoint;//координаты положения карты
	Point _moveMapPoint;//координаты после движения карты
	bool _move;//true если карта двигалась

	void initMinScale();//вычисляем минимальный скалинг
	bool isClickMap(Touch* touch);//клик по карте?

	void mapPointReset();//сбрасываем положение карты по умолчанию
	void updatePosition();//обвноляем положение карты

	bool isBounds(Touch* event, int x, int y, int width, int height);

public:
	virtual bool init();
	CREATE_FUNC(WorldMap);

	bool touchBegan(Touch* touch, Event* event);
	void touchMoved(Touch* touch, Event* event);
	void touchEnded(Touch* touch, Event* event);

	void updateScaleMap(float scaleMap);//обновляем масштабирование карты

	int _idSelectRegion;
	bool isSelectRegion(Touch* touch);
	int SelectRegion(float x, float y);

};

#endif /* WORLD_MAP_H_ */