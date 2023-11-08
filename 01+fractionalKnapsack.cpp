#include <bits/stdc++.h> 
using namespace std; 
  
// Function to find maximum profit 
void maxProfit(vector<int> profit, vector<int> weight, int N) 
{ 
  
    // Number of total weights present 
    int numOfElements = profit.size(); 
    int i; 
  
    // Multimap container to store 
    // ratio and index 
    vector<pair<double, int>> ratio;
  
    // Variable to store maximum profit 
    double max_profit = 0; 
    for (i = 0; i < numOfElements; i++) { 
  
        // Insert ratio profit[i] / weight[i] 
        // and corresponding index 
        ratio.push_back(make_pair( profit[i] / weight[i], i));
    } 

    // Sort the vector based on the double key
    sort(ratio.begin(), ratio.end());

  
    // Declare a reverse iterator 
    // for Multimap 
    //multimap<double, int>::reverse_iterator it; 
  
    // Traverse the map in reverse order 
    for (auto it = ratio.rbegin(); it != ratio.rend(); it++) 
    { 
        cout<<"\n "<<it->first;
  
        // Fraction of weight of i'th item 
        // that can be kept in knapsack 
        double fraction = N / weight[it->second]; 
  
        // if remaining_weight is greater 
        // than the weight of i'th item 
        
        if (N >= 0 && N >= weight[it->second]) 
        { 
  
            // increase max_profit by i'th 
            // profit value 
            max_profit += profit[it->second]; 
  
            // decrement knapsack to form 
            // new remaining_weight 
            N -= weight[it->second]; 
        } 
  
        // remaining_weight less than 
        // weight of i'th item 
        else if (N < weight[it->second]) { 

           // max_profit += fraction  * profit[it->second]; 
            break; 
        } 
    } 
  
    // Print the maximum profit earned 
    std::cout << "Maximum profit earned is:"
         << max_profit; 
} 
  
// Driver Code 
int main() 
{ 
    // Size of list 
    int size = 3; 
  
    // Given profit and weight 
    vector<int> profit(size), weight(size); 
  
    // Profit of items 
    profit[0] = 60, profit[1] = 100, profit[2] = 190;
  
    // Weight of items 
    weight[0] = 10, weight[1] = 20, weight[2] = 30; 
  
    // Capacity of knapsack 
    int N = 50; 
  
    // Function Call 
    maxProfit(profit, weight, N); 
}
