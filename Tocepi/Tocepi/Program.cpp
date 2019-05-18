#include "Program.h"

//TODO: Render queue to make that of which object has the highest Y value
//rendered above the other

Program::Program()
{
	myState = GameState::SESSION;
}

Program::~Program()
{
}

void Program::Init(sf::RenderWindow& aWindow)
{
	InitSession(mySession, aWindow);
}

void Program::Update(float& aDelta, sf::Event& anEvent)
{
	switch (myState)
	{
	case GameState::MENU:

		break;
	case GameState::SESSION:
		mySession.Update(aDelta, anEvent);
		break;
	case GameState::OPTIONS:

		break;
	}
}

void Program::Draw(sf::RenderWindow& aWindow)
{
	switch (myState)
	{
	case GameState::MENU:

		break;
	case GameState::SESSION:
		mySession.Draw(aWindow);
		break;
	case GameState::OPTIONS:

		break;
	}
}

void Program::LateDraw(sf::RenderWindow& aWindow)
{
	switch (myState)
	{
	case GameState::MENU:

		break;
	case GameState::SESSION:
		mySession.LateDraw(aWindow);
		break;
	case GameState::OPTIONS:

		break;
	}
}

void Program::InitSession(SessionHandler& aSession, sf::RenderWindow& aWindow)
{
	//TODO: Session handler to be more flexible
	if (myState == GameState::SESSION)
	{
		aSession.Init
		(
			aWindow.getView().getSize().x,
			aWindow.getView().getSize().y,
			65.0f,
			90.0f,
			0.4f,
			myInput,
			aWindow
		);
	}
}
