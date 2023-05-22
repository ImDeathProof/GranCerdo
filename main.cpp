#include <iostream>

using namespace std;
#include "librerias.h"
#include "funciones.h"



int main() {
    srand(time(NULL));
    ///variables generales
    const int cant_jugadores=2,cant_dados=3,cant_rondas=5;
    int opcion,empieza,trufasronda,tirada_actual,mayor_lanzaj1=0,mayor_lanzaj2=0,cerdo_codicioso;
    char continuar='s'; /// S = sigue /N = no sigue
    bool turnojugador=false,hab_3dados=false;
    ///vectores / matrices
    int m_lanzamientos[5][2];
    int dados[cant_dados]{};
    int trufas_jugador[cant_jugadores]{};
    int oinks[cant_jugadores]{};
    string nombre_jugador[cant_jugadores]{};

    //menu
    rlutil::hidecursor();
    rlutil::setBackgroundColor(rlutil::BLACK);
    rlutil::setColor(rlutil::LIGHTMAGENTA);
    do{
        rlutil :: cls();
        centrartexto("GRAN CERDO",1);
        centrartexto("-----------------------------------------------------------------------------------------------------------------------",2);
        centrartexto(" 1 - JUGAR       ",3);
        centrartexto(" 2 - ESTADISTICAS",4);
        centrartexto(" 3 - CERDITOS    ",5);
        centrartexto(" 0 - SALIR       ",7);
        centrartexto("-------------------------------------------------",8);
        rlutil :: locate(60, 9);
        opcion = rlutil :: getkey();
        switch(opcion){
        case 48:{
            centrartexto("GRAN CERDO",1);
            centrartexto("-----------------------------------------------------------------------------------------------------------------------",2);
            rlutil :: cls();
            centrartexto("SELECCIONO LA OPCION 0, SEGURO QUE DESEA SALIR? SE PERDERAN LOS DATOS DE LA PARTIDA",3);
            centrartexto("S = SI / N = NO",4);
            char op = rlutil :: getkey();
            if(op == 's' || op == 'S'){
                return 0;
            }
        }
        break;
        case 49:{
                for (int i=0;i<cant_rondas;i++){
                    if (i == 0){
                        ///se inicia el juego y si esta en la ronda 1 se cargan nombres y se decide quien comienza
                        cargarnombres(nombre_jugador,cant_jugadores);
                        empieza = quienempieza(dados,cant_dados,nombre_jugador);
                        ///si los dados salen iguales, la funcion retorna 3 y se procede a lanzar nuevamente
                        if(empieza == 3){
                            rlutil :: locate(1,7);
                            centrartexto("Los dados son iguales, hay que tirar otra vez! ",7);
                            empieza = quienempieza(dados,cant_dados,nombre_jugador);
                        }
                        rlutil :: locate(1,7);
                        centrartexto("Empieza el jugador " + nombre_jugador[empieza],7);
                        centrartexto("Presione una tecla para continuar",8);
                        turnojugador = empieza;
                        rlutil :: anykey();
                    }

                    for (int j=0;j<cant_jugadores;j++){
                        trufasronda = 0;
                        int cont_lanzamientos = 0;
                        bool flag_saltarturno = false,flag_oink = false;
                        continuar = 's';
                            if (trufas_jugador[0] >= 10 && trufas_jugador[1] >=10) {
                                hab_3dados = true;
                            }
                        while (continuar != 'n' && continuar != 'N' && continuar == 's' || continuar == 'S' && i < 5){
                            flag_saltarturno = false;
                            flag_oink = false;
                            cont_lanzamientos++;
                            rlutil :: cls();
                            lanzardado(dados,cant_dados,hab_3dados);
                            tirada_actual = hitos(dados,cant_dados,hab_3dados,oinks,turnojugador,continuar,trufas_jugador,flag_oink);
                            if(tirada_actual == 0){
                                trufasronda = 0;
                                flag_saltarturno = true;
                                if(i == 0){
                                    trufas_jugador[turnojugador] = 0;
                                }
                            }
                            else{
                                trufasronda += tirada_actual;
                            }
                            pantalla_de_juego(nombre_jugador,turnojugador,trufas_jugador,i+1,trufasronda,tirada_actual,cont_lanzamientos,dados,cant_dados,hab_3dados);
                            ///dependiendo el valor tira el mismo jugador o el oponente
                            continuar = quien_tira(continuar,flag_oink,flag_saltarturno);
                        }
                        
                        ///guarda la cantidad de lanzamientos del jugador en cada ronda
                        m_lanzamientos[i][turnojugador];
                        
                        if(flag_saltarturno == false){
                            trufas_jugador[turnojugador] += trufasronda;
                        }
                        ///cambia de jugador
                        if(turnojugador == 0){
                            turnojugador = 1;
                        }
                        else{
                            turnojugador = 0;
                        }

                    }
                }
                pantalla_estadisticas(nombre_jugador,cant_jugadores,trufas_jugador,oinks,cerdo_codicioso);
                rlutil :: anykey();
                cerditos();
                rlutil :: anykey();
        }
        break;
        case 50:{
                pantalla_estadisticas(nombre_jugador,cant_jugadores,trufas_jugador,oinks,cerdo_codicioso);
                rlutil :: anykey();
        }
        break;
        case 51:{
                cerditos();
                rlutil :: anykey();
        }
        break;
        default:
            rlutil::setBackgroundColor(rlutil::RED);
            rlutil::setColor(rlutil::WHITE);
            centrartexto("ESTA OPCION ES INCORRECTA",9);
            rlutil::anykey();
            rlutil::setBackgroundColor(rlutil::BLACK);
            rlutil::setColor(rlutil::LIGHTMAGENTA);
        }


    }while(opcion!=0);

    rlutil :: cls();

    return 0;
}
