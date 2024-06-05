#include "Disparo.h"

Disparo::Disparo(sf::Vector2f pos, sf::Vector2f dire, float rot, sf::Texture& texture)
{
    dir = dire;
    sprite.setTexture(texture);
    sprite.setScale(0.25, .025);
    sprite.setOrigin(texture.getSize().x / 2, texture.getSize().y / 2);
    sprite.setPosition(pos);
    sprite.setRotation(rot);
    Vel = 5;
}

void Disparo::Update()
{
    Movement();
}

sf::Vector2f Disparo::GetPosicion()
{
    return sprite.getPosition();
}

void Disparo::Movement() {
    sprite.move(dir.x * Vel, dir.y * Vel);
}

void Disparo::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(sprite, states);
}