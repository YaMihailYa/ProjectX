#include "Animation_loader.h"
#include "Render.h"

Animation_loader* Animation_loader::m_this = nullptr;

Animation_loader::Animation_loader()
{
	if (m_this != nullptr)
		exit(EXIT_FAILURE);
	m_this = this;
	m_last_id = 0;
}


Animation_loader::~Animation_loader()
{
}

void Animation_loader::add(unsigned int texture_id, int countOfFrames)
{
	Texture_loader* textureLoader = Texture_loader::Get();
	sf::Texture* texture = textureLoader->Get_texture(texture_id);

	int objWidth = texture->getSize().x / countOfFrames;
	int objHeight = texture->getSize().y;
	sf::Vector2f coef = Render::Get()->Get_coef();

	std::vector<sf::Sprite> animation;

	for (int i = 0; i < countOfFrames; i++) {
		sf::Sprite sprite;
		sprite.setTexture(*texture);
		sprite.setTextureRect(sf::IntRect(i * objWidth, 0, objWidth, objHeight));
		sprite.setScale(coef);
		animation.push_back(sprite);
	}

	m_map_animations.insert(std::pair<unsigned int, std::vector<sf::Sprite>>(m_last_id, animation));
	m_last_id++;
}

sf::Sprite Animation_loader::getSprite(unsigned int animation_id, unsigned int frame_id)
{
	return m_map_animations[animation_id][frame_id];
}

unsigned int Animation_loader::getNumberOfSprites(unsigned int id)
{
	return m_map_animations[id].size();
}
