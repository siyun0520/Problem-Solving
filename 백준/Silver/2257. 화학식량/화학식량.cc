#include <iostream>
#include <string>
#include <stack>
using namespace std;
stack<int>st;
int out=0;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    string str;
    cin>>str;
    for (int i=0; i<str.length(); i++) {
        char c = str[i];
        if (c=='H') {
            st.push(1);
        }
        else if (c=='C') {
            st.push(12);
        }
        else if (c=='O') {
            st.push(16);
        }
        else if (c=='(') {
            st.push(-1);
        }
        else if (c==')') {
            int rst=0;
            while (!st.empty() && st.top()!= -1) {
                rst+=st.top();
                st.pop();
            }
            st.pop();
            st.push(rst);
        }
        else if (isdigit(c)) {
            int num = c-'0';
            int ans = st.top();
            st.pop();
            st.push(ans*num);
        }
    }
    while (!st.empty()) {
        out+=st.top();
        st.pop();
    }
    cout << out << endl;
}