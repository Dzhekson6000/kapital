#ifndef REGION_MAP_OBJECT_H_
#define REGION_MAP_OBJECT_H_


#include "cocos2d.h"
#include "PPoint.h"
USING_NS_CC;

class RegionMapObject
{
private:
	std::string _textureName;
	int _width;
	int _height;

protected:
	PPoint* _pPoint;
	Sprite* _sprite;

public:
	//конструкторы и деструкторы
	RegionMapObject(){};
	RegionMapObject(PPoint* point, std::string textureName, int width, int height);
	virtual ~RegionMapObject();

	//функции по размеру
	int getWidth();
	int getHeight();
	void setWidth(int width);
	void setHeight(int height);

	//функции по текстуре
	Sprite* getTexture();
	void setTexture(std::string textureName);
	std::string getTextureName();


};

#endif /* REGION_MAP_OBJECT_H_ */