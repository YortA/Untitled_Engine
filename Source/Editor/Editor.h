#pragma once

#include "Core/Scene.h";

class Editor : public Scene // for now editor will just be a derived scene
{
public:

	virtual void create()	override;
	virtual void setup()	override;
	virtual void update()	override;
	virtual void render()	override;
	virtual void destroy()	override;

public:

	void createCore();
	void createSoundBuffers();
	void createFonts();
	void createTextures();
	void createSounds();
	void createMusic();
	void createTexts();
	void createCircles();
	void createRectangles();
	void createSprites();

public:

	void setupCore();
	void setupSoundBuffers();
	void setupFonts();
	void setupTextures();
	void setupSounds();
	void setupMusic();
	void setupTexts();
	void setupCircles();
	void setupRectangles();
	void setupSprites();

public:

	void updateCore();
	void updateImGui();
	void updateTexts();
	void updateSounds();
	void updateMusic();
	void updateCircles();
	void updateRectangles();
	void updateSprites();

public:

	void renderImGui();
	void renderTexts(unsigned int renderLayer);
	void renderCircles(unsigned int renderLayer);
	void renderRectangles(unsigned int renderLayer);
	void renderSprites(unsigned int renderLayer);

public:

	void destroyCore();
	void destroySoundBuffers();
	void destroyFonts();
	void destroyTextures();
	void destroySounds();
	void destroyMusic();
	void destroyTexts();
	void destroyCircles();
	void destroyRectangles();
	void destroySprites();
	
public:

	float			uiUniversalScale;
	float			uiBorderScale;
	float			uiTextScale;
	sf::Color		uiDarkOrange;
	sf::Color		uiDarkGrey;
	sf::Color		uiClearColor;
	sf::Vector2f	resolution;

	unsigned int	tempSpriteArrayPosition;
	float			tempSpriteOrigin[2];
	float			tempSpriteScale[2];
	float			tempSpritePosition[2];
	float			tempSpriteColor[3];
	float			tempSpriteOpacity;
	float			tempSpriteRotation;
	bool			tempSpriteRenderEnabled;
	unsigned int	tempSpriteRenderLayer;		
};

