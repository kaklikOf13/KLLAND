#include "KLLC/KLLC.h"
#include <stdio.h>
#include <cstring>
void PrintHelp(){
    printf("Commands:\n");
    printf(" eval-run <path>\n");
}
int main(int argc, char* argv[]){
    if (argc>=1){
        if(strncmp(argv[1],"eval-run",strlen(argv[1]))==0){
            if (argc>=2){
                kllc::VM vm;
                size_t retsize;
                kllc::byte* v=vm.EVAL_FILE(argv[2],&retsize);
                printf("%s\n",kllc::BytesToHex(v,retsize).c_str(),retsize);
            }
        }else{
            printf("Invalid Command '%s'.\n");
            PrintHelp();
        }
    }else{
        PrintHelp();
    }
}