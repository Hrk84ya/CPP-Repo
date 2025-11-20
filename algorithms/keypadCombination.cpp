#include <iostream>
#include <string>
using namespace std;

// Array to store characters corresponding to each digit on a keypad
string keypadArr[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

// Function to generate all possible combinations of letters from keypad digits
void keypad(string str, string ans)
{
    // Base case: if str is empty, print the current combination stored in ans
    if (str.length() == 0)
    {
        cout << ans << endl;
        return;
    }

    // Extract the first character of str
    char ch = str[0];
    // Get the corresponding string of characters from keypadArr based on ch
    string code = keypadArr[ch - '0'];
    // Get the rest of the string (remaining string after excluding the first character)
    string ros = str.substr(1);

    // Iterate through all characters in code
    for (int i = 0; i < code.length(); i++)
    {
        // Recursively call keypad with ros (rest of the string) and ans concatenated with current character from code
        keypad(ros, ans + code[i]);
    }
}

// Main function
int main()
{
    // Call keypad function with initial string "23" and empty initial answer string
    keypad("23", "");
    return 0;
}
