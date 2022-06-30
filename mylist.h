#include <cstddef>

class myList
{
  public:
  myList();
  ~myList();
  void push_back(int data);
  void pop_back();
  int& back();
  std::size_t size() const;
  bool empty() const;

  // This is just for demonstration purposes
  void print() const;

  private:
  struct Element
  {
    int data;
    Element* next;
  };
  Element* start     = nullptr;
  std::size_t m_size = 0;
};
