#include "IntegrationLibrary.h"
#include "Physics.h"
int main()
{
    // ����
    RenderWindow window(sf::VideoMode({ 800, 600 }), "Game");
    // ������ ����
    window.setFramerateLimit(60);

    // ���� ��ü ����
    Physics physics;

    // ���� ����
    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent())
        {
            //â �ݱ� ��ư�� ������ ���
            if (event->is<sf::Event::Closed>())
            {
                // â �ݱ�
                window.close();
            }
            //Ű���� Ű�� ������ ��� ó��
            else if (const auto* keypressed = event->getIf < sf::Event::KeyPressed>())
            {
                // Esc�� ������ ��� â �ݱ�
                if (keypressed->scancode == sf::Keyboard::Scancode::Escape)
                {
                    window.close();
                }
            }
        }


        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::A))
        {
            physics.playerx -= 2;

        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::D))
        {
            physics.playerx += 2;

        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Space)) {
            physics.Jump();
        }

        // �浹 üũ
        physics.Collision();

        // �÷��̾� �׸����
        sf::RectangleShape player(sf::Vector2f(physics.playerw, physics.playerh));
        player.setPosition({ static_cast<float>(physics.playerx), static_cast<float>(physics.playery) });
        player.setFillColor(sf::Color::Blue);

        // �÷��� �׸���� 
        sf::RectangleShape platform(sf::Vector2f(physics.platformw, physics.platformh));
        platform.setPosition({ static_cast<float>(physics.platformx), static_cast<float>(physics.platformy) });
        platform.setFillColor(sf::Color::Green);

        // ȭ�� �׸���
        window.clear(sf::Color::Black);
        window.draw(player);
        window.draw(platform);
        window.display();
    }

    return 0;
}