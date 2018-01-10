#include <iostream>
#include "Picture.h"

char * init[] = { "Paris", "in the", "Spring" };

int main()
{
  Picture p(init, 3);
  std::cout << p << std::endl;
  Picture q = frame(p);
  std::cout << q << std::endl;
  std::cout << frame(q & frame(p | q)) << std::endl;

  std::cout << "输入任意字符退出：";
  getchar();
  return 0;
}