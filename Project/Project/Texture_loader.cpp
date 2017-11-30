#include "Texture_loader.h"



Texture_loader* Texture_loader::m_this = nullptr;

Texture_loader::Texture_loader()
{
	if (m_this != nullptr)
		exit(EXIT_FAILURE);

	m_this = this;

	m_last_id = -1;
}


Texture_loader::~Texture_loader()
{
	std::map<int, sf::Texture*>::iterator it;

	for (it = this->m_textures.begin(); it != this->m_textures.end(); it++)
	{
		delete it->second;
	}
}


bool Texture_loader::Add_texture(char *fileName)
{
	sf::Texture *texture = new sf::Texture();
	
	if (!texture->loadFromFile(fileName))
	{
		return false;
	}

	this->m_last_id++;

	this->m_textures.insert(std::pair<int, sf::Texture*>(m_last_id, texture));

	return true;
}

sf::Texture* Texture_loader::Get_texture(unsigned int id)
{
	if (this->m_textures.count(id) == 0)
	{
		// Texture not found
		exit(EXIT_FAILURE);
	}
	else
	{
		return this->m_textures[id];
	}
}
