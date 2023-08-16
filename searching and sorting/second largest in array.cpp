int findSecondLargest(int *input, int n)
{
    //Write your code here
    int count=0;

    int num=input[0];
    for(int i=0;i<n;i++){
        if(input[i]==num){
            count++;
        }
    }
    if(count==n){
        return -2147483648;
    }
    int max=-2147483648;
    int index;
    for(int i=0;i<n;i++){
        if(input[i]>max){
            max=input[i];
            index=i;
        }
    }
    for(int i=0;i<n;i++){
        if(input[i]==max){
            input[i]=-2147483648;
        }
    }
    input[index]=-2147483648;
    max=-2147483648;
    for(int i=0;i<n;i++){
        if(input[i]>max){
            max=input[i];
        }
    }
   
    return max;
}
