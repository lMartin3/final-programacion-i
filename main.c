#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
#define INTENTOS_MAXIMOS 3
int codigos[100];
int stock[100];

//  á    é    í    ó    ú
// 160, 130, 161, 162, 163

int main()
{
    char name[20];
    char password[10];
    int intentos = 0;

    do{
        printf("Ingrese el nombre de usuario: ");
        scanf("%s", name);
        printf("Ingrese la contrase%ca: ", 164);
        scanf("%s", password);

        if (strcmp(name, "admin") == 0 && strcmp(password, "admin1234") == 0) {
            printf("Bienvenido!\n");
            break;
        }
        else {
            intentos++;
            printf("Usuario y/o contrase%ca incorrectos, le quedan %d intentos\n", 164, INTENTOS_MAXIMOS-intentos);
        }
    } while (intentos < INTENTOS_MAXIMOS);
    if(intentos>=3) {
        printf("Ha superado el n%cmero de intentos permitidos\n", 163);
        return -1;
    }
    int opcion = 0;
    do
    {
        printf("-------- Men%c principal --------\n", 163);
        printf("Por favor, seleccione una opci%cn:\n", 162);
        printf("1- Cargar un producto\n");
        printf("2- Modificar stock\n");
        printf("3- Mostrar productos sin stock\n");
        printf("4- Mostrar producto con mayor stock\n");
        printf("5- Mostrar todos los productos cargados y su stock\n");
        printf("6- Salir\n");
        printf("--------------------------------\n");
        scanf("%d", &opcion);
        switch (opcion)
        {
        case 1:
        {
            cargarProducto();
            break;
        }
        case 2:
        {
            modificarStock();
            break;
        }
        case 3:
        {
            listarProductos(1);
            break;
        }
        case 4:
        {
            mostrarProductoConMayorStock();
            break;
        }
        case 5:
        {
            listarProductos(0);
            break;
        }
        case 6:
        {
            break;
        }
        default:
        {
            printf("Opci%cn inv%clida!", 162, 160);
        }
        }
        if(opcion!=6) {
            system("PAUSE");
        }
    } while (opcion != 6);
    printf("Adi%cs!", 162);
    return 1;
}

int obtenerIndiceDeProductoPorID(int idProducto)
{
    for (int i = 0; i < MAX; i++)
    {
        if (codigos[i] == idProducto)
        {
            return i;
        }
    }
    return -1;
}

void cargarProducto()
{
    // Obtenemos el primer indice disponible para ambos arrays
    int indice = obtenerIndiceDeProductoPorID(0);
    printf("---- CARGAR NUEVO PRODUCTO ----\n");
    if (indice < 0 || indice >= MAX)
    {
        printf("Se alcanz%c la cantidad m%cxima de productos cargados (%d)\n", 162, 160, indice);
        return;
    }

    int codigo = -1;
    do
    {
        printf("Ingrese un c%cdigo de barras para el producto: ", 162);
        scanf("%d", &codigo);
        if (codigo < 1)
        {
            printf("El codigo debe ser positivo!");
        }
        else if (obtenerIndiceDeProductoPorID(codigo) != -1)
        {
            // Esto significa que ya existe un producto con ese código
            printf("Ya existe un producto con ese c%cdigo!\n", 162);
        }
        else
        {
            codigos[indice] = codigo;
        }
    } while (codigos[indice] == 0);
    printf("Ingrese un stock incial para el producto: ");
    scanf("%d", &stock[indice]);
    printf("Nuevo producto con c%cdigo %d y stock %d registrado correctamente\n", 162, codigos[indice], stock[indice]);
}

void modificarStock()
{
    printf("---- MODIFICAR STOCK ----\n");
    int codigoIngresado = -1;
    int indiceProducto = -1;
    do
    {
        printf("Ingrese el codigo del producto cuyo stock desea modificar: ");
        scanf("%d", &codigoIngresado);
        int ix = obtenerIndiceDeProductoPorID(codigoIngresado);
        if (codigoIngresado >= 1 && ix >= 0)
        {
            indiceProducto = ix;
        }
        if (indiceProducto == -1)
        {
            printf("No se encontr%c ningun producto con ese c%cdigo\n", 162, 162);
        }
    } while (indiceProducto == -1);

    int nuevoStock = -1;
    do
    {
        printf("Ingrese el nuevo stock: ");
        scanf("%d", &nuevoStock);
        if (nuevoStock < 0)
        {
            printf("Tiene que ingresar un n%cmero positivo!", 163);
        }
    } while (nuevoStock < 0);

    stock[indiceProducto] = nuevoStock;
    printf("Stock del producto %d actualizado a %d correctamente\n", codigoIngresado, nuevoStock);
}

void listarProductos(int soloSinStock)
{
    printf(soloSinStock == 1 ? "---- PRODUCTOS SIN STOCK ----\n" : "---- LISTA DE PRODUCTOS ----\n");
    for (int i = 0; i < MAX; i++)
    {
        if (codigos[i] == 0)
            break;
        if (soloSinStock == 1 && stock[i] > 0)
            continue;
        printf("-> Codigo: %d | Stock: %d\n", codigos[i], stock[i]);
    }
    printf("----------- FIN -----------\n");
}

void mostrarProductoConMayorStock()
{
    printf("---- PRODUCTO CON MAYOR STOCK ----\n");
    if (codigos[0] == 0)
    {
        printf("No hay productos registrados\n");
    }
    else
    {
        int mayorIndex = 0;
        for (int i = 0; i < MAX; i++)
        {
            if (codigos[i] == 0)
                break;
            if (stock[i] > stock[mayorIndex])
            {
                mayorIndex = i;
            }
        }
        printf("C%cdigo: %d | Stock: %d", 162, codigos[mayorIndex], stock[mayorIndex]);
    }
    printf("----------- FIN -----------\n");
}