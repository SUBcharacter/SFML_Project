#pragma once
#include "IntegrationLibrary.h"
#include <optional>
#include <memory>

#include "Title.h"
#include "IGameState.h"

class Game_Manager
{
private:

	sf::RenderWindow m_window;
	sf::Clock m_clock;

	std::unique_ptr<IgameState> m_currentState;//�ӽ÷� ��������

public:
	Game_Manager();

	~Game_Manager();

	void run();

	sf::RenderWindow& getWindow();
};

