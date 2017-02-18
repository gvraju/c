    /*

     * C Program to sort an array based on heap sort algorithm(MAX heap)

     */ 

    #include <stdio.h>


    void heapsort(int [], int n);
    int sumof2nos(int [], int, int);

    void main()

    {
    	int heap[10], no, i, j, c, root, temp;
	int tsum;

        printf("\n Enter no of elements :");

        scanf("%d", &no);

        printf("\n Enter the nos : ");

        for (i = 0; i < no; i++)

           scanf("%d", &heap[i]);

        printf("\nEnter Target Sum: ");
	scanf("%d",&tsum);

//	heapsort(heap, no);
//	printf("\nSorted array : ");
//	for (i=0; i < no; i++)
//	  printf("%d ", heap[i]);
//	printf("\n");

	if (sumof2nos(heap,no,tsum))
		printf("\ntsum=%d is present in the given array\n", tsum);
	else
		printf("\ntsum=%d is NOT present in the given array\n", tsum);
	return;

    }

int sumof2nos(int A[10], int no, int tsum)
{
	int i, j;

	heapsort(A,no);

	i = 0;
	j = no-1;

	while ( i < j )
	{
		if ( A[i] + A[j] < tsum )
			i++;
		else
			if ( A[i] + A[j] > tsum )
				j--;
			else
				return 1; // element FOUND
	}
	return 0;
}

void heapsort(int heap[10], int no)
{
 	int i, j, temp, c, root;
        for (i = 1; i < no; i++)
        {

            c = i;

            do

            {

                root = (c - 1) / 2;             

                if (heap[root] < heap[c])   /* to create MAX heap array */

                {

                    temp = heap[root];

                    heap[root] = heap[c];

                    heap[c] = temp;

                }

                c = root;

            } while (c != 0);

        }

     

        printf("Heap array : ");

        for (i = 0; i < no; i++)

            printf("%d ", heap[i]);

        for (j = no - 1; j >= 0; j--)

        {

            temp = heap[0];

            heap[0] = heap[j];    /* swap max element with rightmost leaf element */

            heap[j] = temp;

            root = 0;

            do 

            {

                c = 2 * root + 1;    /* left node of root element */

                if ((heap[c] < heap[c + 1]) && c < j-1)

                    c++;

                if (heap[root]<heap[c] && c<j)    /* again rearrange to max heap array */

                {

                    temp = heap[root];

                    heap[root] = heap[c];

                    heap[c] = temp;

                }

                root = c;

            } while (c < j);

        } 

   }
