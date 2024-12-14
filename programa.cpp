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
