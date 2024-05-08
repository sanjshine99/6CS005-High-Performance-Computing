/*Question 1*/
// #include <stdio.h>
// #include <stdlib.h>

// int main(int argc, char *argv[])
// {
//   if (argc != 3)
//   {
//     printf("Usage: %s <name> <age>\n", argv[0]);
//     return 1;
//   }

//   char *name = argv[1];
//   int age = atoi(argv[2]);

//   printf("Hello %s, you are %d years old.\n", name, age);

//   return 0;
// }

/*Question 2*/
// #include <stdio.h>

// int main()
// {
//   char name[100];
//   int age;

//   printf("Enter your name: ");
//   scanf("%s", name);

//   printf("Enter your age: ");
//   scanf("%d", &age);

//   printf("Hello %s, you are %d years old.\n", name, age);

//   return 0;
// }

/*Question 3*/
// #include <stdio.h>

// int main()
// {
//   for (int n = 1; n <= 100; n++)
//   {
//     if (n % 2 == 0)
//     {
//       printf("Bish");
//     }
//     if (n % 3 == 0)
//     {
//       printf("Bash");
//     }
//     if (n % 5 == 0)
//     {
//       printf("Bosh");
//     }
//     if (n % 2 != 0 && n % 3 != 0 && n % 5 != 0)
//     {
//       printf("%d", n);
//     }
//     printf("\n");
//   }
//   return 0;
// }

/*Question 4*/
// #include <stdio.h>
// void swap(int *a, int *b)
// {
//   int temp = *a;
//   *a = *b;
//   *b = temp;
// }
// int main()
// {
//   int a = 3;
//   int b = 4;
//   printf("Before swapping: a is %d and b is %d\n", a, b);
//   swap(&a, &b);
//   printf("After swapping: a is now %d and b is now %d\n", a, b);
//   return 0;
// }

/*Question 5*/
// #include <stdio.h>
// #include <stdlib.h>
// #include <time.h>
// int main()
// {
//   int size;
//   do
//   {
//     printf("Enter the size of the array (between 1 and 50): ");
//     scanf("%d", &size);
//   } while (size < 1 || size > 50);
//   int *numbers = (int *)malloc(size * sizeof(int));
//   if (numbers == NULL)
//   {
//     printf("Memory allocation failed.\n");
//     return 1;
//   }
//   srand(time(NULL));
//   for (int i = 0; i < size; i++)
//   {
//     numbers[i] = rand();
//     printf("%d is %d\n", i, numbers[i]);
//   }
//   free(numbers);
//   return 0;
// }

/*Question 6*/
// URL:https://onlinegdb.com/DMex6uQae
// #include <pthread.h>
// #include <stdio.h>
// #include <stdlib.h>
// #include <unistd.h>

// void *threadFunction(void *p)
// {
//   int id = *(int *)p;
//   for (int i = 0; i < 10; i++)
//   {
//     printf("Thread ID %ld, Thread Number %d: i=%d\n", pthread_self(), id, i);
//     usleep(100000);
//   }
//   free(p);
//   return NULL;
// }

// int main(int argc, char *argv[])
// {
//   if (argc < 2)
//   {
//     printf("Usage: %s <number_of_threads>\n", argv[0]);
//     return 1;
//   }

//   int num_threads = atoi(argv[1]);
//   pthread_t *threads = malloc(num_threads * sizeof(pthread_t));

//   if (threads == NULL)
//   {
//     printf("Failed to allocate memory for thread IDs.\n");
//     return 1;
//   }

//   for (int i = 0; i < num_threads; i++)
//   {
//     int *id = malloc(sizeof(int));
//     *id = i + 1;
//     if (pthread_create(&threads[i], NULL, threadFunction, id) != 0)
//     {
//       printf("Failed to create thread %d\n", i);
//       free(id);
//     }
//   }
//   for (int i = 0; i < num_threads; i++)
//   {
//     pthread_join(threads[i], NULL);
//   }

//   free(threads);
//   return 0;
// }

/*Question 7*/
// 1.
/*
how to run the program:
compile: gcc -o myprog myprog.c -pthread -lm
run: ./myprog
*/
// #include <pthread.h>
// #include <stdio.h>
// #include <stdlib.h>
// #include <math.h>

// #define MAX_NUM 100000
// #define NUM_THREADS 3

// // Function to check if a number is prime
// int is_prime(int num)
// {
//   if (num <= 1)
//     return 0; // 0 and 1 are not prime numbers
//   if (num % 2 == 0 && num != 2)
//     return 0;
//   for (int i = 3; i <= sqrt(num); i += 2)
//   {
//     if (num % i == 0)
//       return 0;
//   }
//   return 1;
// }

//
// void *find_primes(void *arg)
// {
//   int thread_part = *(int *)arg;
//   int start = thread_part * (MAX_NUM / NUM_THREADS) + 1;
//   int end = (thread_part + 1) * (MAX_NUM / NUM_THREADS);
//   if (thread_part == NUM_THREADS - 1)
//     end = MAX_NUM;

//   for (int num = start; num <= end; num++)
//   {
//     if (is_prime(num))
//     {
//       printf("%d is prime\n", num);
//     }
//   }
//   free(arg);
//   return NULL;
// }

// int main()
// {
//   pthread_t threads[NUM_THREADS];

//   // Creating threads
//   for (int i = 0; i < NUM_THREADS; i++)
//   {
//     int *part = malloc(sizeof(int));
//     *part = i;
//     if (pthread_create(&threads[i], NULL, find_primes, part) != 0)
//     {
//       perror("Failed to create thread");
//     }
//   }

//   // Joining threads
//   for (int i = 0; i < NUM_THREADS; i++)
//   {
//     pthread_join(threads[i], NULL);
//   }

//   return 0;
// }

// 2
/*
How to run
compile: gcc -o myprog myprog.c -pthread -lm
run: ./myprog
*/
// #include <pthread.h>
// #include <stdio.h>
// #include <stdlib.h>
// #include <math.h>

// int is_prime(int num)
// {
//   if (num <= 1)
//     return 0;
//   if (num % 2 == 0 && num != 2)
//     return 0;
//   for (int i = 3; i <= sqrt(num); i += 2)
//   {
//     if (num % i == 0)
//       return 0;
//   }
//   return 1;
// }

// void *find_primes(void *arg)
// {
//   int thread_part = *(int *)arg;
//   int num_threads = *((int *)arg + 1);
//   int start = thread_part * (100000 / num_threads) + 1;
//   int end = (thread_part + 1) * (100000 / num_threads);
//   if (thread_part == num_threads - 1)
//     end = 100000;

//   for (int num = start; num <= end; num++)
//   {
//     if (is_prime(num))
//     {
//       printf("%d is prime\n", num);
//     }
//   }
//   free(arg);
//   return NULL;
// }

// int main()
// {
//   int num_threads;
//   printf("Enter the number of threads: ");
//   scanf("%d", &num_threads);

//   pthread_t *threads = malloc(num_threads * sizeof(pthread_t));
//   if (threads == NULL)
//   {
//     fprintf(stderr, "Unable to allocate memory for threads\n");
//     return 1;
//   }

//   for (int i = 0; i < num_threads; i++)
//   {
//     int *arg = malloc(2 * sizeof(int));
//     if (arg == NULL)
//     {
//       fprintf(stderr, "Unable to allocate memory for thread arguments\n");
//       continue;
//     }
//     *arg = i;
//     *(arg + 1) = num_threads;
//     if (pthread_create(&threads[i], NULL, find_primes, arg) != 0)
//     {
//       perror("Failed to create thread");
//     }
//   }

//   for (int i = 0; i < num_threads; i++)
//   {
//     pthread_join(threads[i], NULL);
//   }

//   free(threads);
//   return 0;
// }

// 3
// #include <pthread.h>
// #include <stdio.h>
// #include <stdlib.h>
// #include <math.h>

// int is_prime(int num)
// {
//   if (num <= 1)
//     return 0;
//   if (num % 2 == 0 && num != 2)
//     return 0;
//   for (int i = 3; i <= sqrt(num); i += 2)
//   {
//     if (num % i == 0)
//       return 0;
//   }
//   return 1;
// }

// void *find_primes(void *arg)
// {
//   int thread_part = *(int *)arg;
//   int num_threads = *((int *)arg + 1);
//   int start = thread_part * (100000 / num_threads) + 1;
//   int end = (thread_part + 1) * (100000 / num_threads);
//   if (thread_part == num_threads - 1)
//     end = 100000;

//   int prime_count = 0;
//   for (int num = start; num <= end; num++)
//   {
//     if (is_prime(num))
//     {
//       prime_count++;
//     }
//   }
//   free(arg);
//   int *return_value = malloc(sizeof(int));
//   *return_value = prime_count;
//   pthread_exit(return_value);
// }

// int main()
// {
//   int num_threads;
//   printf("Enter the number of threads: ");
//   scanf("%d", &num_threads);

//   pthread_t *threads = malloc(num_threads * sizeof(pthread_t));
//   if (threads == NULL)
//   {
//     fprintf(stderr, "Unable to allocate memory for threads\n");
//     return 1;
//   }
//   for (int i = 0; i < num_threads; i++)
//   {
//     int *arg = malloc(2 * sizeof(int));
//     if (arg == NULL)
//     {
//       fprintf(stderr, "Unable to allocate memory for thread arguments\n");
//       continue;
//     }
//     *arg = i;
//     *(arg + 1) = num_threads;
//     if (pthread_create(&threads[i], NULL, find_primes, arg) != 0)
//     {
//       perror("Failed to create thread");
//     }
//   }
//   for (int i = 0; i < num_threads; i++)
//   {
//     int *prime_count;
//     pthread_join(threads[i], (void **)&prime_count);
//     printf("Thread %d found %d prime numbers.\n", i, *prime_count);
//     free(prime_count);
//   }

//   free(threads);
//   return 0;
// }

// 4
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_PRIMES 5

int is_prime(int num)
{
  if (num <= 1)
    return 0;
  if (num % 2 == 0 && num != 2)
    return 0;
  for (int i = 3; i <= sqrt(num); i += 2)
  {
    if (num % i == 0)
      return 0;
  }
  return 1;
}

void *find_primes(void *arg)
{
  int thread_part = *(int *)arg;
  int num_threads = *((int *)arg + 1);
  int start = thread_part * (100000 / num_threads) + 1;
  int end = (thread_part + 1) * (100000 / num_threads);
  if (thread_part == num_threads - 1)
    end = 100000;

  pthread_setcancelstate(PTHREAD_CANCEL_ENABLE, NULL);
  pthread_setcanceltype(PTHREAD_CANCEL_DEFERRED, NULL);

  int prime_count = 0;
  for (int num = start; num <= end; num++)
  {
    if (is_prime(num))
    {
      prime_count++;
      if (prime_count == MAX_PRIMES)
      {
        break;
      }
    }
  }

  free(arg);
  int *return_value = malloc(sizeof(int));
  *return_value = prime_count;
  pthread_exit(return_value);
}

int main()
{
  int num_threads;
  printf("Enter the number of threads: ");
  scanf("%d", &num_threads);

  pthread_t *threads = malloc(num_threads * sizeof(pthread_t));
  if (threads == NULL)
  {
    fprintf(stderr, "Unable to allocate memory for threads\n");
    return 1;
  }

  for (int i = 0; i < num_threads; i++)
  {
    int *arg = malloc(2 * sizeof(int));
    if (arg == NULL)
    {
      fprintf(stderr, "Unable to allocate memory for thread arguments\n");
      continue;
    }
    *arg = i;
    *(arg + 1) = num_threads;
    if (pthread_create(&threads[i], NULL, find_primes, arg) != 0)
    {
      perror("Failed to create thread");
    }
  }

  for (int i = 0; i < num_threads; i++)
  {
    int *prime_count;
    pthread_join(threads[i], (void **)&prime_count);
    printf("Thread %d found %d prime numbers (stopped after finding 5).\n", i, *prime_count);
    free(prime_count);
  }

  free(threads);
  return 0;
}
