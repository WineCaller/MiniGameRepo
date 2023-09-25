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
	
	// Window 포인터 변수 초기화
	void InitWindowPointer();

	// Window 동적 생성
	void InitWindow();

	// 동적 생성된 Window 삭제
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
	// 앞 const : 반환값이 변경되지 않음
	// 뒤 const : 매개변수, 함수 내부 값이 변경되지않음
	const bool Running() const;

	void EventHandler();

	void Update();

	void Render();

	
};