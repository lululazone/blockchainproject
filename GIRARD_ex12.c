#define _POSIX_C_SOURCE 1
#include <stdio.h>
#include <time.h>
#include <sys/stat.h>
#include <dirent.h>



#define TOUT_VA_BIEN 0
#define ERR_ACCES_REP 1


void AfficherInfos(char Design[])
{
  struct stat Infos;

  if (stat(Design,&Infos)==-1)
  {
    perror(Design);
return; }

  printf("%-20s : ",Design);
  if (S_ISDIR(Infos.st_mode))
    printf("répertoire ");
  else
    printf("fichier    ");

  printf("%8ld octets ",Infos.st_size);

  printf("%s",ctime(&Infos.st_mtime));
}
int main(int argc, char *argv[])
{
  int cpt ; /* compteur de paramètres */
  DIR *Repertoire;
  struct dirent *Element;
  if (argc==1)
  {

    Repertoire=opendir(".");
    if (Repertoire==NULL)
    {
      perror("Échec  ");
      return ERR_ACCES_REP;
    }

  while ((Element=readdir(Repertoire))!=NULL)
    AfficherInfos(Element->d_name);
  closedir(Repertoire);
  }
  else
  {
    for(cpt=1;cpt<argc;cpt++)
    {
      AfficherInfos(argv[cpt]);
    }
  }
return TOUT_VA_BIEN;
   }
