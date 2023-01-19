#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H

class InputManager
{

public:

	// Constructor & Destructor
	InputManager() {}
	~InputManager() {}



	bool IsSpriteClicked(Sprite object, Mouse::Button button, RenderWindow& window);  // Detect a click on the sprite button on the window

	Vector2i GetMousePosition(sf::RenderWindow& window);							  // Detect the mouse position on the window

private:

};

#endif // INPUTMANAGER_H

