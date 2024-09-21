#include<stdio.h>
#include<conio.h>
#include<string.h>

void main(){
    char user[100],pass[100];
    char tamp[100], tamp2[100];
    printf("username:"); scanf("%s",&user);
    printf("password:"); scanf("%s",&pass);
    FILE *fptr;
    fptr = fopen("lgn.txt", "a");
    fprintf(fptr, "%s\n%s\n", user, pass);
    fclose(fptr);
    system("cls");
    FILE *ptr;
    ptr = fopen("lgn.txt", "r");
    printf("username:"); scanf("%s",&user);
    printf("password:"); scanf("%s",&pass);

    int a=0;
    while (fscanf(ptr, "%[^\n]\n%[^\n]\n", tamp, tamp2) != EOF)
    {
        if (strcmp(user, tamp) == 0 && strcmp(pass, tamp2) == 0)
        {
            break;
        }
    }
    fclose(ptr);
    if (strcmp(user, tamp) == 0 && strcmp(pass, tamp2) == 0)
    {
       printf("berhasil login");
    }
    else
    {
        for (int a = 0; a < 2; a++)
        {
            
            printf("user dan password invalid!!");
        }

    }
    getch();
}