#pragma once
#ifndef MAIN_SCENE_H_
#define MAIN_SCENE_H_

#include "cocos2d.h"
#include "Scroller.h"
#include "ProfilRage.h"
#include "ChatRage.h"
#include "WorldRage.h"

USING_NS_CC;
class MainScene : public cocos2d::Layer
{
private:
	std::string _key;
	Scroller* scroller;


	Scene* _scene;
public:



	static MainScene* create(int id, std::string key);
	virtual bool init(int id, std::string key);
	Scene* getScene() const;
};

#endif /* MAIN_SCENE_H_ */