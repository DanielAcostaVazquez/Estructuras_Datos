#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <limits>

using namespace std;

int MesToInt(string mes){
  if(mes == "Jan") return 1;
  else if (mes == "Feb") return 2;
  else if (mes == "Mar") return 3;
  else if (mes == "Apr") return 4;
  else if (mes == "May") return 5;
  else if (mes == "Jun") return 6;
  else if (mes == "Jul") return 7;
  else if (mes == "Aug") return 8;
  else if (mes == "Sep") return 9;
  else if (mes == "Oct") return 10;
  else if (mes == "Nov") return 11;
  else if (mes == "Dec") return 12;
  return -1;
};

string IntToMes(int mes){
  if(mes == 1) return "Jan";
  else if (mes == 2) return "Feb";
  else if (mes == 3) return "Mar";
  else if (mes == 4) return "Apr";
  else if (mes == 5) return "May";
  else if (mes == 6) return "Jun";
  else if (mes == 7) return "Jul";
  else if (mes == 8) return "Aug";
  else if (mes == 9) return "Sep";
  else if (mes == 10) return "Oct";
  else if (mes == 11) return "Nov";
  else if (mes == 12) return "Dec";
  return "NUL";
};

class Log{
public:
Log(int mes, int dia, int hora, int min, int seg, int idR1, int idR2, int idR3, int idH, int puerto, string fallo){
  this->mes = mes;
  this->dia = dia;
  this->hora = hora;
  this->min = min;
  this->seg = seg;
  this->idR1 = idR1;
  this->idR2 = idR2;
  this->idR3 = idR3;
  this->idH = idH;
  this->puerto = puerto;
  this->fallo = fallo;
}
void setMes(int mes){
  this->mes = mes;
}
void setDia(int dia){
  this->dia = dia;
}
void setHora(int hora){
  this->hora = hora;
}
void setMinuto(int min){
  this->min = min;
}
void setSegundo(int seg){
  this->seg = seg;
}
void setIdR1(int idR1){
  this->idR1 = idR1;
}
void setIdR2(int idR2){
  this->idR2 = idR2;
}
void setIdR3(int idR3){
  this->idR3 = idR3;
}
void setIdH(int idH){
  this->idH = idH;
}
void setPuerto(int puerto){
  this->puerto = puerto;
}
void setFallo(string fallo){
  this->fallo = fallo;
}
int getMes(){
  return mes;
}
int getDia(){
  return dia;
}
int getHora(){
  return hora;
}
int getMinuto(){
  return min;
}
int getSegundo(){
  return seg;
}
int getIdR1(){
  return idR1;
}
int getIdR2(){
  return idR2;
}
int getIdR3(){
  return idR3;
}
int getIdH(){
  return idH;
}
int getPuerto(){
  return puerto;
}
string getFallo(){
  return fallo;
}
void printLog(){
  cout << IntToMes(mes) << " " << dia << " " << hora << ":" << min << ":" << seg << " " << idR1 << "." << idR2 << "." << idR3 << "." << idH << ":" << puerto << " " << fallo << endl;
}

void saveLog(vector<Log> n){
  ofstream file;
  file.open("sorted.txt");
  for(int i = 0; i < n.size(); i++){
      file << IntToMes(n[i].mes) << " " << n[i].dia << " " << n[i].hora << ":" << n[i].min << ":" << n[i].seg << " " << n[i].idR1 << "." << n[i].idR2 << "." << n[i].idR3 << "." << n[i].idH << ":" << n[i].puerto << " " << n[i].fallo << endl;
    }
  file.close();
}
bool operator < (Log &l){
  if(this->mes <= l.mes){
    if(this->mes == l.mes){
      if(this->dia <= l.dia){
        if(this->dia == l.dia){
          if(this->hora <= l.hora){
            if(this->hora == l.hora){
              if(this->min <= l.min){
                if(this->min == l.min){
                  if(this->seg <= l.seg){
                    if(this->seg == l.seg){
                      if(this->idR1 <= l.idR1){
                        if(this->idR1 == l.idR1){
                          if(this->idR2 <= l.idR2){
                            if(this->idR2 == l.idR2){
                              if(this->idR3 <= l.idR3){
                                if(this->idR3 == l.idR3){
                                  if(this->idH <= l.idH){
                                    if(this->idH == l.idH){
                                      if(this->puerto < l.puerto) return true;
                                      else return false;
                                    }
                                    return true;
                                  }
                                  return false;
                                }
                                return true;
                              }
                              return false;
                            }
                            return true;
                          }
                          return false;
                        }
                        return true;
                      }
                      return false;
                    }
                    return true;
                  }
                  return false;
                }
                return true;
              }
              return false;
            }
            return true;
          }
          return false;
        }
        return true;
      }
      return false;
    }
    return true;
  }
  return false;
}

bool operator == (Log &l){
  if(this->mes == l.mes && this->dia == l.dia && this->hora == l.hora && this->min == l.min && this->seg == l.seg && this->idR1 == l.idR1 && this->idR2 == l.idR2 && this->idR3 == l.idR3 && this->idH == l.idH && this->puerto == l.puerto) return true;
  else return false;
}
private:
int mes, dia, hora, min, seg, idR1, idR2, idR3, idH, puerto;
string fallo;
};

bool obtenerArchivo(string nombre, vector<Log>& bitacora){
  ifstream in(nombre.c_str());
  if(!in){
    cout << "Error al abrir el archivo: " << nombre << endl;
    return false;
  }
  string str;
  while(getline(in, str)){
    if(str.size() > 0){
      int i = 0;
      int m = MesToInt(str.substr(i,3));
      i+=4;
      int d = 0;
      if((str.substr(i+1,1)) == " "){
        d = stoi(str.substr(i,1));
        i+=2;
      }
      else{
        d = stoi(str.substr(i,2));
        i+=3;
      }
      int h = stoi(str.substr(i,2));
      i+=3;
      int mi = stoi(str.substr(i,2));
      i+=3;
      int s = stoi(str.substr(i,2));
      i+=3;
      int r1 = 0;
      if((str.substr(i+1,1)) == "."){
        r1 = stoi(str.substr(i,1));
        i+=2;
      }
      else if((str.substr(i+2,1)) == "."){
        r1 = stoi(str.substr(i,2));
        i+=3;
      }
      else{
        r1 = stoi(str.substr(i,3));
        i+=4;
      }
      int r2 = 0;
      if((str.substr(i+1,1)) == "."){
        r2 = stoi(str.substr(i,1));
        i+=2;
      }
      else if((str.substr(i+2,1)) == "."){
        r2 = stoi(str.substr(i,2));
        i+=3;
      }
      else{
        r2 = stoi(str.substr(i,3));
        i+=4;
      }
      int r3 = 0;
      if((str.substr(i+1,1)) == "."){
        r3 = stoi(str.substr(i,1));
        i+=2;
      }
      else if((str.substr(i+2,1)) == "."){
        r3 = stoi(str.substr(i,2));
        i+=3;
      }
      else{
        r3 = stoi(str.substr(i,3));
        i+=4;
      }
      int host = 0;
      if((str.substr(i+1,1)) == ":"){
        host = stoi(str.substr(i,1));
        i+=2;
      }
      else if((str.substr(i+2,1)) == ":"){
        host = stoi(str.substr(i,2));
        i+=3;
      }
      else{
        host = stoi(str.substr(i,3));
        i+=4;
      }
      int p = stoi(str.substr(i,4));
      i+=5;
      string f = str.substr(i);
      Log Objeto(m,d,h,mi,s,r1,r2,r3,host,p,f);
      bitacora.push_back(Objeto);
    }
  }
  in.close();
  return true;
}

void uneMerge(int inicio, int mitad, int fin, vector<Log>& bitacora){
  int i, j;
  vector<Log> aux;
  i = inicio;
  j = mitad + 1;
  while(i<=mitad && j<=fin){
    if(bitacora[i] < bitacora[j]){
      aux.push_back(bitacora[i]);
      i++;
    }
    else{
      aux.push_back(bitacora[j]);
      j++;
    }
  }

  while(i <= mitad){
    aux.push_back(bitacora[i]);
    i++;
  }

  while(j <= fin){
    aux.push_back(bitacora[j]);
    j++;
  }

  for(int c = inicio; c <= fin; c++){
    bitacora[c] = aux[c - inicio];
  }
}

void MergeSort(int inicio, int fin, vector<Log>& bitacora){
  if(inicio < fin){
  int mitad = (inicio + fin)/2;
  MergeSort(inicio, mitad, bitacora);
  MergeSort(mitad+1, fin, bitacora);
  uneMerge(inicio, mitad, fin, bitacora);
  }
}

int busqueda(vector<Log> n, int mes, int dia){
  int centro, min, max;
  Log valorCentral(0,0,0,0,0,0,0,0,0,0," ");
  Log resultado(mes, dia, 0, 0, 0, 0, 0, 0, 0, 0, " ");
  min = 0;
  max = (n.size() - 1);
  while (min <= max){
    centro = (min+max)/2;
    valorCentral = n[centro];
    if (resultado == valorCentral) return centro;
    if(resultado < valorCentral){
      if(valorCentral == n[0]) return 0;
      if(n[centro - 1] < resultado) return centro;
    }
    if (resultado < valorCentral){
      max = centro - 1;
    }
    else{
      min = centro + 1;
    }
  }

  return-1;
}

int main() {
  vector<Log> bitacora;
  bool resultado = obtenerArchivo("bitacora.txt", bitacora);
  MergeSort(0,(bitacora.size() - 1), bitacora);
  ofstream file;
  file.open("sorted.txt");
  if(resultado){
    bitacora[0].saveLog(bitacora);
    int userInM = 0;
    int userInD = 0;
    int userFM = 0;
    int userFD = 0;
    while(userInM < 1 || userInM > 12){
      cout << "Ingresa el mes inicial que deseas buscar: " << endl;
      cin >> userInM;
      if(cin.fail()){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
      }
    }
    while(userInD < 1 || userInD > 31){
      cout << "Ingresa el dia inicial que deseas buscar: " << endl;
      cin >> userInD;
      if(cin.fail()){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
      }
    }
    while(userFM < 1 || userFM > 12){
      cout << "Ingresa el mes final que deseas buscar: " << endl;
      cin >> userFM;
      if(cin.fail()){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
      }
    }
    while(userFD < 1 || userFD > 31){
      cout << "Ingresa el dia final que deseas buscar: " << endl;
      cin >> userFD;
      if(cin.fail()){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
      }
    }
    int b = busqueda(bitacora, userInM, userInD);
    Log stop(userFM,userFD,23,59,59,999,999,999,999,9999," ");
    for(int i = b; i < bitacora.size(); i++){
      if(stop < bitacora[i]) break;
      bitacora[i].printLog();
    }
  }
  file.close();

}
