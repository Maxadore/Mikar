#include "Framework.h"

// Boolean for detect if sprite is clicked
bool InputManager::IsSpriteClicked(Sprite object, Mouse::Button button, RenderWindow& window)
{	
	// Detection bouton souris
	if (Mouse::isButtonPressed(button))
	{
		IntRect playButtonRect(object.getPosition().x, object.getPosition().y, object.getGlobalBounds().width, object.getGlobalBounds().height);

		if (playButtonRect.contains(Mouse::getPosition(window)))
		{
			return true;
		}
	}

	return false;
}

Vector2i InputManager::GetMousePosition(RenderWindow& window)
{
	return Mouse::getPosition(window);
}