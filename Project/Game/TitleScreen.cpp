#include "TitleScreen.h"
#include <iostream> // ���� �޽��� ����� ���� ���� (std::cerr ���)

// ������ ����
TitleScreen::TitleScreen(const std::string& backgroundTexturePath)
 : backgroundTexture(), // �⺻ �����ڷ� ���� ����
font()
{
    // 1. ��� �ؽ�ó �ε�
    if (!backgroundTexture.loadFromFile(backgroundTexturePath))
    {
        std::cerr << "����: ��� ��������Ʈ(" << backgroundTexturePath << ")�� ã�� �� �����ϴ�." << std::endl;
        // ���� ���ø����̼ǿ����� ���⼭ ���� ó�� ������ �߰��ؾ� �մϴ�.
    }
    // ��� ��������Ʈ�� �ؽ�ó ���� (��ġ/ũ�� ������ run()���� ������ ũ�� ������� ����)
    backgroundSprite.setTexture(backgroundTexture);

    // 2. ��Ʈ �ε�
    // ��Ʈ ���� ��ο� Ȯ����(.ttf, .otf ��)�� ��Ȯ�� ����ؾ� �մϴ�.
    if (!font.openFromFile("Assets/KoPubWorld_Batang_Bold.ttf")) // ����: .ttf Ȯ���� ���
    {
        std::cerr << "����: ��Ʈ (Assets/KoPubWorld Batang Bold.ttf)�� ã�� �� �����ϴ�." << std::endl;
        // ���� ���ø����̼ǿ����� ���⼭ ���� ó�� ������ �߰��ؾ� �մϴ�.
    }

    // 3. Ÿ��Ʋ �ؽ�Ʈ �ʱ� ���� (��Ʈ, ���ڿ�, ũ��, ����)
    titleText.setFont(font);
    titleText.setString("Welcome to the TitleScreen Screen!");
    titleText.setCharacterSize(48);
    titleText.setFillColor(sf::Color::White);
    // �ؽ�Ʈ ��ġ ������ run()���� ������ ũ�� ������� �����մϴ�.
}

// run() �Լ� ����
void TitleScreen::run(sf::RenderWindow& window) // sf::RenderWindow�� ������ ����
{
    // �������� ���� ũ�⸦ �����ɴϴ�.
    sf::Vector2u windowSize = window.getSize();

   // // ��� ��������Ʈ ũ�� ���� (������ ũ�⿡ ����)
   // // �ؽ�ó ũ�Ⱑ 0�� ��� ������ ���� ������ ���� üũ�մϴ�.
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
        // �̺�Ʈ ���� (main �Լ��� ��Ÿ���� �����ϴ�)
        while (const std::optional event = window.pollEvent())
        {
            // â �ݱ� ��ư�� ������ ���
            if (event->is<sf::Event::Closed>())
            {
                window.close(); // â �ݱ�
                return; // Ÿ��Ʋ ȭ�� ���� ����
            }
            // Ű���� Ű�� ������ ��� ó��
            else if (const auto* keypressed = event->getIf < sf::Event::KeyPressed>())
            {
                // Enter �Ǵ� Escape�� ������ ��� Ÿ��Ʋ ȭ�� ����
                if (keypressed->scancode == sf::Keyboard::Scancode::Enter ||
                    keypressed->scancode == sf::Keyboard::Scancode::Escape)
                {
                    return; // Ÿ��Ʋ ȭ�� ���� ���� (â�� ���� �ʰ� ���� ������ �Ѿ)
                }
            }
        }

        // â�� ����ϴ�.
        window.clear(sf::Color::Black);

        // 1. ��� ��������Ʈ�� ���� �׸��ϴ�.
        window.draw(backgroundSprite);

        // 2. �� ���� Ÿ��Ʋ �ؽ�Ʈ�� �׸��ϴ�.
        window.draw(titleText);

        // ȭ�鿡 �׸� ������ ǥ���մϴ�.
        window.display();
    }
}