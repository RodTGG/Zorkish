#include "stdafx.h"
#include "BlackBoard.h"

BlackBoard::BlackBoard()
{
}

BlackBoard::~BlackBoard()
{
}

void BlackBoard::SendMessage(Player* aP, std::string aMessage)
{
	for (unsigned int i = 0; i < aP->getLocation()->fCharacters->fChars.size(); i++)
	{
		if (aP->getLocation()->fCharacters->fChars[i]->isSubscribed())
		{
			aP->getLocation()->fCharacters->fChars[i]->addBMessage(aMessage);
		}
	}
	for (unsigned int i = 0; i < aP->getLocation()->fInventory->fItems.size(); i++)
	{
		if (aP->getLocation()->fInventory->fItems[i]->isSubscribed())
		{
			aP->getLocation()->fInventory->fItems[i]->addBMessage(aMessage);
		}
	}
	for (unsigned int i = 0; i < aP->getInventory()->fItems.size(); i++)
	{
		if (aP->getInventory()->fItems[i]->isSubscribed())
		{
			aP->getInventory()->fItems[i]->addBMessage(aMessage);
		}
	}
}