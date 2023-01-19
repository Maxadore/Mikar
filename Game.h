#ifndef GAME_H
#define GAME_H

struct GameData
{
	StateManager m_manager;
	RenderWindow m_window;
	AssetManager m_assets;
	InputManager m_input;
};

typedef shared_ptr<GameData> GameDataRef;

class Game
{
public:
	Game(int width, int height, std::string title);

private:
	// Updates run at 60 per second.
	const float dt = 1.0f / 60.0f;
	sf::Clock m_clock;

	GameDataRef m_data = std::make_shared<GameData>();

	void Run();
};

#endif // GAME_H

