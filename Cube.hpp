#ifndef CUBE_HPP
#define CUBE_HPP

#include <SFML/Graphics.hpp>

class Cube
{
public:
    // Prototypes
    Cube();
    Cube(sf::Vector2f size);
    void render(sf::RenderWindow& window);
    sf::FloatRect getHitbox() const;

private:
    // Cube pour tester une première collision avec le joueur
    sf::RectangleShape m_shape;
};

#endif