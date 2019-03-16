#include <stdio.h>
#include <stdlib.h>

struct Point {
	int row;
	int column;
};

class RotatableMatrix
{
	public:

	RotatableMatrix(int size, const char *fileName):
	MATRIX_SIZE(size)
	{
		LoadFromFile(fileName);

		protect = 0;
	}
	
	int main(void) {	
		RotateOuterMatrix();

		PrintMatrix();

		TestIfOuterMatrixRotated();

		return 0;
	}

	private:
	
	const int MATRIX_SIZE ;

	Point source_point, target_point;

	int matrix[10][10] ;
	int resultant_matrix[10][10];					
	int protect;
	int LOWER_BOUND;
	int UPPER_BOUND;

	void LoadFromFile(const char *fileName)
	{
		FILE *fptr;
		int row = 0, column = 0, flag = 1;

		fptr = fopen(fileName, "r");
		
		int buf; 
		
		for(row = 0; (row < MATRIX_SIZE) && (flag == 1); row++)
		{
			for(column = 0; (column < MATRIX_SIZE) && (flag == 1); column++)
			{
				fscanf(fptr, "%d", &buf);
				
				matrix[row][column] = buf;
			}
		}
		
		for(row = 0; (row < MATRIX_SIZE) && (flag == 1); row++)
		{
			for(column = 0; (column < MATRIX_SIZE) && (flag == 1); column++)
			{
				fscanf(fptr, "%d", &buf);
				
				resultant_matrix[row][column] = buf;
			}
		}
		
		fclose(fptr);
	}
	
	void SwapElement() {
		int temp = matrix[target_point.row][target_point.column];
		matrix[target_point.row][target_point.column] = protect;
		protect = temp;
	}

	void RotateOuterMatrix() {
		
		int iter;
		
		for(iter = 0; iter < (MATRIX_SIZE/2); ++iter)
		{
			LOWER_BOUND = iter ;
			UPPER_BOUND = MATRIX_SIZE - iter;
			
			source_point.row = source_point.column = LOWER_BOUND;
			protect = matrix[source_point.row][source_point.column];
			do
			{
				SetTargetRotation();		
				//PrintPoints();
				SwapElement();
				
				source_point.row = target_point.row;
				source_point.column = target_point.column;	
			}while( rotationNotCompleted() );
		}
	}

	void SetTargetRotation() {
		if (source_point.row == LOWER_BOUND)
		{
			SetTargetRotationForFirstRow();
		}
		else if (source_point.column == UPPER_BOUND - 1)
		{
			SetTargetRotationForLastColumn();		
		}
		else if(source_point.row == UPPER_BOUND - 1)
		{
			SetTargetRotationForLastRow();
		}
		else if(source_point.column == LOWER_BOUND)
		{
			SetTargetRotationForFirstColumn();
		}
	}

	void SetTargetRotationForFirstRow() {
		if (source_point.column+1 == UPPER_BOUND)
		{
			target_point.column = UPPER_BOUND - 1;
			target_point.row = source_point.row + 1;
		}
		else
		{
			target_point.column = source_point.column + 1;
			target_point.row = source_point.row;	
		}
	}

	void SetTargetRotationForLastColumn() {
		if (source_point.row+1 == UPPER_BOUND)
		{
			target_point.row = source_point.row;
			target_point.column = source_point.column - 1;
		}
		else
		{
			target_point.column = source_point.column;
			target_point.row = source_point.row + 1;	
		}
	}

	void SetTargetRotationForLastRow() {
		if (source_point.column == LOWER_BOUND)
		{
			target_point.row = source_point.row - 1;
			target_point.column = source_point.column;
		}
		else
		{
			target_point.column = source_point.column - 1;
			target_point.row = source_point.row;	
		}
	}

	void SetTargetRotationForFirstColumn() {
		if (source_point.row == LOWER_BOUND)
		{
			target_point.row = source_point.row;
			target_point.column = source_point.column + 1;
		}
		else
		{
			target_point.column = source_point.column;
			target_point.row = source_point.row - 1;	
		}
	}

	void PrintPoints() {
		printf("Source: (%d, %d) | Target: (%d, %d)\n", 
			source_point.row, source_point.column, target_point.row, target_point.column);
	}

	int rotationNotCompleted() {
		if ( target_point.row == LOWER_BOUND && target_point.column == LOWER_BOUND ) 
		{
			return 0;
		}
		return 1;
	}

	void TestIfOuterMatrixRotated(){
		int row = 0, column = 0, flag = 1;

		for(row = 0; (row < MATRIX_SIZE) && (flag == 1); row++)
		{
			for(column = 0; (column < MATRIX_SIZE) && (flag == 1); column++)
			{
				if(matrix[row][column] != resultant_matrix[row][column])
				{
					flag = 0;
				}
			}
		}

		printf("%s\n", flag ? "OK" : "FAIL");
	}

	void PrintMatrix() {
		int row = 0, column = 0, flag = 1;

		for(row = 0; (row < MATRIX_SIZE) && (flag == 1); row++)
		{
			for(column = 0; (column < MATRIX_SIZE) && (flag == 1); column++)
			{
				printf("%d\t",matrix[row][column]);
			}
			printf("\n");
		}
	}
};

int main(int argc, char *argv[])
{
	int size = atoi(argv[1]);
	char *fileName = argv[2];
	
	RotatableMatrix object(size, fileName);
	
	object.main();
	
	return 0;
}