#include <stdio.h>
#define MAX 100

// Inicializamos los valores en -1
int codigos[100] = {-1};
int stock[100] = {-1};

//  á    é    í    ó    ú
// 160, 130, 161, 162, 163

int main() {
    int opcion = 0;
    do {
        printf("-------- Men%c principal --------", 163);
        printf("Por favor, seleccione una opci%cn:", 162);
        printf("1- Cargar un producto");
        printf("2- Modificar stock");
        printf("3- Mostrar productos sin stock");
        printf("4- Mostrar producto con mayor stock");
        printf("5- Salir");
        printf("--------------------------------");
        scanf("%d", &opcion);
    } while(opcion != 5);
    printf("Adi%cs!", 162);
    return 0;
}


int obtenerIndiceDisponible() {
    for(int i=0;i<MAX;i++) {
        if(codigos[i]==-1) {
            return i;
        }
    }
    return -1;
}
