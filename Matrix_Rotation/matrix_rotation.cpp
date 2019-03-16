#include <stdio.h>

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
		source_point.row = source_point.column = 0;
		protect = matrix[source_point.row][source_point.column];
		do
		{
			SetTargetRotation();		
			PrintPoints();
			SwapElement();
			
			source_point.row = target_point.row;
			source_point.column = target_point.column;	
		}while( rotationNotCompleted() );
	}

	void SetTargetRotation() {
		if (source_point.row == 0)
		{
			SetTargetRotationForFirstRow();
		}
		else if (source_point.column == MATRIX_SIZE - 1)
		{
			SetTargetRotationForLastColumn();		
		}
		else if(source_point.row == MATRIX_SIZE - 1)
		{
			SetTargetRotationForLastRow();
		}
		else if(source_point.column == 0)
		{
			SetTargetRotationForFirstColumn();
		}
	}

	void SetTargetRotationForFirstRow() {
		if (source_point.column+1 == MATRIX_SIZE)
		{
			target_point.column = MATRIX_SIZE - 1;
			target_point.row = source_point.row + 1;
		}
		else
		{
			target_point.column = source_point.column + 1;
			target_point.row = source_point.row;	
		}
	}

	void SetTargetRotationForLastColumn() {
		if (source_point.row+1 == MATRIX_SIZE)
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
		if (source_point.column == 0)
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
		if (source_point.row == 0)
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
		if ( target_point.row == 0 && target_point.column == 0 ) 
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

int main()
{
	RotatableMatrix obj(3, "edge3.txt"), obj1(4, "edge4.txt");
	
	obj.main();
	obj1.main();
	
	return 0;
}