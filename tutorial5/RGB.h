#ifndef RGB_H
#define RGB_H

#include "defs.h"

class RGB {
    public:
        // constructors
        RGB();
        RGB(int red, int green, int blue);
        
        // getter functions
        int getR() const;
        int getG() const;
        int getB() const;

        // setter functions
        
        // member functions
        void print();

        // static funtions
        static RGB WHITE();
        static RGB BLACK();
        static RGB RED();
        static RGB GREEN();
        static RGB BLUE();

    private: 
        // member variables
        int r;
        int g;
        int b;
};

#endif