#include <iostream>
#include <string>

std::string addStrings(const std::string& num1, const std::string& num2) {
    std::string result;
    int i = num1.length() - 1;
    int j = num2.length() - 1;
    int carry = 0;

    while (i >= 0 || j >= 0 || carry > 0) {
        int digit1 = (i >= 0) ? num1[i] - '0' : 0;
        int digit2 = (j >= 0) ? num2[j] - '0' : 0;

        int sum = digit1 + digit2 + carry;
        carry = sum / 10;
        int digit = sum % 10;

        result.insert(result.begin(), digit + '0');

        --i;
        --j;
    }

    return result;
}

int main() {
    std::string num1 = "11";
    std::string num2 = "123";

    std::string sum = addStrings(num1, num2);

    std::cout << "Sum: " << sum << std::endl;

    return 0;
}
