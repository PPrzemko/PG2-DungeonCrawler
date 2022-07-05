#include "mylist.h"

using std::cout;
using std::endl;

myList::myList()
{
}

myList::~myList()
{
  while (start != nullptr)
  {
    pop_back();
  }
}

void myList::push_back(int data)
{
  Element* tmp = new Element{data, nullptr};

  // list is empty
  if (empty())
  {
    start = tmp;
    m_size++;
    return;
  }

  // search last Element
  Element* current = start;
  while (current->next != nullptr)
  {
    // advance current pointer by one element
    current = current->next;
  }
  current->next = tmp;
  m_size++;
}

void myList::print() const
{
  // In order to iterate over the list, we need a "current element" pointer
  // which is then advanced by one element in each iteration
  Element* current = start;
  while (current != nullptr)
  {
    cout << current->data << " ";
    current = current->next;
  }
  cout << endl;
}

void myList::pop_back()
{
  // list is already empty
  if (start == nullptr)
  {
    return;
  }

  // list has single element
  if (start->next == nullptr)
  {
    delete start;
    start = nullptr;
    return;
  }

  // if list has 2 or more elements, look for the second last element
  Element* current = start;
  while (current->next->next != nullptr)
  {
    current = current->next;
  }
  delete current->next;
  current->next = nullptr;
  m_size--;
}

std::size_t myList::size() const
{
  return m_size;
}

bool myList::empty() const
{
  return m_size == 0;
  // Alternatively: return start == nullptr;
}

int main()
{
  myList l;
  l.push_back(2);
  l.push_back(3);
  l.push_back(5);
  l.push_back(7);
  l.push_back(11);

  l.print();

  l.pop_back();
  l.print();
}

