#include "Expr.h"
#include "Expr_node.h"

std::ostream & operator<< (std::ostream& o, const Expr& t)
{
  t.p->print(o);
  return o;
}

Expr::Expr(int n)
{
  p = new Int_node(n);
}

Expr::Expr(const std::string & op, Expr t)
{
  p = new Unary_node(op, t);
}

Expr::Expr(const std::string & op, Expr left, Expr right)
{
  p = new Binary_node(op, left, right);
}

Expr::Expr(const std::string & op, Expr left, Expr middle, Expr right)
{
  p = new Ternary_node(op, left, middle, right);
}

Expr::Expr(const Expr & t)
{
  p = t.p;
  ++p->use;
}

Expr & Expr::operator=(const Expr & rhs)
{
  rhs.p->use++;
  if (--p->use == 0)
    delete p;
  p = rhs.p;
  return *this;
}

Expr::~Expr()
{
  if (--p->use == 0)
    delete p;
}

int Expr::eval() const
{
  return p->eval();
}
