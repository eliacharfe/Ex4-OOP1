#include <iostream>
#include "Menu.h"

Menu::Menu() :m_char (EMPTY_CELL) 
{ }
//--------------------------------------------------------
void Menu::Draw(sf::RenderWindow& window)
{
	sf::Vector2f pos;
	pos.x = 0;
	pos.y = 0;
	for (int i = 0; i < m_gameObject.size(); i++)
	{
		m_gameObject[i].SetGameObjectposition( pos );
		m_char = m_gameObject[i].getObjectType();
		m_gameObject[i].DrawMenu(window, i);
		pos.y += BUTTOMS_SIZE_MENU;
	}
}
//--------------------------------------------------
void Menu::setMenu()
{
	sf::Vector2f pos(0, 0);

	for (int i = 0; i < NUM_BUTTOMS; i++)
	{
		GameObject temp(pos, m_char);
		m_gameObject.push_back(temp);
		pos.y += DEF_SIZE_WINDOW / NUM_BUTTOMS;
	}
}
//-------------------------------------
int Menu::getWidth()const
{
	return BUTTOMS_SIZE_MENU;
}
//---------------------------------------------------
char Menu::GetObjectType() const
{
	return m_char;
}
//--------------------------------------------------
void Menu::buttomPressed(sf::Vector2f location)
{
	for (int i = 0; i < m_gameObject.size(); i++)
	{
		m_gameObject[i].makeFalse();
		if (m_gameObject[i].isButtomPressed(location, i))
		{
			m_char = m_gameObject[i].getObjectType();
			std::cout << "\nmenu pressed: " << m_char << std::endl;
		}
	}
}
//--------------------------------------------------------------