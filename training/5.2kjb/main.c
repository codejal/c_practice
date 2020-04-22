#include <stdio.h>
#include <stdlib.h>
#include "expr.h"
expression expr1;
expression expr2;
expression result_add;
expression result_sub;

struct term *term1P, *term2P;

int main(void)
{
    /* Construct expression 1 */
    createExpr(&expr1); // Get the start pointer set
    insertTerm(&expr1, 10, 1000);
    insertTerm(&expr1, 100, 2000);
    insertTerm(&expr1, -10, 500);
    insertTerm(&expr1, -10, -1000);
    printf("Expression_1 = ");
    printExpr(&expr1);

    /* Construct expression 2 */
    createExpr(&expr2); // Get the start pointer set
    expr2 = expr1;
    printf("Expression_2 = ");
    printExpr(&expr2);

    /* Construct result = expr1 + expr2 */
    createExpr(&result_add);
    term1P = getFirstTerm(&expr1);
    term2P = getFirstTerm(&expr2);
    while (term1P != NULL || term2P != NULL)
    {
        if (term1P == NULL)
        {
            insertTerm(&result_add, term2P->coeff, term2P->power);
            term2P = getNextTerm(&expr2, term2P);
            continue;
        }
        if (term2P == NULL)
        {
            insertTerm(&result_add, term1P->coeff, term1P->power);
            term1P = getNextTerm(&expr1, term1P);
            continue;
        }
        if (term1P->power == term2P->power)
        {
            if (term1P->coeff + term2P->coeff != 0)
                insertTerm(&result_add, term1P->coeff + term2P->coeff, term2P->power);

            term2P = getNextTerm(&expr2, term2P);
            term1P = getNextTerm(&expr1, term1P);
            continue;
        }
        if (term1P->power > term2P->power)
        {
            insertTerm(&result_add, term1P->coeff, term1P->power);
            term1P = getNextTerm(&expr1, term1P);
            continue;
        }
        if (term1P->power < term2P->power)
        {
            insertTerm(&result_add, term2P->coeff, term2P->power);
            term2P = getNextTerm(&expr2, term2P);
            continue;
        }
    }
    printf("Expression_1 + Expression_2 = ");
    printExpr(&result_add);
    expr2 = expr1;
    createExpr(&result_sub);
    term1P = getFirstTerm(&expr1);
    term2P = getFirstTerm(&expr2);
    while (term1P != NULL || term2P != NULL)
    {
        if (term1P == NULL)
        {
            insertTerm(&result_sub, (-1) * term2P->coeff, term2P->power);
            term2P = getNextTerm(&expr2, term2P);
            continue;
        }
        else if (term2P == NULL)
        {
            insertTerm(&result_sub, term1P->coeff, term1P->power);
            term1P = getNextTerm(&expr1, term1P);
            continue;
        }
        else if (term1P->power == term2P->power)
        {
            if (term1P->coeff - term2P->coeff != 0)
                insertTerm(&result_sub, term1P->coeff - term2P->coeff, term2P->power);

            term2P = getNextTerm(&expr2, term2P);
            term1P = getNextTerm(&expr1, term1P);
            continue;
        }
        else if (term1P->power > term2P->power)
        {
            insertTerm(&result_sub, term1P->coeff, term1P->power);
            term1P = getNextTerm(&expr1, term1P);
            continue;
        }
        else if (term1P->power < term2P->power)
        {
            insertTerm(&result_sub, (-1) * term2P->coeff, term2P->power);
            term2P = getNextTerm(&expr2, term2P);
            continue;
        }
        else
            result_sub = 0;
    }
    printf("Expression_1 - Expression_2 = 0");
    printExpr(&result_sub);

    return 0;
}