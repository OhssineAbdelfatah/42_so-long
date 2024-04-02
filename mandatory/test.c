char *int_to_str(int nbr){
    int num;
    int len;
    int i;
    char * str;
    num = nbr;
    len = 0;
    i = 0;
    while(num){
        num=num/10;
        len++;
    }
    str = malloc(len+1);
    while(i< len){
        str[len-1-i] = nbr%10 +48;
        nbr/=10;
        i++; 
    }
    str[len]=0;
    return str;
}