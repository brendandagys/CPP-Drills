
// This program implements a basic expression calculator based in this input
// grammar:
//
//  Calculation:
//      Statement
//      Print
//      Quit
//      Calculation Statement
//  Statement:
//      Declaration
//      Expression
//  Print:
//      ";"
//  Quit:
//      "quit"
//  Declaration:
//      "let" Name "=" Expression
//  Expression:
//      Term
//      Expression "+" Term
//      Expression "-" Term
//  Term:
//      Primary
//      Term "*" Primary
//      Term "/" Primary
//      Term "%" Primary
//  Primary:
//      Number
//      "("Expression")"
//      "-" Primary
//      "+" Primary
//      Name
//      Function"("Expression")"
//  Function:
//      "sqrt"
//  Number:
//      [floating-point-literal]
//  Name:
//      [alphabetic-char]
//      Name[alphabetic-char]
//      Name[digit-char]

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

class Token {
    public:
        char kind;
        double value;
        string name;

        Token(char ch) :kind(ch) {}
        Token(char ch, double val) :kind(ch), value(val) {}
        Token(char ch, string n) :kind(ch), name(n) {}
};

class Token_stream {
    public:
        Token_stream() :full(false), buffer(0) {}
        Token get();
        void putback(Token t) { buffer = t; full = true; }
        void ignore(char);

    private:
        bool full;
        Token buffer;
};

const char let = '#';
const char quit = 'Q';
const char print = ';';
const char number = '8';
const char sroot = 's';
const char power = 'p';
const char name = 'a';

const string quitkey = "exit";
const string sqrtkey = "sqrt";
const string powerkey = "pow";

Token Token_stream::get()
{
	if (full) { full = false; return buffer; }
	char ch;
	cin >> ch;
	switch (ch) {
    case '(': case ')':	case '+':	case '-':	case '*':	case '/':	case '%':	case ';':	case '=': case ',': case let:
		return Token(ch);

	case '.':	case '0':	case '1':	case '2':	case '3':	case '4':	case '5':	case '6':	case '7':	case '8':	case '9':
	{	
      cin.putback(ch);
	    double val;
	    cin >> val;
	    return Token(number, val);
	}
	default:
		if (isalpha(ch)) {
			string s;
			s += ch;
			while (cin.get(ch) && (isalpha(ch) || isdigit(ch))) s += ch;
			cin.putback(ch);
			if (s == quitkey) return Token(quit);
      if (s == sqrtkey) return Token(sroot);
      if (s == powerkey) return Token(power);
			return Token(name, s);
		}

		throw runtime_error("Bad token");
	}
}

void Token_stream::ignore(char c)
{
	if (full && c == buffer.kind) {
		full = false;
		return;
	}
	full = false;

	char ch;
	while (cin >> ch)
		if (ch == c) return;
}

class Variable {
    public:
      	string name;
      	double value;
        Variable(string n, double v) :name(n), value(v) { }
};

vector<Variable> var_table;

double get_value(string s)
{
    for (const Variable& v: var_table) {
        if (v.name == s) return v.value;
    }
    throw runtime_error("get: undefined name " + s);
}

void set_value(string s, double d)
{
  for (Variable& v: var_table)
      if (v.name == s) {
          v.value = d;
          return;
      }
	throw runtime_error("set: undefined name " + s);
}

bool is_declared(string s)
{
    for (const Variable& v: var_table)
        if (v.name == s) return true;
    return false;
}

Token_stream ts;


double expression();


double eval_function(char c) {
    vector<double> args;

    Token t = ts.get();
    if (t.kind != '(') throw runtime_error("'(' expected before function");

    switch(c) {
      case sroot:
        args.push_back(expression());
        break;
      case power:
        args.push_back(expression());
        t = ts.get();
        if (t.kind != ',') throw runtime_error("Two args required for `pow`\n");
        args.push_back(expression());
        break;
    }

    t = ts.get();
    if (t.kind != ')') throw runtime_error("')' expected after function");

    switch (c) {
      case sroot:
        if (args[0] < 0) throw runtime_error("Cannot take square root of a negative value.\n");
        return sqrt(args[0]);
      case power:
        {
            if (args[1] != int(args[1])) throw runtime_error("Exponent must be an integer\n");
            return pow(args[0], int(args[1]));
        }
      default:
        throw runtime_error("Function not implemented");
    }
}

double primary()
{
	Token t = ts.get();
	switch (t.kind) {
      case '(':
        {
            double d = expression();
            t = ts.get();
            if (t.kind != ')') throw runtime_error("')' expected");
            return d;
        }
      case '-':
          return -primary();
      case number:
          return t.value;
      case name:
          return get_value(t.name);
      case sroot:
          return eval_function(t.kind);
      case power:
          return eval_function(t.kind);
      default:
          throw runtime_error("primary expected");
      }
}

double term()
{
	double left = primary();

	while (true) {
		Token t = ts.get();
		switch (t.kind) {
		case '*':
			left *= primary();
			break;
		case '/':
		{	
        double d = primary();
        if (d == 0) throw runtime_error("divide by zero");
        left /= d;
        break;
		}
		default:
			ts.putback(t);
			return left;
		}
	}
}

double expression()
{
	double left = term();
	while (true) {
		Token t = ts.get();
		switch (t.kind) {
		case '+':
			left += term();
			break;
		case '-':
			left -= term();
			break;
		default:
			ts.putback(t);
			return left;
		}
	}
}

double declaration()
{
	Token t = ts.get();
	
  if (t.kind != name) throw runtime_error("name expected in declaration");
	
  string token_name = t.name;
	if (is_declared(token_name)) throw runtime_error(token_name + " declared twice");

  Token t2 = ts.get();
  if (t2.kind != '=') throw runtime_error("= missing in declaration of " + token_name);
	
  double d = expression();
	
  var_table.push_back(Variable(token_name, d));
	
  return d;
}

double statement()
{
	Token t = ts.get();
	switch (t.kind) {
	case let:
		return declaration();
	default:
		ts.putback(t);
		return expression();
	}
}

void clean_up_mess()
{
	ts.ignore(print);
}

const string prompt = "> ";
const string result = "= ";

void calculate()
{
	while (true) try {
      cout << prompt;
      Token t = ts.get();
      while (t.kind == print) t = ts.get();
      if (t.kind == quit) return;
      ts.putback(t);
      cout << result << statement() << endl;
	}
	catch (exception& e) {
      cerr << e.what() << endl;
      clean_up_mess();
	}
}

int main()

try {
  var_table.push_back(Variable("k", 1000));
	calculate();
	return 0;
}
catch (exception& e) {
	cerr << "exception: " << e.what() << endl;
	char c;
	while (cin >> c && c != ';');
	return 1;
}
catch (...) {
	cerr << "exception\n";
	char c;
	while (cin >> c && c != ';');
	return 2;
}
