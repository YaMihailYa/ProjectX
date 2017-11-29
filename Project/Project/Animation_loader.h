#pragma once

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

protected:
	std::vector<Animation_t> m_animations;
	unsigned int m_last_id;
};

