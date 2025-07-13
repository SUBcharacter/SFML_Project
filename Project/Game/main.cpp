#include "IntegrationLibrary.h"
#include "Physics.h"
#include "Platform.h"
int main()
{
    // ����
    RenderWindow window(sf::VideoMode({ 600, 800 }), "Game");
    // ������ ����
    window.setFramerateLimit(60);

    // ���� ��ü ����
    Physics physics;

    Platform* pl = new Platform(300, 0, 52, 52);
    pl->SetPosition(300.f,300.f);
    
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
        window.clear();
        pl->Draw(window);
        window.display();
        
    }

    return 0;
}