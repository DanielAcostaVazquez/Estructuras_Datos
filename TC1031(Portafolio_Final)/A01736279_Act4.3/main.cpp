/*
Act 4.3 - Actividad Integral de Grafos
Integrantes:
Daniel Francisco Acosta Vázquez | A01736279
Alan Iván FLores Juárez | A01736001
Ulises Hernández Hernández | A01735823
Creado el 22/11/22
Editado el 22/11/2022
Se creó un programa que analiza un archivo bitçora y regresa la red, así como el host con mayor repeticiones
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;
//Estructura de tipo nodoData que almacena fecha, hora, puerto y error
struct nodoData{
 string fecha;
 string hora;
 string puerto;
 string error;
};
//nodoHost mantiene un vector de salidas conjunto a la data
struct nodoHost{
 string data;
 vector<nodoData> salidas;
};
//nodoRed almacena un string data y un vector de salidas
struct nodoRed{
 string data;
 vector<nodoHost> salidas;
};
//Función que verifica la existencia de la red, retornando el índice correspondiente
//Complejidad O(n)
int verificarExistenciaRed(vector<nodoRed> espacioBuscar, string buscado){
 for(int i = 0; i < espacioBuscar.size(); i++){
   if(espacioBuscar[i].data == buscado){
     return i;
   }
 }
 return -1;
};
//Función que verifica la existencia del host, retornando el índice correspondiente
//Complejidad O(n)
int verificarExistenciaHost(vector<nodoHost> espacioBuscar, string buscado){
 for(int i = 0; i < espacioBuscar.size(); i++){
   if(espacioBuscar[i].data == buscado){
     return i;
   }
 }
 return -1;
};
//Funcion que lee el archivo y asigna a variables correspondientes
//Complejidad O(n)
bool obtenerArchivo(string nombre, vector<nodoRed>& bitacora){
 ifstream in(nombre.c_str());
 if(!in){
   cout << "Error al abrir el archivo: " << nombre << endl;
   return false;
 }
 string str;
 while(getline(in, str)){
   if(str.size() > 0){
     int i = 16; //22
     int iRed = 0;
     int iHost = 0;
     string dataRed = str.substr(i, 7);
     if(verificarExistenciaRed(bitacora, dataRed) == -1){
       nodoRed tmp;
       tmp.data = dataRed;
       bitacora.push_back(tmp);
       iRed = (bitacora.size() - 1);
     }
     else{
       iRed = verificarExistenciaRed(bitacora, dataRed);
     }
     i = 24;
     string dataHost = str.substr(i, 7);
     if(verificarExistenciaHost(bitacora[iRed].salidas, dataHost) == -1){
       nodoHost tmpH;
       tmpH.data = dataHost;
       bitacora[iRed].salidas.push_back(tmpH);
       iHost = (bitacora[iRed].salidas.size() - 1);
     }
     else{
       iHost = verificarExistenciaHost(bitacora[iRed].salidas, dataHost);
     }
     i = 0;
     nodoData tmpD;
     tmpD.fecha = str.substr(0, 6);
     i = 7;
     tmpD.hora = str.substr(i, 15);
     i = 32;
     if(str[36] == ' '){
       tmpD.puerto = str.substr(i, 4);
       i += 5;
     }
     else{
       tmpD.puerto = str.substr(i, 5);
       i += 6;
     }
     tmpD.error = str.substr(i);
     bitacora[iRed].salidas[iHost].salidas.push_back(tmpD);

   }
 }
 in.close();
 return true;
}
//Funcion que imprime el grafo
//Complejidad O(n^2)
void printGraph(vector<nodoRed> bitacora){
 for(int i = 0; i < bitacora.size(); i++){
   cout << bitacora[i].data << endl;
   for(int j = 0; j < bitacora[i].salidas.size(); j++){
     cout << bitacora[i].data << "." << bitacora[i].salidas[j].data << endl;
   }
 }
}
//Funcion que regresa un vector con la(s) ip(s) más repetidas dentro del archivo
//Complejidad O(n)
vector<int> maxRed(vector<nodoRed> root){
 vector<int> index;
 int max = 0;
 for(int i = 0; i < root.size(); i++){
   if(root[i].salidas.size() > max){
     max = root[i].salidas.size();
     index.clear();
     index.push_back(i);
   }
   else if(root[i].salidas.size() == max){
     index.push_back(i);
   }
 }
 return index;
}
//Funcion que regresa un vector de vectores con la(s) ip(s) más repetidas dentro del archivo bitácora
//Complejidad O(n^2)
vector<vector<int>> maxHost(vector<nodoRed> root){
 vector<vector<int>> index;
 int max = 0;
 for(int i = 0; i < root.size(); i++){
   for(int j = 0; j < root[i].salidas.size(); j++){
     if(root[i].salidas[j].salidas.size() > max){
       max = root[i].salidas[j].salidas.size();
       index.clear();
       vector<int> v;
       v.push_back(i);
       v.push_back(j);
       index.push_back(v);
     }
     else if(root[i].salidas[j].salidas.size() == max){
       vector<int> v;
       v.push_back(i);
       v.push_back(j);
       index.push_back(v);
     }
   }
 }
 return index;
}

int main(){
 vector<nodoRed> bitacora;
 obtenerArchivo("bitacora2.txt", bitacora);
 vector<int> maxRedes = maxRed(bitacora);
 vector<vector<int>> maxHosts = maxHost(bitacora);
 for(int i = 0; i < maxRedes.size(); i++){
   cout << bitacora[maxRedes[i]].data << endl;
 }
 cout << endl;
 for(int i = 0; i < maxHosts.size(); i++){
   cout << bitacora[maxHosts[i][0]].data << "." << bitacora[maxHosts[i][0]].salidas[maxHosts[i][1]].data << endl;
 }
 return 0;
}
