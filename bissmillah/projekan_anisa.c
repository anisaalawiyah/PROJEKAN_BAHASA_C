///////////////////////////////////////////////////////////////////////////////////////
/////                                                                               ///
/////                                                                               ///
/////                           PROJEK PELATIHAN BAHASA C                           ///
/////                        PENILAIAN UJIAN AKHIR SEMESTER                         ///
/////                                                                               ///
/////                                                                               ///
/////                      NAMA : ANISA ALAWIYAH                                    ///
/////                      ANGKATAN : 21                                            ///
/////                      PRODI : D3 MANAJEMEN INFORMATIKA                         ///
/////                                                                               ///
/////                                                                               ///
/////                   WINDOWS SIZE :                                              ///
/////                                 WEIGHT : 130                                  ///   
/////                                 HIGHT  : 35                                   ///
/////                                                                               ///
///////////////////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include "calor.c"
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

//////////////////////////////////////////VARIABEL GLOBAL/////////////////////////////////////////////////////////
char pilih1;
char pilih2;
char pilih3;
char pilih4;
int tamp = 0, tamp1 = 0, jumlah = 0;
char nama[100], jk[10], umur[5], nohp[13], email[50], user[50], pass[50], alamat[100], rek[100];
int uang2;
char pilih;
char stok[100];
char uang[100];
char alamat[100];
char data[100][100][100];
char tam[100] = {};
char penerima[100];
char penerima1[100] = "PENDIDIDKAN";
char penerima2[100] = "KESEHATAN";
char penerima3[100] = "PEMBAGUNAN";
char penerima4[100] = "KORBAN BENCANA ALAM";
char bank[100];
char bank1[100] = "BRI";
char bank2[100] = "BCA";
char bank3[100] = "SHOPEEPAY";
char bank4[100] = "DANA";
char hari[][7] = {"Minggu", "Senin", "Selasa", "Rabu", "Kamis", "Jumat", "Sabtu"};
char bulan[][10] = {"Januari", "Februari", "Maret", "April", "Mei", "Juni", "Juli", "Agustus", "September", "Oktober", "November", "Desember"};

///////////////////////////////////////////////PROT0TYPE//////////////////////////////////////////////////////

void tampilan();
void login_user();
void pilihan();
void admin();
void menu_admin();
void pilihan_user();
void daftar();
void menu_utama();
void bg(int clr);
void bingkai(int x, int y, int tcolor, int bcolor, int panjang, int lebar);
void bayar();
void logo();
void loading();
void validasi_nama();
void validasi_jk();
void validasi_umur();
void validasi_nohp();
void validasi_email();
void validasi_user();
void validasi_pass();
void validasi_norek();
void kodebayar();
void bayar_p();
void struk_bayar();
void pendidikan();
void val_pilih();
void kesehatan();
void pembagunan();
void bencana();
void read();
void info();
void pendidikan_s();
void kesehatan_s();
void pembangunan_s();
void bencana_s();
void salurkan_dana();
void data_penyaluran();
void ambil_waktu();
void logo1();
void before();
void validasi_uang();
void validasi_alamat();
void cek_dana();
void validasi_rek();
void tampilann();
void awal();
void keluar();
FILE *fptr;

////////////////////////////////////////////////////TAMPILAN//////////////////////////////////////////////////////
void bg(int clr)
{
    for (int x = 0; x <= 34; x++)
    {
        for (int y = 0; y <= 129; y++)
        {
            gotoxy(0 + y, 0 + x);
            color(clr, 0);
            printf("%c", 219);
        }
        Sleep(5);
    }
}

void bingkai(int x, int y, int tcolor, int bcolor, int panjang, int lebar)
{
    for (int z = 1; z <= panjang; z++)
    {
        for (int v = 1; v <= lebar; v++)
        {
            if (z == 1 || v == 1 || z == panjang || v == lebar)
            {
                gotoxy(x + v, y + z);
                color(tcolor, tcolor);
                printf("%c", 219);
            }
            else
            {
                gotoxy(x + v, y + z);
                color(bcolor, bcolor);
                printf("%c", 219);
            }
        }
    }
}
void ambil_waktu()
{
    time_t sekarang = time(NULL);
    struct tm waktu = *localtime(&sekarang);
    printf("%s, %d %s %d || %02d.%02d WIB", hari[waktu.tm_wday], waktu.tm_mday, bulan[waktu.tm_mon], 1900 + waktu.tm_year, waktu.tm_hour, waktu.tm_min);
}

void loading()
{

    for (int a = 0; a <= 50; a++)
    {
        color(8, 7);
        gotoxy(58, 28);
        printf("loading %d %%", a * 2);
        Sleep(10); // persentase
        color(8, 7);
        gotoxy(39 + a, 31);
        printf("%c", 219);
        Sleep(10);
    }
    // system("cls");
    // kursor(66,30); printf("L O G I N  B E R H A S I L "); Sleep(500);
}
void bingkai_awal()
{
    color(8, 7);
    for (int a = 0; a <= 129; a++)
    {
        gotoxy(a + 0, 0);
        printf("%c%c", 219);
        Sleep(5);
        gotoxy(a + 0, 34);
        printf("%c", 219);
        if (a < 34)
        {
            gotoxy(0, 0 + a);
            printf("%c", 219);
            gotoxy(1, 0 + a);
            printf("%c", 219);
            gotoxy(129, 0 + a);
            printf("%c", 219);
            gotoxy(128, 0 + a);
            printf("%c", 219);
        }
    }
    // tampilan();
    // login();
}

void tampilann()
{
    bg(14);
    bingkai_awal();
    for (int x = 1; x < 5; x++)
    {
        color(0, 14);
        gotoxy(x + 1, 2);
        printf("                        .-'-.                     ");
        Sleep(5);
        gotoxy(x + 1, 3);
        printf("                      /`     |__                  ");
        Sleep(5);
        gotoxy(x + 1, 4);
        printf("                    /`  _.--`-,-`                 ");
        Sleep(5);
        gotoxy(x + 1, 5);
        printf("                    '- |`   a '<-.                 ");
        Sleep(5);
        gotoxy(x + 1, 6);
        printf("                       |     ___) =`             ");
        Sleep(5);
        gotoxy(x + 1, 7);
        printf("                       C_  `    ,_/                ");
        Sleep(5);
        gotoxy(x + 1, 8);
        printf("                         | ;----'                  ");
        Sleep(5);
        gotoxy(x + 1, 9);
        printf("                      _./' '\\._                   ");
        Sleep(5);
        gotoxy(x + 1, 10);
        printf("                /--'`  `-.-`  `'- |                ");
        Sleep(5);
        gotoxy(x + 1, 11);
        printf("                |         o        |             ");
        Sleep(5);
        gotoxy(x + 1, 12);
        printf("                |__ .     o        / )             ");
        Sleep(5);
        gotoxy(x + 1, 13);
        printf("              (___)|            /                  ");
        Sleep(5);
        gotoxy(x + 1, 14);
        printf("                | | |           |-'    .--.      ");
        Sleep(5);
        gotoxy(x + 1, 15);
        printf("              /  |_.-       =     --   =   `        ");
        Sleep(5);
        gotoxy(x + 1, 16);
        printf("              <   `  =-->    _= /        __/         ");
        Sleep(5);
        gotoxy(x + 1, 17);
        printf("              '._     _.-- =  ` -...-'`              ");
        Sleep(5);
        gotoxy(x + 1, 18);
        printf("                  `;  `     __/                     ");
        Sleep(5);
        gotoxy(x + 1, 19);
        printf("                    /```````` |                       ");
        Sleep(5);
        gotoxy(x + 1, 20);
        printf("                  |     ,      |                     ");
        Sleep(5);
        gotoxy(x + 1, 21);
        printf("                   |     |      |                      ");
        Sleep(5);
        gotoxy(x + 1, 22);
        printf("                   |      |      |                      ");
        Sleep(5);
        gotoxy(x + 1, 23);
        printf("                    |       |     |                        ");
        Sleep(5);
        gotoxy(x + 1, 24);
        printf("                   /        |     |                   ");
        Sleep(5);
        gotoxy(x + 1, 25);
        printf("                  /        /     |                    ");
        Sleep(5);
        gotoxy(x + 1, 26);
        printf("                /        /`     /`                     ");
        Sleep(5);
        gotoxy(x + 1, 27);
        printf("              .'        |       |                         ");
        Sleep(5);
        gotoxy(x + 1, 28);
        printf("              (          /--.___.'                        ");
        Sleep(5);
        gotoxy(x + 1, 29);
        printf("              `--...__.' /    | __                             ");
        Sleep(5);
        gotoxy(x + 1, 30);
        printf("              /     | __ |        `)                               ");
        Sleep(5);
        gotoxy(x + 1, 31);
        printf("              |         `)---'----`                           ");
        Sleep(5);
        gotoxy(x + 1, 32);
        printf("              '----'----`                                         ");
        Sleep(5);
    }
}

void awal()
{
    bg(14);
    tampilann();
    color(0, 14);
    gotoxy(55, 5);
    printf("|||||||||  ||||||||  |||||||| ||||||||  ");
    gotoxy(55, 6);
    printf("||        ||      || ||       ||        ");
    gotoxy(55, 7);
    printf("||        ||      || ||       ||||||||  ");
    gotoxy(55, 8);
    printf("||        |||||||||| ||       ||        ");
    gotoxy(55, 9);
    printf("||||||||| ||      || ||       ||||||||  ");

    gotoxy(62, 12);
    printf("  ||        |||||    ");
    gotoxy(62, 13);
    printf("  ||       ||   ||   ");
    gotoxy(62, 14);
    printf("  |||||||  ||   ||   ");
    gotoxy(62, 15);
    printf("  ||       ||   ||   ");
    gotoxy(62, 16);
    printf("  |||||||   |||||    ");

    gotoxy(48, 19);
    printf("  ||    || ||    || |||    |||  |||||||  ||||||||   ||||||    ");
    gotoxy(48, 20);
    printf("  ||    || ||    || || |  | || ||     || ||    ||   ||        ");
    gotoxy(48, 21);
    printf("  |||||||| ||    || ||  ||  || ||     || ||    ||     ||      ");
    gotoxy(48, 22);
    printf("  ||    || ||    || ||      || ||||||||| ||    ||       ||    ");
    gotoxy(48, 23);
    printf("  ||    || |||||||| ||      || ||     || ||    ||  ||||||     ");
    gotoxy(54, 33);
    printf("Tekan enter untuk lanjut");
    pause();
    pilihan();
}

void pilihan()
{
    bg(7);
    bingkai_awal();
    // bingkai(0,0,8,7,34,130);
    bingkai(50, 5, 8, 14, 5, 23);
    gotoxy(54, 8);
    color(0, 14);
    printf(" 1 . A D M I N");
    bingkai(50, 12, 8, 14, 5, 23);
    gotoxy(54, 15);
    color(0, 14);
    printf(" 2 . U S E R  ");
    bingkai(50, 19, 8, 14, 5, 23);
    gotoxy(54, 22);
    color(0, 14);
    printf(" 3 . K E L U A R");
    gotoxy(49, 28);
    color(0, 7);
    printf(">> Tekan Pilihan Anda(1-3) <<");
    do
    {
        gotoxy(78, 28);
        pilih1 = getche();
        if (pilih1 == '1')
        {
            admin();
        }
        else if (pilih1 == '2')
        {
            pilihan_user();
        }
        else if (pilih1 == '3')
        {
            exit(0);
        }
        else
        {

            gotoxy(54, 29);
            printf("inputan salah");
            Sleep(50);
            gotoxy(53, 29);
            printf("              ");
            gotoxy(78, 28);
            printf("  ");
        }
    } while (pilih1 != '1' || pilih1 == '2' || pilih1 == '3');
}

void pilihan_user()
{

    system("cls");
    bg(14);
    bingkai_awal();
    gotoxy(45, 4);
    color(0, 14);
    printf("  ___                       _           ");
    gotoxy(45, 5);
    color(0, 14);
    printf(" | _ ) ___ _ _ __ _ _ _  __| |__ _     ");
    gotoxy(45, 6);
    color(0, 14);
    printf(" | _ \\/ -_) '_/ _` | ' \\/ _` / _| | ");
    gotoxy(45, 7);
    color(0, 14);
    printf(" |___/\\___|_| \\__,_|_||_\\__,_\\__,_| ");
    gotoxy(90, 32);
    color(0, 14);
    printf("Tekan 0 untuk kembali!!");
    bingkai(15, 12, 8, 7, 5, 23);
    gotoxy(23, 15);
    color(0, 7);
    printf("1.DAFTAR");
    bingkai(54, 12, 8, 7, 5, 23);
    gotoxy(63, 15);
    color(0, 7);
    printf("2.LOGIN");
    bingkai(92, 12, 8, 7, 5, 23);
    gotoxy(100, 15);
    color(0, 7);
    printf(" 3.INFO ");
    gotoxy(60, 24);
    color(0, 14);
    printf(" PILIH:");
    do
    {
        gotoxy(68, 24);
        pilih2 = getche();
        if (pilih2 == '0')
        {
            pilihan();
        }
        else if (pilih2 == '1')
        {
            daftar();
        }
        else if (pilih2 == '2')
        {
            login_user();
        }
        else if (pilih2 == '3')
        {
            info();
        }
        else
        {
            gotoxy(54, 29);
            printf("inputan invalid!!");
            Sleep(50);
            gotoxy(54, 29);
            printf("                 ");
            gotoxy(68, 24);
            printf("        ");
        }
    } while (pilih2 != '0' || pilih2 != '1' || pilih2 != '2' || pilih2 != '3');
}

void login_user()
{
    bg(7);

    for (int a = 35; a <= 40; a++)
    {
        for (int b = 0; b <= 8; b++)
        {
            gotoxy(45, 3);
            color(0, 7);
            printf(".__                .__          ");
            gotoxy(45, 4);
            color(0, 7);
            printf("|  |   ____   ____ |__| ____     ");
            gotoxy(45, 5);
            color(0, 7);
            printf("|  |  /  _ \\ / ___\\|  |/    \\ ");
            gotoxy(45, 6);
            color(0, 7);
            printf("|  |_(  <_> ) /_/  >  |   |  \\   ");
            gotoxy(45, 7);
            color(0, 7);
            printf("|____/\\____/\\___  /|__|___|  /   ");
            gotoxy(45, 8);
            color(0, 7);
            printf("           /_____/         \\/    ");
        }
    }
    bingkai_awal();
    char tamp[100], tamp2[100];
    FILE *ptr;
    ptr = fopen("login.txt", "r");

    bingkai(45, 10, 8, 14, 9, 30);
    bingkai(45, 14, 8, 14, 1, 30);
    gotoxy(48, 13);
    color(0, 14);
    printf("USERNAME:");
    gotoxy(48, 17);
    color(0, 14);
    printf("PASSWORD:");
    gotoxy(58, 13);
    validasi_user();
    gotoxy(58, 17);
    validasi_pass();
    int a = 0;
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
        gotoxy(30, 20);
        loading();
        system("cls");
        menu_utama();
    }
    else
    {
        for (int a = 0; a < 2; a++)
        {
            printf("%c", 7);
            gotoxy(45, 23);
            printf("user dan password invalid!!");
              char inp;
    gotoxy(40,36);color(0,7);printf("Tekan y/Y untuk Registrasi,dan Tekan t/T untuk kembali Login");
        while ((inp = getch()) != 'y' && inp != 'Y' && inp != 't' && inp != 'T' )
        {

        }
        if (inp == 'y' || inp == 'Y')
        {
        gotoxy(45,25);
        printf("                                                            ");
        daftar();
        }else{
        gotoxy(45,25);
        printf("                                                            ");
        login_user();
        }
            Sleep(500);
        }
        system("cls");
        login_user();
    }
    char inp;
    gotoxy(45,35);color(0,7);printf("Tekan y/Y untuk Registrasi,dan Tekan t/T untuk kembali Login");
        while ((inp = getch()) != 'y' && inp != 'Y' && inp != 't' && inp != 'T' )
        {

        }
        if (inp == 'y' || inp == 'Y')
        {
        gotoxy(45,25);
        printf("                                                            ");
        daftar();
        }else{
        gotoxy(45,25);
        printf("                                                            ");
        login_user();
        }
    }


void daftar()
{
    system("cls");
    bingkai_awal();
    bingkai(40, 3, 8, 8, 28, 50);
    bingkai(42, 5, 7, 0, 24, 46);
    bingkai(43, 9, 7, 7, 1, 44);
    color(15, 0);
    gotoxy(45, 8);
    printf("NAMA          :");
    bingkai(43, 12, 7, 7, 1, 44);
    color(15, 0);
    gotoxy(45, 12);
    printf("JENIS KELAMIN :");
    color(8, 0);
    gotoxy(82, 12);
    printf("L/P");
    bingkai(43, 15, 7, 7, 1, 44);
    color(15, 0);
    gotoxy(45, 15);
    printf("UMUR          :");
    bingkai(43, 18, 7, 7, 1, 44);
    color(15, 0);
    gotoxy(45, 18);
    printf("NO.Hp         :+628");
    bingkai(43, 21, 7, 7, 1, 44);
    color(15, 0);
    gotoxy(45, 21);
    printf("EMAIL         : ");
    bingkai(43, 24, 7, 7, 1, 44);
    color(15, 0);
    gotoxy(45, 24);
    printf("USERNAME      : ");
    bingkai(43, 27, 7, 7, 0, 44);
    color(15, 0);
    gotoxy(45, 27);
    printf("PASSWORD      : ");
    gotoxy(60, 8);
    color(15, 0);
    validasi_nama();
    gotoxy(60, 8);
    color(15, 0);
    printf("%s", nama);
    gotoxy(60, 12);
    color(15, 0);
    validasi_jk();
    gotoxy(60, 12);
    color(15, 0);
    printf("%s", jk);
    gotoxy(60, 15);
    color(15, 0);
    validasi_umur();
    gotoxy(64, 18);
    color(15, 0);
    validasi_nohp();
    gotoxy(60, 21);
    color(15, 0);
    validasi_email();
    gotoxy(60, 21);
    color(15, 0);
    printf("%s", email);
    gotoxy(60, 24);
    color(15, 0);
    validasi_user();
    gotoxy(60, 27);
    color(15, 0);
    validasi_pass();

    FILE *fptr;
    fptr = fopen("login.txt", "a");
    fprintf(fptr, "%s\n%s\n", user, pass);
    fclose(fptr);

    gotoxy(51, 33);
    color(0, 14);
    printf("Anda Berhasil Mendaftar!!");
    Sleep(500);
    gotoxy(40, 33);
    color(0, 14);
    printf("Tekan Apa Saja Untuk Lanjut Login!");
    pause();
    login_user();
}

void menu_utama()
{
    system("cls");
    bg(15);
    bingkai_awal();
    gotoxy(62, 33);
    color(0, 15);
    printf("Tekan 0 untuk kembali!");
    gotoxy(28, 3);
    color(0, 15);
    printf("M A R I B E R S E D E K A H");
    bingkai(14, 4, 8, 8, 28, 42);
    bingkai(3, 6, 0, 14, 27, 48);
    bingkai(7, 11, 0, 0, 1, 41);
    gotoxy(14, 10);
    color(0, 14);
    printf("PILIH KATEGORI BERSEDEKAH");
    gotoxy(11, 14);
    color(0, 14);
    printf("1.PENDIDIKAN");
    gotoxy(11, 17);
    color(0, 14);
    printf("2.KESEHATAN");
    gotoxy(11, 21);
    color(0, 14);
    printf("3.PEMBAGUNAN");
    gotoxy(11, 25);
    color(0, 14);
    printf("4.KORBAN BENCANA ALAM");
    gotoxy(11, 30);
    color(0, 14);
    printf("Pilih:");

    do
    {
        gotoxy(19, 30);
        pilih = getche();
        if (pilih == '0')
        {
            pilihan_user();
        }
        else if (pilih == '1')
        {
            strcpy(penerima, penerima1);
            pendidikan();
        }
        else if (pilih == '2')
        {

            strcpy(penerima, penerima2);
            kesehatan();
        }
        else if (pilih == '3')
        {

            strcpy(penerima, penerima3);
            pembagunan();
        }
        else if (pilih == '4')
        {
            bencana();
            strcpy(penerima, penerima4);
        }
        else
        {
            gotoxy(19, 30);
            printf("inputan invalid!!");
            Sleep(50);
            gotoxy(19, 30);
            printf("                 ");
            gotoxy(19, 30);
            printf("           ");
        }
    } while (pilih != '0' || pilih != '1' || pilih != '2' || pilih != '3' || pilih != '4');
}

void bayar()

{
    bingkai(14, 4, 8, 8, 28, 42);
    bingkai(3, 6, 0, 14, 27, 48);
    gotoxy(62, 33);
    color(0, 15);
    printf("Tekan 0 untuk kembali!");
    bingkai(7, 11, 0, 0, 1, 41);
    gotoxy(15, 10);
    color(0, 14);
    printf("PILIH METODE PEMBAYARAN\n");
    gotoxy(11, 14);
    color(0, 14);
    printf("1.BRI");
    gotoxy(11, 16);
    color(0, 14);
    printf("2.BCA");
    gotoxy(11, 18);
    color(0, 14);
    printf("3.SHOPEEPAY");
    gotoxy(11, 20);
    color(0, 14);
    printf("4.DANA");
    gotoxy(11, 30);
    color(0, 14);
    printf("pilih:");
    do
    {
        gotoxy(19, 30);
        pilih3 = getche();
        if (pilih3 == '0')
        {
            menu_utama();
        }
        else if (pilih3 == '1')
        {
            strcpy(bank, bank1);
            gotoxy(70, 10);
            color(0, 15);
            printf("Masukan no.rek:");
            validasi_rek();
            gotoxy(70, 12);
            printf("Nama:");
            validasi_nama();
            struk_bayar();
        }

        else if (pilih3 == '2')
        {
            strcpy(bank, bank2);
            gotoxy(70, 10);
            color(0, 15);
            printf("masukkan no.rek:");
            validasi_rek();
            gotoxy(70, 12);
            printf("Nama:");
            validasi_nama();
            struk_bayar();
        }
        else if (pilih3 == '3')
        {
            strcpy(bank, bank3);
            gotoxy(70, 10);
            color(0, 15);
            printf("masukkan no.rek:");
            validasi_rek();
            gotoxy(70, 12);
            printf("Nama:");
            validasi_nama();
            struk_bayar();
        }
        else if (pilih3 == '4')
        {
            strcpy(bank, bank4);
            gotoxy(70, 10);
            color(0, 15);
            printf("masukkan no.rek:");
            validasi_rek();
            gotoxy(70, 12);
            printf("Nama:");
            validasi_nama();
            struk_bayar();
        }
        else if (pilih3 == '5')
        {
            gotoxy(70, 10);
            color(0, 15);
            printf("masukkan no.rek:");
            validasi_rek();
            gotoxy(70, 12);
            printf("Nama:");
            validasi_nama();
            struk_bayar();
        }
        else
        {
            gotoxy(22, 32);
            printf("inputan invalid!!");
            Sleep(50);
            gotoxy(22, 32);
            printf("                 ");
            gotoxy(19, 30);
            printf("                 ");
        }
    } while (pilih != '0' || pilih != '1' || pilih != '2' || pilih != '3' || pilih != '4' || pilih != '5');
}

void struk_bayar()
{
    char c;
    system("cls");
    bg(7);
    bingkai_awal();
    Sleep(500);
    bingkai(44, 4, 8, 8, 26, 44);
    bingkai(46, 5, 14, 14, 24, 40);
    gotoxy(47, 8);
    color(0, 14);
    printf("---------------------------------------");
    gotoxy(55, 10);
    color(0, 14);
    printf("  O R A N G  B A I K    ");
    gotoxy(53, 12);
    color(0, 14);
    printf(">>anda telah bersedekah<<");
    gotoxy(49, 14);
    color(0, 14);
    ambil_waktu();
    gotoxy(53, 16);
    color(0, 14);
    printf("sebesar Rp.%s", stok);
    gotoxy(53, 17);
    color(0, 14);
    printf("melalu BANK %s", bank);
    gotoxy(53, 18);
    color(0, 14);
    printf("Dalam Kategori %s", penerima);
    gotoxy(53, 20);
    color(0, 14);
    printf(">>>semoga berkah,aminn<<<");
    gotoxy(49, 22);
    color(0, 14);
    printf("J A Z A K A L L A H  K H A I R A N");
    gotoxy(47, 24);
    color(0, 14);
    printf("---------------------------------------");
    gotoxy(19, 32);
    color(0, 7);
    printf("apakan  andaa ingin keluar?(y/t)");
    while (c != 'y' || c != 'Y' || c != 't' || c != 'T')
    {
        gotoxy(57, 37);
        c = getche();
        gotoxy(57, 37);
        printf(" ");
        if (c == 'y' || c == 'Y')
        {
            pilihan();
        }
        else if (c == 't' || c == 'T')
        {
            menu_utama();
        }
        else
        {
            gotoxy(19, 32);
            color(15, 0);
            printf("Tekan y/Y atau t/T.");
            Sleep(1000);
            gotoxy(19, 32);
            color(15, 0);
            printf("                   ");
        }
    }
}

void pendidikan()
{
    char stk[100] = {};
    int tamp = 0, tamp1 = 0, jumlah = 0;
    gotoxy(74, 5);
    color(0, 15);
    printf(">>>KATEGORI PENDIDIKAN<<<");
    gotoxy(70, 8);
    color(0, 15);
    printf("Nominal :Rp.");
    validasi_uang();
    tamp = atoi(stok);
    FILE *dana;
    dana = fopen("pendidikan.txt", "r");
    fscanf(dana, "%d", &tamp1);
    fclose(dana);
    dana = fopen("pendidikan.txt", "w");
    jumlah = tamp1 + tamp;
    fprintf(dana, "%d", jumlah);
    fclose(dana);
    bayar();
}
void kesehatan()
{
    char stk[100] = {};
    int tamp = 0, tamp1 = 0, jumlah = 0;
    gotoxy(74, 5);
    color(0, 15);
    printf(">>>KATEGORI KESEHATAN<<<");
    gotoxy(70, 8);
    color(0, 15);
    printf("Nominal :Rp.");
    validasi_uang();
    tamp = atoi(stok);
    FILE *dana;
    dana = fopen("kesehatan.txt", "r");
    fscanf(dana, "%d", &tamp1);
    fclose(dana);
    dana = fopen("kesehatan.txt", "w");
    jumlah = tamp1 + tamp;
    fprintf(dana, "%d", jumlah);
    fclose(dana);
    bayar();
}
void pembagunan()
{
    char stk[100] = {};
    int tamp = 0, tamp1 = 0, jumlah = 0;
    gotoxy(74, 5);
    color(0, 15);
    printf(">>>KATEGORI PEMBANGUNAN<<<");
    gotoxy(70, 8);
    color(0, 15);
    printf("Nominal :Rp.");
    validasi_uang();
    tamp = atoi(stok);
    FILE *dana;
    dana = fopen("pembangunan.txt", "r");
    fscanf(dana, "%d", &tamp1);
    fclose(dana);
    dana = fopen("pembangunan.txt", "w");
    jumlah = tamp1 + tamp;
    fprintf(dana, "%d", jumlah);
    fclose(dana);
    bayar();
}
void bencana()
{
    char stk[100] = {};
    int tamp = 0, tamp1 = 0, jumlah = 0;
    gotoxy(73, 5);
    color(0, 15);
    printf(">>>KATEGORI BENCANA ALAM<<<");
    gotoxy(70, 8);
    color(0, 15);
    printf("Nominal:Rp.");
    validasi_uang();
    tamp = atoi(stok);
    FILE *dana;
    dana = fopen("bencana.txt", "r");
    fscanf(dana, "%d", &tamp1);
    fclose(dana);
    dana = fopen("bencana.txt", "w");
    jumlah = tamp1 + tamp;
    fprintf(dana, "%d", jumlah);
    fclose(dana);
    bayar();
}

void info()
{
    system("cls");
    bingkai_awal();
    bingkai(31, 5, 8, 8, 23, 69);
    bingkai(33, 6, 0, 14, 20, 65);
    bingkai(34, 10, 0, 14, 1, 64);
    gotoxy(51, 9);
    color(0, 14);
    printf("I N F O   A P L I K A S I");
    gotoxy(35, 13);
    color(0, 14);
    printf("care to humas  merupakan aplikasi yang dibuat dengan tujuan ");
    gotoxy(35, 14);
    color(0, 14);
    printf("untuk memudahkan kita dalam beramal.Karena pada masa sekarang,");
    gotoxy(35, 15);
    color(0, 14);
    printf("semua kegiatan bisa kita lakukan secara cepat dan real time.");
    gotoxy(35, 16);
    color(0, 14);
    printf("dan aplikasi ini memudahkan orang-orang yang malas keluar");
    gotoxy(35, 17);
    color(0, 14);
    printf("rumah tapi tetap igin melakukan amal baik.Karena sebagaimana");
    gotoxy(35, 18);
    color(0, 14);
    printf("kita ketahui bahwa sebagai sesama manusia kita sudah sepatutnya");
    gotoxy(35, 19);
    color(0, 14);
    printf("membantu satu sama lain.Dan yang sudah kita ketahui bahwa ");
    gotoxy(35, 20);
    color(0, 14);
    printf("tangan di atas lebih baik dari pada tangan di bawah.");
    gotoxy(35, 21);
    color(0, 14);
    printf("di dalam aplikasi ini terdapat 4 fitur katerogi untuk bersedah.");
    gotoxy(35, 23);
    color(0, 14);
    printf("Copyright by@anisaalawiyah238.@gmail.com");
    gotoxy(10, 31);
    color(0, 14);
    printf("Tekan Apa Saja Untuk kembali.");
    getch();
    pilihan();
}

//////////////////////////////////////////////// A D M I N /////////////////////////////////////////////////
void admin()
{
    bg(14);
    bingkai_awal();
    gotoxy(45, 4);
    color(0, 14);
    printf("  _           _                _       _         ");
    gotoxy(45, 5);
    color(0, 14);
    printf(" | |___  __ _(_)_ _    __ _ __| |_ __ (_)_ _     ");
    gotoxy(45, 6);
    color(0, 14);
    printf(" | / _ \\/ _` | | ' \\  / _` / _` | '  \\| | ' \\ ");
    gotoxy(45, 7);
    color(0, 14);
    printf(" |_\\___/\\__, |_|_||_| \\__,_\\__,_|_|_|_|_|_||_|");
    gotoxy(45, 8);
    color(0, 14);
    printf("        |___/                                     ");
    bingkai(51, 13, 8, 0, 3, 25);
    gotoxy(53, 15);
    color(15, 0);
    printf("kode  akses : ");
    int a = 0, b = 0;
    gotoxy(66, 15);
//    login_user[a] = getch();
    while (user[a] != 13)
    {
        if (user[a] == 8)
        {
            a--;
            if (a < 0)
            {
                a = 0;
            }
            gotoxy(66 + a, 15);
            printf(" ");
        }
        else
        {
            printf("*");
            a++;
        }

        if (a > 5)
        {
            a = 5;
            gotoxy(71, 15);
            printf(" ");
        }
        gotoxy(66 + a, 15);
    //    login_user[a] = getch();
    }
    user[a] = '\0';

    if ((strlen(user) <= 9) && (strcmp(user, "12345") == 0))
    {
        loading();
        system("cls");
        menu_admin();
    }
    else
    {
        for (int x = 0; x < 2; x++)
        {
            gotoxy(50, 30);
            printf("KODE AKSES SALAH !!!");
            Sleep(200);
            gotoxy(50, 30);
            printf("                     ");
            Sleep(200);
        }
        system("cls");
        admin();
    }

    gotoxy(10, 10);
    color(0, 14);
    printf("Tekan Apa Saja Untuk kembali.");
    getch();
    pilihan();
}
void menu_admin()
{
    bg(7);
    bingkai_awal();
    char a;
    gotoxy(8, 32);
    color(0, 7);
    printf("Tekan 0 untuk kembali");
    bingkai(1, 4, 8, 14, 20, 40);
    gotoxy(10, 2);
    color(0, 7);
    printf("M E N U   A D M I N");
    bingkai(2, 9, 8, 14, 1, 38);
    gotoxy(14, 8);
    color(0, 14);
    printf("1.CEK DANA");
    bingkai(2, 14, 8, 14, 1, 38);
    gotoxy(13, 13);
    color(0, 14);
    printf("2.SALURKAN DANA ");
    bingkai(2, 19, 8, 14, 1, 38);
    gotoxy(10, 18);
    color(0, 14);
    printf("3.CEK DANA YANG DI SALURKAN");

    gotoxy(9, 22);
    color(0, 14);
    printf("pilih:");
    do
    {
        gotoxy(16, 22);
        color(0, 14);
        a = getche();
        if (a == '0')
        {
            menu_admin();
        }
        else if (a == '1')
        {
            read();
        }
        else if (a == '2')
        {
            read();
            salurkan_dana();
        }
        else if (a == '3')
        {
            cek_dana();
        }
        else
        {
            gotoxy(16, 22);
            printf("pilihan invalid!!");
            Sleep(500);
            gotoxy(16, 22);
            printf("                    ");
            gotoxy(16, 22);
            printf(" ");
        }
    } while (a != '0' || a != '1' || a != '2' || a != '3');
}
void keluar()
{
    char c;
    gotoxy(50, 33);
    color(0, 7);
    printf("apakan  anda ingin keluar?(y/t)");
    while (c != 'y' || c != 'Y' || c != 't' || c != 'T')
    {
        gotoxy(90, 33);
        c = getche();
        if (c == 'y' || c == 'Y')
        {
            pilihan();
        }
        else if (c == 't' || c == 'T')
        {
            menu_admin();
        }
        else
        {
            gotoxy(90, 33);
            color(0, 7);
            printf("Tekan y/Y atau t/T.");
            Sleep(500);
            gotoxy(90, 33);
            color(0, 7);
            printf("                   ");
            gotoxy(90, 33);
            printf(" ");
        }
    }
}
void read()
{
    char buff_int[200];
    FILE *fptr;
    fptr = fopen("pendidikan.txt", "r");
    fgets(buff_int, sizeof(buff_int), fptr);
    gotoxy(50, 5);
    color(0, 7);
    printf("1.Donasi pendidikan    :Rp.%s", buff_int);
    fclose(fptr);
    fptr = fopen("kesehatan.txt", "r");
    fgets(buff_int, sizeof(buff_int), fptr);
    gotoxy(50, 7);
    color(0, 7);
    printf("2.Donasi kesehatan     :Rp.%s", buff_int);
    fclose(fptr);
    fptr = fopen("pembangunan.txt", "r");
    fgets(buff_int, sizeof(buff_int), fptr);
    gotoxy(50, 9);
    color(0, 7);
    printf("3.Donasi pembagunan    :Rp.%s", buff_int);
    fclose(fptr);
    fptr = fopen("bencana.txt", "r");
    fgets(buff_int, sizeof(buff_int), fptr);
    gotoxy(50, 11);
    color(0, 7);
    printf("4.Donasi Bencana alam  :Rp.%s", buff_int);
    fclose(fptr);
    // keluar();
}

void pendidikan_s()
{
    char stk[100] = {};
    int input = 0, saldo = 0, jumlah = 0;
    gotoxy(50, 16);
    color(0, 7);
    printf("masukkan jumlah nominal:Rp. ");
    gotoxy(77, 16);
    color(12, 7);
    validasi_uang();
    input = atoi(stok);
    FILE *dana;
    dana = fopen("pendidikan.txt", "r");
    fscanf(dana, "%d", &saldo);
    fclose(dana);

    if (input >= saldo)
    {
        gotoxy(77, 16);
        printf("Dana tidak mencukupi!!");
        Sleep(500);
        gotoxy(77, 16);
        printf("                       ");
        gotoxy(77, 16);
        printf("    ");
        fprintf(dana, "%d", tamp1);
        Sleep(500);
        pendidikan_s();
    }
    else
    {
        dana = fopen("pendidikan.txt", "w");
        jumlah = saldo - input;
        fprintf(dana, "%d", jumlah);
        fclose(dana);
    }
}
void kesehatan_s()
{
    char stk[100] = {};
    int input = 0, saldo = 0, jumlah = 0;
    gotoxy(50, 16);
    color(0, 7);
    printf("masukkan jumlah nominal:Rp.");
    gotoxy(77, 16);
    color(12, 7);
    validasi_uang();
    input = atoi(stok);
    FILE *dana;
    dana = fopen("kesehatan.txt", "r");
    fscanf(dana, "%d", &saldo);
    fclose(dana);

    if (input >= saldo)
    {
        gotoxy(77, 16);
        printf("Dana tidak mencukupi!!");
        Sleep(500);
        gotoxy(77, 16);
        printf("                       ");
        gotoxy(77, 16);
        printf("    ");
        Sleep(500);
        kesehatan_s();
    }
    else
    {
        dana = fopen("kesehatan.txt", "w");
        jumlah = saldo - input;
        fprintf(dana, "%d", jumlah);
        fclose(dana);
    }
}
void pembangunan_s()
{
    char stk[100] = {};
    int input = 0, saldo = 0, jumlah = 0;

    gotoxy(50, 16);
    color(0, 7);
    printf("masukkan jumlah nominal:Rp. ");
    gotoxy(77, 16);
    color(12, 7);
    validasi_uang();
    input = atoi(stok);

    FILE *dana;
    dana = fopen("pembangunan.txt", "r");
    fscanf(dana, "%d", &saldo);
    fclose(dana);

    if (input >= saldo)
    {
        gotoxy(77, 16);
        printf("Dana tidak mencukupi!!");
        Sleep(500);
        gotoxy(77, 16);
        printf("                       ");
        gotoxy(77, 16);
        printf("    ");
        Sleep(500);
        pembangunan_s();
    }
    else
    {
        dana = fopen("pembangunan.txt", "w");
        jumlah = saldo - input;
        fprintf(dana, "%d", jumlah);
        fclose(dana);
    }
}
void bencana_s()
{
    char stk[100] = {};
    int input = 0, saldo = 0, jumlah = 0;
    gotoxy(50, 16);
    printf("masukkan jumlah nominal:Rp. ");
    gotoxy(77, 16);
    color(12, 7);
    validasi_uang();
    input = atoi(stok);
    FILE *dana;
    dana = fopen("bencana.txt", "r");
    fscanf(dana, "%d", &saldo);
    fclose(dana);
    if (input >= saldo)
    {
        gotoxy(77, 16);
        printf("Dana tidak mencukupi!!");
        Sleep(500);
        gotoxy(77, 16);
        printf("                       ");
        gotoxy(77, 16);
        printf("    ");
        Sleep(500);
        bencana_s();
    }
    else
    {
        dana = fopen("bencana.txt", "w");
        jumlah = saldo - input;
        fprintf(dana, "%d", jumlah);
        fclose(dana);
    }
}

void salurkan_dana()
{
    bingkai_awal();
    gotoxy(50, 14);
    color(0, 7);
    printf("Pilih kategori yang ingin di salurkan:");
    do
    {
        gotoxy(88, 14);
        pilih4 = getche();
        if (pilih4 == '1')
        {
            pendidikan_s();
            data_penyaluran();
        }
        else if (pilih4 == '2')
        {
            kesehatan_s();
            data_penyaluran();
        }
        else if (pilih4 == '3')
        {
            pembangunan_s();
            data_penyaluran();
        }
        else if (pilih4 == '4')
        {
            bencana_s();
            data_penyaluran();
        }
        else
        {
            gotoxy(88, 14);
            printf("inputan invalid!!");
            Sleep(100);
            gotoxy(88, 14);
            printf("                  ");
            gotoxy(88, 14);
            printf(" ");
        }
    } while (pilih4 != '1' || pilih4 != '2' || pilih4 != '3');
}

void data_penyaluran()
{

    bingkai(64, 18, 8, 7, 13, 57);
    bingkai(65, 22, 8, 7, 1, 56);
    gotoxy(70, 21);
    color(0, 7);
    printf("NAMA : ");
    bingkai(65, 26, 8, 7, 1, 56);
    gotoxy(70, 25);
    color(0, 7);
    printf("NO.HP :+62");
    bingkai(65, 30, 8, 7, 0, 56);
    gotoxy(70, 29);
    color(0, 7);
    printf("Alamat:");
    gotoxy(76, 21);
    validasi_nama();
    gotoxy(80, 25);
    validasi_nohp();
    gotoxy(77, 29);
    validasi_alamat();
    char buff[100];
    FILE *fptr;
    fptr = fopen("data_penyaluran.txt", "a");
    fprintf(fptr, "%s;%s;%s;%s\n", nama, nohp, alamat, stok);
    fclose(fptr);
    keluar();
}
void cek_dana()
{

    char nama[100][100], nohp[100][100], alamat[100][100], stok[100][100];
    char login_user[100];
    int index = 0;
    int a;
    FILE *data;
    data = fopen("data_penyaluran.txt", "r");
    while (fscanf(data, "%[^;];%[^;]\t;%[^;];%[^\n]\n", nama[index], nohp[index], alamat[index], stok[index]) != EOF)
    {
        index++;
    }

    for (int i = 0; i < index; i++)
    {
        gotoxy(50, 5 + i + i);
        color(0, 7);
        printf("%s", nama[i]);
        gotoxy(70, 5 + i + i);
        color(0, 7);
        printf("+62%s\t", nohp[i]);
        gotoxy(88, 5 + i + i);
        color(0, 7);
        printf("%s", alamat[i]);
        gotoxy(100, +5 + i + i);
        color(0, 7);
        printf("%s", stok[i]);
    }
    fclose(data);
    keluar();
}
///////////////////////////////////////////////////////////////////////validasi alamat//////////////////////////////////////////////////////////////////////////////////
void validasi_alamat()
{
    char tamp[100];
    char inp;
    int index = 0;
    int space = 0;
    while ((inp = getch()) != 13 || index < 4 || tamp[index - 1] == ' ')
    {
        if (inp >= 'a' && inp <= 'z' && index != 0 && (inp != tamp[index - 1] || inp != tamp[index - 2]) && index < 19 ||
            inp >= 'A' && inp <= 'Z' && (index == 0 || tamp[index - 1] == ' ') && index < 19 ||
            inp == ' ' && index != 0 && inp != tamp[index - 1] && space < 1)
        {
            printf("%c", inp);
            tamp[index] = inp;
            index++;
            if (inp == ' ')
            {
                space++;
            }
        }
        else if (inp == 8 && index != 0)
        {
            if (tamp[index - 1] == ' ')
            {
                space--;
            }
            printf("\b \b");
            index--;
            tamp[index] = '\0';
        }
        // strupr(tamp);
        strcpy(alamat, tamp);
    }
}
///////////////////////////////////////////////////////////validasi uang///////////////////////////////////////////////////////////
void validasi_uang()
{
    // strcpy(stok, "");
    char input;
    int index = 0;
    while ((input = getch()) != 13 || index < 5)
    {
        if (index < 7 && (input >= '1' && input <= '9' || input >= '0' && input <= '9' && index != 0))
        {
            printf("%c", input);
            stok[index] = input;
            index++;
        }
        else if (input == 8 && index != 0)
        {
            printf("\b \b");
            index--;
            stok[index] = '\0';
        }
    }
}

///////////////////////////////////////////////////////////////////////////////validasi norek///////////////////////////////////////////////////////////////
void validasi_rek()
{
    char input;
    int index = 0;
    while ((input = getch()) != 13 || index < 10)
    {
        if (index < 15 && (input >= '1' && input <= '9' || input >= '0' && input <= '9' && index != 0))
        {
            printf("%c", input);
            rek[index] = input;
            index++;
        }
        else if (input == 8 && index != 0)
        {
            printf("\b \b");
            index--;
            rek[index] = '\0';
        }
    }
}
/////////////////////////////////////////////////////////////////////////validasi nama////////////////////////////////////////////////////////////
void validasi_nama()
{
    char input;
    int index = 0;
    while ((input = getch()) != 13 || index < 3 || nama[index - 1] == ' ')
    {
        if (index < 30 && (input >= 'A' && input <= 'Z' && index == 0 || input >= 'A' && input <= 'Z' && nama[index - 1] == ' ' || input == ' ' && index != 0 && nama[index - 1] != ' ' || input >= 'a' && input <= 'z' && index != 0 && nama[index - 1] != ' ') && (input != nama[index - 1] || input != nama[index - 2]))
        {
            printf("%c", input);
            nama[index] = input;
            index++;
        }
        else if (input == 8 && index != 0)
        {
            printf("\b \b");
            index--;
            nama[index] = '\0';
        }
    }
}
//////////////////////////////////////////////////////////////validasi jk/////////////////////////////////////////////////////////////////////////////////////////
void validasi_jk()
{
    char inputan;
    char data1[30] = {};
    char data2[30] = {};
    int index = 0;
    while ((inputan = getch()) != 13 || index < 1 || data1[index - 1] == ' ' || data1[index - 1] == '-' || data1[index - 1] == '\'')
    {
        if (index < 1 && (inputan == 'p' || inputan == 'l' || inputan == 'L' || inputan == 'P' ||
                          inputan == ' ' && index != 0 && data1[index - 1] != ' ' || inputan == '-' && index != 0 && data1[index - 1] != '-' || inputan == '\'' && index != 0 && data1[index - 1] != '\''))
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
    strcpy(jk, data2);
}
//////////////////////////////////////////////////////////////validasi email/////////////////////////////////////////////////////////////////////////////////////

void validasi_email()
{
    char inputan;
    char data1[30] = {};
    char data2[30] = {};
    int index = 0;
    while ((inputan = getch()) != 13 || index < 3 || data1[index - 1] == ' ' || data1[index - 1] == '-' || data1[index - 1] == '\'')
    {
        if (index < 15 && (inputan >= 'a' && inputan <= 'z' || inputan == ' ' && index != 0 && data1[index - 1] != ' ' || inputan == '-' && index != 0 && data1[index - 1] != '-' || inputan == '\'' && index != 0 && data1[index - 1] != '\'' || inputan == '_' || (inputan >= '0' && inputan <= '9') && index != 0) && (inputan != data1[index - 1] || inputan != data1[index - 2]))
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
    strcpy(email, data2);
    strcpy(email, strcat(email, "@gmail.com"));
}
//////////////////////////////////////////////////////////validasi user/////////////////////////////////////////////////////////////////////////////////////
void validasi_user()
{
    char inputan;
    char data1[30] = {};
    char data2[30] = {};
    int index = 0;
    while ((inputan = getch()) != 13 || index < 3 || data1[index - 1] == ' ' || data1[index - 1] == '-' || data1[index - 1] == '\'')
    {
        if (index < 10 && (inputan >= 'a' && inputan <= 'z' || 
        inputan == ' ' && index != 0 && data1[index - 1] != ' ' || 
        inputan == '-' && index != 0 && data1[index - 1] != '-' || 
        inputan == '\'' && index != 0 && data1[index - 1] != '\'' || 
        (inputan >= '0' && inputan <= '9') && index != 0) && (inputan != data1[index - 1] || inputan != data1[index - 2]))
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
    // strupr(data2);
    strcpy(user, data2);
}
///////////////////////////////////////////////////////////validasi password//////////////////////////////////////////////////////////////////////////////
void validasi_pass()
{
    char inputan;
    char data1[30] = {};
    char data2[30] = {};
    int index = 0;
    while ((inputan = getch()) != 13 || index < 3 || data1[index - 1] == ' ' || data1[index - 1] == '-' || data1[index - 1] == '\'')
    {
        if (index < 10 && (inputan >= 'a' && inputan <= 'z' || inputan >= 'A' && inputan <= 'Z' || inputan == ' ' && index != 0 && data1[index - 1] != ' ' || inputan == '-' && index != 0 && data1[index - 1] != '-' || inputan == '\'' && index != 0 && data1[index - 1] != '\'' || inputan >= '0' && inputan <= '9'))
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
    // strupr(data2);
    strcpy(pass, data2);
}
//////////////////////////////////////////////////////////validasi no.hp///////////////////////////////////////////////////////////////
void validasi_nohp()
{
    char inputan1;
    char data1[30] = {};
    char data2[30] = {};
    int index = 0;

    while ((inputan1 = getch()) != 13 || index < 9)
    {
        if (inputan1 >= '0' && inputan1 <= '9' && index < 11 && (inputan1 != data1[index - 1] || inputan1 != data1[index - 2] || inputan1 != data1[index - 3]))
        {
            if (index >= 1 || (index == 0 && inputan1 != '4' && index == 0 && inputan1 != '6' && index == 0 && inputan1 != '0'))
            {
                printf("%c", inputan1);
                data1[index] = inputan1;
                index++;
            }
            else if (index >= 4)
            {
                printf("%c", inputan1);
                data1[index] = inputan1;
                index++;
            }
        }
        else if (inputan1 == 8 && index != 0)
        {
            printf("\b \b");
            index -= 1;
            data1[index] = ' ';
        }
        for (int a = 0; a < index; a++)
        {
            data2[a] = data1[a];
        }
        strcpy(nohp, data2);
    }
}
////////////////////////////////////////////////////////////validasi umur/////////////////////////////////////////////////////////////////////////
void validasi_umur()
{
    char inputan;
    char data1[30] = {};
    char data2[30] = {};
    int index = 0;
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
void main()
{
    system("mode con cols=130 lines=35");
    awal();
    getch();
}