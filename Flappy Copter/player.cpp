#include "player.h"

Player::Player()
{
	// Вписываем в переменную скорость Боба
	playerSpeed = 400;

	// Связываем текстуру и спрайт
	playerTexture.loadFromFile("player.png");
	playerSprite.setTexture(playerTexture);

	// Устанавливаем начальную позицию Боба в пикселях
	playerPosition.x = 500;
	playerPosition.y = 800;

}

// Делаем приватный спрайт доступным для функции draw()
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

// Двигаем Боба на основании пользовательского ввода в этом кадре,
// прошедшего времени и скорости
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

	// Теперь сдвигаем спрайт на новую позицию
	m_Sprite.setPosition(m_Position);

}