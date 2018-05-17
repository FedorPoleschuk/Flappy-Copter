#include "player.h"

Player::Player()
{
	// ��������� � ���������� �������� ����
	playerSpeed = 400;

	// ��������� �������� � ������
	playerTexture.loadFromFile("player.png");
	playerSprite.setTexture(playerTexture);

	// ������������� ��������� ������� ���� � ��������
	playerPosition.x = 500;
	playerPosition.y = 800;

}

// ������ ��������� ������ ��������� ��� ������� draw()
Sprite Player::getSprite()
{
	return playerSprite;
}

void Player::move(int type)
{
	if (type == 1) m_LeftPressed = true;
}

void Bob::moveRight()
{
	m_RightPressed = true;
}

void Bob::stopLeft()
{
	m_LeftPressed = false;
}

void Bob::stopRight()
{
	m_RightPressed = false;
}

// ������� ���� �� ��������� ����������������� ����� � ���� �����,
// ���������� ������� � ��������
void Bob::update(float elapsedTime)
{
	if (m_RightPressed)
	{
		m_Position.x += m_Speed * elapsedTime;
	}

	if (m_LeftPressed)
	{
		m_Position.x -= m_Speed * elapsedTime;
	}

	// ������ �������� ������ �� ����� �������
	m_Sprite.setPosition(m_Position);

}