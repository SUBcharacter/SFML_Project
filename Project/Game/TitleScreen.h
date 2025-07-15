#pragma once
#include <SFML/Graphics.hpp>
#include "IntegrationLibrary.h" // �� ����� �ʿ��� ��� �����մϴ�.

class TitleScreen {
public:
    // ������: ��� �̹��� ���� ��θ� �޾� �ʱ�ȭ�մϴ�.
    TitleScreen(const std::string& backgroundTexturePath);

    // run() �Լ�: ���޹��� �����쿡 Ÿ��Ʋ ȭ���� ǥ���ϰ� �̺�Ʈ�� ó���մϴ�.
    // �����찡 �����ų� Ư�� Ű�� ������ �Լ��� �����մϴ�.
    void run(sf::RenderWindow& window); // sf::RenderWindow�� ������ �޵��� ����

private:
    sf::Texture backgroundTexture; // ��� �̹����� ���� �ؽ�ó
    sf::Sprite backgroundSprite;   // �ؽ�ó�� ����Ͽ� ȭ�鿡 �׸� ��������Ʈ

    sf::Font font;                 // Ÿ��Ʋ �ؽ�Ʈ�� ����� ��Ʈ
    sf::Text titleText;            // Ÿ��Ʋ ���ڿ��� ǥ���� sf::Text ��ü
};