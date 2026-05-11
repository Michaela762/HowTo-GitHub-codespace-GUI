#include <iostream>
#include <vector>

std::vector<double> multiplyMatrixVector(
    const std::vector<std::vector<double>> &matrix,
    const std::vector<double> &vector)
{
    // Kontrola prázdné matice
    if (matrix.empty() || matrix[0].empty()) // nechci prázdnou matici ani matici bez sloupců
    {
        return {};
    }

    size_t cols = matrix[0].size();

    // Kontrola kompatibility rozměrů
    if (cols != vector.size())
    {
        return {};
    }

    // Kontrola, že všechny řádky mají stejnou délku
    for (const auto &row : matrix) //smyčka přes řádky
    {
        if (row.size() != cols)
        {
            return {};
        }
    }


    // Výpočet
    std::vector<double> result; //prázdný vektor, do kterého se ukládájí výsledky

    for (const auto &row : matrix) //projde každý řádek matice
    {
        double sum = 0.0; //slouží k průběžnému ukládání součtu při výpočtu skalárního součinu

        for (size_t i = 0; i < cols; i++) //smyčka přes prvky řádku
        {
            sum += row[i] * vector[i]; //součin prvku z matice k odpovidajícímu prvku z vektoru a následně všechny součiny sečtu
        }

        result.push_back(sum); //přidá výsledek do vektoru
    }

    return result;
}

int main()
{
    std::vector<std::vector<double>> matrix = {
        {8.0, 3.0, 6.0},
        {5.0, 9.0, 2.0}};
    std::vector<double> vector = {7.0, 11.0, 3.0};

    std::vector<double> result = multiplyMatrixVector(matrix, vector);

    if (result.empty())
    {
        std::cout << "Použili jste neplatné rozměry." << std::endl;
    }
    else
    {
        std::cout << "Výsledek sočinu matice a vektoru je ";
        for (double value : result)
        {
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
