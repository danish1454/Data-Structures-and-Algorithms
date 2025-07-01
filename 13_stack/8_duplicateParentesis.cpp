#include<iostream>
#include<stack>
#include<string>
using namespace std;

bool isDuplicate(string str) {
    stack<char> st;

    for (int i = 0; i < str.size(); i++) {
        char ch = str[i];
        if (ch != ')') {
            st.push(ch);
        } else {
            // Check for the content inside the parenthesis
            if (!st.empty() && st.top() == '(') {
                return true; // Found duplicate parenthesis
            } else {
                // Pop till matching '(' is found
                while (!st.empty() && st.top() != '(') {
                    st.pop();
                }
                if (!st.empty()) {
                    st.pop(); // Pop the matching '('
                }
            }
        }
    }
    return false;
}

int main() {
    string str1 = "(a+(b+c))";
    string str2 = "(((a+((b-c))))";
    cout << isDuplicate(str1) << endl; // Output should be 0 (false)
    cout << isDuplicate(str2) << endl; // Output should be 1 (true)
    return 0;
}
