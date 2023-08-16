void bubbleSort(int *input, int size)
{
   for(int j=0;j<size-1;j++){
       for(int i=0;i<size-1-j;i++){
           if(input[i]>input[i+1]){
               swap(input[i],input[i+1]);
           }
       }
   }
}
