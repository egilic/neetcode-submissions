class Solution {
public:
    bool isOpen(char s)
    {
        return s == '(' || s == '[' || s == '{';
    }

    bool isValid(string s) {
        stack<char> openStack;
        for (int i = 0; i < s.length(); ++i)
        {
            if (isOpen(s[i])) {
                openStack.push(s[i]);
            } else {
                if (openStack.empty()) 
                {
                    cout << "Open stack empty";
                    return false;
                }
                char cTop = openStack.top();
                openStack.pop();

                if (cTop == '(') {
                    if (s[i] != ')') 
                    {
                        cout << "Top of open stack is " << cTop << " but current nonOpen char is " << s[i];
                        return false;
                    }
                } 
                else if (cTop == '{')
                {
                    if (s[i] != '}') 
                    {
                        cout << "Top of open stack is " << cTop << " but current nonOpen char is " << s[i];
                        return false;
                    }
                }
                else {
                    if (s[i] != ']') 
                    {
                        cout << "Top of open stack is " << cTop << " but current nonOpen char is " << s[i];
                        return false;
                    }
                }
            }
        }

        return openStack.size() == 0;
    }
};
