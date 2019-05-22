#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include "simple_ray/ray_default_scene.h"

int main(int argc, char** argv)
{
	/* TODO: check and parse command line arguments */
	//void checking_parameter(argv){
        int Anzahl_prozesse = atoi(argv[1]);
        int Auflosung= atoi(argv[2]);
        int Samples = atoi(argv[3]);

        if (Anzahl_prozesse<1 || Anzahl_prozesse>128){
            perror("Anzahlprozesse nicht im wertebereich");
            return -1;
        };

        if (Auflosung<1 || Auflosung>10000){
            perror("Auflosung nicht im wertebereich");
            return -1;
        };

        if (Samples<1){
            perror("Samples nicht im wertebereich");
            return -1;
        };


	


	/* initialize scene */
	ray_Scene* scene = ray_createScene();

	/* TODO: divide work load and create n child processes */

	//create bmp rect to save the geteilte bild
	bmp_Rect *part = malloc(sizeof(bmp_Rect)*Anzahl_prozesse);
	
	//create array for x value ( to enhance the bild verteilung in x achse)
	int *part_auflosung = malloc(sizeof(int)* Anzahl_prozesse);

	//divide picture for every process
	for (int i = 0; i < Anzahl_prozesse; ++i)
	{
		if (i== Anzahl_prozesse-1) //part for the last 
		{
			part_auflosung[i]=(Auflosung/Anzahl_prozesse)+(Auflosung%Anzahl_prozesse);
		}else{ //for normal part
			part_auflosung[i]=Auflosung/Anzahl_prozesse;
		}
	}

	//initializing values for bmp rect.
	int *initial_x = calloc(sizeof(int), Anzahl_prozesse);
	for (int i = 0; i < Anzahl_prozesse; ++i)
	{
		(part+i)->x = initial_x[i] * part_auflosung[i] + Auflosung; //x cordinates start from 0.  
		(part+i)->y = Auflosung;
		(part+i)->w = part_auflosung[i];
		(part+i)->h = Auflosung;
		initial_x[i]=i+1;
	}

	//process calling
	int *pid = malloc(sizeof(int)*Anzahl_prozesse);
	int id=-1; //id for parent process ist -1
	for (int i = 0; i < Anzahl_prozesse; ++i)
	{
		pid[i]=fork();
		if (pid[i]==0)
		{
			id=i; //for kind process, kind process id ist all number execept -1
			break;
		}
	}

	/* TODO: each child process renders it's part of the image and saves it to an individual file;
			 the parent process meanwhile waits for children to finish their work
	*/
	if(id != -1){
			//printf("i am child");
			printf("%d\n",id);
			char filename[9];
			sprintf(filename,"img%d.bmp",id);
			printf("%d %d\n",part[id].x,part[id].y);
			bmp_Image* teilimage = malloc(sizeof(bmp_Image));
			teilimage = ray_renderScene(part+id,Auflosung,Auflosung,Samples,scene,NULL);
			bmp_saveToFile(teilimage,filename);
			bmp_free(teilimage);
		}else{
		printf("%d\n",id);
			for(int i = 0;i < Anzahl_prozesse;i++){
				waitpid(pid[i],NULL,0);
			}
		}



	/* TODO: parent process loads all files and merges them into a single image */

	/* TODO: save final image to file "final.bmp" */


	/* free memory */
	//ray_freeScene(scene);
	/* TODO: make sure to free all allocated memory */
	//ray_freeScene(scene);
	
	return 0;
}
