#include "Framework.h"

SplashState::SplashState(GameDataRef data) : m_data(data)
{

}

void SplashState::Init()
{
	this->m_data->m_assets.LoadTexture("Splash State Background", SPLASH_SCENE_BACKGROUND_FILEPATH);

	m_background.setTexture(this->m_data->m_assets.GetTexture("Splash State Background"));
}

void SplashState::HandleInput()
{
	sf::Event event;

	while (this->m_data->m_window.pollEvent(event))
	{
		if (sf::Event::Closed == event.type)
		{
			this->m_data->m_window.close();
		}
	}
}

void SplashState::Update(float dt)
{
	if (this->m_clock.getElapsedTime().asSeconds() > SPLASH_STATE_SHOW_TIME)
	{
		// Switch To Main Menu
		this->m_data->m_manager.AddState(StateRef(new MainMenuState(m_data)), true);
	}
}

void SplashState::Draw(float dt)
{
	this->m_data->m_window.clear(sf::Color::Black);

	this->m_data->m_window.draw(this->m_background);

	this->m_data->m_window.display();
}