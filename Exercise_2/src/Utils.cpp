#include "Utils.hpp"

#include "iostream"
#include "fstream"
#include "sstream"
#include<iomanip>

using namespace std;

bool ImportData(const string& inputFilePath,
                double& S,
                size_t& n,
                double*& w,
                double*& r)
{
    //Apri il file
    ifstream file;
    file.open(inputFilePath);

    if (file.fail())
    {
        cerr << "L'apertura del file non è riuscita" << endl;
        return false;
    }

    //Prendi i dati
    int count = 0;
    char separatore = ';';
    string line;
    while (!file.eof())
    {
        getline(file, line);
        if(line[0] == 'S'){
            istringstream convertS;
            convertS.str(line.substr(2));
            convertS >> S;
        }
        else if(line[0] == 'n'){
            istringstream convertN;
            convertN.str(line.substr(2));
            convertN >> n;
        }
        else if(line[0] == 'w'){
            w = new double[n];
            r = new double[n];
        }
        else if (line[0] == '0'){

            int index = 0;
            while(line[index] != separatore){
                index++;
            }
            string valore1_str = line.substr(0, index);
            istringstream convertNum1(valore1_str);
            convertNum1 >> w[count];

            string valore2_str = line.substr(index+1);
            istringstream convertNum2(valore2_str);
            convertNum2 >> r[count];

            count++;
        }

    }

    // Chiudi il file
    file.close();

    return true;

}


double RateOfReturn(const size_t& n,
                    const double* const& w,
                    const double* const& r)
{
    double rate = 0;
    for (unsigned int i = 0; i < n; i++)
        rate += w[i] * r[i];
    return rate;
}


double FinalValue(const double& S,
                  const double& rate)
{
    double V = 0;
    V = (1+rate)*S;
    return V;
}


bool ExportResult(const string& outputFilePath,
                  const double& S,
                  const size_t& n,
                  const double* const& w,
                  const double* const& r,
                  const double& rate,
                  const double& V)
{

    // Apri il file
    ofstream file;
    file.open(outputFilePath);

    if (file.fail())
    {
        cerr << "L'apertura del file non è riuscita" << endl;
        return false;
    }

    //Esporta i dati
    file << "S = " << fixed << setprecision(2) << S << " n = " << n << endl;

    file << "w = [ ";
    for (unsigned int i = 0; i < n; i++){
        file << w[i] << " ";
    }
    file << "]" << endl;

    file << "r = [ ";
    for (unsigned int i = 0; i < n; i++){
        file << r[i] << " ";
    }
    file << "]" << endl;

    file << "Rate of return of the portfolio: " << setprecision(4) << rate << endl;
    file << "V: " << setprecision(2) << V << endl;

    // Chiudi il file
    file.close();

    return true;
}

