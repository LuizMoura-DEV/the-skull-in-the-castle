#include <iostream>
#include <clocale>
#include <stdlib.h>
#include "bibItens.h"
#include "bibNPC.h"
#include "bibDado.h"
#include "bibGame.h"
#include <time.h>
#include "stdafx.h"
#include <fcntl.h>
#include <io.h>

#include <windows.h>
#include <io.h> // <- need to add this include for _setmode
#include <fcntl.h> // <- need to add this include for _O_TEXT
#include <cstdio> // <- need to add this include for wprintf


using namespace std;


int dado(int menor, int maior) {
    srand((unsigned)time(0));                   //Gera um valor aleatorio
    return rand()%(maior-menor+1) + menor;      //utilizando como intervalo as variaveis menor e maior
}
