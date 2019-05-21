#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include "simple_ray/ray_default_scene.h"

int main(int argc, char** argv)
{
	/* TODO: check and parse command line arguments */
	int prozesse=atoi(argv[1]);
	int auflösung=atoi(argv[2]);
	int samples=atoi(argv[3]);


	if(!(1<=prozesse && prozesse<=128 && 1<=auflösung && auflösung<=10000 && samples>=1 && argc==4)){	//prüft ob eingabeparamter korrekt 
		printf("Übergabeparameter sind ungültig.\nProgramm beendet.\n");
		return 0;
	} 

	printf("Prozesse: %d\nAuflösung: %d\nSamples %d\n",prozesse,auflösung,samples);
	
	/* initialize scene */
	ray_Scene* scene = ray_createDefaultScene();

	/* TODO: divide work load and create n child processes */
	
	int breite= auflösung/prozesse;
	int restbreite= auflösung%prozesse;

	for(int i=0; i<prozesse;i++){ 
		fork();
		bmp_Rect p;					//evtl. sinnvoller mit einem struct array ?
		p.x=0+i*breite;				//aufteilen des bildes könnte evtl. auch vor for loop erfolgen?
		p.y=0;
		p.w=breite;
		p.h=auflösung;

		if(i==prozesse-1){
			p.w=breite+restbreite;
		}

		//bmp_Rect *sp=&p;
		bmp_saveToFile(ray_renderScene(&p,p.w,p.h,samples,scene,NULL),"bild.bmp");

	}

	/* TODO: each child process renders it's part of the image and saves it to an individual file;
			 the parent process meanwhile waits for children to finish their work
	*/



	/* TODO: parent process loads all files and merges them into a single image */

	/* TODO: save final image to file "final.bmp" */


	/* free memory */
	ray_freeScene(scene);
	/* TODO: make sure to free all allocated memory */
	
	return 0;
}
