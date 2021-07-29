//BOJ 1081 

#include<iostream>
#include<string>
using namespace std;

int cnt[10];
int SIZE;
int ten=1;

void calc(int num){
    while (num!=0){
        cnt[num%10]+=ten;
        num/=10;
    }
}
int main() {
    int l,u;
    int ans;
    cin>>l>>u;
    
    while (l <= u) {
        //끝자리 0으로 만들기
        while (l % 10 != 0 && l <= u) {
            calc(l);
            l++;
        }
        if (l > u) break;
        //끝자리 9로 만들기
        while (u % 10 != 9 && l <= u) {
            calc(u);
            u--;
        }

        l /= 10;
        u /= 10;
        for (int i=0; i<=9; i++) {
            cnt[i] += (u - l + 1)*ten;
        }
        ten *= 10;
    }
    for (int i=0; i<=9; i++) {
        ans+=cnt[i]*i;
    }
    cout<<ans<<endl;
    return 0;
}