#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>
#include "Input.hpp"
#include "Player.hpp"
#include "Cube.hpp"

class Game
{
public:
	// Prototypes
	Game();
	void run();
	void processEvents();
	void update();
	void render();
	void checkCollision();

private:
	// 25 tuiles de 32 pixels
	const int M_WINDOW_WIDTH;
	// 18 tuiles de 32 pixels
	const int M_WINDOW_HEIGHT;
	
	sf::RenderWindow m_window;
	Input m_input;
	Player m_player;
	Cube m_cube;
};

#endif