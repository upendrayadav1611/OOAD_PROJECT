#include<iostream>
#include<stdio.h>
#include<math.h>
#include<string>
#include<algorithm>
#include<stdlib.h>
#include<string.h>
#include<termios.h>
#include<time.h>
#include<limits>
#include<unistd.h>
#include<thread>
#include<chrono>
#include<fstream>
#include<cstdio>
#include<ctype.h>
#define maxi(a, b) a > b ? a : b
#define mini(a, b) a < b ? a : b

#define BUYER 0
#define SELLER 1

using namespace std;

string globalUser = "LOGIN";
fstream fout;
fstream fin;
int strcmpi (char *s1,char *s2)
{
    int i=0,diff=0;
    for(i=0; s1[i]!='\0'; i++)
    {
        if( toupper(s1[i])!=toupper(s2[i]) )
            return 1;           
    }
    return 0;
}