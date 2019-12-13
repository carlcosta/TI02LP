#ifndef HEADER_H_
#define HEADER_H_

typedef enum
{
    false,
    true

} bool;

typedef struct
{
    int dia;
    int mes;
    int ano;

} Data;

typedef enum
{
    Baixo,
    Moderado,
    Elevado,

} NivelImpacto;

#endif