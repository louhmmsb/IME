/* Implementação da biblioteca vetores (libvetor) */

#include "vetores.h" /* Protótipo das funções relacionadas à estrutura vetor*/
#include <math.h> /* sqrt ... */


/* Implementação das funções */

/* Nota: definição do struct vetor 
 *   
 *   typedef struct {
 *         double x;
 *         double y;
 *   } vetor;
 *
*/

/* soma_vetor 
 *
 * Recebe: dois vetores (u, v)
 * Retorna: vetor w (u + v) 
 */
vetor soma_vetor (vetor u, vetor v)
{
    vetor w; /* vetor que será retornado pela função */

    w.x = u.x + v.x;
    w.y = u.y + v.y;

    return w;
}


/* subtrai_vetor
 *
 * Recebe: dois vetores (u, v)
 * Retorna: vetor s (u - v) 
 */
vetor subtrai_vetor (vetor u, vetor v)
{
    vetor w;

    w.x = u.x - v.x;
    w.y = u.y - v.y;

    return w;
}


/* real_vetor
 * 
 * Recebe: um real r, um vetor v
 * Retorna: r * v
*/
vetor real_vetor (double r, vetor v)
{
   vetor w;

   w.x = r * v.x;
   w.y = r * v.y;

   return w;
}


/* produto_escalar
 *
 * Recebe: dois vetores (u, v)
 * Retorna: um número real (produto escalar de u com v)
 */
double produto_escalar (vetor u, vetor v)
{
   double escalar;

   escalar = (u.x * v.x) + (u.y * v.y);

   return escalar;
}


/* normaliza
 *
 * Recebe: vetor v
 * Retorna: vetor w com norma 1, ie, w = (v/(||v||))
 */
vetor normaliza (vetor v)
{
   double norma;
   vetor w;

   norma = sqrt(produto_escalar(v, v));

   w.x = v.x/norma;
   w.y = v.y/norma;

   return w;
}

/* inverte_vetor
 *
 * Recebe: um vetor v
 * Retorna: vetor w, tal que: w = -v
 */
vetor inverte_vetor (vetor v)
{
    vetor w;

    w.x = -(v.x);
    w.y = -(w.y);

    return w;
}

