#include "Core/Engine.h"

/*
	Scene functionality is at a bare minimum for now
	to practice basic concepts. I intend for them to be
	as universal and modular as possible in the future.

	While it's not automated yet, you can see that the 
	engine can take scenes derived from the semi-abstract "Scene" 
	base class and executes their overirdden create(), setup(), 
	update(), render(), and destroy() functions accordingly or
	as specified in engine source code.

	If you want to make a new scene or see scenes already made,
	go to the "scenes" folder in the "source" folder to get an
	idea of how I intend for them to be used. Almost feels like
	a knock-off script.

	Better commentation coming soon... I did my best to 
	make "self-commenting code" but we all know how that 
	goes...

	Disclaimer: "Untitled" Engine is in it's planning stage and is far
	from fully designed or fully functional. At the moment, engine is 
	only capable of making scenes with limited resources. Simple Tilemap 
	and Animation classes already written, will be implemented soon.
*/

int main()
{
	// create default scene and store it with SceneManager (position 0)
	SceneManager::PushBackScene(new SceneLoading(),	"Loading");

	// creates Editor (or whatever) scene and store it with SceneManager (position 1)
	SceneManager::PushBackScene(new Editor(), "Editor");

	// Engine initialized window video mode, title, style, context settings, and framerate limit
	Engine::Initialize(sf::VideoMode(1280, 720), sf::String("Untitled Engine"), sf::Style::None, sf::ContextSettings(0, 0, 4), 60);
	
	// setup with or without flags (will be defined soon)
	Engine::Setup(SETUP_FLAG::TO_DO_1);

	// Engine attaches active derived scene from SceneManager for reference
	Engine::AttachActiveScene(*SceneManager::GetScene("Loading"));
	
	// Engine attaches queued derived scene from SceneManager for future reference
	Engine::AttachQueuedScene(*SceneManager::GetScene("Editor"));
	
	// main engine loop
	while (Engine::IsRunning())
	{
		// if theres aren't any scenes queued
		if (Engine::GetQueuedScene() == nullptr)
		{
			// attach the designated default scene (a loading screen in this case)
			Engine::AttachQueuedScene(*SceneManager::GetScene("Loading"));
		}

		// run/execute active scene
		Engine::ExcuteActiveScene();
	}
	
	// exit engine
	Engine::Exit();
}