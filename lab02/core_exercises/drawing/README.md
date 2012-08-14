Core Exercise 1: Drawing Example
================================

![Screenshot](https://raw.github.com/adammw/hit3172/master/lab02/core_exercises/drawing/screenshot.png)

In the screenshot, there are 4 Rectangle objects, 1 Ellipse object, 1 Drawing object and 1 DrawingController object. The 5 Shape objects are part of the shapes array vector in the Drawing object, which is the controlling Drawing object of the DrawingController. When the main loop calls draw on the DrawingController object, it asks the Drawing object to draw and then prints the text of which Shape is currently selected on top. The drawing object asks each of its Shape objects to draw, which is handled by each different subclass of Shape, and call the various methods of the SwinGame Drawing API.

[View full doxygen documentation here](http://adammw.github.com/hit3172/lab02/core_exercises/drawing/doc/html/index.html).

