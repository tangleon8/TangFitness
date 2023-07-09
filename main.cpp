#include <iostream>
#include <string>
using namespace std;

struct User {
    string username;
    string password;
    int age;
    string gender;
    string phoneNumber;
    int reasonToJoin;
    int subscriptionMonths;
    string startDate;
};

struct Exercise {
    string name;
};

struct Diet {
    string recipe;
    string macronutrients;
};

class Gym {
private:
    User* users;
    int userCount;

public:
    Gym() {
        users = nullptr;
        userCount = 0;
    }

    void registerUser() {
        string username, password, confirmPassword;
        int age;
        string gender, phoneNumber;
        int reasonToJoin;
        int subscriptionMonths;

        cout << "Enter username: ";
        cin >> username;
        cout << "Enter password: ";
        cin >> password;
        cout << "Confirm password: ";
        cin >> confirmPassword;

        if (password != confirmPassword) {
            cout << "Passwords do not match. Registration failed." << endl;
            return;
        }

        cout << "Enter age: ";
        cin >> age;
        cout << "Enter gender: ";
        cin >> gender;
        cout << "Enter phone number: ";
        cin >> phoneNumber;

        cout << "Reasons to join the gym: " << endl;
        cout << "1. Muscle Building" << endl;
        cout << "2. Weight Loss" << endl;
        cout << "3. Cardio" << endl;
        cout << "4. Get Stronger" << endl;
        cout << "5. Become a better Athlete" << endl;
        cout << "Enter your reason number: ";
        cin >> reasonToJoin;

        cout << "Subscription options: " << endl;
        cout << "1. 1 month ($50)" << endl;
        cout << "2. 3 months ($125)" << endl;
        cout << "3. 6 months ($235)" << endl;
        cout << "4. 1 year ($500)" << endl;
        cout << "Enter your subscription choice: ";
        cin >> subscriptionMonths;

        // Store the user information
        User newUser;
        newUser.username = username;
        newUser.password = password;
        newUser.age = age;
        newUser.gender = gender;
        newUser.phoneNumber = phoneNumber;
        newUser.reasonToJoin = reasonToJoin;
        newUser.subscriptionMonths = subscriptionMonths;
        // Add the new user to the list
        addUser(newUser);

        cout << "Registration successful!" << endl;
    }

    void signIn() {
        string username, password;

        cout << "Enter username: ";
        cin >> username;
        cout << "Enter password: ";
        cin >> password;

        User* currentUser = nullptr;

        for (int i = 0; i < userCount; i++) {
            if (users[i].username == username && users[i].password == password) {
                currentUser = &users[i];
                break;
            }
        }

        if (currentUser == nullptr) {
            cout << "Invalid username or password. Sign in failed." << endl;
            return;
        }

        cout << "Welcome, " << currentUser->username << "! Stay motivated!" << endl;

        // Display gym schedule
        displaySchedule();

        // Display user's diet
        displayDiet(currentUser->reasonToJoin);

        // Display membership days
        displayMembershipDays(currentUser->startDate, currentUser->subscriptionMonths);
    }

    void addUser(User user) {
        User* newUsers = new User[userCount + 1];

        for (int i = 0; i < userCount; i++) {
            newUsers[i] = users[i];
        }

        newUsers[userCount] = user;
        delete[] users;
        users = newUsers;
        userCount++;
    }

    void displaySchedule() {
        // Display the gym's schedule for the day
        cout << "Gym Schedule for Today:" << endl;
        // Add your schedule details here
        cout << "1. Exercise 1" << endl;
        cout << "2. Exercise 2" << endl;
        cout << "3. Exercise 3" << endl;
        cout << "4. Exercise 4" << endl;
        cout << "5. Exercise 5" << endl;
        cout << "6. Exercise 6" << endl;
    }

    void displayDiet(int reasonToJoin) {
        cout << "Recommended Diet: " << endl;
        // Display diet based on the reason to join
        switch (reasonToJoin) {
            case 1:
                cout << "Muscle Building Diet" << endl;
                displayMuscleBuildingDiet();
                break;
            case 2:
                cout << "Weight Loss Diet" << endl;
                displayWeightLossDiet();
                break;
            case 3:
                cout << "Cardio Diet" << endl;
                displayCardioDiet();
                break;
            case 4:
                cout << "Strength Building Diet" << endl;
                displayStrengthBuildingDiet();
                break;
            case 5:
                cout << "Athletic Performance Diet" << endl;
                displayAthleticPerformanceDiet();
                break;
            default:
                cout << "Invalid reason to join the gym." << endl;
        }
    }

    void displayMembershipDays(string startDate, int subscriptionMonths) {
        // Display the user's membership details
        cout << "Membership Start Date: " << startDate << endl;
        // Calculate the remaining membership days based on the current date
        // and the subscription duration
        // Display the remaining days
    }

    void displayMuscleBuildingDiet() {
        // Display the recipe and macronutrients for muscle building
        Diet diet;
        diet.recipe = "Recipe for Muscle Building";
        diet.macronutrients = "Protein: 40g, Carbohydrates: 50g, Fat: 20g";
        cout << "Recipe: " << diet.recipe << endl;
        cout << "Macronutrients: " << diet.macronutrients << endl;
    }

    void displayWeightLossDiet() {
        // Display the recipe and macronutrients for weight loss
        Diet diet;
        diet.recipe = "Recipe for Weight Loss";
        diet.macronutrients = "Protein: 30g, Carbohydrates: 40g, Fat: 10g";
        cout << "Recipe: " << diet.recipe << endl;
        cout << "Macronutrients: " << diet.macronutrients << endl;
    }

    void displayCardioDiet() {
        // Display the recipe and macronutrients for cardio
        Diet diet;
        diet.recipe = "Recipe for Cardio";
        diet.macronutrients = "Protein: 20g, Carbohydrates: 30g, Fat: 5g";
        cout << "Recipe: " << diet.recipe << endl;
        cout << "Macronutrients: " << diet.macronutrients << endl;
    }

    void displayStrengthBuildingDiet() {
        // Display the recipe and macronutrients for strength building
        Diet diet;
        diet.recipe = "Recipe for Strength Building";
        diet.macronutrients = "Protein: 35g, Carbohydrates: 45g, Fat: 15g";
        cout << "Recipe: " << diet.recipe << endl;
        cout << "Macronutrients: " << diet.macronutrients << endl;
    }

    void displayAthleticPerformanceDiet() {
        // Display the recipe and macronutrients for athletic performance
        Diet diet;
        diet.recipe = "Recipe for Athletic Performance";
        diet.macronutrients = "Protein: 30g, Carbohydrates: 40g, Fat: 10g";
        cout << "Recipe: " << diet.recipe << endl;
        cout << "Macronutrients: " << diet.macronutrients << endl;
    }

    ~Gym() {
        delete[] users;
    }
};

int main() {
    Gym gym;
    int choice;

    do {
        cout << "Gym Management System" << endl;
        cout << "1. Register" << endl;
        cout << "2. Sign In" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                gym.registerUser();
                break;
            case 2:
                gym.signIn();
                break;
            case 3:
                cout << "Thank you. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 3);

    return 0;
}