#include <stdio.h>
#include <string.h>
#define MAX_STR_LENGTH 20


int cumulative(int n)                    // Calculate cumulative sum from zero to "n"
{
    if (n==0)
        return 0;
    else
        return n + cumulative(n-1);
}

unsigned long long factorial(int n)   // Calculate factorial of "n"
{
    if ((n==0)||(n==1))
        return 1;
    else
        return n*factorial(n-1);
}

int nth_fibonacci(int n)              // Find the nth number in fibonacci sequence (0, 1, 1, 2, 3, 5, 8...). Eg: 0 is the 1st fibonacci number, 1 is the second, 1 is third etc.
{
    if ((n==1)||(n==2))
        return n-1;
    else
        return nth_fibonacci(n-1) + nth_fibonacci(n-2);
}

long long array_product(int arr[], int size, int current_idx)      // Calculate the product of all elements of an array
{
    if (current_idx==size-1)
        return arr[current_idx];
    else
        return arr[current_idx]* array_product(arr, size, current_idx+1);
}

int is_palindrome(char *input_string, int length, int current_idx)         // Check if a string is palindrome
{
    if (current_idx>=length-1-current_idx)
        return 1;
    else if (input_string[current_idx]!=input_string[length-1-current_idx])
        return 0;
    else
        return is_palindrome(input_string, length, current_idx+1);
}

void string_reverse(char *input_string, int length, int current_idx)      // Reverse an input string
{
    if (current_idx>=length-1-current_idx)
        return ;
    else
    {
        char ch=input_string[current_idx];
        input_string[current_idx] = input_string[length-1-current_idx];
        input_string[length-1-current_idx] = ch;
        return string_reverse(input_string, length, current_idx+1);
    }
}

int main()
{
    
    int n;
    printf("\nEnter a number: ");
    scanf("%d",&n);
    
    printf("\nCumulative Sum(n) = %d",cumulative(n));
    
    printf("\nFactorial(n) = %llu", factorial(n));
    
    printf("\nFibonacci(n) = %d", nth_fibonacci(n));
    
    int arr[n];
    printf("\n\nEnter %d elements of the array separated by space: ",n);
    for(int i=0; i<n; i++)
        scanf("%d",&arr[i]);
    printf("Array product: %lld",array_product(arr, n, 0));
    
    char str[MAX_STR_LENGTH];
    printf("\nEnter a string (max characters %d): ", MAX_STR_LENGTH-1);
    fgets(str, MAX_STR_LENGTH, stdin);
    int length = strlen(str) - 1;                          //exclude the NULL character
    if (is_palindrome(str, length, 0)==1)                    
        printf("\nThe entered string is palindrome.");
    else
        printf("\nThe entered string is not a palindrome!!");
    
    char str_copy[MAX_STR_LENGTH]; 
    strcpy(str_copy, str);
    string_reverse(str_copy, length, 0);
    printf("\nReversed string: %s", str_copy);
    return 0;
}
