#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <bits/stdc++.h>
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
Log(int mes, int dia, int hora, int min, int seg, int idR1, int idR2, int idR3, int idH, int puerto, string fallo, unsigned long long int tiempo){
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
  this->tiempo = tiempo;
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
void setTiempo(unsigned long long int tiempo){
  this->tiempo = tiempo;
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
//Complejidad O(1)
void printLog(){
  cout << IntToMes(mes) << " " << dia << " " << hora << ":" << min << ":" << seg << " " << idR1 << "." << idR2 << "." << idR3 << "." << idH << ":" << puerto << " " << fallo << endl;
}

//Complejidad O(n)
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
                                      if(this->puerto <= l.puerto){
                                        if(this->puerto == l.puerto){
                                          if(this->tiempo < l.tiempo) return true;
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
  if(this->mes == l.mes && this->dia == l.dia && this->hora == l.hora && this->min == l.min && this->seg == l.seg && this->idR1 == l.idR1 && this->idR2 == l.idR2 && this->idR3 == l.idR3 && this->idH == l.idH && this->puerto == l.puerto && this->tiempo == l.tiempo) return true;
  else return false;
}
public:
int mes, dia, hora, min, seg, idR1, idR2, idR3, idH, puerto;
string fallo;
unsigned long long int tiempo;
};

struct nodo{
  Log data;
  struct nodo *prev;
  struct nodo *next;
};
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
      unsigned long long int t;
      t = (m*2592000)+(d*86400)+(h*3600)+(mi*60)+s;

      Log Objeto(m,d,h,mi,s,r1,r2,r3,host,p,f,t);
      struct nodo * tmp = new nodo; //nodo temporal
      struct nodo * unode = bitacora; //ultimo nodo de la lista

      tmp->data = Objeto;
      tmp->next = NULL;

      if(bitacora == NULL){
        tmp->prev = NULL;
        bitacora = tmp;  //Si la lista esta vacía se inserta al inicio
      }
      else{
        while(unode->next != NULL){ //Se recorre la lista en busqueda del ultimo nodo
          unode = unode->next;
        }
        unode->next = tmp; //Se inserta el nodo al final
        tmp->prev = unode;
      }
    }
  }
  in.close();
  return true;
}
//Complejidad O(n)
void Imprime(nodo *& inicio){
  struct nodo * tmp = inicio;
  while(tmp->next != NULL){ //Imprime nodo y se recorre
    tmp->data.printLog();
    tmp = tmp->next;
  }
  tmp->data.printLog(); //Imprime ultimo nodo
};
//Complejidad O(n)
void Imprime_reversa(struct nodo *&bitacora) {
   //traverse the list to display each node
   struct nodo* tail = bitacora;
   while (tail -> next != NULL){
     tail = tail -> next;
   }
   struct nodo* tmp = tail;
   while (tmp -> prev != NULL){
     tmp -> data.printLog();
     tmp = tmp -> prev;
   }
   tmp -> data.printLog();

}
//Complejidad O(n)
void ordena(struct nodo*& bitacora){
    int swapped, i;
    struct nodo *ptr1;
    struct nodo *lptr = NULL;

    //Comprobar si la lista está vacía
    if (bitacora == NULL)
        return;
    //Si no entonces ejecutar el ordenamiento (1)
    do{
        swapped = 0;
        ptr1 = bitacora;

        while (ptr1->next != lptr){
            if (ptr1->data.idR1 > ptr1->next->data.idR1){
                swap(ptr1->data, ptr1->next->data);
                swapped = 1;
            } else if (ptr1->data.idR1 == ptr1->next->data.idR1){
                if (ptr1->data.idR2 > ptr1->next->data.idR2){
                    swap(ptr1->data, ptr1->next->data);
                    swapped = 1;
                } else if (ptr1->data.idR2 == ptr1->next->data.idR2){
                    if (ptr1->data.idR3 > ptr1->next->data.idR3){
                        swap(ptr1->data, ptr1->next->data);
                        swapped = 1;
                    } else if (ptr1->data.idR3 == ptr1->next->data.idR3){
                        if (ptr1->data.idH > ptr1->next->data.idH){
                            swap(ptr1->data, ptr1->next->data);
                        swapped = 1;
                        } else if (ptr1->data.idH == ptr1->next->data.idH){
                            if (ptr1->data.puerto > ptr1->next->data.puerto){
                                swap(ptr1->data, ptr1->next->data);
                                swapped = 1;
                            } else if (ptr1->data.puerto == ptr1->next->data.puerto){
                                if (ptr1->data.tiempo > ptr1->next->data.tiempo){
                                    swap(ptr1->data, ptr1->next->data);
                                    swapped = 1;
                                }
                            }
                        }
                    }
                }
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    }
    while (swapped);
}

int main() {
  int ip1, ip2, ip3, ip4, puerto;
  int dia1, hora1, min1, seg1;
  string x, y;
  struct nodo * bitacora = NULL;
  bool resultado = obtenerArchivo("bitacora.txt", bitacora);
  ordena(bitacora);
  // Guardar(bitacora);
  struct nodo * tmp1 = bitacora;
  int cont=1;
  while (tmp1 -> next != NULL){
    tmp1 = tmp1 -> next;
    cont ++;
  }

//No nos dio tiempo realizar la busqueda por ip
  //cin>>x;
  //cin>>y;

  ofstream file;
  file.open("sorted.txt");
  struct nodo * tmp = bitacora;
  //Complejidad O(n)
  for(int i = 0; i < cont; i++){
      file << IntToMes(tmp -> data.mes) << " " << tmp -> data.dia << " " << tmp -> data.hora << ":" << tmp -> data.min << ":" << tmp -> data.seg << " " << tmp -> data.idR1 << "." << tmp -> data.idR2 << "." << tmp -> data.idR3 << "." << tmp -> data.idH << ":" << tmp -> data.puerto << " " << tmp -> data.fallo<< endl;
      tmp = tmp -> next;
    }

  file.close();

  Imprime_reversa(bitacora);

}
