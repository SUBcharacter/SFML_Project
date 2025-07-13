#pragma once
#include "IGameState.h"
#include <optional>
#include "Game_Manager.h"

class Title : public IgameState
{
private:
    sf::Texture m_backgroundTexture; // ��� �ؽ�ó
    std::optional<sf::Sprite> m_backgroundSprite;                 // ��� ��������Ʈ
    sf::Font m_font;                 // ��Ʈ
    std::optional<sf::Text> m_titleText;            // ���� �ؽ�Ʈ
    std::optional<sf::Text> m_pressEnterText;       // "Press Enter" �ؽ�Ʈ

public:

    Title();
    virtual ~Title() override;
    void onEnter(Game_Manager& game) override;
    void handleInput(Game_Manager& game, const sf::Event& event) override;
    void update(Game_Manager& game, float deltaTime) override;
    void draw(Game_Manager& game, sf::RenderWindow& window) override;
    void onExit(Game_Manager& game) override;


};


