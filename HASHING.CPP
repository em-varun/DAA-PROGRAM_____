#include <bits/stdc++.h>
using namespace std;

int main() {

string s="geeksforgeeks";


int arr[26]={0};

//Storing the count
for(int i=0;i<s.size();i++){
	arr[s[i]-'a']++;
}


char ch='e';

cout<<"The count of ch is "<<arr[ch-'a']<<endl;
return 0;
}
