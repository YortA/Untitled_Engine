#include "Engine.h"




// static declarations (core)
sf::VideoMode			Engine::GlobalVideoMode;
sf::String				Engine::GlobalTitle;
sf::Uint32				Engine::GlobalStyle;
sf::ContextSettings		Engine::GlobalContextSettings;
unsigned int			Engine::GlobalFramerateLimit;
sf::Vector2f			Engine::GlobalAspectRatio;
sf::Vector2f			Engine::GlobalScale;
RenderWindow*			Engine::GlobalWindow;

// static declarations (scenes)
Scene*	Engine::ActiveScene; 
Scene*	Engine::QueuedScene;





void Engine::Initialize(
	const sf::VideoMode&		videoMode, 
	const sf::String&			title, 
	const sf::Uint32&			style, 
	const sf::ContextSettings&	contextSettings, 
	unsigned int				framerateLimit)
{
	// initialize globals
	GlobalVideoMode			= videoMode;
	GlobalTitle				= title;
	GlobalStyle				= style;
	GlobalContextSettings	= contextSettings;
	GlobalFramerateLimit	= framerateLimit;
	GlobalAspectRatio		= AspectRatioCalculator::GetAspectRatio(sf::Vector2f(videoMode.width, videoMode.height));
	GlobalScale				= sf::Vector2f(1.f, 1.f); // fix later
	GlobalWindow			= new RenderWindow(GlobalVideoMode, GlobalTitle, GlobalStyle, GlobalContextSettings, GlobalFramerateLimit); // state flags soon
}

void Engine::Setup(SETUP_FLAG flags)
{
	// setup event manager
	EventManager::AttachGlobalWindow(*GlobalWindow);
}

void Engine::AttachQueuedScene(Scene& scene)
{
	// point/set engine's "QueuedScene" to scene parameter reference
	QueuedScene = &scene;
}

void Engine::AttachActiveScene(Scene& scene)
{
	// point/set engine's "ActiveScene" to scene parameter reference
	ActiveScene = &scene;

	// attach globals to active scene
	ActiveScene->attachGlobals(
		GlobalVideoMode,
		GlobalTitle,
		GlobalStyle,
		GlobalContextSettings,
		GlobalFramerateLimit,
		GlobalAspectRatio,
		GlobalScale,
		*GlobalWindow);
}

void Engine::ExcuteActiveScene()
{
	if (ActiveScene != nullptr) // if there is an active scene attached to engine
	{
		if (StateManager::GetGenericSceneState() == GENERIC_SCENE_STATE::CREATE)
		{
			// create scene
			ActiveScene->create();
		}
		else if (StateManager::GetGenericSceneState() == GENERIC_SCENE_STATE::SETUP)
		{
			// setup scene
			ActiveScene->setup();
		}
		else if (StateManager::GetGenericSceneState() == GENERIC_SCENE_STATE::DESTROY)
		{
			// destroy scene
			ActiveScene->destroy();
		}
		else if (StateManager::GetGenericSceneState() == GENERIC_SCENE_STATE::ACTIVE)
		{
			// update managers
			FileManager::Update();
			DeltaManager::Update();
			EventManager::Update();
			StateManager::Update();
			SceneManager::Update();

			// update scene
			ActiveScene->update();

			// render scene
			ActiveScene->render();
		}
		else if (StateManager::GetGenericSceneState() == GENERIC_SCENE_STATE::INACTIVE)
		{
			// reset generic scene state
			StateManager::SetGenericSceneState(GENERIC_SCENE_STATE::CREATE);

			// detach active scene from core components
			DetachActiveScene();

			// recursive
			ExcuteActiveScene();
		}
	}
	else if (QueuedScene != nullptr) // if there is a queued scene attached to engine
	{
		// point active scene to queued scene
		AttachActiveScene(*QueuedScene);

		// detach queued scene 
		DetachQueuedScene();

		// recursive
		ExcuteActiveScene();
	}
	else
	{
		// debugger/warning/error TO DO
	}
}

void Engine::DetachQueuedScene()
{
	// stop pointing "QueuedScene" at current queued scene reference
	QueuedScene = nullptr;
}

void Engine::DetachActiveScene()
{
	// detach globals from active scene
	ActiveScene->detachGlobals();

	// stop pointing "ActiveScene" at current active scene reference
	ActiveScene = nullptr;
}

void Engine::Exit()
{
	// detach active scene
	DetachActiveScene();

	// detach queued scene
	DetachQueuedScene();

	// manager clean up
	EventManager::DetachGlobalWindow();

	// state flags soon
	delete GlobalWindow;
}

Scene* Engine::GetActiveScene()
{
	return ActiveScene;
}

Scene* Engine::GetQueuedScene()
{
	return QueuedScene;
}

bool Engine::IsRunning()
{
	return GlobalWindow->isOpen();
}
