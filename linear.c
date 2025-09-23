#include<stdio.h>
int main(){
int n,i,key,found=0;
printf("ENTER NUMBER OF ELEMENTS");
scanf("%d",&n);
int arr[n];
printf("ENTER %d ELEMENTS \n",n);
for(i=0;i<n;i++){
  scanf("%d",&arr[i]);
  }
 printf("ENTER ELEMENT TO SEARCH");
 scanf("%d",&key);
 for(i=0;i<n;i++){
 if(arr[i]==key){
  printf("ELEMENT %d FOUND AT POSITION %d\n",key,i+1);
  found=1;
  break;
  }
 }
   if(found==0){
   printf("ELEMENT %d NOT FOUND IN THE ARRAY \n",key);
  }
   return 0;
  }
 
