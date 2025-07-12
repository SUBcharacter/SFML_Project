#include "Platform.h"

Platform::Platform() : platformSprit(platformTex)
{
	if (!platformTex.loadFromFile("PlatformAssets/Platform.png"))
	{
		cout << "���� : �÷��� ��������Ʈ�� ã�� �� ����" << endl;
		return;
	}
	platformRect = IntRect({ 10,10 }, { 30,20 });
	platformSprit.setTextureRect(platformRect);
	platformSprit.setOrigin({ 30.f,30.f });
	platformSprit.setPosition({ 400,300 });
	SetPlatformPos();
}

void Platform::SetPlatformPos()
{
	platformPos.x = platformSprit.getPosition().x;
	platformPos.y = platformSprit.getPosition().y;
}

Pos Platform::GetPlatformPos()
{
	SetPlatformPos();
	return platformPos;
}

void Platform::Draw(RenderWindow& window)
{
	window.draw(platformSprit);
}
