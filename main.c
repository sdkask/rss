/*--------------------------------------
 *                                     *                                        
 * Program: ???????                    *
 * Description: Smaller reader RSS.    *
 * Author: Vucamberg Belo dos Santos.  *
 * E-mail: vuca.net@gmail.com          *
 * Date: 2017/01                       *
 *                                     *
 *-------------------------------------*/

#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<errno.h>

#define FILESIZE 5000

int main(int argc, char *argv[]){
	int fd_in_url;
	int i, j=1, k;
	char *buf_cont_file;
	char *aux;

	buf_cont_file=malloc(FILESIZE);
	memset(buf_cont_file,0, FILESIZE);

	if((fd_in_url=open(argv[1], O_RDONLY))<1){
		printf("Erro: %s\n", strerror(errno));
		exit(1);
	}

	if((read(fd_in_url, buf_cont_file, FILESIZE))<1){
		printf("Erro:  %s\n", strerror(errno));
		exit(1);
	}

	for(i=0;i<strlen(buf_cont_file);i++){
		while(buf_cont_file[k]!='\n'){
			printf("%c",buf_cont_file[k]);
			k++;
		}
		if(buf_cont_file[i]=='\n'){
			printf(" Linha %d\n", j), j++;
			k++;
		}
	}

	free(buf_cont_file);

	return 0;
}
