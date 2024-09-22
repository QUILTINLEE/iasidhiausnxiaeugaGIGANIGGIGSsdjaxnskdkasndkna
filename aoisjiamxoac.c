#include <stdio.h>
#include <pthread.h>


// Thread 1       || Thread 2
//                || 
// int a = 5;     ||int x = 5;
// int b = 15;    ||int y = 10;
// int c = 0;     ||int z = 0;
// c += a + b;    ||z += x + y;


// Thread 1       || Thread 2
//                || 
// int a = 5;     ||
//                ||int x = 5;
// int b = 15;    ||
// int c = 0      ||
//                ||int y = 10;
//                ||int z = 0;
// c += a + b;    ||
//                ||z += x + y;




int a = 5;
int b = 15;
int c = 0;
int z = 0;

void *sum( void *arg) {
    
int x = 5;
int y = 10;


    z += x + y;
 
}

void *plus( void *arg) {
    
    c += a + b;
    
}


int main() {
    pthread_t thread1, thread2;

    pthread_create(&thread1, NULL, sum, NULL);
    pthread_create(&thread2, NULL, plus, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);



    printf("Final sum: %d\n", z);
    printf("Final plus: %d\n", c);

    return 0;
}
