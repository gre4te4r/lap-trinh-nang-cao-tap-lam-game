#include "Bullet.h"


void Bullet::load(int x, int y, int width, int height, std::string textureID){

    GameObject::load(x, y, width, height, textureID);

}

void Bullet::draw(SDL_Renderer* pRenderer){

    TextureManager::Instance()->draw(m_textureID, (int)m_position.getX(), (int)m_position.getY(), m_width, m_height, pRenderer, m_flip);

}

void Bullet::update(){
    if(m_flip == SDL_FLIP_NONE){
     m_position.setX(m_position.getX() + 5);
    }
    if(m_flip == SDL_FLIP_HORIZONTAL){
     m_position.setX(m_position.getX() - 5);
    }
}

bool Bullet::isOffScreen(){

        return m_position.getX() > 720;

}

void Bullet::flipBullet(SDL_RendererFlip flip){

    m_flip = flip;


}



float Bullet::getBulletPosX(){


    return m_position.getX();


}
float Bullet::getBulletPosY(){


    return m_position.getY();


}

int Bullet::getBulletWidth(){

    return m_width;

}

int Bullet::getBulletHeight(){

    return m_height;

}
