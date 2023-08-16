bool checkPalindrome(char str[]) {
    // Write your code here
    int count=0;
    for(int i=0;str[i]!='\0';i++){
        count++;
    }
    for(int i=0;i<count;i++){
        if(str[i]!=str[count-1-i]){
            return false;
        }
    }
    return true;
}
