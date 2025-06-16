#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#define _WINSOCK_DEPRECATED_NO_WARNINGS 1
#pragma comment(lib,"pthreadVC2.lib")
#define HAVE_STRUCT_TIMESPEC
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>


#define largura_matriz 100 //aqui vc define a largura que quer que sua matriz tenha
#define altura_matriz 100 // e aqui, a altura

//definir largura e altura dos macroblocos 
#define largura_macrobloco 10 
#define altura_macrobloco 10 

//variavel global
int blocoSeguinte = 0;
//controle com mutex = apenas uma thread por vez executa um trecho critico do codigo
pthread_mutex_t mutexBloco;

//funcao p pegar o bloco seguinte
int pegarBlocoSeguinte(){
    int bloco;
    pthread_mutex_lock (&mutexBloco); 
    bloco = blocoSeguinte;
    blocoSeguinte++;
    pthread_mutex_unlock (&mutexBloco); //libera p que outras threads possam acessar
    return bloco;
}

//funcao p calcular coodernadas do macrobloco
void calcCoordenadas(int IDbloco, int *primeira_linha, int *ultima_linha, int *primeira_coluna, int *ultima_coluna)
{
    int blocosPorLinha = largura_matriz / largura_macrobloco;

    int bloco_linha = IDbloco / blocosPorLinha; // de repente da pra colocar no #define
    int bloco_coluna = IDbloco % blocosPorLinha;

    *primeira_linha = bloco_linha * altura_macrobloco;
    *ultima_linha = *primeira_linha + altura_macrobloco - 1;

    *primeira_coluna = bloco_coluna * largura_macrobloco;
    *ultima_coluna = *primeira_coluna + largura_macrobloco - 1;
}

//funcao da thread para buscar numeros primos
void *procuraPrimosThread(void *arg) {
    int blocosPorLinha = largura_matriz / largura_macrobloco;
    int blocosPorColuna = altura_matriz / altura_macrobloco;
    int blocosInteiros = blocosPorLinha * blocosPorColuna;

    while (1){
        int IDbloco = blocoSeguinte();
        if (IDbloco >= blocosInteiros){
            break;
        }
     //FALTA COMPLETAR ESSA FUNCAO
    }

}

//funcao p criar e gerenciar threads (busca paralela)