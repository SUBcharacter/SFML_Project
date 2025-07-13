#pragma once
#include "IntegrationLibrary.h"

class Camera
{
private:
	sf::View view;

	// ȭ�� ��� (�÷��̾ ���� ������ ī�޶� �̵�)
	float C_top;
	float C_bottom;

	// ī�޶� �߽� ��ġ ����
	float C_viewWidth;
	float C_viewHeight ;


public:
	Camera(float width, float height); // ȭ�� �ʺ�� ���� �Է¹޾� �ʱ�ȭ

	void C_UpdateView(const sf::Vector2f& playerPositon); // �÷��̾� ��ġ�� ���� ī�޶� ����

	sf::View C_GetView() const; // �� ��ȯ



};

