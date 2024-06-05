#pragma once
#include <SFML\Graphics.hpp>
#include "Colicionable.h" 
class TanqueRapido : public sf::Drawable , public :: Colicionable
{
	sf::Sprite _sprite;
	sf::Texture _texture;
	sf::Vector2f _Velocidad;

public:
	TanqueRapido();
	void update();
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	void respawn(); 
	sf::FloatRect getBounds() const override;
};

