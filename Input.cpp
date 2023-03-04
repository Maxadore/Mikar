#include <SFML/Graphics.hpp>
#include "Input.hpp"

using namespace sf;

// Constructeur
Input::Input()
{
	m_button.left = m_button.right = m_button.up = m_button.down = m_button.attack = m_button.quit = false;
}

// M�thode qui acc�de � la structure de type Button et qui nous retourne l'�tat du bouton
Input::Button Input::getButton() const
{
	return m_button;
}

// M�thode qui g�re les entr�es (clavier / souris)
void Input::inputsHandler(Event event, RenderWindow& window)
{
	// On v�rifie si le joueur presse une touche du clavier
	if (event.type == Event::KeyPressed)
	{
		// On teste le code de la touche press�e
		switch (event.key.code)
		{
		case Keyboard::Left:
			m_button.left = true;
			break;
		case Keyboard::Right:
			m_button.right = true;
			break;
		case Keyboard::Up:
			m_button.up = true;
			break;
		case Keyboard::Down:
			m_button.down = true;
			break;
		case Keyboard::Escape:
			m_button.quit = true;
			break;
		default:
			break;
		}
	}
	
	// On v�rifie si le joueur rel�che une touche du clavier
	if (event.type == Event::KeyReleased)
	{
		// On teste le code de la touche rel�ch�e
		switch (event.key.code)
		{
		case Keyboard::Left:
			m_button.left = false;
			break;
		case Keyboard::Right:
			m_button.right = false;
			break;
		case Keyboard::Up:
			m_button.up = false;
			break;
		case Keyboard::Down:
			m_button.down = false;
			break;
		case Keyboard::Escape:
			m_button.quit = false;
			break;
		default:
			break;
		}
	}

	// On v�rifie si le joueur presse le bouton gauche de la souris
	if (event.type == Event::MouseButtonPressed)
	{
		if (event.mouseButton.button == Mouse::Left)
		{
			m_button.attack = true;
		}
	}
	
	// On v�rifie si le joueur rel�che le bouton gauche de la souris
	if (event.type == Event::MouseButtonReleased)
	{
		if (event.mouseButton.button == Mouse::Left)
		{
			m_button.attack = false;
		}
	}

	// On v�rifie si le joueur clique sur la croix de la fen�tre
	if (event.type == Event::Closed)
	{
		// On ferme la fen�tre
		window.close();
	}
}