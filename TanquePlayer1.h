#pragma once
#include <SFML/Graphics.hpp>
#include "Colicionable.h"
#include "Disparo.h"

class TanquePlayer1 : public sf::Drawable, public Colicionable
{
    sf::Sprite _sprite;
    sf::Texture _texture;
    sf::Vector2f _Velocidad;

public:
    TanquePlayer1();
    void update();
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    sf::FloatRect getBounds() const override;

    
};