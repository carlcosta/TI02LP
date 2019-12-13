#ifndef AUDITORIAS_H_
#define AUDITORIAS_H_
#define TAM_AUDITORIAS 100

//#define Auditorias//
#define FICHEIRO_AUDITORIAS "auditorias/auditorias.txt"


typedef struct
{
    int id;
    int codigo;
    int duracaoMinutos;
    Data data;
    Colaborador colaborador;
    Vulnerabilidade vulnerabilidade;
    bool ativo;
    
    

} Auditoria;

Auditoria novaAuditoria(int id);
int inserirAuditoria(Auditoria *auditoria, int n);

#endif
