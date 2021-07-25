#include<iostream>
#include<vector> // for 2D vector
#include<algorithm> // for sort()
using namespace std;
  
// Driver function to sort the 2D vector
// on basis of a particular column
bool sortcol( const vector<int>& v1,
               const vector<int>& v2 ) {
 return v1[1] < v2[1];
}
  
int main()
{
    // Initializing 2D vector "vect" with
    // values
    vector< vector<int> > vect{{3, 5, 1},
                                {4, 8, 6},
                                {7, 2, 9}};
  
    // Number of rows;
    int m = vect.size();
  
    // Number of columns (Assuming all rows
    // are of same size).  We can have different
    // sizes though (like Java).
    int n = vect[0].size();
      
    // Displaying the 2D vector before sorting
    cout << "The Matrix before sorting is:\n";
    for (int i=0; i<m; i++)
    {
        for (int j=0; j<n ;j++)
            cout << vect[i][j] << " ";
        cout << endl;
    }                               
  
    // Use of "sort()" for sorting on basis
    // of 2nd column
    sort(vect.begin(), vect.end(),sortcol);
  
    // Displaying the 2D vector after sorting
    cout << "The Matrix after sorting is:\n";
    for (int i=0; i<m; i++)
    {
        for (int j=0; j<n ;j++)
            cout << vect[i][j] << " ";
        cout << endl;
    }
    return 0;
}