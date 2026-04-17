#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>

using namespace std;

int num, k;
int w[101] = {0,};
int v[101] = {0,};
int dp[101][100001];

void dipr(){
    for(int lim=1;lim<=k;lim++){
        for(int row=1;row<=num;row++){
            if(w[row]>lim){ 
                dp[row][lim] = dp[row-1][lim];
            }
            else{
                dp[row][lim] = max(dp[row-1][lim-w[row]]+v[row],dp[row-1][lim]);
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> num >> k;
    for (int i=1;i<=num;i++){
        cin >> w[i] >> v[i];
    }
    
    for(int r=0;r<=num;r++){
        dp[r][0] = 0;
    }
    for(int c=0;c<=k;c++){
        dp[0][c] = 0;
    }

    dipr();

    cout << dp[num][k];

    return 0;
    
}