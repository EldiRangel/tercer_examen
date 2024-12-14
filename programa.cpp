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

void actualizarOwner() {
    string name;
    cout << "Ingrese el nombre del owner a actualizar: ";
    cin >> name;
    for (int i = 0; i < ownerCount; i++) {
        if (owners[i].name == name) {
            cout << "Ingrese la nueva direccion: ";
            cin >> owners[i].address;
            cout << "Ingrese el nuevo telefono: ";
            cin >> owners[i].phone;
            cout << "Datos actualizados.\n";
            return;
        }
    }
    cout << "owner no encontrado.\n";
}

void eliminarOwner() {
    string name;
    cout << "Ingrese el nombre del owner a eliminar: ";
    cin >> name;
    for (int i = 0; i < ownerCount; i++) {
        if (owners[i].name == name) {
            for (int j = i; j < ownerCount - 1; j++) {
                owners[j] = owners[j + 1];
            }
            ownerCount--;
            cout << "owner eliminado.\n";
            return;
        }
    }
    cout << "owner no encontrado.\n";
}

int main() {
    int option;

    do {
        cout << "1. Gestion de Mascotas\n";
        cout << "2. Gestion de Owners\n";
        cout << "3. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> option;
        cout << "\n";

        if (option == 1) {
            int petOption;
            do {
                cout << "1. Agregar nueva mascota\n";
                cout << "2. Ver todas las mascotas\n";
                cout << "3. Actualizar datos de una mascota\n";
                cout << "4. Eliminar una mascota\n";
                cout << "0. Volver\n";
                cout << "Seleccione una opción: ";
                cin >> petOption;
                cout << "\n";

                switch (petOption) {
                    case 1:
                        agregarMascota();
                        break;
                    case 2:
                        verMascotas();
                        break;
                    case 3:
                        actualizarMascota();
                        break;
                    case 4:
                        eliminarMascota();
                        break;
                    case 0:
                        cout << "Saliendo\n";
                        cout << "\n";
                        break;
                    default:
                        cout << "Opción inválida.\n";
                }
            } while (petOption != 0);

        } else if (option == 2) {
            int ownerOption;
            do {
                cout << "1. Agregar nuevo owner\n";
                cout << "2. Ver todos los owners\n";
                cout << "3. Actualizar datos de un owner\n";
                cout << "4. Eliminar un owner\n";
                cout << "0. Volver\n";
                cout << "Seleccione una opción: ";
                cin >> ownerOption;
                cout << "\n";

                switch (ownerOption) {
                    case 1:
                        agregarOwner();
                        break;
                    case 2:
                        verOwners();
                        break;
                    case 3:
                        actualizarOwner();
                        break;
                    case 4:
                        eliminarOwner();
                        break;
                    case 0:
                        cout << "Saliendo\n";
                        cout << "\n";
                        break;
                    default:
                        cout << "Opcion inválida. Intente de nuevo.\n";
                }
            } while (ownerOption != 0);
        } else if (option != 3) {
            cout << "Opcion inválida. Intente de nuevo.\n";
        }
    } while (option != 3);

    cout << "Saliendo del programa...\n";
    return 0;
}

