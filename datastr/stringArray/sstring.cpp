#include "stdio.h"
#include "iostream"
#include "malloc.h"
#include "string.h"

#define CHUNKSIZE 80

char blank = '#';

typedef struct Chunck{
  char ch[CHUNKSIZE];
  struct Chunck *next;
}Chunck;

typedef struct{
  Chunck *head,*tail;
  int curlen;
}LString;

void InitString(LString *T){
  (*T).curlen=0;
  (*T).head=NULL;
  (*T).tail=NULL;
}

//Assign String 
bool StrAssign(LString *T,char *chars){
  int i,j,k,l;
  Chunck *p,*q;
  i=strlen(chars); //get the lenght of the string 
  if(!i||strchr(chars,blank)) //length of the string is 0 or includes blanks;
    return false;
  (*T).curlen=i; 
  j=i/CHUNKSIZE;//get the number of Chunck 
  if(i%CHUNKSIZE)
    j++;
  for(k=0;k<j;k++){
    p=new Chunck;
    if(!p){
      return false;
    }
    if(k==0){ 
      // first Chunck 
      (*T).head=p;
    }else{
      q->next=p;
      q=p;
    }
    for(l=0;l<CHUNKSIZE&&*chars;l++)
    {
      *(q->ch+l)=*chars++;
    }
    if(!*chars)
    {
      (*T).tail=q;
      q->next=NULL;
      for(;l<CHUNKSIZE;l++)
        *(q->ch+l)=blank;
    }
  }
  return true;
}


void StrPrint(LString T)
{
  int i=0,j;
  Chunck *h;
  h=T.head;
  while(i<T.curlen)
  {
    for(j=0;i<CHUNKSIZE;j++)
      if(*(h->ch+j)!=blank)
      {
        printf("%c",*(h->ch+j));
        i++;
      }
    h=h->next;
  }
  std::cout<<std::endl;
}

int main()
{
  char S1[] = "ABCDEFGHI";
  char *s1 = S1;
  int pos,len;
  LString t1;
  InitString(&t1);
  std::cout<<"t1 init success!"<<std::endl;
  if(StrAssign(&t1,s1)){
    std::cout<<"t1:";
    StrPrint(t1);
  }
  return 0;
}



