#pragma once
#include "iostream"

using namespace std;

//ImportData legge i dati in input dal file di input
// inputfilePath: nome del percorso del file di input
// S: quantità investita all'inizio del periodo
// n: taglia finale dei vettori
// w: vettore delle frazioni di S
// r: vettore degli interessi
// ritorna il risultato dell'operazione, vero se ha avuto successo, falso altrimenti
bool ImportData(const string& inputFilePath,
                double& S,
                size_t& n,
                double*& w,
                double*& r);


// RateOfReturn calcola il tasso di rendimento
// n: taglia finale dei vettori
// w: vettore delle frazioni di S
// r: vettore degli interessi
double RateOfReturn(const size_t& n,
                    const double* const& w,
                    const double* const& r);


// FinalValue calcola il valore finale del portafoglio
// S: quantità investita all'inizio del periodo
// rate: tasso di rendimento
double FinalValue(const double& S,
                  const double& rate);


// ExportResult esporta i risultati nel file di output
// outputFilePath: nome del percorso del file di output
// S: quantità investita all'inizio del periodo
// n: taglia finale dei vettori
// w: vettore delle frazioni di S
// r: vettore degli interessi
// rate: tasso di rendimento
// V: valore finale del portafoglio
// ritorna il risultato dell'operazione, vero se ha avuto successo, falso altrimenti
bool ExportResult(const string& outputFilePath,
                  const double& S,
                  const size_t& n,
                  const double* const& w,
                  const double* const& r,
                  const double& rate,
                  const double& V);
