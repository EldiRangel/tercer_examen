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

void actualizarOwner(const string &filename) {
    string cedula, newCed, newNombre, newApell, newAddress, newPhone;
    bool exists = false;

    cout << "Ingrese la cedula del owner a actualizar: ";
    cin >> cedula;

    ifstream file(filename.c_str()); 
    if (!file.is_open()) {
        cerr << "Error al abrir el archivo " << filename << "\n";
        return;
    }

    string line;
    while (getline(file, line)) {
        if (line.substr(0, line.find(',')) == cedula) {
            exists = true;
            break;
        }
    }
    file.close();

    if (!exists) {
        cout << "No se encontro un owner con la cedula: " << cedula << ".\n\n";
        return;
    }

    cout << "Status: Modificando\n";
    cout << "   Ingrese la cedula del owner: ";
    cin >> newCed;
    cout << "   Ingrese el nombre del owner: ";
    cin >> newNombre;
    cout << "     Ingrese el apellido del owner: ";
    cin >> newApell;
    cout << "   Ingrese la direccion del owner: ";
    cin.ignore();
    getline(cin, newAddress);
    cout << "   Ingrese el telefono del owner: ";
    cin >> newPhone;

    string updatedData = newCed + "," + newNombre + "," + newApell + "," + newAddress + "," + newPhone;

    ifstream inputFile(filename.c_str()); 
    if (!inputFile.is_open()) {
        cerr << "Error al abrir el archivo " << filename << "\n";
        return;
    }

    ofstream tempFile("temp.csv"); 
    if (!tempFile.is_open()) {
        cerr << "Error al abrir el archivo temporal\n";
        return;
    }

    bool updated = false;

    while (getline(inputFile, line)) {
        if (line.substr(0, line.find(',')) == cedula) {
            tempFile << updatedData << "\n";
            updated = true;
        } else {
            tempFile << line << "\n";
        }
    }

    inputFile.close();
    tempFile.close();

    remove(filename.c_str()); 
    rename("temp.csv", filename.c_str()); 

    if (updated)
        cout << "El owner con la cedula: " << cedula << " fue actualizado correctamente.\n\n";
    else
        cout << "Hubo un error al actualizar el dueño.\n\n";
}
