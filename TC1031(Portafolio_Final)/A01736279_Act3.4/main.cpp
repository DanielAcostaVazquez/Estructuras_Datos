/* Act 3.4  Actividad Integral de BST
Integrantes:
Alan Iván FLores Juárez | A01736001
Ulises Hernández Hernández | A01735823
Daniel Francisco Acosta Vázquez | A01736279
Creado el 31/10/22
Editado el 2/11/2022
Organizando una bitácora en un BST por IP, desplegar los 5 datos mayores del
BST.
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
//Convierte los meseses string a numeros
//Complejidad O(1)
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
//Convierte los numeros a meses string
//Complejidad O(1)
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
//Clase de tipo Log
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
Log(){

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
//Funcion que guarda el vector
//Complejidad O(1)
void saveLog(vector<Log> n){
  ofstream file;
  file.open("sorted.txt");
  for(int i = 0; i < n.size(); i++){
      file << IntToMes(n[i].mes) << " " << n[i].dia << " " << n[i].hora << ":" << n[i].min << ":" << n[i].seg << " " << n[i].idR1 << "." << n[i].idR2 << "." << n[i].idR3 << "." << n[i].idH << ":" << n[i].puerto << " " << n[i].fallo << endl;
    }
  file.close();
}
bool operator < (Log &l){
  if(this->idR1 <= l.idR1){
    if(this->idR1 == l.idR1){
      if(this->idR2 <= l.idR2){
        if(this->idR2 == l.idR2){
          if(this->idR3 <= l.idR3){
            if(this->idR3 == l.idR3){
              if(this->idH <= l.idH){
                if(this->idH == l.idH){
                  if(this->puerto <= l.puerto){
                    if(this->puerto == l.puerto){
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
                                          if(this->fallo < l.fallo) return true;
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
    return true;
  }
  return false;
}
//Complejidad O(1)
bool operator == (Log &l){
  if(this->mes == l.mes && this->dia == l.dia && this->hora == l.hora && this->min == l.min && this->seg == l.seg && this->idR1 == l.idR1 && this->idR2 == l.idR2 && this->idR3 == l.idR3 && this->idH == l.idH && this->puerto == l.puerto) return true;
  else return false;
}
private:
int mes, dia, hora, min, seg, idR1, idR2, idR3, idH, puerto;
string fallo;
};
//Estructura de tipo nodo
struct nodo{
  Log data;
  struct nodo *izq;
  struct nodo *der;
};
//Funcion que imprime el Log
//Complejidad O(1)
void printLog(Log l){
  cout << IntToMes(l.getMes()) << " " << l.getDia() << " " << l.getHora() << ":" << l.getMinuto() << ":" << l.getSegundo() << " " << l.getIdR1() << "." << l.getIdR2() << "." << l.getIdR3() << "." << l.getIdH() << ":" << l.getPuerto() << " " << l.getFallo()<< endl;
}
//Funcion que empuja el nuevo elemento
//Complejidad O(log n)
void push(Log Objeto, struct nodo *& root){
  if(root == NULL){
    root = new nodo;
    root->data = Objeto;
    root->der = NULL;
    root->izq = NULL;
  }
  else{
    if(root->data < Objeto){
      if(root->der == NULL){
        root->der = new nodo;
        root->der->data = Objeto;
        root->der->der = NULL;
        root->der->izq = NULL;
      }
      else{
        push(Objeto, root->der);
      }
    }
    else{
      if(root->izq == NULL){
        root->izq = new nodo;
        root->izq->data = Objeto;
        root->izq->der = NULL;
        root->izq->izq = NULL;
      }
      else{
        push(Objeto, root->izq);
      }
    }
  }
}
//Función que extrae el elemento mayor y lo elimina
//Complejidad O(log n)
Log pop(struct nodo *& act, struct nodo *& prev){
  if(act->der == NULL){
    Log l;
    l = act->data;
    if(act->izq == NULL){
      prev->der = NULL;
    }
    else{
      prev->der = act->izq;
    }
    return l;
  }
  else{
    return pop(act->der, act);
  }
}
//Funcion que obtiene los string del archivo txt
//Complejidad O(n)
bool obtenerArchivo(string nombre, struct nodo*& bitacora){
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
      push(Objeto, bitacora);

    }
  }
  in.close();
  return true;
}

int main() {
  struct nodo * bitacora = NULL;
  bool resultado = obtenerArchivo("bitacora.txt", bitacora);
  for(int i = 0; i < 5; i++){
    printLog(pop(bitacora,bitacora));
  }
}
