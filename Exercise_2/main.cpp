#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include "Utils.hpp"

using namespace std;

int main()
{
    string inputFileName = "./data.csv";
    double S = 0;
    size_t n = 0;
    double* w = nullptr;
    double* r = nullptr;

    //Importo i dati
    if (!ImportData(inputFileName, S, n, w, r))
    {
        cerr << "Qualcosa è andato storto con l'importazione" << endl;
        return -1;
    }
    else
    {
        cout << "S = " << fixed << setprecision(2) << S << " n = " << n << endl;
        cout << "w = [ ";
        for (unsigned int i = 0; i < n; i++){
            cout << w[i] << " ";
        }
        cout << "]" << endl;
        cout << "r = [ ";
        for (unsigned int i = 0; i < n; i++){
            cout << r[i] << " ";
        }
        cout << "]" << endl;
    }

    //Opero e stampo i risultati
    double rate = RateOfReturn(n, w, r);
    cout << "Rate of return of the portfolio: " << setprecision(4) << rate << endl;
    double V = FinalValue(S, rate);
    cout << "V: " << setprecision(2) << V << endl;

    //Esporto i dati sul file
    string outputFileName = "./result.txt";
    if (!ExportResult(outputFileName, S, n, w, r, rate, V))
    {
        cerr << "Qualcosa è andato storto con l'esportazione" << endl;
        return -1;
    }
    else
        cout << "Esporazione riuscita" << endl;

    delete[] w;
    delete[] r;

    return 0;
}
