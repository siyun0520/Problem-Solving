#include <bits/stdc++.h>
using namespace std;
int n;
int main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);
    cin>>n;
    int dice[n];
    int a=0,b=0,c=0,d=0;
    double score=0,time=0;
    for (int i=0;i<n;i++) {
        cin>>dice[i];
    }
    double add_score=1.0;
    int add_time=4;
    for (int i=0;i<n;i++) {
        if (time>240) {
            if (score>=35 && score<65) a++;
            else if (score>=65 && score<95) b++;
            else if (score>=95 && score<125) c++;
            else if (score>=125) d++;
            score=0;
            time=0;
            add_score=1;
            add_time=4;
        }
        if (dice[i]==1) {
            if (score>=35 && score<65) a++;
            else if (score>=65 && score<95) b++;
            else if (score>=95 && score<125) c++;
            else if (score>=125) d++;
            score=0;
            time=0;
            add_score=1;
            add_time=4;
        }
        else if (dice[i]==2){
            if (add_score>1) {
                add_score=add_score/2;
            }
            else if (add_score==1) {
                add_time+=2;
            }
            score+=add_score;
            time+=add_time;
        }
        else if (dice[i]==3) {
            score+=add_score;
            time+=add_time;
        }
        else if (dice[i]==4) {
            score+=add_score;
            time+=add_time;
            time+=56;
        }
        else if (dice[i]==5) {
            if (add_time>1) {
                add_time--;
            }
            score+=add_score;
            time+=add_time;
        }
        else if (dice[i]==6) {
            if (add_score<32) {
                add_score*=2;
            }
            score+=add_score;
            time+=add_time;
        }
    }
    cout << a << endl << b << endl << c << endl << d << endl;
    return 0;
}