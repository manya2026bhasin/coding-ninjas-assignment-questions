/*
Reverse Word Wise

Reverse the given string word wise. That is, the last word in given string should come at 1st place, last second word at 2nd place and so on. Individual words should remain as it is.
Input format :
String in a single line
Output format :
Word wise reversed string in a single line
Constraints :
0 <= |S| <= 10^7
where |S| represents the length of string, S.
Sample Input 1:
Welcome to Coding Ninjas
Sample Output 1:
Ninjas Coding to Welcome
Sample Input 2:
Always indent your code
Sample Output 2:
code your indent Always
*/

void reverseStringWordWise(char input[]) {
  // Write your code here
  int c=0;
  for(int i=0;input[i]!='\0';i++){
      c++;
  }
  int l=c;
  if(l%2==0){
      int j=l/2;
      while(j<l){
          int temp;
          temp=input[l-j-1];
          input[l-j-1]=input[j];
          input[j]=temp;
          j++;
      }
  }
  else{
      int j=(l/2)+1;
      while(j<l){
          int temp;
          temp=input[l-j-1];
          input[l-j-1]=input[j];
          input[j]=temp;
          j++;
      }
  }
   int i=0;
    int k=0;
    while(1){
        if(input[i]==' '|| input[i]=='\0'){
            int x = i-1;
            while(k<x){
                char temp = input[k];
                input[k]=input[x];
                input[x]=temp;
                k++;
                x--;
            }
            k=i+1;
        }
        if(input[i]=='\0'){
            break;
        }
        i++;
    }
}
