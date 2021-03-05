/*
----VARIABLES----
arraySize = size of array[]
array[] = contains main array elements
displayChoice = choice by user in display-menu
i = iteration index
key = search element
mainChoice = choice by user in main-menu
position[]  = contains position of a key element
pos = position of element to be searched
searchChoice = choice by user in search-menu
searchCount = size of searchElement[]
searchElement[] = contains the elements to be searched
tempArr[] = contains a copy of main array elements

----FUNCTIONS----
displayOperation - main display function
    -ascendingOrder()
    -displayAllNumbers()
    -removeDuplicates()
    -removeZero()

searchOperation - main search function
    -searchByPosition()
    -searchSingleElement()
    -searchMultipleElements()


*/

#include<stdio.h>
#include<conio.h>

#define RANGE 1000

void main(){
    int arraySize,i,mainChoice=0;

    printf("Enter Array Size : ");
    scanf("%d",&arraySize);

    int array[arraySize];

    printf("Enter Array Elements: \n");
    for(i=0;i<arraySize;i++){
        scanf("%d",&array[i]);
    }

    while(mainChoice!=3){
        printf("\nWhat do you wanna do ?\n"
               "1. Search Operation\n"
               "2. Display Array\n"
               "3.Exit\n"
        );
        printf("Enter you're choice: ");
        scanf("%d",&mainChoice);
            switch(mainChoice){
                case 1: searchOperations(array,arraySize);
                        break;
                case 2: displayOperations(array,arraySize);
                        break;
                case 3: break;
                default: printf("Invalid choice!\n Choose (1/2).\n");
            }
    }
}

void searchOperations(int array[], int arraySize){

    int searchChoice=0;

    while(searchChoice!=4){
        printf("\nHow do you wanna search ?\n"
               "1. Search element by position\n"
               "2. Search a single element\n"
               "3. Search multiple elements\n"
               "4. Exit\n"
        );

        printf("Enter you're choice: ");
        scanf("%d",&searchChoice);

        switch(searchChoice){
            case 1: searchByPosition(array,arraySize);
                    break;
            case 2: searchSingleElement(array,arraySize);
                    break;
            case 3: searchMultipleElements(array,arraySize);
                    break;
            case 4: break;
            default: printf("Invalid choice!\n Choose (1/2/3/4).\n");
        }
    }

}


void displayOperations(int array[], int arraySize){
    int displayChoice=0;

    while(displayChoice!=5){
        printf("\nHow do you wanna display ?\n"
               "1. Display all elements in array\n"
               "2. Display with removed duplicates\n"
               "3. Display with removed zeros\n"
               "4. Display in ascending order\n"
               "5. Exit\n"
        );

        printf("Enter you're choice: ");
        scanf("%d",&displayChoice);

        switch(displayChoice){
            case 1: displayAllNumbers(array,arraySize);
                    break;
            case 2: removeDuplicates(array,arraySize);
                    break;
            case 3: removeZero(array,arraySize);
                    break;
            case 4: ascendingOrder(array,arraySize);
                    break;
            case 5: break;
            default: printf("Invalid choice!\n Choose (1/2/3/4).\n");
        }
    }
}







//search functions
void searchByPosition(int array[], int arraySize){
    int i,j=0,pos,flag=0;

    printf("\nEnter the position = ");
    scanf("%d",&pos);

    if(pos<=arraySize){
        printf("Element at position %d is = %d \n",pos,array[pos-1]);
    }else{
        printf("The specified position is out of bound.\n");
    }
    return 0;
}

void searchSingleElement(int array[], int arraySize){
    int i,j=0,key,flag=0;

    int position[arraySize];
    memset(position, 0, sizeof(position));

    printf("\nEnter the element to search = ");
    scanf("%d",&key);

    for(i=0;i<arraySize;i++){
        if(array[i]==key){
            flag = 1;
            position[j] = i+1;
            j++;
        }
    }

    if(flag == 0){
        printf("\nElement %d was not found. \n",key);
        return 0;
    }

    printf("\nIn the array = ");
    for(i = 0; i < arraySize; i++){
        printf("%d  ",array[i]);
    }
    printf("\nElement %d was found at position = ",key);
    for(i=0;i<j;i++){
        printf("%d ",position[i]);
    }
    printf("\n");

    return 0;
}

void searchMultipleElements(int array[], int arraySize){
    int i,j,seachCount;

    printf("Enter the total number of elements to be searched = ");
    scanf("%d",&seachCount);

    int searchElements[seachCount];

    printf("\nEnter the elements to be searched =");
    for(i=0;i<seachCount;i++){
        scanf("%d",&searchElements[i]);
    }

    for(i=0;i<arraySize;i++){
        for(j=0;j<seachCount;j++){
            if(array[i]==searchElements[j]){
                printf("\nThe element %d was found at position = %d",searchElements[j],i+1);
                break;
            }
        }
        if(j==arraySize){
            printf("\nThe element %d was not found",searchElements[j]);
        }
    }
}



//display functions
void displayAllNumbers(int array[], int arraySize){
    int i;
    printf("\nThe array = ");
    for(i = 0; i < arraySize; i++){
        printf("%d  ",array[i]);
    }
    printf("\n");
    return 0;
}

void removeDuplicates(int array[], int arraySize){
    int i,j,k;
    int tempArr[arraySize];
    for (i=0;i<arraySize;i++){
        tempArr[i]=array[i];
    }

    for (i = 0; i < arraySize; i++){
		for(j = i + 1; j < arraySize; j++){
    		if(tempArr[i] == tempArr[j]){
    			for(k = j; k < arraySize; k++){
    				tempArr[k] = tempArr[k + 1];
				}
				arraySize--;
				j--;
			}
		}
	}
	printf("\nArray after removing duplicates = ");
	for (i = 0; i < arraySize; i++){
 		printf("%d ", tempArr[i]);
  	}
  	printf("\n");
    return 0;
}

void removeZero(int array[], int arraySize){
    int i;
    printf("\nArray with removed zeros = ");
    for(i=0;i<arraySize;i++){
        if(array[i]!=0){
            printf("%d ",array[i]);
        }
    }
    printf("\n");
    return 0;
}

void ascendingOrder(int array[], int arraySize){
  int i,k = 0;

  int tempArr[arraySize];
    for (i=0;i<arraySize;i++){
        tempArr[i]=array[i];
    }


  int freq[RANGE];
  memset(freq, 0, sizeof(freq));

  for (i = 0; i < arraySize; i++){
    freq[array[i]]++;
  }

  for(int i=0;i<RANGE;i++){
    while(freq[i]--){
        tempArr[k++] = i;
    }
  }

  printf("\nArray in ascending order = ");
  for(i=0;i<arraySize;i++){
    printf("%d ",tempArr[i]);
  }
  printf("\n");



}


