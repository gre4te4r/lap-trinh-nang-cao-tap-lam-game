#include "player.h"
#include "InputHandler.h"

void Player::load(int x, int y, int width, int height, std::string textureID)
{

    GameObject::load(x, y, width, height, textureID);
}

void Player::draw(SDL_Renderer *pRenderer)
{

    TextureManager::Instance()->drawFrame(m_textureID, (int)m_position.getX(), (int)m_position.getY(), m_width, m_height, m_currentRow, m_currentFrame, pRenderer, m_flip);
}

void Player::update()
{

    m_currentFrame = 1;

    if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_D) || TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_A) || TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_S) || TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_W))
    {

        m_textureID = "run";

        int a = 5;

        if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_D))
        {
            if (m_position.getX() >= 820)
                m_velocity.setX(0);
            else
            {
                m_currentFrame = int(((SDL_GetTicks() / 100) % 7));
                m_velocity.setX(a);
                m_velocity.setY(0);
                GameObject::update();
                m_flip = SDL_FLIP_NONE;
            }
        }
        if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_A))
        {
            if (m_position.getX() <= 0)
                m_velocity.setX(0);
            else
            {
                m_currentFrame = int(((SDL_GetTicks() / 100) % 7));
                m_velocity.setX(-a);
                m_velocity.setY(0);
                GameObject::update();
                m_flip = SDL_FLIP_HORIZONTAL;
            }
        }
        if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_W))
        {
            if (m_position.getY() <= 0)
                m_velocity.setY(0);
            else
            {
                m_currentFrame = int(((SDL_GetTicks() / 100) % 7));
                m_velocity.setX(0);
                m_velocity.setY(-a);
                GameObject::update();
            }
        }
        if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_S))
        {
            if (m_position.getY() >= 440)
                m_velocity.setY(0);
            else
            {
                m_currentFrame = int(((SDL_GetTicks() / 100) % 7));
                m_velocity.setX(0);
                m_velocity.setY(a);
                GameObject::update();
            }
        }
    }
    else
    {
        //        std::cout << m_position.getY()<<std::endl;
        m_currentFrame = int(((SDL_GetTicks() / 150) % 4));
        m_velocity.setX(0);
        m_velocity.setY(0);
        m_textureID = "idle";
    }
    //    std::cout << "x: " << m_position.getX()<< std::endl;
    //    std::cout << "y: " << m_position.getY()<< std::endl;
}

Vector2D Player::playerGetPosition()
{
    return m_position;
}

SDL_RendererFlip Player::getPlayerFlip()
{
    return m_flip;
}

int Player::getPlayerWidth()
{
    return m_width;
}

int Player::getPlayerHeight()
{
    return m_height;
}
