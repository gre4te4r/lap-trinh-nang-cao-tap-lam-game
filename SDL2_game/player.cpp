#include"player.h"
#include"InputHandler.h"

void Player::load(int x, int y, int width, int height, std::string textureID){

 GameObject::load(x, y, width, height, textureID);

}

void Player::draw(SDL_Renderer* pRenderer){
    TextureManager::Instance()->drawFrame(m_textureID, (int)m_position.getX(), (int)m_position.getY(), m_width, m_height, m_currentRow, m_currentFrame, pRenderer, m_flip);


}

void Player::update(){

    m_currentFrame = int(((SDL_GetTicks() / 100) % 12));

    if(TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_D)){

        m_velocity.setX(1);
        GameObject::update();
        m_flip = SDL_FLIP_NONE;

}
    if(TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_A)){

        m_velocity.setX(-1);
        GameObject::update();
        m_flip = SDL_FLIP_HORIZONTAL;
    }
    if(TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_W)){

        m_velocity.setY(-1);
        GameObject::update();
    }
    if(TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_S)){

        m_velocity.setY(1);
        GameObject::update();
    }
}



