Core Exercise 3: Blackjack Iteration 1
======================================

This program is the start of a object-oriented Blackjack card game program.

This iteration deals with the Card class; each card must know its rank, suit and if it is face up,
as well as being able to get its description and be turned over. 

The main function does the following:

1. Reads a rank and suit from the user. 
2. Creates a matching Card object
3. In a loop asks the user if they want to:
  * **Turn Card Over** - in which case the Card object is told to turn over
  * **Show Card** - gets the Card object's description and writes it to the Terminal. 
  * **Quit** - ends the program

**What happens if you ask the null/nil card for its description, or to turn over?**

If the card pointer is NULL, that means it does not actually point to the location in memory where the object is stored, so attempting to call any methods of that piece of memory will cause undefined behaviour that is dependent on both the operating system and the compiler. In most systems, it causes the program to be halted or crash with a segmentation fault.

**Do the cards maintain their own identity? What does this mean?**

The card objects are all unique - they each hold their own data values. Calling a method on one card object will not affect the data in any other card object directly. To share any values between all objects of the class, the value must be part of the class rather than the object (i.e. static).