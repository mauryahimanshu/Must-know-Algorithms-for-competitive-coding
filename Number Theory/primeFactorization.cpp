#include <iostream>
#include <vector>

std::vector<int> getPrimeFactors(long long int input) {
	std::vector<int> factors;
	// divides by two until number is odd
	// after this step, the algorithm will be approx. twice as fast, because we can increment the divisor by 2 each iteration
	while (input % 2 == 0) {
		input /= 2;
		factors.push_back(2);
	}
	// divides by divisor and checks if number is divisible by it
	int divisor = 3;
	while (input != 1) {
		if (input % divisor == 0) {
			input /= divisor;
			factors.push_back(divisor);
		} else {
			divisor += 2;
		}
	}
	return factors;
}

int main() {
	long long int input;
	std::cout << "Enter a positive integer larger than one : ";
	std::cin >> input;
	if (std::cin.fail()) {
		std::cerr << "std::cin failed. Please enter a valid integer." << std::endl;
		return 0;
	}
	std::cout << "Prime factors of " << input << " : " << std::endl;
	std::vector<int> primeFactors = getPrimeFactors(input);
	for (int i = 0; i < primeFactors.size(); i++) {
		std::cout << primeFactors[i] << " ";
	}
	return 0;
}