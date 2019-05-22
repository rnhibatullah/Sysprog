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
	ray_Scene* scene = ray_createDefaultScene();

	/* TODO: divide work load and create n child processes */

	//create bmp rect to save the geteilte bild.
	bmp_Rect *part = calloc(sizeof(bmp_Rect),Anzahl_prozesse+1);
	
	//create array for x value ( to enhance the image verteilung in x achse)
	int *part_auflosung = malloc(sizeof(int)* Anzahl_prozesse);

	//divide picture for every process
	for (int i = 0; i < Anzahl_prozesse; ++i)
	{
		if (i== Anzahl_prozesse-1) //for the last process
		{
			part_auflosung[i]=(Auflosung/Anzahl_prozesse)+(Auflosung%Anzahl_prozesse);
		}else{ //for normal process
			part_auflosung[i]=Auflosung/Anzahl_prozesse;
		}
	}

	//initializing values for bmp rect.
	int initial_x = 0;
	for (int i = 0; i < Anzahl_prozesse; ++i)
	{
		part[i].x = initial_x * part_auflosung[i]; //x cordinates start from 0.  
		part[i].y = 0;
		part[i].w = part_auflosung[i];
		part[i].h = Auflosung;
		initial_x++;
	}

	//process calling
	int *pid = malloc(sizeof(int)*Anzahl_prozesse);
	int id=-1; //id for parent process ist -1
	for (int i = 0; i < Anzahl_prozesse; ++i)
	{
		pid[i]=fork();
		if (pid[i]==0)
		{
			id=i; //child process id ist all number execept -1
			break;
		}
	}

	/* TODO: each child process renders it's part of the image and saves it to an individual file;
			 the parent process meanwhile waits for children to finish their work
	*/

	

	//for all process execpt parent 
	if(id == -1){
		for(int i = 0;i < Anzahl_prozesse;i++)
		{
			waitpid(pid[i],NULL,0);
		}

	}else{

		//file name for bmp
		char filename[9];
		sprintf(filename,"img%d.bmp",id);



		//process progress name
		char processname[10];
		sprintf(processname,"process%d",id);

		//save the part_rendered image
		bmp_Image* part_rendered = malloc(sizeof(bmp_Image));
		part_rendered = ray_renderScene((part+id),Auflosung,Auflosung,Samples,scene,processname);
			
		//save the part_rendered image to file
		bmp_saveToFile(part_rendered,filename);
		bmp_free(part_rendered);

		
	}



	/* TODO: parent process loads all files and merges them into a single image */

	//load from data
	bmp_Image * load_from_data_part_rendered = malloc(sizeof(bmp_Image));
	load_from_data_part_rendered = bmp_loadFromData(Auflosung,Auflosung,NULL);

	for (int i = 0; i < Anzahl_prozesse; ++i)
	{
	

			//file name for bmp
			char filename[9];
			sprintf(filename,"img%d.bmp",i);


			//load from file
			bmp_Image * load_part_rendered = malloc(sizeof(bmp_Image));
			load_part_rendered = bmp_loadFromFile(filename);
			
			bmp_stamp(load_part_rendered, load_from_data_part_rendered,part[i].x,part[i].y);

	}


	/* TODO: save final image to file "final.bmp" */
	//file name for bmp
	char filename[10];
	sprintf(filename,"final.bmp");


	bmp_saveToFile(load_from_data_part_rendered,filename);

	
	/* free memory */
	ray_freeScene(scene);
	//free(load_from_data_part_rendered);

	//free part*
	for (int i = 0; i < Anzahl_prozesse; ++i)
	{
		free(part);
	}
	free(part);


	//free part_auflosung
	for (int i = 0; i < Anzahl_prozesse; ++i)
	{
		free(part_auflosung);
	}
	free(part_auflosung);


	/* TODO: make sure to free all allocated memory */
	//ray_freeScene(scene);
	
	return 0;
}
