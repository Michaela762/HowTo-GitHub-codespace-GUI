#include <iostream>

void passByValue(int a) // a is a copy
{
    std::cout << "Value before: " << a << std::endl;
    a = 1; // modifies only the local copy
}

void passByPointer(int *a) // a is an address
{
    std::cout << "Pointer before: " << *a << std::endl;
    *a = 1; // modifies the original variable
}

void passByReference(int &a) // a is an alias
{
    std::cout << "Reference before: " << a << std::endl;
    a = 1; // modifies the original variable
}

int main()
{
    int a = 0;

    passByValue(a);
    std::cout << "Value after: " << a << std::endl;

    a = 0;
    passByPointer(&a);
    std::cout << "Pointer after: " << a << std::endl;

    a = 0;
    passByReference(a);
    std::cout << "Reference after: " << a << std::endl;

    return 0;
}
