#include <iostream>
#include "Picture.h"

char * init[] = { "Paris", "in the", "Spring" };

int main()
{
  Picture pic(init, 3);
  Picture q = frame(pic);
  std::cout << frame(q & (pic | q)) << std::endl;

  std::cout << "���������ַ��˳���";
  getchar();
  return 0;
}