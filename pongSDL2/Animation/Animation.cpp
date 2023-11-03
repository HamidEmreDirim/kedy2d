#include "Animation.h"
#include "TextureManeger.h"



void Animation::Update() {
	
	m_SpriteFrame = (SDL_GetTicks() / m_AnimSpeed) % m_FrameCount;

}

void Animation::Draw(float x, float y, int spritWidth, int spriteHeight) {
	TextureManeger::GetInstance()->DrawFrame(m_TextureID, x, y, spritWidth, spriteHeight, m_SpriteRow, m_SpriteFrame, m_Flip);
}

void Animation::SetProps(std::string textureID, int spritRow, int frame, int animSpeed, SDL_RendererFlip flip) {
	m_TextureID = textureID;
	m_SpriteRow = spritRow;
	m_FrameCount = frame;
	m_AnimSpeed = animSpeed;
	m_Flip = flip;
}