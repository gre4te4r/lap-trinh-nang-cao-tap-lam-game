#ifndef PLAYSTATE_H_INCLUDED
#define PLAYSTATE_H_INCLUDED

#include "GameState.h"
class PlayState : public GameState
{
public:
 virtual void update();
 virtual void render();
 virtual bool onEnter();
 virtual bool onExit();
 virtual std::string getStateID() const { return s_playID; }
private:
 static const std::string s_playID;
};

#endif // PLAYSTATE_H_INCLUDED
