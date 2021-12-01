#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int a = 1;
    while (a){
        
        time_t t = time(NULL);
        struct tm tm = *localtime(&t);
        int year = tm.tm_year + 1900, month = tm.tm_mon + 1, day = tm.tm_mday;
        printf("Aujourd'hui nous somme le: %02d/%02d/%d\n", day, month, year);
        int c;
        printf("Menu :\n\t - 1 ) Renseigner une date\n\t - 2 ) Lire toutes les dates\n\t - 3 ) Quitter\n");
        printf("Que voulez vous faire ? ");
        scanf("%d", &c);
        if (c == 1)
        {
            while(a){
                char bd[11]; //* Taille max = 10 + 1 char d'arret
                printf("Veuillez renseignez votre date de naissance (format: dd/mm/yyyy ou dd/mm/yy): ");
                scanf("%s", &bd);
                int taille_logique = 0, taille_physique = 3;
                int date[3];
                char *token = strtok(bd, "/");
                while (token != NULL)
                {
                    if (taille_logique < taille_physique)
                    {
                        date[taille_logique] = token;
                        ++taille_logique;
                        token = strtok(NULL, "/");
                    }
                    else
                    {
                        printf("Vous ne pouvez pas rentrer plus d'instruction que pr%cvu", 130);
                        break;
                    }
                }
                if (taille_logique<taille_physique)
                {
                    printf("La date n'est pas valide\n");
                    break;
                }
                int jour = atoi(date[0]);
                int mois = atoi(date[1]);
                int annee;
                if (strlen(date[2]) == 2)
                {
                    annee = 2000 + atoi(date[2]);
                    if (annee > year)
                    {
                        annee = 1900 + atoi(date[2]);
                    }
                }
                else if (strlen(date[2]) == 4)
                {
                    annee = atoi(date[2]);
                }
                else
                {
                    printf("Ann%ce non valide", 130);
                    break;
                }

                printf("Jour : %02d, Mois : %02d, Ann%ce : %d\n", jour, mois, 130, annee);

                if ((jour > 0 && jour <= 31) ^ (mois > 0 && mois <= 12) ^ (annee > 1920 && annee <= year))
                {
                    if (mois == 2)
                    {
                        if (jour == 29)
                        {
                            if (annee % 4 == 0)
                            {
                                if (annee % 100 == 0)
                                {
                                    if ((annee % 400 == 0))
                                    {
                                        if (((jour > day) && (mois >= month) && (annee >= year)) || ((jour > day) && (mois > month) && (annee >= year)) || ((jour > day) && (mois > month) && (annee > year)))
                                        {
                                            printf("La date n'est pas encore pass%c", 130);
                                            break;
                                        }
                                        else
                                        {
                                            printf("La date %02d/%02d/%d a %ctait enregistr%c\n", jour, mois, annee, 130, 130);
                                            FILE *fpointer = fopen("bd.txt", "a");
                                            fprintf(fpointer, "%02d/%02d/%d\n", jour, mois, annee);
                                            fclose(fpointer);
                                        }
                                        break;
                                    }
                                    else
                                    {
                                        printf("La date n'est pas valide\n");
                                        break;
                                    }
                                }
                                else
                                {
                                        if (((jour > day) && (mois >= month) && (annee >= year)) || ((jour > day) && (mois > month) && (annee >= year)) || ((jour > day) && (mois > month) && (annee > year)))
                                        {
                                            printf("La date n'est pas encore pass%c", 130);
                                            break;
                                        }
                                        else
                                        {
                                            printf("La date %02d/%02d/%d a %ctait enregistr%c\n", jour, mois, annee, 130, 130);
                                            FILE *fpointer = fopen("bd.txt", "a");
                                            fprintf(fpointer, "%02d/%02d/%d\n", jour, mois, annee);
                                            fclose(fpointer);
                                        }
                                        break;
                                }
                            }
                            else
                            {
                                printf("La date n'est pas valide\n");
                                break;
                            }
                        }
                        else if ((jour <= 28) && (mois == 2))
                        {
                            if (((jour > day) && (mois >= month) && (annee >= year)) || ((jour > day) && (mois > month) && (annee >= year)) || ((jour > day) && (mois > month) && (annee > year)))
                            {
                                printf("La date n'est pas encore pass%c", 130);
                                break;
                            }
                            else
                            {
                                printf("La date %02d/%02d/%d a %ctait enregistr%c\n", jour, mois, annee, 130, 130);
                                FILE *fpointer = fopen("bd.txt", "a");
                                fprintf(fpointer, "%02d/%02d/%d\n", jour, mois, annee);
                                fclose(fpointer);
                                break;
                            }
                        }
                        else
                        {
                            printf("La date n'est pas valide\n");
                            break;
                        }
                    }
                    if (((jour <= 31) && ((mois == 1) || (mois == 3) || (mois == 5) || (mois == 7) || (mois == 8) || (mois == 10) || (mois == 12))) || (((jour <= 30) && ((mois == 4) || (mois == 6) || (mois == 9) || (mois == 11)))))
                    {
                        if (((jour > day) && (mois >= month) && (annee >= year)) || ((jour > day) && (mois > month) && (annee >= year)) || ((jour > day) && (mois > month) && (annee > year)))
                        {
                            printf("La date n'est pas encore pass%c", 130);
                            break;
                        }
                        else
                        {
                            printf("La date %02d/%02d/%d a %ctait enregistr%c\n", jour, mois, annee, 130, 130);
                            FILE *fpointer = fopen("bd.txt", "a");
                            fprintf(fpointer, "%02d/%02d/%d\n", jour, mois, annee);
                            fclose(fpointer);
                        }
                    }
                    else
                    {
                        printf("La date n'est pas valide\n");
                        break;
                    }

                    if ((jour > day) && (mois >= month) && (annee >= year))
                    {
                        printf("Impossible");
                        break;
                    }
                }
                else
                {
                    printf("La date n'est pas valide\n");
                    break;
                }
            }
        }else if (c == 2)
        {
            char line[255];
            FILE * fpointer = fopen("bd.txt", "r");
            if (fpointer == NULL)
            {
                perror("Le fichier n'est pas présent");
                break;
            }

            fgets(line, 255, fpointer);

            while (!feof(fpointer))
            {
                fgets(line, sizeof(line), fpointer);
                printf("%s", line );
            }

            fclose(fpointer);
        }
        else if(c == 3)
        {
            exit(0);
        }
        else
        {
            printf("Saisie invalide\n");
        }
    }
    return 0;
}