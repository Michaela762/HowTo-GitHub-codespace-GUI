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
    for (const auto &row : matrix) 
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

        for (size_t i = 0; i < cols; i++) 
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
        std::cout << "Pouzili jste neplatne rozmery." << std::endl;
    }
    else
    {
        std::cout << "Vysledek soucinu matice a vektoru je ";
        for (double value : result)
        {
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}

/* #include <iostream>
#include <string>
#include <vector>

// Jeden uživatel
class User 
{
public:
    User(std::string name, int age, std::string street) //konstruktor zajišťující, že objekt vždy vznikne s korektními daty 
        : name_(name), age_(age), street_(street)
    {
    }

    std::string getName() const { return name_; } //Gettery - umožňuje čtení dat, fuknce const zakazuje jakoukoliv změnu dat
    int getAge() const { return age_; }
    std::string getStreet() const { return street_; }

    void setAge(int age) { age_ = age; } //Setter - umožňuje změnu věku 

private: // uchovává data uživatele
    std::string name_;
    int age_;
    std::string street_;
};

// Více úživatelů
class UserList 
{
public:
    // Vložení jednoho uživatele
    void add(const User &user) //funkce přijme uživatele
    {
        users_.push_back(user); //přidá ho do seznamu
    }

    // Výpis všech uživatelů
    void printAll() const //fuknce jenom vypisuje data, nemění je
    {
        for (const User &user : users_) 
        {
            std::cout << "Name: " << user.getName() << std::endl;
            std::cout << "Age: " << user.getAge() << std::endl;
            std::cout << "Street: " << user.getStreet() << std::endl;
        }
    }

    // Výpočet průměrného věku
    double averageAge() const // fuknce vždy vrátí číslo
    {
        if (users_.empty()) //předchází dělení 0
            return 0.0;

        int sum = 0; //proměnná pro součet věků 
        for (const User &user : users_)
        {
            sum += user.getAge();
        }
        return static_cast<double>(sum) / users_.size(); //vydělí součet počtem uživatel a převede na double, aby vyšel desetinný výsledek
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
    std::vector<User> users_; // uložení uživatelů - jejich seznam 
};

int main()
{
    // Uživatelé
    UserList users; 
    users.add(User("Anežka", 19, "Ticha 33"));
    users.add(User("Robert", 34, "Javorova 2"));
    users.add(User("Iva", 27, "Slunecni 18"));

    // Výpis uživatelů 
    std::cout << "Seznam uzivatelu: " << std::endl;
    users.printAll();

    // Průměrný věk
    std::cout << "Prumerny vek:" << users.averageAge() << std::endl;

    // Změna věku
    int newAge;
    std::cout << "Zadejte novy vek: ";
    std::cin >> newAge;
    users.setAllAges(newAge);

    users.printAll();

    return 0;
} */



