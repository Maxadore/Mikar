#include "Framework.h"

MainMenuState::MainMenuState(GameDataRef data) : m_data(data)
{

}

void MainMenuState::Init()
{
	this->m_data->m_assets.LoadTexture("Main Menu Background", MAIN_MENU_BACKGROUND_FILEPATH);
	this->m_data->m_assets.LoadTexture("Game Title", GAME_TITLE_FILEPATH);
	this->m_data->m_assets.LoadTexture("Play Button", PLAY_BUTTON_FILEPATH);

	m_background.setTexture(this->m_data->m_assets.GetTexture("Main Menu Background"));
	m_title.setTexture(this->m_data->m_assets.GetTexture("Game Title"));
	m_playButton.setTexture(this->m_data->m_assets.GetTexture("Play Button"));

	m_title.setPosition((WIN_WIDTH / 2), (WIN_HEIGHT / 2));
	m_title.setScale(0.5, 0.5);
	m_playButton.setPosition((WIN_WIDTH / 2) - (m_playButton.getGlobalBounds().width / 2), (WIN_HEIGHT / 2) - (m_playButton.getGlobalBounds().height / 2));
	m_playButton.setScale(0.5, 0.5);
}

void MainMenuState::HandleInput()
{
	sf::Event event;

	while (this->m_data->m_window.pollEvent(event))
	{
		if (sf::Event::Closed == event.type)
		{
			this->m_data->m_window.close();
		}

		if (this->m_data->m_input.IsSpriteClicked(this->m_playButton, sf::Mouse::Left, this->m_data->m_window))
		{
			// Switch To Main Menu
			this->m_data->m_manager.AddState(StateRef(new GameState(m_data)), true);
		}
	}
}

void MainMenuState::Update(float dt)
{

}

void MainMenuState::Draw(float dt)
{
	this->m_data->m_window.clear(sf::Color::Black);

	this->m_data->m_window.draw(this->m_background);
	this->m_data->m_window.draw(this->m_title);
	this->m_data->m_window.draw(this->m_playButton);

	this->m_data->m_window.display();
}
