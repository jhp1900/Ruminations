#include <algorithm>
#include "Picture.h"

Picture::Picture()
  : height(0)
  , width(0)
  , data(0)
{
}

Picture::Picture(const char * const * array, int n)
{
  int w = 0;
  for (int i = 0; i < n; ++i)
    w = std::max(w, (int)strlen(array[i]));
  Init(n, w);

  for (int i = 0; i < n; ++i) {
    const char* src = array[i];
    int len = strlen(src);
    int j = 0;

    for ( ; j < len; ++j) 
      position(i, j) = src[j];

    for ( ; j < width; ++j) 
      position(i, j) = ' ';
  }
}

Picture::Picture(const Picture & p)
  : height(p.height)
  , width(p.width)
  , data(new char[p.height * p.width])
{
  copyblock(0, 0, p);
}

Picture::~Picture()
{
  delete[] data;
}

Picture & Picture::operator=(const Picture & p)
{
  if (this != &p) {
    delete[] data;
    Init(p.height, p.width);
    copyblock(0, 0, p);
  }
  return *this;
}

void Picture::Init(int h, int w)
{
  height = h;
  width = w;
  data = new char[height * width];
}

char & Picture::position(int row, int col)
{
  return data[row * width + col];
}

char Picture::position(int row, int col) const
{
  return data[row * width + col];
}

void Picture::copyblock(int row, int col, const Picture & p)
{
  for (int i = 0; i < p.height; ++i) {
    for (int j = 0; j < p.width; ++j)
      position(i + row, j + col) = p.position(i, j);
  }
}

void Picture::clear(int h1, int w1, int h2, int w2)
{
}

void Picture::clear()
{
  for (int i = 0; i < height; ++i) {
    for (int j = 0; j < width; ++j)
      position(i, j) = ' ';
  }
}

std::ostream & operator<<(std::ostream & o, const Picture & p)
{
  for (int i = 0; i < p.height; ++i) {
    for (int j = 0; j < p.width; ++j)
      o << p.position(i, j);
    o << std::endl;
  }
  return o;
}

Picture frame(const Picture& p)
{
  Picture r;
  r.Init(p.height + 2, p.width + 2);

  for (int i = 1; i < r.height - 1; ++i) {
    r.position(i, 0) = '|';
    r.position(i, r.width - 1) = '|';
  }

  for (int j = 1; j < r.width - 1; ++j) {
    r.position(0, j) = '-';
    r.position(r.height - 1, j) = '-';
  }

  r.position(0, 0) = '+';
  r.position(0, r.width - 1) = '+';
  r.position(r.height - 1, 0) = '+';
  r.position(r.height - 1, r.width - 1) = '+';

  r.copyblock(1, 1, p);

  return r;
}

Picture operator&(const Picture & p, const Picture & q)
{
  Picture r;
  r.Init(p.height + q.height, std::max(p.width, q.width));
  r.clear();
  r.copyblock(0, 0, p);
  r.copyblock(p.height, 0, q);
  return r;
}

Picture operator|(const Picture & p, const Picture & q)
{
  Picture r;
  r.Init(std::max(p.height, q.height), p.width + q.width);
  r.clear();
  r.copyblock(0, 0, p);
  r.copyblock(0, p.width, q);
  return r;
}
