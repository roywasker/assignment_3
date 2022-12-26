#include <stdio.h>
#include <string.h>
#include "txtfind.h"
#define LINE 256
#define WORD 30

int newgetlinen(char s[]);// look its work
int getword(char w[]); 
int substring( char * str1, char * str2); 
int similar (char *s, char *t, int n);
void print_lines(char * str); // look its work
void print_similar_words(char * str); 

int main(int argc, char** argv){
    char findstr[WORD]={0};
    char fun[3]={0};
    getword(findstr);
    getword(fun);
    if (fun[0]=='a')
    {
        print_lines(findstr);
    }else if (fun[0]=='b')
    {
        char s[2];
        newgetlinen(s);
        print_similar_words(findstr);
    }else{
        printf("incorrect function type");
    }
    return 0;
}

int newgetlinen(char s[]){
    for (size_t i = 0; i < LINE; i++)
    {
        char ch='\0';
        scanf("%c",&ch);
        if (ch=='\n'||ch==EOF)
        {
            s[i]='\0';
            break;
        }
        else if (ch=='\r')
        {
            ch='\n';
        }
        s[i]=ch;
    }
    return strlen(s);
}
int getword(char w[]){
    char ch=1;
    int i=0;
    while(ch!=EOF){
        ch=fgetc(stdin);
        if (ch==EOF)
        {
            break;
        }
        if(ch!='\n'&&ch!='\t'&&ch!=' ')
        {
            w[i++]=ch;
        }else{
            break;
        }
    }
    return strlen(w);
}

int substring( char * str1, char * str2){ 
    if (strlen(str1)<strlen(str2))
    {
        return 0;
    }else if (strlen(str1)==strlen(str2))
    {
        if (strcmp(str1,str2)==0)
        {
            return 1;
        }else{
            return 0;
        }
    }
    int count=0,j=0;
    for (size_t i = 0; i < strlen(str1); i++)
    {
        if (str1[i]==str2[j])
        {
            j++;
            count++;
        }else{
            j=0;
            count=0;
        }
        if (count == strlen(str2))
        {
            return 1;
        }
    }
    return 0;
}

int similar (char *s, char *t, int n){ 
    if (strlen(s)<strlen(t))
    {
        return 0;
    }else if (strlen(s)==strlen(t))
    {
        if (strcmp(s,t)==0)
        {
            return 1;
        }else{
            return 0;
        }
    }
    int count=0,j=0;
    for (size_t i = 0; i < strlen(s); i++)
    {
        if (s[i]==t[j]) 
        {
            j++;
        }else{
            count++;
        }
        if (count>n)
        {
            return 0;
        }
    }
    return 1;
}

void print_lines(char * str){
    char line[LINE]={0};
    int linelen=1;               
    while(linelen>0){          
        memset(&line,0,sizeof(line));
        linelen=newgetlinen(line);
        if (substring(line,str)==1)
        {
            printf("%s",line);
        }
    }
}

void print_similar_words(char * str){
    char word[WORD]={0};
    int wordlen=1;            
    while(wordlen>0){          
        memset(&word,0,sizeof(word));
        wordlen=getword(word);
        if (similar(word,str,1)==1)
        {
            printf("%s\n",word);
        }
    }
}