#include<bits/stdc++.h> 
using namespace std; 
int order(int num) 
{ 
    int zeroes = log10(num); 
    int threshold = 1; 
    for(int i = 0 ; i < zeroes ; i++ ) threshold*=10; 
    return threshold; 
} 
int main() 
{ 
    ifstream fin("u_s_hihi.txt"); 
    double consistency_factor = 0.1; 
    assert(!fin.fail()); 
    int num_tasks,num_vms; 
    fin >> num_tasks >> num_vms; 
    vector<vector<double>> task_times(num_tasks, 
    vector<double>(num_vms, 0)); 
    for (int i = 0; i < num_tasks; i++)  
    for (int j = 0; j < num_vms; j++)  
    fin >> task_times[i][j]; 
    fin.close(); 
    int machine1 = 0, machine2 = 0; 
    vector<double> completionTimes(num_vms,0); 
    double mn1,mn2; 
    int threshold = 0; 
    for(int i=0;i<num_tasks;i++) 
    { 
        mn1=INT_MAX; 
        mn2=INT_MAX; 
        for(int j=0 ; j < num_vms ; j++) 
        { 
            if(mn1 > task_times[i][j]+completionTimes[j]) 
            { 
                mn1=task_times[i][j]+completionTimes[j]; 
                machine1=j; 
            } 
            if(mn2 > task_times[i][j]) 
            { 
                mn2=task_times[i][j]; 
                machine2=j; 
            } 
            threshold = consistency_factor*(max(threshold,order(task_times[i][j]))); 
        } 
        if(mn2+completionTimes[machine2] - mn1 < threshold) 
            completionTimes[machine2]+=mn2; 
        else completionTimes[machine1]=mn1;  
    } 
    double mx = *max_element(completionTimes.begin(),completionTimes.end()); 
    cout<<"Completion time = "<<setprecision(10)<<mx<<endl; 
} 