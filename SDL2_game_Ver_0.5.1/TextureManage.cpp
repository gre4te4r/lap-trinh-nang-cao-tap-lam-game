#include"TextureManage.h"


TextureManager* TextureManager::s_pInstance = nullptr;

bool TextureManager::load(std::string fileName, std::string id, SDL_Renderer* pRenderer){

    SDL_Texture* pTexture = IMG_LoadTexture(pRenderer, fileName.c_str());

    if(pTexture != 0){

        m_textureMap[id] = pTexture;
        return true;

    }

    return false;
}

void TextureManager::draw(std::string id, int x, int y, int width, int height, SDL_Renderer* pRenderer, SDL_RendererFlip flip){

    SDL_Rect srcRect;
    SDL_Rect destRect;

    srcRect.x = 0;
    srcRect.y = 0;

    srcRect.w = destRect.w = width;
    srcRect.h = destRect.h = height;

    destRect.x = x;
    destRect.y = y;

    SDL_RenderCopyEx(pRenderer, m_textureMap[id], &srcRect, &destRect, 0, 0, flip);
}

void TextureManager::drawFrame(std::string id, int x, int y, int width, int height, int currentRow, int currentFrame, SDL_Renderer *pRenderer, SDL_RendererFlip flip)
{
    SDL_Rect srcRect;
    SDL_Rect destRect;

    srcRect.x = width * currentFrame;
    srcRect.y = height * (currentRow - 1);

    srcRect.w = width;
    srcRect.h = height;
    destRect.w = width;
    destRect.h = height;

    destRect.x = x;
    destRect.y = y;
    SDL_RenderCopyEx(pRenderer, m_textureMap[id], &srcRect, &destRect, 0, 0, flip);
}
void TextureManager::drawButton(std::string id, int x, int y, int width, int height, int currentRow, int currentFrame, SDL_Renderer *pRenderer, SDL_RendererFlip flip)
{
    SDL_Rect srcRect;
    SDL_Rect destRect;

    srcRect.x = width * currentFrame;
    srcRect.y = height * (currentRow - 1);

    srcRect.w = width/2;
    srcRect.h = height/2;
    destRect.w = width;
    destRect.h = height;

    destRect.x = x;
    destRect.y = y;
    SDL_RenderCopyEx(pRenderer, m_textureMap[id], &srcRect, &destRect, 0, 0, flip);
}

void TextureManager::clearFromTextureMap(std::string id)
{
 m_textureMap.erase(id);
}
