Core Exercise 2: Counter
========================

The program creates two counter objects: `counter1` and `counter2`, by using the new keyword on the counter class.
The program allocates memory for the new objects and runs the counter constructor which initialses the count, before returning a pointer to the objects. The increment method is called 5 times on the first counter, and 10 times on the second counter. Each time, the object increments its count field internally. Then the `get_value` method is called to return the value of each object's count, before printing it to the screen. Finally, the objects are destroyed by the delete keyword.

![Sequence Diagram](https://raw.github.com/adammw/hit3172/master/lab01/core_exercises/counter/sequence_diagram.png)