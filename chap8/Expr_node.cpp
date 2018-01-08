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

int Int_node::eval() const
{
  return n;
}

Unary_node::Unary_node(const std::string & a, Expr b)
  : op(a), opnd(b) 
{
}

void Unary_node::print(std::ostream & o) const
{
  o << "(" << op << opnd << ")";
}

int Unary_node::eval() const
{
  if (op == "-")
    return -opnd.eval();
  throw "error, bad op " + op + " int UnaryNode";
}

Binary_node::Binary_node(const std::string & a, Expr b, Expr c)
  : op(a), left(b), right(c) 
{
}

void Binary_node::print(std::ostream & o) const
{
  o << "(" << left << op << right << ")";
}

int Binary_node::eval() const
{
  int op1 = left.eval();
  int op2 = right.eval();

  if (op == "-")
    return op1 - op2;
  else if (op == "+")
    return op1 + op2;
  else if (op == "*")
    return op1 * op2;
  else if (op == "/" && op2 != 0)
    return op1 / op2;

  throw "error, bad op " + op + " in BinaryNode";
}

Ternary_node::Ternary_node(const std::string & a, Expr b, Expr c, Expr d)
  : op(a), left(b), middle(c), right(d)
{
}

void Ternary_node::print(std::ostream & o) const
{
  o << "(" << left << " ? " << middle << " : " << right << ")";
}

int Ternary_node::eval() const
{
  if (left.eval())
    return middle.eval();
  else
    return right.eval();
}
