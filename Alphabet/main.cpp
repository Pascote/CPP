#include <iostream>
#include <vector>
#include <string>
#include <cctype>

void alphabet_with_char(){

	char alphabet[27];

	for(int i = 0; i < 26; ++i){

		alphabet[i] = 'a'+i;
	}

	alphabet[26] = '\0';

	std::cout << alphabet << std::endl;
}

void explanation_of_alphabet_with_char(){

	std::cout << "The logic starts with char alphabet[27], because the last position will be the null character" << std::endl;
}

void alphabet_with_vector(){

	std::vector<char> alphabet(26);

	for(int i = 0; i < 26; ++i){

		alphabet[i] = 'a'+i;
	}

	for(char letter : alphabet){

		std::cout << letter;
	}

	std::cout << std::endl;
}

void explanation_of_alphabet_with_vector(){

	std::cout << "The logic starts with std::vector<char> alphabet(26), uses a for to iterate (alphabet[i] = 'a' + i), and then iterate every letter of the alphabet" << std::endl;
}

void alphabet_with_string(){

	std::string alphabet;

	for(char ch = 'a'; ch <= 'z'; ++ch){
		alphabet += ch;
	}

	std::cout << alphabet << std::endl;
}

void explanation_of_alphabet_with_string(){

	std::cout << "The logic starts with std::string alphabet, then iterates from char ch = 'a' to ch <= 'z', and finishes with alphabet += ch" << std::endl;
}

int main(){

	int user_value;
	char evaluator;

	std::cout << "Choose how you want your alphabet example!" << std::endl;
	std::cout << "[1] to CHAR, [2] to VECTOR, [3] to STRING -> ";
	std::cin >> user_value;

	switch(user_value){
		case 1:
			std::cout << "\nYou did choose 1. Here is the alphabet with CHAR." << std::endl;
			alphabet_with_char();

			std::cout << "Do you know to see the explanation? [Y] to yes, [N] to no -> ";
			std::cin >> evaluator;

			if(tolower(evaluator) == 'y'){
				explanation_of_alphabet_with_char();
			}else{
				std::cout << "See you soon!" << std::endl;
			}
			break;

		case 2:
			std::cout << "\nYou did choose 2. Here is the alphabet with VECTOR." << std::endl;
			alphabet_with_vector();

			std::cout << "Do you know to see the explanation? [Y] to yes, [N] to no -> ";
			std::cin >> evaluator;

			if(tolower(evaluator) == 'y'){
				explanation_of_alphabet_with_vector();
			}else{
				std::cout << "See you soon!" << std::endl;
			}
			break;

		case 3:
			std::cout << "\nYou did choose 3. Here is the alphabet with STRING." << std::endl;
			alphabet_with_string();

			std::cout << "Do you know to see the explanation? [Y] to yes, [N] to no -> ";
			std::cin >> evaluator;

			if(tolower(evaluator) == 'y'){
				explanation_of_alphabet_with_string();
			}else{
				std::cout << "See you soon!" << std::endl;
			}
			break;

		default:
			std::cout << "Valid number, ok?" << std::endl;
	}

	return 0;
}
