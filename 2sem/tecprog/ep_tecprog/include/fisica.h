/* Declaração das funções e estruturas responsáveis por 
 * calcular as forcas, aceleracao, velocidade, posicao
 * de cada corpo
 *
 * Pressupõe que os vetores tem a mesma base ortonormal 
 */

#ifndef FISICA
#define FISICA
#include "structs.h"


#define VEL_ANGULAR -2.0
#define ANTIHORARIO 1
#define HORARIO -1

/* calcula_gravidade
 *
 * Recebe: 	corpo 1 e corpo 2	
 * Retorna: a forca gravitacional que o corpo 2 exerce
 * 			sobre o corpo 1
 */
vetor calcula_gravidade(corpo* c1, corpo* c2);

/* calcula_aceleracao
 *
 * Recebe: 	o vetor forca
 * 		    a massa de um corpo
 * Retorna: a aceleracao instantanea do corpo
 */
vetor calcula_aceleracao(vetor forca, double massa);

/* calcula_velocidade
 *
 * Recebe: 	o vetor aceleracao
 * 		   	a massa de um corpo
 * 			o intervalo de tempo
 * Retorna: a velocidade instantanea do corpo
 */
vetor calcula_velocidade(vetor aceleracao, double tempo);

/* calcula_deslocamento
 *
 * Recebe: 	o vetor velocidade
 * 			o intervalo de tempo
 * Retorna: o vetor de deslocamento do corpo
 */
vetor calcula_deslocamento(vetor velocidade, vetor aceleracao, double tempo);

/*
 * Retorna: 1 se houve colisao, 0 senão
 */
int detecta_colisao(corpo* c1, corpo* c2);

/* rotaciona
 *
 * Recebe:	um corpo
 * 			sentido:
 * 				1:	sentido anti-horario
 * 				-1:	sentido horario
 */
void rotaciona(corpo* c, int sentido);
#endif

