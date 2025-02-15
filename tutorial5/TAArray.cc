#include <iostream>
using namespace std;

#include "TAArray.h"

// constructor
TAArray::TAArray(){
    size = 0;
    elements = new TextArea*[MAX_COMPONENTS];
}

// destructor
TAArray::~TAArray(){
    delete [] elements;
}

bool TextArea::add(TextArea* ta) {
    if (size >= MAX_COMPONENTS)return false;

    for (int i = size; i > 0 ; --i){
        if (ta->lessThan(*elements[i-1])){
            //keep making space by copying elements
            //one location to the right
            elements[i]=elements[i-1];
        }else{
            //we have found where s should go
            elements[i] = ta;
            ++size;
            return true;
        }
    }

    //we went through every location, and s was less than 
    //all of them. Therefore s goes in location 0
    elements[0] = s;
    ++size;
    return true;
}

bool TextArea::get(const string& id, TextArea** ta) {
    for (int i = 0; i < size; ++i){
        if (name == elements[i]->getID()){
            *ta = elements[i];
            return true;
        }
    }
    return false;
}

bool TextArea::get(int index, TextArea** ta) {
    if (index < 0 || index >= size) return false;
    *ta = elements[index];
    return true;
}

bool remove(const string& id, TextArea** ta) {
    int index = 0;
    //we want to find the index of the element to remove
    while (id != elements[index]->getID() && index < size){
        ++index;
    }

    //did we fall off the end of the List?
    if (index == size) return false;

    //we have found what we wanted to remove,
    //assign the output value
    *ta = elements[index];

    //copy everything after index left one position
    while (index < size - 1){
        elements[index] = elements[index + 1];
        ++index;
    }
    --size;
    return true;
}

void removeUpTo(const string& id, List& goners) {
    //find index of the first Student who comes after name
    int index = 0;

    while (id >= elements[index]->getID()&& index < size){
        //return them to the calling function
        arr.add(elements[index++]);
    }

    //the number of items to remove
    int toRemove = index;
    while(index < size){
        elements[index - toRemove] = elements[index];
        ++index;
    }

    size -= toRemove;
}

void print() {
  cout << endl << endl << "Students:" << endl;
  for (int i=0; i<size; ++i)
    elements[i]->print();

  cout << endl;
}