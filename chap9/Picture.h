#ifndef CHAP9_PICTURE_H
#define CHAP9_PICTURE_H

#include <iostream>

class Picture
{
friend std::ostream& operator<< (std::ostream&, const Picture&);

friend Picture frame(const Picture&);
friend Picture operator& (const Picture&, const Picture&);
friend Picture operator| (const Picture&, const Picture&);

public:
  Picture();
  Picture(const char* const*, int);
  Picture(const Picture&);
  ~Picture();

  Picture& operator= (const Picture&);

private:
  void Init(int h, int w);
  char & position(int row, int col);
  char position(int row, int col) const;
  void copyblock(int h, int w, const Picture& p);

private:
  int height, width;
  char * data;
};



#endif // !CHAP9_PICTURE_H
