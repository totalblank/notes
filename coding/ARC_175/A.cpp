// Solution by Hlcoder

#include<iostream>
#include<set>
#include<algorithm>
#include<vector>
#include<string>
#include<set>
#include<map>
#include<stack>
#include<numeric>
#include<queue>
#include<cassert>
#include<cmath>
#include<deque>
using namespace std;
typedef long long ll;
const ll INF=1LL<<60;
typedef pair<int,int> P;
typedef pair<ll,P> PP;


const int mod = 998244353;
struct mint {
  long long x; // typedef long long long long;
  mint(long long x=0):x((x%mod+mod)%mod){}
  mint operator-() const { return mint(-x);}
  mint& operator+=(const mint a) {
    if ((x += a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator-=(const mint a) {
    if ((x += mod-a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator*=(const mint a) { (x *= a.x) %= mod; return *this;}
  mint operator+(const mint a) const { return mint(*this) += a;}
  mint operator-(const mint a) const { return mint(*this) -= a;}
  mint operator*(const mint a) const { return mint(*this) *= a;}
  bool operator==(const mint a) const {return a.x==x;}
  mint pow(long long t) const {
    if (!t) return 1;
    mint a = pow(t>>1);
    a *= a;
    if (t&1) a *= *this;
    return a;
  }

  // for prime mod
  mint inv() const { return pow(mod-2);}
  mint& operator/=(const mint a) { return *this *= a.inv();}
  mint operator/(const mint a) const { return mint(*this) /= a;}
};

std::istream& operator>>(std::istream& is, mint& a) { return is >> a.x;}
std::ostream& operator<<(std::ostream& os, const mint& a) { return os << a.x;}



struct combination {
  std::vector<mint> fact, ifact;
  combination(int n):fact(n+1),ifact(n+1) {
    assert(n < mod);
    fact[0] = 1;
    for (int i = 1; i <= n; ++i) fact[i] = fact[i-1]*i;
    ifact[n] = fact[n].inv();
    for (int i = n; i >= 1; --i) ifact[i-1] = ifact[i]*i;
  }
  mint operator()(int n, int k) {
    if (k < 0 || k > n) return 0;
    return fact[n]*ifact[k]*ifact[n-k];
  }
};

int main(){
    int N;
    cin>>N;
    vector<int> p(N);
    for(int i=0;i<N;i++){
        cin>>p[i];
        p[i]--;
    }
    string S;
    cin>>S;

    mint ans=0;
    
    {
        mint ans_left=1;
        vector<bool> used_left(N,1);
        
        for(int i=0;i<N;i++){
            int pos=p[i];
            int rhs=(pos+1+N)%N;
            if(used_left[rhs]){
                if(S[pos]=='R')ans_left*=0;
            }else{
                if(S[pos]=='?')ans_left*=2;
            }

            used_left[pos]=0;
            
        }
        //cout<<"ans_left="<<ans_left<<endl;

        ans+=ans_left;

    }

    {
        mint ans_right=1;
        vector<bool> used_right(N,1);
        
        for(int i=0;i<N;i++){
            int pos=p[i];
            int lhs=(pos-1+N)%N;
            if(used_right[lhs]){
                if(S[pos]=='L')ans_right*=0;
            }else{
                if(S[pos]=='?')ans_right*=2;
            }

            used_right[pos]=0;
            
        }
        //cout<<"ans_right="<<ans_right<<endl;

        ans+=ans_right;

    }

    cout<<ans<<endl;
}
