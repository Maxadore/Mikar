#ifndef SPLASHSTATE_H
#define SPLASHSTATE_H
class SplashState : public State
{
public:
	SplashState(GameDataRef data);

	void Init();

	void HandleInput();
	void Update(float dt);
	void Draw(float dt);

private:
	GameDataRef m_data;

	sf::Clock m_clock;

	sf::Sprite m_background;
};
#endif // SPLASHSTATE_H
