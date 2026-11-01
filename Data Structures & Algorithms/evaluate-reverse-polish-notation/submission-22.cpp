class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        if (tokens.size() == 1) { return stoi(tokens[0]); }

        int i = 0;
        stack<int> args;
        while (i < tokens.size()) {
            if (tokens[i] == "+") {
                int arg2 = args.top(); args.pop();
                int arg1 = args.top(); args.pop();
                args.push(arg1+arg2);
            } else if (tokens[i] == "-") {
                int arg2 = args.top(); args.pop();
                int arg1 = args.top(); args.pop();
                args.push(arg1-arg2);
            } else if (tokens[i] == "*") {
                int arg2 = args.top(); args.pop();
                int arg1 = args.top(); args.pop();
                args.push(arg1*arg2);
            } else if (tokens[i] == "/") {
                int arg2 = args.top(); args.pop();
                int arg1 = args.top(); args.pop();
                args.push(arg1/arg2);
            } else {
                args.push(stoi(tokens[i]));
            }
            i++;
        }
        return args.top();
    }
};
