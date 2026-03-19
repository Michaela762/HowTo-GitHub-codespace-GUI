#include <iostream>
#include <string>

int main()
{
    std::cout << "Vitejte v kalkulacce" << std::endl;
    std::cout << "Zadejte prvni cislo: ";
    float a;
    std::cin >> a;
    std::cout << "Zadejte druhe cislo: ";
    float b;
    std::cin >> b;

    float sum = a + b;
    float difference = a - b;
    float product = a * b;
    float quotient = a / b;

    std::cout << "Soucet: " << sum << std::endl;
    std::cout << "Rozdil: " << difference << std::endl;
    std::cout << "Soucin: " << product << std::endl;
    std::cout << "Podil: " << quotient << std::endl;
    std::cout << "Dekuji za pouziti kalkulacky, aplikaci ukoncite libovolnou klavesou." << std::endl;
    /*  std::cin.get();
     std::cin.get(); */

    return 0;
}
