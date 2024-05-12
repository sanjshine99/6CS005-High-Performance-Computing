/**********Before**********/
// compile : gcc -o myprog myprog.c -pthread -lm
// run : ./myprog
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include <pthread.h>
// #include <unistd.h>

// char *messages[3] = {NULL, NULL, NULL};

// void *messenger(void *p)
// {
//     long tid = (long)p;
//     char tmpbuf[100];

//     for (int i = 0; i < 10; i++)
//     {

//         long int dest = (tid + 1) % 3;
//         sprintf(tmpbuf, "Hello from Thread %ld!", tid);
//         char *msg = strdup(tmpbuf);
//         messages[dest] = msg;
//         printf("Thread %ld sent the message to Thread %ld\n", tid, dest);

//         printf("Thread %ld received the message '%s'\n", tid, messages[tid]);
//         free(messages[tid]);
//         messages[tid] = NULL;
//     }
//     return NULL;
// }

// void main()
// {
//     pthread_t thrID1, thrID2, thrID3;

//     pthread_create(&thrID1, NULL, messenger, (void *)0);
//     pthread_create(&thrID2, NULL, messenger, (void *)1);
//     pthread_create(&thrID3, NULL, messenger, (void *)2);
//     pthread_join(thrID1, NULL);
//     pthread_join(thrID2, NULL);
//     pthread_join(thrID3, NULL);
// }

/***Using busy waiting***/
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include <pthread.h>
// #include <unistd.h>

// char *messages[3] = {NULL, NULL, NULL};
// volatile int turn = 0;

// void *messenger(void *p)
// {
//     long tid = (long)p;
//     char tmpbuf[100];

//     for (int i = 0; i < 10; i++)
//     {
//         if (tid == 0)
//         {
//             while (turn != 0)
//                 ;
//             sprintf(tmpbuf, "Hello from Thread %ld!", tid);
//             messages[1] = strdup(tmpbuf);
//             printf("Thread %ld sent the message to Thread 1\n", tid);
//             turn = 1;
//         }
//         if (tid == 1)
//         {
//             while (turn != 1)
//                 ;
//             printf("Thread %ld received the message '%s'\n", tid, messages[1]);
//             free(messages[1]);
//             messages[1] = NULL;

//             sprintf(tmpbuf, "Hello from Thread %ld!", tid);
//             messages[2] = strdup(tmpbuf);
//             printf("Thread %ld sent the message to Thread 2\n", tid);
//             turn = 2;
//         }

//         if (tid == 2)
//         {
//             while (turn != 2)
//                 ;
//             printf("Thread %ld received the message '%s'\n", tid, messages[2]);
//             free(messages[2]);
//             messages[2] = NULL;

//             sprintf(tmpbuf, "Hello from Thread %ld!", tid);
//             messages[0] = strdup(tmpbuf);
//             printf("Thread %ld sent the message to Thread 0\n", tid);
//             turn = 0;
//         }

//         if (tid == 0)
//         {
//             while (turn != 0)
//                 ;
//             printf("Thread %ld received the message '%s'\n", tid, messages[0]);
//             free(messages[0]);
//             messages[0] = NULL;
//         }
//     }
//     return NULL;
// }

// int main()
// {
//     pthread_t thrID1, thrID2, thrID3;

//     pthread_create(&thrID1, NULL, messenger, (void *)0);
//     pthread_create(&thrID2, NULL, messenger, (void *)1);
//     pthread_create(&thrID3, NULL, messenger, (void *)2);

//     pthread_join(thrID1, NULL);
//     pthread_join(thrID2, NULL);
//     pthread_join(thrID3, NULL);

//     return 0;
// }

/***Mutex***/
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include <pthread.h>
// #include <semaphore.h>
// #include <unistd.h>

// char *messages[3] = {NULL, NULL, NULL};
// sem_t sems[3];

// void *messenger(void *p)
// {
//     long tid = (long)p;
//     long dest = (tid + 1) % 3;
//     char tmpbuf[100];

//     for (int i = 0; i < 10; i++)
//     {

//         sem_wait(&sems[tid]);

//         if (messages[tid] != NULL)
//         {
//             printf("Thread %ld received the message '%s'\n", tid, messages[tid]);
//             free(messages[tid]);
//             messages[tid] = NULL;
//         }

//         sprintf(tmpbuf, "Hello from Thread %ld!", tid);
//         messages[dest] = strdup(tmpbuf);
//         printf("Thread %ld sent the message to Thread %ld\n", tid, dest);

//         sem_post(&sems[dest]);
//     }
//     return NULL;
// }

// int main()
// {
//     pthread_t threads[3];

//     sem_init(&sems[0], 0, 1);
//     sem_init(&sems[1], 0, 0);
//     sem_init(&sems[2], 0, 0);

//     for (long i = 0; i < 3; i++)
//     {
//         pthread_create(&threads[i], NULL, messenger, (void *)i);
//     }

//     for (int i = 0; i < 3; i++)
//     {
//         pthread_join(threads[i], NULL);
//     }

//     for (int i = 0; i < 3; i++)
//     {
//         sem_destroy(&sems[i]);
//     }

//     return 0;
// }

/***Using Semaphores***/
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define NUM_THREADS 3
#define NUM_ITERATIONS 10

sem_t sems[NUM_THREADS];
char *messages[NUM_THREADS] = {NULL, NULL, NULL};

void *messenger(void *p)
{
    long tid = (long)p;
    long dest = (tid + 1) % NUM_THREADS;
    for (int i = 0; i < NUM_ITERATIONS; i++)
    {
        sem_wait(&sems[tid]);
        if (messages[tid] != NULL)
        {
            printf("Thread %ld received the message '%s'\n", tid, messages[tid]);
            free(messages[tid]);
            messages[tid] = NULL;
        }
        char *msg = malloc(50 * sizeof(char));
        sprintf(msg, "Hello from Thread %ld!", tid);
        messages[dest] = msg;
        printf("Thread %ld sent the message to Thread %ld\n", tid, dest);
        sem_post(&sems[dest]);
        usleep(100000);
    }
    return NULL;
}

int main()
{
    pthread_t threads[NUM_THREADS];
    for (int i = 0; i < NUM_THREADS; i++)
    {
        sem_init(&sems[i], 0, i == 0 ? 1 : 0);
    }
    for (long i = 0; i < NUM_THREADS; i++)
    {
        pthread_create(&threads[i], NULL, messenger, (void *)i);
    }
    for (int i = 0; i < NUM_THREADS; i++)
    {
        pthread_join(threads[i], NULL);
    }
    for (int i = 0; i < NUM_THREADS; i++)
    {
        sem_destroy(&sems[i]);
    }

    return 0;
}
