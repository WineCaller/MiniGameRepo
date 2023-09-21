# SFML ���̺귯�� ��ġ

## ������Ʈ

## �ٿ�ε�
- C++ 17 : 2022 / 32��Ʈ

## ���� ����
```
- MiniGame - External - include
				      - lib
		   - MiniGame
		   - MiniGame.sln
```

- SFML > include ��ü ����/���� => - MiniGame - External - include
- SFML > lib ��ü ����/���� => - MiniGame - External - lib
- SFML > bin ��ü ���� => - MiniGame - MiniGame

# VS 2022 ȯ�� ����

- Solution Explorer > Drop Down Menu > Properies
- ��� ���� ����
	- Configuration > All Configuration
	- Platform > Win32
- C/C++ > General > Aditional include Directories
	- SFML���� �����ؿ� ����/������ �ִ� ��ġ�� ���� 
	- $(SolutionDir) : ���� ������Ʈ ���� ���
	
- Linker > Genaral > Additional Library Directories
	- SFML���� �����ؿ� ����/������ �ִ� ��ġ�� ����
	
- Linker > Input > additional Dependancies
	- Configuration > Release

```
 sfml-system.lib
 sfml-graphics.ilb
 sfml-window.lib
 sfml-audio.lib
 sfml-network.lib
```

- Linker > Input > additional Dependancies
	- Configuration > Debug
	
```
 sfml-system-d.lib
 sfml-graphics-d.ilb
 sfml-window-d.lib
 sfml-audio-d.lib
 sfml-network-d.lib
```

# Event

## Event ����
- ���, ��Ȳ�� ��ȭ
- Interface�� �����ؼ� ����� ��Ȳ�� ��ȭ
- Ű����, ���콺�� ����� ��Ȳ�� ��ȭ
	- Ű���� �̺�Ʈ : Ű �Է�
	- ���콺 �̺�Ʈ : ���콺 Ŭ��( Push / Release), �� ��ũ��, ���� Ŭ��, ������
- ��ġ ��ũ�� : ��ġ, ��������, ��ġ
- �ε�

## Event Handing

- Event Delegate
- Event Listening