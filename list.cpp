#include "list.h"


using namespace std;
List::List()
{

}

void List::push_back(Level* level)
{
    Element* new_element = new Element();
    new_element->level = level;
    new_element->prev_element = bot_element;
    if(bot_element != nullptr){
        bot_element->next_element = new_element;
    }
    bot_element = new_element;
    if(!list_size){
        top_element = new_element;
    }
    list_size++;
}

void List::push_front(Level* level)
{
    Element* new_element = new Element();
    new_element->level = level;
    new_element->next_element = top_element;
    if(top_element != nullptr){
       top_element->prev_element = new_element;
    }
    top_element = new_element;
    if(!list_size){
      bot_element = new_element;
    }
    list_size++;
}

void List::pop_back()
{
    if(empty()) throw 0;
    Element* this_element = bot_element;
    if(list_size == 1){
        top_element = nullptr;
        bot_element = nullptr;
        delete this_element;
        list_size--;
        return;
    }
    else{
        bot_element = bot_element->prev_element;
        bot_element->next_element = nullptr;
        delete this_element;
        list_size--;
        return;
    }
}

void List::pop_front()
{
    if(empty()) throw 0;
    Element* this_element = top_element;
    if(list_size == 1){
        top_element = nullptr;
        bot_element = nullptr;
        delete this_element;
        list_size--;
        return;
    }
    else{
        top_element = top_element->next_element;
        top_element->prev_element = nullptr;
        delete this_element;
        list_size--;
        return;
    }
}

bool List::empty()
{
    if(!list_size){
        return true;
    }else{
        return false;
    }

}

size_t List::size() const
{
    return list_size;
}

void List::remove(Level* level)
{
    for(auto elements=this->begin(); elements != this->end(); ++elements){
        bool found = elements.currentElement->level == level;
        if(found){
            if(elements.currentElement == this->top_element){
                this->pop_back();
            }else if(elements.currentElement == this->bot_element){
                this->pop_front();
            }else{
                elements.currentElement->prev_element->next_element = elements.currentElement->next_element;
                elements.currentElement->next_element->prev_element = elements.currentElement->prev_element;
                delete elements.currentElement;
            }
            this->list_size--;
        }
    }
}

// ITERATOR SHIT
List::Iterator::Iterator(Element *currentElement): currentElement(currentElement)
{

}
List::Iterator List::begin()
{
    return Iterator(top_element);
}

List::Iterator List::end()
{
    return Iterator(bot_element);
}

List::Iterator &List::Iterator::operator++()
{
    if(this->currentElement){
        this->currentElement = this->currentElement->next_element;
        return *this;
    }else{
        throw 0;
    }

}

List::Iterator &List::Iterator::operator--()
{
    if(this->currentElement){
        this->currentElement = this->currentElement->prev_element;
        return *this;
    }else{
        throw 0;
    }
}

Level *&List::Iterator::operator*()
{
    return this->currentElement->level;
}

bool List::Iterator::operator==(const Iterator &comparison)
{
    if(this->currentElement == comparison.currentElement){
        return true;
    }
    return false;
}

bool List::Iterator::operator!=(const Iterator &comparison)
{
    if(this->currentElement != comparison.currentElement){
        return true;
    }
    return false;
}















