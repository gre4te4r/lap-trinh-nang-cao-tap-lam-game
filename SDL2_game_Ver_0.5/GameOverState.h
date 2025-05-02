#ifndef GAMEOVERSTATE_H_INCLUDED
#define GAMEOVERSTATE_H_INCLUDED
#include "GameState.h"
#include "gameObject.h"
#include "MenuButton.h"
#include "gameclass.h"
class GameOverState : public GameState
{
public:
    virtual void update();
    virtual void render();
    virtual bool onEnter();
    virtual bool onExit();
    virtual std::string getStateID() const { return s_gameOverID; }

private:
    static void s_gameOverToMain();
    static void s_restartPlay();
    static const std::string s_gameOverID;
    std::vector<GameObject *> m_gameObjects;
};

#endif // GAMEOVERSTATE_H_INCLUDED
