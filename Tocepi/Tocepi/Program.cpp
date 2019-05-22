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

void Program::Init(sf::RenderWindow& aWindow, bool aFrameCFlag)
{
	InitSession(mySession, aWindow);
	myFrameCFlag = aFrameCFlag;

	if (aFrameCFlag)
	{
		if (!myBaseFont.loadFromFile("Content/fonts/PressStart2P/PressStart2P.ttf"))
		{
			myFrameCFlag = false;
			std::cout << "Couldn't load base font" << std::endl;
		}
		else
		{
			myText.setFont(myBaseFont);
			myText.setString("TEMP");
			myText.setCharacterSize(24); //in pixels
			myText.setFillColor(sf::Color::Red);
			myText.setStyle(sf::Text::Bold);
			myCounter = 0;
		}
	}
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

	if (myFrameCFlag)
	{
		myCounter++;
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

void Program::LateDraw(sf::RenderWindow& aWindow, float& someFps)
{
	aWindow.setView(aWindow.getDefaultView()); //Makes sure that UI Elements etc are actually visible
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

	if (myFrameCFlag)
	{
		if (myCounter >= 60)
		{
			myText.setString("FPS: " + std::to_string(someFps));
			myCounter = 0;
		}
		aWindow.draw(myText);
	}
}

void Program::InitSession(SessionHandler & aSession, sf::RenderWindow & aWindow)
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
