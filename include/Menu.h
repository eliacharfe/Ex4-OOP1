#pragma once
#include "GameObject.h"
#include "consts.h"

class Menu
{
public:
	Menu();

	void Draw(sf::RenderWindow& window);

	void setMenu();

	int getWidth()const;
	
	char GetObjectType() const;
	void buttomPressed(sf::Vector2f location);

	//bool GetifObjectPressed();

private:
	std::vector<GameObject> m_gameObject;
	sf::Vector2f size;

	char m_char;
};