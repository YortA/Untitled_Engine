#pragma once

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>

class Sprite : public sf::Sprite
{
public:

	void setup(
		const sf::Vector2f& size			= sf::Vector2f(0.f, 0.f),	//
		const sf::Vector2f& origin			= sf::Vector2f(0.f, 0.f),	//
		const sf::Vector2f& scale			= sf::Vector2f(1.f, 1.f),	//
		const sf::Vector2f& position		= sf::Vector2f(0.f, 0.f),	//
		const sf::Color&	color			= sf::Color::White,			//
		const sf::Uint8&	opacity			= sf::Uint8(0),				//	I like to be explicit here even though color will take care of it as well
		bool				isRenderEnabled = true,						//
		unsigned int		renderLayer		= 1,						//
		sf::Texture*		texture			= nullptr)					//
	{
		if (texture != nullptr)
		{
			setTexture(*texture);
		}

		setOrigin(origin);
		setScale(scale);
		setPosition(position);
		setColor(color);
		setOpacity(opacity);
		setRenderEnabled(isRenderEnabled);
		setRenderLayer(renderLayer);
	}

public:

	void setPosition(float x, float y, bool scaled = true)
	{
		setPosition(sf::Vector2f(x, y), scaled);
	}

	void setPosition(const sf::Vector2f& position, bool scaled = true)
	{
		if (scaled)
		{
			sf::Sprite::setPosition(position.x * getScale().x, position.y * getScale().y);
		}
		else
		{
			sf::Sprite::setPosition(position.x, position.y);
		}
	}

	sf::Uint8 getOpacity()
	{
		return getColor().a;
	}

	void setOpacity(sf::Uint8 transparency)
	{
		setColor(sf::Color(
			getColor().r,
			getColor().g,
			getColor().b,
			transparency));
	}

	bool isTransparent()
	{
		if (getOpacity() > 0)
		{
			return false;
		}
		else
		{
			return true;
		}
	}

	bool isOpaque()
	{
		if (getOpacity() < 255)
		{
			return false;
		}
		else
		{
			return true;
		}
	}

	void fadeOut(float speed)
	{
		if ((getOpacity() - sf::Uint8(speed)) <= 0)
		{
			setOpacity(0);
		}
		else
		{
			setOpacity(getOpacity() - sf::Uint8(speed));
		}
	}

	void fadeIn(float speed)
	{
		if ((getOpacity() + sf::Uint8(speed)) >= 255)
		{
			setOpacity(255);
		}
		else
		{
			setOpacity(getOpacity() + sf::Uint8(speed));
		}
	}

public:

	void setSpeed(const sf::Vector2f& speed)
	{
		this->speed = speed;
	}

	void setSpeed(float x, float y)
	{
		this->speed = sf::Vector2f(x, y);
	}

	sf::Vector2f getSpeed()
	{
		return speed;
	}

public:

	void setRenderEnabled(bool renderEnabled)
	{
		this->renderEnabled = renderEnabled;
	}

	bool isRenderEnabled()
	{
		return renderEnabled;
	}

public:

	void setRenderLayer(unsigned int renderLayer)
	{
		this->renderLayer = renderLayer;
	}

	unsigned int getRenderLayer()
	{
		return renderLayer;
	}

private:

	sf::Vector2f	speed = sf::Vector2f();
	bool			renderEnabled = false;
	unsigned int	renderLayer = 1;

};

