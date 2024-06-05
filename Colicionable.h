#pragma once
#include <SFML\Graphics.hpp>

class Colicionable {
public:
    // Método virtual puro para obtener los límites del objeto
    virtual sf::FloatRect getBounds() const = 0;

    // Método para verificar la colisión
    bool Colision(const Colicionable& col) const;
};