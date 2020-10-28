#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

FILE *f;
char opcode[20];
char buffer[200];
char start[] = "START";

void deleteSpace(char* buf){
    char temp[10];
     //printf("%s",buf);

    for(int i=0, j=0;buf[i]!='\0';i++){
        
        if(buf[i]==' '||buf[i]=='\t') {continue;}
        else{
            if(temp[j]=='.') {printf("%c",temp[j]); break;}
            temp[j]=buf[i];
            
            j++;
            

        }
    }
    

    //return temp;

}

int main(int argc, char *argv[])
{
    char filename[50];

    if (argc > 1){
        strcpy(filename, argv[1]);
    }
    else {
        printf("No file.");
        exit(1);
    }

    f = fopen(filename, "r");
    while (f == NULL){
        printf("Can't find: %s\n", filename);
        exit(1);
    }
    // Start pass1 processing..
    int i = 0;

    while (i != 1){
        if (fgets(buffer, 255, f) < 0){
            printf("read error");
        }
        else{
            if (strncmp(buffer, ".", 1) == 0){
                continue;
            }
            else{
                printf("%c\n", buffer[0]);
                i++;
                deleteSpace(buffer);
                if (strcmp(buffer, "START") == 0){
                    break;
                }
            }
        }

        /* do
    {
        if (fgets(buffer, 255, f) < 0)
        {
            printf("error fgets");
        }
        printf("%s", buffer);
        while (buffer[0] == '.' || buffer[0] == '\n')
        {
            if (fgets(buffer, 255, f) < 0)
            {
                printf("%s", buffer);
            }
        }
    }while (buffer[0] == "END");*/
     }
}