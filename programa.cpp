#include <iostream>
#include <string>
using namespace std;

struct Pet {
    string name;
    string type;
    int age;
};

struct Owner {
    string name;
    string address;
    string phone;
};

const int MAX_PETS = 100;
const int MAX_OWNERS = 100;

Pet pets[MAX_PETS];
Owner owners[MAX_OWNERS];

int petCount = 0;
int ownerCount = 0;

void agregarMascota() {
    if (petCount < MAX_PETS) {
        cout << "Ingrese el nombre de la mascota: ";
        cin >> pets[petCount].name;
        cout << "Ingrese el tipo de mascota: ";
        cin >> pets[petCount].type;
        cout << "Ingrese la edad de la mascota: ";
        cin >> pets[petCount].age;
        petCount++;
        cout << "Mascota agregada exitosamente.\n";
    } else {
        cout << "No se pueden agregar más mascotas.\n";
    }
}

void verMascotas() {
    for (int i = 0; i < petCount; i++) {
        cout << "Nombre: " << pets[i].name << ", Tipo: " << pets[i].type << ", Edad: " << pets[i].age << "\n";
    }
}

void actualizarMascota() {
    string name;
    cout << "Ingrese el nombre de la mascota a actualizar: ";
    cin >> name;
    for (int i = 0; i < petCount; i++) {
        if (pets[i].name == name) {
            cout << "Ingrese el nuevo tipo: ";
            cin >> pets[i].type;
            cout << "Ingrese la nueva edad: ";
            cin >> pets[i].age;
            cout << "Datos actualizados.\n";
            return;
        }
    }
    cout << "Mascota no encontrada.\n";
}

void eliminarMascota() {
    string name;
    cout << "Ingrese el nombre de la mascota a eliminar: ";
    cin >> name;
    for (int i = 0; i < petCount; i++) {
        if (pets[i].name == name) {
            for (int j = i; j < petCount - 1; j++) {
                pets[j] = pets[j + 1];
            }
            petCount--;
            cout << "Mascota eliminada.\n";
            return;
        }
    }
    cout << "Mascota no encontrada.\n";
}

void agregarOwner() {
    if (ownerCount < MAX_OWNERS) {
        cout << "Ingrese el nombre del dueño: ";
        cin >> owners[ownerCount].name;
        cout << "Ingrese la dirección: ";
        cin >> owners[ownerCount].address;
        cout << "Ingrese el teléfono: ";
        cin >> owners[ownerCount].phone;
        ownerCount++;
        cout << "Dueño agregado exitosamente.\n";
    } else {
        cout << "No se pueden agregar más dueños.\n";
    }
}

void verOwners() {
    for (int i = 0; i < ownerCount; i++) {
        cout << "Nombre: " << owners[i].name << ", Dirección: " << owners[i].address << ", Teléfono: " << owners[i].phone << "\n";
    }
}
