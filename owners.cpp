#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct Owner {
    string cedula;
    string nombre;
    string apellido;
    string address;
    string telefono;
    string filename;
};

void crearOwner(Owner &owner) {
    cout << "Ingrese la cedula del owner: ";
    cin >> owner.cedula;
    cout << "Ingrese el nombre del owner: ";
    cin >> owner.nombre;
    cout << "Ingrese el apellido del owner: ";
    cin >> owner.apellido;
    cout << "Ingrese la direccion del owner: ";
    cin.ignore(); 
    getline(cin, owner.address);
    cout << "Ingrese el telefono del owner: ";
    cin >> owner.telefono;

    ofstream file(owner.filename.c_str(), ios::app); 
    if (file.is_open()) {
        file << owner.cedula << "," << owner.nombre << "," << owner.apellido << "," << owner.address << "," << owner.telefono << "\n";
        file.close();
        cout << "Owner registrado correctamente.\n\n";
    } else {
        cerr << "Error al abrir el archivo " << owner.filename << "\n";
    }
}

void leerOwners(const string &filename) {
    ifstream file(filename.c_str()); 
    if (file.is_open()) {
        string line;
        cout << "Cedula: | Nombre: | Apellido: | Direccion: |Telefono: |\n";
        while (getline(file, line)) {
            cout << line << "\n";
        }
        file.close();
    } else {
        cerr << "Error al abrir el archivo " << filename << "\n";
    }
}
