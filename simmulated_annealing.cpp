#include <bits/stdc++.h>
using namespace std;

//c++ code for the above approach
class Solution {
    
    public:
    float CVRMSE;
    vector<int> config;
    Solution(float CVRMSE, vector<int> configuration) {
        this->CVRMSE = CVRMSE;
        config = configuration;
    }
};

// Function prototype 
Solution genRandSol();

// global variables. 
int T = 1;
float Tmin = 0.0001;
float alpha = 0.9;
int numIterations = 100;
int M = 5;
int N = 5;
vector<vector<char>> sourceArray(M, vector<char>(N, 'X'));
vector<int> temp = {};
Solution mini = Solution((float)INT_MAX, temp);
Solution currentSol = genRandSol();

Solution genRandSol() {
    // Instantiating for the sake of compilation
    vector<int> a = {1, 2, 3, 4, 5};
    return Solution(-1.0, a);
}

Solution neighbor(Solution currentSol) {
    return currentSol;
}

float cost(vector<int> inputConfiguration) {
    return -1.0;
}

// Mapping from [0, M*N] --> [0,M]x[0,N]
vector<int> indexToPoints(int index) {
    vector<int> points = {index % M,index/M};
    return points;
}


//Returns minimum value based on optimization
int main(){
    
    while (T > Tmin) {
        for (int i = 0; i < numIterations; i++) {
            // Reassigns global minimum accordingly
            if (currentSol.CVRMSE < mini.CVRMSE) {
                mini = currentSol;
            }
            Solution newSol = neighbor(currentSol);
            float ap = exp((currentSol.CVRMSE - newSol.CVRMSE) / T);
            srand( (unsigned)time( NULL ) );
            if (ap > (float) rand()/RAND_MAX) {
                currentSol = newSol;
            }
        }
        T *= alpha; // Decreases T, cooling phase
    }
    
    cout << mini.CVRMSE << "\n\n";
    
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            sourceArray[i][j] = 'X';
        }
    }   
    
    // Displays
    for(int index = 0; index < mini.config.size(); index++){
        int obj = mini.config[index];
        vector<int> coord = indexToPoints(obj);
        sourceArray[coord[0]][coord[1]] = '-';
    }

    // Displays optimal location
    for (int i = 0; i < M; i++) {
        string row = "";
        for (int j = 0; j < N; j++) {
            row = row + sourceArray[i][j] + " ";
        }
        cout << (row) << endl;
    }
}

// The code is contributed by Nidhi goel. 
