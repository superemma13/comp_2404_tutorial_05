#ifndef TEXTAREA_H
#define TEXTAREA_H

#include <X11/Xlib.h>
#include <unistd.h>
#include <string>

#include "defs.h"
#include "RGB.h"

class TextArea {
    public:
        // constructors
        TextArea();
        TextArea(int x, int y, int width, int height, const std::string& id, const std::string& text);
        TextArea(const Rectangle& rectangle, const std::string& id, const std::string& text, RGB fill = RGB::WHITE(), RGB border = RGB::BLACK());
        
        // copy constructors
        TextArea(const TextArea& other);

        // getter functions
        int getX() const;
        int getY() const;
        int getHeight() const;
        int getWidth() const;
        RGB getFill();
        RGB getBorder();
        std::string getID();

        // setter functions
        void setFill(RGB fill);
        void setBorder(RGB border);

        // member functions
        void draw(Display* display, Window win, GC gc, int x, int y);
        bool overlaps(const TextArea& ta) const;
        void print() const;
        
    private: 
        // member variables
        int x, y;
        int width, height;
        std::string text;
        std::string id;       
        RGB fill, border;
};

#endif