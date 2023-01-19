#include "Framework.h"

GameState::GameState(GameDataRef data) : m_data(data)
{

}

void GameState::Init()
{
	this->m_data->m_assets.LoadTexture("Game Background", GAME_BACKGROUND_FILEPATH);

	m_background.setTexture(this->m_data->m_assets.GetTexture("Game Background"));
}

void GameState::HandleInput()
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

void GameState::Update(float dt)
{

}

void GameState::Draw(float dt)
{
	this->m_data->m_window.clear(sf::Color::Red);

	this->m_data->m_window.draw(this->m_background);

	this->m_data->m_window.display();
}