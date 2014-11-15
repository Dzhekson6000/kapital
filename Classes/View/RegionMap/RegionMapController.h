#ifndef REGION_MAP_CONTROLLER_H_
#define REGION_MAP_CONTROLLER_H_

#include "cocos2d.h"
USING_NS_CC;

class RegionMapController
{
private:
	bool _moveMap;//true ���� ����� ����������
	bool _move;//true ���� ����� ���������
	Point _moveMapPoint;//���������� ����� �������� �����

	Size _size;
public:
	RegionMapController();
	void touchBegan(Touch* touch, Event* event);
	void touchMoved(Touch* touch, Event* event);
	void touchEnded(Touch* touch, Event* event);

	float _ScaleMap;
	Point _mapPoint;//���������� ��������� �����
};

#endif /* REGION_MAP_CONTROLLER_H_ */