#include <stdio.h>
#include <math.h>


int main(void) {
    float Lab, Lbc, Lca, xA, xB, xC, yA, yB, yC, area, perimeter, s;

    printf("Enter x- and y-coordinates of point A:- ");
    scanf("%f %f", &xA, &yA);
    printf("Enter x- and y-coordinates of point B:- ");
    scanf("%f %f", &xB, &yB);
    printf("Enter x- and y-coordinates of point C:- ");
    scanf("%f %f", &xC, &yC);

    Lab = sqrt(pow(xA - xB, 2) + pow(yA - yB, 2));
    Lbc = sqrt(pow(xB - xC, 2) + pow(yB - yC, 2));
    Lca = sqrt(pow(xC - xA, 2) + pow(yC - yA, 2));
    perimeter = Lab + Lbc + Lca;
    s = perimeter / 2;
    area = sqrt(s * (s - Lab) * (s - Lbc) * (s - Lca));

    printf("Length of AB is %.3f\n", Lab);
    printf("Length of BC is %.3f\n", Lbc);
    printf("Length of CA is %.3f\n", Lca);
    printf("Perimeter is %.3f\n", perimeter);
    printf("Area is %.3f\n", area);
    return 0;
}

