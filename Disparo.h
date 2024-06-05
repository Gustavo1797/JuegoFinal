#pragma once
#include <SFML/Graphics.hpp>

class Disparo : public sf::Drawable
{
private:
    sf::Sprite sprite;
    float Vel;
    sf::Vector2f dir;
    void Movement();

public:
    Disparo(sf::Vector2f, sf::Vector2f, float, sf::Texture&);
    void Update();
    sf::Vector2f GetPosicion();
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};