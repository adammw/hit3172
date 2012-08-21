Core Exercise 2: Blackjack Iteration 3
======================================

This program:

1. Creates a Blackjack Game object
2. Starts the game
3. Loop while the player chooses to "hit" and the player's hand is not full
 * Output description of dealer's hand
 * Output description of player's hand 
 * Ask the user to "Hit" or "Stand"
   * If they "Hit"
     * Tell the game to Hit
     * If the player busts print "You busted!"
   * If they "Stand"
     * Tell the game to Stand
4. Output description of dealer's hand 
5. Output description of player's hand 
6. Ask the game if the player has won
 * Print "You win!" or "You lose!"

The Blackjack Game object plays the role of the rules and logic of the game and how it uses the blackjack hand, the cards and deck. The blackjack hand object plays the role of each player, and has the responsibility to keep track of each players cards and score, and judge them as bust or blackjack. Therefore, to implement another game such as Poker, the Card and Deck classes can also be used by a separate Poker Game and Poker Hand objects, with the same responsiblities but implemented differently for the different game rules. The blackjack hand class is also important as its objects allow us to instantiate multiple hands for different players and keep track of their cards and score independently of each other.