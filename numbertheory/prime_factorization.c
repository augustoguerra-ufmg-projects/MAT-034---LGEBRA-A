// arquivo :	prime_factorization.c
// descricao :	implementacao de um algoritmo simples para fatorar um numero inteiro positivo n em numeros primos
// autor :	Augusto Guerra de Lima - augustoguerra@dcc.ufmg.br
// historico :	20241029 arquivo criado

#include<stdio.h>
#include<stdlib.h>

// estrutura auxiliar para armazenar fatores primos
typedef
struct primes
{
	int prime;
	struct primes* next;
}primes_t;

typedef primes_t* primes_ptr;

// um numero n que nao e primo pode ser fatorado em fatores nao triviais i.e != {1,n} 
// t.q. n=ab onde a,b <= sqrt(n) 
// certamente entao ha um fator entre 2 e o piso da raiz quadrada de n
// se o laco de iteracao atinge a raiz de n entao a fatoracao passa para o processo de finalizacao
// se a e b nao sao primos entao a=km e b=qt e assim por diante ate atingir um primo
// portanto a fatoracao termina

// Entrada :	um inteiro positivo n
// Saida :	uma lista encadeada com a fatoracao de n em primos

// Complexidade :	O(sqrt(n)) no laco while

primes_ptr prime_factorization(int n)
{
	primes_ptr factors = NULL;
	primes_ptr p = NULL;

	for(int i=2; i*i <= n; i++)
	{
		while(n%i==0)
		{
			primes_ptr q=(primes_ptr)malloc(sizeof(primes_t));
			q->prime=i;
			q->next=NULL;

			if(factors==NULL)
				factors=q;
			else 
				p->next=q;

			p=q;
			n/=i;	
		}
	}
	if(n>1)
	{
		primes_ptr q=(primes_ptr)malloc(sizeof(primes_t));
		q->prime=n;
		q->next=NULL;

		if(factors==NULL)
			factors=q;
		else 
			p->next=q;

		p=q;
	}

	return(factors);
}


// metodo opcional para vizualizar os fatores primos
/*
void print_prime_factorization(primes_ptr p)
{
	primes_ptr i=p;
	printf("[");
	while(i!=NULL)
	{
		printf("%d,",i->prime);
		i=i->next;
	}
	printf("]\n");
}
*/
