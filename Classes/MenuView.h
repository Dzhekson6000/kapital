#ifndef MENU_VIEW_H_
#define MENU_VIEW_H_

#include "cocos2d.h"
USING_NS_CC;

class MenuView : public cocos2d::Layer
{
	Size _size;
	std::vector<std::string> _menuLabel;
	std::vector<Label*> _menuList;
	Sprite* _fon;
	int _idSelect;
public:
	int getMenuN();
	void onSelect(int id);
	boolean isSelectedMenu(float y);
	int selectMenuItem(float x);

	virtual bool init();
	CREATE_FUNC(MenuView);
};

#endif /* MENU_VIEW_H_ */