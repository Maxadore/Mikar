#include "Framework.h"


Game::Game(int width, int height, std::string title)
{
	srand(time(NULL));

	m_data->m_window.create(sf::VideoMode(width, height), title, sf::Style::Close | sf::Style::Titlebar);
	m_data->m_manager.AddState(StateRef(new SplashState(this->m_data)));

	this->Run();
}

void Game::Run()
{
	float newTime, frameTime, interpolation;

	float currentTime = this->m_clock.getElapsedTime().asSeconds();
	float accumulator = 0.0f;

	while (this->m_data->m_window.isOpen())
	{
		this->m_data->m_manager.ProcessStateChanges();

		newTime = this->m_clock.getElapsedTime().asSeconds();
		frameTime = newTime - currentTime;

		if (frameTime > 0.25f)
		{
			frameTime = 0.25f;
		}

		currentTime = newTime;
		accumulator += frameTime;

		while (accumulator >= dt)
		{
			this->m_data->m_manager.GetActiveState()->HandleInput();
			this->m_data->m_manager.GetActiveState()->Update(dt);

			accumulator -= dt;
		}

		interpolation = accumulator / dt;
		this->m_data->m_manager.GetActiveState()->Draw(interpolation);
	}
}
