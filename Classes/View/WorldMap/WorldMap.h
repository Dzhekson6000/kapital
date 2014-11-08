#ifndef WORLD_MAP_H_
#define WORLD_MAP_H_


#include "cocos2d.h"
USING_NS_CC;

class WorldMap : public cocos2d::Layer
{
private:
	Size _size;
	Sprite* _map;

	
	//����������� �������
	float _minScaleMapX;
	float _minScaleMapY;
	
	bool _moveMap;//true ���� ����� ����������
	Point _mapPoint;//���������� ��������� �����
	Point _moveMapPoint;//���������� ����� �������� �����
	bool _move;//true ���� ����� ���������

	void initMinScale();//��������� ����������� �������
	bool isClickMap(Touch* touch);//���� �� �����?

	void mapPointReset();//���������� ��������� ����� �� ���������
	void updatePosition();//��������� ��������� �����

	bool isBounds(Touch* event, int x, int y, int width, int height);

public:
	virtual bool init();
	CREATE_FUNC(WorldMap);

	bool touchBegan(Touch* touch, Event* event);
	void touchMoved(Touch* touch, Event* event);
	void touchEnded(Touch* touch, Event* event);

	void updateScaleMap(float scaleMap);//��������� ��������������� �����

	int _idSelectRegion;
	bool isSelectRegion(Touch* touch);
	int SelectRegion(float x, float y);

};

#endif /* WORLD_MAP_H_ */