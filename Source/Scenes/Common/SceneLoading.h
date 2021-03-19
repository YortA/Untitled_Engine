#pragma once

#include "Core/Scene.h"

enum class LOAD_STATE : unsigned int
{
	LOADING,
	FINISHED
};

class SceneLoading : public Scene
{
public:

	virtual void create()	override;
	virtual void setup()	override;
	virtual void update()	override;
	virtual void render()	override;
	virtual void destroy()	override;

private:

	void setupMain();
	void setupFonts();
	void setupTexts();
	void setupRectangles();

private:

	void updateLoadingDots(RectangleShape& dot1, RectangleShape& dot2, RectangleShape& dot3);
	void updateLoadingBars(RectangleShape& bar1, RectangleShape& bar2);
	void updateSplashScreen(RectangleShape& splashScreen);

private:

	void slingDotIn(RectangleShape& dot);
	void slingDotOut(RectangleShape& dot);
	void slingDotsIn(RectangleShape& dot1, RectangleShape& dot2, RectangleShape& dot3);
	void slingDotsOut(RectangleShape& dot1, RectangleShape& dot2, RectangleShape& dot3);
	bool allDotsInCenter(RectangleShape& dot1, RectangleShape& dot2, RectangleShape& dot3);
	bool allDotsOffScreen(RectangleShape& dot1, RectangleShape& dot2, RectangleShape& dot3);
	
private:

	LOAD_STATE		loadState		= LOAD_STATE::LOADING;
	bool			dotLoopSlingIn	= false;
	bool			dotLoopSlingOut = false;
	float			fadeSpeed		= 0.f;
	float			animationSpeed	= 0.f;
	sf::Color		darkOrange		= sf::Color();
	sf::Color		darkGrey		= sf::Color();

};