Core Exercise 3: Beggar My Neighbour
====================================

Design
------

![UML Class Diagram](https://raw.github.com/adammw/hit3172/master/lab04/core_exercises/beggar-my-neighbour/uml_class_diagram.png)

### Starting the game

Starting the game is done with the beggar_game object, which shuffles the deck, and distributes all the cards to each player's beggar_hand object evenly.

### Playing a card

Playing a card consists of drawing a card from the top of the hand, and if it is a ace or face card, remembering the number of penalty cards the opponent has to play. The card is then added to the discard pile object (discard_hand).

### Picking up winnings

When the number of penalty cards the opponent has to play reaches zero, the cards in the discard_hand is added to the players hand, and the discard_hand is cleared.