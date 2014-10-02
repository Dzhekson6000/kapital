#ifndef SCROLLER_H_
#define SCROLLER_H_

#include "cocos2d.h"
#include "Rage.h"
#include "MenuView.h";
USING_NS_CC;

class Scroller : public cocos2d::Layer
{
private:
	Size _size;
	Layer* _scroll;

	bool _moved;
	float _xMoved;
	float _positionX;

	std::vector<Rage*> _rageList;
	MenuView* _menuView;
	void goToRage(int n);
public:
	void addRage(Rage* rage);
	virtual bool touchBegan(Touch* touch, Event* event);
	virtual void touchMoved(Touch* touch, Event* event);
	virtual void touchEnded(Touch* touch, Event* event);
	virtual bool init();
	
	CREATE_FUNC(Scroller);
};


#endif /* SCROLLER_H_ */