#include <iostream>
#include <cctype>

void addition(){
    int first_value, second_value;

    std::cout << "Type here your first value, please -> ";
    std::cin >> first_value;

    std::cout << "Type here your second value, please -> ";
    std::cin >> second_value;

    int addition_result = first_value + second_value;

    std::cout << "\nThe result of " << first_value << " + " << second_value << " is " << addition_result << "\n" << std::endl;
}

void subtraction(){
    int first_value, second_value;

    std::cout << "Type here your first value, please -> ";
    std::cin >> first_value;

    std::cout << "Type here your second value, please -> ";
    std::cin >> second_value;

    int subtraction_result = first_value - second_value;

    std::cout << "\nThe result of " << first_value << " - " << second_value << " is " << subtraction_result << "\n" << std::endl;
}

void multiplication(){
    int first_value, second_value;

    std::cout << "Type here your first value, please -> ";
    std::cin >> first_value;

    std::cout << "Type here your second value, please -> ";
    std::cin >> second_value;

    int multiplication_result = first_value * second_value;

    std::cout << "\nThe result of " << first_value << " * " << second_value << " is " << multiplication_result << "\n" << std::endl;
}

void division(){
    int first_value, second_value;

    std::cout << "Type here your first value, please -> ";
    std::cin >> first_value;

    std::cout << "Type here your second value, please -> ";
    std::cin >> second_value;

    int division_result = first_value / second_value;

    if(second_value != 0){
        std::cout << "\nThe result of " << first_value << " / " << second_value << " is " << division_result << "\n" << std::endl;
    }else{
        std::cout << "\nError: Division by zero is not allowed!\n" << std::endl;
    }

}

int choice_user_collect(){
    std::cout << "\n----CALCULATOR---\n";

    std::string options[4] = {
        "[1] TO ADD",
        "[2] TO SUBTRACT",
        "[3] TO MULTIPLY",
        "[4] TO DIVIDE"
        };

    int size_of_options = sizeof(options) / sizeof(options[0]);
    int choice_from_user;

    for(int i = 0; i < size_of_options; ++i){
        std::cout << options[i] << std::endl;
    }

    std::cout << "Choose your option here -> ";
    std::cin >> choice_from_user;

    return choice_from_user;
}

int main(){
    int choice;
    bool continue_program = true;

    while(continue_program){
        choice = choice_user_collect();

        switch(choice){
            case 1:
                std::cout << "\nYou did choose TO ADD!\n" << std::endl;
                addition();
                break;
            case 2:
                std::cout << "\nYou did choose TO SUBTRACTE!\n" << std::endl;
                subtraction();
                break;
            case 3:
                std::cout << "\nYou did choose TO MULTIPLY!\n" << std::endl;
                multiplication();
                break;
            case 4:
                std::cout << "\nYou did choose TO DIVIDE!\n" << std::endl;
                division();
                break;
            default:
                std::cout << "\nUse a valid number, please!\n" << std::endl;
        }

        char user_response;

        std::cout << "Do you want to continue? [Y] to continue, [N] to stop -> ";
        std::cin >> user_response;

        if(std::tolower(user_response) != 'y'){
            std::cout << "\nSee you soon!\n" << std::endl;
            continue_program = false;
        } else{
            std::cout << "\nLet's calculate one more time!\n" << std::endl;
        }
    }

    std::cout << "------------------";

    return 0;
}
