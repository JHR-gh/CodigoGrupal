#include <iostream>
#include <string.h>
using namespace std;
struct alumno {
  char nombre[50];
  int dni;
  char telefono[20];
  int grado;
  int edad;
};

void ingresar_alumno(alumno *a) {
  cout << "Ingrese el nombre del alumno: ";
  cin.get();
  cin.getline(a->nombre, 50);
  cout << "Ingrese el DNI del alumno: ";
  cin >> a->dni;
  cout << "Ingrese el teléfono del apoderado del alumno: ";
  cin.get();
  cin.getline(a->telefono, 20);
  cout << "Ingrese el grado del alumno: ";
  cin >> a->grado;
  cout << "Ingrese la edad del alumno: ";
  cin >> a->edad;
  cout << "\n";
}

void mostrar_alumno(alumno *a) {
  cout << "Nombre: " << a->nombre << endl;
  cout << "DNI: " << a->dni << endl;
  cout << "Teléfono: " << a->telefono << endl;
  cout << "Grado: " << a->grado << endl;
  cout << "Edad: " << a->edad << endl;
}

int buscar_alumno(alumno *alumnos, int n, int grado) {
  for (int i = 0; i < n; i++) {
    if (alumnos[i].grado == grado) {
      return i;
    }
  }

  return -1;
}

int main() {
  alumno *alumnos;

  int n;
  cout << "Ingrese la cantidad de alumnos: ";
  cin >> n;

  alumnos = new alumno[n];

  for (int i = 0; i < n; i++) {
    ingresar_alumno(&alumnos[i]);
  }

  int opcion;
  do {
    cout << endl;
    cout << "[1.] Mostrar la lista de todos los alumnos" << endl;
    cout << "[2.] Buscar un alumno por grado" << endl;
    cout << "[3.] Salir" << endl;
    cout << "Ingrese una opción:\n";
    cin >> opcion;

    switch (opcion) {
      case 1:{
        for (int i = 0; i < n; i++) {
          mostrar_alumno(&alumnos[i]);
        }
        break;}

      case 2:{
        int grado;
        cout << "Ingrese el grado del alumno a buscar: ";
        cin >> grado;

        int i = buscar_alumno(alumnos, n, grado);

        if (i != -1) {
          mostrar_alumno(&alumnos[i]);
        } else {
          cout << "El alumno no fue encontrado" << endl;
        }
        break;}

      case 3:{
        cout << "Saliendo del programa..." << endl;
        break;}

      default:{
        cout << "Opción inválida" << endl;
        break;}
    }
  } while (opcion != 3);
  delete[] alumnos;

  return 0;
}
