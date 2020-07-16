// untuk pertama kali registrasi menggunakan menu no 99 
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

FILE *user_user;
FILE *user_user2;
FILE *user_admin;
FILE *pt_user;

int tmptgl,tmpbln,tmpthn;
int pil,i=0,j=0,n;
char a[25];
char delete[100];
char username[20];
char password[20];

void menuadm();
void menusr();
void bayar();
void pembayaran();
	
struct pt{
	char nm[10],npt[20],top[2],rek[7];
	int inc;
}pt,tempt;

struct user{
	char us[20],ps[20],nd[20],nb[20];
	char dd[2],rek[7],nik[20];
	char nmt[20],nrt[8];
	int htf;
	int saldo;
}lu,tempusr,sort[100],temp;

struct admin{
	char nm[20],nik[20],tgl[2],nip[25];
}p,tmpadm;

char ipttf(char b[20], char c[8], char d[20], int a){
	user_user=fopen("customer.dat","ab");
	strcpy(lu.nmt,b);
	strcpy(lu.nrt,c);
	while(fread(&lu,sizeof(lu),1,user_user)==1 && strcmp(d,lu.us)!=0){
	}
	lu.htf=a;
	fwrite(&lu,sizeof(lu),1,user_user);
	fclose(user_user);
	return 0;
}

void bayar(){
	//MENU PEMBAYARAN//
	char pil;
	int c=0;
	char tempnmt[8],tempnrt[8];
	int temphtf;
	printf("Bayar:\n");
	printf("1. PLN\n2. KAMPUS\nPilihan: ");
	scanf("%d",&pil);getchar();system("cls");
	if(pil==1){
		user_user=fopen("customer.dat","rb+");
		pt_user=fopen("instansi.dat","rb+");
		while(fread(&pt,sizeof(pt),1,pt_user)==1 && strcmp(pt.nm,"PLN")!=0){
		}
		while(fread(&lu,sizeof(lu),1,user_user)==1 && strcmp(tempusr.us,lu.us)!=0){
		}
		printf("Bayar Tagihan %s\n",pt.nm);
		printf("Jumlah yang dibayarkan : Rp. 100000,-\n");
		printf("Saldo Anda : %d\n",lu.saldo);
			if(lu.saldo>=100000){
				printf("Saldo Anda mencukupi\n");
				printf("Apakah anda ingin melanjutkan pembayaran (y/n)\n");
				printf("Pilihan: ");scanf("%c",&pil);
				if(pil=='y' || pil=='Y'){
					lu.saldo=lu.saldo-100000;
					pt.inc=pt.inc+100000;
					printf("Transaksi Berhasil!\n");
					printf("Sisa Saldo Anda : Rp. %d\n",lu.saldo);
					strcpy(tempnmt,"PLN");
					strcpy(tempnrt,pt.rek);
					fseek(user_user,-sizeof(lu),SEEK_CUR);
					fseek(pt_user,-sizeof(pt),SEEK_CUR);
					fwrite(&lu,sizeof(lu),1,user_user);
					fwrite(&pt,sizeof(pt),1,pt_user);
					fclose(user_user);fclose(pt_user);
					user_user=fopen("customer.dat","ab");
					strcpy(lu.nmt,tempnmt);
					strcpy(lu.nrt,tempnrt);
					lu.htf=100000;
					fwrite(&lu,sizeof(lu),1,user_user);
					fclose(user_user);
					getch();system("cls");menusr();
				}else if(pil=='n' || pil=='N'){
					fclose(user_user);fclose(pt_user);
					printf("Transaksi canceled!\n");
					getch();system("cls");menusr();
				}
			}else if(lu.saldo<=100000){
				printf("Saldo Anda tidak mencukupi!\n");
				printf("Kembali ke menu user\n");
				fclose(user_user);fclose(pt_user);
				getch();system("cls");menusr();
			}
	}
	if(pil==2){
		user_user=fopen("customer.dat","rb+");
		pt_user=fopen("instansi.dat","rb+");
		printf("Gunakan Huruf Besar!\n");
		printf("Masukan Nama Kampus: ");gets(tempt.nm);
		while(fread(&pt,sizeof(pt),1,pt_user)==1 && strcmp(pt.nm,tempt.nm)!=0){
		}
		while(fread(&lu,sizeof(lu),1,user_user)==1 && strcmp(tempusr.us,lu.us)!=0){
		}
		printf("Bayar Tagihan %s\n",pt.nm);
		printf("Jumlah yang dibayarkan : Rp. 1000000,-\n");
		printf("Saldo Anda : %d\n",lu.saldo);
		if(lu.saldo>=1000000){
				printf("Saldo Anda mencukupi\n");
				printf("Apakah anda ingin melanjutkan pembayaran (y/n)\n");
				printf("Pilihan: ");scanf("%c",&pil);
				if(pil=='y' || pil=='Y'){
					lu.saldo=lu.saldo-1000000;
					pt.inc=pt.inc+1000000;
					printf("Transaksi Berhasil!\n");
					printf("Sisa Saldo Anda : Rp. %d\n",lu.saldo);
					strcpy(tempnmt,pt.nm);
					strcpy(tempnrt,pt.rek);
					fseek(user_user,-sizeof(lu),SEEK_CUR);
					fseek(pt_user,-sizeof(pt),SEEK_CUR);
					fwrite(&lu,sizeof(lu),1,user_user);
					fwrite(&pt,sizeof(pt),1,pt_user);
					fclose(user_user);fclose(pt_user);
					user_user=fopen("customer.dat","ab");
					strcpy(lu.nmt,tempnmt);
					strcpy(lu.nrt,tempnrt);
					lu.htf=1000000;
					fwrite(&lu,sizeof(lu),1,user_user);
					fclose(user_user);
					getch();system("cls");menusr();
				}else if(pil=='n' || pil=='N'){
					fclose(user_user);fclose(pt_user);
					printf("Transaksi canceled!\n");
					getch();system("cls");menusr();
				}
			}else if(lu.saldo<=1000000){
				printf("Saldo Anda tidak mencukupi!\n");
				printf("Kembali ke menu user\n");
				fclose(user_user);fclose(pt_user);
				getch();system("cls");menusr();
			}
	}
	if(pil==3){
		menusr();
	}
}

int hitung(int a, char b[20]){
	user_user=fopen("customer.dat","rb+");
	while(fread(&lu,sizeof(lu),1,user_user)==1 && strcmp(b,lu.us)!=0){
	}
	lu.saldo=lu.saldo-a;
	fseek(user_user,-sizeof(lu),SEEK_CUR);
	fwrite(&lu,sizeof(lu),1,user_user);
	fclose(user_user);
	return 0;
}

void tf(){
	//TRANSFER DANA//
	char pil;
	char temprek[8],anem[20];
	char tempnmt[20],tempnrt[8];
	int temphtf,tempjml,e,h;
	strcpy(anem,tempusr.us);
	user_user=fopen("customer.dat","rb+");
	printf("No Rekening Tujuan: ");gets(temprek);
	printf("Jumlah: "); scanf("%d",&tempjml);getchar();
	system("cls");
	e=0;
	while(fread(&lu,sizeof(lu),1,user_user)==1 && strcmp(temprek,lu.rek)!=0){
	}
	if(strcmp(temprek,lu.rek)==0){
		printf("Lanjutkan pembayaran(y/n)?\n");
		scanf("%c",&pil);getchar();
		if(pil=='y' || pil=='Y'){
			strcpy(tempnmt,lu.nd);
			strcpy(tempnrt,lu.rek);
			lu.saldo=lu.saldo+tempjml;
			fseek(user_user,-sizeof(lu),SEEK_CUR);
			fwrite(&lu,sizeof(lu),1,user_user);
			fclose(user_user);
			if(hitung(tempjml,anem)==0)
			if(ipttf(tempnmt,tempnrt,anem,tempjml)==0)
			printf("Transaksi Berhasil!\n");
			getch();system("cls");menusr();
		}
		if(pil=='n' || pil=='N'){
			printf("Transaksi dibatalkan!\n");
			getch();system("cls");fclose(user_user);
			menusr();
		}
	}else if(strcmp(temprek,lu.rek)!=0){
		printf("No Rekening tidak ditemukan!\n");
		getch();system("cls");fclose(user_user);
		menusr();
	}
}				

void waktu(){
	i=0;
	user_user=fopen("customer.dat","rb");
	while(fread(&lu,sizeof(lu),1,user_user)==1){
		if(strcmp(tempusr.us,lu.us)==0){
			printf("Transaksi ke-%d:\n",i);
			printf("%s --> %s\n",lu.nd,lu.nmt);
			printf("%s --> %s\n",lu.rek,lu.nrt);
			printf("Besar Transaksi: Rp. %d,-\n",lu.htf);
			printf("+++++++++++++++++++++++++++++++++++++++++\n\n");
			i++;
		}
	}
	getch();system("cls");
	fclose(user_user);menusr();
}

void jumlah(){//bagian ini sudah dihapus dan harus kalian isi lagi sesuai dengan file.exe
	user_user=fopen("customer.dat","rb+");
	i=0;
	int x=0;
	while(fread(&lu,sizeof(lu),1,user_user)==1){
		 sort[i]=lu;
		 i++;
		 x++;
	}
	for(i=x-1;i>=1;i--)
		for(j=1;j<=i;j++){
			if(sort[j-1].htf<sort[j].htf){ 
			temp=sort[j-1];
			sort[j-1]=sort[j];
			sort[j]=temp;
			}
	}
	for(i=0;i<x;i++){
		printf("Transaksi ke-%d:\n",i);
			printf("%s --> %s\n",sort[i].nd,sort[i].nmt);
			printf("%s --> %s\n",sort[i].rek,sort[i].nrt);
			printf("Besar Transaksi: Rp. %d,-\n",sort[i].htf);
			printf("+++++++++++++++++++++++++++++++++++++++++\n\n");
	}	
	getch();
	system("cls");
	fclose(user_user);
	printf("\n");	
	menusr();
}

void histori(){
	//MENU UNTUK MELIHAT HISTORI TRANSAKSI//
	//BERDASARKAN WAKTU DAN JUMLAH DANA//
	printf("Histori\n");
	printf("Urutkan berdasakan:\n");
	printf("1. Waktu\n2. Jumlah Dana\n");
	printf("Pilihan: ");
	scanf("%d",&pil);getchar();system("cls");
	switch(pil){
		case 1 : waktu();break;
		case 2 : jumlah();break;
		default: menusr();break;
		}	
}

void ceksaldo(){//bagian ini sudah dihapus dan harus kalian isi lagi sesuai dengan file.exe
	//USER CEK SALDO YANG DIMILIKINYA//
	i=0;
	user_user=fopen("customer.dat","rb");
	while(fread(&lu,sizeof(lu),1,user_user)==1){
		if(strcmp(tempusr.us,lu.us)==0){
			printf("Rekening : %s",lu.rek);
			printf("\n");
			printf("Saldo    : %d",lu.saldo);
			getch();
			system("cls");
			menusr();
		}
	}
	fclose(user_user);
}

void menusr(){
	//MENU USER BIASA//
	printf("Selamat Datang Di Internet Banking DKMBank\n");
	printf("1. Cek Saldo\n2. Pembayaran\n3. Transfer Dana\n");
	printf("4. Histori Transaksi\n5. Exit\nPilihan: ");scanf("%d",&pil);getchar();
	system("cls");
	switch(pil){
		case 1 : ceksaldo();break;
		case 2 : bayar();break;
		case 3 : tf();break;
		case 4 : histori();break;
		case 5 : main();break;
		case 6 : menusr();break;
	}
}

void login(){//bagian ini sudah dihapus dan harus kalian isi lagi sesuai dengan file.exe
	//LOGIN USER MAX 3X COBA//
	
	//semua user bisamasuk, 3x gagal tak bisa
	system("cls");
	if(i<3){
	printf("Username : ");gets(tempusr.us);
	printf("Password : ");gets(tempusr.ps);
	user_user = fopen("customer.dat","rb");
	while(fread(&lu,sizeof(lu),1,user_user)==1){
		if(strcmp(tempusr.us,lu.us)==0){
			if(strcmp(tempusr.us,lu.us)==0 && strcmp(tempusr.ps,lu.ps)==0){
				system("cls");
				getch();i=0;
				menusr();
			}
			else{
				printf("Login Gagal!");		
				login();
			}
		}
	}
	fclose(user_user);
	}
	
	else{
		printf("Anda sudah mencoba lebih dari 3 kali, silahkan coba lain kali...");
		getch();
		fclose(user_user);
		main();
	}	
}

	//user 1 gagal user 2 berhasil
	/*system("cls");
	char user[20];
	char pass[20];
	if(i<3){
		printf("Username: ");gets(tempusr.us);
		printf("Password: ");gets(tempusr.ps);
		user_user = fopen("customer.dat","rb+");
		while(fread(&lu,sizeof(lu),1,user_user)==1){
		  }
			if(strcmp(tempusr.us,lu.us)==0&&strcmp(tempusr.ps,lu.ps)==0){
				system("cls");
				getch();
				i=0;
				menusr();
			}	
		
		else{
			printf("Login Gagal");
			getch();
			i++;
		    login();
			}
		fclose(user_user);
	}
	
	else{
		printf("Anda Telah Salah 3x, Silahkan Registrasi");
		main();
		fclose(user_user);
	}
}*/
	
	
void regis1(){//bagian ini sudah dihapus dan harus kalian isi lagi sesuai dengan file.exe
	system("cls");
	user_user=fopen("customer.dat","ab+");
	printf("BIODATA \n");
	printf("Nama Depan        : ");gets(lu.nd);
	printf("Nama Belakang     : ");gets(lu.nb);
	printf("Tgl Lahir         : ");gets(lu.dd);
	printf("NIK (10 Digit) 	  : ");gets(lu.nik);
	fflush(stdin); 
	system("cls");
	printf("Username          : ");gets(lu.us);
	printf("Rekening          : ");gets(lu.rek);
	printf("Password          : ");gets(lu.ps);
	printf("Saldo Awal        : ");scanf("%d",&lu.saldo);
	getch();
	fwrite(&lu,sizeof(lu),1,user_user);
	fclose(user_user);
	main();		
}


void isisaldo(){//bagian ini sudah dihapus dan harus kalian isi lagi sesuai dengan file.exe
	//ISI SALDO//
	int saldotambahan;
		user_user=fopen("customer.dat","ab");
		user_admin=fopen("customer.dat","ab+");
		while(fread(&p,sizeof(p),1,user_admin)==1){ 
		}
		while(fread(&lu,sizeof(lu),1,user_user)==1){
		}
		printf ("No Rekening    : "); gets(lu.rek);
		printf ("Saldo Sekarang : %d \n", lu.saldo);
		printf ("Tambahan saldo :  "); scanf ("%d", &saldotambahan);
		system("cls");
		lu.saldo=lu.saldo+saldotambahan;
		printf("Saldo %s adalah: %d", lu.rek,lu.saldo);
		
		fclose(user_admin);
		fclose(user_user);
		getch();
		system("cls");
		menuadm();
}
	
	/*int s, jml;
	int saldoplus;
	user_user = fopen("customer.dat","ab+");
	user_admin = fopen("customer.dat","ab+");
	while(fread(&lu,sizeof(lu),1,user_user)==1){
		printf ("No Rekening    : "); gets(lu.rek);
		printf ("Saldo Sekarang : %d \n", lu.saldo);
		printf ("Tambah Jumlah Saldo : "); scanf("%d", &saldoplus);
		
		if (strcmp(tempusr.us, lu.rek)==0){	
			fseek(user_admin,(int) -sizeof(p), SEEK_CUR);
			lu.saldo = lu.saldo + saldoplus;
		
			fwrite(&p, sizeof(p), 1, user_admin);  
			fclose(user_admin);
			system("cls");
			printf("Saldo Sekarang : %d", lu.saldo);
			getchar();
			system("cls");
			menuadm();
			break;
		}
		}
	}

//}
//}*/

void instansi(){
	printf("1. Regis Instansi\n2. Lihat Data Instansi\n3. Kembali\nPilihan: ");
	scanf("%d",&pil);getchar();system("cls");
	switch(pil){
		case 1 :{//bagian ini sudah dihapus dan harus kalian isi lagi sesuai dengan file.exe
			system("cls");
			pt_user=fopen("instansi.dat","ab");
			printf("Nama Instansi : "); gets(pt.nm);
			printf("No Instansi   : "); gets(pt.npt);
			printf("Tgl Berdiri   : "); gets(pt.top);
			fflush(stdin);
			system("cls");
			printf("No.Rekening   : "); gets(pt.rek);
			printf("Saldo Awal    : "); scanf("%d", &pt.inc);
			fflush(stdin); 
			getch();
			fwrite(&pt,sizeof(pt),1,pt_user);
			fclose(pt_user);
			system("cls");
			menuadm();
			break;
		}
			
		case 2 :
			pt_user=fopen("instansi.dat","rb");
			while(fread(&pt,sizeof(pt),1,pt_user)==1){
				printf("%s\n",pt.nm);
				printf("No Instansi %s\n",pt.npt);
				printf("No Rekening %s\n",pt.rek);
				printf("Jumlah Pendapatan %d\n\n",pt.inc);
			}
			fclose(pt_user);
			getch();system("cls");
			menuadm();break;
		}
}
void hapus(){//bagian ini sudah dihapus dan harus kalian isi lagi sesuai dengan file.exe
		user_user = fopen("customer.dat", "ab+");
		user_user2 = fopen("customer2.dat", "ab+");
		printf("Silahkan masukkan nama menu yang akan dihapus: "); gets(delete);
		while (fread(&lu,sizeof(struct user),1,user_user)==1){
        if(feof(user_user)!=0){
            break;
        }	
		if (strcmp(lu.us,delete)!=0){
		fwrite(&lu, sizeof(struct user),1,user_user2);
		}
		}

		fclose(user_user);
		fclose(user_user2);
		remove("customer.dat");
		rename("customer2.dat","customer.dat");
		system("cls");
		menuadm();
}

void menuadm(){
	//MENU ADMIN/PEGAWAI//
	printf("Halo Admin!\n");
	printf("Menu:\n");
	printf("1. Isi Saldo\n2. Kerja Sama Instansi\n3. Hapus Custumer \n4. Exit\nPilihan: ");scanf("%d",&pil);
	getchar();system("cls");
	switch(pil){
		case 1 : isisaldo();break;
		case 2 : instansi();break;
		case 3 : hapus();break;
		case 4 : main();break;
		default: menuadm();break;
	}
}

void loginp(){
	//LOGIN ADMIN//
	char tmp1[20],tmp2[20];
	int j=0;
	if(j<=2){

	printf("Username: ");gets(tmp1);
	printf("Password: ");gets(tmp2);

		if(strcmp(tmp1,"admin")==0&&strcmp(tmp2,"admin")==0){
		
		system("cls");
		menuadm();
	}else {
		j++;
		printf("Username atau Password salah! Coba lagi");
		getch();system("cls");
	loginp();
}
	}else{
		printf("Anda sudah 3x salah");
		main();
	}
}

main(){
	//FUNGSI UTAMA//
	system("cls");
	printf("1. Login\n2. Regis\n3. Login Admin\n4. Exit\nPilihan: ");
	scanf("%d",&pil);getchar();
	system("cls");
	i=0; j=0;
	switch(pil){
		case 1 : login();break;
		case 2 : regis1();break;
		case 3 : loginp();break;
		case 4: break;
	
		default: main();break;
	}
}
