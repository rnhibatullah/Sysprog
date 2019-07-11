#include "matrix.h"

matrix* create_matrix(unsigned int m, unsigned int n, int* numbers)
{
	/*TODO:
			-Argumente auf Gueltigkeit ueberpruefen
			-neue Matrix erstellen und zurückgeben (Pointer!!!)
			-(das Array soll dabei zwar kopiert, aber ansonsten UNVERAENDERT abgespeichert werden.
			  Dies ist für die automatischen Tests unerlässlich)
	*/
	if (m*n != (sizeof(numbers)/sizeof(int)))
	{
		printf("m*n ist the same as size of numbers");
		exit(1);
	}

	matrix *newMatrix = (matrix*)malloc(sizeof(matrix));
	if(newMatrix == NULL){
		printf("\n");
		exit(1);
	}
	newMatrix->m = m;
	newMatrix->n = n;
	newMatrix->elements = (int*) malloc(sizeof(int)*m*n);

	for (int i = 0; i < m*n; ++i)
	{
		/* code */
		newMatrix->elements[i]=numbers[i];
	}

	return newMatrix;
}

matrix* create_matrix_from_row(unsigned int m, unsigned int row_nr, matrix* row)
{
	/*TODO
			-Argumente auf Gueltigkeit ueberpruefen
			-Erstellen einer neuen Matrix (Initialisierung mit 0)
			-Kopieren der gegebenen Zeile an die richtige Stelle
	*/
	matrix *newMatrix = (matrix*)malloc(sizeof(matrix));
	if(newMatrix == NULL){
		printf("ungultige matrix bei create matrix from row");
		exit(1);
	}
	
	//erstelle neue matrix mit zero
	for (int i = 0; i < row->n*m; ++i)
	{
		newMatrix->elements[i]=0;
	}

	for (int i = 0; i < row->n ; ++i)
	{
		newMatrix->elements[row_nr*row->n+i] = row->elements[i];
	}




	
	return NULL;
}

void free_matrix(matrix* matrix)
{
	/*TODO:
			-Argumente auf Gueltigkeit ueberpruefen
			-Matrix und alle dynamisch reservierten elemente der Matrix freigeben
	*/
	if(matrix == NULL){
		printf("ungultige Matrix bei free matrix");
		exit(1);
	}
	free(matrix->elements);
	free(matrix);

	
}

matrix* duplicate_matrix(matrix* old)
{
	/*TODO:
			-Argumente auf Gueltigkeit ueberpruefen
			-Erstellen und Zurückgeben einer NEUEN Matrix mit genau den selben Parametern der gegebenen Matrix
	*/
	matrix *newMatrix = (matrix*)malloc(sizeof(matrix));
	if(newMatrix == NULL){
		printf("ungultige matrix bei duplicate matrix");
		exit(1);
	}
	int n = old->n;
	int m = old->m;
	newMatrix->n = n;
	newMatrix->m = m;
	
	for (int i = 0; i < m*n; ++i)
	{
		/* code */
		newMatrix->elements[i] = old->elements[i];
	}
	


	return newMatrix;
}

matrix* add_matrix(matrix* a, matrix* b)
{
	/*TODO:
			-Argumente auf Gueltigkeit ueberpruefen
			-Elementweises Addieren von a und b (a+b)
			-Rueckgabe des Ergebnisses
	*/
	for (int i = 0; i < b->m*b->n; ++i)
	{
		/* code */
		b->elements[i]=b->elements[i]+ a->elements[i];
	}

	return b;
}

matrix* subtract_matrix(matrix* a, matrix* b)
{
	/*TODO:
			-Argumente auf Gueltigkeit ueberpruefen
			-Elementweises Subtrahieren von a und b (a-b)
			-Rueckgabe des Ergebnisses
	*/
	for (int i = 0; i < b->m*b->n; ++i)
	{
		/* code */
		b->elements[i]=a->elements[i]- b->elements[i];
	}
	
	return b;
}

int get_elem_of_matrix(matrix* matrix, unsigned int i, unsigned int j)
{
	/*TODO
		-Argumente auf Gueltigkeit ueberpruefen
		-Rueckgabe des Elements an den Indizes i und j	
	*/
	int result =0;
	result = matrix->elements[(i)*matrix->m + j];

	return result;
}

int check_matrix(matrix* matrix)
{
	/*TODO:
			-Argumente auf Gueltigkeit ueberpruefen
			-Pruefen, ob die Elemente der Matrix <, > oder = 0 sind
			->sobald ein Element <0 ist, soll -1 zurückgegeben werden
			->wenn alle Elemente 0 sind, soll 0 zurückgegeben werden
			->ansonsten soll 1 zurückgegeben werden
	*/
	for (int i = 0; i < matrix->m * matrix->n; ++i)
	{
		if (matrix->elements[i]<0)
		{
			return -1;
		}
		if(matrix->elements[i]==0){
			continue;
		}
		return 0;

	}

	return 1;
}

matrix* get_row_from_matrix(matrix* mat, unsigned int m)
{
	/*TODO:
			-Argumente auf Gueltigkeit ueberpruefen
			-Rueckgabe der m-ten Zeile der Matrix (Die Zeile selbst ist auch wieder eine Matrix mit genau einer Zeile)
	*/

	matrix *newMatrix = (matrix*)malloc(sizeof(matrix));
	if(newMatrix == NULL){
		printf("ungultige matrix get row from matrix");
		exit(1);
	}

	newMatrix->m = 1;
	newMatrix->n = mat->n;
	newMatrix->elements = malloc(sizeof(int));

	for (int i = 0; i < mat->n ; ++i)
	{
		newMatrix->elements[i] = mat->elements[m*mat->n+i];
	}




	return NULL;

}

void clear_row_of_matrix(matrix* matrix, unsigned int m)
{
	/*TODO
			-Argumente auf Gueltigkeit ueberpruefen
			-Die m-te Zeile der gegebenen Matrix nullen (alle Einträge auf '0' setzen)
	*/
	for (int i = 0; i < matrix->n ; ++i)
	{
		matrix->elements[(m)*matrix->n+i] =0;
	}

}

void print_matrix(matrix* matrix)
{
	if(matrix == NULL)
	{
		printf("ERROR: print_matrix() | given matrix is NULL\n");
		return;
	}


	//determines the largest element
	int max = get_elem_of_matrix(matrix, 0,0);
	for(int i = 0; i< matrix->m; i++)
	{
		for(int j = 0; j < matrix->n; j++)
		{
			int current = get_elem_of_matrix(matrix, i,j);
			max = (current>max) ? current : max;
		}
	}

	int grade = 1;	//represents the number of digits of the largest element
	while(max > 9)
	{
		max/=10;
		grade++;
	}

	//prints upper line
	printf(" ");
	for(int i = 0; i< ((grade + 1)*matrix->n +1); i++)
	{
		printf("-");
	}
	printf("\n");

	//prints body
	for(int i = 0; i< matrix->m; i++)
	{
		printf("| ");
		for(int j = 0; j < matrix->n; j++)
		{
			printf("%*i ", grade, get_elem_of_matrix(matrix, i, j));
		}
		printf("|\n");
	}

	//prints lower line
	printf(" ");
	for(int i = 0; i< ((grade + 1)*matrix->n +1); i++)
	{
		printf("-");
	}
	printf("\n");
}


//===============================================================================

/*TODO:
	Hier koennen bei Bedarf eigene Funktionen implementiert werden
*/


//===============================================================================
