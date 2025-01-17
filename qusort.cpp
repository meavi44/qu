// C++ program to implement sorting a 
// queue data structure 
#include <bits/stdc++.h> 

using namespace std; 

  
// Queue elements after sortedIndex are  
// already sorted. This function returns 
// index of minimum element from front to 
// sortedIndex 

int minIndex(queue<int> &q, int sortedIndex) 
{ 

    int min_index = -1; 

    int min_val = INT_MAX; 

    int n = q.size(); 

    for (int i=0; i<n; i++) 

    { 

        int curr = q.front(); 

        q.pop();  // This is dequeue() in C++ STL 

  

        // we add the condition i <= sortedIndex 

        // because we don't want to traverse 

        // on the sorted part of the queue, 

        // which is the right part. 

        if (curr <= min_val && i <= sortedIndex) 

        { 

            min_index = i; 

            min_val = curr; 

        } 

        q.push(curr);  // This is enqueue() in  

                       // C++ STL 

    } 

    return min_index; 
} 

  
// Moves given minimum element to rear of  
// queue 

void insertMinToRear(queue<int> &q, int min_index) 
{ 

    int min_val; 

    int n = q.size(); 

    for (int i = 0; i < n; i++) 

    { 

        int curr = q.front(); 

        q.pop(); 

        if (i != min_index) 

            q.push(curr); 

        else

            min_val = curr; 

    } 

    q.push(min_val); 
} 

  

void sortQueue(queue<int> &q) 
{ 

    for (int i = 1; i <= q.size(); i++) 

    { 

        int min_index = minIndex(q, q.size() - i); 

        insertMinToRear(q, min_index); 

    } 
} 

  
// driver code 

int main() 
{ 

  queue<int> q; 

  q.push(30); 

  q.push(11); 

  q.push(15); 

  q.push(4); 

    

  // Sort queue 

  sortQueue(q); 

    

  // Print sorted queue 

  while (q.empty() == false) 

  { 

     cout << q.front() << " "; 

     q.pop(); 

  } 

  cout << endl; 

  return 0; 
}