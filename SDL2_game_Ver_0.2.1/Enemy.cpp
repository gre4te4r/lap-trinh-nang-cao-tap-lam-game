#include"Enemy.h"

void Enemy::load(int x, int y, int width, int height, std::string textureID){

    GameObject::load(x, y, width, height, textureID);

}

void Enemy::draw(SDL_Renderer* pRenderer){




    TextureManager::Instance()->drawFrame(m_textureID, (int)m_position.getX(), (int)m_position.getY(), m_width, m_height, m_currentRow, m_currentFrame, pRenderer, m_flip);

}

void Enemy::update(){


    if(m_flip == SDL_FLIP_HORIZONTAL){
         m_position.setX(m_position.getX() - 1);
    }else{
        m_position.setX(m_position.getX() + 1);
    }
//    m_position.setY(m_position.getY() + 1);

    m_currentFrame = int(((SDL_GetTicks() / 100) % 7));

}

void Enemy::flipEnemy(){

    m_flip = SDL_FLIP_HORIZONTAL;

}




float Enemy::getEnemyPosX(){


    return m_position.getX();


}
float Enemy::getEnemyPosY(){


    return m_position.getY();


}

int Enemy::getEnemyWidth(){

    return m_width;

}

int Enemy::getEnemyHeight(){

    return m_height;

}

