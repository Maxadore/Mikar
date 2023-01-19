#ifndef GAMESTATE_H
#define GAMESTATE_H

class GameState : public State
{
public:
	GameState(GameDataRef data);

	void Init();

	void HandleInput();
	void Update(float dt);
	void Draw(float dt);

private:
	GameDataRef m_data;

	sf::Sprite m_background;
};
#endif // GAMESTATE_H

