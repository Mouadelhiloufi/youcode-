#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define Max 100

typedef struct {
    int year;
    int month;
    int day;
} date_reserv;

typedef struct {
    char Nom[20];
    char Prenom[20];
    char Tele[20];
    int age;
    char statut[25];
    int id;
    date_reserv reservation_date;
} reservation;

reservation res[Max] = {
    {"Benali", "Ahmed", "0650123456", 30, "Confirmé", 1, {2024, 10, 5}},
    {"El Amrani", "Sara", "0676543210", 28, "En attente", 2, {2024, 10, 10}},
    {"Khalid", "Fatima", "0681234567", 35, "Annulé", 3, {2024, 10, 15}},
    {"Zahra", "Omar", "0699876543", 22, "Confirmé", 4, {2024, 10, 20}},
    {"Lahcen", "Nadia", "0612345678", 40, "Confirmé", 5, {2024, 11, 1}},
    {"Amina", "Rachid", "0658765432", 31, "En attente", 6, {2024, 11, 5}},
    {"Mohammed", "Salma", "0675432109", 27, "Confirmé", 7, {2024, 11, 15}},
    {"Hassan", "Mouna", "0687654321", 29, "Annulé", 8, {2024, 11, 20}},
    {"Youssef", "Hiba", "0698765432", 24, "Confirmé", 9, {2024, 11, 25}},
    {"Samira", "Reda", "0610987654", 36, "En attente", 10, {2024, 12, 1}}
};


    int id=10;
    int number = 10;

void Ajouter() {
    if (number < Max) {
        printf("Donner le nom: ");
        scanf("%s", res[number].Nom);
        printf("Donner le prenom: ");
        scanf("%s", res[number].Prenom);
        printf("Donner le numero de telephone qui commence par '06' ou '07': ");
        scanf("%s", res[number].Tele);
        printf("Donner l'age: ");
        scanf("%d", &res[number].age);
        printf("Donner le statut: ");
        scanf("%s", res[number].statut);
        printf("Donner le jour de reservation 'dd' : ");
        scanf("%d", &res[number].reservation_date.day);
        printf("Donner le mois de reservation 'mm': ");
        scanf("%d", &res[number].reservation_date.month);
        printf("Donner l'annee de reservation 'yyyy': ");
        scanf("%d", &res[number].reservation_date.year);
        res[number].id = ++id;
        number++;
        printf("Reservation ajoutee avec succes.\n");
    } else {
        printf("Les reservations sont terminees.\n");
    }
}

void Modifier() {
    int s_reference;
    printf("Donner la reference: ");
    scanf("%d", &s_reference);

    for (int i = 0; i < number; i++) {
        if (res[i].id == s_reference) {
            printf("Donner le nouveau nom: ");
            scanf("%s", res[i].Nom);
            printf("Donner le nouveau prenom: ");
            scanf("%s", res[i].Prenom);
            printf("Donner le nouveau numero de telephone: ");
            scanf("%s", res[i].Tele);
            printf("Donner le nouveau age: ");
            scanf("%d", &res[i].age);
            printf("Donner le nouveau statut: ");
            scanf("%s", res[i].statut);
            printf("Donner la nouvelle date de reservation (jour mois annee): ");
            scanf("%d %d %d", &res[i].reservation_date.day, &res[i].reservation_date.month, &res[i].reservation_date.year);
            printf("Reservation modifiee avec succes.\n");
            return;
        }
    }
    printf("Reservation non trouvee.\n");
}

void Affichage_res() {
    if (number == 0) {
        printf("Aucune reservation a afficher.\n");
        return;
    }

    printf("Liste des reservations:\n");
    for (int i = 0; i < number; i++) {
        printf("ID: %d, Nom: %s, Prenom: %s, Tele: %s, Age: %d, Statut: %s, Date: %d/%d/%d\n",
               res[i].id, res[i].Nom, res[i].Prenom, res[i].Tele, res[i].age, res[i].statut,
               res[i].reservation_date.day, res[i].reservation_date.month, res[i].reservation_date.year);
    }
}

void Suppression() {
    int s_reference;
    printf("Donner la reference a supprimer: ");
    scanf("%d", &s_reference);

    for (int i = 0; i < number; i++) {
        if (res[i].id == s_reference) {
            for (int j = i; j < number - 1; j++) {
                res[j] = res[j + 1];
            }
            number--;
            printf("Reservation supprimee avec succes.\n");
            return;
        }
    }
    printf("Reservation non trouvee.\n");
}

void tri_par_nom() {
    reservation temp;

    for (int i = 0; i < number - 1; i++) {
        for (int j = 0; j < number - i - 1; j++) {
            if (strcmp(res[j].Nom, res[j + 1].Nom) > 0) {

                temp = res[j];
                res[j] = res[j + 1];
                res[j + 1] = temp;
            }
        }
    }
    Affichage_res();
}


void recherche_nom(){

   char name_n[25];
    printf("  donner le nom  ");
    scanf("%s",&name_n);

    for(int i=0;i<number;i++){

     if (strcmp(res[i].Nom, name_n) == 0) {
        printf("%s\n", res[i].Nom);
        printf("%s\n", res[i].Prenom);
        printf("%s\n", res[i].Tele);
        printf("%d\n", res[i].age);
        printf("%s\n", res[i].statut);
        printf("%d\n", res[i].id);
        printf("%d/%d/%d\n", res[i].reservation_date.year, res[i].reservation_date.month, res[i].reservation_date.day);
    }

        }
    }
int main() {
    int choix;

    while (1) {
        printf("\nMenu:\n");
        printf("1: Ajouter\n");
        printf("2: Modifier\n");
        printf("3: Supprimer\n");
        printf("4: Afficher\n");
        printf("5: Trie par nom\n");
        printf("6: Recherche par nom\n");
        printf("7: Quitter\n");
        printf("Choix: ");
        scanf("%d", &choix);

        switch (choix) {
            case 1: Ajouter(); break;
            case 2: Modifier(); break;
            case 3: Suppression(); break;
            case 4: Affichage_res(); break;
            case 5:tri_par_nom(); break;
            case 6:recherche_nom(); break;
            case 7: return 0;
            default: printf("Choix invalide. Veuillez reessayer.\n");
        }
    }
    return 0;
}
