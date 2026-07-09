#include <array>
#include <cmath>
#include <iostream>
#include <vector>

constexpr int ANZAHL_VEKTOREN = 3;
constexpr int DIMENSION = 3;

std::vector<std::vector<double>> globalBasis(ANZAHL_VEKTOREN, std::vector<double>(DIMENSION, 0.0));
std::vector<std::vector<double>> onbbasis(ANZAHL_VEKTOREN, std::vector<double>(DIMENSION, 0.0));

double skalarprodukt(std::vector<double> a, std::vector<double> b) {
    return a[0] * b[0] + a[1] * b[1] + a[2] * b[2];
}

std::vector<double> normieren(std::vector<double> n) {
    double betrag = std::sqrt(skalarprodukt(n, n));
    if (betrag > 0.0) {
        for (int i = 0; i < DIMENSION; i++) {
            n[i] = n[i] / betrag;
        }
    }
    return n;
}

int main() {
    globalBasis[0] = {0.2, 5, 0};
    globalBasis[1] = {0, 1.5, 0};
    globalBasis[2] = {7, 0, 13.666};
    //scchritt 1 b1 normieren
    std::vector<double> temp = globalBasis[0];
    onbbasis[0] = normieren(temp);//q1
    //schritt 2 b2 senktrecht stellen und dann normieren
    temp = globalBasis[1];
    for (int i = 0; i < DIMENSION; i++) {
        temp[i] = globalBasis[1][i]-skalarprodukt(globalBasis[1], onbbasis[0]) * onbbasis[0][i];
    }
    temp = normieren(temp);
    onbbasis[1]= temp;
    //schritt k
    for (int k = 0; k < ANZAHL_VEKTOREN; k++) {

        // 1. Wir starten mit dem aktuellen schiefen Vektor b_k
        std::vector<double> temp = globalBasis[k];

        // 2. Das Summenzeichen: Ziehe alle Schatten der BISHIERIGEN (i < k) fertigen Vektoren ab
        for (int i = 0; i < k; i++) {
            double projektionsFaktor = skalarprodukt(globalBasis[k], onbbasis[i]);

            // Jetzt ziehen wir den Schatten komponentenweise von temp ab
            temp[0] = temp[0] - projektionsFaktor * onbbasis[i][0];
            temp[1] = temp[1] - projektionsFaktor * onbbasis[i][1];
            temp[2] = temp[2] - projektionsFaktor * onbbasis[i][2];
        }

        // 3. Den bereinigten Vektor normieren (auf Länge 1 bringen)
        double laenge = std::sqrt(skalarprodukt(temp, temp));
        if (laenge > 0.0) {
            onbbasis[k][0] = temp[0] / laenge;
            onbbasis[k][1] = temp[1] / laenge;
            onbbasis[k][2] = temp[2] / laenge;
        }
    }

    for (int k = 0; k < ANZAHL_VEKTOREN; k++) {
        std::cout << "q" << (k+1) << ": ["
                  << onbbasis[k][0] << ", "
                  << onbbasis[k][1] << ", "
                  << onbbasis[k][2] << "]\n";
    }
    return 0;
}