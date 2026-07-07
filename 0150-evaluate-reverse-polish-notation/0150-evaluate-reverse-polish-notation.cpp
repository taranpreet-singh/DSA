class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stack;
        for (auto t : tokens) {
            if (t == "+" || t == "-" || t == "*" || t == "/") {
                int num2 = stack.top();
                stack.pop();
                int num1 = stack.top();
                stack.pop();
                if (t == "+")
                    num1 += num2;
                if (t == "-")
                    num1 -= num2;
                if (t == "*")
                    num1 *= num2;
                if (t == "/")
                    num1 /= num2;

                stack.push(num1);
            } else {
                stack.push(stoi(t));
            }
        }

        return stack.top();
    }
};