#ifndef CHAT_RAGE_H_
#define CHAT_RAGE_H_

#include "Tools/Rage.h"

USING_NS_CC;

#include "cocos-ext.h"

class ChatRage : public Rage
{
public:
	virtual bool init();
	CREATE_FUNC(ChatRage);
};

#endif /* CHAT_RAGE_H_ */