/* Declaração das funções e estruas responsáveis para 
 * trabalhar com vetores em duas dimensões
 *
 * Pressupõe que os vetores tem a mesma base ortonormal 
 */

#ifndef VETORES
#define VETORES

/* Estrutura do vetor em duas dimenões */ 
typedef struct
{
    double x; /* componente x do vetor (abscissas) */
    double y; /* componente y dos vetores (ordenadas) */

} vetor;


/* soma_vetor
 *
 * Recebe: dois vetores u, v
 * Retorna: vetor u + v
 */
vetor soma_vetor (vetor u, vetor v);


/* subtrai_vetor
 *
 * Recebe: dois vetores u, v
 * Retorna vetor u - v
 */
vetor subtrai_vetor (vetor u, vetor v);


/* real_vetor
 *
 * Recebe: um real r
 * Recebe: um vetor v
 * Retorna: r * v
 */
vetor real_vetor (double r, vetor v);


/* produto_escalar
 *
 * Recebe: dois vetores (u, v)
 * Retorna: um número real (o produto escalar entre u e v)
 */
double produto_escalar (vetor u, vetor v);


/* normaliza
 *
 * Recebe: vetor v
 * Retorna: vetor w com norma 1, ie, w = v/(||v||)
 */
vetor normaliza (vetor v);


/* inverte_vetor
 *
 * Recebe: vetor v
 * Retorna: vetor w, tal que, w = -v
 */
vetor inverte_vetor (vetor v);

#endif

