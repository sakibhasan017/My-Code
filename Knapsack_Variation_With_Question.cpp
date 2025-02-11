
/*
You are in a book shop which sells n different books. You know the price, the number of pages, and the number of copies of each book.

You have decided that the total price of your purchases will be at most x. What is the maximum number of pages you can buy? You can buy several copies of the same book.

Input:

    The first input line contains two integers n and x:
        n: the number of books
        x: the maximum total price

    The next line contains n integers h₁, h₂, ..., hₙ:
        The price of each book

    The next line contains n integers s₁, s₂, ..., sₙ:
        The number of pages in each book

    The last line contains n integers k₁, k₂, ..., kₙ:
        The number of copies available for each book

Output:

Print one integer: the maximum number of pages that can be bought without exceeding the price limit x.

Constraints:
    1 ≤ n ≤ 100
    1 ≤ x ≤ 10^5
    1 ≤ hi,si,ki ≤ 1000

Example:
Input

3 10
2 6 3
8 5 4
3 5 2

Output

28
*/

#include<bits/stdc++.h>
#define inf (1<<30)-1
using namespace std;

 int price[107],page[107],copies[107];

 int KS(int rem,int ext,int n,int wc){
    if(n<0) return 0;
    if(ext<=0) return 0;
    if(price[n]>wc) return KS(rem,ext,n-1,wc);

    int exclude=KS(rem,ext,n-1,wc);
    int include1=page[n]+KS(rem+1,copies[n]-rem,n,wc-price[n]);
    int include2=page[n]+KS(rem,copies[n]-rem,n-1,wc-price[n]);
    
    return max({include1,include2,exclude});
 }

int main(){
   
    int n,wc;
    cin>>n>>wc;
 

    for(int i=0;i<n;i++){
       cin>>price[i];
    }

    for(int i=0;i<n;i++){
       cin>>page[i];
    }

    for(int i=0;i<n;i++){
       cin>>copies[i];
    }

   
   cout<<KS(1,copies[n-1],n-1,wc)<<endl;
     

}