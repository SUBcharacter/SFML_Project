#include "Player.h"

Player::Player() : playerSprite(playerTexture)
{
	if (!playerTexture.loadFromFile("Assets/player.png"))
	{
		cerr << "���� : player ��������Ʈ ã�� �� ����." << endl;
		return;
	}
	playerSprite.setTextureRect(IntRect({ 0,0 }, { 50,50 }));
	playerSprite.setOrigin({ 25.f,25.f });
	playerSprite.setPosition({ 300.f,500.f });

	Updatehitbox();
	UpdatesenseBox();

}

void Player::SetPlayerPos(float x, float y)
{
	playerSprite.setPosition({ x,y });
	Updatehitbox();
	UpdatesenseBox();
}

void Player::Updatehitbox()
{
	Vector2f spritepos = playerSprite.getPosition();
	Vector2f hitboxsize(30.f, 30.f);
	Vector2f hitboxPos = spritepos - (hitboxsize / 2.f);

	hitBox.position.x = hitboxPos.x;
	hitBox.position.y = hitboxPos.y;
	hitBox.size.x = hitboxPos.x;
	hitBox.size.y = hitboxPos.y;
}

void Player::UpdatesenseBox()
{
	Vector2f spritespos = playerSprite.getPosition();
	Vector2f size(96.f, 80.f);
	Vector2f offset(-48.f, -40.f); 
	Vector2f topLeft = spritespos + offset;

	senseBox = FloatRect(spritespos,offset);
}

void Player::UpdateAnimation()
{

}

void Player::UpdateState()
{
	if (!IsOnGround) // ������ ��
	{
		currentState = PlayerState::Jumping;
	}
	else if (Keyboard::isKeyPressed(Keyboard::Scan::A) && playerSprite.getPosition().x > 0) // ���� Ű ���� ��
	{
		currentState = PlayerState::L_Running;
	}
	else if (Keyboard::isKeyPressed(Keyboard::Scan::D) && playerSprite.getPosition().x < 600) // ������ Ű ���� ��
	{
		currentState = PlayerState::R_Running;
	}
	else // �ƹ��͵� �� �� ��
	{
		currentState = PlayerState::Idle;
	}
}

void Player::Draw(RenderWindow& window)
{
	window.draw(playerSprite);
}

// �ν� ������ �ִ� �� ��ǥ�� �׸��� ��ǥ�� ��ȯ�ϴ� �Լ�
vector<pair<int, int>> Player::GetnearGridcells()
{
	vector<pair<int, int>> neargirdcells;

	float left = senseBox.position.x;
	float top = senseBox.position.y;
	float right = senseBox.position.x + senseBox.size.x;
	float bottom = senseBox.position.y + senseBox.size.y;

	float cellsize = 100.f;

	int gridleft = static_cast<int>(floor(left / cellsize));
	int gridright = static_cast<int>(floor(right / cellsize));
	int gridtop = static_cast<int>(floor(top / cellsize));
	int gridbottom = static_cast<int>(floor(bottom / cellsize));

	for (int y = gridtop; y <= gridbottom ; y++)
	{
		for (int x = gridleft; x <= gridright; x++)
		{
			neargirdcells.emplace_back(x, y);
		}
	}
	return neargirdcells;
}

FloatRect& Player::GetSenseBox()
{
	return senseBox;
}
Vector2f Player::GetPlayerPos()
{
	return playerSprite.getPosition();
}

FloatRect& Player::GetHitBox()
{
	return hitBox;
}

void Player::Move(float deltaTime)
{

	bool jumpKey = Keyboard::isKeyPressed(Keyboard::Scan::W);

	if (jumpKey)
	{
		if (IsOnGround)
		{
			velocityY = -300.f;
			IsOnGround = false;
		}

	}
	
	if (!IsOnGround)
	{
		velocityY += GRAVITY * deltaTime;
		playerSprite.move({ 0.0f, velocityY * deltaTime });
	}

	if (Keyboard::isKeyPressed(Keyboard::Scan::A) && playerSprite.getPosition().x > 0)
	{
		playerSprite.move({ -200.0f * deltaTime ,0.0f });
		playerSprite.setTextureRect(IntRect({ 0,0 }, { 50,50 }));
		playerSprite.setScale({ -1.0f, 1.0f });
	}
	if (Keyboard::isKeyPressed(Keyboard::Scan::D) && playerSprite.getPosition().x < 600)
	{
		playerSprite.move({ 200.0f * deltaTime ,0.0f });
		playerSprite.setTextureRect(IntRect({ 0,0 }, { 50,50 }));
		playerSprite.setScale({ 1.0f, 1.0f });

	}

	Updatehitbox();
	UpdatesenseBox();
}


