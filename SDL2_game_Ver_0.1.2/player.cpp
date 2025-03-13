#include"player.h"
#include"InputHandler.h"

void Player::load(int x, int y, int width, int height, std::string textureID){

 GameObject::load(x, y, width, height, textureID);

}

void Player::draw(SDL_Renderer* pRenderer){

    TextureManager::Instance()->drawFrame(m_textureID, (int)m_position.getX(), (int)m_position.getY(), m_width, m_height, m_currentRow, m_currentFrame, pRenderer, m_flip);

}


void Player::update(){

    m_currentFrame = 1;

    if(TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_E)){

        m_currentFrame = int(((SDL_GetTicks() / 70) % 8));
        m_velocity.setX(0);
        m_velocity.setY(0);
        m_textureID = "attack";

    }else if(TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_D)||TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_A)||TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_S)||TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_W)){

        m_textureID = "walk";

        if(TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_D)){
            m_currentFrame = int(((SDL_GetTicks() / 100) % 12));
            m_velocity.setX(2);
            m_velocity.setY(0);
            GameObject::update();
            m_flip = SDL_FLIP_NONE;
}
        if(TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_A)){
            m_currentFrame = int(((SDL_GetTicks() / 100) % 12));
            m_velocity.setX(-2);
            m_velocity.setY(0);
            GameObject::update();
            m_flip = SDL_FLIP_HORIZONTAL;
    }
        if(TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_W)){
            m_currentFrame = int(((SDL_GetTicks() / 100) % 12));
            m_velocity.setX(0);
            m_velocity.setY(-2);
            GameObject::update();
    }
        if(TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_S)){
            m_currentFrame = int(((SDL_GetTicks() / 100) % 12));
            m_velocity.setX(0);
            m_velocity.setY(2);
            GameObject::update();
    }

    }else{

        m_currentFrame = int(((SDL_GetTicks() / 150) % 9));
        m_velocity.setX(0);
        m_velocity.setY(0);
        m_textureID = "idle";

    }
}



