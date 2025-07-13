#include "Platform.h"

Platform::Platform() : platformSprite(platformTex)
{
	if (!platformTex.loadFromFile("Assets/platform.png"))
	{
		cerr << "���� : �ؽ��� ���� ����" << endl;
		return;
	}
	platformSprite.setTexture(platformTex);
	FloatRect bounds = platformSprite.getGlobalBounds();
	platformSprite.setOrigin(bounds.width/2.f)
}
