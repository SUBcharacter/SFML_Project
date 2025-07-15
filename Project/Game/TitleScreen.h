#pragma once
#include "IntegrationLibrary.h"

class TitleScreen {
public:
    TitleScreen(const std::string& backgroundTexturePath);
    void run(sf::RenderWindow& window);

private:
    sf::Texture backgroundTexture;
    sf::Sprite backgroundSprite;   // �� �κп��� �⺻ ������ ������ �߻��� �� �ֽ��ϴ�.

    sf::Font font;
    sf::Text titleText;            // �� �κп��� �⺻ ������ ������ �߻��� �� �ֽ��ϴ�.
};