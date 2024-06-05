#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>
#include "TanquePlayer1.h"
#include "TanqueRapido.h"
#include "Disparo.h"
///HOLA

int main()
{
    // Inicializar la semilla para generar números aleatorios
    std::srand(static_cast<unsigned>(std::time(0)));

    // Crear la ventana del juego
    sf::RenderWindow window(sf::VideoMode(700, 650), "Gotham City.");
    window.setFramerateLimit(60);

    // Crear objetos del jugador, enemigo y vector de disparos
    TanquePlayer1 Player;
    TanqueRapido Enemigo1;
    Enemigo1.respawn();
    std::vector<Disparo> disparos;
    sf::Texture balaTexture;
    balaTexture.loadFromFile("bala.jpg");

    // Bucle principal del juego
    while (window.isOpen())
    {
        // Manejar eventos de la ventana
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Actualizar los objetos del juego
        Player.update();
        Enemigo1.update();

        // Verificar si el jugador quiere disparar
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        {
            Player.disparar(disparos, balaTexture);
        }

        // Actualizar y dibujar los disparos
        for (auto& disparo : disparos)
        {
            disparo.Update();
        }

        // Dibujar todo en la ventana
        window.clear();
        window.draw(Player);
        window.draw(Enemigo1);
        for (const auto& disparo : disparos)
        {
            window.draw(disparo);
        }
        window.display();
    }

    return 0;
}
