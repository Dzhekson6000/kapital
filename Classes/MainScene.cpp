#include "MainScene.h"


MainScene* MainScene::create(int id, std::string key)
{
	MainScene* scene = new MainScene();
	if(scene && scene->init(id, key)){
		return (MainScene*)scene->autorelease();
	}
	CC_SAFE_DELETE(scene);
	return scene;
}

CCScene* MainScene::getScene() const {
	return _scene;
}

bool MainScene::init(int id, std::string key) {
	if ( !Layer::init() )  {
        return false;
    }

	_key = key;
	_scene = Scene::create();
	_scene->addChild(this);


	scroller = Scroller::create();
	this->addChild(scroller);

	scroller->addRage(ChatRage::create() );
	scroller->addRage(WorldRage::create() );
	scroller->addRage(ProfilRage::create() );
	
	
	return true;
}