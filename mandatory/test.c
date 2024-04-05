// char *int_to_str(int nbr){
//     int num;
//     int len;
//     int i;
//     char * str;
//     num = nbr;
//     len = 0;
//     i = 0;
//     while(num){
//         num=num/10;
//         len++;
//     }
//     str = malloc(len+1);
//     while(i< len){
//         str[len-1-i] = nbr%10 +48;
//         nbr/=10;
//         i++; 
//     }
//     str[len]=0;
//     return str;
// }
int check_map_name(char *name){
    int i;
    int j;
    int k;
    char *ext;

    ext = ".ber";
    i = 0;
    k = 3;
    while(name[i++]);    
    j = i;
    i--;
    while(i-- > j-4){
        if(name[i] != ext[k]){
            return -1;
        }
        k--;
    }
    return 0;
}

#include"so_long.h"
#include"stdio.h"

int main(){
    ft_printf("%d ",check_map_name("mab"));
}