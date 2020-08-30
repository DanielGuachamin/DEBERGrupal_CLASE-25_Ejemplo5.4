#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;
const int MAX = 50;

void ingresar_datos(double calificaciones[MAX], string nombres[MAX], int t);
double validar_nota(double nota);
void ordenar(double calificaciones[MAX], string nombres[MAX], int t);
void imprimir(double calificaciones[MAX], string nombres[MAX], int t);

int main() {
  int i;
  ofstream promedios;
  double Calificaciones[MAX];
  string Nombres[MAX];
  int tamanio;
  promedios.open("Promedio y Nombres", ios::out);
  if (promedios.is_open())
  {
    cout << "Ingrese la cantidad de alumnos: ";
    cin >> tamanio;
    ingresar_datos(Calificaciones, Nombres, tamanio);
    cout << endl;
    imprimir(Calificaciones, Nombres, tamanio);
    promedios << "Alumnos y sus promedios: " << '\n';
    for(i = 0; i < tamanio; i++)
    {
      promedios << Nombres[i] << " tiene: " << setw(10) << right << fixed << setprecision(2) << Calificaciones[i] << '\n';
    }
    ordenar(Calificaciones, Nombres, tamanio);
    promedios << "Alumnos y sus promedios ordenados de mayor a menor: " << '\n';
    for(i = 0; i < tamanio; i++)
    {
      promedios << Nombres[i] << " tiene: " << setw(10) << right << fixed << setprecision(2) << Calificaciones[i] << '\n';
    }
    promedios << "Fin de la lista";
    cout << endl;
    imprimir(Calificaciones, Nombres, tamanio);
  }
  else
  {
    cout << "\nEl archivo no se pudo abrir correctamente" << endl;
  }
  promedios.close();
  return 0;
}

void ingresar_datos(double calificaciones[MAX], string nombres[MAX], int t)
{
  int x;
  for (x = 0; x < t; x++)
  {
    cin.ignore();
    cout << "\nIngrese el nombre del alumno: ";
    getline(cin, nombres[x]); 
    cout << "Ingrese el promedio del alumno: ";
    cin >> calificaciones[x];
    calificaciones[x] = validar_nota(calificaciones[x]);
  }
}

void ordenar(double calificaciones[MAX], string nombres[MAX], int t)
{
  int i, j; 
  double aux;
  string cambio;
  for(i = 0; i < t; i++)
  {
    for( j = i + 1; j < t; j++)
    {
      if (calificaciones[i] < calificaciones[j])
      {
        aux = calificaciones[i];
        calificaciones[i] = calificaciones[j];
        calificaciones[j] = aux;
        cambio = nombres[i];
        nombres[i] = nombres[j];
        nombres[j] = cambio;
      }
    }
  }
}

double validar_nota(double nota)
{
  while (nota < 0)
  {
    cout << "\nValor ingresado incorrecto. Ingrese la calificacion del alumno: ";
    cin >> nota;
  }
  return nota;
}

void imprimir(double calificaciones[MAX], string nombres[MAX], int t)
{
  int i;
  for(i = 0; i < t; i++)
  {
    cout << nombres[i] << " tiene: " << setw(10) << right << fixed << setprecision(2) << calificaciones[i] << endl;
  }
}