#pragma once
#include "Character.h"
#include "TextureManeger.h"
#include "Animation.h"
#include "RigidBody.h"

class Warrior : public Character
{
public:
	Warrior(Properties* props);
	virtual void Draw();
	virtual void Clean();
	virtual void Update(float dt);

private:
	//int m_Row, m_Frame, m_FrameCount, m_AnimSpeed;

	RigidBody* m_RigidBody;
	Animation* m_Animation;

};

