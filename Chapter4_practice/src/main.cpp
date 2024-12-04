#include "array.hpp"

int main()
{

Array<char> myCharArray;
myCharArray.Display();

Array<int> myIntArray;
myIntArray.Display();

Array<double> myDoubleArray;
myDoubleArray.Display();

myCharArray.SetValue('p',2);
myCharArray.SetValue('o',3);
myCharArray.SetValue('p',4);
myCharArray.SetValue('o',5);
myCharArray.SetValue('m',7);
myCharArray.Display();

return 0;
}
