#include <stdio.h>

int main() {
    float km_h, m_s;

    printf("Entrez la vitesse en kilom�tres par heure (km/h) : ");
    scanf("%f", &km_h);

    m_s = km_h * 0.27778;

    printf("La vitesse en m�tres par seconde (m/s) est : %.2f\n", m_s);
    
    return 0;
}
