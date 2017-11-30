#pragma once

enum Direction_t
{
	LEFT,
	RIGHT
};

// Types of items (bones, cookies, ect)
enum Items_category
{
	COOKIE,
	BONE,
	KEY,
	WRENCH
};

enum Colour_t
{
	YELLOW,
	GREEN,
	BLUE,
	RED,
	PINK,
	ORANGE
};

struct Item_t
{
	Items_category _type;
	Colour_t _colour;
};
