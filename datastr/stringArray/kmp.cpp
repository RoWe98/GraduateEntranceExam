#include "cstring"
#include "cstdio"
#include "iostream"
#include "string"


void GetNext(char ch[],int cLen,int next[]){//cLen为串ch的长度
    next[1] = 0;
    int i = 1,j = 0;
    while(i<=cLen){
        if(j==0||ch[i]==ch[j]) next[++i] = ++j;
        else j = next[j];
    }
}

int main()
{
    char p[]={' ','a','b','a','a','b','c','a','c'};
    //char p[]={' '};
    int pLen = sizeof(p)/sizeof(char)-1;
    //int pLen = strlen(p)-1;
    std::cout<<pLen<<std::endl;
    int next[50];
    GetNext(p,pLen,next);
    for(int i=1;i<=pLen;i++)
    {
        printf("%d",next[i]);
    }
    std::cout<<std::endl;
    return 0;
}
