/* #include <iostream>
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
} */

#include <iostream>
#include <string>
#include <vector>

class User // reprezentuje jednoho uživatele
{
public:
    User(std::string name, int age, std::string street) //konstruktor zajišťující, že objekt vždy vznikne s korektními daty - zabráníme vzniku neplatných nebo neúplných objektů
        : name_(name), age_(age), street_(street)
    {
    }

    std::string getName() const { return name_; } //Member functions pracují s daty uživatele, ke kterému náleží
    int getAge() const { return age_; }
    std::string getStreet() const { return street_; }

    void setAge(int age) { age_ = age; }

private: //Member variables - uchovává data uživatele
    std::string name_;
    int age_;
    std::string street_;
};

class UserList // více úživatelů
{
public:
    // Vložení jednoho uživatele
    void add(const User &user)
    {
        users_.push_back(user);
    }

    // Výpis všech uživatelů
    void printAll() const
    {
        for (const User &user : users_)
        {
            std::cout << "Name: " << user.getName() << std::endl;
            std::cout << "Age: " << user.getAge() << std::endl;
            std::cout << "Street: " << user.getStreet() << std::endl;
        }
    }

    // Výpočet průměrného věku
    double averageAge() const
    {
        if (users_.empty()) //předchází dělení 0
            return 0.0;

        int sum = 0;
        for (const User &user : users_)
        {
            sum += user.getAge();
        }
        return static_cast<double>(sum) / users_.size();
    }

    // nastavení věku všem uživatelům
    void setAllAges(int age)
    {
        for (User &user : users_)
        {
            user.setAge(age);
        }
    }

private:
    std::vector<User> users_;
};

int main()
{
    UserList users;
    users.add(User("Alice", 21, "Kvetna 12"));
    users.add(User("Bob", 30, "Parkova 7"));
    users.add(User("Ema", 25, "Lesni 3"));

    std::cout << "Vekovy prumer je " << users.averageAge() << std::endl;

    int newAge;
    std::cout << "Zadejte novy vek: ";
    std::cin >> newAge;
    users.setAllAges(newAge);

    users.printAll();

    return 0;
}
