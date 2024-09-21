#include<stdio.h>
#include<conio.h>
// void main()
// {
//     char input;
//     int index = 0;
//     char nama[100];
//     // Loop berlanjut sampai tombol Enter (ASCII 13) ditekan, dan kondisi tertentu terpenuhi.
//     while ((input = getch()) != 13 || index < 3 || nama[index - 1] == ' ')
//     {
//         // Periksa apakah input berada dalam kondisi valid untuk sebuah nama.
//         if (index < 30 && 
//             ((input >= 'A' && input <= 'Z' && index == 0) ||  // Karakter pertama harus huruf kapital.
//             (input >= 'A' && input <= 'Z' && nama[index - 1] == ' ') ||  // Huruf kapital setelah spasi.
//                 (input == ' ' && index != 0 && nama[index - 1] != ' ') ||  // Spasi setelah karakter non-spasi.
//                 (input >= 'a' && input <= 'z' && index != 0 && nama[index - 1] != ' ')  // Huruf kecil setelah karakter non-spasi.
//             ) && (input != nama[index - 1] || input != nama[index - 1]))  // Hindari karakter berturut-turut yang sama.
//         {
//             printf("%c", input);
//             nama[index] = input;  // Simpan input valid dalam array 'nama'.
//             index++;
//         }
//         else if (input == 8 && index != 0)  // Tangani tombol backspace (ASCII 8).
//         {
//             printf("\b \b");  // Pindahkan kursor ke belakang, cetak spasi, dan pindahkan kursor ke belakang lagi.
//             index--;
//             nama[index] = '\0';  
//         }
//     } 
//     getch();
// }

void main(){
    char inputan;
    char data1[30] = {};
    char data2[30] = {};
    int index = 0;
    char umur[5];
    while ((inputan = getch()) != 13 || index < 2 || data1[index - 1] == ' ' || data1[index - 1] == '-' || data1[index - 1] == '\'')
    {
        if (index < 2 && (inputan == '0' && index != 0 || 
        inputan >= '1' && inputan <= '9' || 
        inputan == ' ' && index != 0 && data1[index - 1] != ' ' || 
        inputan == '-' && index != 0 && data1[index - 1] != '-' || 
        inputan == '\'' && index != 0 && data1[index - 1] != '\''))
        {
            printf("%c", inputan);
            data1[index] = inputan;
            index++;
        }
        else if (inputan == 8 && index != 0)
        {
            printf("\b \b");
            index -= 1;
            data1[index] = ' ';
        }
    }
    for (int a = 0; a < index; a++)
    {
        data2[a] = data1[a];
    }
    strupr(data2);
    strcpy(umur, data2);
}