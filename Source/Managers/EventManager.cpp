#include "EventManager.h"

#include <imgui.h>
#include <imgui-SFML.h>
#include "Core/Common.h"
#include "Managers/DeltaManager.h"
#include "Managers/StateManager.h"

RenderWindow*	EventManager::pGlobalWindow;

void EventManager::Update()
{
	if (pGlobalWindow != nullptr)
	{
		sf::Event event;

		while (pGlobalWindow->pollEvent(event))
		{
			ImGui::SFML::ProcessEvent(event);

			switch (event.type)
			{
				case sf::Event::Closed:
				{
					pGlobalWindow->close();
				}
				break;

				case sf::Event::KeyPressed:
				{
					if (Keyboard::isKeyPressed(Keyboard::LAlt) && Keyboard::isKeyPressed(Keyboard::M))
					{
						pGlobalWindow->setPosition(sf::Vector2i(
							Mouse::getPosition().x - pGlobalWindow->getSize().x / 2, 
							Mouse::getPosition().y - pGlobalWindow->getSize().y / 2));
					}

					switch (event.key.code)
					{
						case Keyboard::Escape:
						{
							if (StateManager::GetGenericSceneState() == GENERIC_SCENE_STATE::ACTIVE)
							{
								pGlobalWindow->close();
							}
						}
						break;
					}
				}
				break;
			}
		}
	}
	else
	{
		/* TO DO DEBUGGER */ std::cout << "Error - EventManager::pWindow = nullptr - make sure you attached a RenderWindow& using EventManager::AttachWindow() function.\n";
	}
}

void EventManager::AttachGlobalWindow(RenderWindow& renderWindow)
{
	pGlobalWindow = &renderWindow;
	ImGui::SFML::Init(*pGlobalWindow);
}

void EventManager::DetachGlobalWindow()
{
	ImGui::SFML::Shutdown();
	pGlobalWindow = nullptr;
}
