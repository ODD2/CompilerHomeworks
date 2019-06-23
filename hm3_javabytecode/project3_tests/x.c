#include<iostream>
#include<string>
using namespace std;
int main()
{
	string className = "H";
	cout << "\
class " << className << " \
{ \
  method public static void main (java.lang.String[])\
  max_stack 2\
  { \
    getstatic java.io.PrintStream java.lang.System.out\
    ldc \"Hello World!\"\
    invokevirtual void java.io.PrintStream.println(java.lang.String)\
    return\
  }\
}" << endl;
}
