// A Dynamic Programming solution for subset sum problem
#include <stdio.h>
#define true 1
#define false 0

 void myprintarray(int a[10][10], int I, int J) // I=n+1, J = sum+1
 { static int t=1;
 return;
 printf("\n----call-[%d] array contents----\n",t++);
 printf("\n set[0,1,2] = 4,5,2\n");
 for (int i=0; i < J; i++) {
   printf("\nSum:%d ", i); 
  for (int j=0; j < I; j++)
 	printf("%d ", a[i][j]);
//	printf("\n");
  }
  printf("\n--------------------------------\n");
 }
 // Returns true if there is a subset of set[] with sun equal to given sum
 int isSubsetSum(int set[], int n, int sum)
 {
     // The value of subset[i][j] will be true if there is a 
         // subset of set[0..j-1] with sum equal to i
	     int subset[sum+1][n+1];
	      
	      	for (int i = 0; i <= sum; i++)
		for (int j = 0; i <= n; i++)
			subset[i][j] = false;
			myprintarray(subset,n+1,sum+1);
	          // If sum is 0, then answer is true
		      for (int i = 0; i <= n; i++)
		            subset[0][i] = true;
			     
			     myprintarray(subset,n+1, sum+1);

		         // If sum is not 0 and set is empty, then answer is false
		     for (int i = 1; i <= sum; i++)
		           subset[i][0] = false;
			     myprintarray(subset,n+1,sum+1);
				    
	         // Fill the subset table in botton up manner
	      for (int i = 1; i <= sum; i++)
	           {
	          for (int j = 1; j <= n; j++)
	         {
		 printf("\nUPdating subset (%d,%d) from subset(i,j-1), [%d,%d] = %d",i,j,i,j-1, subset[i][j-1]);
	          subset[i][j] = subset[i][j-1];
			     myprintarray(subset,n+1,sum+1);
			     printf("\ni = %d, set[j-1=%d] = %d", i, j-1, set[j-1]);
	           if (i >= set[j-1]) {
		    printf("\nupdating subset (%d,%d) from subset[i][j-1]-(%d,%d) = %d",i,j, i,j-1,subset[i][j-1]);
                  subset[i][j] = subset[i][j] || subset[i - set[j-1]][j-1];
												       		printf("\n%d >= %d -> subset[%d][%d] is (%d or %d) = %d",i,set[j-1], i,j,subset[i][j-1],subset[i - set[j-1]][j-1],subset[i][j]);
												       		}
			     myprintarray(subset,n+1,sum+1);
												              } printf("\n");
												           }
																		    
											        // uncomment this code to print table
												   printf("\nSet = {4,5,2}");
												     for (int i = 0; i <= sum; i++)
												          {
													  printf("\nsum=%d ", i);
												         for (int j = 0; j <= n; j++)
											           printf ("%4d", subset[i][j]);
												          //printf("\n");
																							       } 
																							        
												          printf("\n");
																							     return subset[sum][n];
																							     }
																							      
																							      // Driver program to test above function
																							      int main()
																								      {
																								        int set[] = {4, 5, 2};
																									  int sum = 9;
																								    int n = sizeof(set)/sizeof(set[0]);
																								      if (isSubsetSum(set, n, sum) == true)
																								           printf("Found a subset with given sum\n");
																								     else
																								          printf("No subset with given sum\n");
																									    return 0;
																								    }
