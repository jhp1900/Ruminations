#ifndef CHAP8_EXPR_NODE_H
#define CHAP8_EXPR_NODE_H

#include <string>
#include <iostream>

#include "Expr.h"

class Expr_node
{
  friend class Expr;
  friend std::ostream & operator<< (std::ostream&, const Expr&);
  int use;

protected:
  Expr_node();
  virtual void print(std::ostream&) const = 0;
  virtual ~Expr_node();
};

class Int_node : public Expr_node
{
  friend class Expr;
  int n;

  Int_node(int k);
  void print(std::ostream& o) const;
};

class Unary_node : public Expr_node
{
  friend class Expr;
  std::string op;
  Expr opnd;

  Unary_node(const std::string & a, Expr b);
  void print(std::ostream & o) const;
};

class Binary_node : public Expr_node
{
  friend class Expr;
  std::string op;
  Expr left;
  Expr right;

  Binary_node(const std::string & a, Expr b, Expr c);
  void print(std::ostream & o) const;
};

#endif // !CHAP8_EXPR_NODE_H

