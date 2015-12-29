#include<stdio.h>
#include<stdlib.h>
#define N 10

void selection_sort(int* arr);
void insertion_sort(int* arr);
void merge_sort(int* arr, int n);
void merge(int*arr, int*L ,int*R, int L_num, int R_num);
void prn_arr(int* arr);


void main()
{
	int* arr;
	int narr[N] = {41,31,48,97,9,65,27,29,13,15};
	int i = 0;

	arr = (int*)malloc(sizeof(int)*N);

	for (i = 0; i < N;i++)
	{
		arr[i] = narr[i];
	}

	printf("정렬 전 배열 출력\n");
	prn_arr(arr);

	printf("\n사용할 알고리즘을 1~4을 입력하여 선택하세요\n1. selection sort\n2. insertion sort\n");
	printf("3. merge sort\n4. quick sort\n\n숫자 입력하세요: ");
	scanf("%d", &i);
	printf("\n");

	switch (i)
	{
		case 1:
			selection_sort(arr); // 정렬알고리즘 선택
			break;
		case 2:
			insertion_sort(arr); // 정렬알고리즘 선택
			break;
		case 3:
			merge_sort(arr,N); // 정렬알고리즘 선택
			break;
		default:
			printf("I don't know!\n");
	}

	prn_arr(arr);
}

void selection_sort(int *arr)
{
	int max=0, l_idx=N-1, m_idx=0 , tmp=0, i;

	while (l_idx > 0)
	{
		// 최대값과 최대값의 인덱스 찾기
		for (i = 0; i <= l_idx; i++)
		{	
			if (max < arr[i])
			{
				max = arr[i];
				m_idx = i;
			}
		}
		
		// 최대값과 마지막값 교환
		arr[m_idx] = arr[l_idx];
		arr[l_idx] = max;

		max = 0;
		m_idx = 0;
		--l_idx;
	}
}

void merge_sort(int* arr, int n)
{
	int L_mid = n / 2,		 R_mid= n - L_mid  ;
	int* L,* R;
	int i, j;
	
	if (n < 2)	return; // base case -> 원소 1개일 때

	L = (int*)malloc(sizeof(int)*L_mid);
	R = (int*)malloc(sizeof(int)*R_mid);

	for (i = 0; i < L_mid; i++)
	{
		L[i] = arr[i];
	}
	for (i = L_mid; i < n; i++)
	{
		R[i - L_mid] = arr[i];
	}

	merge_sort(L, L_mid);
	merge_sort(R, R_mid);

	merge(arr, L, R, L_mid, R_mid);

	free(L);
	free(R);
}

void merge(int*arr, int*L, int*R, int L_num, int R_num)
{
	int i=0, j=0, k=0; // i = left , j = right , k = total
	
	while (i<L_num && j<R_num)
	{
		if(L[i] < R[j])
		{
			arr[k++] = L[i++];
		}
		else
		{
			arr[k++] = R[j++];
		}
	}

	while (i<L_num)
	{
		arr[k++] = L[i++];
	}
	while (j<R_num)
	{
		arr[k++] = R[j++];
	}
}


void insertion_sort(int* arr)
{
	int ins = 1, idx = 0, tmp_ins=0, i, j;

	while (ins < N)
	{
		// 최초에 원소 1개일 때 할거 없음
		
		// 원소 2개 이상일 때
		for (i = 0; i < ins; i++)
		{
			if (arr[ins] < arr[i])
			{
				idx = i;
				tmp_ins = arr[ins];

				for (j = ins-1; j >= idx ; j--)
				{
					arr[j+1] = arr[j];
				}

				arr[idx] = tmp_ins;
			}
		}
		++ins;
	}
}

void prn_arr(int* arr)
{
	int i = 0;
	for (i = 0; i < N; i++)
	{
		printf("%d ",arr[i]);
	}

	printf("\n");
}