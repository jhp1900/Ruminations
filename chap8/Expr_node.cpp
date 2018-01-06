#include "Expr_node.h"

Expr_node::Expr_node()
  : use(1)
{
}

Expr_node::~Expr_node()
{
}

Int_node::Int_node(int k)
  : n(k) 
{
}

void Int_node::print(std::ostream & o) const
{
  o << n;
}

Unary_node::Unary_node(const std::string & a, Expr b)
  : op(a), opnd(b) 
{
}

void Unary_node::print(std::ostream & o) const
{
  o << "(" << op << opnd << ")";
}

Binary_node::Binary_node(const std::string & a, Expr b, Expr c)
  : op(a), left(b), right(c) 
{
}

void Binary_node::print(std::ostream & o) const
{
  o << "(" << left << op << right << ")";
}
