#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct date {
	int day, month, year;
}date;


typedef struct director_info {
	char* director_surname, * director_name;
}director_info;


typedef struct movie {
	int id;
	char* title;
	director_info* director;
	date* release_date;
}movie;



int main(void)
{
	FILE* fp;
	int i = 0;
	int lines = 0;
	char ch;
	int eggrafes;
	struct movie* movieArray;
	int mov_size = 100;
	int choice;
	int found;
	int thesi;
	movie temp;
	int k=0;
	
	
	//Anoigma tou arxeiou
	fp = fopen("text.txt", "r");
	if (fp == NULL)
	{
		printf(" Error: fopen() failed\n");
		exit(EXIT_FAILURE);
	}

	//Desmeusi mnimis 
	movieArray=(movie*)malloc(sizeof(movie) * mov_size);
	if (!movieArray)
	{
		printf("\nMemory commitment failure");
		exit(0);
	}

	//Metrisi grammwn arxeiou
	while ((ch = fgetc(fp)) != EOF)
	{
		if (ch == '\n')
		{
			lines++;
		}
	}

	//Rewind arxi arxeiou
    if(lines>1)
    {
	fseek(fp, 0, SEEK_SET); 
	}			

	//Diavasma arxeiou
	while (!feof(fp))
	{
		
		eggrafes = (lines / 7);
		//printf("eggrafes: %d\n", eggrafes);

		for (i = 0; i <eggrafes; i++) 
		{
			//Arxikopoisi
			int id = 0;
			char title[40];
			char director_name[40];
			char director_surname[40];
			int day, month, year = 0;
			
			//Diavasma eggrafwn
			fscanf(fp, "%d\n", &id);
		    fgets(title, 40, fp);
		    size_t sl = strlen(title); // size_t typos tou s1 gia strlen, metraei to mikos tou alvarithimikou
				if(sl > 0 && title[sl - 1] == '\n')
				{
   					title[sl - 1] = '\0';
				}		
		    fgets(director_name, 40, fp);
		    size_t s2 = strlen(director_name);
				if(s2 > 0 && director_name[s2 - 1] == '\n')
				{
   					director_name[s2 - 1] = '\0';
				}	
			fgets(director_surname, 40, fp);
			size_t s3 = strlen(director_surname);
				if(s3 > 0 && director_surname[s3 - 1] == '\n')
				{
   					director_surname[s3 - 1] = '\0';
				}	
			fscanf(fp, "%d\n", &day);
			fscanf(fp, "%d\n", &month);
			fscanf(fp, "%d\n", &year);

	    	//Desmeusi mnimis kai anathesi
			movieArray[i].id = id;
			
			movieArray[i].title = (char*)malloc(40 * sizeof(char));
			memcpy(movieArray[i].title, title,40);
			
			movieArray[i].director = (director_info*)malloc(sizeof(director_info));
			
			movieArray[i].director->director_name = (char*)malloc(40 * sizeof(char));
			memcpy(movieArray[i].director->director_name, director_name,40);
			
			movieArray[i].director->director_surname = (char*)malloc(40 * sizeof(char));
			memcpy(movieArray[i].director->director_surname, director_surname,40);
			
			movieArray[i].release_date = (date*)malloc(sizeof(date));
			movieArray[i].release_date->day = day;
			movieArray[i].release_date->month = month;
			movieArray[i].release_date->year = year;
			
					
		}
        
	}


//Menou epilogwn
while(1)
	{
		printf("\n\nMenu selections\n");
		printf("-----------------------\n");
		
		printf("1. Insert a new movie\n");
		printf("2. Delete a movie based on movie's id\n");
		printf("3. Search a movie based on movie's title\n");
		printf("4. Search a movie based on movie's director\n");
		printf("5. Exit\n");
		
		printf("\nEnter choice: ");
		scanf("%d", &choice);
		getchar();
		
		switch(choice)
		{
			//Prosthiki neas eggrafis
			case 1:
			{
						
				int id;
				char title[40];
				char director_name[40];
				char director_surname[40];
				int day, month, year = 0;
				int i;
				
				i=eggrafes;
	
				if(eggrafes>100)
				{
					movieArray=(movie*)realloc(movieArray,1);
				}
		
				//Diavasma neas eggrafis
				id=eggrafes;
	
				printf("\nTitle: ");
				gets(title);
	
				printf("\nDirector name: ");
				gets(director_name);
	
				printf("\nDirector surname: ");
				gets(director_surname);
	
				printf("\nRelease date day: ");
				scanf("%d", &day);
				if(day>31 || day<1)
				{
					printf("The day needs to be from 1 to 31");
					printf("\nRelease date day: ");
					scanf("%d", &day);
				}
	
				printf("\nRelease date month: ");
				scanf("%d", &month);
				if(month>12 || month<1)
				{
					printf("The month needs to be from 1 to 12");
					printf("\nRelease date month: ");
					scanf("%d", &month);
				}
	
				printf("\nRelease date year: ");
				scanf("%d", &year);
				if(year>2020 || year<1900)
				{
					printf("The year needs to be from 1900 to 2020");
					printf("\nRelease date year: ");
					scanf("%d", &year);
				}
				
  				//Desmeusi mnimis kai anathesi
				movieArray[i].id=id+1;
	
        		movieArray[i].title=(char*)malloc(40*sizeof(char));
        		memcpy(movieArray[i].title, title,sizeof(40)*10);
		   
				movieArray[i].director = (director_info*)malloc(sizeof(director_info));
			
				movieArray[i].director->director_name = (char*)malloc(40 * sizeof(char));
				memcpy(movieArray[i].director->director_name, director_name,sizeof(40)*10);
			
				movieArray[i].director->director_surname = (char*)malloc(40 * sizeof(char));
				memcpy(movieArray[i].director->director_surname, director_surname,sizeof(40)*10);
				
				movieArray[i].release_date = (date*)malloc(sizeof(date));
				movieArray[i].release_date->day = day;
				movieArray[i].release_date->month = month;
				movieArray[i].release_date->year = year;
		
				eggrafes=eggrafes+1; 
				
			/*
				//Elegxos neas eggrafis
				printf("%d\n", movieArray[eggrafes-1].id);
				printf("%s\n", movieArray[eggrafes-1].title);
				printf("%s\n", movieArray[eggrafes-1].director->director_name);
				printf("%s\n", movieArray[eggrafes-1].director->director_surname);
				printf("%d\n", movieArray[eggrafes-1].release_date->day);
				printf("%d\n", movieArray[eggrafes-1].release_date->month);
				printf("%d\n", movieArray[eggrafes-1].release_date->year);
		
			} 
			*/
			
			break;
			
			//Diagrafi eggrafis
			case 2:
				{
				    int id=0;
					
					for(i=0; i<eggrafes; i++)
					{
						printf("\n=========================================\n");
						printf("%d\n", movieArray[i].id);
						printf("%s\n", movieArray[i].title);
					}
				
				
					printf("\nEnter the id of the movie you want to be deleted: ");
					scanf("%d", &id);
				
					//Euresi thesis eggrafis 
					for(i=0; i<eggrafes; i++)
					{
						if(movieArray[i].id==id)
						{
							found=1;
							thesi=i;
							break;
						}
					}
					
					if(found==0)
					{
						printf("The id was not found\n");
					}
					
					
					if(thesi>=eggrafes+1)
					{
					printf("Deletion not possible.\n");
					}
					else
					{
						//Diagrafi
						for(i=thesi; i<eggrafes-1; i++)
						{
							movieArray[i]=movieArray[i+1]; 
						
					   	}
					   	//Allagi id twn epomenwn eggrafwn
					    for(id; id<eggrafes; id++)
				     	{
						 	movieArray[id-1].id=id;
				     	}
							
						for(i=0; i<eggrafes-1; i++)
						{
						printf("=========================================\n");
						printf("%d\n", movieArray[i].id);
						printf("%s\n", movieArray[i].title);
						}
						
					}
				
				eggrafes=eggrafes-1; 
				
				}
				break;
			
			//Euresi tainias vasi titlou
			case 3:
				{
					
					int result;
        	        char title[40];
				    
				    //Diavasma titlou kai desmeusi mnimis
					printf("\nEnter the title of the movie you want: ");
					gets(title);
					
				    movieArray[i].title=(char*)malloc(40*sizeof(char));
					
					//Euresi thesis
					for(i=0; i<eggrafes; i++)
					{
						result=memcmp(movieArray[i].title, title, sizeof(40));
				
						if(result==0)
						{	
							thesi=i;
							break;
						}
						
					}
					
					if(result==1 || result==-1)
					{
						printf("\nError: The title you entered is not found\n");
					}
				
					//Emfanisi eggrafis
					if(result==0)
					{
						printf("=========================================\n");
						printf("%d\n", movieArray[thesi].id);
						printf("%s\n", movieArray[thesi].title);
						printf("%s\n", movieArray[thesi].director->director_name);
						printf("%s\n", movieArray[thesi].director->director_surname);
						printf("%d\n", movieArray[thesi].release_date->day);
						printf("%d\n", movieArray[thesi].release_date->month);
						printf("%d\n", movieArray[thesi].release_date->year);
					}
					
				}
				break;
			
			//Euresi tainiwn vasi skinotheti
			case 4:
				{
					int i,j;
					char temp[40];
					movie temp2;
					char temp3[40];
					int start=0;
					int end=eggrafes-1;
					int middle;
					char surname[40];
				 
					//Taksinomisi alfavitika vasi epithetou 
					for(i=0; i<eggrafes; i++)
					{
					    memcpy(temp, movieArray[i].director->director_surname,sizeof(40));
						memcpy(temp3, movieArray[i].title,sizeof(40));
					    
						j=i; 
						while((j>0))
						{
							if(memcmp(movieArray[j-1].director->director_surname, temp,sizeof(40))>0)
							{ //swap
								temp2=movieArray[j];
								movieArray[j]=movieArray[j-1];
								movieArray[j-1]=temp2;	
							}
							//An to epitheto einai idio, taksinomisi alfavitika vasi titlou
							else if(memcmp(movieArray[j-1].director->director_surname, temp,sizeof(40))==0)
							{
				   				if(memcmp(movieArray[j-1].title, temp3,sizeof(40))>0)
								{
				      				while(j-1>0) 
									{	//swap
										temp2=movieArray[j];
										movieArray[j]=movieArray[j-1];
										movieArray[j-1]=temp2;
										j--;
			     					}
								}	
							}
			      		
						  j--;
						}
					}
				
				/*	
					//Elegxos taksinomisis
					for(i=0; i<eggrafes; i++)
					{
						printf("=========================================\n");
						printf("%d\n", movieArray[i].id);
						printf("%s\n", movieArray[i].title);
						printf("%s\n", movieArray[i].director->director_surname);
					
					}
				*/
					//Diavasma epithetou kai desmeusi mnimis 
					printf("\nEnter the surname to be searched: ");
					gets(surname);
			
			
		    		movieArray[i].director = (director_info*)malloc(sizeof(director_info));
					movieArray[i].director->director_surname = (char*)malloc(40 * sizeof(char));
			
					//Binary search
					do
					{
						middle=(start+end)/2; 
						if(memcmp(surname,movieArray[middle].director->director_surname,sizeof(40))<0)
						{
							end=middle-1;	
						}
						else if(memcmp(surname,movieArray[middle].director->director_surname,sizeof(40))>0) 
						{
							start=middle+1;
						}
						
					}while(memcmp(surname,movieArray[middle].director->director_surname,sizeof(40))!=0 && start<=end); 
			
					
					if(memcmp(surname,movieArray[middle].director->director_surname,sizeof(40))==0)
					{
						printf("\nFound\n");
						thesi=middle;
					
						printf("=========================================\n");
						printf("%d\n", movieArray[middle].id);
						printf("%s\n", movieArray[middle].title);
						printf("%s\n", movieArray[middle].director->director_name);
						printf("%s\n", movieArray[middle].director->director_surname);
						printf("%d\n", movieArray[middle].release_date->day);
						printf("%d\n", movieArray[middle].release_date->month);
						printf("%d\n", movieArray[middle].release_date->year);
					}
					else
					{
						printf("\nFailed");
					}
			
					//Elegxos deksia kai aristera gia idio epitheto
		   			for(i=0; i<thesi; i++) // deksia
		   			{
		   				if((memcmp(surname,movieArray[i].director->director_surname,sizeof(40))==0))
		   				{
		   					printf("=========================================\n");
							printf("%d\n", movieArray[i].id);
							printf("%s\n", movieArray[i].title);
							printf("%s\n", movieArray[i].director->director_name);
							printf("%s\n", movieArray[i].director->director_surname);
							printf("%d\n", movieArray[i].release_date->day);
							printf("%d\n", movieArray[i].release_date->month);
							printf("%d\n", movieArray[i].release_date->year);	
			  			}
		   			}
		   
		   
		  	  		for(i=eggrafes; i>thesi; i--) // aristera
		  			{
		   				if((memcmp(surname,movieArray[i].director->director_surname,sizeof(40))==0))
		   				{
		   					printf("=========================================\n");
							printf("%d\n", movieArray[i].id);
							printf("%s\n", movieArray[i].title);
							printf("%s\n", movieArray[i].director->director_name);
							printf("%s\n", movieArray[i].director->director_surname);
							printf("%d\n", movieArray[i].release_date->day);
							printf("%d\n", movieArray[i].release_date->month);
							printf("%d\n", movieArray[i].release_date->year);	
			  			}
		   			}
				}
				break;
			
			//Overwrite kai exit
			case 5:
				{
					//Anoigma arxeiou kai ovewrite
					fp=fopen("text.txt", "w"); 
	            	if (fp==NULL) 
             		{
		           		printf(" Error: fopen() failed\n");
		            	exit(EXIT_FAILURE);	
	            	} 
	            
					for(i=0; i<eggrafes; i++)
	            	{
						fprintf(fp, "%d\n", movieArray[i].id);
						fprintf(fp, "%s\n", movieArray[i].title);
						fprintf(fp, "%s\n", movieArray[i].director->director_name);
						fprintf(fp, "%s\n", movieArray[i].director->director_surname);
						fprintf(fp, "%d\n", movieArray[i].release_date->day);
						fprintf(fp, "%d\n", movieArray[i].release_date->month);
						fprintf(fp, "%d\n", movieArray[i].release_date->year);
	            	}
				
					//Kleisimo arxeiou, apodesmeusi mnimis kai eksodos
					fclose(fp);
					free(movieArray);
					exit(0);
				}
			
			default:
				printf("\n Wrong choice\n");
			break;
				
	}
	
}

}
}


