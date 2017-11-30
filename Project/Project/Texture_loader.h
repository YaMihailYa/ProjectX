#pragma once
/**
* Load all textures from files
*/

class Texture_loader
{
public:
	Texture_loader();
	~Texture_loader();

	// Add texture to the hash table (false if failed)
	bool Add_texture(char *fileName);

	// Get texture by id
	sf::Texture* Get_texture(unsigned int id);
	static Texture_loader* Get() { return m_this; }
protected:

	static Texture_loader* m_this;

	static std::map<int, sf::Texture*> m_textures;
	// id of last loaded texture
	int m_last_id;
};

