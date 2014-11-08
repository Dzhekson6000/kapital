#ifndef INTERFACE_WORLD_VIEW_H_
#define INTERFACE_WORLD_VIEW_H_


#include "cocos2d.h"

USING_NS_CC;

class InterfaceWorldView : public Layer
{
private:
	Sprite* _mainInterface;

	Sprite* _plus;
	Sprite* _minus;
	

	void clickScale(int scale);

	Size _size;

	void initPlusMinus();
	bool isClickPlus(Touch* touch);
	bool isClickMinus(Touch* touch);

	bool isBounds(Touch* event, int x, int y, int width, int height);

	//блок инфо о регионе
	Sprite* _nextButton;
	bool _createInfo;
	bool _nextRegion;
	bool isClickNext(Touch*touch);

public:
	virtual bool init();
	CREATE_FUNC(InterfaceWorldView);

	void touchEnded(Touch* touch, Event* event);
	float _scaleMap;

	void createInfoRegion(int id);
	bool getNextRegion();
};

#endif /* INTERFACE_WORLD_VIEW_H_ */