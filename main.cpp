
#include <SFML/Graphics.hpp>
#include "settings.h"
#include "Grass.h"
#include "Player.h"
#include "Textobj.h"
#include "game.h"
using namespace sf;

int main()
{
	// Îáúåêò, êîòîðûé, ñîáñòâåííî, ÿâëÿåòñÿ ãëàâíûì îêíîì ïðèëîæåíèÿ
	RenderWindow window(VideoMode(width, height), WINDOW_TITLE);
	window.setFramerateLimit(FPS);
	Player player(Vector2f{ 500.f,0.f });
	Weed weed(Vector2f{ 0.f,0.f }, "Weed1.jpg");
	Score score(Vector2f{ 1400.f,10.f });
	Game game;
	// Ãëàâíûé öèêë ïðèëîæåíèÿ. Âûïîëíÿåòñÿ, ïîêà îòêðûòî îêíî
	while (window.isOpen())
	{
		// Îáðàáàòûâàåì î÷åðåäü ñîáûòèé â öèêëå
		Event event;
		while (window.pollEvent(event))
		{
			// Ïîëüçîâàòåëü íàæàë íà «êðåñòèê» è õî÷åò çàêðûòü îêíî?
			if (event.type == Event::Closed)
				// òîãäà çàêðûâàåì åãî
				window.close();
		}
		player.update();
		score.updateText(player.getScore());
		game.update();
		// Îòðèñîâêà îêíà 
		window.clear();
		weed.draw(window);
		score.draw(window);
		player.draw(window);
		game.draw(window);
		window.display();
	}

	return 0;
}