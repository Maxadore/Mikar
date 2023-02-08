#include <iostream>
#include <SFML/Graphics.hpp>
#include "Input.hpp"

// Constantes
const int WINDOW_WIDTH = 800; // 25 tuiles de 32 pixels
const int WINDOW_HEIGHT = 576; // 18 tuiles de 32 pixels
const int SPRITE_SIZE = 32; // Sprites de 32x32 pixels
const int HERO_SPEED = 1; // Vitesse du héros

// Prototypes
void checkButtons();
void playerAnimation();
void checkCollision();