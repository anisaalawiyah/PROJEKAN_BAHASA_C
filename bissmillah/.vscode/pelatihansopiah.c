#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <windows.h>

void main(){
    char nama[100];
    char baca [100];
    char hapus [100];
    int pilih ;
    FILE *fptr;
    
  
    do{
    int a=0;
        char data [a][100];
        bool cekdata = false;
        printf ("1.menambah\n2.tampil data\n3.update\n4.delete\n5.keluar\npilih :");
        scanf ("%d",&pilih);
        if (pilih==1){
            fptr = fopen ("database.txt.c","a");
            printf ("masukkan isi database :");gets (nama);

            fgets (nama ,sizeof(nama),stdin);

            fputs (nama,fptr);

            printf ("file berhasil ditulis\n");
            fclose (fptr);
            system ("pause");
            system ("cls");

        }
        else if (pilih==2){
            fptr =fopen ("database.txt","r");
            printf ("isi dalam database\n");
            while (fgets (baca,sizeof(baca),fptr)){
                printf ("%s",baca); 
            }
            fclose (fptr);
                system ("pause");
            system ("cls");
        }
        else if (pilih==3){

            getchar();
            printf ("masukkan nama yg ingin di update");
            gets (hapus);
            strcat (hapus,"\n");
            fptr=fopen ("database.txt","r");
            while (fgets(baca ,sizeof(baca),fptr)){
                strcpy (data [a],baca);
                a++;
            }
            for (int i=0;i<a;i++){
                if (strcmp(data[i],hapus)==0){
                    printf ("maukkan nama baru :");
                    gets (hapus);
                    strcat(hapus,"\n");
                    strcpy (data [i],hapus);
                    cekdata=true;

                }
            }
            if (cekdata){
                fptr=fopen ("database,txt","w");
                fclose (fptr);
                for (int i=0;i<a;i++){
                    fptr =fopen ("database,txt","a");
                    fputs (data [i],fptr);
                    fclose (fptr);
                }
            }
        }
    }while(pilih != 5);
    



}