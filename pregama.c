#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <libxml/parser.h>

double double_retournement_hz(double, double); /* Calcul du double retournement pour Hz */
int validation_angle(double);                  /* Test de validation des valeurs angulaires */
double double_retournement_v(double, double);  /* Calcul du double retournement pour V */


int main(int nbarg, char *argv[])
{
    char *nomFichierEntree;
    char *nomFichierSortie;
    
    if(nbarg!=3)
    {        
        printf("pregama <input_file.xml> <output_file.xml>\n");
        exit(EXIT_FAILURE);
    }


    nomFichierEntree = argv[1];
    nomFichierSortie = argv[2];
    
    printf("%s\n", nomFichierEntree);
    printf("%s\n", nomFichierSortie);
    
    /*
    double angle_1 = 0;
    double angle_2 = 0;
    double angle_3 = 0;
    
    printf("Entrez deux valeurs d'angles: ");
    if (scanf("%lf %lf", &angle_1, &angle_2) !=2)
    {
        return EXIT_FAILURE;
        abort();
    }
    else
    {
        angle_3 = double_retournement_hz(angle_1, angle_2);
        printf("%f\n", angle_3);
    }
    */
     
    exit(EXIT_SUCCESS);

}


/* Calcul de la valeur moyenne d'un angle horizontal par double retournement' */
double double_retournement_hz(double hz_cercle_I, double hz_cercle_II)
{
    double hz_corrige = -1;
    
    if(validation_angle(hz_cercle_I) && validation_angle(hz_cercle_II))
    {
        if (hz_cercle_II > 200)
        {
            hz_corrige = (hz_cercle_I+(hz_cercle_II-200))/2;
            return hz_corrige;
        }
        else if (hz_cercle_II < 200)
        {
            hz_corrige = (hz_cercle_I+(hz_cercle_II+200))/2;
            return hz_corrige;
        }
        else if ((hz_cercle_II==200) && (hz_cercle_I > 200))
        {
            hz_corrige = (hz_cercle_I+hz_cercle_II+200)/2;
            return hz_corrige;
        }
        else if ((hz_cercle_II==200) && (hz_cercle_I<=200))
        {
            hz_corrige = (hz_cercle_I+hz_cercle_II-200)/2;
            return hz_corrige;
        }
        else
        {
            hz_corrige = -1;
            return hz_corrige;
        }
    }
    else
    {
        hz_corrige = -1;
        return hz_corrige;
    }
    
}

/* Calcul de la valeur moyenne d'un angle vertical par double retournement' */
double double_retournement_v(double v_cercle_I, double v_cercle_II)
{
    double v_corrige = -1;
    
    /* On vérifie que 0 <= v_cercle_I < 200 et que 200 < v_cercle_II < 400 */ 
    if((validation_angle(v_cercle_I) && v_cercle_I<200) && (validation_angle(v_cercle_II) && v_cercle_II>200))
    {
        v_corrige = (v_cercle_I+(400-v_cercle_II))/2;
        return v_corrige;
    }
    else
    {
        v_corrige = -1;
        return v_corrige;
    }
}

/* La fonction vérifie que la valeur angulaire est comprise entre 0 et 400 */
int validation_angle(double angle)
{
    if ((angle>=0) && (angle<400))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
