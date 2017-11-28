#include "Texture_loader.h"



Texture_loader* Texture_loader::m_this = nullptr;

Texture_loader::Texture_loader()
{
	if (m_this != nullptr)
		exit(EXIT_FAILURE);

	m_this = this;
}


Texture_loader::~Texture_loader()
{
}
