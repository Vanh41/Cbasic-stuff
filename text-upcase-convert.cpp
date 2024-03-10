void convert(char *str) {
    int i = 0;
    while (str[i] != '\0') {
        str[i] = toupper(str[i]); 
        i++;
    }
}

int main(){
	char a[100000];
	scanf("%[^\t]s",a);
	convert(a);
	printf("%s",a);
}
