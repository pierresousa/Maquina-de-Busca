#include <iostream>
#include <string>
#include <dirent.h>
#include <vector>
#include "list_database.h"

using namespace std;

vector <string> requestArchievs(){

    DIR *diretorio;
    struct dirent *lsdir;
    string arquivo, line;
    int tamanho, contador=0;
    vector <string> arquivos;

    diretorio = opendir("../database/");

    while ( ( lsdir = readdir(diretorio) ) != NULL )
    {
        arquivo = lsdir->d_name;
        tamanho = arquivo.length();
        if( arquivo[tamanho-3]=='t' && arquivo[tamanho-2]=='x' && arquivo[tamanho-1]=='t'){
            contador++;
            arquivos.push_back(lsdir->d_name);
        }
        
    }

    closedir(diretorio);

    return arquivos;
}