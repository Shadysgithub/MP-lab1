// Asqarjon Anvarov 220050 
// Tuesday 09:00

// Question 1
#include <iostream>
using namespace std;

int main(int argCount, char *argValues[])
{
  cout << "Total arguments: " << argCount << endl;
  cout << "List of arguments:" << endl;

  for (int index = 0; index < argCount; ++index)
  {
    cout << "Arg " << index << ": " << argValues[index] << endl;
  }

  return 0;
}

// Question 2
// In C++, program execution always begins at main().

// Question 3
// In Java main is public static and has no return type. In C++ it returns an int status code.

// Question 4
// In C++, 0 = success, nonzero = failure. Java uses System.exit(value) for similar purpose.


// VARIABLES
// Question 1
#include <iostream>
using namespace std;

int main()
{
  int firstNum = 10, secondNum = 20;

  cout << "Before swap: firstNum = " << firstNum << ", secondNum = " << secondNum << endl;

  firstNum = firstNum + secondNum;
  secondNum = firstNum - secondNum;
  firstNum = firstNum - secondNum;

  cout << "After swap: firstNum = " << firstNum << ", secondNum = " << secondNum << endl;
  return 0;
}

// Question 2
// Primitive types keep raw values, reference ones hold memory locations.

// Question 3
// Local scope → exists inside block/function. Static/global → persists for whole program.

// Question 4
// C++ checks types during compilation.


// CONTROL FLOW
// Question 1
#include <iostream>
using namespace std;

int main()
{
  int prev = 0, curr = 1, nextNum;
  cout << "First 10 Fibonacci numbers: ";

  for (int i = 1; i <= 10; ++i)
  {
    if (i == 1)
    {
      cout << prev << " ";
      continue;
    }
    if (i == 2)
    {
      cout << curr << " ";
      continue;
    }
    nextNum = prev + curr;
    prev = curr;
    curr = nextNum;
    cout << nextNum << " ";
  }
  cout << endl;
  return 0;
}

// Question 2
// while: check first, may not run. do-while: check last, runs at least once.

// Question 3
// switch allows multiple paths using case/default/break.

// Question 4
// Short-circuit stops once outcome is clear. Example: (x!=0 && 10/x>1) avoids zero division.


// FUNCTION METHODS
// Question 1
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool checkPalindrome(const string &text)
{
  return equal(text.begin(), text.begin() + text.size() / 2, text.rbegin());
}

int main()
{
  cout << "madam palindrome? " << (checkPalindrome("madam") ? "true" : "false") << endl;
  cout << "hello palindrome? " << (checkPalindrome("hello") ? "true" : "false") << endl;
  return 0;
}

// Question 2
// C++: pass by value/ref/pointer. Java: always pass by value.

// Question 3
// Overloading requires different parameters. Changing only return type is not enough.

// Question 4
// Recursion: function calls itself. Needs a base case to stop.


// COMMENTS
// Question 1
#include <iostream>
using namespace std;

/**
 * Documentation style comment
 */
int main()
{
  // single-line comment
  int number = 5; // inline comment

  /*
     multi-line
     explanation
  */
  cout << "Comment example" << endl;
  return 0;
}

// Question 2
// Comments help understand code and teamwork.

// Question 3
// Tools like Doxygen/Javadoc turn them into docs.

// Question 4
// Clear code is good, but comments explain tricky logic.


// CLASSES
// Question 1
#include <iostream>
using namespace std;

class BankAccount
{
private:
  double funds;

public:
  BankAccount(double startBalance)
  {
    funds = (startBalance >= 0) ? startBalance : 0;
  }
  void deposit(double sum)
  {
    if (sum > 0)
      funds += sum;
  }
  double getBalance()
  {
    return funds;
  }
};

int main()
{
  BankAccount wallet(100.5);
  cout << "Initial: " << wallet.getBalance() << endl;
  wallet.deposit(50.25);
  cout << "After deposit: " << wallet.getBalance() << endl;
  return 0;
}

// Question 2
// Class = blueprint, object = actual instance.

// Question 3
// Public = everywhere, Private = inside class, Protected = class + children.

// Question 4
// Constructor sets up object. Default one has no arguments.


// ENUMS
// Question 1
#include <iostream>
#include <string>
using namespace std;

enum class Season
{
  SPRING,
  SUMMER,
  AUTUMN,
  WINTER
};

string suggestActivity(Season s)
{
  switch (s)
  {
  case Season::SPRING:
    return "Go hiking";
  case Season::SUMMER:
    return "Swim at the beach";
  case Season::AUTUMN:
    return "Collect leaves";
  case Season::WINTER:
    return "Make a snowman";
  default:
    return "Just relax";
  }
}

int main()
{
  Season current = Season::AUTUMN;
  cout << suggestActivity(current) << endl;
  return 0;
}

// Question 2
// Enums safer than plain numbers or strings.

// Question 3
// They improve clarity and prevent invalid values.

// Question 4
// C++11 enums are strongly typed. Java enums can also hold methods/fields.


// INHERITANCE
// Question 1
#include <iostream>
using namespace std;

class Vehicle
{
public:
  void startEngine() { cout << "Engine running." << endl; }
};

class Car : public Vehicle
{
public:
  void drive() { cout << "Car drives forward." << endl; }
};

int main()
{
  Car autoCar;
  autoCar.startEngine();
  autoCar.drive();
  return 0;
}

// Question 2
// is-a → inheritance, has-a → composition.

// Question 3
// Overriding = redefine base method. C++ uses virtual/override, Java uses @Override.

// Question 4
// Diamond problem = multiple inheritance conflict. C++ handles with virtual inheritance; Java uses interfaces.


// MIXINS / INTERFACES
// Question 1
#include <iostream>
#include <string>
using namespace std;

class IStringable
{
public:
  virtual string toString() const = 0;
  virtual ~IStringable() = default;
};

class Printer
{
public:
  void print(const IStringable &obj)
  {
    cout << obj.toString() << endl;
  }
};

class Book : public IStringable
{
private:
  string title, author;

public:
  Book(string t, string a) : title(t), author(a) {}
  string toString() const override
  {
    return "'" + title + "' by " + author;
  }
};

int main()
{
  Book hobbit("The Hobbit", "J.R.R. Tolkien");
  Printer printer;
  printer.print(hobbit);
  return 0;
}

// Question 2
// Interfaces/mixins add shared behavior without strict hierarchy.

// Question 3
// Java supports default methods, working like mixins.

// Question 4
// Inheritance is simple but rigid; composition is flexible; mixins reusable but tricky.


// POLYMORPHISM
// Question 1
#include <iostream>
#include <vector>
#include <memory>
using namespace std;

class Shape
{
public:
  virtual double getArea() const = 0;
  virtual ~Shape() = default;
};

class Rectangle : public Shape
{
  double width, height;

public:
  Rectangle(double w, double h) : width(w), height(h) {}
  double getArea() const override { return width * height; }
};

class Circle : public Shape
{
  double radius;

public:
  Circle(double r) : radius(r) {}
  double getArea() const override { return 3.14159 * radius * radius; }
};

int main()
{
  vector<unique_ptr<Shape>> figures;
  figures.push_back(make_unique<Rectangle>(10, 5));
  figures.push_back(make_unique<Circle>(3));

  for (const auto &f : figures)
  {
    cout << "Area: " << f->getArea() << endl;
  }
  return 0;
}

// Question 2
// Compile-time = overloading, Runtime = overriding.

// Question 3
// Abstract class may include methods. Interface = pure virtual only.

// Question 4
// Polymorphism defines contracts for different implementations.


// ASYNC OPERATIONS
// Question 1
#include <iostream>
#include <future>
using namespace std;

long long calcSum()
{
  long long result = 0;
  for (long long i = 1; i <= 1000000; ++i)
  {
    result += i;
  }
  return result;
}

int main()
{
  cout << "Main thread: start calculation..." << endl;
  future<long long> output = async(launch::async, calcSum);

  cout << "Main thread: waiting..." << endl;
  cout << "Result: " << output.get() << endl;
  return 0;
}

// Question 2
// Async helps avoid blocking on long I/O tasks.

// Question 3
// Parallel = simultaneous, Concurrent = interleaved execution.

// Question 4
// Futures/promises carry results of async tasks.


// EXCEPTIONS
// Question 1
#include <iostream>
#include <stdexcept>
using namespace std;

void checkAge(int years)
{
  if (years < 0)
    throw invalid_argument("Age must be non-negative.");
  cout << "Age: " << years << endl;
}

int main()
{
  try
  {
    checkAge(-5);
  }
  catch (const invalid_argument &err)
  {
    cerr << "Error: " << err.what() << endl;
  }
  cout << "Program continues..." << endl;
  return 0;
}

// Question 2
// try = risky code, catch = handler, finally = always runs. C++ usually relies on RAII instead of finally.

// Question 3
// Java: checked/unchecked exceptions. C++: all treated as unchecked.

// Question 4
// Exceptions separate error handling from logic, but too many reduce clarity.
