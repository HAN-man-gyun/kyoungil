#include <iostream>
#include <conio.h>
void Desc001();
void  ArrayFunc(int* ptrArray);
void  ArrayFunc1(int* ptrArray, int arraySize);
void  ArrayFunc2(int array_[], int arraySize);
void selectionSort();
void ShuffleOnce(int* firstNumber, int* secondNumber);
void bubbleSort();
void Descrip003();
void control();
void SlidingPuzzle();
int main()
{
	int size;
	std::cin >> size;

	int puzzle[6][6];
	int data = 1;
	for (int y = 0; y < size; y++)
	{
		for (int x = 0; x < size; x++) //초기화
		{
			puzzle[y][x] = data++;
		}
	}
	const int shuffleCount2 = 10;
	srand(time(NULL));
	int randomIdx1, randomIdx2 = 0;
	for (int i = 0; i < shuffleCount2; i++)
	{
		randomIdx1 = rand() % size; // 랜덤한값 rand()에 6을 나누어서 0~5까지나오게함.
		randomIdx2 = rand() % size; //  그후 1을 더함.

		ShuffleOnce(&puzzle[randomIdx1][randomIdx2], &puzzle[randomIdx2][randomIdx1]);
	}

	int playerPosX = size-1; //비어있는 가로의 좌표
	int playerPosY =  size-1; //비어있는 세로의 좌표
	puzzle[playerPosY][playerPosX] = 0;
	//alt 방향키 위아래로 움직이기 가능 

	while (true)
	{
		for (int y = 0; y < size; y++)
		{
			for (int x = 0; x < size; x++)
			{
				
				printf("%d\t", puzzle[y][x]);   //출력
			}
			printf("\n");
		}
		printf("\n");

		char input;
		input = _getch(); //즉시 반영을 위해 _getch()를 사용하고 input에 입력을 받음
		switch (input) //input의 결과에  따라 플레이어의 x와 y좌표를 옮김
		{
		case 'a':
			ShuffleOnce(&puzzle[playerPosY][playerPosX], &puzzle[playerPosY][playerPosX - 1]);
			if (playerPosX > 0)
			playerPosX--;
			break;
		case 'w':
			ShuffleOnce(&puzzle[playerPosY][playerPosX], &puzzle[playerPosY - 1][playerPosX]);
			if(playerPosY>0)
			playerPosY--;
			break;
		case 's':
			ShuffleOnce(&puzzle[playerPosY][playerPosX], &puzzle[playerPosY + 1][playerPosX]);
			if (playerPosY < size-1)
			playerPosY++;
			break;
		case 'd':
			ShuffleOnce(&puzzle[playerPosY][playerPosX], &puzzle[playerPosY][playerPosX + 1]);
			if(playerPosX < size-1)
			playerPosX++;
			break;
		}
		puzzle[playerPosY][playerPosX] = 0;

		/*
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				if(puzzle[i][j] == )
			}
		}
		*/
		system("cls");
	}

	return 0;
}

void Desc001()
{
	int numbers[10] = { 0, };
	for (int i = 0; i < 10; i++)
	{
		numbers[i] = i + 1;
	}
	for (int i = 0; i < 10; i++)
	{
		printf("%d", numbers[i]);
	}
	printf("\n");
	
	int* ptrNumber = &numbers[2];
	printf("3번째 자리에 있는 값 +1-> %d\n", (*ptrNumber) + 1);
	//*을 통해 역참조하여 numbers3번째자리에 있는값 3에서 1을 더해서 4가 나왔다.
	printf("주소에 1을더한 값 +1-> %d\n", ptrNumber + 1);
	//*를 사용하지않고 ptr에 저장되어있는 주소에 순수하게 1을 더하면 어떻게될까?.
	//ptrNumber는 4byte인 int형을 가리킨다. 즉 ptr이 가지고있는 주소에 1을 더하면
	//1이 더해지는것이 아닌 주소에 4byte가 더해지는것이다. 4byte가 한칸 더해졌으니 당연히
	//다음 인덱스의 주소가 나오는것이다.
	printf("3번째 자리에 있는 값 +1-> %d\n", *(ptrNumber + 1));
	//이경우 4가 나온다.
	
	//numbers의 주소는 numbers[0]의 주소와 같다.
	printf("numbers의 주소값 -> %p\n", numbers);
	printf("numbers[0] 의 주소값 -> %p\n", &numbers[0]);
	printf("\n");
	ArrayFunc1(numbers, 10);


	printf("numbers 의 Size :%d \n", sizeof(numbers));
	ArrayFunc2(numbers, 10);
	//결국 배열을 함수의 인자로 넣어도 내부적으로 포인터와 같이 작동하며
	//컴퓨터는 여전히 배열의 크기를 모른다.
	//이때문에 배열을 넣는 함수도 크기를 같이 넣어줘야한다.
	//포인터의 크기는 기본적으로 8byte다 즉. sizeof(array_)
	//sizeof(ptrArray)는 둘다 8byte가 된다. +1을하면 64bit에서는 8byte가 증가한다.

	//numbers[4];  가 배열에서의 역참조
	//*(ptrNumber+4) 가 포인터에서의 역참조
}
void  ArrayFunc(int* ptrArray)
{
		printf("ptrArray 역참조 값 : %d\n", *(ptrArray));
		printf("ptrArray +1 주소의 역참조 값 : %d\n", *(ptrArray + 1));
		//ptrArray는 배열크기10의 numbers를 참조하고있는데 이때 배열크기를 넘어선
		//값을 더하더라도 문법상으로 오류가 나지않는다. 이것을 주의해야한다.
		//또한 이것을 방지하기위해 함수에 배열의 크기를 같이 인수로 넣어주어서
		//반복문으로 배열의 크기를 넘어서지않도록 지정해줘야한다.
}

void  ArrayFunc1(int* ptrArray, int arraySize)
{
	for (int i = 0; i < arraySize; i++)
	{
		printf("ptrArray[%d] 역참조 값 :%d\n", i, *(ptrArray + i));
	}
}

void  ArrayFunc2(int array_[], int arraySize)
{
	printf("함수에서 찍어본 numbers의 Size :%d\n", sizeof(array_));
	for (int i = 0; i < arraySize; i++)
	{
		printf("array[%d]의 값 :%d\n", i, array_[i]);
	}
}
//정렬
//선택정렬 
//반복문에서 가장 작은값을 찾아서 0번째 인덱스와 교환한다.
//다음루프에서 0번째 인덱스는 빼고 나머지루프를 돈다.
//또 가장작은 값을 찾아서 1번째 인덱스와 교환한다.
//다음 루프에서 0~1번째 인덱스는 빼고 나머지 루프를 돈다.
//이하 반복하면 순서대로 오름차순으로 값이 정렬된다.
//21,59,36,99,17이 있다고 가정하면
//1번쨰사이클 17을 찾아서 0번째인덱스 21과 스왑 ->17,59,36,99,21
//2본쨰사이클 21을 찾아서 1번째인덱스 59와 스왑 ->17,21,36,99,59
void ShuffleOnce(int *firstNumber, int *secondNumber) // 인수로 포인터를 받는다.
{
	int temp = 0;
	temp = *firstNumber; //* temp에 임시로 first의 역참조값을 저장
	*firstNumber = *secondNumber; 
	*secondNumber = temp;

}
void selectionSort()
{
	int array1[5] = { 0, };  //배열array1의 선언
	for (int i = 0; i < 5; i++)
	{
		std::cin>>array1[i]; //for문을 통해 array1에 입력받기
	}

	for (int i = 0; i < ((sizeof(array1)/sizeof(int))-1); i++)
	{//i가 0부터  3까지 나오게한다. sizeof(array1)/sizeof(int)은 = 20/4 =5이다.
		for (int j = i + 1; j < (sizeof(array1)/sizeof(int)); j++)
		{
			if (array1[i] > array1[j])
			{
				ShuffleOnce(&array1[i], &array1[j]); //ShuffleOnce에 배열인덱스의 주소를 전달한다.
			}
		}
	}
	for (int i = 0; i < sizeof(array1)/sizeof(int); i++)
	{
		printf("%d ", array1[i]); //배열출력문
	}
}

//버블정렬은 0번째 인덱스와 1번째 인덱스를 비교해서 스왑한다.
//작은 값은 왼쪽, 큰값은 오른쪽으로 스왑한다. 다음 사이클에서 1번쨰 인덱스와
//2번쨰 인덱스를 비교해서 작은값은 오른쪽으로 스왑한다.
//21,59,36,99,17
//1번째 사이클에서 21과 59를 비교한후 59가 크기에 움직이지않고 넘어간다.
//2번째 사이클에서 59와 36을 비교한후 59가 크기에 59를 오른쪽으로 움직인다.
//3번째 사이클에서 59와 99를 비교한후 99가 크기에 움직이지 않는다.
//4번째 사이클에서 99와 17을 비쿄한후 99가 크기에 99를 오른쪽으로 움직인다.

void bubbleSort()
{
	int array1[5] = { 0, };  //배열array1의 선언
	for (int i = 0; i < 5; i++)
	{
		std::cin >> array1[i]; //for문을 통해 array1에 입력받기
	}
	int cir = (sizeof(array1) / sizeof(int));
	for (cir; cir > 0; cir--)
	{
		for (int i = 0; i < (cir - 1); i++)
		{//i가 0부터  3까지 나오게한다. sizeof(array1)/sizeof(int)은 = 20/4 =5이다.
			int j = i + 1;
			if (array1[i] > array1[j])
			{
				ShuffleOnce(&array1[i], &array1[j]); //ShuffleOnce에 배열인덱스의 주소를 전달한다.
			}
		}
	}
	for (int i = 0; i < (sizeof(array1) / sizeof(int)); i++)
	{
		printf("%d ", array1[i]); //배열출력문
	}
	printf("\n");
}
//삽입정렬
//메인루프를 돌면서 정렬할 요소를 선택한다.정렬할 요소를 이미 정렬이 끝난 배열 안에서
//자리를 찾아가도록 스왑한다.
//21,59,36,99,17
//1번째사이클에서 21선택하고 종료한다. 
//2번째사이클에서 21와 59을 비교하고 21이 작기에 종료한다. 
//3번째사이클에서 59와 36을 비교하고 59가 크기에 스왑한다.
//4번째사이클에서 21과 36을 비교하고 21이 작기에 종료한다.
//5번째사이클에서 36과 59을 비교하고 36이 작기에 종료한다.
/*
void insertSort()
{
	int array2[5] = { 0, };  //배열array2의 선언
	for (int i = 0; i < 5; i++)
	{
		std::cin >> array2[i]; //for문을 통해 array2에 입력받기
	}
	int cir = (sizeof(array2) / sizeof(int));
	for (int i = 1; i < cir-1; i++)
	{
		if (array2[i] < array2[j])
		{
			(&array2[i], &array2[j]);
		}
	}
}
*/

//다차원배열
void Descrip003()
{
	char char_[25] = { 0, };
	char char2_[5][5] =
	{0,};
	for (int i = 0; i < 25; i++)
	{
		char_[i] = '*';
	}
	for (int y = 0; y < 5; y++)
	{
		for (int x = 0; x < 5; x++)
		{
			if (x == 2 && y == 2)
			{
				char2_[2][2] = '0';
				continue;
			}
			char2_[y][x] = '*';
		}
	}
	/*출력부분
	for (int i = 0; i < 25; i++)
	{
		printf("%c ", char_[i]);

		if (i % 5 == 4)
		{
			printf("\n");
		}
	}
	
	printf("\n");
	*/
	//char_의 주소는 char[0][0]의 주소와같다.
	//즉 char_에서

	for (int y = 0; y < 5; y++)
	{
		for (int x = 0; x < 5; x++)
		{
			printf("%c ", char2_[y][x]);
		}
		printf("\n");
	}
	printf("\n");
}

void control()
{
	char char2_[5][5] =
	{ 0, };

	for (int y = 0; y < 5; y++)
	{
		for (int x = 0; x < 5; x++) //초기화
		{
			char2_[y][x] = '*';
		}
	}
	int playerPosX = 2; //player 열좌표
	int playerPosY = 2; //palyer 행좌표
	char2_[playerPosY][playerPosX] = '0';
	//alt 방향키 위아래로 움직이기 가능 

	while (true)
	{
		for (int y = 0; y < 5; y++)
		{
			for (int x = 0; x < 5; x++)
			{
				printf("%c ", char2_[y][x]);   //출력
			}
			printf("\n");
		}
		printf("\n");

		char input;
		input = _getch(); //즉시 반영을 위해 _getch()를 사용하고 input에 입력을 받음
		char2_[playerPosY][playerPosX] = '*';  //플레이어의 위치를 *로 만듬
		switch (input) //input의 결과에  따라 플레이어의 x와 y좌표를 옮김
		{
		case 'a':
			playerPosX--;
			break;
		case 'w':
			playerPosY--;
			break;
		case 's':
			playerPosY++;
			break;
		case 'd':
			playerPosX++;
			break;
		}
		char2_[playerPosY][playerPosX] = '0'; // 옮긴 player의 좌표에 '0'을 넣음.

		system("cls");
	}
}
	
	
