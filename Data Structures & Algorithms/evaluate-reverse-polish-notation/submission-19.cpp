class Solution {
public:
    int computeResult(string& operation, int opOne, int opTwo)
    {
        if (operation == "*")
        {
            return opOne * opTwo;
        }
        else if (operation == "/")
        {
            return opTwo / opOne;
        }
        else if (operation == "-")
        {
            return opTwo - opOne;
        }   
        else if (operation == "+")
        {
            return opOne + opTwo;
        }
        else
        {
            return 0;
        }
    }

    int evalRPN(vector<string>& tokens) {
        stack<int> operandStack;
        stack<string> operatorStack;
        for (auto& s : tokens)
        {
            if(s == "+" || s == "-" || s == "/" || s == "*")
            {
                operatorStack.push(s);
            }
            else
            {
                operandStack.push(stoi(s));
            }
            if (operatorStack.size() > 0 && operandStack.size() > 1)
            {
                auto operation = operatorStack.top();
                operatorStack.pop();

                auto operandOne = operandStack.top();
                operandStack.pop();
                auto operandTwo = operandStack.top();
                operandStack.pop();

                int res = computeResult(operation, operandOne, operandTwo);
                operandStack.push(res);
            }
        }

        if (!operandStack.empty())
        {
            return operandStack.top();
        }
        return 0; // error
    }
};
