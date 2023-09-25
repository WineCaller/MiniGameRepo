#include <iostream>

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

using namespace sf;
using namespace std;

void SmpleWindow()
{
	// ������ â�� �����ϱ�
	RenderWindow Window(VideoMode(1024, 768), "Mini Game", Style::Titlebar | Style::Close);

	Event e;

	while (Window.isOpen()) // isOpen() : Window Open ���� Ȯ�� => true
	{
		//Close ��ư�� Ŭ�� Event ���� => Window Close
		while (Window.pollEvent(e)) // Event ����
		{
			// Event type ����
			switch (e.type)
			{
			case Event::Closed: // Window Close ��ư �̺�Ʈ ����
					Window.close();
					break;
			}
		}
	}
}