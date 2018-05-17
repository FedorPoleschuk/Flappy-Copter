#include <SFML/Graphics.hpp>




using namespace sf;

class Entity {
public:
	
	float dx, dy, x, y, speed, moveTimer;//�������� ���������� ������ ��� ������� �����
	int w, h, health;
	bool life, isMove, onGround;
	Texture texture;
	Sprite sprite;
	String name;//����� ����� ���� ������, �� �� ����� ������ ������ ����� ��� �������������� �����.����� ���� �������� ������ �� ����� � ����� ������� ���� �������� � update � ����������� �� �����
	Entity(Image &image, float X, float Y, int W, int H, String Name) {
		x = X; y = Y; w = W; h = H; name = Name; moveTimer = 0;
		speed = 0; health = 100; dx = 0; dy = 0;
		life = true; onGround = false; isMove = false;
		texture.loadFromImage(image);
		sprite.setTexture(texture);
		sprite.setOrigin(w / 2, h / 2);
	}
	FloatRect getRect() {
		return FloatRect(x, y, w, h);
	}
};
////////////////////////////////////////////////////����� ������////////////////////////
class Player :public Entity {
public:
	enum { left, right, up, down, jump, stay } state;//��������� ��� ������������ - ��������� �������
	int playerScore;//��� ���������� ����� ���� ������ � ������
	Player(Image &image, float X, float Y, int W, int H, String Name) :Entity(image, X, Y, W, H, Name) {
		playerScore = 0; state = stay;
		
			
			
		
	}
	float currentFrame = 0;
	Clock clock;
	void control() {

		float watch = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		watch = watch / 400;

		if (name == "Player1") {
			currentFrame += 0.005*watch; //������ ��� ����������� �� "������". ���������� ������� �� ���� �������� ������������ ������� � ��������. ������� 0.005 ����� �������� �������� ��������
			if (currentFrame > 6) currentFrame -= 6; // ���� ������ � �������� ����� - ������������ �����.
			sprite.setTextureRect(IntRect(363 + 363 * int(currentFrame), 0, w, h));
		}
		if (Keyboard::isKeyPressed) {//���� ������ �������
			if (Keyboard::isKeyPressed(Keyboard::Left)) {//� ������ �����
				state = left; speed = 0.1;
				if (name == "Player1") {
					currentFrame += 0.005*watch; //������ ��� ����������� �� "������". ���������� ������� �� ���� �������� ������������ ������� � ��������. ������� 0.005 ����� �������� �������� ��������
					if (currentFrame > 6) currentFrame -= 6; // ���� ������ � �������� ����� - ������������ �����.
					sprite.setTextureRect(IntRect(363 + 363 * int(currentFrame), 0, w, h));
				}
			}
			if (Keyboard::isKeyPressed(Keyboard::Right)) {
				state = right; speed = 0.2;
				if (name == "Player1") {
					currentFrame += 0.005*watch; //������ ��� ����������� �� "������". ���������� ������� �� ���� �������� ������������ ������� � ��������. ������� 0.005 ����� �������� �������� ��������
					if (currentFrame > 6) currentFrame -= 6; // ���� ������ � �������� ����� - ������������ �����.
					sprite.setTextureRect(IntRect(363 + 363 * int(currentFrame), 0, w, h));
				}
				}
			
			if (Keyboard::isKeyPressed(Keyboard::Up)) {//���� ������ ������� ����� � �� �� �����, �� ����� �������
				state = up; speed = 0.2;//�������� ������ ������
				if (name == "Player1") {
					currentFrame += 0.005*watch; //������ ��� ����������� �� "������". ���������� ������� �� ���� �������� ������������ ������� � ��������. ������� 0.005 ����� �������� �������� ��������
					if (currentFrame > 6) currentFrame -= 6; // ���� ������ � �������� ����� - ������������ �����.
					sprite.setTextureRect(IntRect(363 + 363 * int(currentFrame), 0, w, h));
				}
				}
			if (Keyboard::isKeyPressed(Keyboard::Down)) {
				state = down; speed = 0.2;
				if (name == "Player1") {
					currentFrame += 0.005*watch; //������ ��� ����������� �� "������". ���������� ������� �� ���� �������� ������������ ������� � ��������. ������� 0.005 ����� �������� �������� ��������
					if (currentFrame > 6) currentFrame -= 6; // ���� ������ � �������� ����� - ������������ �����.
					sprite.setTextureRect(IntRect(363 + 363 * int(currentFrame), 0, w, h));
				}
				}
		}
	}
	void checkCollisionWithMap(float Dx, float Dy)//� ��� �������� ������������ � ������
	{
	//	for (int i = y / 275; i < (y + h) / 275; i++)//���������� �� ��������� �����
	//		for (int j = x / 372; j<(x + w) / 372; j++)
	//		{
	//			if ((TileMap[i][j] == '0')|| (TileMap[i][j] == 's'))//���� ������� ��� ������ �����? ��
	//			{
	//			//	if (Dy>0) { y = i * 124 - h;  dy = 0; onGround = true; }//�� Y ����=>���� � ���(����� �� �����) ��� ������. � ���� ������ ���� ���������� ��������� � ��������� ��� �� �����, ��� ���� ������� ��� �� �� ����� ��� ����� ����� ����� �������
	//			//	if (Dy<0) { y = i * 124 + 124;  dy = 0; }//������������ � �������� ������ �����(����� � �� �����������)
	//			//	if (Dx>0) { x = j * 363 - w; }//� ������ ����� �����
	//			//	if (Dx<0) { x = j * 363 + 363; }// � ����� ����� �����
	//			}
	//			//else { onGround = false; }//���� ������ �.� �� ����� ���������� � �� ������ ����������� ��� ��������� ������� �������� ����
	//		}
	}
	void update(float time)
	{
		control();//������� ���������� ����������
		switch (state)//��� �������� ��������� �������� � ����������� �� ���������
		{
		case right:dx = speed;  break;//��������� ���� ������
		case left: dx = -speed; break;//��������� ���� �����
		case up:   dx = 0; dy =0.05 - speed; break;//����� ��������� �������� ������ (�������� �� ��������)
		case down: dx = 0; dy =0.05 + speed; break;//����� ��������� �� ����� ������ ��������� (�������� �� ��������)
		case stay: break;//� ����� ����		
		}
		x += 0.1 * time;
		//checkCollisionWithMap(dx, 0);//������������ ������������ �� �
		y += dy * time;
		if (x > 73125) x = 2250;
		if (y < 100) y = 100;
		if (y > 2600) y = 2600;
		checkCollisionWithMap(0, dy);//������������ ������������ �� Y
		sprite.setPosition(x + w / 2, y + h / 2); //������ ������� ������� � ����� ��� ������
		if (health <= 0) { life = false; }
		speed = 0; 
		if (!onGround) { dy =  0.05; }//������� � ����� ������ ����������� � �����
		if (life) { getplayercoordinateforview(x, y); }
		//dy = dy + 0.05*time;//��������� ������������� � �����
	}
};
class Enemy :public Entity {
public:
	Enemy(Image &image, float X, float Y, int W, int H, String Name) :Entity(image, X, Y, W, H, Name) {
		if (name == "EasyEnemy") {
			
			



			dx = -0.3;//���� ��������.���� ������ ������ ���������
		}
	}
	void checkCollisionWithMap(float Dx, float Dy)//� ��� �������� ������������ � ������
	{
	//	for (int i = y / 32; i < (y + h) / 32; i++)//���������� �� ��������� �����
	//		for (int j = x / 32; j<(x + w) / 32; j++)
	//		{
	//			if (TileMap[i][j] == '0')//���� ������� ��� ������ �����, ��
	//			{
	//				if (Dy>0) { y = i * 32 - h; }//�� Y ����=>���� � ���(����� �� �����) ��� ������. � ���� ������ ���� ���������� ��������� � ��������� ��� �� �����, ��� ���� ������� ��� �� �� ����� ��� ����� ����� ����� �������
	//				if (Dy<0) { y = i * 32 + 32; }//������������ � �������� ������ �����(����� � �� �����������)
	//				if (Dx>0) { x = j * 32 - w; dx = -0.1; sprite.scale(-1, 1); }//� ������ ����� �����
	//				if (Dx<0) { x = j * 32 + 32; dx = 0.1; sprite.scale(-1, 1); }// � ����� ����� �����
	//			}
	//		}
	}
	float currentFrame = 0;
	Clock clock;
	void update(float time)
	{
		
		float watch = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		watch = watch / 800;


		//��� ��������� � ����� ������ ������ ����� �����
								  //moveTimer += time;if (moveTimer>3000){ dx *= -1; moveTimer = 0; }//������ ����������� �������� ������ 3 ���
			

			currentFrame += 0.005*watch; //������ ��� ����������� �� "������". ���������� ������� �� ���� �������� ������������ ������� � ��������. ������� 0.005 ����� �������� �������� ��������
			if (currentFrame > 6) currentFrame -= 6; // ���� ������ � �������� ����� - ������������ �����.
			sprite.setTextureRect(IntRect(210 * int(currentFrame), 0, w, h));
			
			checkCollisionWithMap(dx, 0);//������������ ������������ �� �
			x += dx * time;
			if (x < 0) x = 70000;
			sprite.setPosition(x + w / 2, y + h / 2); //������ ������� ������� � ����� ��� ������
			if (health <= 0) { life = false; }

		
	}
};