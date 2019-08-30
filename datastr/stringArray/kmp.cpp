#include "cstring"
#include "cstdio"
#include "iostream"
#include "string"


void GetNext_val(char ch[],int cLen,int nextval[])
{
  int i=1;nextval[1]=0;
  int j=0;
  while(i<=cLen)
  {
   if(j==0||ch[i]==ch[j])
   {
      ++i;++j;
      if(ch[i]!=ch[j]) nextval[i]=j;
      else nextval[i]=nextval[j];
   }
   else j=nextval[j];
  }
}

void GetNext(char ch[],int cLen,int next[]){//cLen为串ch的长度
    next[1] = 0;
    int i = 1,j = 0;
    while(i<=cLen){
        if(j==0||ch[i]==ch[j]) next[++i] = ++j;
        else j = next[j];
    }
}

int Index_KMP(char ch1[],char ch2[],int pos,int pLen,int tLen,int next[])
{
  int i = pos;
  int j=1;
  while(i<=pLen&&j<=tLen)
  {
    if(j==0||ch1[i]==ch2[j])
    {
      ++i;
      ++j;
    }
    else{
      j=next[j];
    }
  }
  if(j>tLen) return i-tLen;
  else return 0;
}

int main()
{
    char p[]={' ','a','c','b','d','a','b','a','a','b','c','a','c'};
    char t[]={' ','a','b','a','a','b','c','a','c'};
    //char p[]={' '};
    int tLen = sizeof(t)/sizeof(char)-1;
    int pLen = sizeof(p)/sizeof(char)-1;
    //int pLen = strlen(p)-1;
    
    
    std::cout<<"p string:";
    for(int i=1;i<=pLen;i++)
    {
      std::cout<<p[i]<<" ";
    }
    std::cout<<std::endl;


    std::cout<<"t string:";
    for(int i=1;i<=tLen;i++)
    {
      std::cout<<t[i]<<" ";
    }
    std::cout<<std::endl;

    std::cout<<"p string length:"<<pLen<<std::endl;
    std::cout<<"t string length:"<<tLen<<std::endl;
    int next[50];
    int nextval[50];
    GetNext(t,tLen,next);
    GetNext_val(t,tLen,nextval);
    
    std::cout<<"next:   ";
    for(int i=1;i<=tLen;i++)
    {
        printf("%d ",next[i]);
    }
    std::cout<<std::endl;

    std::cout<<"nextval:";
    for(int i=1;i<=tLen;i++)
    {
      printf("%d ",nextval[i]);
    }
    std::cout<<std::endl;
    
    int kmp_index = Index_KMP(p,t,1,pLen,tLen,nextval);
    std::cout<<"kmp_index:"<<kmp_index<<std::endl;
    return 0;
}
