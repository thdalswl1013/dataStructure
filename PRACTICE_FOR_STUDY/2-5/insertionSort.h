
void sort(int a[], int n) 
{
    int i, j, key;

    for (i = 1; i < n; i++) // 인텍스 0은 이미 정렬된 것으로 볼 수 있다.
    {
        key = a[i]; // 현재 삽입될 숫자인 i번째 정수를 key 변수로 복사

        for (j = i - 1; j >= 0 && a[j] > key; j--) // 현재 정렬된 배열은 i-1까지이므로 i-1번째부터 역순으로 조사한다.
        {
            a[j + 1] = a[j]; // key 값보다 정렬된 배열에 있는 값이 크면 j번째를 j+1번째로 이동
        }

        a[j + 1] = key;
    }
}
