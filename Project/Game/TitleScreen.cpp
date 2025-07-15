#include "TitleScreen.h"

// ������ ����
// ��� �ʱ�ȭ ����Ʈ�� ����Ͽ� backgroundTexture, font�� ���� �ε��ϰ�
// �� ���� backgroundSprite�� titleText�� �ʱ�ȭ�մϴ�.
TitleScreen::TitleScreen(const std::string& backgroundTexturePath)
// ��� �ʱ�ȭ ����Ʈ ����
// backgroundTexture �ε�
    : backgroundTexture(), // �⺻ �����ڷ� ���� ����
    font() // �⺻ �����ڷ� ���� ����
{
    // 1. ��� �ؽ�ó �ε� (������ �������� �ε�)
    if (!backgroundTexture.loadFromFile(backgroundTexturePath))
    {
        std::cerr << "����: ��� ��������Ʈ(" << backgroundTexturePath << ")�� ã�� �� �����ϴ�." << std::endl;
        // ���� ó�� ����
    }
    // ���� backgroundTexture�� ��ȿ�ϹǷ� backgroundSprite�� �����մϴ�.
    backgroundSprite.setTexture(backgroundTexture); // ���⼭ setTexture ȣ��

    // 2. ��Ʈ �ε� (������ �������� �ε�)
    if (!font.openFromFile("Assets/KoPubWorld Batang Bold.ttf")) // ��Ȯ�� ��Ʈ ��ο� Ȯ���� Ȯ��
    {
        std::cerr << "����: ��Ʈ (Assets/KoPubWorld Batang Bold.ttf)�� ã�� �� �����ϴ�." << std::endl;
        // ���� ó�� ����
    }
    // ���� font�� ��ȿ�ϹǷ� titleText�� �����մϴ�.
    titleText.setFont(font); // ���⼭ setFont ȣ��

    // 3. Ÿ��Ʋ �ؽ�Ʈ�� ������ ����
    titleText.setString("Welcome to the TitleScreen Screen!");
    titleText.setCharacterSize(48);
    titleText.setFillColor(sf::Color::White);
}

// run() �Լ��� ������ �����մϴ�.
void TitleScreen::run(sf::RenderWindow& window)
{
   // // �������� ���� ũ�⸦ �����ɴϴ�.
   // sf::Vector2u windowSize = window.getSize();
   //
   // // ��� ��������Ʈ ũ�� ���� (������ ũ�⿡ ����)
   // if (backgroundTexture.getSize().x > 0 && backgroundTexture.getSize().y > 0) {
   //     float scaleX = static_cast<float>(windowSize.x) / backgroundTexture.getSize().x;
   //     float scaleY = static_cast<float>(windowSize.y) / backgroundTexture.getSize().y;
   //     backgroundSprite.setScale(scaleX, scaleY);
   // }
   // backgroundSprite.setPosition(0.f, 0.f); // ����� â�� ���� ��ܿ� ��ġ
   //
   // // Ÿ��Ʋ �ؽ�Ʈ�� â�� �߾ӿ� ��ġ��Ű�� ���� ����(origin) ���� �� ��ġ ����
   // sf::FloatRect textRect = titleText.getLocalBounds();
   // titleText.setOrigin(textRect.left + textRect.width / 2.0f,
   //     textRect.top + textRect.height / 2.0f);
   // titleText.setPosition(static_cast<float>(windowSize.x / 2.0f),
   //     static_cast<float>(windowSize.y / 2.0f));

    // ���� ����: �����찡 �����ִ� ���� Ÿ��Ʋ ȭ���� ǥ��
    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
                return;
            }
            else if (const auto* keypressed = event->getIf < sf::Event::KeyPressed>())
            {
                if (keypressed->scancode == sf::Keyboard::Scancode::Enter ||
                    keypressed->scancode == sf::Keyboard::Scancode::Escape)
                {
                    return;
                }
            }
        }

        window.clear(sf::Color::Black);
        window.draw(backgroundSprite);
        window.draw(titleText);
        window.display();
    }
}