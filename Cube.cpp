#include <SFML/Graphics.hpp>
#include "Cube.hpp"

using namespace sf;

Cube::Cube()
{

}

Cube::Cube(Vector2f size)
{
    // Cube pour la collision
    m_shape.setSize(size);
    m_shape.setFillColor(Color::Red);
    m_shape.setPosition(100, 100);
}

void Cube::render(RenderWindow& window)
{
    window.draw(m_shape);
}

FloatRect Cube::getHitbox() const
{
    return m_shape.getGlobalBounds();
}