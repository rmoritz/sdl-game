#include "texturemanager.hh"
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"

My::TextureManager* My::TextureManager::s_pInstance = nullptr;

My::TextureManager* My::TextureManager::Instance() {
    if (!s_pInstance) {
        s_pInstance = new My::TextureManager();
    }
    
    return s_pInstance;
}

bool My::TextureManager::load(std::string fileName, std::string id, 
        SDL_Renderer* pRenderer) {

    SDL_Surface* pTempSurface = IMG_Load(fileName.c_str());
    
    if (!pTempSurface) {
        return false;
    }

    SDL_Texture* pTexture = SDL_CreateTextureFromSurface(pRenderer, pTempSurface);
    SDL_FreeSurface(pTempSurface);
    
    if (!pTexture) {
        return false;
    }

    _textureMap[id] = pTexture;
    return true;
}

void My::TextureManager::draw(std::string id, int x, int y, int width, int height,
        SDL_Renderer* pRenderer, SDL_RendererFlip flip) {
    SDL_Rect srcRect, destRect;
    
    srcRect.x = srcRect.y = 0;
    srcRect.w = destRect.w = width;
    srcRect.h = destRect.h = height;
    destRect.x = x;
    destRect.y = y;
    
    SDL_RenderCopyEx(pRenderer, _textureMap[id], &srcRect, &destRect,
        0, 0, flip);
}

void My::TextureManager::drawFrame(std::string id, int x, int y, int width, int height,
        int currentRow, int currentFrame, SDL_Renderer* pRenderer, 
        SDL_RendererFlip flip) {
    SDL_Rect srcRect, destRect;
  
    srcRect.x = width * currentFrame;
    srcRect.y = height * currentRow;
    srcRect.w = destRect.w = width;
    srcRect.h = destRect.h = height;
    destRect.x = x;
    destRect.y = y;
    
    SDL_RenderCopyEx(pRenderer, _textureMap[id], &srcRect, &destRect,
        0, 0, flip);    
}