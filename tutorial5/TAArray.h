#ifndef TAARRAY_H
#define TAARRAY_H

#include "defs.h"
#include "TextArea.h"

class TAArray {
    public:
        // constructor
        TAArray();
        // deconstructor
        ~TAArray();
        
        // member functions
        bool add(TextArea*);
        bool get(const string& id, TextArea**);
        bool get(int index, TextArea**);
        bool remove(const string& id, TextArea**);
        void removeUpTo(const string& id, List& goners);
        inline int getSize(){ return size; }
        void print();

    private: 
        // member variables
        TextArea** elements;
        int size;
};


#endif