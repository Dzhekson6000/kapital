#ifndef SCROLLER_H_
#define SCROLLER_H_

#include "cocos2d.h"
#include "Rage.h"
#include "View/MenuView.h"
USING_NS_CC;

class Scroller : public cocos2d::Layer
{
private:
	void initTouch();
	EventListenerTouchOneByOne* _touchListener;

	Size _size;
	Layer* _scroll;

	bool _moved;
	float _xMoved;
	float _positionX;

	std::vector<Rage*> _rageList;
	MenuView* _menuView;
	void goToRage(int n);
	void updateActive();
public:
	void addRage(Rage* rage, int n);
	virtual bool touchBegan(Touch* touch, Event* event);
	virtual void touchMoved(Touch* touch, Event* event);
	virtual void touchEnded(Touch* touch, Event* event);
	virtual bool init();
	
	CREATE_FUNC(Scroller);
};


#endif /* SCROLLER_H_ */