#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Pet {
    string ID;
    string nombre;
    string tipo;
    string raza;
    string cedulaOwner;
    string filename;
};

void AgregarMascota(Pet &pet) {
    cout << "Ingrese el ID de la mascota: ";
    cin >> pet.ID;
    cout << "Ingrese el nombre de la mascota: ";
    cin >> pet.nombre;
    cout << "Ingrese el tipo de la mascota (Perro, Gato, etc): ";
    cin >> pet.tipo;
    cout << "Ingrese la raza de la mascota: ";
    cin.ignore();
    getline(cin, pet.raza);
    cout << "Ingrese la cedula del owner: ";
    cin >> pet.cedulaOwner;

    ofstream file(pet.filename.c_str(), ios::app); 
    if (file.is_open()) {
        file << pet.ID << "," << pet.nombre << "," << pet.tipo << "," << pet.raza << "," << pet.cedulaOwner << "\n";
        file.close();
        cout << "Mascota registrada correctamente.\n\n";
    } else {
        cerr << "Error al abrir el archivo " << pet.filename << "\n";
    }
}
