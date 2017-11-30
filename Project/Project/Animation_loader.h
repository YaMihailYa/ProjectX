#pragma once
#include "Texture_loader.h"

struct Animation_t
{
	unsigned int id;
	std::vector<sf::Sprite> frames;
};

class Animation_loader
{
public:
	Animation_loader();
	~Animation_loader();

	void add(unsigned int texture_id, int countOfFrames);
	sf::Sprite getSprite(unsigned int animation_id, unsigned int frame_id);

protected:
	std::map<int, std::vector<sf::Sprite>> m_map_animations;
	unsigned int m_last_id;
};

