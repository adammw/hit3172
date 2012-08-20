#include <stdio.h>
#include <stdbool.h>
#include "SwinGame.h"
#include "deck.h"
#include "card.h"

#define CARD_WIDTH 202.5
#define CARD_HEIGHT 315

void draw_card(card* card, point2d position) {
    // load a bitmap containing all the cards
    static bitmap cards_bitmap = load_bitmap("cards.png");
    int x = 2, y = 4; // card back position

	// Only change to the correct card if pointer is non-null and card is face up
	if (card && card->is_faceup() && card->get_rank() < card::RANK_MAX && card->get_suit() < card::SUIT_MAX) {
		x = card->get_rank() - 1;
		y = card->get_suit();
	}

	// Draw the portion of the bitmap sheet with the card on it
	draw_bitmap_part(cards_bitmap, x*CARD_WIDTH, y*CARD_HEIGHT, CARD_WIDTH, CARD_HEIGHT, position.x, position.y);
}

int main()
{
    open_audio();
    open_graphics_window("Blackjack", 800, 600);
    load_default_colors();

    /* create a deck of cards */
    deck* current_deck = new deck;
    card* active_card = NULL;

    /* loop until the window is closed */
    do
    {
        process_events();

        /* if the user clicks the deck, draw a card out of the deck */
        if (mouse_clicked(LEFT_BUTTON) &&
        		mouse_position().x >= 30 &&
        		mouse_position().x <= 30 + CARD_WIDTH &&
        		mouse_position().y >= (int)(300 - (CARD_HEIGHT * 0.5)) &&
        		mouse_position().y <= (int)(300 + (CARD_HEIGHT * 0.5)) &&
        		current_deck->get_cards_remaining()) {

        	active_card = current_deck->draw();

        	/* make sure the active card is face up */
        	if (!active_card->is_faceup())
        		active_card->turn_over();
        }

        /* if the user presses the S key, shuffle the deck */
        if (key_typed(VK_S)) {
        	current_deck->shuffle();
        	active_card = NULL;
        }

        /* clear the screen on each loop */
        clear_screen(ColorWhite);

        /* draw a rectangle outline */
        draw_rectangle(color_black, 20, (int)(290 - (CARD_HEIGHT * 0.5)), CARD_WIDTH + 20, CARD_HEIGHT + 20);

        /* draw the deck if there are remaining cards */
        point2d position = {30, (int)(300 - (CARD_HEIGHT * 0.5))};
        if (current_deck->get_cards_remaining())
			draw_card(NULL, position);

        /* draw the active card */
        position.x = 760 - CARD_WIDTH;
        if (active_card)
        	draw_card(active_card, position);

        /* draw the framerate counter */
        draw_framerate(0,0);
        
        /* limit to 60 FPS */
        refresh_screen(60);

    } while ( ! window_close_requested() );
    
    /* delete the card deck on exit */
    delete current_deck;

    close_audio();
    
    release_all_resources();
    return 0;
}
