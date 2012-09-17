Swin-Adventure Case Study
=========================

## Vision

Swin-Adventure will provide hours of interactive fun for Swinburne students who want to be entertained during lectures on their notebooks. Swin-Adventure is a console based adventure game that allows people to explore a fantasy world instead of listening to lectures.

## Explaination

**Explain the features of the Identifiable Object class, and how you think this is likely to be used in future iterations**

The Identifiable Object class allows us to categorise other objects as idenitifiable in the future without having to rewrite any of the code to allow us to indentify the object. It also allows us to use a generalised Identifiable pointer to point to any object that is identifiable, regardless of it's actual subtype. The class itself supports adding particular identifiers to an object both during construction and afterwards with the add_identifier method, allows other objects to ask it if it is identifiable by a string name with the are_you method, as well as retrieving the first (primary) identifier with the first_id getter method.