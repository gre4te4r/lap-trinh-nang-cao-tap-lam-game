#include<iostream>
#include "GameStateMachine.h"

void GameStateMachine::pushState(GameState *pState)
{

    m_gameStates.push_back(pState);
    std::cout << "Pushing new State\n";
    m_gameStates.back()->onEnter();
}
void GameStateMachine::popState()
{
    if (!m_gameStates.empty())
    {
        if (m_gameStates.back()->onExit())
        {
            std::cout << "delete State\n";
            delete m_gameStates.back();
            m_gameStates.pop_back();
        }
    }
}

void GameStateMachine::changeState(GameState *pState)
{
    if (!m_gameStates.empty())
    {
        if (m_gameStates.back()->getStateID() == pState->getStateID())
        {
            return;
        }
        if (m_gameStates.back()->onExit())
        {
            delete m_gameStates.back();
            m_gameStates.pop_back();
        }
    }

    m_gameStates.push_back(pState);

    m_gameStates.back()->onEnter();
}
void GameStateMachine::update()
{
    if (!m_gameStates.empty())
    {
        m_gameStates.back()->update();
    }
}
void GameStateMachine::render()
{
    if (!m_gameStates.empty())
    {
        m_gameStates.back()->render();
    }
}
