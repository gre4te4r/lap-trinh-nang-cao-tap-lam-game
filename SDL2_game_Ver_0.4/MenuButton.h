#ifndef MENUBUTTON_H_INCLUDED
#define MENUBUTTON_H_INCLUDED

#include "gameObject.h"
#include <string>

class MenuButton : public GameObject
{
public:

   void load(int x, int y, int width, int height, std::string textureID, void (*callback)(),bool released);

    virtual void draw(SDL_Renderer* pRenderer);
    virtual void update();
    virtual void clean();

private:
    enum button_state
    {
        MOUSE_OUT = 0,
        MOUSE_OVER = 1,
        CLICKED = 2
    };

    void (*m_callback)();
    bool m_bReleased;
};

#endif // MENUBUTTON_H_INCLUDED
