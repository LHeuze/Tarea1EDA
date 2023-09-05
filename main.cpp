#include <iostream>
#include <fstream>
#include <ctime>
#include <chrono>
#include "sorts.hpp"

using namespace std;
long getElapsedTime(chrono::time_point<chrono::high_resolution_clock> t1,
		chrono::time_point<chrono::high_resolution_clock> t2){
	auto int_ms = chrono::duration_cast<chrono::milliseconds>(t2 - t1);
	return static_cast<long>(int_ms.count());
}

int main (){
    vector<int> RUTs;
    string Narchivo;
    ifstream archivo;
    string tipoSort;
    
    
    cout << "Ingrese nombre del archivo a leer: ";
    cin >> Narchivo;
    Narchivo = "../"+Narchivo;
    string salida = Narchivo+".sorted";
    
    
    cout << "Ingrese tipo de sort: ";
    cin >> tipoSort;
    
    // Sacar datos de archivo de inputs y ponerlos en vector RUTs
    archivo.open(Narchivo);
    if (archivo.fail()){
        cout << "Error al abrir el archivo" << endl;
        return 1;
    }
    
    string linea;
    int dato;
    while (getline(archivo,linea)){        
        dato = stoi(linea);
        RUTs.push_back(dato);
    }
    archivo.close();
    
    
    // Algoritmo 
    auto start = chrono::high_resolution_clock::now();
    if (tipoSort == "Q"){
        sort1::quickSort(RUTs,0,RUTs.size());
    }
    else if(tipoSort == "I") {
        sort1::insertSort(RUTs);
    }
    else if(tipoSort == "M"){
        sort1::mergeSort(RUTs,0,RUTs.size()-1);
    }
    else if (tipoSort == "R"){
        sort1::radixSort(RUTs);
    }
    
    auto end = chrono::high_resolution_clock::now();
    long elapsedTime = getElapsedTime(start, end);
    cout << "Tiempo transcurrido: " << elapsedTime << " milisegundos" << endl;
    
    
    
    // Copiar vector RUTs a archivo de salida
    ofstream Sarchivo(salida);
    for(int i = 0; i<RUTs.size();i++){
        Sarchivo << RUTs[i]<< endl;
    }
    Sarchivo.close();
    return 0;
}