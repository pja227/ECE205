/**
 * Perry Addey
 */
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <cctype>
#include <stack>

using namespace std;

class Node {
    public:
        string data;
        Node* left;
        Node* right;

        Node(string val) {
            data = val;
            left = nullptr;
            right = nullptr;
        }
};

int precedence(char op);
bool isOperator(char c);
double evaluate(Node* root);
string infixToPostfix(string s);
Node* constructTree(string postfix);

int main() {
    string exp1 = "(16 + 2) * 5 - 28 / 4";

    string postfix1 = infixToPostfix(exp1);
    Node* root1 = constructTree(postfix1);

    cout << "Postfix expression: " << postfix1 << endl;
    cout << "Result: " << evaluate(root1) << endl;
    cout << endl;

    string exp2 = "(8 + 1) * 3 - 8 / 4";

    string postfix2 = infixToPostfix(exp2);
    Node* root2 = constructTree(postfix2);

    cout << "Postfix expression: " << postfix2 << endl;
    cout << "Result: " << evaluate(root2) << endl;
    cout << endl;

    string exp3 = "(10 - 2) * (15 + 5) / 4";

    string postfix3 = infixToPostfix(exp3);
    Node* root3 = constructTree(postfix3);

    cout << "Postfix expression: " << postfix3 << endl;
    cout << "Result: " << evaluate(root3) << endl;
}

string infixToPostfix(string s) {
    stack<char> st;
    string result;

    for (int i = 0; i < s.length(); i++) {
        char c = s[i];

        if (c == ' ') {
            continue;
        }

        // if the scanned character is an operand, add it to the output string
        if (isdigit(c)) {
            while (i < s.length() && isdigit(s[i])) {
                result += s[i];
                i++;
            }
            result += ' ';
            i--;
        }

        // if the scanned character is an '(', push it to the stack
        else if (c == '(') {
            st.push('(');
        }

        // if the scanned character is an ')', pop and to output string from the stack
        // until an '(' is encountered 
        else if (c == ')') {
            while (!st.empty() && st.top() != '(') {
                result += st.top();
                result += ' ';
                st.pop();
            }
            st.pop();
        }
        
        // an operator is encountered
        else {
            while (!st.empty() && st.top() != '(' && precedence(c) <= precedence(st.top())) {
                result += st.top();
                result += ' ';
                st.pop();
            }
            st.push(c);
        }
    }

    // pop all the operators from the stack
    while (!st.empty()) {
        result += st.top();
        result += ' ';
        st.pop();
    }

    return result;
}

Node* constructTree(string postfix) {
    stack<Node*> st;

    Node* t;
    Node* t1;
    Node* t2;
    string token;

    // Traverse the postfix expression for every character
    for (int i = 0; i <= postfix.length(); i++) {
        if (i == postfix.length() || postfix[i] == ' ') {
            if (token.length() == 0) {
                continue;
            }

            if (token.length() == 1 && isOperator(token[0])) {
                if (st.size() < 2) {
                    return nullptr;
                }

                t = new Node(token);

                // Pop two top nodes
                t1 = st.top();
                st.pop();
                t2 = st.top();
                st.pop();

                // Make them children
                t->right = t1;
                t->left = t2;

                // Add this subexpression to stack
                st.push(t);
            } else {
                t = new Node(token);
                st.push(t);
            }

            token = "";
        } else {
            token += postfix[i];
        }
    }

    if (st.empty()) {
        return nullptr;
    }

    // Only element should be the root of expression tree
    t = st.top();
    st.pop();

    return t;
}

double evaluate(Node* root) {
    if (root == nullptr) {
        return 0;
    }

    // If leaf node, return its numeric value
    if (root->left == nullptr && root->right == nullptr) {
        return stod(root->data);
    }

    // Evaluate left and right subtrees
    double leftVal = evaluate(root->left);
    double rightVal = evaluate(root->right);

    // Apply operator at the current node
    if (root->data == "+") {
        return leftVal + rightVal;
    } else if (root->data == "-") {
        return leftVal - rightVal;
    } else if (root->data == "*") {
        return leftVal * rightVal;
    } else if (root->data == "/") {
        return leftVal / rightVal;
    }

    return 0;
}

int precedence(char op) {
    if (op == '+' || op == '-') {
        return 1;
    }
    if (op == '*' || op == '/') {
        return 2;
    }
    return 0;
}

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}