#pragma once
#include "Static_Object.h"

class LootBox
{
public:
	LootBox();
	~LootBox();

	void showBox();
	void changeBox();


private:
	Static_Object* Box;

};