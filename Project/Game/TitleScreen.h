#pragma once
#include "IntegrationLibrary.h"

class TitleScreen {
public:
    TitleScreen(const string& backgroundTexturePath);

    void run(RenderWindow& window);

private:
    Texture backgroundTexture;
    Sprite backgroundSprite;   // �� �κп��� �⺻ ������ ������ �߻��� �� �ֽ��ϴ�.

    Font font;
    Text titleText;            // �� �κп��� �⺻ ������ ������ �߻��� �� �ֽ��ϴ�.
};


// ������
// 1. AI �������� ����. AI �˻��뵵�θ� ����� ��.
// 2. �ȵȴٰ� �������� ����
// 3. AI�� �� �ڵ带 �����ϰ� ����� ��
//