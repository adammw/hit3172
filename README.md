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