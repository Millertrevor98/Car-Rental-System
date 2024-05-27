#include <iostream>
#include <vector>
#include <string>

class Car {
public:
    Car(std::string make, std::string model, int year)
        : make(make), model(model), year(year), isRented(false) {}

    std::string getMake() const { return make; }
    std::string getModel() const { return model; }
    int getYear() const { return year; }
    bool getIsRented() const { return isRented; }

    void rentCar() { isRented = true; }
    void returnCar() { isRented = false; }

    void displayCar() const {
        std::cout << year << " " << make << " " << model
                  << (isRented ? " (Rented)" : " (Available)") << std::endl;
    }

private:
    std::string make;
    std::string model;
    int year;
    bool isRented;
};

class CarRentalSystem {
public:
    void addCar(const Car& car) {
        cars.push_back(car);
    }

    void deleteCar(const std::string& make, const std::string& model) {
        for (auto it = cars.begin(); it != cars.end(); ++it) {
            if (it->getMake() == make && it->getModel() == model && !it->getIsRented()) {
                cars.erase(it);
                std::cout << "Car deleted successfully!" << std::endl;
                return;
            }
        }
        std::cout << "Car not found or is currently rented!" << std::endl;
    }

    void viewAvailableCars() const {
        for (const auto& car : cars) {
            if (!car.getIsRented()) {
                car.displayCar();
            }
        }
    }

    void rentCar(const std::string& make, const std::string& model) {
        for (auto& car : cars) {
            if (car.getMake() == make && car.getModel() == model && !car.getIsRented()) {
                car.rentCar();
                std::cout << "Car rented successfully!" << std::endl;
                return;
            }
        }
        std::cout << "Car not available for rent!" << std::endl;
    }

private:
    std::vector<Car> cars;
};

int main() {
    CarRentalSystem rentalSystem;

    rentalSystem.addCar(Car("Toyota", "Camry", 2020));
    rentalSystem.addCar(Car("Honda", "Accord", 2019));
    rentalSystem.addCar(Car("Ford", "Mustang", 2021));

    int choice;
    while (true) {
        std::cout << "\nCar Rental System Menu\n";
        std::cout << "1. View available cars\n";
        std::cout << "2. Rent a car\n";
        std::cout << "3. Add a new car\n";
        std::cout << "4. Delete an existing car\n";
        std::cout << "5. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        if (choice == 1) {
            rentalSystem.viewAvailableCars();
        } else if (choice == 2) {
            std::string make, model;
            std::cout << "Enter car make: ";
            std::cin >> make;
            std::cout << "Enter car model: ";
            std::cin >> model;
            rentalSystem.rentCar(make, model);
        } else if (choice == 3) {
            std::string make, model;
            int year;
            std::cout << "Enter car make: ";
            std::cin >> make;
            std::cout << "Enter car model: ";
            std::cin >> model;
            std::cout << "Enter car year: ";
            std::cin >> year;
            rentalSystem.addCar(Car(make, model, year));
            std::cout << "Car added successfully!" << std::endl;
        } else if (choice == 4) {
            std::string make, model;
            std::cout << "Enter car make: ";
            std::cin >> make;
            std::cout << "Enter car model: ";
            std::cin >> model;
            rentalSystem.deleteCar(make, model);
        } else if (choice == 5) {
            break;
        } else {
            std::cout << "Invalid choice! Please try again.\n";
        }
    }

    return 0;
}
