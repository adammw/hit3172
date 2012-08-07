#include <stdio.h>
#include <stdbool.h>
#include "SwinGame.h"
#include "Card.h"
#include "GraphicalCard.h"

int main()
{
    open_audio();
    open_graphics_window("Blackjack", 800, 600);
    load_default_colors();

    /* load a bitmap containing all the cards */
    bitmap cardsBitmap = load_bitmap("cards.png");

    /* initalise an array of cards, and position them */
    const int num_cards = 8;
    int i;
    GraphicalCard* cards[num_cards];
    point2d pos = {0};
    for ( i = 0; i < num_cards; i++) {
    	cards[i] = new GraphicalCard(cardsBitmap, (Card::rank)(rand() % 12 + 1), (Card::suit)(rand() % 4));
    	cards[i]->set_position(pos);
    	pos.x += CARD_WIDTH;
    	if (i % 4 == 3) { pos.y += CARD_HEIGHT; pos.x = 0; }
	}

    do
    {
        process_events();
        
        /* turn over cards when clicked */
        if (mouse_clicked(LEFT_BUTTON)) {
        	for ( i = 0; i < num_cards; i++) {
        		if (cards[i]->is_at(mouse_position()))
        			cards[i]->turn_over();
        	}
        }

        clear_screen(ColorWhite);

        /* draw cards */
        for ( i = 0; i < num_cards; i++) {
			cards[i]->draw();
		}

        draw_framerate(0,0);
        
        refresh_screen();
    } while ( ! window_close_requested() );
    
    /* release card objects when closing */
    for ( i = 0; i < num_cards; i++) {
		delete cards[i];
	}

    close_audio();
    
    release_all_resources();
    return 0;
}
