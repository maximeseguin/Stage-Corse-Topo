#include <stdio.h>
#include <stdlib.h>

double double_retournement_hz(double, double); /* Calcul du double retournement */
int validation_angle(double);                  /* Test de validation des valeurs angulaires */

int main(void)
{
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
        printf("%lf\n", angle_3);
    };
     
    return 0;
}

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
        };
    }
    else
    {
        hz_corrige = -1;
        return hz_corrige;
    };
    
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
