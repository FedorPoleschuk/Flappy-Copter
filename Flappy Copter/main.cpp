#include <SFML/Graphics.hpp>
#include "map.h"
#include "view.h"
#include <sstream>
#include "player.h"
#include <SFML/Audio.hpp>
using namespace sf;

int main()
{
	RenderWindow window(VideoMode(1366, 768), "Pink Helicopter", sf::Style::Fullscreen);
	view.reset(FloatRect(0, 0, 1366, 768));
	sf::Music music;
	if (!music.openFromFile("sound.wav"))
		return -1; // error
	music.play();
	
	Image map_image;
	map_image.loadFromFile("kpm2.png");
	Texture map;
	map.loadFromImage(map_image);
	Sprite s_map;
	s_map.setTexture(map);

	Image cloud_image;
	cloud_image.loadFromFile("cloud.png");
	Texture cloud;
	cloud.loadFromImage(cloud_image);
	Sprite s_cloud;
	s_cloud.setTexture(cloud);

	Image tree_image;
	tree_image.loadFromFile("tree.png");
	Texture tree;
	tree.loadFromImage(tree_image);
	Sprite s_tree;
	s_tree.setTexture(tree);



	

	Image quest_image;
	Image heroImage;
	heroImage.loadFromFile("hero.png");
	Player p(heroImage, 1000, 500, -363, 124, "Player1");

	Image easyEnemyImage;
	easyEnemyImage.loadFromFile("bird.png");
	easyEnemyImage.createMaskFromColor(Color(255, 0, 0));//сделали маску по цвету.но лучше изначально иметь прозрачную картинку
	Enemy easyEnemy(easyEnemyImage, 5452, 671, 200, 124, "EasyEnemy");//простой враг, объект класса врага
	Enemy easyEnemy1(easyEnemyImage, 10000, 1871, 200, 124, "EasyEnemy");//простой враг, объект класса врага
	Enemy easyEnemy2(easyEnemyImage, 5400, 1671, 200, 124, "EasyEnemy");//простой враг, объект класса врага
	Enemy easyEnemy3(easyEnemyImage, 20500, 3671, 200, 124, "EasyEnemy");//простой враг, объект класса врага
	Enemy easyEnemy4(easyEnemyImage, 25600, 1261, 200, 124, "EasyEnemy");//простой враг, объект класса врага
	Enemy easyEnemy5(easyEnemyImage, 30042, 861, 200, 124, "EasyEnemy");//простой враг, объект класса врага
	Enemy easyEnemy6(easyEnemyImage, 5234, 961, 200, 124, "EasyEnemy");//простой враг, объект класса врага
	Enemy easyEnemy7(easyEnemyImage, 10570, 871, 200, 124, "EasyEnemy");//простой враг, объект класса врага
	Enemy easyEnemy8(easyEnemyImage, 5052, 361, 200, 124, "EasyEnemy");//простой враг, объект класса врага
	Enemy easyEnemy9(easyEnemyImage, 50960, 1571, 200, 124, "EasyEnemy");//простой враг, объект класса врага
	Enemy easyEnemy11(easyEnemyImage, 5323, 471, 200, 124, "EasyEnemy");//простой враг, объект класса врага
	Enemy easyEnemy21(easyEnemyImage, 16400, 1691, 200, 124, "EasyEnemy");//простой враг, объект класса врага
	Enemy easyEnemy31(easyEnemyImage, 5300, 8671, 200, 124, "EasyEnemy");//простой враг, объект класса врага
	Enemy easyEnemy41(easyEnemyImage, 5080, 461, 200, 124, "EasyEnemy");//простой враг, объект класса врага
	Enemy easyEnemy51(easyEnemyImage, 30000, 371, 200, 124, "EasyEnemy");//простой враг, объект класса врага
	Enemy easyEnemy61(easyEnemyImage, 35745, 971, 200, 124, "EasyEnemy");//простой враг, объект класса врага
	Enemy easyEnemy71(easyEnemyImage, 40740, 4651, 200, 124, "EasyEnemy");//простой враг, объект класса врага
	Enemy easyEnemy81(easyEnemyImage, 45225, 3671, 200, 124, "EasyEnemy");//простой враг, объект класса врага
	Enemy easyEnemy91(easyEnemyImage, 5240,1671, 200, 124, "EasyEnemy");//простой враг, объект класса врага
	Enemy easyEnemy12(easyEnemyImage, 10552, 261, 200, 124, "EasyEnemy");//простой враг, объект класса врага
	Enemy easyEnemy22(easyEnemyImage, 1531, 8671, 200, 124, "EasyEnemy");//простой враг, объект класса врага
	Enemy easyEnemy32(easyEnemyImage, 28269, 1071, 200, 124, "EasyEnemy");//простой враг, объект класса врага
	Enemy easyEnemy42(easyEnemyImage, 2950, 561, 200, 124, "EasyEnemy");//простой враг, объект класса врага
	Enemy easyEnemy52(easyEnemyImage, 30070, 1771, 200, 124, "EasyEnemy");//простой враг, объект класса врага
	Enemy easyEnemy62(easyEnemyImage, 37960, 9671, 200, 124, "EasyEnemy");//простой враг, объект класса врага
	Enemy easyEnemy72(easyEnemyImage, 43050, 471, 200, 124, "EasyEnemy");//простой враг, объект класса врага
	Enemy easyEnemy82(easyEnemyImage, 46060, 671, 200, 124, "EasyEnemy");//простой враг, объект класса врага
	Enemy easyEnemy92(easyEnemyImage, 54640, 171, 200, 124, "EasyEnemy");//простой враг, объект класса врага



	float currentFrame = 0;
	Clock clock;
	while (window.isOpen())
	{
		float time = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		time = time / 400;
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		if (Keyboard::isKeyPressed(Keyboard::Escape))
		{
			window.close();
		}
		p.update(time);// Player update function
		
		



		easyEnemy.update(time);//easyEnemy update function
		easyEnemy1.update(time);
		easyEnemy2.update(time);
		easyEnemy3.update(time);
		easyEnemy4.update(time);
		easyEnemy5.update(time);
		easyEnemy6.update(time);
		easyEnemy7.update(time);
		easyEnemy8.update(time);
		easyEnemy9.update(time);
		easyEnemy11.update(time);//easyEnemy update function
		easyEnemy21.update(time);
		easyEnemy21.update(time);
		easyEnemy31.update(time);
		easyEnemy41.update(time);
		easyEnemy51.update(time);
		easyEnemy61.update(time);
		easyEnemy71.update(time);
		easyEnemy81.update(time);
		easyEnemy91.update(time);//easyEnemy update function
		easyEnemy12.update(time);
		easyEnemy22.update(time);
		easyEnemy32.update(time);
		easyEnemy42.update(time);
		easyEnemy52.update(time);
		easyEnemy62.update(time);
		easyEnemy72.update(time);
		easyEnemy82.update(time);
		easyEnemy92.update(time);
		
		window.setView(view);
		window.clear(Color(164, 221,238));
		for (int i = 0; i < HEIGHT_MAP; i++)
			for (int j = 0; j < WIDTH_MAP; j++)
			{
				if (TileMap[i][j] == 's')  s_map.setTextureRect(IntRect(0, 0, 372, 140));
				if (TileMap[i][j] == ' ')  s_map.setTextureRect(IntRect(32, 0, 0, 0));
				if ((TileMap[i][j] == '0')) s_map.setTextureRect(IntRect(0, 0, 375, 275));
				s_map.setPosition(j *372, i * 275);
				window.draw(s_map);
			}

		for (int i = 0; i < HEIGHT_MAP; i++)
			for (int j = 0; j < WIDTH_MAP; j++)
			{
				if (Cloud[i][j] == 's')  s_cloud.setTextureRect(IntRect(0, 0, 372, 275));
				if (Cloud[i][j] == ' ')  s_cloud.setTextureRect(IntRect(32, 0, 0, 0));
				if ((Cloud[i][j] == '0')) s_cloud.setTextureRect(IntRect(0, 0, 375, 275));
				s_cloud.setPosition(j * 372, i * 275);
				window.draw(s_cloud);
			}

		for (int i = 0; i < 5; i++)
			for (int j = 0; j < WIDTH_MAP; j++)
			{
				if (Cloud[i][j] == 's')  s_tree.setTextureRect(IntRect(0, 0, 0, 0));
				if (Cloud[i][j] == ' ')  s_tree.setTextureRect(IntRect(32, 0, 0, 0));
				if ((Tree[i][j] == 't')) s_tree.setTextureRect(IntRect(0, 0, 375, 550));
				s_tree.setPosition(j * 372, i * 550);
				window.draw(s_tree);
			}


		window.draw(easyEnemy.sprite);
		window.draw(easyEnemy1.sprite);
		window.draw(easyEnemy2.sprite);
		window.draw(easyEnemy3.sprite);
		window.draw(easyEnemy4.sprite);
		window.draw(easyEnemy5.sprite);
		window.draw(easyEnemy6.sprite);
		window.draw(easyEnemy7.sprite);
		window.draw(easyEnemy8.sprite);
		window.draw(easyEnemy9.sprite);
		window.draw(easyEnemy11.sprite);
		window.draw(easyEnemy21.sprite);
		window.draw(easyEnemy31.sprite);
		window.draw(easyEnemy41.sprite);
		window.draw(easyEnemy51.sprite);
		window.draw(easyEnemy61.sprite);
		window.draw(easyEnemy71.sprite);
		window.draw(easyEnemy81.sprite);
		window.draw(easyEnemy91.sprite);
		window.draw(easyEnemy12.sprite);
		window.draw(easyEnemy22.sprite);
		window.draw(easyEnemy32.sprite);
		window.draw(easyEnemy42.sprite);
		window.draw(easyEnemy52.sprite);
		window.draw(easyEnemy62.sprite);
		window.draw(easyEnemy72.sprite);
		window.draw(easyEnemy82.sprite);
		window.draw(easyEnemy92.sprite);
		window.draw(p.sprite);
		window.display();
	}
	return 0;
}