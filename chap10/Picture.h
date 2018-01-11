#ifndef CHAP10_PICTURE_H
#define CHAP10_PICTURE_H

#include <iostream>

class P_Node;

class Picture
{
public:
  Picture(const char* const*, int);
  Picture(const Picture&);
  ~Picture();

private:
  friend std::ostream& operator<< (std::ostream&, const Picture&);
  friend Picture frame(const Picture&);
  friend Picture operator& (const Picture&, const Picture&);
  friend Picture operator| (const Picture&, const Picture&);

private:
  P_Node * p;
};

#endif // !CHAP10_PICTURE_H
