/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_merge.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 21:24:54 by kipark            #+#    #+#             */
/*   Updated: 2022/04/17 13:55:16 by kipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// int N,arr[1000001];
// int *arr2;

// void merge(int left, int right)
// {
// 	int mid = (left + right) / 2;

// 	int i = left;
// 	int j = mid + 1;
// 	int k = left;
// 	while (i <= mid && j <= right)
// 	{
// 		if (arr[i] <= arr[j]) 
// 			arr2[k++] = arr[i++]; 
// 		else
// 			arr2[k++] = arr[j++];
// 	}

// 	int tmp = i>mid ? j : i;
	
// 	while(k<=right) arr2[k++] = arr[tmp++];

// 	for (int i=left;i<=right;i++) arr[i] = arr2[i];
// }

// void partition(int left,int right)
// {
// 	int mid;
// 	if (left < right)
// 	{
// 		mid = (left + right) / 2; 
// 		partition(left, mid);
// 		partition(mid + 1, right);
// 		merge(left, right);
// 	}
// }

void sort_arr(int *arr, int arr_length)
{
	int i;
	int j;
	int temp;

	i = 0;
	j = 0;
	while(i < arr_length)
	{
		j = i+1;
		while(j < arr_length)
		{
			if(arr[i] > arr[j])
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
			++j;
		}
		++i;		
	}
}
