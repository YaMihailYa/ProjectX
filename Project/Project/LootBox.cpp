#include "LootBox.h"

LootBox::LootBox() { Box = nullptr; }

LootBox::~LootBox() { delete Box; Box = nullptr; }

void LootBox::showBox()
{
	Box = new Static_Object(86);
}

void LootBox::changeBox()
{
}
