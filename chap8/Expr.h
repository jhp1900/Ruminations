#ifndef CHAP8_EXPR_H
#define CHAP8_EXPR_H

#include <string>
#include <iostream>

class Expr_node;

class Expr
{
  friend class Expr_node;
  friend std::ostream & operator<< (std::ostream&, const Expr&);
  Expr_node * p;

public:
  Expr(int);
  Expr(const std::string&, Expr);
  Expr(const std::string&, Expr, Expr);
  Expr(const Expr&);
  Expr& operator= (const Expr&);
  ~Expr();
};

#endif // !CHAP8_EXPR_H
