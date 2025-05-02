#include "MenuButton.h"
#include "InputHandler.h"

void MenuButton::load(int x, int y, int width, int height, std::string textureID,void (*callback)(), bool released)
{

    GameObject::load(x, y, width, height, textureID);
    m_callback= callback;
    m_bReleased = released;

}

void MenuButton::draw(SDL_Renderer* pRenderer)
{
    TextureManager::Instance()->drawFrame(m_textureID,
        (int)m_position.getX(), (int)m_position.getY(),
        m_width, m_height, 1, m_currentFrame, pRenderer);
//    TextureManager::Instance()->draw(m_textureID,(int)m_position.getX(),(int)m_position.getY(), m_width, m_height, pRenderer);
}

void MenuButton::update()
{
    std::cout << "currentFrame: " << m_currentFrame << "\n";

    Vector2D* pMousePos = TheInputHandler::Instance()->getMousePosition();

    if (pMousePos->getX() < (m_position.getX() + m_width) &&
        pMousePos->getX() > m_position.getX() &&
        pMousePos->getY() < (m_position.getY() + m_height) &&
        pMousePos->getY() > m_position.getY())
    {
        if (TheInputHandler::Instance()->getMouseButtonState(LEFT) && m_bReleased)
        {
            m_currentFrame = CLICKED;
            m_callback();
            m_bReleased = false;
        }
        else if (!TheInputHandler::Instance()->getMouseButtonState(LEFT))
        {
            m_bReleased = true;
            m_currentFrame = MOUSE_OVER;
        }
    }
    else
    {
        m_currentFrame = MOUSE_OUT;
    }
}

void MenuButton::clean() {}
