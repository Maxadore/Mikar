#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <SFML/Graphics.hpp>
#include "Input.hpp"

class Player
{
public:
	// Prototypes
	Player();
	void update(Input& input);
	void render(sf::RenderWindow& window);
	void checkButtons(Input& input);
	void animations();
	sf::FloatRect getHitbox() const;

private:
	// Sprite de 32x32 pixels
	const int M_SIZE = 32;
	// Vitesse
	const int M_SPEED = 1;
	
	// Pr�paration pour l'affichage
	sf::Texture m_texture;
	sf::Sprite m_sprite;

	// Diff�rentes directions / actions
	enum Directions { DOWN, RIGHT, UP, LEFT, DOWNWARD_ATTACK, RIGHTWARD_ATTACK, UPWARD_ATTACK, LEFTWARD_ATTACK };

	// Animation (la ligne � jouer)
	// x = lignes et y = colonnes
	sf::Vector2i m_animation;
	
	// Horloge de l'animation
	sf::Clock m_animationClock;

	// Le joueur est-il � l'arr�t ?
	bool m_isIdle;

	// Gestion de l'attaque � l'�p�e
	bool m_needToResetAnimation;
};

#endif