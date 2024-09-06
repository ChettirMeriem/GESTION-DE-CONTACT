
// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max_C 100
#define CAPACITY_INIT  30
///declaration des variables
int i,j;
int TotalContact=0;
 typedef  struct {
    char Nom[max_C];
    char numTel[10];
    char email[50];
}Contact;
Contact contacts[max_C];




/*typedef struct {
    Contact * contacts;
    int TotalContact;
    int capacity;
}ContactList;*/
/*void initialiser_list(ContactList   * li){
    li->contacts=malloc(CAPACITY_INIT*sizeof(Contact)) ;
    li->TotalContact=0;
    li->capacity=CAPACITY_INIT;
    printf("%d",li->capacity);
}
*/


void AjouterContact(){

    if (TotalContact <max_C){
       printf("donner le nom du contact\n");
       scanf("%s",contacts[TotalContact].Nom);
       printf("donner le numero de tel du contact\n");
       scanf("%s",contacts[TotalContact].numTel);
       printf("donner l'email du contact\n");
       scanf("%s",contacts[TotalContact].email);
          TotalContact ++;

    }

}
void AfficherContact(){
    int i;
if (TotalContact == 0){
        printf("liste vide\n");

}else{
for(i=0;i<TotalContact;i++){
    printf("le contact %d de Nom %s, email: %s , numTel:%s est",i+1,contacts[i].Nom,contacts[i].email,contacts[i].numTel);
}
}
}
int  RechercherContact(){
    int i;
    char contact_rechercher[20];
        printf("entrer  le contact rechercher\n");
        scanf("%s",contact_rechercher);
        for( int i=0;i<TotalContact;i++){
            if(strcmp(contacts[i].Nom,contact_rechercher) == 0){
                    // printf("Contact trouvé,Nom :%s,email:%s,numTel:%s",contacts[i].Nom,contacts[i].email,contacts[i].numTel);
    return i;

    }
    return -1;

    }



}
void ModifierContact(){

    int x = RechercherContact();
        if(x!=-1){
         printf("Entrer la nouvelle email");
         scanf("%s",contacts[x].email);
         printf("l'email est mise a jour avec succes.\n");
         printf("Entrer le nouveau numero");
         scanf("%s",contacts[x].numTel);
         printf("l'numero de tel est mise a jour avec succes.\n");
  }
    }

int SupprimerContact(){
    int i,j;
    int c = RechercherContact();
 if(c!=-1){
    for(int i=c;i<TotalContact-1;i++){
        contacts[i]=contacts[i+1];
        printf("le contact est supprimer avec succes:\n");
    }
    TotalContact--;

    return 1;
}
}


int main() {



     int d;
    do {
        printf("La gestion de contacts\n");
        printf("1: Ajouter un Contact\n");
        printf("2: Afficher un contact\n");
        printf("3: Rechercher un contact\n");
        printf("4: Modifier Contact\n");
        printf("5: Supprimer un contact\n");
        printf("Quelle est votre demande ? ");
        scanf("%d", &d);

        switch (d) {
            case 1:
            {

                AjouterContact();
                break;
            }
            case 2:
                 AfficherContact();
                break;
            case 3:
                 RechercherContact();
                break;
                case 4:
                 ModifierContact();
                break;
                case 5:
                 SupprimerContact();
                break;
                 default:
                printf("Demande introuvable\n");
                break;
        }
    }while(d!=0);

    return 0;
}
