/****Question 1****/
// #include <stdio.h>
// #include <stdlib.h>

// #define ROWS 10
// #define COLS 15

// int main()
// {
//     FILE *file = fopen("Data1.txt", "r");
//     if (!file)
//     {
//         perror("Error opening file");
//         return EXIT_FAILURE;
//     }

//     // Allocate memory for data array
//     int data[ROWS][COLS];
//     double normalized[ROWS][COLS];
//     int i, j;

//     // Read data into array
//     for (i = 0; i < ROWS; i++)
//     {
//         for (j = 0; j < COLS; j++)
//         {
//             fscanf(file, "%d", &data[i][j]);
//         }
//     }

//     // Close the file
//     fclose(file);

//     // Normalize data
//     for (j = 0; j < COLS; j++)
//     {
//         int min = data[0][j];
//         int max = data[0][j];

//         // Find min and max in each column
//         for (i = 0; i < ROWS; i++)
//         {
//             if (data[i][j] < min)
//                 min = data[i][j];
//             if (data[i][j] > max)
//                 max = data[i][j];
//         }

//         // Normalize the column
//         for (i = 0; i < ROWS; i++)
//         {
//             normalized[i][j] = (double)(data[i][j] - min) / (max - min);
//         }
//     }

//     // Print normalized data
//     printf("Normalized Data:\n");
//     for (i = 0; i < ROWS; i++)
//     {
//         for (j = 0; j < COLS; j++)
//         {
//             printf("%.2f ", normalized[i][j]);
//         }
//         printf("\n");
//     }

//     return 0;
// }

/****Question 2****/
// #include <stdio.h>
// #include <stdlib.h>

// #define ROWS 10
// #define COLS 15

// int main()
// {
//     FILE *file = fopen("Data1.txt", "r");
//     if (file == NULL)
//     {
//         perror("Error opening file");
//         return EXIT_FAILURE;
//     }

//     // Dynamically allocate memory for the original and flipped arrays
//     int **original = malloc(ROWS * sizeof(int *));
//     int **flipped = malloc(ROWS * sizeof(int *));
//     for (int i = 0; i < ROWS; i++)
//     {
//         original[i] = malloc(COLS * sizeof(int));
//         flipped[i] = malloc(COLS * sizeof(int));
//     }

//     // Read data into the original array
//     for (int i = 0; i < ROWS; i++)
//     {
//         for (int j = 0; j < COLS; j++)
//         {
//             if (fscanf(file, "%d,", &original[i][j]) != 1)
//             {
//                 fprintf(stderr, "Error reading data\n");
//                 fclose(file);
//                 return EXIT_FAILURE;
//             }
//         }
//     }

//     // Close the file
//     fclose(file);

//     // Flip the data from top to bottom
//     for (int i = 0; i < ROWS; i++)
//     {
//         for (int j = 0; j < COLS; j++)
//         {
//             flipped[ROWS - 1 - i][j] = original[i][j];
//         }
//     }

//     // Print flipped data for verification
//     printf("Flipped Data:\n");
//     for (int i = 0; i < ROWS; i++)
//     {
//         for (int j = 0; j < COLS; j++)
//         {
//             printf("%d ", flipped[i][j]);
//         }
//         printf("\n");
//     }

//     // Free dynamically allocated memory
//     for (int i = 0; i < ROWS; i++)
//     {
//         free(original[i]);
//         free(flipped[i]);
//     }
//     free(original);
//     free(flipped);

//     return 0;
// }

/****Question 3****/
// #include <stdio.h>
// #include <stdlib.h>
// #include <stdbool.h>

// #define ROWS 10
// #define COLS 15

// bool isPrime(int num)
// {
//     if (num <= 1)
//         return false;
//     if (num % 2 == 0 && num > 2)
//         return false; // Quick check for even numbers
//     for (int i = 3; i * i <= num; i += 2)
//     {
//         if (num % i == 0)
//             return false;
//     }
//     return true;
// }

// int main()
// {
//     FILE *file = fopen("Data1.txt", "r");
//     if (!file)
//     {
//         perror("Error opening file");
//         return EXIT_FAILURE;
//     }

//     // Dynamically allocate memory for the prime array
//     int **primeArray = malloc(ROWS * sizeof(int *));
//     for (int i = 0; i < ROWS; i++)
//     {
//         primeArray[i] = malloc(COLS * sizeof(int));
//     }

//     // Read data and process primes
//     int num;
//     for (int i = 0; i < ROWS; i++)
//     {
//         for (int j = 0; j < COLS; j++)
//         {
//             if (fscanf(file, "%d,", &num) != 1)
//             {
//                 fprintf(stderr, "Error reading data\n");
//                 fclose(file);
//                 return EXIT_FAILURE;
//             }
//             primeArray[i][j] = isPrime(num) ? num : -1;
//         }
//     }

//     // Close the file
//     fclose(file);

//     // Print the prime filtered data for verification
//     printf("Prime Filtered Data:\n");
//     for (int i = 0; i < ROWS; i++)
//     {
//         for (int j = 0; j < COLS; j++)
//         {
//             printf("%d ", primeArray[i][j]);
//         }
//         printf("\n");
//     }

//     // Free dynamically allocated memory
//     for (int i = 0; i < ROWS; i++)
//     {
//         free(primeArray[i]);
//     }
//     free(primeArray);

//     return 0;
// }

/****Question 4****/
/***Create 3D array using malloc and save it in a new file***/
// #include <stdio.h>
// #include <stdlib.h>

// #define NUM_FILES 6
// #define ROWS 10
// #define COLS 15

// int ***allocate3DArray(int rows, int cols, int depth)
// {
//     int ***arr = (int ***)malloc(depth * sizeof(int **));
//     for (int i = 0; i < depth; i++)
//     {
//         arr[i] = (int **)malloc(rows * sizeof(int *));
//         for (int j = 0; j < rows; j++)
//         {
//             arr[i][j] = (int *)malloc(cols * sizeof(int));
//         }
//     }
//     return arr;
// }

// void free3DArray(int ***arr, int rows, int depth)
// {
//     for (int i = 0; i < depth; i++)
//     {
//         for (int j = 0; j < rows; j++)
//         {
//             free(arr[i][j]);
//         }
//         free(arr[i]);
//     }
//     free(arr);
// }

// void loadData(int ***arr, int depth)
// {
//     char filename[20];
//     FILE *fp;

//     for (int i = 0; i < depth; i++)
//     {
//         sprintf(filename, "Data%d.txt", i + 1); // Assuming filenames are Data1.txt, Data2.txt, etc.
//         fp = fopen(filename, "r");
//         if (fp == NULL)
//         {
//             printf("Error opening file %s\n", filename);
//             exit(1);
//         }

//         for (int j = 0; j < ROWS; j++)
//         {
//             for (int k = 0; k < COLS; k++)
//             {
//                 if (fscanf(fp, "%d,", &arr[i][j][k]) != 1)
//                 {
//                     printf("Error reading file %s\n", filename);
//                     exit(1);
//                 }
//             }
//         }

//         fclose(fp);
//     }
// }

// void saveData(int ***arr, int depth)
// {
//     FILE *fp = fopen("Data3D.txt", "w");
//     if (fp == NULL)
//     {
//         printf("Error opening file for writing\n");
//         exit(1);
//     }

//     for (int i = 0; i < depth; i++)
//     {
//         for (int j = 0; j < ROWS; j++)
//         {
//             for (int k = 0; k < COLS; k++)
//             {
//                 fprintf(fp, "%d,", arr[i][j][k]);
//             }
//             fprintf(fp, "\n");
//         }
//         fprintf(fp, "\n");
//     }

//     fclose(fp);
// }

// int main()
// {
//     int ***data3D = allocate3DArray(ROWS, COLS, NUM_FILES);

//     loadData(data3D, NUM_FILES);

//     // Save the data to Data3D.txt
//     saveData(data3D, NUM_FILES);

//     // Free allocated memory
//     free3DArray(data3D, ROWS, NUM_FILES);

//     return 0;
// }

/***question 1 on newly created file***/
// #include <stdio.h>
// #include <stdlib.h>
// #include <limits.h>

// #define NUM_FILES 6
// #define ROWS 10
// #define COLS 15

// void normalizeData()
// {
//     // Open the Data3D.txt file for reading
//     FILE *fp_in = fopen("Data3D.txt", "r");
//     if (fp_in == NULL)
//     {
//         printf("Error opening file for reading\n");
//         exit(1);
//     }

//     int value;
//     int min = INT_MAX; // Initialize min to the maximum possible integer value
//     int max = INT_MIN; // Initialize max to the minimum possible integer value

//     // Find the minimum and maximum values in the dataset
//     while (fscanf(fp_in, "%d,", &value) == 1)
//     {
//         if (value < min)
//         {
//             min = value;
//         }
//         if (value > max)
//         {
//             max = value;
//         }
//     }

//     // Close the file
//     fclose(fp_in);

//     // Reopen the file for writing
//     FILE *fp_out = fopen("NormalizedData3D.txt", "w");
//     if (fp_out == NULL)
//     {
//         printf("Error opening file for writing\n");
//         exit(1);
//     }

//     // Open the Data3D.txt file again for reading
//     fp_in = fopen("Data3D.txt", "r");
//     if (fp_in == NULL)
//     {
//         printf("Error opening file for reading\n");
//         exit(1);
//     }

//     // Normalize and write the data to the output file
//     while (fscanf(fp_in, "%d,", &value) == 1)
//     {
//         double scaled_value = (double)(value - min) / (max - min);
//         fprintf(fp_out, "%.6f,", scaled_value);
//     }

//     // Close the files
//     fclose(fp_in);
//     fclose(fp_out);
// }

// int main()
// {
//     normalizeData();
//     printf("Normalization complete.\n");
//     return 0;
// }
/***replace the not prime numbers with -1***/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define NUM_FILES 6
#define ROWS 10
#define COLS 15

bool isPrime(int n)
{
    if (n <= 1)
    {
        return false;
    }
    if (n <= 3)
    {
        return true;
    }
    if (n % 2 == 0 || n % 3 == 0)
    {
        return false;
    }
    for (int i = 5; i * i <= n; i += 6)
    {
        if (n % i == 0 || n % (i + 2) == 0)
        {
            return false;
        }
    }
    return true;
}

void replaceNonPrimes()
{
    FILE *fp_in = fopen("Data3D.txt", "r");
    if (fp_in == NULL)
    {
        printf("Error opening file for reading\n");
        exit(1);
    }

    FILE *fp_out = fopen("PrimeNumbersData3D.txt", "w");
    if (fp_out == NULL)
    {
        printf("Error opening file for writing\n");
        exit(1);
    }

    int value;
    while (fscanf(fp_in, "%d,", &value) == 1)
    {
        if (isPrime(value))
        {
            fprintf(fp_out, "%d,", value);
        }
        else
        {
            fprintf(fp_out, "-1,");
        }
    }

    fclose(fp_in);
    fclose(fp_out);
}

int main()
{
    replaceNonPrimes();
    printf("Replacement of non-prime numbers complete.\n");
    return 0;
}
