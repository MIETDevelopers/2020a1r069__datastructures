#include<stdio.h>
#include<stdlib.h>
int printArray(int *array, int size){
    int count;
    for(count=0;count<size;++count){
        printf("\narray[%d] = %d", count, *(array+count));
    }
    return(count + 1);
}
int insertElementInListAt(int*list, int size, int location, int item){
    int newSizeOfList,count;
    list=realloc(list,((size+1)*sizeof(int)));        
    for(count=size;count>=location;count--)
        list[count+1] = list[count];
    list[location] = item;                           
    newSizeOfList = ++size;                       
    return newSizeOfList;
}
int deletion(int*list, int size, int index){
    int newSizeOfList,count;
    for(count=index ;count < size-1; count++)
        list[count] = list[count+1];                            
    newSizeOfList = --size;                         
    return newSizeOfList;
}
int linearSearch(int*list, int size, int element){
    int newSizeOfList,count;
    for(count=0 ;count < size; count++){
        if(list[count]==element){
            printf("\n%d is present at location %d.\n", element, count);
            return count;
        }
    }
    return -1;
}
int main()
{
    int *listA;
    int count, sizeOfListA, element, index, location, item;
    printf("How many numbers?\n");
	scanf(" %d", &sizeOfListA);
    listA = (int*)malloc(sizeof(int));                             
    for (count = 0; count < sizeOfListA; ++count)
	{
		printf("\nEnter listA[%d]\n", count);
		scanf(" %d", (listA+count));
	}
	for (count = 0; count < sizeOfListA; ++count)
	{
		printf("\nlistA[%d] = %d\n", count, *(listA+count));
	}
    printf("\nEnter the location where you want to insert the element :\n");
    scanf("%d",&location);
    printf("\nEnter the element to be inserted :\n");
    scanf("%d",&item);
    sizeOfListA = insertElementInListAt(listA, sizeOfListA, location, item);
    printArray(listA, sizeOfListA);
    printf("\n\nElement inserted successfully\n");
    printf("\nEnter the index of the element to be deleted :\n");
    scanf("%d",&index);
    sizeOfListA = deletion(listA, sizeOfListA,index);
    printArray(listA, sizeOfListA);
    printf("\n\nElement deleted successfully\n\n");
    printf("\nEnter the element to be searched :\n");
    scanf("%d",&element);
    int searchElement = linearSearch(listA, sizeOfListA, element);
    free(listA);
    printf("\nMemory successfully freed.\n");
    return 0;
}