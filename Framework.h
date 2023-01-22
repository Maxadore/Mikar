// Includes

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>				
#include <utility>
#include <memory>				// Manage dynamic memory
#include <stack>				// Adapatator class (running, pop off, back in the game)
#include <map>
#include <stdlib.h> 
#include <time.h>
#include <SFML/Graphics.hpp>	// SFML Graphics Lib
#include <SFML/Audio.hpp>		// SFML Audio	 Lib

// Namespaces

using namespace sf;				// Namespace SFML
using namespace std;			// Namespace C++ Standard Library

// Const

const int WIN_WIDTH = 800;		// 25 tiles of 32 px
const int WIN_HEIGHT = 576;		// 18 tiles of 32 px
const int SPRITE_SIZE = 32;		// Sprites 32x32 pixels

// Include headers

#include "State.h"
#include "StateManager.h"
#include "AssetManager.h"
#include "InputManager.h"
#include "Game.h"
#include "SplashState.h"
#include "MainMenuState.h"
#include "GameState.h"

// Defines

#define SPLASH_STATE_SHOW_TIME 4.0f // Splash state duration

// Textures

#define SPLASH_SCENE_BACKGROUND_FILEPATH "res/unranked.png"
#define MAIN_MENU_BACKGROUND_FILEPATH "res/menu_bg.png"
#define GAME_BACKGROUND_FILEPATH "res/game.png"

#define GAME_TITLE_FILEPATH "res/menu_title.png"
#define PLAY_BUTTON_FILEPATH "res/menu_play.png"

// Sounds

// Musics






