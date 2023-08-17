#include<iterator>
#include<string>
#include<iostream>

using namespace std;

template<typename BidirectionalIterator>
bool isPalindrome(BidirectionalIterator first, BidirectionalIterator last){
    while(true){
        last--;
        if(first == last) break;
        if(*first != *last) return false;
        first++;
        if(first == last) break;
    }
    return true;
}

int main(){
    string word = "ana";
    if (isPalindrome(word.begin(),word.end())) cout<<word<<" is palindrome"<<endl;

    word = "Nadia";
    if (isPalindrome(word.begin(),word.end())) cout<<word<<" is palindrome";
    else cout<<word<<" is not palindrome"<<endl;
    return 0;
}