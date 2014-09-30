// this is a program  when we use files. 
#include <stdio.h>
#include <stdio.h>

struct info{
	char emri[20];
	char mbiemri[20];
	char gjinia[20];
	int mosha;
}; 
int main(){
	int n,i,j;
	printf("Jepni n:");
 	scanf("%d", &n);
 	struct info personi[n];
	FILE *fp;
	fp=fopen("info.txt","r");
	if(fp==NULL) {
		printf("Error!");
		return;
	}
	
	for (i=0;i<n;i++){
		fscanf(fp,"%s",personi[i].emri);
		fscanf(fp,"%s",personi[i].mbiemri);
		fscanf(fp,"%s",personi[i].gjinia);
		fscanf(fp,"%d",&personi[i].mosha);
	}
	
	for (i=0;i<n;i++) {
		for(j=i;j<n;j++)
			if(personi[i].mosha>personi[j].mosha){
				struct info temp;
				temp=personi[i];
				personi[i]=personi[j];
				personi[j]=temp;
			}
			if(personi[i].mosha==personi[j].mosha){
				if (strcmp(personi[i].mbiemri,personi[j].mbiemri)>0){
					struct info temp;
					temp=personi[i];
					personi[i]=personi[j];
					personi[j]=temp;
				}
			}
			if(strcmp(personi[i].mbiemri,personi[j].mbiemri)==0){
				if (strcmp(personi[i].emri,personi[j].emri)>0){
					struct info temp;
					temp=personi[i];
					personi[i]=personi[j];
					personi[j]=temp;
				}
			}
	}
	int k=0;
	struct info personal[k];
	for (i=0;i<n;i++){
		if(personi[i].mosha>=18) {
			personal[k]=personi[i];
			k++;
		}
	}
	for (i=0;i<k;i++){
		printf("Emri: %s\n",personal[i].emri);
		printf("Mbiemri: %s\n",personal[i].mbiemri);
		printf("Gjinia: %s\n",personal[i].gjinia);
		printf("Mosha: %d\n",personal[i].mosha);
		printf("\n");
	}
	
	FILE *fptr;
	fptr=fopen("info.dat","wb");
	if(fptr==NULL){
		printf("Error!");
    }
	fwrite(&personal,sizeof(struct info),k,fptr);
	
	fclose(fp);
	fclose(fptr);
	return 0;
}
