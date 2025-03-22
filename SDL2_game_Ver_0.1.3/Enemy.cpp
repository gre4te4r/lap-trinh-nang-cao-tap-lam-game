#include"Enemy.h"

void Enemy::load(int x, int y, int width, int height, std::string textureID){

    GameObject::load(x, y, width, height, textureID);

}

void Enemy::draw(SDL_Renderer* pRenderer){

    GameObject::draw(pRenderer);

}

void Enemy::update(){

    m_position.setX(m_position.getX() + 1);
//    m_position.setY(m_position.getY() + 1);

    m_currentFrame = int(((SDL_GetTicks() / 100) % 7));
}
