/*

Question 1
Technical writing is an important skill to have in the analytics and computer programming industry for many reasons.

Before we introduce our coding assessment, please explain why YOU think technical writing is important, 
specifically as it pertains to your role as a software developer, analyst, etc.?

//  My answer:

    I believe technical writing is very important as it is able to communicate, copy, and transfer ideas and work onto 
    paper. An example of technical writing is a manual or report. It is written for a specific audience to interpret and 
    understand the function of (in this case of the position i am being considered for), the software being developed. 
    This helps with any and all technical information accessible and understandable to a specific audience, ensuring effective 
    communication and usability of products, systems, and processes the software has. 
*/


/*
Question 2
***PART 1: CODING ASSESSMENT***

PLEASE COMPLETE IN C++

Create a program that accepts an integer 'n' as an argument and executes the fizz buzz task as follows: 
    Starting at 1 and ending 'n' print the following on each line 
	    If the number divisible by only 3, the word Fizz should be printed.
		If the number divisible by only 5, the word Buzz should be printed.
		If the number is divisible by both 3 and 5, FizzBuzz should be printed.
		otherwise print the number. 

Limitations:

1) You must use at least 3 different classes.
2) You must use inheritance and virtual functions.
3) Each class can only print one case (i.e. one class prints Fizz, one prints Buzz, and one prints the number)
4) The base class must have a function that accepts an integer and that function should execute the task.
5) In the main function of the program you must instantiate a base class object with an inherited class.

The code below is an idea to use as a framework:

void main(int argc, char argv)
{
int n = // put argument 2 here;
BaseClass* b = new InheritedClass;
b.printSolution(n)
}
*/

// Code 

#include <iostream>
#include <string>

using namespace std;

class FizzBuzzHandler 
{
public:
    virtual void print(int n) = 0;  // set n to zero temporarily
    virtual ~FizzBuzzHandler() {} // destructor for deleting data for the base class
};

/*
    The following 3 functions are classes that will create the necessary output such as 'Fizz' , 'Buzz', and 'FizzBuzz'
    The regular number not divisible by 3 and/or 5 output is put in the final 'FizzBuzz' class
*/

class FizzClass : public FizzBuzzHandler 
{
public:
    void print(int n) 
    {
        cout << "Fizz" << endl;
    }
};

class BuzzClass : public FizzBuzzHandler 
{
public:
    void print(int n) 
    {
        cout << "Buzz" << endl;
    }
};

class CombinedPrinter : public FizzBuzzHandler
{
public:
    void print(int n) 
    {
        if (n % 3 == 0 && n % 5 == 0)   
            cout << "FizzBuzz" << endl;
        else if (n % 3 != 0 && n % 5 != 0)  // number not divisible by 3 or 5
            cout << n << endl;
        else                            
            cout << "Error" << endl;    // error statement
    }
};

/*
    Processor class to process and create return statements for following case-switch statements
*/

class Processor : public FizzBuzzHandler 
{
private:
    int Case(int i) 
    {
        if (i % 3 == 0 && i % 5 == 0) return 0; // Set returns with values corresponding with case-switch in the next function
        if (i % 3 == 0) return 1;
        if (i % 5 == 0) return 2;
        return 3;
    }

public:
    void print(int n) 
    {
        FizzClass fizzobj;   //Takes classes and sets objects 
        BuzzClass buzzobj;
        CombinedPrinter cpobj;

        for (int i = 1; i <= n; ++i) 
        {
            switch (Case(i)) 
            {
                case 0:
                    cpobj.print(i); // FizzBuzz outout when its both
                    break;
                case 1:
                    fizzobj.print(i);   // Fizz output for when /3
                    break;
                case 2:
                    buzzobj.print(i);   // Buzz output for when /5
                    break;
                case 3:
                    cpobj.print(i); // Neither prior 3-cases number output
                    break;
            }
        }
    }
};

int main() 
{
    
    int n;
    cout << "Please enter a number: " << endl;  // Prompts user for number to be ran
    cin >> n;
    
    FizzBuzzHandler* fbh = new Processor();     // Allows polymorphism by using the FizzBuzz logic handler
    fbh->print(n);  // runs the fizzbuzz printing function 
    delete fbh; // clears memory
    return 0;   //exits
}


/*
I implemented the classic Fizz-Buzz question, but with an OOP (object-oriented programming) twist. 
The OOP twist is to create an overall base class and a virtual print function, and then using three classes. 
For these classes, I made three specific outputs where one outputs "Fizz" when divisible by 3, "Buzz" when divisible by 5, and "FizzBuzz" when divisible by both. 
I then used the idea of a switch-case method to output to help route the logic of the corresponding classes to ensure not to repeat or create redundant code.
In my main function, I prompt the user to input a number, and use polymorphism to help print the correct output. 
At the end, I delete the memory (dynamic memory). 
The code is modular, clear, and easy to follow for future changes and/or reviewing.
*/

