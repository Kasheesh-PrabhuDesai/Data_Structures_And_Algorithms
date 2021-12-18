/*
The coordinator of the placement cell has received many applications of students applying in 
different companies. There are M students and N companies who are offering jobs. Each student 
is interested in a particular number of companies for a job. Each job opening can only accept 
one student and a student can only have 1 job. As a placement coordinator, you want to place 
a maximum number of students.
Your task is to find the maximum number of students that can be placed in one of their desired 
jobs.
The data about the set of favourable jobs are given in the form of an M * N binary matrix named
‘mat’, i.e for M students we have M rows each having N integers. Now for example if the first 
candidate is interested in job 1 the value of mat[i][j] will be 1 otherwise it will be 0.
Note:
It is possible that a single candidate is interested in multiple jobs but he can take up only 
one of the job out of his favourable jobs, also there is no priority in jobs, i.e all favourable
jobs are equally favourable to the candidate.

Approach:

The key idea is to think of the problem as a bipartite graph where one side has nodes of 
applicants and the other side has nodes of jobs and the edges in the graph denote the relation 
between the jobs and candidate. (There is a directed edge between the candidate and job if the 
candidate wants that job.

1) Make an array ‘assign’ which keeps track of assignment of jobs i.e what job is assigned to 
what person. Initially, it is -1 for all ‘N’ elements.
2) Make a variable ‘jobCount’ to keep track of the number of applicants placed.
3) Make all the jobs unvisited initially.
4) Then we loop through all the applicants and for each applicant we check all favorable jobs 
for that particular applicant and if we find a job which is either not assigned or if assigned
to some other applicant, the other applicant has other jobs available, we assign the current 
job to that applicant.
5) We do this using a DFS like function that goes through the row of the current applicant and 
tries to assign one of his favorite jobs using the above-mentioned algorithm.
6) If we are able to assign a job to the applicant we increment the value of ‘jobCount’.
7) Finally, after traversing all nodes, we return the value of ‘jobCount’.

Time Complexity: O(M*N) where M are the no of students and N the number of jobs
Space Complexity: O(M) where N is the total number of applicants
*/

#include <iostream>
#include <vector>

using namespace std;

bool bipartiteMatch(int currentStudent,vector<bool>& visited, vector<int>& jobsAssigned,vector<vector<int>>& mat,int totalJobs)
{
    for(int currentJob = 0; currentJob<totalJobs; currentJob++)
    {
        bool currentJobVisited = visited[currentJob];
        int currentJobAssignedCount = jobsAssigned[currentJob];
        int currentStudentInterested = mat[currentStudent][currentJob];
        if(currentStudentInterested && !currentJobVisited)
        {
            visited[currentJob]=true;
        

            if (currentJobAssignedCount < 0 || bipartiteMatch(jobsAssigned[currentJob], visited, jobsAssigned, mat, totalJobs)) 
            {

                // Assign job v to applicant u
                jobsAssigned[currentJob] = currentStudent;  
                return true;
            }
        }
    }

    return false;
}




int maxMatch(vector<vector<int>> &mat)
{
    int totalStudents = mat.size();
    int totalJobs = mat[0].size();

    vector<int> jobsAssigned(totalJobs,-1);

    int jobsCount=0;

    for(int currentStudent=0;currentStudent<totalStudents;currentStudent++)
    {
        vector<bool> visited(totalJobs,false);

        if(bipartiteMatch(currentStudent,visited,jobsAssigned,mat,totalJobs))
        {
            jobsCount++;
        }


    }

    return jobsCount;

}


int main()
{
    vector<vector<int>> mat = {{0,0,1,1},{1,1,1,1},{0,0,0,1},{1,0,0,0}};

    cout<<maxMatch(mat)<<endl;
}

