/*
 * got_double.cpp
 *
 * Author:  Mark A. Sheldon, Tufts University, Fall 2016
 *
 * A function that will tell you whether a string can be interpreted
 * as a double-precision floating point number, and, if so, give the
 * value.  
 *
 * There is a simple main program to illustrate the use of the
 * got_double() function.
 *
 * To use the function, you must include cstdio as shown.
 * The function illustrates an interesting technique.  The function
 * needs to return two values, but in C/C++ a function can only return
 * one value.  What to do?  There are two choices:
 *
 *      a) Return a struct with two things in it.  We're not doing
 *         that here.
 *      b) Return one item via the normal return value, and get the
 *         other item to the caller by using call-by-reference (CBR).
 *         CBR can be done in two ways in C++, but, because we're
 *         practicing with pointers, I'm doing it with pointers here.
 *         Besides, when you program in C, this is what you'll have to
 *         do. 
 *
 * It is VERY important that you be able to draw an accurate stack
 * diagram that illustrates how this function works.  You don't have
 * to understand sscanf() beyond what is explained below.  If you have
 * any questions, please come talk to one of us.
 *
 */
#include <iostream>
#include <cstdio>

using namespace std;

/*
 * Return true if the string s can be interpreted as a double
 * precision floating point number, placing the associated double into
 * the location pointed to by resultp.
 *
 * Return false if s cannot be interpreted as a double leaving the
 * location pointed to by resultp unmodified (if I read the scanf()
 * spec correctly).
 *
 * Implementer note to students:
 *
 *     sscanf() reads characters from the first C string it's given
 *     trying to match them against the "format specifiers" in the
 *     second C string.  In the case below, "%lf" means "long float,"
 *     which is the format for doubles.  It returns the number of
 *     successful matches, and stores the converted values in the
 *     locations pointed to by the remaining arguments.  In this case,
 *     if the C string from s contains a double, it's placed in the
 *     location pointed to by resultp and it returns 1.
 */
bool got_double(string s, double *resultp)
{
        return sscanf(s.c_str(), "%lf", resultp) == 1;
}

/*
 * This main function illustrates a way to use got_double() above.
 * If you compile this file and run the result, you can use the
 * program like this:
 *
 *      bash-3.2$ ./got_integer 1.58 -2 lskdfj -1.6789 0 b
 *      1.58 is a double with value 1.58
 *      -2 is a double with value -2
 *      lskdfj is not a double :-(
 *      -1.6789 is a double with value -1.6789
 *      0 is a double with value 0
 *      b is not a double :-(
 *      bash-3.2$ 
 */

int main(int argc, char *argv[])
{
        double value;

        for (int i = 1; i < argc; ++i) {
                cout << argv[i] << " ";

                if (got_double(argv[i], &value))
                        cout << "is a double with value " << value;
                else
                        cout << "is not a double :-(";
                cout << endl;
        }
        return 0;
}
