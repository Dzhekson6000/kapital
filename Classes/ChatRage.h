#ifndef CHAT_RAGE_H_
#define CHAT_RAGE_H_

#include "Rage.h"

USING_NS_CC;

class ChatRage : public Rage
{
public:
	virtual bool init();
	CREATE_FUNC(ChatRage);
};

#endif /* CHAT_RAGE_H_ */