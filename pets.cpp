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

void leerPets(const string &filename) {
    ifstream file(filename.c_str()); 
    if (file.is_open()) {
        string line;
        cout << "ID | Nombre | Tipo | Raza | Cedula del owner |\n";
        while (getline(file, line)) {
            cout << line << "\n";
        }
        cout << "\n";
        file.close();
    } else {
        cerr << "Error al abrir el archivo " << filename << "\n";
    }
}

void ActuPets(const string &filename) {
    string ID, newID, newName, newTipo, newRaza, newOwnerCed;
    bool exists = false;

    cout << "Ingrese el ID de la mascota a actualizar: ";
    cin >> ID;

    ifstream file(filename.c_str()); 
    if (!file.is_open()) {
        cerr << "Error al abrir el archivo " << filename << "\n";
        return;
    }

    string line;
    while (getline(file, line)) {
        if (line.substr(0, line.find(',')) == ID) {
            exists = true;
            break;
        }
    }
    file.close();

    if (!exists) {
        cout << "No se encontro una mascota con el ID: " << ID << ".\n";
        return;
    }

    cout << "Status: Modificando\n";
    cout << "   Ingrese el nuevo ID de la mascota: ";
    cin >> newID;
    cout << "   Ingrese el nuevo nombre de la mascota: ";
    cin >> newName;
    cout << "   Ingrese el nuevo tipo de la mascota: ";
    cin >> newTipo;
    cout << "   Ingrese la nueva raza de la mascota: ";
    cin.ignore();
    getline(cin, newRaza);
    cout << "   Ingrese la nueva cedula del owner: ";
    cin >> newOwnerCed;

    string updatedData = newID + "," + newName + "," + newTipo + "," + newRaza + "," + newOwnerCed;

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
        if (line.substr(0, line.find(',')) == ID) {
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
        cout << "La mascota con el ID: " << ID << " fue actualizada correctamente.\n\n";
    else
        cout << "Hubo un error al actualizar la mascota.\n";
}

void deletePet(const string &filename) {
    string ID;

    cout << "Ingrese el ID de la mascota a eliminar: ";
    cin >> ID;

    ifstream file(filename.c_str()); 
    if (!file.is_open()) {
        cerr << "Error al abrir el archivo " << filename << "\n";
        return;
    }

    ofstream tempFile("temp.csv"); 
    if (!tempFile.is_open()) {
        cerr << "Error al abrir el archivo temporal\n";
        return;
    }

    string line;
    bool deleted = false;
    while (getline(file, line)) {
        if (line.substr(0, line.find(',')) == ID) {
            deleted = true;
        } else {
            tempFile << line << "\n";
        }
    }

    file.close();
    tempFile.close();

    remove(filename.c_str()); 
    rename("temp.csv", filename.c_str());

    if (deleted)
        cout << "La mascota con el ID: " << ID << " fue eliminada correctamente.\n";
    else
        cout << "No se encontro una mascota con el ID: " << ID << ".\n";
}

int main() {
    string filename = "pets.csv";
    Pet pet;
    pet.filename = filename;

    int option;

    do {
        cout << "1. Agregar nueva mascota\n";
        cout << "2. Ver todas las mascotas\n";
        cout << "3. Actualizar datos de una mascota\n";
        cout << "4. Eliminar una mascota\n";
        cout << "5. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> option;
        cout << "\n";

        switch (option) {
            case 1:
                AgregarMascota(pet);
                break;
            case 2:
                leerPets(filename);
                break;
            case 3:
                ActuPets(filename);
                break;
            case 4:
                deletePet(filename);
                break;
            case 5:
                cout << "Saliendo del programa...\n";
                break;
            default:
                cout << "Opción inválida. Intente de nuevo.\n";
        }
    } while (option != 5);

    return 0;
}

