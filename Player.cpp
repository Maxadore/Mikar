#include <iostream>
#include <SFML/Graphics.hpp>
#include "Player.hpp"

using namespace std;
using namespace sf;

Player::Player() : m_animation(0, DOWN), m_isIdle(true), m_needToResetAnimation(false)
{
    // Chargement du visuel
	if (!m_texture.loadFromFile("resources/player_sheet.png"))
	{
		cout << "Texture Loading Error" << endl;
	}

    // Application de la texture
    m_sprite.setTexture(m_texture);
    // Découpage pour afficher 1 case de 32x32 pixels
    m_sprite.setTextureRect(IntRect(m_animation.x * M_SIZE, m_animation.y * M_SIZE, M_SIZE, M_SIZE));
}

void Player::update(Input& input)
{
    // Gestion des entrées
	checkButtons(input);
    // Gestion des animations
    animations();
}

void Player::render(RenderWindow& window)
{
	window.draw(m_sprite);
}

void Player::checkButtons(Input& input)
{
    // On vérifie si le joueur n'est pas entrain d'attaquer
    if (!m_needToResetAnimation)
    {
        if (input.getButton().left)
        {
            m_animation.y = LEFT;
            m_sprite.move(-M_SPEED, 0);
            m_isIdle = false;
        }
        else if (input.getButton().right)
        {
            m_animation.y = RIGHT;
            m_sprite.move(M_SPEED, 0);
            m_isIdle = false;
        }
        else if (input.getButton().up)
        {
            m_animation.y = UP;
            m_sprite.move(0, -M_SPEED);
            m_isIdle = false;
        }
        else if (input.getButton().down)
        {
            m_animation.y = DOWN;
            m_sprite.move(0, M_SPEED);
            m_isIdle = false;
        }
        else
        {
            m_isIdle = true;
        }

        if (input.getButton().attack)
        {
            m_needToResetAnimation = true; // Après l'attaque du joueur, on retourne sur l'animation de marche
            m_animation.x = 0; // On retourne à la colonne 0 pour jouer l'animation depuis le début
            m_animation.y += 4; // On descend de 4 lignes sur notre feuille de sprite pour passer de la ligne "marcher" à la ligne "attaquer" sur la texture
        }
    }
}

void Player::animations()
{
    // Modification du joueur à l'écran
    m_sprite.setTextureRect(IntRect(m_animation.x * M_SIZE, m_animation.y * M_SIZE, M_SIZE, M_SIZE));

    // On anime en boucle le joueur
    // On vérifie s'il s'est écoulé 0.1 seconde
    if (m_animationClock.getElapsedTime().asSeconds() > 0.1f)
    {
        // On vérifie si on est à la fin de la texture (en largeur)
        if (m_animation.x * M_SIZE >= m_texture.getSize().x - M_SIZE)
        {
            m_animation.x = 0;

            // On vérifie si l'animation d'attaque du joueur tourne
            if (m_needToResetAnimation)
            {
                // On arrête l'animation d'attaque du joueur et on retourne sur l'animation de marche
                m_needToResetAnimation = false;
                m_animation.y -= 4;
            }
        }
        // On vérifie si on n'est pas encore à la fin de la texture (en largeur)
        else
        {
            // On vérifie si le joueur n'est pas à l'arrêt
            if (!m_isIdle || m_needToResetAnimation)
            {
                m_animation.x++;
            }
        }

        m_animationClock.restart();
    }
}

FloatRect Player::getHitbox() const
{
    return m_sprite.getGlobalBounds();
}