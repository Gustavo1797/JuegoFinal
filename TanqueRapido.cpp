#include <stdlib.h>
#include "TanqueRapido.h"
#include "Colicionable.h"


TanqueRapido::TanqueRapido()
{
	{
		_Velocidad = { 4,4 };
		_texture.loadFromFile("TanqueRapido.jpg");

		_sprite.setTexture(_texture);

		_sprite.setOrigin(_texture.getSize().x / 2, _texture.getSize().y / 2);
		_sprite.setPosition(200, 325);
	}
}

void TanqueRapido::update()
{
    

    /*
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        _Velocidad.y = -4;
        _sprite.setRotation(0);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        _Velocidad.x = -4;
        _sprite.setRotation(270);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        _Velocidad.y = 4;
        _sprite.setRotation(180);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        _Velocidad.x = 4;
        _sprite.setRotation(90);
    }*/

    _sprite.move(_Velocidad);

    if (_sprite.getPosition().x < 0) {
        _sprite.setPosition(_sprite.getGlobalBounds().width / 2, _sprite.getPosition().y);
        _Velocidad.x = -_Velocidad.x;
        _sprite.setRotation(90);

    }
    if (_sprite.getPosition().y - _sprite.getGlobalBounds().height / 2 < 0) {
        _sprite.setPosition(_sprite.getPosition().x, _sprite.getGlobalBounds().height / 2);
        _Velocidad.y = -_Velocidad.y;
        _sprite.setRotation(180);
    }
    if (_sprite.getPosition().x + _sprite.getGlobalBounds().width / 2 > 700) {
        _sprite.setPosition(700 - _sprite.getGlobalBounds().width / 2, _sprite.getPosition().y);
        _Velocidad.x = -_Velocidad.x;
        _sprite.setRotation(270);
    }
    if (_sprite.getPosition().y + _sprite.getGlobalBounds().height / 2 > 650) {
        _sprite.setPosition(_sprite.getPosition().x, 650 - _sprite.getGlobalBounds().height / 2);
        _Velocidad.y = -_Velocidad.y;
        _sprite.setRotation(0);
    }
}

void TanqueRapido::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(_sprite, states);
}

void TanqueRapido::respawn()
{   
    _sprite.setPosition(std::rand() % 600 + _sprite.getGlobalBounds().width, ::rand() % 500 + _sprite.getGlobalBounds().height);
}

sf::FloatRect TanqueRapido::getBounds() const
{
    return _sprite.getGlobalBounds();
}
