#include <iostream>
#include <ctime>
#include <vector>
using namespace std;

const int CLOCKS_PER_MS = CLOCKS_PER_SEC/1000; //clock per milliseconds

clock_t Start = clock();
//call sort function here
clock_t End = clock();
int elapsedTime = (End - Start)/CLOCKS_PER_MS; // converts elapsed time from microseconds to milliseconds.

const int NUMBERS_SIZE = 10;

int genRandInt(int low, int high) {
   return low + rand() % (high - low + 1);
}
void fillArrays(int arr1[], int arr2[],int arr3[]){
    for(int i = 0; i < NUMBERS_SIZE; ++i){
        arr1[i] = genRandInt(0,NUMBERS_SIZE);
        arr2[i] = arr1[i];
        arr3[i] = arr1[i];
    }
}

int partition_Midpoint(int numbers[], int i, int k)
{
  int pivot, leftmost, rightmost, temp;
  pivot = numbers[(i+k)/2];
  leftmost = i;
  rightmost = k;
  int flag = 1;
  while(flag != 0)
  {
    while(numbers[leftmost] < pivot)
    {
      leftmost = leftmost + 1;
    }

    while(numbers[rightmost] > pivot)
    {
      rightmost = rightmost - 1;
    }

    if(leftmost >= rightmost)
    {
      flag = 0;
    }
else //swap numbers[leftmost] and numbers[rightmost]
{
      temp = numbers[leftmost];
      numbers[leftmost] = numbers[rightmost];
      numbers[rightmost] = temp;

      //update leftmost and rightmost
      leftmost = leftmost +1;
      rightmost = rightmost -1;
    }
  }
  return rightmost;

}

int FindMedian(int numbers[], int i, int k)
{
  int center = (i+k)/2;
  if((numbers[k] <= numbers[i] && numbers[i] <= numbers[center]) || (numbers[center] <= numbers[i] && numbers[i] <= numbers[k]))
  {
    return i;
  }
  if((numbers[i] <= numbers[k] && numbers[k] <= numbers[center]) || (numbers[center] <= numbers[k] && numbers[k] <= numbers[i]))
  {
    return k;
  }
  if((numbers[i] <= numbers[center] && numbers[center] <= numbers[k]) || (numbers[k] <= numbers[center] && numbers[center] <= numbers[i]))
  {
    return center;
  }
  return 0;
}

int partition_MedianOfThree(int numbers[], int i, int k)
{
  int center, temp;
  center = (i+k)/2;
  unsigned int medianindex = FindMedian(numbers, i, k);

//swap
temp = numbers[medianindex];
  numbers[medianindex] = numbers[center];
  numbers[center] = temp;

  return partition_Midpoint(numbers, i, k);
  
}

void Quicksort_Midpoint(int numbers[], int i, int k)
{
  if(i < k)
  {
    int p = partition_Midpoint(numbers, i, k);
    Quicksort_Midpoint(numbers, i, p);
    Quicksort_Midpoint(numbers, p + 1, k);
  }
}

void Quicksort_MedianOfThree(int numbers[], int i, int k)
{
  if(i < k)
  {
    int p = partition_MedianOfThree(numbers, i, k);
    Quicksort_MedianOfThree(numbers, i, p);
    Quicksort_MedianOfThree(numbers, p + 1, k);
  }
}

void InsertionSort(int numbers[], int numberSize)
{
  int first, last, temp;
  first = 0;
  last = 0;
  temp = 0;
  for(first = 1; first < numberSize; ++first)
  {
    last = first;
    while(last > 0 && numbers[last] < numbers[last -1])
    {
      temp = numbers[last];
      numbers[last] = numbers[last-1];
      numbers[last - 1] = temp;
      --last;
    }
  }
}

void bubblesort(int numbers[], int n)
{
  int temp;
  for(int i = 0; i < n-1; i++)
  {
    for(int j = i+1; j < n; j++)
    {
      if(numbers[i] > numbers[j])
      {
        temp = numbers[i];
        numbers[i] = numbers[j];
        numbers[j] = temp;
      }
    }
  }
}

int main() 
{
  int arr1[NUMBERS_SIZE];
  int arr2[NUMBERS_SIZE];
  int arr3[NUMBERS_SIZE];

  arr1[0] = 4;
  arr1[1] = 2;
  arr1[2] = 5;
  arr1[3] = 3;
  arr1[4] = 2;
  arr1[5] = 10;
  arr1[6] = 13;
  arr1[7] = 1;
  arr1[8] = 6;
  arr1[9] = 5;
  bubblesort(arr1, NUMBERS_SIZE);
  for(int i = 0; i < NUMBERS_SIZE; i++)
  {
    cout << arr1[i] << " ";
  }
  cout << endl;
}	
