/*
Act 5.2 - Actividad Integral sobre el uso de códigos hash
Integrantes:
Daniel Francisco Acosta Vázquez | A01736279
Alan Iván FLores Juárez | A01736001
Ulises Hernández Hernández | A01735823
Creado el 26/11/22
Editado el 27/11/2022
Programa que lee un archivo "bitacora2.txt" y crea una tabla hash cuya clave es el dominio y contene valores del resumen de ese dominio
*/
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Host {
  int host1;
  int host2;
};

struct Ip {
  string dominio_clave;
  int dominio1;
  int dominio2;
  vector<Host> host;
  int contador;
};

// Funcion que obtiene la posición dentro del vector
// Complejidad O(1)
int getHash(string dominio) {
  int sum = 0;
  for (int i = 0; i < dominio.size(); i++) {
    sum = sum + int(dominio[i]);
  }
  return sum % 32749;
}
//Funcion que inserta en el vector el valor del host
//Complejidad O(n)
void insHost(vector<Host> &vect, Host valor){
  for(int i = 0; i < vect.size(); i++){
    if(vect[i].host1 == valor.host1 && vect[i].host2 == valor.host2){
      return;
    }
  }
  for(int i = 0; i < vect.size(); i++){
    if(vect[i].host1 > valor.host1){
      vect.insert(vect.begin() + i, valor);
      return;
    }
    else if(vect[i].host1 == valor.host1 && vect[i].host2 > valor.host2){
      vect.insert(vect.begin() + i, valor);
      return;
    }
  }
  vect.push_back(valor);
  return;
};

// Funcion que inserta un elemento al vector
// Complejidad O(n)
void ins(vector<Ip> &vect, vector<int> &bandera, Ip direccion, int &contador) {
  int pos = getHash(direccion.dominio_clave);
  if (contador < 32749) {
    if (bandera[pos] != 1) {
      vect[pos] = direccion;
      vect[pos].contador = 1;
      bandera[pos] = 1;
      contador += 1;
    }
    else if(contador < 32749) {
      while (bandera[pos] == 1) {
        if (vect[pos].dominio_clave == direccion.dominio_clave) {
          insHost(vect[pos].host, direccion.host[0]);
          vect[pos].contador += 1;
          contador -= 1;
          return;
        } else {
          if (pos == 32748) {
            pos = 0;
          } else {
            pos += 1;
          }
          if (bandera[pos] != 1) {
            vect[pos] = direccion;
            vect[pos].contador += 1;
            bandera[pos] = 1;
            return;
          }
        }
      }
      bandera[pos] = 1;
      contador += 1;
    }
  }
  if (contador == 32749) {
    cout << "Tabla llena, imposible meter más datos" << endl;
  }
}
//Funcion que lee las Ips del archivo "bitacora2.txt"
//Complejidad O(n)
bool obtenerArchivo(string nombre, vector<Ip> &bitacora, vector<int> &bandera, int &contador) {
  ifstream in(nombre.c_str());
  if (!in) {
    cout << "Error al abrir el archivo: " << nombre << endl;
    return false;
  }
  string str;
  while (getline(in, str)) {
    if (str.size() > 0) {
      if (contador < 32749) {
        Ip nueva_direccion;
        nueva_direccion.dominio1 = stoi(str.substr(16, 3));
        nueva_direccion.dominio2 = stoi(str.substr(20, 3));
        nueva_direccion.dominio_clave = to_string(nueva_direccion.dominio1) + "." + to_string(nueva_direccion.dominio2);
        nueva_direccion.contador = 0;
        Host h;
        h.host1 = stoi(str.substr(24, 3));
        h.host2 = stoi(str.substr(28, 3));
        nueva_direccion.host.push_back(h);
        ins(bitacora, bandera, nueva_direccion, contador);
      } else {
        break;
      }
    }
  }
  in.close();
  return true;
}

// Funcion de busqueda, imprime segun sea necesario
// Complejidad O(1)
void search(vector<Ip> &vect, vector<int> &bandera, string clave) {
  int pos = getHash(clave);
  if (bandera[pos] == 1 && vect[pos].dominio_clave == clave){
    cout << clave << endl;
    cout << vect[pos].contador << endl;
    cout << vect[pos].host.size() << endl;
  for (int i = 0; i < vect[pos].host.size(); i++) {
    cout << vect[pos].dominio_clave << "." << vect[pos].host[i].host1 << "." << vect[pos].host[i].host2 << endl;
  }
  cout << endl;
  return;
}
  else if (bandera[pos] == 2 || (bandera[pos] == 1 && vect[pos].dominio_clave != clave)) {
    int pos_inicial = pos;
    do {
      if (pos == 32748) {
        pos = 0;
      } else {
        pos += 1;
      }
      if (bandera[pos] == 1) {
        if (vect[pos].dominio_clave == clave) {
          cout << clave << endl;
          cout << vect[pos].contador << endl;
          cout << vect[pos].host.size() << endl;
        for (int i = 0; i < vect[pos].host.size(); i++) {
          cout << vect[pos].dominio_clave << "." << vect[pos].host[i].host1 << "." << vect[pos].host[i].host2 << endl;
        }
          cout << endl;
          return;
        }
      }
    } while ((bandera[pos] == 2 || bandera[pos] == 1) && pos_inicial != pos);
    cout << "dato no encontrado" << endl;
    return;
  }
  else {
    cout << "dato no encontrado" << endl;
    return;
  }
}

int main() {
  vector<Ip> bitacora(32749);
  vector<int> bandera(32749, 0);
  int contador = 0;
  if(obtenerArchivo("bitacora2.txt", bitacora, bandera, contador)){
    int cantidad_ips;
    cin >> cantidad_ips;
    for(int i = 0; i < cantidad_ips; i++){
      string ip_clave;
      cin >> ip_clave;
      search(bitacora, bandera, ip_clave);
    }
  }
}
