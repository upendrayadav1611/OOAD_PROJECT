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
