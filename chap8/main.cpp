#include <iostream>
#include "Expr.h"

int main()
{
  Expr t = Expr("*", Expr("-", 5), Expr("+", 3, 4));
  std::cout << t << std::endl;
  t = Expr("*", t, t);
  std::cout << t << std::endl;

  std::cout << "���������ַ��˳���";
  getchar();
}