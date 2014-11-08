#include "RegionMapObject.h"

RegionMapObject::RegionMapObject(PPoint* point, std::string textureName, int width, int height)
{
	this->_width = width;
	this->_height = height;
	this->_pPoint = point;
	this->_textureName = textureName;
	this->_sprite = Sprite::create("img/map/Object/" + textureName + ".png");
	this->_sprite->setPosition(point->getX(), point->getY());
}

RegionMapObject::~RegionMapObject()
{
	delete _pPoint;
}

int RegionMapObject::getWidth()
{
	return this->_width;
}

int RegionMapObject::getHeight()
{
	return this->_height;
}

void RegionMapObject::setWidth(int width)
{
	this->_width = width;
}

void RegionMapObject::setHeight(int height)
{
	this->_height = height;
}

Sprite* RegionMapObject::getTexture() 
{
	return _sprite;
}

std::string RegionMapObject::getTextureName()
{
	return _textureName;
}

void RegionMapObject::setTexture(std::string textureName) {
	this->_textureName = textureName;
	Texture2D *t= Director::getInstance()->getTextureCache()->addImage(textureName + ".png");
	this->_sprite->setTexture(t);
}