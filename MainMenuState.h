#ifndef MAINMENUSTATE_H
#define MAINMENUSTATE_H
class MainMenuState : public State
{
public:
	MainMenuState(GameDataRef data);

	void Init();

	void HandleInput();
	void Update(float dt);
	void Draw(float dt);

private:
	GameDataRef m_data;

	sf::Sprite m_background;
	sf::Sprite m_title;
	sf::Sprite m_playButton;
};

#endif // MAINMENUSTATE_H
