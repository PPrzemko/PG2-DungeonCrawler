#ifndef LIST_H
#define LIST_H
#include <stdexcept>
#include <iostream>
#include "level.h"


class List
{
private:
    struct Element{
        Level* level = nullptr;
        Element* prev_element = nullptr;
        Element* next_element = nullptr;
    };
    Element* top_element = nullptr;
    Element* bot_element = nullptr;
    size_t list_size = 0;


    public:
        class Iterator{
            public:
                Iterator(Element* currentElement);

                Iterator& operator++();
                Iterator& operator--();
                Level*& operator*();
                bool operator==(const Iterator& comparison);
                bool operator!=(const Iterator& comparison);
                Element* currentElement;


            private:

        };
        List();
        void push_back(Level* level);
        void push_front(Level* level);
        void pop_back();
        void pop_front();
        bool empty();
        size_t size() const;
        void remove(Level* level);
        Iterator begin();
        Iterator end();



};

#endif // LIST_H
