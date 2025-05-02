#ifndef INPUTHANDLER_H_INCLUDED
#define INPUTHANDLER_H_INCLUDED

#include <iostream>
#include <vector>

#include "SDL.h"
#include "Vector2D.h"

enum mouse_buttons
{
    LEFT = 0,
    MIDDLE = 1,
    RIGHT = 2
};

class InputHandler
{
public:
    static InputHandler *Instance()
    {
        if (s_pInstance == 0)
        {
            s_pInstance = new InputHandler();
        }

        return s_pInstance;
    }

    void reset();

    void update(SDL_Window *myWindow, SDL_Renderer *myRenderer);
    void clean();

    bool isKeyDown(SDL_Scancode key) const;

    bool getMouseButtonState(int buttonNumber) const;
    Vector2D *getMousePosition() const;

private:
    InputHandler();
    ~InputHandler();

    InputHandler(const InputHandler &);
    InputHandler &operator=(const InputHandler &);

    void onKeyDown();
    void onKeyUp();

    void onMouseMove(SDL_Event &event);
    void onMouseButtonDown(SDL_Event &event);
    void onMouseButtonUp(SDL_Event &event);

    const Uint8 *m_keystates;

    std::vector<bool> m_mouseButtonStates;
    Vector2D *m_mousePosition;

    static InputHandler *s_pInstance;
};
typedef InputHandler TheInputHandler;

#endif // INPUTHANDLER_H_INCLUDED
