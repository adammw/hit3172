Swin-Adventure Case Study
=========================

## Vision

Swin-Adventure will provide hours of interactive fun for Swinburne students who want to be entertained during lectures on their notebooks. Swin-Adventure is a console based adventure game that allows people to explore a fantasy world instead of listening to lectures.

## Explainations

**Explain the features of the Identifiable Object class, and how you think this is likely to be used in future iterations**

The Identifiable Object class allows us to categorise other objects as idenitifiable in the future without having to rewrite any of the code to allow us to indentify the object. It also allows us to use a generalised Identifiable pointer to point to any object that is identifiable, regardless of it's actual subtype. The class itself supports adding particular identifiers to an object both during construction and afterwards with the add_identifier method, allows other objects to ask it if it is identifiable by a string name with the are_you method, as well as retrieving the first (primary) identifier with the first_id getter method.

**How does the Player locate items?**

The Player can locate items by first checking if the identifier matches itself (as it itself is an Identifiable Object), then asking the inventory to fetch the item with the identifier specified. The inventory object then asks each individual item it contains if it matches the identifier, and returns the first item that matches. If no items match, NULL is returned. The Player object then returns whatever the inventory object returned.

**What roles do other objects play in helping the Player achieve this goal?**

The Inventory helps the Player to check each of the items in the inventory for a match, and each Item helps the Inventory check if it matches the identifier by inheriting the Game Object which inherits the Identifiable Object class allowing it to be asked "are you xxx?".

**Explain the role of the “I Have Inventory” interface/protocol. Why is it included in the design?**

The "I Have Inventory" interface is used to allow other objects to perform actions on any object that has an inventory regardless of their implementation and actual class. It is included in the design as it allows us to be more flexible in later code, and not have to worry about for example the differences between Bag and Player objects as they both have "promised" to implement the "I Have Inventory" interface.

Also, we can add extra functionality to the Player object later for other features without distrubing the other objects that use the same interface.

**Iteration 4 (Locations) UML Class Diagram**
![uml class diagram](https://raw.github.com/adammw/hit3172/case_study/diagrams/uml_class_iteration_4.png)

**Iteration 4 (Locations) Player Locate Sequence Diagram**
![uml sequence diagram](https://raw.github.com/adammw/hit3172/case_study/diagrams/player_locate_sequence.png)

**Iteration 5 (Paths and Moving) UML Class Diagram**
![uml class diagram](https://raw.github.com/adammw/hit3172/case_study/diagrams/uml_class_iteration_5.png)

**Iteration 4 (Paths and Moving) Move Command Sequence Diagram**
![uml sequence diagram](https://raw.github.com/adammw/hit3172/case_study/diagrams/move_command_sequence.png)