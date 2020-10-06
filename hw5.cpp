/**********************
PSEUDOCODE:
BubbleSort(std::vector<std::string> &vec)
  Initailizez string temp
  For loop to traverse through the vector
    For loop to traverse the vector after first loop
      Checks if comparisons in vector are above 0
        sets temp to vec[i]
        sets vec[i] to vec[j]
        sets vec[j] to temp

InsertionSortHelper(std::vector<int> &vec, int i)
  Returns if elements in vector are less then 0
  Calls the InsertionSortHelper functon to sort first i - 1 elements
  Initializes int "last" to the last element of vector
  Initailizes int "j"  to i - 2
  While j is greater than 0 and the vector is greater than last
    Sets vec[j+1] to vec[j]
    Decrement of j
  Sets vec[j+1] to last

InsertionSort(std::vector<int>& v)
  Calls the InsertionSortHelper function, passing v and the size of v

MergeVec(vector<string>&vec, int a, int b, int c)
  Initializes int "size1" to b - (a+1)
  Initializes int "size2" to c - b
  Initializes vector<string> left(size1) //left portion
  Initializes vector<string> right(size2) //right portion
  For loop to traverse the vector
    Sets left[i] to vec[a+i]
  For loop to traverse the vector
    Sets right[j] to vec[b+j+1]
  For loop
  If left[i] is less than or equal to right[j]
    Sets vec[k] to left[i]
    Increments i
  Else
    Sets vec[k] to right[j]
    Increments j
  For loop to traverse size1
    Sets vec[k] to left[i]
    Increments k
  For loop to traverse size2
    Sets vec[k] to right[j]
    Increments k

MergeSortHelper(vector<string>&vec, int l, int r)
  If l is less than r
    Initializes int "m" to l + (r - l) / 2;
    Calls the MergeSortHelper funtion for the first half
    Calls the MergeSortHelper function for the other half
    Calls the MergeVec function to merge the two sorted halfs

MergeSort(std::vector<std::string> &vec)
  Calls the MergeSortHelper function, passing vec, 0, and the size of the vector - 1
**********************/
#include <iostream>
#include <vector>
#include <string>
#include "hw5.h"

using namespace std;

void BubbleSort(std::vector<std::string> &vec)  {
  std::string temp;
  for (int i = 0; i < vec.size()-1; i++)  {
    for (int j = i + 1; j < vec.size(); j++)  {
      if (vec[i].compare(vec[j]) > 0)  {
        temp = vec[i];
        vec[i] = vec[j];
        vec[j] = temp;
      }
    }
  }
}

static void InsertionSortHelper(std::vector<int> &vec, int i)  {
  if (i <= 0)
    return;
  InsertionSortHelper(vec, i - 1);

  int last = vec[i - 1];
  int j = i - 2;

  while (j >= 0 && vec[j] > last) 
    { 
        vec[j+1] = vec[j]; 
        j--; 
    } 
    vec[j+1] = last; 
}

void InsertionSort(std::vector<int>& v)  {
  InsertionSortHelper(v, v.size());
}

static void MergeVec(vector<string>&vec, int a, int b, int c)  {
  int size1 = b-a+1;
  int size2 = c-b;
  int i=0;
  int j=0;
  int k;
  vector<string> left(size1);
  vector<string> right(size2);

  for(int i = 0; i < size1; i++)  {
    left[i] = vec[a+i];
  }

  for(int j = 0; j < size2; j++)  {
    right[j] = vec[b+j+1];
  }

  for(k = a; k <= c && i < size1 && j < size2; k++)  {
    if(left[i] <= right[j])  {
      vec[k] = left[i];
      i++;
    }
    else  {
      vec[k] = right[j];
      j++;
    }
  }
  for(i = i; i < size1; ++i)  {
    vec[k] = left[i];
    k++;
  }

  for(j = j; j < size2; j++)  {
    vec[k] = right[j];
    k++;
  }
}
static void MergeSortHelper(vector<string>&vec, int l, int r)  {
  if (l < r)  { 
    int m = l + (r - l) / 2; 
    MergeSortHelper(vec, l, m); 
    MergeSortHelper(vec, m + 1, r); 

    MergeVec(vec, l, m, r);
  } 
}

void MergeSort(std::vector<std::string> &vec)  {
  MergeSortHelper(vec,0,vec.size()-1);
}