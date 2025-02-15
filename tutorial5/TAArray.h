#ifndef TAARRAY_H
#define TAARRAY_H

using namespace std;

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
        bool add(TextArea*, int index);
        bool get(const string& id, TextArea**);
        bool get(int index, TextArea**) const;
        TextArea* get(int index) const;
        TextArea* get(const string& id) const;
        bool remove(const string& id, TextArea**);
        TextArea* remove(int index);
        TextArea* remove(const string& id);
        void removeUpTo(const string& id, TAArray& goners);
        inline int getSize(){ return size; }
        void print();

    private: 
        // member variables
        TextArea** elements;
        int size;
};


#endif