#include "Physics.h"

void Physics::Jump()
{

	if (isOnGround) {
		velocityY = -10.0f;  // ���� ��
		isOnGround = false;
	}

}

void Physics::Collision()
{
    velocityY += gravity;
    playery += static_cast<int>(velocityY);

    // �浹 üũ
    int playerBottom = playery + playerh;
    int platformTop = platformy;

    bool inXRange = (playerx + playerw > platformx) && (playerx < platformx + platformw);
    bool onPlatform = (playerBottom >= platformTop) && (playerBottom <= platformTop + platformh);

    if (inXRange && onPlatform && velocityY >= 0) {
        playery = platformy - playerh;
        velocityY = 0;
        isOnGround = true;
    }
    else {
        isOnGround = false;
    }
}
