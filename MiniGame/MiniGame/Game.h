#pragma once
#include <iostream>
#include <vector>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

using namespace sf;
using namespace std;

class Game
{
private:

	//Event
	sf::Event e;

	// Window
	sf::RenderWindow* Window;
	sf::VideoMode VMode;
	
	// Window ������ ���� �ʱ�ȭ
	void InitWindowPointer();

	// Window ���� ����
	void InitWindow();

	// ���� ������ Window ����
	void Deletewindow();

	// Enemy
	RectangleShape RectEnemy;
	vector<RectangleShape> RectEnemies;

	// Spawn Value
	float EnemySpawnTime;
	float EnemySpawnTimeMax;
	int EnemyMaxNumber;

	// InitRectEnemy
	void InitRectEnemy();

	// Set Spawn Value
	void SetSpawnValue();

	// Player
	CircleShape Player;
	// int player
	void initPlayer();

public:
	
	// constructor
	Game();
	
	// destructor
	~Game();

	// Enemy
	
	// Spawn Enemy
	void SpawnEnemy();

	void UpdateEnemy();

	// Player

	void UpdatePlayer();

	// Collision

	void UpdateCollision();
	void Gameover();

	// Game Loop
	// �� const : ��ȯ���� ������� ����
	// �� const : �Ű�����, �Լ� ���� ���� �����������
	const bool Running() const;

	void EventHandler();

	void Update();

	void Render();

	
};