#include "Bullet.h"


void Bullet::load(int x, int y, int width, int height, std::string textureID){

    GameObject::load(x, y, width, height, textureID);

}

void Bullet::draw(SDL_Renderer* pRenderer){

    TextureManager::Instance()->draw(m_textureID, (int)m_position.getX(), (int)m_position.getY(), m_width, m_height, pRenderer, m_flip);

}

void Bullet::update(){

    float cos, sin;


    float d, k, h;


    if(m_firstPosition.getX() < m_destination.getX()){
        k = m_destination.getX() - m_firstPosition.getX();
    }else{

        k = m_firstPosition.getX() - m_destination.getX();

    }

    if(m_firstPosition.getY() < m_destination.getY()){
        d = m_destination.getY() - m_firstPosition.getY();
    }else{

        d = m_firstPosition.getY() - m_destination.getY();

    }

    h = sqrt(d*d + k*k);
    cos = k/h;
    sin = d/h;



        if (m_firstPosition.getX() < m_destination.getX()&& m_firstPosition.getY() > m_destination.getY()){
            m_velocity.setX(5*cos);
            m_velocity.setY((-5)*sin);
            }
        if(m_firstPosition.getX() < m_destination.getX()&& m_firstPosition.getY() < m_destination.getY()){
            m_velocity.setX(5*cos);
            m_velocity.setY(5*sin);
            }


        if(m_firstPosition.getX() > m_destination.getX()&& m_firstPosition.getY() > m_destination.getY()){
            m_velocity.setX(-5*cos);
            m_velocity.setY((-5)*sin);
            }
        if(m_firstPosition.getX() > m_destination.getX()&& m_firstPosition.getY() < m_destination.getY()){
            m_velocity.setX(-5*cos);
            m_velocity.setY(5*sin);
            }


        GameObject::update();

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


void Bullet::getBulletDestination(Vector2D des){

    m_destination = des;

}
