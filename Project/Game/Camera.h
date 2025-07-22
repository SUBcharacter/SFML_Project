#pragma once
#include "IntegrationLibrary.h"


/*

<Camera Ŭ���� ����>

- �÷��̾ ���/�ϴ� ���(������ ������ ���� ����)�� ������ ī�޶� ���Ʒ��� �̵���.

- ���� ���� �� �÷��̾� ��ġ�� �������� ī�޶� �ʱ�ȭ��.
  ����, ù ���� �� �÷��̾ ȭ�� �߾ӿ� ��ġ��Ű�� ���� �߿���.
  (�ʿ�� ���� �����ϴ� �������ּ���.)

<Camera Ŭ���� ��� ���>

1. ī�޶� ����
   Camera camera(�ʺ�, ����);
   �츮 ���� �ػ󵵴� 600 * 800�̹Ƿ�
   Camera camera(600, 800); ���� �����ϸ� �˴ϴ�.

2. Ÿ��Ʋ ȭ�� �� ����
   Ÿ��Ʋ ������ (0,0) ~ (600,800)�̶��,
   camera.C_StartGame(sf::Vector2f(300.f, 400.f)); ->  Ÿ��Ʋ ȭ�� �߾� ��ǥ�� ī�޶� �ʱ� ��ġ ����

   ���� �÷��� ȭ���� ó�� ���� ��,
   camera.C_StartGame(playerPosition); -> �÷��̾� ��ġ�� ī�޶� �ʱ� ��ġ ����

3. �� �����Ӹ��� �÷��̾� ��ġ�� ���� ī�޶� ������Ʈ
   camera.C_UpdateView(playerPosition);

4. �� ������ �׸��� ���� ȣ���Ͽ� �� ����
   window.setView(camera.C_GetView());

*/


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

	void C_StartGame(const sf::Vector2f& playerPositon); // ���� ������ �� �÷��̾ ���߰� ��

	sf::View C_GetView() const; // �� ��ȯ



};

