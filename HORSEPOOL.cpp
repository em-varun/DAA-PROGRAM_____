#include<iostream>
#include<string>
using namespace std;
class horspoolstring
{
public:
int table[126];
string t,p;
void shifttable();

int horspool(string t, string p);
};
void horspoolstring:: shifttable()
{
int m=this->p.size();
int i,j;
for(i=0;i<126;i++)
table[i]=m;
for(j=0;j<=m-2;j++)
table[p[j]]=m-1-j;
}

int horspoolstring:: horspool (string t,string p)
{

int n,i,k,j,m;
n=t.size();
m=p.size();
for(i=0;i<126;i++)
table[i]=m;
for(j=0;j<=m-2;j++)
table[p[j]]=m-1-j;
i=m-1;
while(i<=n-1)
{
k=0;
while(k<=m-1 && p[m-1-k] == t[i-k])
k++;

if(k == m)
{

return(i-m+1);
}
else

i=i+table[t[i]];
}

return(-1);
}
int main()
{
horspoolstring obj1;
int result;
cout<<"Enter the Text\n";
getline(cin,obj1.t);
cout<<"Enter the Pattern\n";
getline(cin,obj1.p);
obj1.shifttable();
result=obj1.horspool(obj1.t,obj1.p);
if(result != -1)
cout<<"The position of the pattern is"<<result;
else
cout<<"Pattern is not found in the given text\n";
}
