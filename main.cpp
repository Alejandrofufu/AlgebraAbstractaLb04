#include<bits/stdc++.h>
#include <math.h>
using namespace std;
unsigned long long exponente(long long p,long long g,long long x){
    unsigned long long aux = pow(g,x);
    return aux%p;
}
bool isPrimeNumber(long long n) {
   if (n <= 1) return false;
   if (n <= 3) return true;
   if (n%2 == 0 || n%3 == 0) return false;
   for (long long i=5; i*i<=n; i=i+6)
      if (n%i == 0 || n%(i+2) == 0)
         return false;
   return true;
}
long long power(long long x, unsigned long long y, long long p) {
   long long res = 1;
   x = x % p;
   while (y > 0){
      if (y & 1)
      res = (res*x) % p;
      y = y >> 1;
      x = (x*x) % p;
   }
   return res;
}
void GeneratePrimes(unordered_set<long long> &s, long long n) {
   while (n%2 == 0){
      s.insert(2);
      n = n/2;
   }
   for (long long i = 3; i <= sqrt(n); i = i+2){
      while (n%i == 0){
         s.insert(i);
         n = n/i;
      }
   }
   if (n > 2)
   s.insert(n);
}
long long findPrimitiveRoot(long long n) {
   unordered_set<long long> s;
   if (isPrimeNumber(n)==false)
   return -1;
   long long ETF = n-1;
   GeneratePrimes(s, ETF);
   for (long long r=2; r<=ETF; r++){
      bool flag = false;
      for (auto it = s.begin(); it != s.end(); it++){
         if (power(r, ETF/(*it), n) == 1){
            flag = true;
            break;
         }
      }
      if (flag == false)
      return r;
   }
   return -1;
}


int main() {
   long long n;
   cout<<"escriba un numero n: ";cin>>n;
   long long x = 1,g = findPrimitiveRoot(n);
   cout<<" la raiz primitiva mas pequeña de "<<n<<" es "<<g<<"\n";

   /////////////////////////////////////
   unsigned long long o;
   for(long long i = 0;i<n-1;i++){
       o = exponente(n,g,i);
       //cout<<"\n"<<g<<" ^ "<<i<<" mod "<<n<<" = "<<o;
       if(o == 2021)break;
   }
   cout<<"x es "<<o;
   return 0;
}