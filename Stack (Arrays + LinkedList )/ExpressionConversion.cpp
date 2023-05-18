#include <bits/stdc++.h>

using namespace std;

int pre(char x){
    if(x=='+' || x=='-'){
        return 1;
    }
    else if(x=='*' || x=='/'){
        return 2;
    }
    else if(x=='^'){
        return 3;
    }
    return 0;
}

bool isOperator(char x){
    if(x == '+' || x == '-' || x == '*' || x == '/' || x == '^'){
        return true;
    }
    return false;
}

bool isOperand(char x){
    if( (x>='a' && x<='z') || (x>='A' && x<='Z') || (x>='0' && x<='9')){
        return true;
    }
    return false;
}

string infixToPostfix(string infix){

    int len = infix.length();
    string postfix;

    stack<char> st;

    for(int i=0;i<len;i++){
        char c = infix[i];

        if(isOperand(c)){
            postfix.push_back(c);
        }
        else if(c=='('){
            st.push('(');
        }
        else if(c==')'){
            while(st.top()!='('){
                postfix.push_back(st.top());
                st.pop();
            }
            st.pop();
        }
        else{
            while(!st.empty() && pre(c) < pre(st.top())){
                postfix.push_back(st.top());
                st.pop();
            }
            st.push(c);
        }
    }

    while(!st.empty()){
        postfix.push_back(st.top());
        st.pop();
    }
    return postfix;
}

string infixToPrefix(string infix){
    int len = infix.size();

    reverse(infix.begin(),infix.end());

    for(int i=0;i<len;i++){
        if(infix[i]=='('){
            infix[i] = ')';
        }else if(infix[i]==')'){
            infix[i] = '(';
        }
    }

    string prefix = infixToPostfix(infix);
    
    reverse(prefix.begin(),prefix.end());

    return prefix;
}

string postfixToInfix(string postfix){
    string infix;
    int len = postfix.size();
    stack<string> st;
    for(int i=0;i<len;i++){
        if(isOperand(postfix[i])){
            string op(1, postfix[i]);
            st.push(op);
        }
        else{
            string op1 = st.top();
            st.pop();
            string op2 = st.top();
            st.pop();

            string initExpr = "(" + op2 + postfix[i] + op1 + ")";
            st.push(initExpr);
        }
    }
    infix = st.top();
    st.pop();
    return infix;
}

string prefixToInfix(string prefix){
    stack<string> st;
    int len = prefix.size();

    for(int i=len-1;i>=0;i--){
        if(isOperator(prefix[i])){
            string op1 = st.top();
            st.pop();
            string op2 = st.top();
            st.pop();

            string initExpr = "(" + op1 + prefix[i] + op2 + ")";
            st.push(initExpr);
        }else{
            string op(1,prefix[i]);
            st.push(op);
        }
    }

    string infix = st.top();
    st.pop();
    return infix;
}

string postFixToPrefix(string postfix){
    string infix = postfixToInfix(postfix);
    string prefix = infixToPrefix(infix);

    return prefix;
}

string prefixToPostfix(string prefix){
    string infix = prefixToInfix(prefix);
    string postfix = infixToPostfix(infix);

    return postfix;
}

int main(){
    string expression;
    int operation = -1;

    while(operation!=7){
        cout << "Choose any one from below : " << endl;
        cout << "1. Infix to Postfix" << endl;
        cout << "2. Infix to Prefix" << endl;
        cout << "3. Postfix to Infix" << endl;
        cout << "4. Postfix to Prefix" << endl;
        cout << "5. Prefix to Postfix" << endl;
        cout << "6. Prefix to Infix" << endl;
        cout << "7. Exit" << endl << endl;

        cout << "Operation : ";
        cin >> operation;

        if(operation==7){
            cout << endl;
            break;
        }
        
        cout << "Enter Expression : " ;
        cin >> expression;

        cout << endl;

        if(operation==1){
            cout << infixToPostfix(expression) << endl;
        }
        else if(operation==2){
            cout << infixToPrefix(expression) << endl;
        }
        else if(operation==3){
            cout << postfixToInfix(expression) << endl;
        }
        else if(operation==4){
            cout << postFixToPrefix(expression) << endl;
        }
        else if(operation==5){
            cout << infixToPostfix(expression) << endl;
        }
        else if(operation==6){
            cout << infixToPostfix(expression) << endl;
        }

        cout << endl;

    }

    return 0;
};