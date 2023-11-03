#include "Warrior.h"
#include "TextureManeger.h"
#include <SDL.h>
#include "Input.h"
#include "Timer.h"


Warrior::Warrior(Properties* props) : Character(props)
{
	m_RigidBody = new RigidBody();
	m_Animation = new Animation();
	m_Animation->SetProps(m_TextureID, 0, 8, 80);

}

void Warrior::Draw() {
	m_Animation->Draw(m_Transform->X, m_Transform->Y, m_Width, m_Height);
}

bool is_right = true;
void Warrior::Update(float dt) {

	
	

	if (is_right)
		m_Animation->SetProps("player", 0, 8, 80, SDL_FLIP_HORIZONTAL);
	else
		m_Animation->SetProps("player", 0, 8, 80);

	m_RigidBody->UnSetForce();

	if (Input::GetInstance()->GetKeyDown(SDL_SCANCODE_A)) {
		m_RigidBody->ApplyForceX(10*BACKWARD);
		m_Animation->SetProps("player_run", 0, 8, 80, SDL_FLIP_HORIZONTAL);
		is_right = true;

	}

	if (Input::GetInstance()->GetKeyDown(SDL_SCANCODE_D)) {
		m_RigidBody->ApplyForceX(10*FORWARD);
		m_Animation->SetProps("player_run", 0, 8, 80);
		is_right = false;
	}

	m_RigidBody->Update(0.4);
	

	m_Transform->TranslateX(m_RigidBody->Position().X);
	//m_Transform->TranslateY(m_RigidBody->Position().Y);

	m_Animation->Update();
	
}

void Warrior::Clean() {
	TextureManeger::GetInstance()->Clean();
}