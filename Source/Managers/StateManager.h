#pragma once

enum class ENGINE_STATE
{
	INITITIALIZING,
	SETUP,
	RUNNING,
	RESETING,
	EXITING,
};

enum class GENERIC_SCENE_STATE
{
	CREATE,
	SETUP,
	ACTIVE,
	DESTROY,
	INACTIVE,
};

class StateManager
{
private:

	StateManager() = default;

public:

	static void Update();

public:

	static void SetGenericSceneState(GENERIC_SCENE_STATE state);
	static GENERIC_SCENE_STATE& GetGenericSceneState();

private:

	static ENGINE_STATE			EngineState;
	static GENERIC_SCENE_STATE	GenericSceneState;

};

