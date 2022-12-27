/*#include<stdio.h>
#include<stdlib.h>

typedef struct
{
    char JMBG[15];
    char prezime[20];
    char ime[20];
}Ucenik;

void check(FILE *p)
{
    if(p==NULL)
    {
        printf("error\n");
        exit(1);
    }
}
Ucenik ucenik[15];

int main()
{
    int n;
    int j=0;
    int br=0;
    FILE *fp;
    char ime_fajla[30];
    printf("Unesite koliko ucenika zelite da unesete\n");
    scanf("%d",&n);
    //creates files
    sprintf(ime_fajla,"Grupa%d.txt",j+1);
    fp=fopen(ime_fajla,"w");
    check(fp);
    fclose(fp);
    for(int i=0;i<=(n/3);i++)
    {
        sprintf(ime_fajla,"Grupa%d.txt",i+1);
        fp=fopen(ime_fajla,"w");
        check(fp);
        fclose(fp);
    }
    //write in file
    for(int i=0;i<n;i++)
    {
        sprintf(ime_fajla,"Grupa%d.txt",j+1);
        fp=fopen(ime_fajla,"a");
        check(fp);
        printf("Unesite JMBG, prezime i ime za %d. ucenika \n",i+1);
        scanf("%s %s %s",&ucenik[i].JMBG,&ucenik[i].prezime,&ucenik[i].ime);
        fprintf(fp,"%s %s %s\n",ucenik[i].JMBG,ucenik[i].prezime,ucenik[i].ime);
        if(br==2)
        {
            fclose(fp);
            j++;
            br=0;
        }
else br++;
}
for(int i=0;i<=(n/3);i++)
{
    sprintf(ime_fajla,"Grupa%d.txt",i+1);
        fp=fopen(ime_fajla,"r");
        printf("GRUPA:%d\n",i+1);
        printf("--------\n");
        printf("JMBG Ime Prezime\n");

        do {
      int c = fgetc(fp);
      if( feof(fp) ) {
         break ;
      }
      printf("%c", c);
   } while(1);
fclose(fp);
}


}*/


#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct
{
    char JMBG[15];
    char prezime[20];
    char ime[20];
    int grupa;
}Ucenik;

bool check_is_full(int arr[],int i)
{

    if(arr[i]>=3)
    {
        printf("Grupa koju ste uneli je popunjena, upisite ucenika u neku drugu grupu!\n");
        printf("Napisite samo drugu grupu!\n");
        return false;
        }
        else return true;
}
void check(FILE *p)
{
    if(p==NULL)
    {
        printf("Error: file was not created!\n");
        exit(1);
    }
}

void clear_files(FILE *p,char str[])
{
for(int i=0;i<5;i++)
{
   sprintf(str,"Grupa%d.txt",i+1);
   p=fopen(str,"r");
   if(p!=NULL)
   {
       fclose(p);
       p=fopen(str,"w");
       fclose(p);
   }

}
}
Ucenik ucenik[15];

int main()
{
    int n;
    bool moze=true;
    int j=0;
    FILE *fp;
    char ime_fajla[30];
    char stampaj[80];
    int br[5]={0,0,0,0,0};
    printf("Unesite koliko ucenika zelite da unesete\n");
    scanf("%d",&n);
    clear_files(fp,ime_fajla);
    for(int i=0;i<n;i++)
    {
        printf("Unesite JMBG, prezime, ime i broj grupe za %d. ucenika \n",i+1);
        scanf("%s %s %s %d",&ucenik[i].JMBG,&ucenik[i].ime,&ucenik[i].prezime,&ucenik[i].grupa);
        moze=check_is_full(br,ucenik[i].grupa-1);
        while(moze==false)
        {
            scanf("%d",&ucenik[i].grupa);
            moze=check_is_full(br,ucenik[i].grupa-1);
        }

        sprintf(ime_fajla,"Grupa%d.txt",ucenik[i].grupa);
        fp=fopen(ime_fajla,"a");
        check(fp);
        fprintf(fp,"%s %s %s %d\n",ucenik[i].JMBG,ucenik[i].ime,ucenik[i].prezime,ucenik[i].grupa);
        br[ucenik[i].grupa-1]++;
        fclose(fp);
}
printf("SPISAK GRUPA ZA VEZBE\n\n");
printf("SPISAK GRUPA ZA VEZBE\n");

for(int i=0;i<5;i++)
    {
        if(br[i]!=0)
        {

        sprintf(ime_fajla,"Grupa%d.txt",i+1);
        fp=fopen(ime_fajla,"r");
        printf("GRUPA:%d\n",i+1);
        printf("--------\n");
        printf("JMBG Ime Prezime\n");

        do {
      int c = fgetc(fp);
      if( feof(fp) ) {
         break ;
      }
      printf("%c", c);
   } while(1);
fclose(fp);
    }
    while(fgets(stampaj,80,fp)!=NULL)
    {
        puts(stampaj);
    }
        }





}



