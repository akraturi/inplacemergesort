#include <bits/stdc++.h>
using namespace std;
void inplacemerge(int arr[],int i,int j)
{   //a::Denotes the index of the minimum in the first subarray which is being merged
	//b::Denotes the index of the minimum in the second subarray which is being merged
	//x::Denotes the index in the origanal array upto which the array is already sorted
	//y::Bound for the variable a
	//ctr::Always kept equal to b
	int a=i,b=(i+j)/2+1,x=i,y=b,ctr=b;
	while(x<b)
	{
		if(ctr<j&&arr[ctr]>arr[ctr+1])
		{
			swap(arr[ctr],arr[ctr+1]);
			ctr++;
		}
		if(ctr>=j||arr[ctr]<=arr[ctr+1])
		{
			ctr=b;
		}
		if(b>j&&a>x&&b==a+1&&a>y&&ctr==b)
		{
			b=a;
			ctr=b;
			a=y;
		}
		else if(b>j&&a>x&&ctr==b)
		{
			b=y;
			ctr=b;
			a=x;
		}
		else if(b>j&&ctr==b)
		{
			break;
		}
		if(a==x&&x==y&&ctr==b)
		{
			y=b;
		}
		else if(x==y)
		{
			y=a;
		}
		if(a>y&&b>a+1&&arr[b]<arr[a]&&ctr==b)
		{
			swap(arr[a],arr[b]);
			swap(arr[a],arr[x]);
			x++;
			a++;
			if(arr[ctr]>arr[ctr+1])
			{
				swap(arr[ctr],arr[ctr+1]);
				ctr++;
			}
		}
		else if(a==x&&b==y&&arr[b]<arr[a])
			{
				swap(arr[x],arr[b]);
				a=b;
				b++;
				x++;
				if(ctr==b-1)
				{
					ctr++;
				}
			}
		else if(a==x&&b==y&&arr[b]>=arr[a])
			{
				x++;
				a++;
			}
		else if(b==a+1&&arr[b]<arr[a])
			{
				swap(arr[b],arr[x]);
				swap(arr[a],arr[b]);
				b++;
				x++;
				a++;
				if(ctr==b-1)
				{
					ctr++;
				}
			}
		else if(b==a+1&&arr[b]>=arr[a])
			{
				swap(arr[x],arr[a]);
				a=y;
				x++;
			}
		else if(a==y&&x<y&&ctr==b+1&&arr[b]<arr[a])
			{
				swap(arr[x],arr[b]);
				b++;
				x++;
				if(ctr==b-1)
				{
					ctr++;
				}
			}
		else if(b>a+1&&arr[b]>=arr[a])
			{
				swap(arr[x],arr[a]);
				x++;
				a++;

			}
	}
}
	
void mergesort(int a[],int i,int j)
{
	if(j==i+1||i==j)
	{
		if(a[i]>a[j])
		{
			swap(a[j],a[i]);
			return;
		}
	}
	else
	{  int mid=(i+j)/2;
	   mergesort(a,i,mid);
	   mergesort(a,mid+1,j);
	   if(a[mid+1]<a[mid])
	   {  
         inplacemerge(a,i,j);
	   }

	}
}
int main()
{
	int n;
	cout <<"Size of the data:";
	cin >> n;
	int a[n];
	cout <<"Enter data:";
	for(int i=0;i<n;i++)
		cin >>a[i];
	mergesort(a,0,n-1);
	cout <<"Sorted data:";
	for(int i=0;i<n;i++)
	{
		cout <<a[i]<<" ";
	}

}
