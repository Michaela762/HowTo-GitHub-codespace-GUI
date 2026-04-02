#include <iostream>
#include <cmath>

int main()
{
    std::cout << "Vitejte v kalkulacce" << std::endl;
    std::string continueAnswer = "ano";

    while (continueAnswer == "ano")
    {
        std::cout << "Zadejte prvni cislo:" << std::endl;
        float a;
        std::cin >> a;

        std::cout << "Zadejte druhe cislo:" << std::endl;
        float b;
        std::cin >> b;

        std::cout << "Zvolte si operaci:" << std::endl;
        std::cout << "1 - scitani" << std::endl;
        std::cout << "2 - odcitani" << std::endl;
        std::cout << "3 - nasobeni" << std::endl;
        std::cout << "4 - deleni" << std::endl;

        int choice;
        std::cin >> choice;

        float result = 0.0f;
        bool choiceValid = true;

        switch (choice)
        {
        case 1:
            result = a + b;
            break;

        case 2:
            result = a - b;
            break;

        case 3:
            result = a * b;
            break;

        case 4:
            result = a / b;
            break;

        default:
            // neplatna volba
            choiceValid = false;
            break;
        }

        if (choiceValid)
        {
            std::cout << "Vysledek: " << result << std::endl;
        }
        else
        {
            std::cout << "Neplatna volba" << std::endl;
        }

        std::cout << "Prejete si zadat dalsi priklad? [ano/ne]" << std::endl;
        std::cin >> continueAnswer;
    }

    std::cout << "Dekuji za pouziti kalkulacky." << std::endl;

    return 0;
}
