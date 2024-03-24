#include <iostream>
#include <fstream>

using namespace std;

// scrivo la funzione per mappare i valori in [1,5] in [-1,2]
double mappa(double value)
{
    return ((value * 3) - 7)/4;
}

// scrivo la funzione per calcolare la media dei primi i valori
double calcolo_media(double total, int count)
{
    if (count == 0)
    {
        return 0;
    }
    return total / count;
}

int main()
{
    string nome_File = "data.csv";
    fstream fstr(nome_File);
    if(fstr.fail())
    {
        std::cerr << "File not found" << std::endl;
        return 1;
    }
    std::ofstream outFile("result.csv");


    double total = 0;
    int count = 0;
    double value;

    outFile <<"# N Mean"<<"\n";

    while (fstr >> value)
    {
        double valore_mappato = mappa(value);
        total += valore_mappato;
        count++;
        double media = calcolo_media(total, count);

        outFile << count << " " << media << "\n";
    }

    fstr.close();
    outFile.close();



    return 0;
}
