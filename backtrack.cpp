#include<iostream>
#include<stdio.h>
#define NMAX 8
#define MAXCANDIDATES 2
#define FALSE 0
#define TRUE 1

int finished = FALSE;               /* found all solutions yet? */
int is_a_solution(int a[], int k, int n)
{
        return (k == n);                /* is k == n? */
}

void construct_candidates(int a[], int k, int n, int c[], int *ncandidates)
{
        c[0] = TRUE;
        c[1] = FALSE;
        *ncandidates = 2;
}


void process_solution(int a[], int k)
{
    int i;
    printf("{");
    for (i=1; i<=k; i++) /* counter */
        if (a[i] == TRUE) printf(" %d",i);
    printf("}\n");
}


void backtrack(int a[], int k, int input)
{
    int c[MAXCANDIDATES];  /* candidates for next position */
    int ncandidates; /* next position candidate count */
    int i; /* counter */

    if (is_a_solution(a,k,input))
        process_solution(a,k);
    else 
    {
            k = k+1;
            construct_candidates(a,k,input,c,&ncandidates);
            for (i=0; i<ncandidates; i++) 
            {
                a[k] = c[i];
                backtrack(a,k,input);
                if (finished) return; /* terminate early */
            } 
    }
}

int main () {

    int a[NMAX];                    /* solution vector */
    backtrack(a,0,3);
}


