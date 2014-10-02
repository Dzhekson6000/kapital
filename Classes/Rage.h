#ifndef RAGE_H_
#define RAGE_H_

#include "cocos2d.h"

USING_NS_CC;

class Rage : public cocos2d::Layer
{
private:

protected:
	Size _size;
	int _id;
public:
	int getId();
	
};

#endif /* RAGE_H_ */