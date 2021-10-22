#include "GameObject.h"

#include <iostream>

GameObject::GameObject(const sf::Vector2f& position, const char c)
	:  m_position(position), m_char(c)
{
	m_menuTexture.loadFromFile("menu.png");
	m_playerTexture.loadFromFile("player.png");
	m_enemyTexture.loadFromFile("enemy.png");
	m_coinTexture.loadFromFile("coin.png");
	m_wallTexture.loadFromFile("wall.png");
	m_ladderTexture.loadFromFile("ladder.png");
	m_poleTexture.loadFromFile("pole.png");
	m_eraseTexture.loadFromFile("reset.png");
	m_deleteTexture.loadFromFile("delete.png");
	m_saveTexture.loadFromFile("save.png");

	m_outLineColor = sf::Color::Magenta; 
	m_size.x = BUTTOMS_SIZE_MENU;
	m_size.y = BUTTOMS_SIZE_MENU;
	m_outlineThikness = OUTLINE_THIKNESS;
}
//----------------------------------------------------------------
void GameObject::SetGameObjectChar(const char c)
{ 
	m_char = c;
}
//-----------------------------------------------------------
void GameObject::SetGameObjectOutline(sf::Color color, float lineSize)
{
	m_outLineColor = color;
	m_outlineThikness = lineSize;
}
//--------------------------------------------------------------
void GameObject::SetGameObjectposition(sf::Vector2f location)
{
	m_position = location;
}
//--------------------------------------------
void GameObject::DrawMenu(sf::RenderWindow& window, int i)
{
	window.draw(createObject(i));
}
//------------------------------------------------
sf::RectangleShape GameObject::createObject(int i)
{
	auto shape = sf::RectangleShape(m_size);
	shape.setPosition(m_position);
	m_char = setCharType(i);
	shape.setTexture(&getObjPicture(m_char));

	return shape;
}
//-----------------------------------------------------
char GameObject::getObjectType() const
{
	return m_char;
}
//--------------------------------------------------------------
sf::Texture& GameObject::getObjPicture(const char c) 
{
	switch (c)
	{
	case MENU:
		return m_menuTexture; break;
	case(PLAYER):
		return m_playerTexture; break;
	case(ENEMY):
		return  m_enemyTexture; break;
	case(COIN):
		return  m_coinTexture; break;
	case(WALL):
		return  m_wallTexture; break;
	case(LADDER):
		return m_ladderTexture; break;
	case(POLE):
		return m_poleTexture; break;
	case ERASE:
		return m_eraseTexture; break;
	case DELETE:
		return m_deleteTexture; break;
	case SAVE:
		return m_saveTexture; break;
	default:
		break;
	}
	return m_emptyTexture;
}
//----------------------------------------------
char GameObject::setCharType(int i)
{
	switch (i)
	{
	case 0: return MENU; break;
	case 1:	return PLAYER; break;
	case 2:	return ENEMY; break;
	case 3:	return COIN; break;
	case 4:	return WALL; break;
	case 5:	return LADDER; break;
	case 6:	return POLE; break;
	case 7: return ERASE; break;
	case 8: return DELETE; break;
	case 9: return SAVE; break;
	default:
		break;
	}
	return EMPTY_CELL;
}
//------------------------------------------
bool GameObject::isButtomPressed(sf::Vector2f location, int i)
{
	if (createObject(i).getGlobalBounds().contains(location)) {
		m_isObject = true;
	}
	return m_isObject;
}
//--------------------------------------------------------
void GameObject::makeFalse()
{
	m_isObject = false;
}
//------------------------
bool GameObject::isObjectTrue()const
{
	if (m_isObject)
		return true;
	return false;
}










/*
void GameObject::Draw(sf::RenderWindow& window, sf::Texture& texture)
{
	sf::Sprite sprite = sf::Sprite(texture);
	sprite.setPosition(m_position);
	sprite.setScale(m_size.x / sprite.getLocalBounds().width,
		m_size.y / sprite.getLocalBounds().height);

	window.draw(createObject());
	//window.draw(sprite);
}
//----------------------------------------------------------
sf::RectangleShape GameObject::createObject()
{
	auto shape = sf::RectangleShape(m_size);
	shape.setOutlineThickness(3);
	shape.setOutlineColor(sf::Color::Green);
	shape.setPosition(m_position);
	shape.setFillColor(m_color);
	//shape.setTexture(&m_texture);
	return shape;
}

*/


/*sf::Sprite sprite;// = sf::Sprite(getObjPicture(m_objectType));
sprite.setPosition(m_position);
sprite.setScale(m_size.x / sprite.getLocalBounds().width,
	m_size.y / sprite.getLocalBounds().height);
sprite.setTexture(getObjPicture(m_objectType), true);*/