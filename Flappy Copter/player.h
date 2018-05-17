#include <SFML/Graphics.hpp>




using namespace sf;

class Entity {
public:
	
	float dx, dy, x, y, speed, moveTimer;//добавили переменную таймер для будущих целей
	int w, h, health;
	bool life, isMove, onGround;
	Texture texture;
	Sprite sprite;
	String name;//враги могут быть разные, мы не будем делать другой класс для различающегося врага.всего лишь различим врагов по имени и дадим каждому свое действие в update в зависимости от имени
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
////////////////////////////////////////////////////КЛАСС ИГРОКА////////////////////////
class Player :public Entity {
public:
	enum { left, right, up, down, jump, stay } state;//добавляем тип перечисления - состояние объекта
	int playerScore;//эта переменная может быть только у игрока
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
			currentFrame += 0.005*watch; //служит для прохождения по "кадрам". переменная доходит до трех суммируя произведение времени и скорости. изменив 0.005 можно изменить скорость анимации
			if (currentFrame > 6) currentFrame -= 6; // если пришли к третьему кадру - откидываемся назад.
			sprite.setTextureRect(IntRect(363 + 363 * int(currentFrame), 0, w, h));
		}
		if (Keyboard::isKeyPressed) {//если нажата клавиша
			if (Keyboard::isKeyPressed(Keyboard::Left)) {//а именно левая
				state = left; speed = 0.1;
				if (name == "Player1") {
					currentFrame += 0.005*watch; //служит для прохождения по "кадрам". переменная доходит до трех суммируя произведение времени и скорости. изменив 0.005 можно изменить скорость анимации
					if (currentFrame > 6) currentFrame -= 6; // если пришли к третьему кадру - откидываемся назад.
					sprite.setTextureRect(IntRect(363 + 363 * int(currentFrame), 0, w, h));
				}
			}
			if (Keyboard::isKeyPressed(Keyboard::Right)) {
				state = right; speed = 0.2;
				if (name == "Player1") {
					currentFrame += 0.005*watch; //служит для прохождения по "кадрам". переменная доходит до трех суммируя произведение времени и скорости. изменив 0.005 можно изменить скорость анимации
					if (currentFrame > 6) currentFrame -= 6; // если пришли к третьему кадру - откидываемся назад.
					sprite.setTextureRect(IntRect(363 + 363 * int(currentFrame), 0, w, h));
				}
				}
			
			if (Keyboard::isKeyPressed(Keyboard::Up)) {//если нажата клавиша вверх и мы на земле, то можем прыгать
				state = up; speed = 0.2;//увеличил высоту прыжка
				if (name == "Player1") {
					currentFrame += 0.005*watch; //служит для прохождения по "кадрам". переменная доходит до трех суммируя произведение времени и скорости. изменив 0.005 можно изменить скорость анимации
					if (currentFrame > 6) currentFrame -= 6; // если пришли к третьему кадру - откидываемся назад.
					sprite.setTextureRect(IntRect(363 + 363 * int(currentFrame), 0, w, h));
				}
				}
			if (Keyboard::isKeyPressed(Keyboard::Down)) {
				state = down; speed = 0.2;
				if (name == "Player1") {
					currentFrame += 0.005*watch; //служит для прохождения по "кадрам". переменная доходит до трех суммируя произведение времени и скорости. изменив 0.005 можно изменить скорость анимации
					if (currentFrame > 6) currentFrame -= 6; // если пришли к третьему кадру - откидываемся назад.
					sprite.setTextureRect(IntRect(363 + 363 * int(currentFrame), 0, w, h));
				}
				}
		}
	}
	void checkCollisionWithMap(float Dx, float Dy)//ф ция проверки столкновений с картой
	{
	//	for (int i = y / 275; i < (y + h) / 275; i++)//проходимся по элементам карты
	//		for (int j = x / 372; j<(x + w) / 372; j++)
	//		{
	//			if ((TileMap[i][j] == '0')|| (TileMap[i][j] == 's'))//если элемент наш тайлик земли? то
	//			{
	//			//	if (Dy>0) { y = i * 124 - h;  dy = 0; onGround = true; }//по Y вниз=>идем в пол(стоим на месте) или падаем. В этот момент надо вытолкнуть персонажа и поставить его на землю, при этом говорим что мы на земле тем самым снова можем прыгать
	//			//	if (Dy<0) { y = i * 124 + 124;  dy = 0; }//столкновение с верхними краями карты(может и не пригодиться)
	//			//	if (Dx>0) { x = j * 363 - w; }//с правым краем карты
	//			//	if (Dx<0) { x = j * 363 + 363; }// с левым краем карты
	//			}
	//			//else { onGround = false; }//надо убрать т.к мы можем находиться и на другой поверхности или платформе которую разрушит враг
	//		}
	}
	void update(float time)
	{
		control();//функция управления персонажем
		switch (state)//тут делаются различные действия в зависимости от состояния
		{
		case right:dx = speed;  break;//состояние идти вправо
		case left: dx = -speed; break;//состояние идти влево
		case up:   dx = 0; dy =0.05 - speed; break;//будет состояние поднятия наверх (например по лестнице)
		case down: dx = 0; dy =0.05 + speed; break;//будет состояние во время спуска персонажа (например по лестнице)
		case stay: break;//и здесь тоже		
		}
		x += 0.1 * time;
		//checkCollisionWithMap(dx, 0);//обрабатываем столкновение по Х
		y += dy * time;
		if (x > 73125) x = 2250;
		if (y < 100) y = 100;
		if (y > 2600) y = 2600;
		checkCollisionWithMap(0, dy);//обрабатываем столкновение по Y
		sprite.setPosition(x + w / 2, y + h / 2); //задаем позицию спрайта в место его центра
		if (health <= 0) { life = false; }
		speed = 0; 
		if (!onGround) { dy =  0.05; }//убираем и будем всегда притягивать к земле
		if (life) { getplayercoordinateforview(x, y); }
		//dy = dy + 0.05*time;//постоянно притягиваемся к земле
	}
};
class Enemy :public Entity {
public:
	Enemy(Image &image, float X, float Y, int W, int H, String Name) :Entity(image, X, Y, W, H, Name) {
		if (name == "EasyEnemy") {
			
			



			dx = -0.3;//даем скорость.этот объект всегда двигается
		}
	}
	void checkCollisionWithMap(float Dx, float Dy)//ф ция проверки столкновений с картой
	{
	//	for (int i = y / 32; i < (y + h) / 32; i++)//проходимся по элементам карты
	//		for (int j = x / 32; j<(x + w) / 32; j++)
	//		{
	//			if (TileMap[i][j] == '0')//если элемент наш тайлик земли, то
	//			{
	//				if (Dy>0) { y = i * 32 - h; }//по Y вниз=>идем в пол(стоим на месте) или падаем. В этот момент надо вытолкнуть персонажа и поставить его на землю, при этом говорим что мы на земле тем самым снова можем прыгать
	//				if (Dy<0) { y = i * 32 + 32; }//столкновение с верхними краями карты(может и не пригодиться)
	//				if (Dx>0) { x = j * 32 - w; dx = -0.1; sprite.scale(-1, 1); }//с правым краем карты
	//				if (Dx<0) { x = j * 32 + 32; dx = 0.1; sprite.scale(-1, 1); }// с левым краем карты
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


		//для персонажа с таким именем логика будет такой
								  //moveTimer += time;if (moveTimer>3000){ dx *= -1; moveTimer = 0; }//меняет направление примерно каждые 3 сек
			

			currentFrame += 0.005*watch; //служит для прохождения по "кадрам". переменная доходит до трех суммируя произведение времени и скорости. изменив 0.005 можно изменить скорость анимации
			if (currentFrame > 6) currentFrame -= 6; // если пришли к третьему кадру - откидываемся назад.
			sprite.setTextureRect(IntRect(210 * int(currentFrame), 0, w, h));
			
			checkCollisionWithMap(dx, 0);//обрабатываем столкновение по Х
			x += dx * time;
			if (x < 0) x = 70000;
			sprite.setPosition(x + w / 2, y + h / 2); //задаем позицию спрайта в место его центра
			if (health <= 0) { life = false; }

		
	}
};