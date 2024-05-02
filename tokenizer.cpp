#include <bits/stdc++.h>
using namespace std;

bool isDelimiter(char c) {
    if (c == ' ' || c == '+' || c == '-' || c == '*' ||
        c == '/' || c == ',' || c == ';' || c == '>' ||
        c == '<' || c == '=' || c == '(' || c == ')' ||
        c == '[' || c == ']' || c == '{' || c == '}')
        return true;
    return false;
}

bool isOperator(char c) {
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '>' || c == '<' || c == '=')
        return true;
    return false;
}

bool isKeyword(string str) {
    // List of C++ keywords
    string keywords[] = {"auto", "break", "case", "char", "const", "continue", "default",
                              "do", "double", "else", "enum", "extern", "float", "for", "goto",
                              "if", "int", "long", "register", "return", "short", "signed",
                              "sizeof", "static", "struct", "switch", "typedef", "union",
                              "unsigned", "void", "volatile", "while"};

    for (string keyword : keywords) {
        if (str == keyword)
            return true;
    }
    return false;
}

bool isInteger(string str) {
    try {
        stoi(str);
        return true;
    } catch (invalid_argument&) {
        return false;
    }
}

bool isRealNumber(string str) {
    try {
        stod(str);
        return true;
    } catch (invalid_argument&) {
        return false;
    }
}

bool validIdentifier(string str) {
    if (!isalpha(str[0]) && str[0] != '_')
        return false;

    for (char c : str) {
        if (!isalnum(c) && c != '_')
            return false;
    }

    return true;
}


void parse(string str, vector<vector<string>> &v) {
    int left = 0, right = 0;
    int len = str.size();
    
    while (right < len && left <= right) {
        if (!isDelimiter(str[right]))
            right++;

        if (isDelimiter(str[right]) && left == right) {
            if (isOperator(str[right]))
                cout << "'" << str[right] << "' IS A OPERATOR" << endl;
            right++;
            left = right;
        } else if (isDelimiter(str[right]) && left != right
                || (right == len && left != right)) {
            string subStr = str.substr(left, right - left);
            if (isKeyword(subStr))
                cout << "'" << subStr << "' IS A KEYWORD" << endl;

            else if (isInteger(subStr))
                cout << "'" << subStr << "' IS AN INTEGER" << endl;

            else if (isRealNumber(subStr))
                cout << "'" << subStr << "' IS A REAL NUMBER" << endl;

            else if (validIdentifier(subStr) && !isDelimiter(str[right - 1]))
                cout << "'" << subStr << "' IS A VALID IDENTIFIER" << endl;

            else if (!validIdentifier(subStr) && !isDelimiter(str[right - 1]))
                cout << "'" << subStr << "' IS NOT A VALID IDENTIFIER" << endl;
            left = right;
        }
    }
}

int main() {
    string s;
    // string s="int a=b+c;";
    cout<<"Enter the number of lines you want to enter: ";
    vector<vector<string>> v(6);
    int n;
    cin>>n;
    for(int i=-1;i<n;i++){
        getline(cin,s);
        parse(s,v);
    }
    return 0;
}

