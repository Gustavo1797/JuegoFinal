#include "Colicionable.h"


// Implementación del método de colisión
bool Colicionable::Colision(const Colicionable& obj) const {
    return getBounds().intersects(obj.getBounds());
}