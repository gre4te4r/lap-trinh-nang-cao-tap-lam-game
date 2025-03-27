#include"gameObject.h"

void GameObject::load(int x, int y, int width, int height, std::string textureID){

 m_position.setX(x);
 m_position.setY(y);

 m_firstPosition.setX(x);
 m_firstPosition.setY(y);

 m_width = width;
 m_height = height;

 m_textureID = textureID;

 m_currentRow = 1;
 m_currentFrame = 1;
}

void GameObject::draw(SDL_Renderer* pRenderer){

 TextureManager::Instance()->drawFrame(m_textureID, (int)m_position.getX(), (int)m_position.getY(), m_width, m_height, m_currentRow, m_currentFrame, pRenderer);

}

void GameObject::update(){

 m_velocity += m_acceleration;
 m_position += m_velocity;

}

