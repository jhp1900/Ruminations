#include <iostream>
#include "Expr.h"

int main()
{
  Expr t = Expr("*", Expr("-", 5), Expr("+", 3, 4));
  std::cout << t << " = " << t.eval() << std::endl;

  t = Expr("*", t, t);
  std::cout << t << " = " << t.eval() << std::endl;

  t = Expr("?", 1, 2, 3);
  std::cout << t << " = " << t.eval() << std::endl;

  std::cout << "输入任意字符退出：";
  getchar();
}