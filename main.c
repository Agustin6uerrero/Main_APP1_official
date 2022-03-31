#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define READ "r"
#define SOBRE_ESC "a"

struct Invent{
    char *titulo;
    char *autor;
    int anio;
    int estante_numero;
    char *estante_seccion;
    int piso;
    char *edificio;
    char *sede;
};

struct Sedes{
    int asociados;
    char *sede;
};

struct Secciones{
    int asociados;
    char *seccion;
};

struct Piso{
    int asociados;
    int piso;
};

typedef struct Invent inv;
typedef struct Sedes sed;
typedef struct Secciones sec;
typedef struct Piso pis;

inv *bobi;
sed *sedes;
sec *secciones;
pis *pisos;
int contador_gral = 0;
int contador_sed = 0;
int contador_sec = 0;
int contador_pis = 0;

FILE * openingFile(char *filename, char *modo){
    FILE *fp;
    fp = fopen(filename,modo);
    if(fp==NULL){
        printf("Problem\n");
        exit(-1);
    }
    return fp;
}

void agregar_sede(char *sede){
    int flag = 0;
    for(int i = 0; i < contador_sed; i++){
        if(strcmp(sedes[i].sede, sede) == 0){
            flag = 1;
            sedes[i].asociados += 1;
        }
    }
    if(flag == 0){
        sedes[contador_sed + 1].sede = sede;
        sedes[contador_sed + 1].asociados = 1;
    }
}

void agregar_seccion(){

}

void agregar_piso(){

}

void Insertar_Libro(FILE *fp){
    char nombre[300];
    contador_gral += 1;
    //Pide el titulo
    printf("Inserte el titulo del libro que desea agregar a la biblioteca: ");
    fgets(nombre, 300, stdin);
    if ((strlen(nombre) > 0) && (nombre[strlen(nombre) - 1] == '\n'))
    {
        nombre[strlen(nombre) - 1] = '\0';
    }
    fprintf(fp, "\n%s", nombre);
    fprintf(fp, "%s", ",");
    bobi[contador_gral].titulo = nombre;
    //Pide el autor
    printf("Inserte el autor del libro que desea agregar a la biblioteca: ");
    fgets(nombre, 300, stdin);
    if ((strlen(nombre) > 0) && (nombre[strlen(nombre) - 1] == '\n'))
    {
        nombre[strlen(nombre) - 1] = '\0';
    }
    fprintf(fp, " %s", nombre);
    fprintf(fp, "%s", ",");
    bobi[contador_gral].autor = nombre;
    //Pide el año
    printf("Inserte el anio del libro que desea agregar a la biblioteca: ");
    fgets(nombre, 300, stdin);
    if ((strlen(nombre) > 0) && (nombre[strlen(nombre) - 1] == '\n'))
    {
        nombre[strlen(nombre) - 1] = '\0';
    }
    fprintf(fp, " %s", nombre);
    fprintf(fp, "%s", ",");
    bobi[contador_gral].anio = strtol(nombre, NULL, 10);
    //Pide en numero de estante
    printf("Inserte el numero de estante del libro que desea agregar a la biblioteca: ");
    fgets(nombre, 300, stdin);
    if ((strlen(nombre) > 0) && (nombre[strlen(nombre) - 1] == '\n'))
    {
        nombre[strlen(nombre) - 1] = '\0';
    }
    fprintf(fp, " %s", nombre);
    fprintf(fp, "%s", ",");
    bobi[contador_gral].estante_numero = strtol(nombre, NULL, 10);
    //Pide seccion de estante
    printf("Inserte la seccion del estante del libro que desea agregar a la biblioteca: ");
    fgets(nombre, 300, stdin);
    if ((strlen(nombre) > 0) && (nombre[strlen(nombre) - 1] == '\n'))
    {
        nombre[strlen(nombre) - 1] = '\0';
    }
    fprintf(fp, " %s", nombre);
    fprintf(fp, "%s", ",");
    bobi[contador_gral].estante_seccion = nombre;
    //Pide piso
    printf("Inserte el piso del libro que desea agregar a la biblioteca: ");
    fgets(nombre, 300, stdin);
    if ((strlen(nombre) > 0) && (nombre[strlen(nombre) - 1] == '\n'))
    {
        nombre[strlen(nombre) - 1] = '\0';
    }
    fprintf(fp, " %s", nombre);
    fprintf(fp, "%s", ",");
    bobi[contador_gral].piso = strtol(nombre, NULL, 10);
    //Pide edificio
    printf("Inserte el edificio del libro que desea agregar a la biblioteca: ");
    fgets(nombre, 300, stdin);
    if ((strlen(nombre) > 0) && (nombre[strlen(nombre) - 1] == '\n'))
    {
        nombre[strlen(nombre) - 1] = '\0';
    }
    fprintf(fp, " %s", nombre);
    fprintf(fp, "%s", ",");
    bobi[contador_gral].edificio = nombre;
    //Pide sede
    printf("Inserte la sede del libro que desea agregar a la biblioteca: ");
    fgets(nombre, 300, stdin);
    if ((strlen(nombre) > 0) && (nombre[strlen(nombre) - 1] == '\n'))
    {
        nombre[strlen(nombre) - 1] = '\0';
    }
    fprintf(fp, " %s", nombre);
    bobi[contador_gral].sede = nombre;
}

int contar_lineas(FILE *fp){
    char buff[300];
    int i = -1;
    while(!feof(fp)){
        fgets(buff, 1000, fp);
        i = i + 1;
    }
    rewind(fp);
    return i;
}

void condicional(int k, char *tok, int i){
    if (k == 1) {
        bobi[i].autor = tok;
        //printf("\ntitulo: %s\n", bobi[i].titulo);
        //printf("autor: %s\n", bobi[i].autor);
    }
    else if (k == 2) {
        bobi[i].anio = strtol(tok, NULL, 10);
        //bobi[i].anio = atoi(tok);
        //printf("anio: %d\n", bobi[i].anio);
    }
    else if (k == 3) {
        bobi[i].estante_numero = strtol(tok, NULL, 10);
        //printf("estante_numero: %d\n", bobi[i].estante_numero);
    }
    else if (k == 4) {
        bobi[i].estante_seccion = tok;
        //printf("estante_seccion: %s\n", bobi[i].estante_seccion);
    }
    else if (k == 5) {
        bobi[i].piso = strtol(tok, NULL, 10);
        //printf("piso: %d\n", bobi[i].piso);
    }
    else if (k == 6) {
        bobi[i].edificio = tok;
        //printf("edificio: %s\n", bobi[i].edificio);
    }
    else if(k==7){
        bobi[i].sede = tok;
        //printf("sede: %s\n", bobi[i].sede);
        //printf("=====================\n");
    }
}

void guardar_csv(FILE *fp, int contador){
    char *tok, aux[200], tokk[200];
    char buff[300];
    int j = 0, k = 1;
    for(int i = 0; i < contador; i++){
        fgets(buff, 300, fp);
        if(buff[0] != '"') {
            tok = strtok(buff, ",");
            strcpy(tokk, tok);
            bobi[i].titulo = (char *) malloc((strlen(tokk) + 1) * sizeof(char));
            bobi[i].titulo = tokk;
            while (tok != NULL) {
                tok = strtok(NULL, ",");
                condicional(k, tok, i);
                k = k + 1;
                }
            k = 1;
            }

        else{
        tok = strtok(buff, ",");
        strcat(strcpy(aux, tok), ",");
        strcpy(tokk, aux);
        j = 0;
        while (j < 1) {
            tok = strtok(NULL, ",");
            strcat(tokk, tok);
            j = j + 1;
        }
        bobi[i].titulo = (char *) malloc((strlen(tokk) + 1) * sizeof(char));
        bobi[i].titulo = tokk;
        while (tok != NULL) {
            tok = strtok(NULL, ",");
            condicional(k, tok, i);
            k = k + 1;
        }
        k = 1;
        }
    }
    rewind(fp);
}


int main(int argc, char *argv[]){
    //Lee el csv y guarda los datos en arreglo inv bobi
    FILE *fp = openingFile(argv[1], READ);
    int contador = contar_lineas(fp);
    contador_gral = contador;
    bobi = (inv*)malloc((contador+100)*sizeof(inv));
    sedes = (sed*)malloc((contador+100)*sizeof(sed));
    secciones = (sec*)malloc((contador+100)*sizeof(sec));
    pisos = (pis*)malloc((contador+100)*sizeof(pis));
    guardar_csv(fp, contador);
    fclose(fp);
    //=================
    fp = openingFile(argv[1], SOBRE_ESC);
    Insertar_Libro(fp);
    fclose(fp);
    printf("%d", contador_gral);
    return 0;
}