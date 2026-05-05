#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

// node structure
struct Node {
    string data;
    Node* left;
    Node* right;
};

// create a new node
Node* creatNode(string data){
    Node* Node_new = new Node();
    Node_new->data = data;
    Node_new->left = nullptr;
    Node_new->right = nullptr;

    return Node_new;
}

// checks if the string is an operator
bool isOperator(string s){
    if (s == "+" || s == "-" || s == "*" || s == "/")
        return true;
    else
        return false;
}

// checks if the string is an operand or integer
bool isOperand(string s){
    // checks each character in the string
    for (int i = 0; i < s.length(); i++){
        if (s[i] < '0' || s[i] > '9')
            return false;
    }

    return true;
}

// precedence of the operators
int precedence(string s){
    if (s == "*" || s == "/")
        return 2;
    else if (s == "+" || s == "-")
        return 1;
    else
        return 0;
}

// infix to postfix expression
vector<string> infixToPostfix(string exp){
    stack<string> opstack;          // operators
    vector<string> poststack;       // postfix
    string s;
    stringstream input(exp);

    // reads one part at a time according to blanks
    while (input >> s){
        // if  operand, put it in poststack
        if (isOperand(s)){
            poststack.push_back(s);
        }

        // if left parentheses, opstack
        else if (s == "("){
            opstack.push(s);
        }

        // if right parentheses, pop until left parentheses
        else if (s == ")"){
            while (!opstack.empty() && opstack.top() != "("){
                poststack.push_back(opstack.top());
                opstack.pop();
            }

            // remove left parentheses
            if (!opstack.empty())
                opstack.pop();
        }

        // if it is operator
        else if (isOperator(s)){

            // pop operators with higher or equal precedence
            while (!opstack.empty() && opstack.top() != "(" &&
                   precedence(opstack.top()) >= precedence(s)){
                poststack.push_back(opstack.top());
                opstack.pop();
            }
            opstack.push(s);
        }
    }

    // pop remaining operators
    while (!opstack.empty()){
        poststack.push_back(opstack.top());
        opstack.pop();
    }

    return poststack;
}

// print postfix expression
void printPostfix(vector<string> postfix){
    for (int i = 0; i < postfix.size(); i++){
        cout << postfix[i] << " ";
    }
    cout << endl;
}

// construct binary tree from postfix 
Node* constructTree(vector<string> postfix){
    stack<Node*> st;
    Node* t;
    Node* t1;
    Node* t2;

    // go through every item 
    for (int i = 0; i < postfix.size(); i++){
        // if op, make a node and push to stack
        if (isOperand(postfix[i])){
            t = creatNode(postfix[i]);
            st.push(t);
        }

        // if op, pop two nodes and make it the parent
        else if (isOperator(postfix[i])){
            t = creatNode(postfix[i]);
            // 1st pop is the right child
            t1 = st.top();
            st.pop();
            // 2nd is the left child
            t2 = st.top();
            st.pop();

            t->right = t1;
            t->left = t2;

            // push tree back to the stack
            st.push(t);
        }
    }

    // last node is the root
    t = st.top();
    st.pop();
    return t;
}

// postorder prints postfix expression
void postorder(Node* root){
    if (root == nullptr)
        return;

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}


// prints binary tree
void printTree(Node* root){
    if (root == nullptr)
        return;

    cout << "        " << root->data << endl;
    cout << "      /   \\" << endl;

    cout << "     " << root->left->data << "     " << root->right->data << endl;
    cout << "    / \\   / \\" << endl;

    cout << "   " << root->left->left->data << "   "
         << root->left->right->data << " "
         << root->right->left->data << " "
         << root->right->right->data << endl;

    cout << "  / \\" << endl;

    cout << " " << root->left->left->left->data << "  "
         << root->left->left->right->data << endl;
}

// evaluate postfix expression using stack
int evaluatePostfix(vector<string> postfix){
    stack<int> st;
    int op1;
    int op2;
    int res;

    for (int i = 0; i < postfix.size(); i++){
        // if op, push to the stack
        if (isOperand(postfix[i]))
        {
            st.push(stoi(postfix[i]));
        }

        // if op, pop two numbers and solve
        else if (isOperator(postfix[i]))
        {
            op2 = st.top();
            st.pop();

            op1 = st.top();
            st.pop();
            

            // perform the math operation
            if (postfix[i] == "+")
                res = op1 + op2;
            else if (postfix[i] == "-")
                res = op1 - op2;
            else if (postfix[i] == "*")
                res = op1 * op2;
            else if (postfix[i] == "/")
                res = op1 / op2;

            // push result back into stack
            st.push(res);
        }
    }

    return st.top();
}

// delete tree memory when not needed anymore
void deleteTree(Node* root){
    if (root == nullptr)
        return;

    deleteTree(root->left);
    deleteTree(root->right);

    delete root;
}


int main(){
    string exp;
    vector<string> postfix;
    Node* root;
    int answer;

    cout << "Enter infix expression with spaces:" << endl;
    getline(cin, exp);

    // convert infix to postfix
    postfix = infixToPostfix(exp);
    cout << "\nPostfix expression:" << endl;
    printPostfix(postfix);

    // construct binary tree from postfix
    root = constructTree(postfix);
    cout << "\nBinary tree:" << endl;
    printTree(root);

    // postorder traversal also show postfix
    cout << "\nPostorder traversal:" << endl;
    postorder(root);
    cout << endl;

    // evaluate using stack
    answer = evaluatePostfix(postfix);
    cout << "\nAnswer: " << answer << endl;

    // free the memory!
    deleteTree(root);

    return 0;
}