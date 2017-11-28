#pragma once
/**
* Load all textures from files
*/

struct texture_t
{
	unsigned int id;
	sf::Texture texture;
};

class Texture_loader
{
public:
	Texture_loader();
	~Texture_loader();

	// Get texture by id
	sf::Texture Get_texture(unsigned int id);
	static Texture_loader* Get() { return m_this; }
protected:
	static Texture_loader* m_this;

	static std::vector<texture_t> m_textures;
	// id of last loaded texture
	unsigned int m_last_id;
};

