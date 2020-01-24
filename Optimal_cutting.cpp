#include <bits/stdc++.h> 
using namespace std; 
  
// Returns number of rods required using best fit 
// online algorithm 
int bestFit(int length[], int n, int c) 
{ 
    // Initialize result (Count of bins) 
    int res = 0; 
  
    // Create an array to store remaining space in bins 
    // there can be at most n rods 
    int bin_rem[n]; 
  
    // Place items one by one 
    for (int i = 0; i < n; i++) { 
        // Find the best rods that ca\n accomodate 
        // length[i] 
        int j; 
  
        // Initialize minimum space left and index 
        // of best rod 
        int min = c + 1, bi = 0; 
  
        for (j = 0; j < res; j++) { 
            if (bin_rem[j] >= length[i] && bin_rem[j] - length[i] < min) { 
                bi = j;cout<<bi<<"  "<<length[i]-4<<endl;
                min = bin_rem[j] - length[i]; 
            } 
        } 
  
        // If no rod could accommodate length[i], 
        // create a new rod 
        if (min == c + 1) {cout<<res<<"  "<<length[i]-4<<endl; 
            bin_rem[res] = c - length[i]; 
            res++; 
        } 
        else // Assign the item to best rod 
            bin_rem[bi] -= length[i]; 
    
        
    
    } 
    
    cout<<"Amount of material left in each rod is "<<endl;
    for(int i=0;i<res;i++)
        {cout<<bin_rem[i]<<"  ";}
    return res; 
} 
  int firstFitDec(int length[], int n, int c) 
{ 
    // First sort all lengths in decreasing order 
    sort(length, length + n, std::greater<int>()); 
  
    // Now call first fit for sorted items 
    return bestFit(length, n, c); 
} 
// Driver program 
int main() 
{   //the lengths are the lengths
    int length[] = {300,161.55+23.094,300,161.55+23.094,161.55+23.094,161.55+23.094,300,161.55+23.094,161.55+23.094,688.45,300,688.45,688.45,688.45,688.45,688.45,253.78+23.094,300,336.73+23.094,253.78+23.094,336.73+23.094,253.78+23.094,336.73+23.094,573.1+23.094,300}; 
    for(int i=0;i<25;i++)
        {length[i]=length[i]+4;}
    int c = 1000; 
    int n = sizeof(length) / sizeof(length[0]); 
    cout << "Number of rods required in Best Fit : "
         << firstFitDec(length, n, c);  
    return 0; 
} 