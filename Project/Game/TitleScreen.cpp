// TitleScreen.cpp

#include "TitleScreen.h"
#include <iostream>

// SFML�� Vector2f�� ����ϱ� ���� �ʿ� (IntegrationLibrary.h�� ���ԵǾ� ���� �ʴٸ�)
// #include <SFML/System/Vector2.hpp>

TitleScreen::TitleScreen(int left, int top, int width, int height)
    : m_left(left), m_top(top), m_width(width), m_height(height),
    m_selectedButtonIndex(0)
{
    loadAssets();

    m_buttons.push_back(&startButton);
    m_buttons.push_back(&exitButton);

    updateButtonSelection();
}
//ĭ�� ���� ���� �־ �����غ��� �� ���� ����
void TitleScreen::loadAssets() {
    // ��� �̹��� �ε�
    // ����: TitleScreen.cpp �� loadAssets() �Ϻ�

// Ÿ��Ʋ ȭ�� ������ IntRect�� ����
sf::IntRect rectI = { m_left, m_top, m_width, m_height };

// IntRect�� position�� size�� FloatRect�� ��ȯ (static_cast Ȱ��)
sf::FloatRect rectF = {
    { static_cast<float>(rectI.left), static_cast<float>(rectI.top) },
    { static_cast<float>(rectI.width), static_cast<float>(rectI.height) }
};

// ��� �ؽ�ó ����
backSprite.setTexture(backTexture);
backSprite.setTextureRect(rectI); // �ؽ�ó���� ����� ���� ����
backSprite.setPosition(static_cast<sf::Vector2f>(rectF.position)); // ��ġ ����
backSprite.setScale(
    rectF.width / static_cast<float>(backTexture.getSize().x),
    rectF.height / static_cast<float>(backTexture.getSize().y)
);

// �ΰ� ��ġ ���� (�߾� ����)
logoSprite.setTexture(logoTexture);
logoSprite.setOrigin(
    static_cast<float>(logoTexture.getSize().x) / 2.f,
    static_cast<float>(logoTexture.getSize().y) / 2.f
);
logoSprite.setPosition(
    rectF.left + rectF.width / 2.f,
    rectF.top + rectF.height / 4.f
);

// ��ư ��ġ�� ����ϰ� ����
startButton.setOrigin(
    startButton.getLocalBounds().width / 2.f,
    startButton.getLocalBounds().height / 2.f
);
startButton.setPosition(
    rectF.left + rectF.width / 2.f,
    rectF.top + rectF.height / 2.f + 50.f
);

exitButton.setOrigin(
    exitButton.getLocalBounds().width / 2.f,
    exitButton.getLocalBounds().height / 2.f
);
exitButton.setPosition(
    rectF.left + rectF.width / 2.f,
    startButton.getPosition().y + 100.f
);

    // TODO: ��� ���� �ε� �� ��� (���� ����)
    // if (!m_bgMusic.openFromFile("assets/bg_music.ogg")) { ... }
    // m_bgMusic.setLoop(true);
    // m_bgMusic.play();
}

void TitleScreen::handleEvent(const sf::Event& event) {
    if (event.is<sf::Event::Closed>()) {
        m_finished = true;
        m_nextState = GameState::Exiting;
    }
    else if (const auto* keyPressed = event.getIf<sf::Event::KeyPressed>()) {
        if (keyPressed->scancode == sf::Keyboard::Scancode::Escape) {
            m_finished = true;
            m_nextState = GameState::Exiting;
        }
        else if (keyPressed->scancode == sf::Keyboard::Scancode::Up) {
            m_selectedButtonIndex = (m_selectedButtonIndex - 1 + m_buttons.size()) % m_buttons.size();
            updateButtonSelection();
        }
        else if (keyPressed->scancode == sf::Keyboard::Scancode::Down) {
            m_selectedButtonIndex = (m_selectedButtonIndex + 1) % m_buttons.size();
            updateButtonSelection();
        }
        else if (keyPressed->scancode == sf::Keyboard::Scancode::Space) {
            activateSelectedButton();
        }
    }
    // ���콺 Ŭ�� �̺�Ʈ (m_window ������ �����Ƿ� �ּ� ó�� �Ǵ� �ܺο��� window.mapPixelToCoords ���)
    // ���� TitleScreen�� RenderWindow�� ����� ������ �����Ƿ�, �� �κ��� ó���Ϸ���
    // run() �Լ����� window�� handleEvent�� �����ϰų�, handleEvent���� ���� window�� �Ű������� �޾ƾ� �մϴ�.
    // ���⼭�� Ű���� �Է¿� �����ϱ� ���� ���콺 Ŭ�� ������ ��� �����մϴ�.
    /*
    else if (const auto* mouseButtonPressed = event.getIf<sf::Event::MouseButtonPressed>()) {
        if (mouseButtonPressed->button == sf::Mouse::Left) {
            // �� �κ��� TitleScreen�� window ������ ������ ���� �����Ƿ� ������ �ʿ��մϴ�.
            // sf::Vector2f mousePos = static_cast<sf::Vector2f>(sf::Mouse::getPosition(m_window));
            // if (isButtonClicked(startButton, mousePos)) { ... }
        }
    }
    */
}

void TitleScreen::update(float deltaTime) {
    // ����� ��ư ���ÿ� ���� �ð��� �ǵ���� updateButtonSelection()���� ó���ǹǷ�,
    // �߰����� ���� ������Ʈ ������ �ʿ��� �� �����մϴ�.
}

void TitleScreen::draw(sf::RenderWindow& window) {
    window.clear();

    window.draw(backSprite);
    window.draw(logoSprite);
    window.draw(startButton);
    window.draw(exitButton);

    window.display();
}

void TitleScreen::updateButtonSelection() {
    for (sf::Text* button : m_buttons) {
        button->setFillColor(sf::Color::White);
    }
    if (!m_buttons.empty()) {
        m_buttons[m_selectedButtonIndex]->setFillColor(sf::Color::Red); // ���õ� ��ư ����
    }
}

void TitleScreen::activateSelectedButton() {
    if (m_selectedButtonIndex == 0) { // ���� ��ư
        std::cout << "Start Game (����� ����˴ϴ�)" << std::endl;
        m_finished = true;
        m_nextState = GameState::Exiting; // �̿ϼ� ȭ���̹Ƿ� �ӽ÷� ���� ���·� ��ȯ
    }
    else if (m_selectedButtonIndex == 1) { // ���� ��ư
        std::cout << "Exit Game" << std::endl;
        m_finished = true;
        m_nextState = GameState::Exiting;
    }
}

bool TitleScreen::isButtonClicked(const sf::Text& button, const sf::Vector2f& mousePos) {
    // �� �Լ��� ���� ���콺 Ŭ�� ������ �ּ� ó���Ǿ� ������ �ʽ��ϴ�.
    // ���콺 Ŭ�� ����� �ٽ� Ȱ��ȭ�Ϸ���, �� �Լ��� window ������ ���� �� �ֵ��� �����ؾ� �մϴ�.
    return button.getGlobalBounds().contains(mousePos);
}

GameState TitleScreen::run(sf::RenderWindow& window) {
    sf::Clock clock;

    // TODO: ��� ���� ��� ���� (���� ����)
    // m_bgMusic.play();

    while (window.isOpen() && !m_finished) {
        float deltaTime = clock.restart().asSeconds();

        while (const std::optional<sf::Event> eventOpt = window.pollEvent()) {
            handleEvent(*eventOpt);
        }

        update(deltaTime);
        draw(window);
    }

    // TODO: ��� ���� ���� (���� ����)
    // m_bgMusic.stop();

    return m_nextState;
}