#include <iostream>

#include "TextArea.h"

// constructors
TextArea::TextArea(): x(0), y(0), width(0), height(0), text(""), id(""), fill(RGB::WHITE()), border(RGB::BLACK()) {}

TextArea::TextArea(int x, int y, int width, int height, const std::string& id, const std::string& text)
    : x(x), y(y), width(width), height(height), id(id), text(text), fill(RGB::WHITE()), border(RGB::BLACK()) {}

TextArea::TextArea(const Rectangle& rectangle, const std::string& id, const std::string& text, RGB fill, RGB border): 
    x(rectangle.x), y(rectangle.y), width(rectangle.width), height(rectangle.height), id(id), text(text), fill(fill), border(border) {}

// copy constructors
TextArea::TextArea(const TextArea& other): x(other.x), y(other.y), width(other.width), height(other.height), id(other.id), 
    text("DUPLICATE"), fill(other.fill), border(other.border) {}

// getter functions
int TextArea::getX() const { return x; }
int TextArea::getY() const { return y; }
int TextArea::getHeight() const { return height; }
int TextArea::getWidth() const{ return width; }
RGB TextArea::getFill() { return fill; }
RGB TextArea::getBorder() { return border; }

// setter functions
void TextArea::setFill(RGB fill) { this->fill = fill; }
void TextArea::setBorder(RGB border) { this->border = border; }

// draw a textarea onto the window
void draw(Display* display, Window win, GC gc, int x, int y) {
    // draw the textarea background
    /*XSetForeground(display, gc, fill.getColour());
    XFillRectangle(display, win, gc, drawX, drawY, width, height);

    // draw the textarea border
    XSetForeground(display, gc, border.getColour());
    XDrawRectangle(display, win, gc, drawX, drawY, width - 1, height - 1);

    // draw the textarea text
    XSetForeground(display, gc, border.getColour());
    XDrawString(display, win, gc, drawX + 5, drawY + 15, text.c_str(), text.length());    */
}

// check if 2 textareas overlap
bool TextArea::overlaps(const TextArea& ta) const {
    if (((x + width <= ta.getX()) || ta.getX() + ta.getWidth() <= x)
    || ((y + height <= ta.getY()) || ta.getY() + ta.getHeight() <= y)) {
        return false;
    }
    return true;
}

// print textarea info
void TextArea::print() const {
    std::cout << "TextArea id:\t\t" << id << "\nPreferred location:\t" << x << ", " << y 
        << "\nSize:\t\t\t" << width << ", " << height << "\nText:\t\t\t" << text << std:: endl;
}