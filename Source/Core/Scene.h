#pragma once

#include "Core/Common.h"
#include "Managers/FileManager.h"
#include "Managers/DeltaManager.h"
#include "Managers/EventManager.h"
#include "Managers/StateManager.h"

class Scene
{
public:

	Scene() = default;
	~Scene() { detachGlobals(); }

public:

	virtual void create()	= 0;	// intended for creating objects/heap allocations
	virtual void setup()	= 0;	// pre-scene setup/modification
	virtual void update()	= 0;	// update this frame (main loop)
	virtual void render()	= 0;	// render this frame (main loop)
	virtual void destroy()	= 0;	// intended for destroying objects/heap deallocations

public:

	const char*		getId()					{ return id;				}
	unsigned int	getRenderLayerCount()	{ return renderLayerCount;	}
	ImGuiIO			getIO()					{ return IO;				}

public:

	void setId(const char* id)								{ this->id					= id;				}
	void setRenderLayerCount(unsigned int renderLayerCount) { this->renderLayerCount	= renderLayerCount; }

public:

	void pushSoundBuffer(	const char* ID)	{ soundBuffers.push_back(SoundBuffer());	soundBufferIDs.push_back(ID);	}
	void pushSound(			const char* ID)	{ sounds.push_back(Sound());				soundIDs.push_back(ID);			}
	void pushMusic(			const char* ID)	{ music.push_back(new Music());				musicIDs.push_back(ID);			}
	void pushFont(			const char* ID)	{ fonts.push_back(Font());					fontIDs.push_back(ID);			}
	void pushText(			const char* ID)	{ texts.push_back(Text());					textIDs.push_back(ID);			}
	void pushTexture(		const char* ID)	{ textures.push_back(Texture());			textureIDs.push_back(ID);		}
	void pushCircle(		const char* ID)	{ circles.push_back(CircleShape());			circleIDs.push_back(ID);		}
	void pushRectangle(		const char* ID) { rectangles.push_back(RectangleShape());	rectangleIDs.push_back(ID);		}
	void pushSprite(		const char* ID)	{ sprites.push_back(Sprite());				spriteIDs.push_back(ID);		}

public:

	void popSoundBuffer()	{ soundBuffers.pop_back();	soundBufferIDs.pop_back();	}
	void popSound()			{ sounds.pop_back();		soundIDs.pop_back();		}
	void popMusic()			{ music.pop_back();			musicIDs.pop_back();		}
	void popFont()			{ fonts.pop_back();			fontIDs.pop_back();			}
	void popText()			{ texts.pop_back();			textIDs.pop_back();			}
	void popTexture()		{ textures.pop_back();		textureIDs.pop_back();		}
	void popCircle()		{ circles.pop_back();		circleIDs.pop_back();		}
	void popRectangle()		{ rectangles.pop_back();	rectangleIDs.pop_back();	}
	void popSprite()		{ sprites.pop_back();		spriteIDs.pop_back();		}

public:

	void clearSoundBuffer()	{ soundBuffers.clear();	soundBufferIDs.clear();	}
	void clearSound()		{ sounds.clear();		soundIDs.clear();		}
	void clearMusic()		{ music.clear();		musicIDs.clear();		}
	void clearFont()		{ fonts.clear();		fontIDs.clear();		}
	void clearText()		{ texts.clear();		textIDs.clear();		}
	void clearTexture()		{ textures.clear();		textureIDs.clear();		}
	void clearCircle()		{ circles.clear();		circleIDs.clear();		}
	void clearRectangle()	{ rectangles.clear();	rectangleIDs.clear();	}
	void clearSprite()		{ sprites.clear();		spriteIDs.clear();		}

public:

	void clearAllResources()
	{
		clearSoundBuffer();
		clearSound();
		clearMusic();
		clearFont();
		clearText();
		clearTexture();
		clearCircle();
		clearRectangle();
		clearSprite();
	}

public:

	SoundBuffer&	getSoundBuffer(	unsigned int position)	{ return soundBuffers[position];	}
	Sound&			getSound(		unsigned int position)	{ return sounds[position];			}
	Music&			getMusic(		unsigned int position)	{ return *music[position];			}
	Font&			getFont(		unsigned int position)	{ return fonts[position];			}
	Text&			getText(		unsigned int position)	{ return texts[position];			}
	Texture&		getTexture(		unsigned int position)	{ return textures[position];		}
	CircleShape&	getCircle(		unsigned int position)	{ return circles[position];			}
	RectangleShape&	getRectangle(	unsigned int position)	{ return rectangles[position];		}
	Sprite&			getSprite(		unsigned int position)	{ return sprites[position];			}

public:

	SoundBuffer&	getSoundBuffer(	std::string ID)	{ for (unsigned int i = 0; i < soundBufferIDs.size();	i++)	{ if (soundBufferIDs[i]	== ID) return soundBuffers[i];	}	}
	Sound&			getSound(		std::string ID)	{ for (unsigned int i = 0; i < soundIDs.size();			i++)	{ if (soundIDs[i]		== ID) return sounds[i];		}	}
	Music&			getMusic(		std::string ID)	{ for (unsigned int i = 0; i < musicIDs.size();			i++)	{ if (musicIDs[i]		== ID) return *music[i];		}	}
	Font&			getFont(		std::string ID)	{ for (unsigned int i = 0; i < fontIDs.size();			i++)	{ if (fontIDs[i]		== ID) return fonts[i];			}	}
	Text&			getText(		std::string ID)	{ for (unsigned int i = 0; i < textIDs.size();			i++)	{ if (textIDs[i]		== ID) return texts[i];			}	}
	Texture&		getTexture(		std::string ID)	{ for (unsigned int i = 0; i < textureIDs.size();		i++)	{ if (textureIDs[i]		== ID) return textures[i];		}	}
	CircleShape&	getCircle(		std::string ID)	{ for (unsigned int i = 0; i < circleIDs.size();		i++)	{ if (circleIDs[i]		== ID) return circles[i];		}	}
	RectangleShape&	getRectangle(	std::string ID)	{ for (unsigned int i = 0; i < rectangleIDs.size();		i++)	{ if (rectangleIDs[i]	== ID) return rectangles[i];	}	}
	Sprite&			getSprite(		std::string ID)	{ for (unsigned int i = 0; i < spriteIDs.size();		i++)	{ if (spriteIDs[i]		== ID) return sprites[i];		}	}

public:

	unsigned int getSoundBufferCount()	{ return soundBufferIDs.size();	}
	unsigned int getSoundCount()		{ return soundIDs.size();		}
	unsigned int getMusicCount()		{ return musicIDs.size();		}
	unsigned int getFontCount()			{ return fontIDs.size();		}
	unsigned int getTextCount()			{ return textIDs.size();		}
	unsigned int getTextureCount()		{ return textureIDs.size();		}
	unsigned int getCircleCount()		{ return circleIDs.size();		}
	unsigned int getRectangleCount()	{ return rectangleIDs.size();	}
	unsigned int getSpriteCount()		{ return spriteIDs.size();		}

public:

	void attachGlobalVideoMode(sf::VideoMode& globalVideoMode)						{ pGlobalVideoMode			= &globalVideoMode;			}
	void attachGlobalTitle(sf::String& globalTitle)									{ pGlobalTitle				= &globalTitle;				}
	void attachGlobalStyle(sf::Uint32& globalStyle)									{ pGlobalStyle				= &globalStyle;				}
	void attachGlobalContextSettings(sf::ContextSettings& globalContextSettings)	{ pGlobalContextSettings	= &globalContextSettings;	}
	void attachGlobalFramerateLimit(unsigned int& globalFramerateLimit)				{ pGlobalFramerateLimit		= &globalFramerateLimit;	}
	void attachGlobalAspectRatio(sf::Vector2f& globalAspectRatio)					{ pGlobalAspectRatio		= &globalAspectRatio;		}
	void attachGlobalScale(sf::Vector2f& globalScale)								{ pGlobalScale				= &globalScale;				}
	void attachGlobalWindow(RenderWindow& globalWindow)								{ pGlobalWindow				= &globalWindow;			}

public:

	void attachGlobals(
		sf::VideoMode&			globalVideoMode,
		sf::String&				globalTitle,
		sf::Uint32&				globalStyle,
		sf::ContextSettings&	globalContextSettings,
		unsigned int&			globalFramerateLimit,
		sf::Vector2f&			globalAspectRatio,
		sf::Vector2f&			globalScale,
		RenderWindow&			globalWindow)
	{
		attachGlobalVideoMode(globalVideoMode);
		attachGlobalTitle(globalTitle);
		attachGlobalStyle(globalStyle);
		attachGlobalContextSettings(globalContextSettings);
		attachGlobalFramerateLimit(globalFramerateLimit);
		attachGlobalAspectRatio(globalAspectRatio);
		attachGlobalScale(globalScale);
		attachGlobalWindow(globalWindow);
	}

public:

	void detachGlobalVideoMode()		{ pGlobalVideoMode			= nullptr;	}
	void detachGlobalTitle()			{ pGlobalTitle				= nullptr;	}
	void detachGlobalStyle()			{ pGlobalStyle				= nullptr;	}
	void detachGlobalContextSettings()	{ pGlobalContextSettings	= nullptr;	}
	void detachGlobalFramerateLimit()	{ pGlobalFramerateLimit		= nullptr;	}
	void detachGlobalAspectRatio()		{ pGlobalAspectRatio		= nullptr;	}
	void detachGlobalScale()			{ pGlobalScale				= nullptr;	}
	void detachWindow()					{ pGlobalWindow				= nullptr;	}

public:

	void detachGlobals()
	{
		detachGlobalVideoMode();
		detachGlobalTitle();
		detachGlobalStyle();
		detachGlobalContextSettings();
		detachGlobalFramerateLimit();
		detachGlobalAspectRatio();
		detachGlobalScale();
		detachWindow();
	}

public:

	sf::VideoMode&			getGlobalVideoMode()		{ return *pGlobalVideoMode;			}
	sf::String&				getGlobalTitle()			{ return *pGlobalTitle;				}
	sf::Uint32&				getGlobalStyle()			{ return *pGlobalStyle;				}
	sf::ContextSettings&	getGlobalContextSettings()	{ return *pGlobalContextSettings;	}
	unsigned int&			getGlobalFramerateLimit()	{ return *pGlobalFramerateLimit;	}
	sf::Vector2f&			getGlobalAspectRatio()		{ return *pGlobalAspectRatio;		}
	sf::Vector2f&			getGlobalScale()			{ return *pGlobalScale;				}
	RenderWindow&			getGlobalWindow()			{ return *pGlobalWindow;			}

private:

	const char*		id					= nullptr;
	unsigned int	renderLayerCount	= 1;
	ImGuiIO			IO					= ImGuiIO();

private:

	std::vector<SoundBuffer>	soundBuffers;	
	std::vector<Sound>			sounds;			
	std::vector<Music*>			music;			
	std::vector<Font>			fonts;			
	std::vector<Text>			texts;			
	std::vector<Texture>		textures;
	std::vector<CircleShape>	circles;
	std::vector<RectangleShape>	rectangles;		
	std::vector<Sprite>			sprites;

	std::vector<std::string> soundBufferIDs;
	std::vector<std::string> soundIDs;
	std::vector<std::string> musicIDs;
	std::vector<std::string> fontIDs;
	std::vector<std::string> textIDs;
	std::vector<std::string> textureIDs;
	std::vector<std::string> circleIDs;
	std::vector<std::string> rectangleIDs;
	std::vector<std::string> spriteIDs;

public:

	sf::VideoMode*			pGlobalVideoMode		= nullptr;
	sf::String*				pGlobalTitle			= nullptr;
	sf::Uint32*				pGlobalStyle			= nullptr;
	sf::ContextSettings*	pGlobalContextSettings	= nullptr;
	unsigned int*			pGlobalFramerateLimit	= nullptr;
	sf::Vector2f*			pGlobalAspectRatio		= nullptr;
	sf::Vector2f*			pGlobalScale			= nullptr;
	RenderWindow*			pGlobalWindow			= nullptr;

};

