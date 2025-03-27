#include"Enemy.h"

void Enemy::load(int x, int y, int width, int height, std::string textureID){

    GameObject::load(x, y, width, height, textureID);

}

void Enemy::draw(SDL_Renderer* pRenderer){




    TextureManager::Instance()->drawFrame(m_textureID, (int)m_position.getX(), (int)m_position.getY(), m_width, m_height, m_currentRow, m_currentFrame, pRenderer, m_flip);

}

void Enemy::update(){


    float cos, sin;


    float d, k, h;


    if(m_position.getX() < m_destination.getX()){
        k = m_destination.getX() - m_position.getX();
    }else{

        k = m_position.getX() - m_destination.getX();

    }

    if(m_position.getY() < m_destination.getY()){
        d = m_destination.getY() - m_position.getY();
    }else{

        d = m_position.getY() - m_destination.getY();

    }

    h = sqrt(d*d + k*k);

    cos = k/h;

    sin = d/h;

    float a = 2;


        if (m_position.getX() <= m_destination.getX()&& m_position.getY() >= m_destination.getY()){
            m_velocity.setX(a*cos);
            m_velocity.setY((-a)*sin);
            }
        if(m_position.getX() <= m_destination.getX()&& m_position.getY() <= m_destination.getY()){
            m_velocity.setX(a*cos);
            m_velocity.setY(a*sin);
            }


        if(m_position.getX() >= m_destination.getX()&& m_position.getY() >= m_destination.getY()){
            m_velocity.setX(-a*cos);
            m_velocity.setY((-a)*sin);
            }
        if(m_position.getX() >= m_destination.getX()&& m_position.getY() <= m_destination.getY()){
            m_velocity.setX(-a*cos);
            m_velocity.setY(a*sin);
            }
        if(m_position.getX() < m_destination.getX()) m_flip = SDL_FLIP_NONE;
        if(m_position.getX() > m_destination.getX()) m_flip = SDL_FLIP_HORIZONTAL;

        GameObject::update();

    m_currentFrame = int(((SDL_GetTicks() / 100) % 7));

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

void Enemy::getBulletDestination(Vector2D des){

    m_destination = des;

}

