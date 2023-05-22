#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include "librerias.h"
#include "rlutil.h"

void lanzardado(int dados[],const int cant, bool tres_dados);
void armardado(char dado[],int cant,bool tresdados,int posx,int posy);
void cargarnombres(string nombre[],string appelido[],const int cant);
int quienempieza(int dados[], int cant,string nombre[],string apellido[]);
void pantalla_de_juego(string nombre[],int jugador,int trufas_x_jug[],int nro_ronda,int trufasronda,int tirada_actual,int lanzamientos,int dados[],int cant,bool tresdados);
void centrartexto(string texto,int posy);
void pantalla_estadisticas(string nombre[],int cant_jug,int trufas_x_jug[],int cont_oinks[],int cerdo_codicioso);
void cerditos(void);
int hitos(int dados[],const int cant,bool &tresdados,int cont_oniks[],int jugador,char &continuar,int trufas_jugador[],bool &flag_oink);
char quien_tira(char continuar,bool flag_oink,bool flag_saltarturno);
int mayor_cant_lanzamientos(int m_lanzamientos[5][2],int cant_rondas,int &mayor_j1,int &mayor_j2);

///pantall de inicio
void pantalla_inicio(){
///asd
}
///lanzamiento del dado
void lanzardado(int dados[],const int cant, bool tres_dados){
    for(int i=0;i<cant;i++){
        dados[i] = rand() % 6 + 1;
    }
    if (tres_dados==false) {
        dados[2]=0;
    }
}
///armado dados(visual)
void armardado (int dados[],int cant,bool tresdados,int posx,int posy){
    const char x=254,ia=218,da=191,ib=192,db=217,l=196, c=179;
    for(int i=0;i<cant;i++){
        rlutil :: locate(posx+1,posy+1);
        cout << ia << l << l << l << l << l << l << l << l << l << da;
        rlutil :: locate(posx+1,posy+2);
        cout << c << "         " << c;
        rlutil :: locate(posx+1,posy+3);
        cout << c << "         " << c;
        rlutil :: locate(posx+1,posy+4);
        cout << c << "         " << c;
        rlutil :: locate(posx+1,posy+5);
        cout << ib << l << l << l << l << l << l << l << l << l << db;
        switch (dados[i])
        {
        case 1:
            rlutil :: locate(posx+6,posy+3);
            cout << x;
            break;
        case 2:
            rlutil :: locate(posx+4,posy+2);
            cout << x;
            rlutil :: locate(posx+8,posy+4);
            cout << x;
            break;
        case 3:
            rlutil :: locate(posx+4,posy+2);
            cout << x;
            rlutil :: locate(posx+6,posy+3);
            cout << x;
            rlutil :: locate(posx+8,posy+4);
            cout << x;
            break;
            /* code */
        case 4:
            rlutil :: locate(posx+4,posy+2);
            cout << x;
            rlutil :: locate(posx+8,posy+2);
            cout << x;
            rlutil :: locate(posx+4,posy+4);
            cout << x;
            rlutil :: locate(posx+8,posy+4);
            cout << x;
            break;
        case 5:
            rlutil :: locate(posx+4,posy+2);
            cout << x;
            rlutil :: locate(posx+8,posy+2);
            cout << x;
            rlutil :: locate(posx+6,posy+3);
            cout << x;
            rlutil :: locate(posx+4,posy+4);
            cout << x;
            rlutil :: locate(posx+8,posy+4);
            cout << x;
            break;
        case 6:
            rlutil :: locate(posx+4,posy+2);
            cout << x;
            rlutil :: locate(posx+8,posy+2);
            cout << x;
            rlutil :: locate(posx+4,posy+3);
            cout << x;
            rlutil :: locate(posx+8,posy+3);
            cout << x;
            rlutil :: locate(posx+4,posy+4);
            cout << x;
            rlutil :: locate(posx+8,posy+4);
            cout << x;
            break;
        }
        posx += 13;
        if (i == 1 && tresdados == false) {
            i=99;
        }
    }
}
///carga nombre y apellido y lo almacena en los vectores
void cargarnombres(string nombre[],const int cant){
    int posx=39;
    rlutil :: cls();
    for(int i=0;i<cant;i++){
        rlutil :: locate(posx,1);
        cout << "JUGADOR " << i+1;
        rlutil :: locate(posx,4);
        cout << "NOMBRE: ";
        rlutil :: locate(posx+8,4);
        getline(cin, nombre[i]);
        posx+=30;
    }

}
///se define quien empieza.
int quienempieza(int dados[],int cant,string nombre[]){
    int empieza,mayorj1,mayorj2;

    dados[cant]={0};

    ///rlutil :: cls();

    if(dados[0] == 0 && dados[1] == 0){
    centrartexto("Comienza el jugador que saque el dado mas alto!",5);
    centrartexto("Precione una tecla para continuar",6);
    rlutil :: getkey();
    }
    centrartexto("Lanzando dados!",7);
    rlutil :: msleep(500);
    rlutil :: cls();
    rlutil :: locate(33,1);
    cout << nombre[0];
    rlutil :: locate(63,1);
    cout << nombre[1];
    ///lanza los dados del jugador 1
    lanzardado(dados,2,false);
    armardado(dados,2,false,32,1);
    int dadosj1 = dados[0] + dados[1];

    if (dados[0] > dados[1]){
        mayorj1 = dados[0];
    }
    else {
        mayorj1 = dados[1];
    }
    ///lanza los dados del jugador 2 y lo evalua
    lanzardado(dados,2,false);
    armardado(dados,2,false,62,1);
    int dadosj2 = dados[0] + dados[1];

    if (dados[0] > dados[1]){
        mayorj2 = dados[0];
    }
    else {
        mayorj2 = dados[1];
    }
    ///compara para ver quien arranca
    if (dadosj1 > dadosj2){
        empieza = 0;
    }
    else{
        if(dadosj1 == dadosj2){
            if (mayorj1 > mayorj2){
                empieza = 0;
            }
            else{
                empieza = 1;
            }
        }
        else{
            empieza = 1;
        }
    }
    return empieza;
}
///funcion para centrar texto >>> creditos Brian Lara
void centrartexto(string texto, int posy){
    int posx = rlutil :: tcols() / 2 - texto.size() / 2;
    rlutil :: locate(posx,posy);
    cout << texto;
}
///esta es la pantalla que se muestra durante la partida >> estadisticas de la partida
void pantalla_de_juego(string nombre[],int jugador,int trufas_x_jug[],int nro_ronda,int trufasronda,int tirada_actual,int lanzamientos,int dados[],int cant,bool tresdados){
    rlutil :: cls();
    int posx=1,postrufasj1,postrufasj2,posxj2;

    posxj2 = rlutil :: tcols() /2 + 1;

    if(jugador == 1){
        posx = posxj2;
    }
    else{
        posx = 25;
    }
    postrufasj1 = posx + (nombre[0].size()) + 2;
    postrufasj2 = rlutil :: tcols() /2 + (nombre[1].size()) + 2;
    centrartexto("> GRAN CERDO <",1);
    centrartexto("--------------------------------------------------------------------------",2);
    //linea que divide la pantalla
    for(int i=3;i<18;i++){
        centrartexto("|",i);
    }
    rlutil :: locate(25,3);
    cout << nombre[0] << ": ";
    rlutil :: locate(postrufasj1,3);
    cout << trufas_x_jug[0] << " Trufas acumuladas";
    rlutil :: locate(posxj2,3);
    cout << nombre[1] << ": ";
    rlutil :: locate(postrufasj2,3);
    cout << trufas_x_jug[1] << " Trufas acumuladas";

    rlutil :: locate(posx,4);
    cout << "Rondas #" << nro_ronda;
    rlutil :: locate(posx,5);
    cout << "Trufas de la ronda: " << trufasronda;
    rlutil :: locate(posx,8);
    cout << "Lanzamiento #" << lanzamientos;
    rlutil :: locate(posx,16);
    cout << "Sumas: " << tirada_actual << " trufas!";
    if(jugador == 1){
        posx = posxj2;
    }
    else{
        posx = 20;
    }
    armardado(dados,cant,tresdados,posx,10);
}
///esta es la pantalla que se muestra al precionar '2' en el menu >> estadisticas
void pantalla_estadisticas(string nombre[],int cant_jug,int trufas_x_jug[],int cont_oinks[],int cerdo_codicioso){
    int i;
    int PDV[2] {};
    string ganador;
    bool f_empate =false;
    rlutil :: cls();

    centrartexto("GRAN CERDO",1);
    centrartexto("-----------------------------------------------------------------------------------------------------------------------",2);
    rlutil :: locate(1,4);
    cout << "HITO";
    centrartexto("-----------------------------------------------------------------------------------------------------------------------",5);
    rlutil :: locate(30,4);
    cout << nombre[0];
    rlutil :: locate(60,4);
    cout << nombre[1];
    rlutil :: locate (1,7);
    cout << "Mas trufas en total" << endl;
    cout << "Cada 50 trufas" << endl;
    cout << "Oink" << endl;
    cout << "Cerdo codicioso" << endl;
    centrartexto("-----------------------------------------------------------------------------------------------------------------------",12);
    cout << endl << "TOTAL";

    //determina cual tiene mas trufas en total (5 PDV)
    if (trufas_x_jug[0] > trufas_x_jug[1]) {
        PDV[0] += 5;
        rlutil :: locate (30,7);
        cout << " 5 PDV (" << trufas_x_jug[0] << " trufas)";
        rlutil :: locate (60,7);
        cout << "0 PDV (" << trufas_x_jug[1] << " trufas)";
    }
    else {
        if(trufas_x_jug[1] > trufas_x_jug[0]){
            PDV[1] += 5;
            rlutil :: locate (60, 7);
            cout << "5 PDV (" << trufas_x_jug[1] << " trufas)";
            rlutil :: locate (30,7);
            cout << "0 PDV (" << trufas_x_jug[0] << " trufas)";
        }
    }

    //1 PDV cada 50 trufas, falta que muestre cantidad de trufas multiplo de 50, hay un error
    for (i=0; i<2; i++) {
        PDV[i] += (trufas_x_jug[i] / 50);
        rlutil :: locate ((i+1) * 30,8);
        cout << trufas_x_jug[i] / 50 << " PDV";
    }

    //OINK (2 PDV * cantidad de oinks) Falta mostrar cantidad de oinks
    for (i=0; i<2; i++) {
        PDV[i] += cont_oinks[i] * 2;
        rlutil :: locate ((i+1) * 30,9);
        cout << cont_oinks[i] * 2 << " PDV";
    }

    //ronda con mayor cantidad de lanzamientos y mostrar numero
    if (cerdo_codicioso == 0) {
        PDV[0] += 3;
        rlutil :: locate (30,10);
        cout << "3 PDV (";
        rlutil :: locate (60,10);
        cout << "0 PDV";
    }
    else {
        if(cerdo_codicioso == 1){
            PDV[1] += 3;
            rlutil :: locate (60,10);
            cout << "3 PDV";
            rlutil :: locate (30,10);
            cout << "0 PDV";
        }
        else{
            PDV[0] += 3;
            PDV[1] += 3;
            rlutil :: locate (30,10);
            cout << "3 PDV";
            rlutil :: locate (60,10);
            cout << "3 PDV";
        }
    }

    //TOTAL
    rlutil :: locate (30, 13);
    cout << PDV [0] << " PDV";
    rlutil :: locate (60, 13);
    cout << PDV [1] << " PDV";

    if(PDV[0] > PDV[1]){
        ganador=nombre[0];
    }
    else{
        if(PDV[0] == PDV[1]){
            ganador = nombre[0] + " " + nombre[1];
            f_empate = true;
        }
        else{
            ganador = nombre[1];
        }
    }

    int posx = rlutil :: tcols() / 2 - ganador.size() / 2;
    centrartexto("¡FELICITACIONES",18);
    rlutil :: locate(posx,19);
    cout << ganador;
    if(f_empate == true){
        centrartexto("EMPATARON!",20);
    }
    else if(f_empate == false){
    centrartexto("GANASTE!",20);
    }

    centrartexto("Presiona una tecla para continuar", 22);
    rlutil :: getkey();

}
///Esta funcion evaluara lo que contengan los dados y en base a eso devuelve el puntaje que se debe sumar
int hitos(int dados[],const int cant,bool &tresdados,int cont_oinks[],int jugador,char &continuar,int trufas_jugador[],bool &flag_oink){
    int trufas=0, cant_unos=0;
    bool flag_as=false,flag_iguales=false;


    for(int i=0;i<cant;i++){
        ///valida si es un as
        if (dados[i] == 1){
            flag_as = true;
            cant_unos++;
        }
        ///valida si un dado es igual a algun otro (aplica para 3 dados)
        if (dados[i] == dados[i-1] || dados[i] == dados[i+2]){
            flag_iguales = true;
        }
        if(i==1 && tresdados==false){
            i=99;
        }
    }
    ///si todo es falso suma trufas normal
    if(flag_as == false && flag_iguales == false){
        for(int i=0;i<cant;i++){
            trufas += dados[i];
        }
        return trufas;
    }
    ///si algun dado es igual a algun otro, hace un oink y duplica las trufas de la ronda
    if(flag_as == false && flag_iguales == true){
        cont_oinks[jugador] ++;
        flag_oink = true;
        for(int i=0;i<cant;i++){
            trufas += dados[i];
        }
        trufas = trufas * 2;
        continuar = 's';
        return trufas;
    }
    ///si algun dado es un AS
    if(flag_as == true && flag_iguales == false && cant_unos == 1){
        trufas = 0;
        return trufas;
    }
    ///si saca un par de ases >> se hunde en el barro(se agrega un tercer dado) y pierde todas las trufas que venia acumulando hasta el momento
    ///ademas le cede el turno al turno al otro cerdo
    if(cant_unos >= 2){

        ///suma 0 trufas
        trufas = 0;

        ///pierde todas las trufas acumuladas hasta el momento
        int aux = trufas_jugador[jugador];
        trufas_jugador[jugador] = 0;

        ///cede el turno al otro jugador
        continuar = 'n';
        if(tresdados==false){
            tresdados = true;
        }
        ///si se esta jugando con 3 dados >> las trufas pasan al otro jugador
        else if (cant_unos==3) {
                if(jugador == 1){
                trufas_jugador[0] += aux;
                }
                else if(jugador == 0){
                    trufas_jugador[1] += aux;
                }
        }
        return trufas;
    }
}
///Se evalua quien tirara >> sigue el mismo jugador o cambia al oponente
char quien_tira(char continuar,bool flag_oink,bool flag_saltarturno){
    if(flag_saltarturno == false){
        if(flag_oink == true){
            ///si hizo un oink esta obligado a tirar
            centrartexto("OINK! Tiras otra vez!",18);
            continuar = 's';
            rlutil :: anykey();
        }
        else{
            ///si no hizo un oink y no se hunde en el barro puede elegir si tirar o no
            centrartexto("Continuar? S/N",18);
            cin >> continuar;
            if(continuar != 'n' && continuar != 'N' && continuar != 's' && continuar != 'S'){
                centrartexto("La tecla ingresada es incorrecta, por favor ingrese S o N",18);
                cin >> continuar;
            }
        }
    }
    else{
        ///si se hunde en el barro tira el otro jugador
        centrartexto ("UPS! Te hundiste en el barro! Salta el turno!",18);
        rlutil :: msleep(50);
        continuar = 'n';
        rlutil :: anykey();
    }

    return continuar;
}
///aca se evaluara quien fue el jugador que realizo mas lanzamientos y en que ronda
int mayor_cant_lanzamientos(int m_lanzamientos[5][2],int cant_rondas, int &mayor_j1,int &mayor_j2){
    for(int r=0;r<cant_rondas;r++){
        if(m_lanzamientos[r][0] > mayor_j1){
            mayor_j1 = m_lanzamientos[r][0];
        }
        if(m_lanzamientos[r][1] > mayor_j2){
            mayor_j2 = m_lanzamientos[r][1];
        }
    }
    if(mayor_j1 > mayor_j2){
        return 0;
    }
    else{
        if(mayor_j1 == mayor_j2){
            return -1;
        }
        else{
            return 1;
        }
    }
}
///*CREDITOS DEL JUEGO*///

void cerditos(void){
    rlutil::cls();
    centrartexto("IDEA ORIGINAL CREADA POR ANGEL SIMON",1);
    centrartexto("Codigo creado por:",3);
    centrartexto("27235 - Mariano Stoessel",4);
    centrartexto("26885 - Elias Garcia",5);
    centrartexto("26232 - Tomas Manfredi",6);
    centrartexto("26911 - Brian Galeano",7);
    centrartexto("GRACIAS POR JUGAR!",9);

    centrartexto("Presiona una tecla para continuar", 22);
    rlutil :: getkey();

}
#endif // FUNCIONES_H_INCLUDED
