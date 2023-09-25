#include "Game.h"

using namespace sf;

void Game::InitWindowPointer()
{
	// nullptr : 주소값이 없는 상태 -> 아무것도 가리키고 있지않은 상태
	this->Window = nullptr;

}

void Game::InitWindow()
{
	this->VMode.width = 1024;
	this->VMode.height = 768;

	this->Window = new sf::RenderWindow(this->VMode, "Mini Game", sf::Style::Titlebar | sf::Style::Close);

	this->Window->setFramerateLimit(144);
}

void Game::Deletewindow()
{
	delete this->Window;
}

void Game::InitRectEnemy()
{
	this->RectEnemy.setSize(Vector2f(50.0f, 50.0f));
	this->RectEnemy.setFillColor(Color::Green);
	this->RectEnemy.setPosition(30.f, 30.f);
}

void Game::SetSpawnValue()
{
	this->EnemySpawnTime = 0.0f;
	this->EnemySpawnTimeMax = 20.0f;
	this->EnemyMaxNumber = 10;
}

void Game::initPlayer()
{
	this->Player.setRadius(20.0f);
	this->Player.setFillColor(Color::White);
	this->Player.setPosition(this->Window->getSize().x / 2, this->Window->getSize().y / 2);

}

Game::Game()
{
	this->InitWindowPointer();
	this->InitWindow();
	
	this->InitRectEnemy();
	this->SetSpawnValue();

	this->initPlayer();
}

Game::~Game()
{
	this->Deletewindow();
}

void Game::SpawnEnemy()
{
	this->RectEnemy.setPosition(static_cast<float>(rand() % 1024),0.0f);
	RectEnemies.push_back(this->RectEnemy);
}

void Game::UpdateEnemy()
{
	// 한 위도우에 표시되는 최대 개수 제한
	if (this->RectEnemies.size() < this->EnemyMaxNumber)
	{
		// 적이 생성되는 시간 간격
		if (this->EnemySpawnTime >= this->EnemySpawnTimeMax)
		{
			this->SpawnEnemy();
			this->EnemySpawnTime = 0.0f;
		}
		else
		{
			this->EnemySpawnTime += 1.0f;
		}

	}
	// 여러 적을 생성되는 즉시 움직임
	this->RectEnemy.move(0.0f, 3.0f);
	for (int i = 0; i < this->RectEnemies.size(); i++)
	{
		this->RectEnemies[i].move(0.0f, 3.0f);
	}
	// 적이 윈도우 바깥으로 벗어나면( Y좌표가 Window의 Y크기를 넘어가면 ) 삭제
	for (int i = 0; i < this->RectEnemies.size(); i++)
	{
		if (this->RectEnemies[i].getPosition().y >= this->Window->getSize().y)
		{
			this->RectEnemies.erase(this->RectEnemies.begin() + i);
		}
	}
}

void Game::UpdatePlayer()
{
	if (Keyboard::isKeyPressed(Keyboard::Left))
	{
		this->Player.move(-5.0f, 0.0f);
	}
	if (Keyboard::isKeyPressed(Keyboard::Right))
	{
		this->Player.move(5.0f, 0.0f);
	}
	if (Keyboard::isKeyPressed(Keyboard::Up))
	{
		this->Player.move(0.0f, -5.0f);
	}
	if (Keyboard::isKeyPressed(Keyboard::Down))
	{
		this->Player.move(0.0f, 5.0f);
	}
}

void Game::UpdateCollision()
{
	for (int i = 0; i < RectEnemies.size(); i++)
	{
		if (this->Player.getGlobalBounds().intersects(this->RectEnemies[i].getGlobalBounds()))
		{
			this->Gameover();
		}

	}
}

void Game::Gameover()
{
	delete this->Window;
}

const bool Game::Running() const
{
	return this->Window->isOpen();
}

void Game::EventHandler()
{
	while (Window->pollEvent(e)) 
	{
		switch (e.type)
		{
		case Event::Closed: 
				Window->close();
				break;
		}
	}
}

void Game::Update()
{
	this->UpdateEnemy();
	this->UpdatePlayer();
	this->UpdateCollision();
}

void Game::Render()
{
	// 이전 프레임에 그려진 내용을 지움
	this->Window->clear();

	// draw object
	// draw Enemy
	for (int i = 0; i < this->RectEnemies.size(); i++)
	{
		this->Window->draw(this->RectEnemies[i]);
	}
	
	// draw player
	this->Window->draw(this->Player);

	
	// display
	this->Window->display();
}

