## Nomes de variáveis 

Aqui está uma lista de palavras-chave reservadas em C que não podem ser usadas como nomes de variáveis:

- _Bool
- default
- if
- sizeof
- while
- _Complex
- do
- inline
- static
- _Imaginary
- double
- int
- struct
- auto
- else
- long
- switch
- break
- enum
- register
- typedef
- case
- extern
- restrict
- union
- char
- float
- return
- unsigned
- const
- for
- short
- void
- continue
- goto
- signed
- volatile

## Tamanho

<table>
  <tr>
    <th>Tipo</th>
    <th>Significado</th>
    <th>Tamanho (bytes)</th>
    <th>Tamanho (bits)</th>
  </tr>
  <tr>
    <td>char</td>
    <td>um único byte, capaz de conter um caractere</td>
    <td>1 byte</td>
    <td>8 bits</td>
  </tr>
  <tr>
    <td>int</td>
    <td>um inteiro</td>
    <td>4 bytes</td>
    <td>32 bits</td>
  </tr>
  <tr>
    <td>float</td>
    <td>número de ponto flutuante de precisão simples</td>
    <td>4 bytes</td>
    <td>32 bits</td>
  </tr>
  <tr>
    <td>double</td>
    <td>número de ponto flutuante de precisão dupla</td>
    <td>8 bytes</td>
    <td>64 bits</td>
  </tr>
</table>

## Representação 

<table>
  <tr>
    <th>Qualificador</th>
    <th>Tamanho (bytes)</th>
    <th>Tamanho (bits)</th>
  </tr>
  <tr>
    <td>short int</td>
    <td>2 bytes</td>
    <td>16 bits</td>
  </tr>
  <tr>
    <td>long int</td>
    <td>8 bytes</td>
    <td>64 bits</td>
  </tr>
  <tr>
    <td>long double</td>
    <td>16 bytes</td>
    <td>128 bits</td>
  </tr>
</table>


### Os códigos de ASCII variam de 0 a 255
- O alfabeto maiúsculo começa em 65 ( A) e termina em 90 ( Z); o alfabeto minúsculo começa em 97 ( a) e termina em 122 ( z). Outros símbolos, como (, !, Tab, retorno de carro, etc., também são representados na tabela ASCII.

# Semelhantes

```c
#include <stdio.h>

int main() {
  int i;
  for (i=1; i<=10; i++) {
    if ((i % 2) != 0) {
      printf("%d is odd\n", i);
    }
    else {
      printf("%d is even\n", i);
    }
  }
}
```

```c
#include <stdio.h>

int main() {
  int i;
  for (i=1; i<=10; i++) {
    (i % 2) ? printf("%d is odd\n", i) : printf("%d is even\n", i);
  }
}
```

> condition ? expression1 : expression2

## Newton method

```c
#include <stdio.h>

int main(int argc, char **argv)
{
  double x2 = 4;
  double x0 = 10;
  double xi;
  int i;
  for (i=0; i<5; i++) {
    xi = x0 - ( ((x0*x0) - x2) / (2*x0) );
    printf("x%d = %.12f, x%d = %.12f\n", i, x0, i+1, xi);
    x0 = xi;
  }
  return 0;
} 
```
## Triângulo 
```c
#include <stdio.h>

int main(int argc, char **argv)
{
  int n=6;
  int i, j;
  for (i=0; i<=n; i++)
  {
    for (j=0; j<(n-i); j++)
    { 
      printf(" "); 
    }
    for(j=(n-i); j<(n-i)+((2*i)-1); j++)
    { 
      printf("*"); 
    }
    printf("\n");
  }
  return 0;
}
```
## Fibonacci
```c
#include <stdio.h>

int Fibonacci(int n) {
    if (n==0) return 0;
    else if (n==1) return 1;
    else return Fibonacci(n-1) + Fibonacci(n-2);
}

int main() {
    int n = 10;
    int Fn = Fibonacci(n);
    printf("Fibonacci(%d) = %d\n", n, Fn);
    return 0;
}
```
