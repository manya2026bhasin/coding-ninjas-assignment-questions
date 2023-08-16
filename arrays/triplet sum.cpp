int tripletSum(int *input, int size, int x)
{
	//Write your code here
	int count=0;
	int i,j,k;
	for(i=0;i<size;i++){
		for(j=i+1;j<size;j++){
			for(k=j+1;k<size;k++){
				if((input[i]+input[j]+input[k])==x){
					count++;
				}
			}
		}
	}
	return count;
}
