#include <iostream>
#include <SFML/Graphics.hpp>
#include "Game.hpp"
#include "Player.hpp"
#include "Cube.hpp"

using namespace std;
using namespace sf;

Game::Game() : m_window(VideoMode(M_WINDOW_WIDTH, M_WINDOW_HEIGHT, 32), "Mikar", Style::Default)
{
	m_window.setVerticalSyncEnabled(true);
	
	m_cube = Cube(Vector2f(32, 32));
}

void Game::run()
{
	// Boucle du jeu
	while (m_window.isOpen())
	{
		processEvents();
		update();
		render();
		checkCollision();
	}
}

void Game::processEvents()
{
	Event event;

	// Boucle sur les événements
	while (m_window.pollEvent(event))
	{
		// Gestion des entrées (clavier / souris)
		m_input.inputsHandler(event, m_window);

		if (event.type == Event::Closed)
		{
			m_window.close();
		}
	}
}

void Game::update()
{
	m_player.update(m_input);

	if (m_input.getButton().quit)
	{
		m_window.close();
	}
}

void Game::render()
{
	// Couleur de la fenêtre en noir
	m_window.clear(Color::Black);

	// Dessin des éléments
	m_cube.render(m_window);
	m_player.render(m_window);

	// Dessin à l'écran de tous les éléments
	m_window.display();
}

// Teste la collision entre le joueur et le cube
void Game::checkCollision()
{
	// Hitbox du joueur
	FloatRect playerHitbox = m_player.getHitbox();

	// Hitbox du cube
	FloatRect cubeHitbox = m_cube.getHitbox();

	// On vérifie si le joueur entre en collision avec le cube
	if (playerHitbox.intersects(cubeHitbox))
	{
		// On affiche un simple message en console indiquant qu'il y a bien une collision
		cout << "Collision !" << endl;
	}
}