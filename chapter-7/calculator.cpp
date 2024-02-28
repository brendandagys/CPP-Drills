#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

const char number = '8';
const char quit = 'Q';
const char print = ';';
const string prompt = "> ";
const string result = "= ";
const char name = 'a';
const char let = 'L';
const string declkey = "let";
const string quitkey = "quit";

//------------------------------------------------------------------------------

class Token{
public:
    char kind;        // what kind of token
    double value;     // for numbers: a value 
    string name;
    Token(char ch)    // make a Token from a char
        :kind(ch), value(0) { }
    Token(char ch, double val)     // make a Token from a char and a double
        :kind(ch), value(val) { }
    Token(char ch, string n)
        :kind(ch), name(n) { }
};

//------------------------------------------------------------------------------

class Token_stream {
public:
    Token_stream() :full(false), buffer(0) {};   // make a Token_stream that reads from cin
    Token get();      // get a Token (get() is defined elsewhere)
    void putback(Token t);    // put a Token back
    void ignore(char c);
private:
    bool full;        // is there a Token in the buffer?
    Token buffer;     // here is where we keep a Token put back using putback()
};

//------------------------------------------------------------------------------

// The putback() member function puts its argument back into the Token_stream's buffer:
void Token_stream::putback(Token t)
{
    if (full) throw runtime_error("putback() into a full buffer");
    buffer = t;       // copy t to buffer
    full = true;      // buffer is now full
}

void Token_stream::ignore(char c) {
    if (full && c == buffer.kind) {
        full = false;
        return;
    }

    full = false;

    char ch = 0;
    while (cin >> ch) {
        if (ch == c) return;
    }
}

//------------------------------------------------------------------------------

Token Token_stream::get()
{
    if (full) {       // do we already have a Token ready?
        full = false;
        return buffer;
    }

    char ch;
    cin >> ch;    // note that >> skips whitespace (space, newline, tab, etc.)

    switch (ch) {
      case '(': case ')': case '+': case '-': case '*': case '/': case '%': case ';': case '=':
        return Token(ch);        // let each character represent itself
    case '.':
    case '0': case '1': case '2': case '3': case '4':
    case '5': case '6': case '7': case '8': case '9':
    {
        cin.putback(ch);         // put digit back into the input stream
        double val;
        cin >> val;              // read a floating-point number
        return Token(number, val);
    }
    default:
        if (isalpha(ch)) {
            string s;
            s += ch;
            while (cin.get(ch) && (isalpha(ch) || isdigit(ch))) s += ch;
            cin.putback(ch);
            if (s == declkey) return Token(let);
            if (s == quitkey) return Token(quit);
            return Token(name, s);
        }

        throw runtime_error("Bad token");
    }
}


class Variable {
public:
    string name;
    double value;
    Variable(string n, double v) :name(n), value(v) {}
};

//------------------------------------------------------------------------------

Token_stream ts;        // provides get() and putback() 
vector<Variable> var_table;

double get_value(string s) {
    for (int i=0; i < var_table.size(); ++i)
        if (var_table[i].name == s) return var_table[i].value;
    throw runtime_error("get: undefined variable: " + s);
}

void set_value(string s, double d) {
    for (int i = 0; i < var_table.size(); ++i) {
        if (var_table[i].name == s) {
            var_table[i].value = d;
            return;
        }
    }

    throw runtime_error("set: undefined variable: " + s);
}

//------------------------------------------------------------------------------

double expression();    // declaration so that primary() can call expression()

//------------------------------------------------------------------------------

bool is_declared(string var) {
    for (int i = 0; i < var_table.size(); ++i) {
      if (var_table[i].name == var) return true;
    }
    return false;
}

double define_name(string var, double val) {
  if (is_declared(var)) throw runtime_error(var + " declared twice");
  var_table.push_back(Variable(var, val));
  return val;
}

double declaration() {
    Token t = ts.get();
    if (t.kind != name) throw runtime_error("name expected in declaration");
    string var_name = t.name;

    Token t2 = ts.get();
    if (t2.kind != '=') throw runtime_error("= missing in declaration of " + var_name);

    double d = expression();
    define_name(var_name, d);
    return d;
}

double statement() {
    Token t = ts.get();
    switch (t.kind) {
        case let:
            return declaration();
        default:
            ts.putback(t);
            return expression();
    }
}

// deal with numbers and parentheses
double primary()
{
    Token t = ts.get();
    switch (t.kind) {
    case '(':    // handle '(' expression ')'
    {
        double d = expression();
        t = ts.get();
        if (t.kind != ')') throw runtime_error("')' expected)");
        
        return d;
    }
    case '-':
        return -primary();
    case number:
        return t.value;
    case name:
        return get_value(t.name);
    case '+':
        return primary();
    default:
        throw runtime_error("primary expected");
    }
}

//------------------------------------------------------------------------------

// deal with *, /, and %
double term()
{
    double left = primary();
    Token t = ts.get();        // get the next token from token stream

    while (true) {
        switch (t.kind) {
        case '*':
            left *= term();
            t = ts.get();
            break;
        case '/':
        {
            double d = term();
            if (d == 0) throw runtime_error("divide by zero");
            left /= d;
            t = ts.get();
            break;
        }
        case '%':
        {
            double d = term();
            int i1 = int(left);
            if (i1 != left) throw runtime_error("left-hand operand of % not int");
            int i2 = int(d);
            if (i2 != d) throw runtime_error("right-hand operand of % not int");
            if (12 == 0) throw runtime_error("%: divide by zero");
            left = i1 % i2;
            t = ts.get();
            break;
        }
        default:
            ts.putback(t);     // put t back into the token stream
            return left;
        }
    }
}

//------------------------------------------------------------------------------

// deal with + and -
double expression()
{
    double left = term();      // read and evaluate a Term
    Token t = ts.get();        // get the next token from token stream

    while (true) {
        switch (t.kind) {
        case '+':
            left += term();    // evaluate Term and add
            t = ts.get();
            break;
        case '-':
            left -= term();    // evaluate Term and subtract
            t = ts.get();
            break;
        default:
            ts.putback(t);     // put t back into the token stream
            return left;       // finally: no more + or -: return the answer
        }
    }
}

//------------------------------------------------------------------------------
void clean_up_mess() {
    ts.ignore(print);
}

void calculate() {
    while (cin) {
        try {
            cout << prompt;
            Token t = ts.get();
            while (t.kind == print) t = ts.get(); // first discard all "prints"
            if (t.kind == quit) return; // quit
            ts.putback(t);
            cout << result << statement() << '\n';
        }
        catch (exception& e) {
          cerr << e.what() << '\n';
          clean_up_mess();
        }
    }
}

int main()
try
{
    cout << "\nWelome to our simple calculator.\n"
         << "Please enter expressions using floating-point numbers.\n"
         << "The operations +, -, *, /, %, and () are available.\n"
         << "Finish with an = to evaluation. Press x to exit.\n\n";

    define_name("pi", 3.14159);
    define_name("e", 2.71828);

    calculate();
    return 0;
}
catch (exception& e) {
    cerr << e.what() << '\n';
    cout << "Please enter the character ~ to close the window.\n";
    char ch;
    while (cin >> ch) {
      if (ch == '~') return 1;
    }
    return 1;
}
catch (...) {
    cerr << "Oops: unknown exception!\n";
    return 2;
}

//------------------------------------------------------------------------------
