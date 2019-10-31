#include <fstream>
#include "sorts.cpp"

using namespace std;


// A single pair is stored in a Vector<long>
// You have to return a vector of all pairs.
vector< vector<long> > smartSearch(vector<long> nums, long k)
{   
    vector <vector<long> > result;
    nums = QuickSortArray(nums);
    long lenOfVect = nums.size();
    long *sortedArray = new long[lenOfVect];
    for(int i =0 ; i< lenOfVect; i++)
    {
        sortedArray[i] = nums[i];
    }
    // Binary search 
    for(int i =0 ; i <lenOfVect; i++)
    {
        long num = k-sortedArray[i];
        // if(num <0)
        // {
        //     break;
        // }
        long first = 0;
        long last = lenOfVect-1;
        long middle = (first+last)/2;
        while (first <= last)
        {
           if(sortedArray[middle] < num)
           {
            first = middle + 1;

           }
           else if(sortedArray[middle] == num)
            {
                vector<long> pair;
                pair.push_back(sortedArray[i]);
                pair.push_back(num);
                result.push_back(pair);
                break; 
            } 
            else 
            { 
                last = middle - 1; 
            } 
               
            middle = (first + last)/2; 
        } 
            if(first > last)
        {
        }
    }

    
    return result;
    // Write your code in this function
}


int main()
{
    vector<long> nums;
    ifstream in("random.txt");
    long n;
    while(in >> n)
        nums.push_back(n);
    in.close();

    long k;
    cout << "Enter the value of K: ";
    cin >> k;

    vector< vector<long> > result = smartSearch(nums, k);

    for(int i = 0; i < result.size(); i++)
        cout << result[i][0] << ", " << result[i][1] << endl;

    return 0;
}