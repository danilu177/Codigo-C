#include <stdio.h>  


#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <wchar.h>
#include <locale.h>
#include <windows.h>

#define MAX_ESTUDIANTES_A 40
#define MAX_ESTUDIANTES_B 43

void seleccion_idioma();
void menu_inicial();

typedef struct {
    char cedula[12];
    float notas[4]; // LOC-154, INI-154, MAT-165 e ING-143.
} Estudiante;

int _idioma  = 0;

void limpia_pantalla(){
    #ifdef _WIN32
        system("cls"); // Comando para Windows
    #else
        system("clear"); // Comando para Unix/Linux/Mac
    #endif
}



char* cambio_idioma(char* cadena) {       
    if (_idioma == 1){                          
        if (strcmp(cadena,"Seleccione una opcion") == 0){
            return "Select an option";        
        }else if (strcmp(cadena ,"Ver Datos") == 0){
            return "See Data";
        }else if (strcmp(cadena ,"Ver Resultados") == 0){
            return "See Results";
        }else if (strcmp(cadena ,"Anterior") == 0){
            return "Previous";        
        }else if (strcmp(cadena , "Cedula") == 0){
            return "ID";
        }else if (strcmp(cadena , "Materia") == 0){
            return "Subjet";
        }else if (strcmp(cadena , "Nota") == 0){
            return "Grades";
        }else if (strcmp(cadena , "Presiona Enter para continuar") == 0){
            return "Press Enter to continue";
        }else if (strcmp(cadena , "Seccion") == 0){
            return "group";
        }else if (strcmp(cadena , "La calificacion mas alta es") == 0){
            return "The highest rating is";
        }else if (strcmp(cadena , "Seleccione una materia") == 0){
            return "Select a subjet";
        }else if (strcmp(cadena , "Estudiantes con la calificacion mas alta") == 0){
            return "Students with the highest grade";
        }else if (strcmp(cadena , "La proposicion") == 0){
            return "The proposition";        
        }else if (strcmp(cadena , "con dominio de discurso") == 0){
            return "with domain of discourse";
        }else if (strcmp(cadena , "es") == 0){
            return "is";
        }else if (strcmp(cadena , "Verdadera") == 0){
            return "True";
        }else if (strcmp(cadena , "Falsa") == 0){
            return "False";

        }else if (strcmp(cadena , "La nota de cada uno de los estudiantes de la seccion A es mayor que la nota de cada uno de los estudiantes de la seccion B") == 0){
        	
            return "The grade of each of the students in section A is higher than the grade of each of the students in section B";
		
        }else if (strcmp(cadena , "La nota de cada uno de los estudiantes de la seccion A es mayor que al menos una nota de los estudiantes de la seccion B") == 0){
			
            return "The grade of each of the students in section A is higher than at least one grade of the students in section B";
        
        }else if (strcmp(cadena , "La nota de al menos uno de los estudiantes de la seccion A es mayor que la nota de cada uno de los estudiantes de la seccion B") == 0){
        	
            return "The grade of at least one of the students in section A is higher than the grade of each of the students in section B";
		
        }else if (strcmp(cadena , "La nota de  al menos unos de los estudiantes de la seccion A es mayor que al menos una nota de los estudiantes de la seccion B") == 0){
			
            return "The grade of at least one of the students in section A is higher than at least one grade of the students in section B";
        
        }else if (strcmp(cadena , "La nota de cada uno de los estudiantes de la seccion B es mayor que la nota de cada uno de los estudiantes de la seccion A") == 0){
        	
            return "The grade of each of the students in section B is higher than the grade of each of the students in section A";
		
        }else if (strcmp(cadena , "La nota de cada uno de los estudiantes de la seccion B es mayor que al menos una nota de los estudiantes de la seccion A") == 0){
			
            return "The grade of each of the students in section B is higher than at least one grade of the students in section A";
        
        }else if (strcmp(cadena , "La nota de al menos uno de los estudiantes de la seccion B es mayor que a la nota de cada uno de los estudiantes de la seccion A") == 0){
        	
            return "The grade of at least one of the students in section B is higher than the grade of each of the students in section A";
		
        }else if (strcmp(cadena , "La nota de  al menos unos de los estudiantes de la seccion B es mayor que al menos una nota de los estudiantes de la seccion A") == 0){
			
            return "The grade of at least one of the students in section B is higher than at least one grade of the students in section A";

        }else if (strcmp(cadena , "Comparativa entre Seccion A y Seccion B") == 0){
            return "Comparison between Section A and Section B \n";

        }else if (strcmp(cadena , "Comparativa entre Seccion B y Seccion A") == 0){
            return "Comparison between Section B and Section A \n";

        }else if (strcmp(cadena , "Seleccione una proposicion\n") == 0){
            return "Select a proposal \n";
        
        
        }else if (strcmp(cadena , "Bienvenidos a nuestro proyecto") == 0){
            return "Welcome to our proyect \n";
        }else if (strcmp(cadena ,"Los integrantes del grupo son:") == 0){
            return "The members of the team are:";

        }else if (strcmp(cadena ,"Gracias por ver nuestro proyecto\n") == 0){
            return "Thanks to see our proyect\n";
        }else if (strcmp(cadena ,"Hasta luego\n") == 0){
            return "Goodbye!\n";  
        }else if (strcmp(cadena ,"Salir") == 0){
            return "Exit";  
        }else{
            return cadena;
        }
    }
    return cadena;
}

void esperar_continuar(){
	printf("%s...\n", cambio_idioma("Presiona Enter para continuar"));
    getchar();
	getchar();
}

void cerrarApp(){
    limpia_pantalla();       
    printf(cambio_idioma("Gracias por ver nuestro proyecto\n"));
    printf(cambio_idioma("Hasta luego\n"));
    esperar_continuar();  
    exit(0);
}


void cargar_data(Estudiante *estudiantes_A,Estudiante *estudiantes_B){      
        Estudiante seccionA[MAX_ESTUDIANTES_A] = {
        {"28204750", {13, 13, 13, 12}},
        {"28604286", {10, 0, 0, 0}},  // Solo ve LOG (Lógica) con nota 10
        {"28720160", {9, 9, 9, 10}},
        {"29910191", {6, 8, 9, 13}},
        {"29976423", {3, 1, 6, 7}},
        {"30025107", {4, 5, 6, 9}},
        {"30025364", {10, 8, 11, 14}},
        {"30304358", {5, 5, 7, 13}},
        {"30318050", {5, 5, 7, 11}},
        {"30509428", {6, 8, 8, 12}},
        {"30554221", {8, 12, 10, 16}},
        {"30616022", {9, 13, 10, 10}},
        {"30621370", {9, 7, 10, 13}},
        {"30868117", {3, 10, 10, 8}},
        {"30895463", {4, 6, 10, 12}},
        {"30995739", {10, 8, 10, 11}},
        {"31003968", {12, 14, 11, 11}},
        {"31027844", {8, 10, 8, 11}},
        {"31041280", {11, 10, 10, 12}},
        {"31077263", {4, 3, 8, 8}},
        {"31152397", {9, 10, 10, 9}},
        {"31212501", {10, 13, 10, 12}},
        {"31212748", {11, 10, 10, 14}},
        {"31277624", {4, 5, 11, 9}},
        {"31300904", {5, 13, 9, 12}},
        {"31802535", {9, 14, 8, 14}},
        {"31843360", {8, 9, 10, 12}},
        {"31930471", {8, 0, 0, 0}},  // Solo ve LOG (Lógica) con nota 8
        {"31971884", {6, 6, 11, 11}},
        {"31973411", {8, 11, 9, 14}},
        {"32023436", {5, 4, 4, 12}},
        {"32114506", {11, 13, 11, 15}},
        {"32114546", {10, 10, 11, 13}},
        {"32120564", {6, 6, 10, 14}},
        {"32257442", {13, 13, 12, 14}},
        {"32708173", {1, 1, 2, 1}},
        {"32908154", {6, 11, 6, 9}},
        {"32934300", {7, 4, 6, 12}},
        {"32958402", {6, 8, 9, 13}},
        {"33286847", {6, 5, 9, 10}},
    };

    // Datos de los estudiantes de la sección B
    Estudiante seccionB[MAX_ESTUDIANTES_B] = {
     {"27666750", {13, 14, 12, 11}},
     {"27816179", {6, 6, 8, 11}},
     {"28114901", {9, 4, 10, 11}},
     {"28204076", {0, 0, 0, 5}},  // Solo ve ING (Inglés) con nota 5
     {"28493042", {6, 3, 5, 8}},
     {"29851531", {13, 14, 12, 11}},
     {"29997721", {3, 5, 4, 11}},
     {"30025094", {0, 5, 0, 0}},  // Solo ve INI (Informática) con nota 5
     {"30025743", {11, 11, 9, 9}},
     {"30173950", {0, 0, 9, 10}},  // Ve MAT y INC (Matemática e Informática)
     {"30205063", {12, 14, 11, 11}},
     {"30324636", {11, 11, 9, 10}},
     {"30352925", {11, 11, 10, 10}},
     {"30417006", {8, 7, 12, 10}},
     {"30559804", {0, 0, 1, 0}},  // Solo ve MAT (Matemáticas) con nota 1
     {"30587623", {8, 11, 11, 11}},
     {"30657216", {5, 5, 6, 6}},
     {"30664420", {10, 14, 11, 12}},
     {"30880837", {8, 5, 10, 9}},
     {"30895081", {7, 2, 8, 8}},
     {"31028020", {7, 3, 9, 10}},
     {"31181474", {7, 10, 6, 8}},
     {"31367977", {11, 14, 11, 12}},
     {"31662843", {8, 12, 10, 10}},
     {"31663762", {11, 12, 12, 11}},
     {"31692418", {5, 1, 7, 7}},
     {"31802592", {4, 3, 8, 10}},
     {"31986837", {4, 3, 5, 7}},
     {"32014083", {7, 5, 8, 8}},
     {"32114888", {7, 3, 7, 12}},
     {"32163244", {3, 4, 7, 8}},
     {"32206701", {1, 3, 6, 1}},
     {"32237008", {8, 11, 10, 7}},
     {"32260073", {8, 6, 8, 9}},
     {"32306351", {3, 7, 9, 12}},
     {"32307009", {8, 12, 8, 12}},
     {"32467798", {6, 4, 9, 10}},
     {"32533151", {8, 9, 8, 11}},
     {"32552150", {4, 3, 5, 9}},
     {"32627455", {8, 4, 11, 9}},
     {"33343709", {3, 8, 6, 1}},
     {"33997066", {3, 3, 8, 7}},
     {"34234936", {3, 5, 6, 0}},
    };
    memcpy(estudiantes_A,seccionA,sizeof(seccionA));
    memcpy(estudiantes_B,seccionB,sizeof(seccionB));
}



float buscar_nota_alta(int materia_seleccionada, Estudiante estudiantes_A[], Estudiante estudiantes_B[]){
    float nota_alta = 0;    
    for (int i = 0; i < MAX_ESTUDIANTES_A; i++) {
        if (estudiantes_A[i].notas[materia_seleccionada] > nota_alta) {
            nota_alta = estudiantes_A[i].notas[materia_seleccionada];            
        }
    }
    for (int i = 0; i < MAX_ESTUDIANTES_B; i++) {
        if (estudiantes_B[i].notas[materia_seleccionada] > nota_alta) {
            nota_alta = estudiantes_B[i].notas[materia_seleccionada];            
        }
    }
    return nota_alta;
}

bool verificar_proposicion_A (Estudiante D1[], Estudiante D2[], int materia_seleccionada, int max_d1, int max_d2) {
    bool result = true;    
    for (int i = 0; i < max_d1; i++) {
        for (int j = 0; j < max_d2; j++) {
            if (D1[i].notas[materia_seleccionada] <= D2[j].notas[materia_seleccionada]) {
                result = false;
                break;
            }
        }
        if (!result) break;
    }
    return result;
}

int verificar_proposicion_B (Estudiante D1[], Estudiante D2[], int materia_seleccionada, int max_d1, int max_d2) {
    bool result = true;   
    for (int i = 0; i < max_d1; i++) {
        int existe = 0;
        for (int j = 0; j < max_d2; j++) {
            if (D1[i].notas[materia_seleccionada] > D2[j].notas[materia_seleccionada]) {
                existe = false;
                break;
            }
        }
        if (!existe) {
            result = false;
            break;
        }
    }
    return result;
}

int verificar_proposicion_C (Estudiante D1[], Estudiante D2[], int materia_seleccionada, int max_d1, int max_d2) {
    bool result = false;   
    for (int i = 0; i < max_d1; i++) {
        bool para_todos = true;
        for (int j = 0; j < max_d2; j++) {
            if (D1[i].notas[materia_seleccionada] <=  D2[j].notas[materia_seleccionada]) {
                para_todos = false;
                break;
            }
        }
        if (para_todos) {
            result = true;
            break;
        }
    }
    return result;
}

int verificar_proposicion_D (Estudiante D1[], Estudiante D2[], int materiaseleccionada, int max_d1, int max_d2) {
    bool result = false;   
     for (int i = 0; i < max_d1; i++) {
        for (int j = 0; j < max_d2; j++) {
            if (D1[i].notas[materiaseleccionada] > D2[j].notas[materiaseleccionada]) {
                result = true;
                break;
            }
        }
        if (result) break;
    }
    return result;
}

void imprime_resultado_proposicion(char mensaje[], bool resultado_proposicion ){
    char respuesta_proposicion[20] ;
    if (resultado_proposicion){
        strcpy(respuesta_proposicion,cambio_idioma("Verdadera"));
    }else{
        strcpy(respuesta_proposicion,cambio_idioma("Falsa"));        
    }
    printf("%s  %s\n", mensaje , respuesta_proposicion);
}

void imprime_nota_alta(int materia_seleccionada, float nota_alta, Estudiante Data[], char seccion_seleccionada[], int Max_Estudiante){
    for (int i = 0; i < Max_Estudiante; i++)
    {
        if (Data[i].notas[materia_seleccionada] == nota_alta) {
                printf("   %s  %s %s\n", Data[i].cedula, cambio_idioma("Seccion"), seccion_seleccionada );
        }
    }
}

void ver_resultados(Estudiante estudiantes_A[], Estudiante estudiantes_B[]){
    int materia_seleccionada; 
    int proposicion_seleccionada;
    float nota_alta = 0;
    int resultado_proposicion = 0;    
    limpia_pantalla();    
    printf("%s\n",cambio_idioma("Seleccione una materia"));
    printf(" 0 LOC-154\n");
    printf(" 1 INI-154\n");
    printf(" 2 MAT-165\n");
    printf(" 3 ING-143\n");
    
    scanf("%d", & materia_seleccionada);
    limpia_pantalla();  
    nota_alta = buscar_nota_alta(materia_seleccionada,estudiantes_A, estudiantes_B ); 

    printf("%s: %f \n", cambio_idioma("La calificacion mas alta es"), nota_alta);
    printf("\n");
    printf("%s:\n", cambio_idioma("Estudiantes con la calificacion mas alta"));
    printf("\n");
    imprime_nota_alta(materia_seleccionada, nota_alta, estudiantes_A, "A", MAX_ESTUDIANTES_A );
    printf("\n");
    imprime_nota_alta(materia_seleccionada, nota_alta, estudiantes_B, "B", MAX_ESTUDIANTES_B );
    printf("\n");
    printf("***********************************\n");
    
    printf(cambio_idioma ("Seleccione una proposicion\n"));

    printf(" 1     ∀ X ∀ Y : X > Y \n");
    printf(" 2     ∀ X ∃ Y : X > Y \n");
    printf(" 3     ∃ X ∀ Y : X > Y \n");
    printf(" 4     ∃ X ∃ Y : X > Y \n");
    scanf("%d", & proposicion_seleccionada);

    if (proposicion_seleccionada == 1){
        printf("%s\n", cambio_idioma("Comparativa entre Seccion A y Seccion B"));
        resultado_proposicion = verificar_proposicion_A(estudiantes_A,estudiantes_B,materia_seleccionada,MAX_ESTUDIANTES_A, MAX_ESTUDIANTES_B);
        imprime_resultado_proposicion(cambio_idioma("La nota de cada uno de los estudiantes de la seccion A es mayor que la nota de cada uno de los estudiantes de la seccion B"), resultado_proposicion);
        printf("%s\n", cambio_idioma("Comparativa entre Seccion B y Seccion A"));
        resultado_proposicion = verificar_proposicion_A(estudiantes_B,estudiantes_A,materia_seleccionada,MAX_ESTUDIANTES_B, MAX_ESTUDIANTES_A);
        imprime_resultado_proposicion(cambio_idioma("La nota de cada uno de los estudiantes de la seccion B es mayor que la nota de cada uno de los estudiantes de la seccion A"), resultado_proposicion);   
    }
    if (proposicion_seleccionada == 2){
        printf("%s\n", cambio_idioma("Comparativa entre Seccion A y Seccion B"));
        resultado_proposicion = verificar_proposicion_B(estudiantes_A,estudiantes_B,materia_seleccionada,MAX_ESTUDIANTES_A, MAX_ESTUDIANTES_B);
        imprime_resultado_proposicion(cambio_idioma("La nota de cada uno de los estudiantes de la seccion A es mayor que al menos una nota de los estudiantes de la seccion B"), resultado_proposicion);
        printf("%s\n", cambio_idioma("Comparativa entre Seccion B y Seccion A"));
        resultado_proposicion = verificar_proposicion_B(estudiantes_B,estudiantes_A,materia_seleccionada,MAX_ESTUDIANTES_B, MAX_ESTUDIANTES_A);
        imprime_resultado_proposicion(cambio_idioma("La nota de cada uno de los estudiantes de la seccion B es mayor que al menos una nota de los estudiantes de la seccion A"), resultado_proposicion);   
    }
    
    if (proposicion_seleccionada == 3){
        printf("%s\n", cambio_idioma("Comparativa entre Seccion A y Seccion B"));
        resultado_proposicion = verificar_proposicion_C(estudiantes_A,estudiantes_B,materia_seleccionada,MAX_ESTUDIANTES_A, MAX_ESTUDIANTES_B);
        imprime_resultado_proposicion(cambio_idioma("La nota de al menos uno de los estudiantes de la seccion A es mayor que la nota de cada uno de los estudiantes de la seccion B"), resultado_proposicion);
        printf("%s\n", cambio_idioma("Comparativa entre Seccion B y Seccion A"));
        resultado_proposicion = verificar_proposicion_C(estudiantes_B,estudiantes_A,materia_seleccionada,MAX_ESTUDIANTES_B, MAX_ESTUDIANTES_A);
        imprime_resultado_proposicion(cambio_idioma("La nota de al menos uno de los estudiantes de la seccion B es mayor que a la nota de cada uno de los estudiantes de la seccion A"), resultado_proposicion);   
    }

    if (proposicion_seleccionada == 4){
        printf("%s\n", cambio_idioma("Comparativa entre Seccion A y Seccion B"));
        resultado_proposicion = verificar_proposicion_C(estudiantes_A,estudiantes_B,materia_seleccionada,MAX_ESTUDIANTES_A, MAX_ESTUDIANTES_B);
        imprime_resultado_proposicion(cambio_idioma("La nota de  al menos unos de los estudiantes de la seccion A es mayor que al menos una nota de los estudiantes de la seccion B"), resultado_proposicion);
        printf("%s\n", cambio_idioma("Comparativa entre Seccion B y Seccion A"));
        resultado_proposicion = verificar_proposicion_C(estudiantes_B,estudiantes_A,materia_seleccionada,MAX_ESTUDIANTES_B, MAX_ESTUDIANTES_A);
        imprime_resultado_proposicion(cambio_idioma("La nota de  al menos unos de los estudiantes de la seccion B es mayor que al menos una nota de los estudiantes de la seccion A"), resultado_proposicion);   
    }

    esperar_continuar();
   
}

void menu_inicial(Estudiante estudiantes_A[], Estudiante estudiantes_B[]){
    int opcion  = 0;  
    while (opcion != 2 )
    {          
        limpia_pantalla();  
        printf("%s \n", cambio_idioma("Seleccione una opcion"));    
        printf(" 1 %s \n", cambio_idioma("Ver Resultados"));
        printf(" 2 %s \n", cambio_idioma("Anterior"));
        printf(" 9 %s \n", cambio_idioma("Salir"));
        scanf("%d", & opcion);
        if (opcion == 1){            
            ver_resultados(estudiantes_A,estudiantes_B);
        }else if (opcion == 9){        
            cerrarApp();
        }  
    }
}

void presentacion(){   
    limpia_pantalla();       
    printf("%s \n",cambio_idioma("Bienvenidos a nuestro proyecto"));
    printf("%s \n",cambio_idioma("Los integrantes del grupo son:"));
    printf("   Daniel Lucena,\n   Magdiel Arreche,\n   Daniel Mendoza,\n   David Silva,\n   Daniel Ortiz,\n   Miguel Alvarado,\n   Ignacio Escalona\n");    
    esperar_continuar();
}

void seleccion_idioma(Estudiante estudiantes_A[], Estudiante estudiantes_B[]){  
    while (_idioma != 3)
    {
            
        limpia_pantalla();      
       
        printf("Seleccione un idioma/Select a language \n");
        printf("1 Ingles/English \n");
        printf("2 Espanol/Spanish \n");
        printf("3 Salir/Exit \n");    
        scanf("%d", & _idioma);      
        if (_idioma != 3){
            presentacion();     
            menu_inicial(estudiantes_A, estudiantes_B);
        }
    }
}

int main() {   
    SetConsoleOutputCP(CP_UTF8);
    Estudiante estudiantes_A[MAX_ESTUDIANTES_A];
    Estudiante estudiantes_B[MAX_ESTUDIANTES_B];    
    cargar_data(estudiantes_A, estudiantes_B);
    seleccion_idioma(estudiantes_A, estudiantes_B);   
    cerrarApp();
}