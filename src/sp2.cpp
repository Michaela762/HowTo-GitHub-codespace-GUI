#include <iostream>
#include <string>
#include <vector>

class User
{
public:
    User(std::string name, int age, std::string street)
        : name_(name), age_(age), street_(street)
    {
    }

    std::string getName() const { return name_; }
    int getAge() const { return age_; }
    std::string getStreet() const { return street_; }
    void setAge(int age) { age_ = age; }

private:
    std::string name_;
    int age_;
    std::string street_;
};

class UserList
{
public:
    void add(const User &user)
    {
        users_.push_back(user);
    }

    void printAll() const
    {
        for (const User &user : users_)
        {
            std::cout << "Name: " << user.getName() << std::endl;
            std::cout << "Age: " << user.getAge() << std::endl;
            std::cout << "Street: " << user.getStreet() << std::endl;
        }
    }

    double averageAge() const
    {
        int sum = 0;
        for (const User &user : users_)
        {
            sum += user.getAge();
        }
        return static_cast<double>(sum) / users_.size();
    }

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

    std::cout << "Vekovy prumer: " << users.averageAge() << std::endl;

    int newAge;
    std::cout << "Zadejte novy vek: ";
    std::cin >> newAge;
    users.setAllAges(newAge);

    users.printAll();

    return 0;
}
