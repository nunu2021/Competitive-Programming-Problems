#include <stdio.h>
#include "bits/stdc++.h"
#include <cstring>
using namespace std;

int main(){
    int names, commands;
    scanf("%d %d", &names, &commands);
    map<string, string> name_map;
    for(int i = 0; i < names; i++){
        char ip[15], name[10];
        scanf("%s %s \n",  name, ip);
        name_map[ip] = name;
    }
    
    for (int i = 0; i<commands; i++){
        char ip[15], command[11];
        scanf("%s %[^;];", command, ip);
        printf("%s %s; #%s\n", command, ip, (name_map[ip]).c_str());
    }
}