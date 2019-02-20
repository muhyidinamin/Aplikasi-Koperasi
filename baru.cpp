#include <stdio.h>	
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>

int pil , i, jenis;						//Daftar variabel global
	long int data;
	char opsi, search[25];

FILE *fdata /*file database*/, *ftemp; /*file sementara*/

struct nasabah							//variabel record dengan nama nas
{ char nama[40];
  char norek[10];
  int setoran;
  int saldo;
  char status;
}nas;

void setcolor(unsigned short color) 	//fungsi untuk pemberian warna
{
  	HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);	//membuat objek hCon
  	SetConsoleTextAttribute(hCon,color);			//program untuk merubah warna,color akan diganti dengan nilai i nantinya
}

void gotoxy(int x, int y)				//fungsi untuk membuat titik kordinat
{

	HANDLE hConsoleOutput;
	COORD dwCursorPosition;
	dwCursorPosition.X=x;
	dwCursorPosition.Y=y;
	hConsoleOutput=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput,dwCursorPosition);
}

void alfa()				//SUBPROGRAM nama kelompok 
{
	gotoxy(15,7); printf("=============================================\n");Sleep(500);
	gotoxy(15,8); printf("|       =       =        =====      =       |\n");Sleep(500);
	gotoxy(15,9); printf("|      = =      =        =         = =      |\n");Sleep(500);
	gotoxy(15,10);printf("|     =   =     =        =====    =   =     |\n");Sleep(500);
	gotoxy(15,11);printf("|    =======    =        =       =======    |\n");Sleep(500);
	gotoxy(15,12);printf("|   =       =   =====    =      =       =   |\n");Sleep(500);
	gotoxy(15,13);printf("=============================================\n");Sleep(500);
}

int loading()
{						//SUBPROGRAM fungsi untuk loading
    int n,j;
    for(n=0;n<80;n++)
    {
		printf("loading %d %", n+20);
        printf("\n");
        for(j=0;j<n;j++)
        {
            printf(">");
        }
    system("cls");
    }
    alfa();
	gotoxy(15,14);printf("Anggota Kelompok:\n");
	gotoxy(15,15);printf("\t   Muhamad Muhyidin Amin    1441177004201\n");Sleep(500);  //Sleep untuk delay time
	gotoxy(15,16);printf("\t   Mukhammad Khilmi         1441177004160\n");Sleep(500);
	gotoxy(15,17);printf("\t   Yudi Raharjo             1441177004169\n");Sleep(500);
	gotoxy(15,18);printf("\t   Ariyanto                 1441177004132\n");Sleep(500);
	gotoxy(15,19);printf("\t   Hikmah Rusman Pratama    1441177004265\n");Sleep(500);
	gotoxy(15,21);printf("Press any key to continue...");
	getch();
	return 0;
}

void header()			//SUBPROGRAM header program
{
	gotoxy(9,3); puts(" Sistem Penyimpanan dan Pengambilan Tabungan Koperasi");			
	gotoxy(23,4);puts(" Fasilkom Unsika 2014/2015");
	gotoxy(28,5);puts(" Kelompok Alfa");
}

void menu()				//SUBPROGRAM untuk main menu
{			

	system("cls");
	header();
	gotoxy(20,7);printf("=================================");
	gotoxy(20,8);printf("|    M A I N     M E N U        |");
	gotoxy(20,9);printf("=================================");
	gotoxy(20,10);printf("| 1. Pembukaan tabungan         |");
	gotoxy(20,11);printf("| 2. Deposit                    |");
	gotoxy(20,12);printf("| 3. Witdraw                    |");
	gotoxy(20,13);printf("| 4. Informasi                  |");
	gotoxy(20,14);printf("| 5. Penutupan tabungan         |");
	gotoxy(20,15);printf("| 6. Cari data Nasabah          |");
	gotoxy(20,16);printf("| 7. Keluar                     |");
	gotoxy(20,17);printf("_________________________________");
	gotoxy(20,18);printf("Pilihan Anda : ");
	fflush(stdin);                                         
	pil = getche();
    system("cls");
	return;
}

void buka() 			//SUBPROGRAM untuk membuka filedata
	{
		fdata = fopen("database.txt", "r+");                        			//buka file dan baca file database
		if(fdata == NULL) 														//jika belum ada file
		{                                           				  
			fdata = fopen ("database.txt","w+");                    			//maka buat dan tulis database baru
			if(fdata == NULL) 
			{ 									  					  
				puts(" File database tidak dapat dibuat!\n");     
			}
		}
	}

void isi()				//SUBPROGRAM untuk mengisi/input nasabah baru	
{
		buka();
		fseek(fdata, 0, SEEK_END); 												//membaca filedata secara random
	   	gotoxy(20,1);printf(" FORMULIR PENDAFTARAN TABUNGAN  \n");
	   	gotoxy(10,2);puts("_____________________________________________");
		gotoxy(10,3);printf(" Nomor Rekening     : ");gets(nas.norek);			//Input data Nasabah baru
		gotoxy(10,4);printf(" Nama               : ");gets(nas.nama);		
		gotoxy(10,5);printf(" Setoran Awal       : ");scanf("%d", &nas.saldo);
		gotoxy(10,6);puts("_____________________________________________");
		gotoxy(10,7); puts(" Jenis Tabungan : \n");
		gotoxy(10,8); puts(" 1. Tabungan Pelajar \n");
		gotoxy(10,9); puts(" 2. Tabungan Umum \n");
		gotoxy(10,10);puts(" 3. Tabungan Bisnis \n");
		gotoxy(10,11);printf(" Silahkan Masukkan Jenis tabungan"); 
		gotoxy(10,12);printf(" yang akan dibuat : ");scanf("%d", &jenis);		//Penentuan Jenis tabungan yang akan dibuat
				switch(jenis){
					case 1 :
						gotoxy(10,14);printf(" Biaya Pendaftaran untuk Tabungan Pelajar : 5000 \n");
						nas.setoran=(nas.saldo+5000);
						gotoxy(10,15);printf(" Jumlah yang harus dibayar : %d\n", nas.setoran);
						nas.status = 'P';
						fwrite(&nas, data, 1, fdata);
						break;
					case 2 :
						gotoxy(10,14);printf(" Biaya Pendaftaran untuk Tabungan Umum : 10000 \n");
						nas.setoran=(nas.saldo+10000);
						gotoxy(10,15);printf(" Jumlah yang harus dibayar : %d\n", nas.setoran);
						nas.status='U';
						fwrite(&nas, data, 1, fdata);
						break;
					case 3 :
						gotoxy(10,14);printf(" Biaya Pendaftaran untuk Tabungan Bisnis : 15000 \n");
						nas.setoran=(nas.saldo+15000);
						gotoxy(10,15);printf(" Jumlah yang harus dibayar : %d\n", nas.setoran);
						nas.status='B';
						fwrite(&nas, data, 1, fdata);
						break;
				}
		char x[]={"====> Selamat Bergabung di Koperasi Alfa <===="};			//Ucapan Selamat
		int a,b,i,n;
		n=strlen(x);
		for(i=0;i<n;i++)
		{	for(a=0;a<=99999;a++){
				for(b=0;b<=120;b++){
				}
			}
			gotoxy(10+i,17);printf("%c", x[i]);
		}
		Sleep(1000);
		gotoxy(10,18);printf("\n Press any key to back . . . ");				//untuk kembali ke main menu
		fflush(stdin);
		getchar();
		system("cls");	   	 
		fclose(fdata);         	   //Menutup file database
}

void back()		//SUBPROGRAM untuk kembali ke main menu
{
	printf("\n\t Press any key to back . . . ");
	getch(); 										//menahan layar sampai penekanan tombol keyboard  
	system("cls");     								//bersihkan layar
}

void setoran()		//SUBPROGRAM untuk menambahkan saldo (Menabung)
{
	int setor;		//Variabel local
	
	buka();
	opsi = 'y';
	while(opsi == 'y' || opsi == 'Y') 
	{
		printf("\n Masukkan No rekening yang dicari : ");    
		scanf("%s", search);
		rewind(fdata);											            	//Mereset posisi pointer ke posisi awal file
		while(fread(&nas, data, 1, fdata) == 1) 
		{
			if(strcmp(nas.norek, search) == 0)
				{                         
					gotoxy(10,3);printf("|========================================|");       	 	//outputan data nasabah sblm menabung              
					gotoxy(10,4);printf("|  Data Nasabah dengan No Rekening '%s'  |", search);
				 	gotoxy(10,5);printf("|========================================|");
					gotoxy(10,6);printf("| Nomor Rekening    : %s", nas.norek);gotoxy(51,6);puts("|");
					gotoxy(10,7);printf("| Nama              : %s", nas.nama);gotoxy(51,7);puts("|");		
					gotoxy(10,8);printf("| Jumlah Saldo      : %d", nas.saldo);gotoxy(51,8);puts("|");
					gotoxy(10,9);printf("| Status Tabungan   : %c", nas.status);gotoxy(51,9);puts("|");
       				gotoxy(10,10);printf("|========================================|");
					gotoxy(10,11);printf(" Masukkan nominal   : ");scanf("%d", &setor);
       				fflush(stdin);
					nas.saldo +=setor;																//Operasi penambahan saldo
					
					gotoxy(10,13);printf("|========================================|");				//outputan data nasabah stlh menabung
					gotoxy(10,14);printf("|  Informasi Saldo saat ini No.Rek '%s'  |", search);
				 	gotoxy(10,15);printf("|========================================|");
					gotoxy(10,16);printf("| Nomor Rekening    : %s", nas.norek);gotoxy(51,16);puts("|");
					gotoxy(10,17);printf("| Nama              : %s", nas.nama);gotoxy(51,17);puts("|");		
					gotoxy(10,18);printf("| Jumlah Saldo      : %d", nas.saldo);gotoxy(51,18);puts("|");
					gotoxy(10,19);printf("| Status Tabungan   : %c", nas.status);gotoxy(51,19);puts("|");
       				gotoxy(10,20);printf("|========================================|");
					fseek(fdata, - data, SEEK_CUR);                   	//pointer balik ke posisi awal
					fwrite(&nas, data, 1, fdata);						//menulis data ke filedata
					break;
			 	}       
		}
		gotoxy(10,23);printf("INGIN MENABUNG LAGI? [Y/T]: ");			//konfirmasi
		fflush(stdin); 								
		opsi = getchar();
		system("cls");													//bersihkan layar
	}
		
	fclose(fdata);														//Menutup file database
 	printf("\n");
    back();
}

void penarikan()		//SUBPROGRAM untuk Mengurangi saldo (Mengambil uang)
{
	int tarik;			//Variabel local
	
	buka();
	opsi = 'y';
	while(opsi == 'y' || opsi == 'Y') 
	{
		printf("\n Masukkan No rekening yang dicari : ");    
		scanf("%s", search);
		rewind(fdata);											            	//Mereset posisi pointer ke posisi awal file
		while(fread(&nas, data, 1, fdata) == 1) 
		{
			if(strcmp(nas.norek, search) == 0)									//membandingkan 2 string antara no.rek dgn inputan
				{                         
					gotoxy(10,3);printf("|========================================|");              //outputan data nasabah sblm diambil
					gotoxy(10,4);printf("|  Data Nasabah dengan No Rekening '%s'  |", search);
				 	gotoxy(10,5);printf("|========================================|");
					gotoxy(10,6);printf("| Nomor Rekening    : %s", nas.norek);gotoxy(51,6);puts("|");
					gotoxy(10,7);printf("| Nama              : %s", nas.nama);gotoxy(51,7);puts("|");		
					gotoxy(10,8);printf("| Jumlah Saldo      : %d", nas.saldo);gotoxy(51,8);puts("|");
					gotoxy(10,9);printf("| Status Tabungan   : %c", nas.status);gotoxy(51,9);puts("|");
       				gotoxy(10,10);printf("|========================================|");
					gotoxy(10,11);printf(" Masukkan nominal   : ");scanf("%d", &tarik);
       				fflush(stdin);
					if(nas.saldo>tarik && nas.saldo>20000){						//Syarat jika ingin mengambil tabungan
						nas.saldo -=tarik;										//Operasi pengurangan tabungan
						nas.saldo -=5000;										//biaya pengambilan 
						gotoxy(10,13);printf(" Biaya Penarikan sebesar 5000 ");
					}else{
						gotoxy(10,13);printf(" Saldo anda tidak mencukupi.");	//Pesan peringatan
						goto end;
					}
					gotoxy(10,14);printf("|========================================|");             //outputan data nasabah stlh diambil         
					gotoxy(10,15);printf("|  Informasi Saldo saat ini No.Rek '%s'  |", search);
				 	gotoxy(10,16);printf("|========================================|");
					gotoxy(10,17);printf("| Nomor Rekening    : %s", nas.norek);gotoxy(51,16);puts("|");
					gotoxy(10,18);printf("| Nama              : %s", nas.nama);gotoxy(51,17);puts("|");		
					gotoxy(10,19);printf("| Jumlah Saldo      : %d", nas.saldo);gotoxy(51,18);puts("|");
					gotoxy(10,20);printf("| Status Tabungan   : %c", nas.status);gotoxy(51,19);puts("|");
       				gotoxy(10,21);printf("|========================================|");
					fseek(fdata, - data, SEEK_CUR);                  			//pointer balik ke posisi awal
					fwrite(&nas, data, 1, fdata);								//menulis data ke file databse 
					break;
       			}
		}
		end:
		gotoxy(10,23);printf("INGIN MENGAMBIL LAGI? [Y/T]: ");					//konfirmasi
		fflush(stdin); 
		opsi = getchar();
		system("cls");
	}
		
	fclose(fdata);
	printf("\n");
    back();
}
	
void view()		//SUBPROGRAM untuk menampilkan daftar dari keseluruhan nasabah/anggota
{
		buka();											//Membuka file database 
        rewind(fdata);			   						//Mereset posisi pointer ke posisi awal file 
        i=1;
        gotoxy(20,1);printf("   DAFTAR NASABAH BANK \n");
 		gotoxy(5,2);printf("|====|===============|==============|==============|================|\n");
   		gotoxy(5,3);printf("| No |  No Rekening  |     Nama     | Total Saldo  | Jenis Tabungan |\n");
  		gotoxy(5,4);printf("|====|===============|==============|==============|================|\n");
		while(fread(&nas, data, 1, fdata) == 1)  				//Membaca database struct dari file database sampai bernilai 1 
        {				   		
			gotoxy(7,5+i);printf("%d", i);
      		gotoxy(12,5+i);printf(nas.norek);
      		gotoxy(28,5+i);printf(nas.nama);
      		gotoxy(43,5+i);printf("%d", nas.saldo);
      		gotoxy(58,5+i);printf("%c", nas.status);	
			i++;
    	}
    	gotoxy(5,5+i);printf("|====|===============|==============|==============|================|");         	         	
    	fclose(fdata);									//Menutup file database 
        printf("\n");
        back();
}

void hapus()
{
	buka();
	opsi='y';
	while(opsi == 'Y'|| opsi == 'y') 
	{
		printf(" Masukkan No Rekening yang akan dihapus: ");					
		scanf("%s", search);
		gotoxy(10,3);printf("|========================================|");                      
		gotoxy(10,4);printf("|    Nasabah dengan No Rekening '%s'     |", search);
	 	gotoxy(10,5);printf("|========================================|");
		ftemp = fopen("file_sementara.txt", "w");								//membuat file sementara
		rewind(fdata);															//Mereset posisi pointer ke posisi awal file
		while(fread(&nas, data, 1, fdata) == 1)						//Membaca database struct dari file database sampai bernilai 1
		{
			if(strcmp(search, nas.norek) != 0)						//membandingkan 2 string
			{        	                    
				fwrite(&nas, data, 1, ftemp);						//jika tidak sesuai inputan copi ke ftemp -> file_sementara.txt
       		}
		}
				
			fclose(fdata);											//menutup file database pointer fdata
			fclose(ftemp);											//menutup file database pointer ftemp
			remove("database.txt");									//menghapus file database lama
			rename("file_sementara.txt", "database.txt");			//mengubah nama file database
			fdata = fopen("database.txt", "r+");					//mengubah pointer ftemp -> fdata
		char x[]={"__________ DATA SUDAH TERHAPUS ___________"};
		int a,b,i,n;
		n=strlen(x);
		for(i=0;i<n;i++)
		{	for(a=0;a<=99999;a++){
				for(b=0;b<=120;b++){
				}
			}
			gotoxy(10+i,7);printf("%c", x[i]);
		}

		gotoxy(10,9);printf("HAPUS DATA NASABAH LAIN?? [Y/T]: ");	//konfirmasi
		fflush(stdin) ;
		opsi = getchar();
		system("cls");
	}
	fclose(fdata);
	back();
}
   	
void cari()		//SUBPROGRAM untuk mencari data salah satu nasabah/anggota koperasi 
{
	buka();
	opsi = 'y';
	while(opsi == 'y' || opsi == 'Y') 
	{
		printf("\n Masukkan No rekening yang dicari : ");    
		scanf("%s", search);
		rewind(fdata);											       	//Mereset posisi pointer ke posisi awal file
		while(fread(&nas, data, 1, fdata) == 1) 
		{
			if(strcmp(nas.norek, search) == 0)							//membandingkan 2 string antara no.rek dgn inputan 
				{   gotoxy(10,3);printf("|========================================|");                      
					gotoxy(10,4);printf("|  Data Nasabah dengan No Rekening '%s'  |", search);
				 	gotoxy(10,5);printf("|========================================|");
					gotoxy(10,6);printf("| Nomor Rekening    : %s", nas.norek);gotoxy(51,6);puts("|");
					gotoxy(10,7);printf("| Nama              : %s", nas.nama);gotoxy(51,7);puts("|");		
					gotoxy(10,8);printf("| Jumlah Saldo      : %d", nas.saldo);gotoxy(51,8);puts("|");
					gotoxy(10,9);printf("| Status Tabungan   : %c", nas.status);gotoxy(51,9);puts("|");
   					gotoxy(10,10);printf("|========================================|");
					fflush(stdin);
					break;
       			}
		}
		printf("\n Cari Data Nasabah Lain? [Y/T]: ");					//konfirmasi untuk looping
		fflush(stdin); 
		opsi = getchar();
		
	}								
	fclose(fdata);
	back();
}

void keluar()
{
	fclose(fdata);		//Menutup file database apabila ada yang masih terbuka
	header();			//header program
	alfa();
	char x[]={"===================> TERIMA KASIH <==================="};			//Ucapan Selamat
		int a,b,i,n;
		n=strlen(x);
		for(i=0;i<n;i++)
		{	for(a=0;a<=99999;a++){
				for(b=0;b<=120;b++){
				}
			}
			gotoxy(10+i,17);printf("%c", x[i]);
		}
	Sleep(1000);
    exit (0);
		
}

main()
{ 
	setcolor(113);
	data = sizeof(nas); //mengngitung ukuran data nasabah
	loading();
	while(8) 
		{
        	menu();
        	switch(pil) 
			{           
            	case '1':
					isi(); 	//memanggil SUBPROGRAM isi/input data nasabah baru
            		break;

            	case '2':
                	setoran(); 	//memanggil SUBPROGRAM setoran data
            		break;
            	
				case '3':
                	penarikan(); 	//memanggil SUBPROGRAM penarikan data
            		break;
            		
            	case '4':
                	view(); 	//memanggil SUBPROGRAM view/lihat data
            		break;
            		
            	case '5':
                	hapus(); 	//memanggil SUBPROGRAM hapus data
            		break;
					
				case '6':
                	cari(); 	//memanggil SUBPROGRAM cari data nasabah
            		break;
            		
				case '7':
					keluar();	  //memanggil SUBPROGRAM keluar
					break;
					
				default:
					printf(" Kode yang anda inputkan salah!\n \n Silahkan Masukan Nilai Antara  1/2/3/4/5/6/7. \n");
					getch();
					break; 
			}
		}	
}
