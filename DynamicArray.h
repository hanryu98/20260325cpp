#pragma once
#ifndef __DynamicArray_H__
#define __DynamicArray_H__

class DynamicArray
{
public:
	DynamicArray()
	{
		Size = 0;
		Data = nullptr;
		//Data = new int[Size];
	}

	~DynamicArray()
	{
		delete[] Data;
		Data = nullptr;
	}

	void PushBack(int InValue)
	{
		Size++;
		// 1. 늘어난 영역만큼 새로 할당
		int* NewData = new int[Size];

		//2. 원본 복제
		for (int i = 0; i < Size - 1; i++)
		{
			NewData[i] = Data[i];

		}

		//3. 새로 들어온 값을 넣는다
		NewData[Size - 1] = InValue;

		//4. 원래 있던걸 지운다
		delete[] Data;

		//5. 원래 데이터의 포인터에 새 데이터 포인터 연결
		Data = NewData;

	}
	
	//함수 뒤에 const read only 함수임
	inline size_t GetSize() const
	{

		return Size;
	}

	int& operator [] (int Index) const
	{
		return Data[Index];
	}

//protected:
	int* Data;
	size_t Size = 0;
};

class FVector
{
	FVector operator+(const FVector& RHS)
	{

	}
};

#endif