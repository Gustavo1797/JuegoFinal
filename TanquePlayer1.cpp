#include "TanquePlayer1.h"


TanquePlayer1::TanquePlayer1()
{
    _Velocidad = { 0,0 };
    _texture.loadFromFile("Tanque1.jpg");
    _sprite.setTexture(_texture);
    _sprite.setOrigin(_texture.getSize().x / 2, _texture.getSize().y / 2);
    _sprite.setPosition(350, 325);
}

void TanquePlayer1::update()
{
    {
    _Velocidad = { 0 , 0 };


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
    }

    _sprite.move(_Velocidad);

    if (_sprite.getPosition().x - _sprite.getGlobalBounds().width / 2 < 0) {
        _sprite.setPosition(_sprite.getGlobalBounds().width / 2, _sprite.getPosition().y);
    }
    if (_sprite.getPosition().y - _sprite.getGlobalBounds().height / 2 < 0) {
        _sprite.setPosition(_sprite.getPosition().x, _sprite.getGlobalBounds().height / 2);
    }
    if (_sprite.getPosition().x + _sprite.getGlobalBounds().width / 2 > 700) {
        _sprite.setPosition(700 - _sprite.getGlobalBounds().width / 2, _sprite.getPosition().y);
    }
    if (_sprite.getPosition().y + _sprite.getGlobalBounds().height / 2 > 650) {
        _sprite.setPosition(_sprite.getPosition().x, 650 - _sprite.getGlobalBounds().height / 2);
    }
    }
}

void TanquePlayer1::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(_sprite, states);
}

sf::FloatRect TanquePlayer1::getBounds() const
{
    return _sprite.getGlobalBounds();
}

void TanquePlayer1::disparar(std::vector<Disparo>& disparos, sf::Texture& texturaDisparo)
{
    // Calcular la dirección del disparo basándote en la orientación del tanque
    float anguloRad = _sprite.getRotation() * (3.14159f / 360.f); // Convertir el ángulo a radianes
    sf::Vector2f direccionDisparo(std::cos(anguloRad), std::sin(anguloRad));

    // Calcular la posición del cañón del tanque
    float offset = 5;/* distancia desde el centro del tanque hasta la punta del cañón */
    sf::Vector2f posicionCañon(_sprite.getPosition().x + offset * std::cos(anguloRad),
        _sprite.getPosition().y + offset * std::sin(anguloRad));

    // Crear un nuevo disparo con la posición y dirección adecuadas
    disparos.push_back(Disparo(posicionCañon, direccionDisparo, 0, texturaDisparo));
}